// ⓒ 2024. Changjin Ha. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "InGameContentManagement.generated.h"

/**
 *
 */

UENUM(BlueprintType)
enum class EContentTypeModel : uint8
{
	IRREVERSIBLE_PROMISE = 0 UMETA(DisplayName = "Irreversible Promise"),
	Invalid
};

UENUM(BlueprintType)
enum class ESubTitleTypeModel : uint8
{
	SUB_TITLE = 0 UMETA(DisplayName = "SubTitle"),
	COMMAND = 1 UMETA(DisplayName = "Command"),
	FULL_SCREEN_TITLE = 2 UMETA(DisplayName = "Full-Screen Title"),
	OPTION = 3 UMETA(DisplayName = "Option")
};

UENUM(BlueprintType)
enum class ETextFont : uint8
{
	SQUARE = 0 UMETA(DisplayName = "Square"),
	MYEONGJO = 1 UMETA(DisplayName = "Myeongjo")
};

UENUM(BlueprintType)
enum class ETextColor : uint8
{
	BLACK = 0 UMETA(DisplayName = "Black"),
	WHITE = 1 UMETA(DisplayName = "White"),
	RED = 2 UMETA(DisplayName = "Red"),
	BLUE = 3 UMETA(DisplayName = "Blue"),
	GREEN = 4 UMETA(DisplayName = "Green")
};

USTRUCT(BlueprintType)
struct A_MUSE_API FSubtitleDataModel
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SubtitleType")
	ESubTitleTypeModel subTitleType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SubtitleText")
	FString subtitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SubtitleFont")
	ETextFont font;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SubtitleColor")
	ETextColor color;

	FSubtitleDataModel(ESubTitleTypeModel type_, FString subtitle_, ETextFont font_, ETextColor color_) : subTitleType(type_), subtitle(subtitle_), font(font_), color(color_) {}
	FSubtitleDataModel() : subTitleType(ESubTitleTypeModel::SUB_TITLE), subtitle(TEXT("")), font(ETextFont::SQUARE), color(ETextColor::WHITE) {}
};

UCLASS()
class A_MUSE_API UInGameContentManagement : public UUserWidget
{
	GENERATED_BODY()


public:
	virtual void NativeConstruct() override;

protected:
	FSubtitleDataModel getSubtitle();

	UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
	void updateIndex();

	UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
	void updateSubtitle();

	UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
	void init(EContentTypeModel contentType);

	UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
	void updateOption(int opt);

	UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
	float getIndex();
    
    UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
    bool showARSession();
    
    UFUNCTION(BlueprintCallable, Category = "Widget Interaction")
    bool playAudio();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UTextBlock* txtSubTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UTextBlock* txtLargeSubTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCanvasPanel* panel_optionButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UTextBlock* txt_option_0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UTextBlock* txt_option_1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UButton* btnNext;

	UPROPERTY(EditAnywhere)
	EContentTypeModel currentContent;
	int currentIndex;
};
