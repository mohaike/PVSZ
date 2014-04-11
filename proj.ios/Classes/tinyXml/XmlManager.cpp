//
//  XmlManager.cpp
//  PlantAndZombieMy
//
//  Created by  liwenhao on 14-4-3.
//
//

#include "XmlManager.h"
USING_NS_CC;

XmlManager* XmlManager::defaultManager(){
    static XmlManager *manager = NULL;
    if (manager == NULL) {
        manager = new XmlManager();
    }
    return manager;
}

void printXML(TiXmlDocument *doc){
    TiXmlPrinter printer;//提供工具类，目的是将xml的数据按格式输出
    doc->Accept(&printer);
    cout << printer.CStr() << endl;

}
/*
 FirstChildElement
 FirstAttribute
 Value
 GetText
 */
CCDictionary * XmlManager::dictionaryFromZombieXML(const char *fileName){
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fileName, "r", &size);
    TiXmlDocument *doc = new TiXmlDocument;
    doc->Parse(pFileContent,0,TIXML_ENCODING_UTF8);
//    printXML(doc);
    CCDictionary *dic = new CCDictionary();
    TiXmlElement *rootElement = doc->RootElement();
    TiXmlElement *element = rootElement->FirstChildElement();
    
 /*******************************************************/
    
    while (element) {//每一个循环便是一个僵尸
        
        
        
        TiXmlAttribute *attribute = element->FirstAttribute();
        const char *attributeValue = attribute->Value();
        TiXmlElement *childElement = element->FirstChildElement();
        CCDictionary *elementDictionary = CCDictionary::create();
        
        while (childElement) {//每个循环便是一个字典的子元
            TiXmlElement *c_childElement = childElement->FirstChildElement();
            const char *childElementName = childElement->Value();
            CCDictionary *c_cDic = CCDictionary::create();
            
            
            while (c_childElement) {
                const char *childElementName = c_childElement->Value();
                const char *childElementValue = c_childElement->GetText();
                c_cDic->setObject(CCString::createWithFormat("%s",childElementValue), childElementName);
                c_childElement = c_childElement->NextSiblingElement();
            }
            
            
            const char *childElementValue;
            if (c_cDic->count() == 0) {
                childElementValue = childElement->GetText();
                elementDictionary->setObject(CCString::createWithFormat("%s",childElementValue), childElementName);
            }else{
                elementDictionary->setObject(c_cDic, childElementName);
            }
            childElement = childElement->NextSiblingElement();
        }
        
        dic->setObject(elementDictionary, attributeValue);//(值, key)
        element = element->NextSiblingElement();
        
        
        
        
    }
 /*******************************************************/
    
    
    
    
    
    return (CCDictionary *)dic->autorelease();
}



CCDictionary * XmlManager::dictionaryFromPlantXML(const char *fileName){
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fileName, "r", &size);
    TiXmlDocument *doc = new TiXmlDocument;
    doc->Parse(pFileContent,0,TIXML_ENCODING_UTF8);
    CCDictionary *dic = new CCDictionary();
     TiXmlElement *rootElement = doc->RootElement();
    TiXmlElement *element = rootElement->FirstChildElement();
    while (element) {
        TiXmlAttribute *attribute = element->FirstAttribute();
        const char *attributeValue = attribute->Value();
        TiXmlElement *childElement = element->FirstChildElement();
        CCDictionary *elementDictionary = CCDictionary::create();
        while (childElement) {
            TiXmlElement *c_childElement = childElement->FirstChildElement();
            const char *childElementName = childElement->Value();
            CCArray *c_cArray = CCArray::create();//大数组
            while (c_childElement) {
                const char *childElementName = c_childElement->Value();
                const char *childElementValue = c_childElement->GetText();
                CCArray *item = CCArray::create();//子数组
                item ->addObject(CCString::createWithFormat("%s",childElementName));//键在前面
                item ->addObject(CCString::createWithFormat("%s",childElementValue));//值在后面
                c_cArray->addObject(item);
                c_childElement = c_childElement->NextSiblingElement();
            }
            const char *childElementValue;
            if (c_cArray->count() == 0) {
                childElementValue = childElement->GetText();
                elementDictionary->setObject(CCString::createWithFormat("%s",childElementValue), childElementName);
            }else{
                elementDictionary->setObject(c_cArray, childElementName);
            }
            childElement = childElement->NextSiblingElement();
        }
        dic->setObject(elementDictionary, attributeValue);
        element = element->NextSiblingElement();
    }
    return (CCDictionary *)dic->autorelease();
}

//递归取出xml中的数据
CCDictionary *XmlManager::dictionaryFromXML(const char *fileName,int childElementsCategory){

    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fileName, "r", &size);
    TiXmlDocument *doc = new TiXmlDocument;
    doc->Parse(pFileContent,0,TIXML_ENCODING_UTF8);
    TiXmlElement *rootElement = doc->RootElement();
    if (childElementsCategory ==ChildElementsInDictionary) {
        return dictionaryFromTiXmlElement(rootElement);
    }else if(childElementsCategory ==ChildElementsInDictionary){
        return ArrayFromTiXmlElement(rootElement);
    }else{
        return dictionaryArrayFromTiXmlElement(rootElement);
    }
}

