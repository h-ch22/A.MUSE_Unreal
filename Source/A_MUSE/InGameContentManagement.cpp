// ⓒ 2024. Changjin Ha. All Rights Reserved.


#include "InGameContentManagement.h"
#include "Components/TextBlock.h"

int currentIndex = -1;
int option = 0;
EContentTypeModel currentContent;

FSubtitleDataModel UInGameContentManagement::getSubtitle() {
	TMap<float, FSubtitleDataModel> irreversiblePromiseSubTitles = {
		{ 0, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("당신은 얼굴의 절반 이상이 멍으로 뒤덮여 괴물처럼 태어나 부모로부터 버려져 보육시설에서 자랐습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 1, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("당신은 외모 때문에 살면서 한 번도 삶의 밑바닥에서 벗어난 적이 없었고,"), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 2, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("성인이 된 당신을 반기는 곳은 조폭이 운영하는 카지노 뿐이였습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 3, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("결국 당신에게 남은 것은 엄청난 양의 빚 뿐이였습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 4, FSubtitleDataModel(ESubTitleTypeModel::COMMAND, TEXT("다리 아래를 보십시오."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 5, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("저기..."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 6, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("노파를 바라보십시오."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 7, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("혹시 무슨 일 있나요?"), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 8, FSubtitleDataModel(ESubTitleTypeModel::COMMAND, TEXT("노파에게 대답할 답변을 선택하십시오."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 9, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("괜찮으면, 저희 집에 오시지 않겠어요? 마침 지금부터 돌아가서 저녁 준비를 할 참이예요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 10, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("얻어먹고 나서 이런 말 하기 좀 뭣하지만, 동정심 때문이더라도 낯선 사람을 집에 들이는건 위험해."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 11, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("괜찮아요. 별로 위험할 것도 없어요. 집에 훔쳐갈 것도 없고."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 12, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("단지 누군가와 오랜만에 식사하고 싶었을 뿐."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 13, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("당신은 그 날 이후로 몇 차례 노파의 집에서 함께 식사를 하며 자연스럽게 서로의 사정을 알게 되었습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 14, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("16년 전, 저는 남편을 사고로 잃고 홀로 딸을 키우고 있었어요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 15, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("그런데 하나뿐인 딸마저 두 남자에게 납치되어 능욕당한 후 살해당하고 말았어요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 16, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("곧바로 체포된 두 범인은 사형이 아닌 무기징역을 선고받았고, 저는 매순간 분노와 회한으로 얼룩진 삶을 살고 있는 중이예요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 17, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("그래서 실례지만 부탁이 있는데, 내 딸을 살해한 놈들이 나중에 교도소에서 나오면 그들을 죽여줄 수 있나요?"), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 18, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("약속만 해주면 내 전 재산을 드릴게요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 19, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("내 손으로 죽이고 싶지만, 저는 3개월 전에 암으로 시한부 판정을 받았어요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 20, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("난 그들이 나오기 전에 세상을 떠날거예요.\n부디 나 대신 내 딸의 한을 풀어주세요."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 21, FSubtitleDataModel(ESubTitleTypeModel::COMMAND, TEXT("노파의 제안을 수락하시겠습니까?"), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 21.1, FSubtitleDataModel(ESubTitleTypeModel::COMMAND, TEXT("노파의 제안을 수락하였습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 21.2, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("노파가 제안한 금액은 당신의 삶을 바꾸고도 남을 금액이었지만, 당신은 돈을 위해 살인을 약속할 수는 없었습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 21.21, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("하지만 다시 생각해보니 노파가 암으로 곧 세상을 떠난다면 당신이 약속을 지키지 않아도 모를 것이기에, 당신은 노파의 제안을 수락하게 됩니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 22, FSubtitleDataModel(ESubTitleTypeModel::SUB_TITLE, TEXT("정말 고마워요. 정말.."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 23, FSubtitleDataModel(ESubTitleTypeModel::COMMAND, TEXT("거울 앞으로 가십시오."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 24, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("당신은 노파의 돈으로 성형수술을 해서 얼굴의 멍을 지우고, 새 호적을 구입해 새 사람이 되었습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 25, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("15년 후..."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 26, FSubtitleDataModel(ESubTitleTypeModel::FULL_SCREEN_TITLE, TEXT("당신은 사업 파트너를 만나 꽤 잘나가는 바 사업을 진행하고 있고, 가정을 꾸리게 되었습니다."), ETextFont::SQUARE, ETextColor::WHITE) },
		{ 27, FSubtitleDataModel(ESubTitleTypeModel::COMMAND, TEXT("우편함에서 편지를 꺼내십시오."), ETextFont::SQUARE, ETextColor::WHITE) }
	};

	if (currentContent == EContentTypeModel::IRREVERSIBLE_PROMISE) {
		return irreversiblePromiseSubTitles[currentIndex];
	}
	else {
		return irreversiblePromiseSubTitles[currentIndex];
	}
}

void UInGameContentManagement::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInGameContentManagement::init(EContentTypeModel contentType) {
	currentContent = contentType;
	currentIndex = -1;
	txtSubTitle = Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_subtitle")));
	txtLargeSubTitle = Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_largeSubTitle")));
	panel_optionButton = Cast<UCanvasPanel>(GetWidgetFromName(TEXT("panel_optionButtons")));
	btnNext = Cast<UButton>(GetWidgetFromName(TEXT("btn_next")));
}

void UInGameContentManagement::updateIndex() {
	if (currentIndex < 21 || currentIndex >= 23) {
		currentIndex += 1;
	}
	else if (currentIndex == 21) {
		if (option == 0) {
			currentIndex += 0.1;
		}
		else {
			currentIndex += 0.2;
		}
	}
	else if (currentIndex == 21.2) {
		currentIndex += 0.01;
	}
	else if (currentIndex == 21.21) {
		currentIndex = 22;
	}
}

float UInGameContentManagement::getIndex() {
	return currentIndex;
}

void UInGameContentManagement::updateOption(int opt) {
	option = opt;
}

void UInGameContentManagement::updateSubtitle() {
	FSubtitleDataModel subtitleData = getSubtitle();
	FString subtitle = subtitleData.subtitle;
	FTCHARToUTF8 convertedText(*subtitle);
	btnNext->SetVisibility(ESlateVisibility::Visible);

	panel_optionButton->SetVisibility(ESlateVisibility::Hidden);

	if (subtitleData.subTitleType == ESubTitleTypeModel::SUB_TITLE || subtitleData.subTitleType == ESubTitleTypeModel::COMMAND) {
		if (subtitleData.subTitleType == ESubTitleTypeModel::COMMAND) {
			btnNext->SetVisibility(ESlateVisibility::Hidden);
		} else {
			btnNext->SetVisibility(ESlateVisibility::Visible);
		}
		
		txtLargeSubTitle->SetVisibility(ESlateVisibility::Hidden);
		txtSubTitle->SetVisibility(ESlateVisibility::Visible);
		txtSubTitle->SetText(FText::FromString(*subtitle));
	}
	else if (subtitleData.subTitleType == ESubTitleTypeModel::FULL_SCREEN_TITLE) {
		txtSubTitle->SetVisibility(ESlateVisibility::Hidden);
		txtLargeSubTitle->SetVisibility(ESlateVisibility::Visible);
		txtLargeSubTitle->SetText(FText::FromString(*subtitle));
	}

	if (currentIndex == 8) {
		panel_optionButton->SetVisibility(ESlateVisibility::Visible);
		
		FString option_0 = TEXT("알 바 아니잖아.\n신경 꺼.");
		FString option_1 = TEXT("그냥 배가 고파서\n그런거야.");

		txt_option_0->SetText(FText::FromString(*option_0));
		txt_option_1->SetText(FText::FromString(*option_1));
	}
	else if (currentIndex == 21) {
		panel_optionButton->SetVisibility(ESlateVisibility::Visible);

		FString option_0 = TEXT("예");
		FString option_1 = TEXT("아니오");

		txt_option_0->SetText(FText::FromString(*option_0));
		txt_option_1->SetText(FText::FromString(*option_1));
	}
}

bool UInGameContentManagement::showARSession(){
    FSubtitleDataModel subtitleData = getSubtitle();
    
    if(subtitleData.subTitleType == ESubTitleTypeModel::FULL_SCREEN_TITLE){
        return false;
    } else {
        return true;
    }
}

bool UInGameContentManagement::playAudio(){
    if(currentIndex != 4 && currentIndex != 6 && currentIndex != 8 && currentIndex != 21 && currentIndex != 23 && currentIndex != 25) {
        return true;
    } else {
        return false;
    }
}
