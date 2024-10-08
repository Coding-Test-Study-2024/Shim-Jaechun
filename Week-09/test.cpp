// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimTestCharacter_j.h"
#include "ATCAnimInstance_j.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Engine/Classes/GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"

// Sets default values
AAnimTestCharacter_j::AAnimTestCharacter_j()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArmComponent->SetupAttachment(GetCapsuleComponent());
	CameraSpringArmComponent->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight));
	CameraSpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CameraSpringArmComponent, USpringArmComponent::SocketName);

	//GetCharacterMovement()->JumpZVelocity = 200.0f;	// 점프 높이
	//JumpMaxCount = 1;	// 점프 가능 횟수
	//JumpMaxHoldTime = 0.5f;	// 체공 시간

	currentMoveMode = EMoveMode::QuarterViewMode;

	//playerHp = 5;
	maxStamina = 5.0f;
	currentStamina = 5.0f;

	// 스테미너 소진 카운트
	callStaminaCount = 0;
	// 스테미너 소진 시 딜레이
	waitCount = 3.0f;

	sprintSpeed = 650.0f;
	walkSpeed = 400.0f;

	swampSprintSpeed = 500.0f;
	swampWalkSpeed = 320.0F;

	pushSpeed = 200.0f;

	swampjumpZvelocity = 350.0f;
	jumpZvelocity = 500.0f;

	sprintAble = true;
	rollAble = true;
	sitAble = true;
	IsLoading = true;

	IsLadder2 = false;
	climbable2 = false;
	IsPushing2 = false;
	isInSwamp = false;
	IsDeath = false;
	IsInCutScene = false;
}

// Called when the game starts or when spawned
void AAnimTestCharacter_j::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAnimTestCharacter_j::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAnimTestCharacter_j::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AAnimTestCharacter_j::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AAnimTestCharacter_j::MoveRight);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AAnimTestCharacter_j::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AAnimTestCharacter_j::StopJump);
	InputComponent->BindAction("Sit", IE_Pressed, this, &AAnimTestCharacter_j::Sit);

	InputComponent->BindAction("Sprint", IE_Pressed, this, &AAnimTestCharacter_j::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &AAnimTestCharacter_j::StopSprinting);
}

void AAnimTestCharacter_j::MoveForward(float value)
{
	// Normal Walking
	if ((Controller != NULL) && (value != 0.0f) && !IsLadder2 && (currentMoveMode != EMoveMode::SideViewMode) && (currentMoveMode != EMoveMode::BackViewMode))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
	// Ladder climbing
	else if ((Controller != NULL) && (value != 0.0f) && IsLadder2 && (currentMoveMode != EMoveMode::SideViewMode) && (currentMoveMode != EMoveMode::BackViewMode))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "is Ladder");
		AddMovementInput(FVector::UpVector, value);
	}
}
void AAnimTestCharacter_j::MoveRight(float value)
{
	// Normal SideView Walking
	if ((Controller != NULL) && (value != 0.0f) && !IsLadder2 && (currentMoveMode == EMoveMode::SideViewMode))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput((Direction * -1.0f), value);
	}
	// Normal QuarterView Walking
	else if ((Controller != NULL) && (value != 0.0f) && !IsLadder2 && (currentMoveMode != EMoveMode::SideViewMode))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void AAnimTestCharacter_j::StartJump()
{
	if (this->GetCharacterMovement()->IsCrouching())
	{
		UnCrouch();
	}
	else if (currentMoveMode != EMoveMode::TopViewMode && !this->GetCharacterMovement()->IsFalling() && !IsDeath && !IsInCutScene && !IsLoading)
	{
		bPressedJump = true;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SB_Jump, this->GetActorLocation());
	}
}

void AAnimTestCharacter_j::StopJump()
{
	bPressedJump = false;
}
// 앉기 기능 활성화, 비 활성화
// GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

void AAnimTestCharacter_j::Sit()
{
	if ((Controller != NULL) && sitAble)
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}
}

void AAnimTestCharacter_j::Sprint()
{
	if (!IsPushing2 && !this->GetCharacterMovement()->IsFalling())
	{ // 스테미너가 0인 경우
		if (currentStamina > 0)
		{
			// recover 타이머 해제
			GetWorldTimerManager().ClearTimer(recoverTH);
			GetWorldTimerManager().SetTimer(consumeTH, this, &AAnimTestCharacter_j::ConsumeStamina, 0.1f, true);
		}
	}
}
void AAnimTestCharacter_j::StopSprinting()
{
	if (currentStamina > 0 && sprintAble)
	{
		// consume 타이머 해제
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 0.1f, true);
	}
}


// 스테미너 감소
void AAnimTestCharacter_j::ConsumeStamina()
{
	// 플레이어의 현재 속도가 달리는 속도일 경우 감소
	if (this->GetVelocity().Size() >= sprintSpeed)
	{
		currentStamina -= 0.1f;
		IsIncreaseStamina = false;
	}
	else
	{
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 0.1f, true);
	}
	// 스테미너 모두 소진 시 캐릭터의 속도 감소.
	if (currentStamina <= 0)
	{
		currentStamina = 0;
		sprintAble = false;
		GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetWorldTimerManager().SetTimer(zeroTH, this, &AAnimTestCharacter_j::StaminaZero, 0.1f, true);
	}
}
// 스테미너 탈진 타이머
void AAnimTestCharacter_j::StaminaZero()
{
	// 딜레이 시간 적용
	waitCount -= 0.1f;

	if (waitCount <= 0.0f)
	{
		// 일정량의 스테미너를 즉시 회복
		currentStamina += 3.0f;
		sprintAble = true;
		waitCount = 3.0f;
		GetWorld()->GetTimerManager().ClearTimer(zeroTH);
		GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 0.1f, true);
	}
}
// 스테미너 회복
void AAnimTestCharacter_j::RecoverStamina()
{
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	currentStamina += 0.1f;
	IsIncreaseStamina = true;
	// 스테미너가 최대 수치를 넘은 경우 recover 중지.
	if (currentStamina >= maxStamina)
	{
		currentStamina = maxStamina;
		GetWorldTimerManager().ClearTimer(recoverTH);
	}
}

float AAnimTestCharacter_j::GetMaxStamina()
{
	return maxStamina;
}

float AAnimTestCharacter_j::GetCurrentStamina()
{
	return currentStamina;
}
void AAnimTestCharacter_j::SetSwarmpMode(bool state)
{
	if (!state)
	{
		isInSwamp = false;
	}
	else
	{
		isInSwamp = true;
	}
}