CCDictionary *XmlManager::ArrayFromTiXmlElement(TiXmlElement *rootElement){
    CCDictionary *rootDictionary = new CCDictionary();
    const char *rootName = rootElement->Value();
    rootDictionary->setObject(CCString::createWithFormat("%s",rootName), nameS);
    const char *rootText = rootElement->GetText();
    if (rootText) {
        rootDictionary->setObject(CCString::createWithFormat("%s",rootText), textS);
    }
    TiXmlAttribute *attribute = rootElement->FirstAttribute();
    CCDictionary *attributeDictionary = CCDictionary::create();
    while (attribute) {
        const char *attr_name = attribute->Name();
        const char *attr_value = attribute->Value();
        attributeDictionary->setObject(CCString::createWithFormat("%s",attr_value), attr_name);
        attribute = attribute->Next();
    }
    if (attributeDictionary->count()>0) {
        rootDictionary->setObject(attributeDictionary, attributeDictionaryS);
    }
    TiXmlElement *element = rootElement->FirstChildElement();
    CCArray *childElementArray = CCArray::create();
    while (element) {
        CCDictionary *childDic = ArrayFromTiXmlElement(element);
        childElementArray->addObject(childDic);
        element = element->NextSiblingElement();
    }
    if (childElementArray->count()>0) {
        rootDictionary->setObject(childElementArray, childElementArrayS);
    }
    return rootDictionary;
}

CCDictionary *XmlManager::dictionaryFromTiXmlElement(TiXmlElement *rootElement){
    CCDictionary *rootDictionary = new CCDictionary();
    const char *rootName = rootElement->Value();/**/
    rootDictionary->setObject(CCString::createWithFormat("%s",rootName), nameS);
    const char *rootText = rootElement->GetText();/**/
    if (rootText) {
        rootDictionary->setObject(CCString::createWithFormat("%s",rootText), textS);
    }
    TiXmlAttribute *attribute = rootElement->FirstAttribute();/**/
    CCDictionary *attributeDictionary = CCDictionary::create();
    while (attribute) {
        const char *attr_name = attribute->Name();
        const char *attr_value = attribute->Value();
        attributeDictionary->setObject(CCString::createWithFormat("%s",attr_value), attr_name);
        attribute = attribute->Next();
    }
    if (attributeDictionary->count()>0) {
        rootDictionary->setObject(attributeDictionary, attributeDictionaryS);
    }
    TiXmlElement *element = rootElement->FirstChildElement();/**/
    CCDictionary *childElementDictionary = CCDictionary::create();
    while (element) {
        CCDictionary *childDic = dictionaryFromTiXmlElement(element);
        const char *childName = childDic->valueForKey(nameS)->getCString();
        childElementDictionary->setObject(childDic, childName);
        element = element->NextSiblingElement();
    }
    if (childElementDictionary->count()>0) {
        rootDictionary->setObject(childElementDictionary,childElementDictionaryS);
    }
    return rootDictionary;
}


CCDictionary *XmlManager::dictionaryArrayFromTiXmlElement(TiXmlElement *rootElement){
    CCDictionary *rootDictionary = new CCDictionary();
    const char *rootName = rootElement->Value();
    rootDictionary->setObject(CCString::createWithFormat("%s",rootName), nameS);
    const char *rootText = rootElement->GetText();
    if (rootText) {
        rootDictionary->setObject(CCString::createWithFormat("%s",rootText), textS);
    }
    TiXmlAttribute *attribute = rootElement->FirstAttribute();
    CCDictionary *attributeDictionary = CCDictionary::create();
    while (attribute) {
        const char *attr_name = attribute->Name();
        const char *attr_value = attribute->Value();
        attributeDictionary->setObject(CCString::createWithFormat("%s",attr_value), attr_name);
        attribute = attribute->Next();
    }
    if (attributeDictionary->count()>0) {
        rootDictionary->setObject(attributeDictionary, attributeDictionaryS);
    }
    TiXmlElement *element = rootElement->FirstChildElement();
    CCDictionary *childElementDictionary = CCDictionary::create();
    while (element) {
        CCDictionary *childDic = dictionaryArrayFromTiXmlElement(element);
        const char *childName = childDic->valueForKey(nameS)->getCString();
        CCArray *childElementArray = (CCArray *)childElementDictionary->objectForKey(childName);
        if (childElementArray == NULL) {
            childElementArray = CCArray::create();
            childElementDictionary->setObject(childElementArray, childName);//子结点字典
        }
        childElementArray->addObject(childDic);//子结点数组
        element = element->NextSiblingElement();
    }
    if (childElementDictionary->count()>0) {
        rootDictionary->setObject(childElementDictionary,childElementDictionaryArrayS);
    }
    return rootDictionary;
}