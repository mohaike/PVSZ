//
//  PlantParentCard.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-10.
//
//

#include "PlantParentCard.h"

void PlantParentCard::setPlantBatchNode(CCSpriteBatchNode *_plantBatchNode){
    plantBatchNode = _plantBatchNode;
}

CCSpriteBatchNode * PlantParentCard::getPlantBatchNode(){
    return plantBatchNode;
}

void PlantParentCard::setCardBufferState(){
    //空的方法???????
}

void PlantParentCard::setCardState(int state){
    cardState = state;
}

int PlantParentCard::getCardState(){
    return cardState;
}

void PlantParentCard::setCardFrameSp(CardFrame *_cardFrameSp){
    cardFrameSp = _cardFrameSp;
}

CardFrame * PlantParentCard::getCardFrameSp(){
    return cardFrameSp;
}

void PlantParentCard::setSunCount(int _count){
    sunCount = _count;
}

int PlantParentCard::getSunCount(){
    return sunCount;
}
