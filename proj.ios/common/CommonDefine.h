//
//  CommonDefine.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#ifndef PlantAndZombie_3_CommonDefine_h
#define PlantAndZombie_3_CommonDefine_h

#define Connect(x,y) CCString::createWithFormat("%s%s",x,y)
//通知名称
#define PlantCardNotificationS "PlantCardNotification"
#define ChangeCardStateNotificationS "ChangeCardStateNotification"
#define AttackPlantNotificationS "AttackPlantNotification"
#define PlantDieNotificationS "PlantDieNotification"
#define CreateSunSpriteNotificationS "CreateSunSpriteNotification"
#define CherryBombNotificationS "CherryBombNotification"
#define ClickSunSpriteNotificationS "ClickSunSpriteNotification"

#define AttactTime (0.5)
#define ZombieAddress {120,220,340}
#define CreateZombieTime (40)
#define CreateSunSpriteTime (2)
#define ReleaseSunSpriteTime (30)
#define SunSpriteTag (10086)

//图片名称
#define PoleVaultingZombieS "PoleVaultingZombie"
#define ZombieS "Zombie"
#define AnimationsS "Animations"
#define OneZombiePNGS "Zombie1.png"
#define OnePlantPNGS "Boom.png"
#define tableViewPNGS "tableView.png"
#define OneSunSpritePictureS "sun1.png"
//xml,解析名称
#define nameS "name"
#define textS "text"
#define attributeDictionaryS "attributeDictionary"
#define childElementArrayS "childElementArray"
#define childElementDictionaryS "childElementDictionary"
#define childElementDictionaryArrayS "childElementDictionaryArray"
#define PlantS "Plant"
#define HealthPoint_S "HealthPoint"
#define AttackNum_S "AttackNum"
#define CreateBulletTime_S "CreateBulletTime"
#define SpriteImageName_S "SpriteImageName"
#define SpriteImageNum_S "SpriteImageNum"
#define SpriteImageExt_S "SpriteImageExt"
#define ProductionName_S "ProductionName"
#define BoundingBoxX_S "BoundingBoxX"
#define PlantCard_S "PlantCard"
#define PlantCardB_S "PlantCardB"

//xml,动画名称
#define ZombieWalkS "Zombie"
#define ZombieLostHeadWalkS "ZombieLostHead"
#define ZombieAttackS "ZombieAttack"
#define ZombieLostHeadAttackS "ZombieLostHeadAttack"
#define ZombieDieS "ZombieDie"
#define ZombieBombDieS "BombDie1"
#define ZombieHeadS "ZombieHead"


#define PoleVaultingJumpS "PoleVaultingZombieJump"
#define PoleVaultingZombieWalkS "PoleVaultingZombie"
#define PoleVaultingZombieLostHeadWalkS "PoleVaultingZombieLostHeadWalk"
#define PoleVaultingZombieAttackS "PoleVaultingZombieAttack"
#define PoleVaultingZombieLostHeadAttackS "PoleVaultingZombieLostHeadAttack"
#define PoleVaultingZombieDieS "PoleVaultingZombieDie"
#define PoleVaultingZombieBombDieS "BombDie1"
#define PoleVaultingZombieHeadS "PoleVaultingZombieHead"



#define PA_CabbageplantS "Cabbageplant"
#define PA_MachineplantS "Machineplant"
#define PA_PeashooterS "Peashooter"
#define PA_blueS "blue"
#define PA_cherryBoumpS "cherryBoump"
#define PA_sunS "sun"
#define PA_sunflowerS "sunflower"


//文件名称
#define map_png "map.png"
#define ZombiePropertity_xml "ZombiePropertity.xml"
#define zombie_plist "zombie.plist"
#define zombie_png  "zombie.png"
#define plantPropertity_xml "plantPropertity.xml"
#define plant_plist "plant.plist"
#define plant_png "plant.png"
#define bullet_plist "bullet.plist"
#define bullet_png "bullet.png"


//改变系统宏定义
#define Lazy_CC_SYNTHESIZE_RETAIN(varType, varName, funName)    \
protected: varType varName; \
public: virtual varType get##funName(void); \
public: virtual void set##funName(varType var)   \
{ \
if (varName != var) \
{ \
CC_SAFE_RETAIN(var); \
CC_SAFE_RELEASE(varName); \
varName = var; \
} \
}

#define LazyPrivate_CC_SYNTHESIZE_RETAIN(varType, varName, funName)    \
private: varType varName; \
private: virtual varType get##funName(void); \
private: virtual void set##funName(varType var)   \
{ \
if (varName != var) \
{ \
CC_SAFE_RETAIN(var); \
CC_SAFE_RELEASE(varName); \
varName = var; \
} \
}

#define Private_CC_SYNTHESIZE_RETAIN(varType, varName, funName)    \
private: varType varName; \
private: virtual varType get##funName(void){return varName}; \
private: virtual void set##funName(varType var)   \
{ \
if (varName != var) \
{ \
CC_SAFE_RETAIN(var); \
CC_SAFE_RELEASE(varName); \
varName = var; \
} \
}

#define Write_CC_SYNTHESIZE(varType,varName,funName)\
protected: varType varName;\
public: virtual varType get##funName(void){return varName;}\
public: virtual void set##funName(varType var);\


#define Lazy_CC_SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void);\
public: virtual void set##funName(varType var){ varName = var; }

#define LazyPrivate_CC_SYNTHESIZE(varType, varName, funName)    \
private: varType varName; \
private: virtual varType get##funName(void); \
private: virtual void set##funName(varType var){ varName = var; }


#define Private_CC_SYNTHESIZE(varType, varName, funName)    \
private: varType varName; \
private: virtual varType get##funName(void){return varName); \
private: virtual void set##funName(varType var){ varName = var; }




#define SUN_SP_TAG 111





#endif
