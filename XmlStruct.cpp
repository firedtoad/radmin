#include"TinyXml/tinystr.h"
#include"TinyXml/tinyxml.h"
#include"XmlStruct.h"
#include <string.h>
#include<stddef.h>
#include "Protocol/PubFunDef.h"
#include <boost/uuid/random_generator.hpp>
using namespace PubFunDef;
KeyType ActiveRecruitKeys[]={
    {"ID",0,offsetof(ActiveRecruit,ID) },
    {"HeroID",0,offsetof(ActiveRecruit,HeroID) },
    {"Des",1,offsetof(ActiveRecruit,Des) }
};
KeyType ActiveRecruitTimesKeys[]={
    {"RecruitTimes",0,offsetof(ActiveRecruitTimes,RecruitTimes) },
    {"Job1",5,offsetof(ActiveRecruitTimes,Job1) },
    {"Job2",5,offsetof(ActiveRecruitTimes,Job2) },
    {"Job3",5,offsetof(ActiveRecruitTimes,Job3) },
    {"Job4",5,offsetof(ActiveRecruitTimes,Job4) },
    {"Job5",5,offsetof(ActiveRecruitTimes,Job5) },
    {"FragTimes",0,offsetof(ActiveRecruitTimes,FragTimes) }
};
KeyType ActiveRecruitbaseKeys[]={
    {"ID",0,offsetof(ActiveRecruitbase,ID) },
    {"Key",1,offsetof(ActiveRecruitbase,Key) },
    {"Value",1,offsetof(ActiveRecruitbase,Value) },
    {"Des",1,offsetof(ActiveRecruitbase,Des) }
};
KeyType ActivityKeys[]={
    {"ID",0,offsetof(Activity,ID) },
    {"FightID",5,offsetof(Activity,FightID) },
    {"SpiritExpend",0,offsetof(Activity,SpiritExpend) },
    {"FightNum",0,offsetof(Activity,FightNum) },
    {"OpenTime",0,offsetof(Activity,OpenTime) },
    {"ContinueTime",0,offsetof(Activity,ContinueTime) },
    {"Limit",3,offsetof(Activity,Limit) },
    {"ActivityFightType",0,offsetof(Activity,ActivityFightType) }
};
KeyType ActivityBaseKeys[]={
    {"ID",0,offsetof(ActivityBase,ID) },
    {"Key",1,offsetof(ActivityBase,Key) },
    {"Value",0,offsetof(ActivityBase,Value) },
    {"Des",1,offsetof(ActivityBase,Des) }
};
KeyType ActivityFightKeys[]={
    {"FightID",0,offsetof(ActivityFight,FightID) },
    {"FightSetID",3,offsetof(ActivityFight,FightSetID) },
    {"DropBoxID",0,offsetof(ActivityFight,DropBoxID) },
    {"RewardNum",5,offsetof(ActivityFight,RewardNum) },
    {"FightScene",0,offsetof(ActivityFight,FightScene) }
};
KeyType ActivityHeroKeys[]={
    {"ID",0,offsetof(ActivityHero,ID) },
    {"HeroID",3,offsetof(ActivityHero,HeroID) }
};
KeyType ActivityOpenKeys[]={
    {"OpenTime",0,offsetof(ActivityOpen,OpenTime) },
    {"Activity1ID",5,offsetof(ActivityOpen,Activity1ID) },
    {"Activity2ID",5,offsetof(ActivityOpen,Activity2ID) }
};
KeyType AddArtifactKeys[]={
    {"Id",0,offsetof(AddArtifact,Id) },
    {"ArtifactTimes",0,offsetof(AddArtifact,ArtifactTimes) },
    {"ItemReward",5,offsetof(AddArtifact,ItemReward) }
};
KeyType AddRecruitKeys[]={
    {"Id",0,offsetof(AddRecruit,Id) },
    {"RecruitNum",0,offsetof(AddRecruit,RecruitNum) },
    {"ItemReward",5,offsetof(AddRecruit,ItemReward) }
};
KeyType AllRankKeys[]={
    {"ID",0,offsetof(AllRank,ID) },
    {"Key",1,offsetof(AllRank,Key) },
    {"Title",0,offsetof(AllRank,Title) },
    {"OpenLv",0,offsetof(AllRank,OpenLv) },
    {"Des",1,offsetof(AllRank,Des) },
    {"Value",0,offsetof(AllRank,Value) },
    {"CountLv",0,offsetof(AllRank,CountLv) },
    {"Show",0,offsetof(AllRank,Show) }
};
KeyType ArenaKeys[]={
    {"ID",0,offsetof(Arena,ID) },
    {"RobotGroupID",0,offsetof(Arena,RobotGroupID) },
    {"Level",0,offsetof(Arena,Level) },
    {"Name",1,offsetof(Arena,Name) },
    {"Capacity",0,offsetof(Arena,Capacity) },
    {"UpgradeArenaID",0,offsetof(Arena,UpgradeArenaID) },
    {"UpgradeNum",0,offsetof(Arena,UpgradeNum) },
    {"OutNum",0,offsetof(Arena,OutNum) },
    {"RankNum",0,offsetof(Arena,RankNum) },
    {"RankRewardID",0,offsetof(Arena,RankRewardID) },
    {"WinRewardValue",5,offsetof(Arena,WinRewardValue) },
    {"LoseRewardValue",5,offsetof(Arena,LoseRewardValue) },
    {"MatchID",0,offsetof(Arena,MatchID) },
    {"Notice",0,offsetof(Arena,Notice) }
};
KeyType ArenaBaseKeys[]={
    {"ID",0,offsetof(ArenaBase,ID) },
    {"Key",1,offsetof(ArenaBase,Key) },
    {"Value",1,offsetof(ArenaBase,Value) },
    {"Des",1,offsetof(ArenaBase,Des) }
};
KeyType ArenaMatchKeys[]={
    {"ID",0,offsetof(ArenaMatch,ID) },
    {"MatchID",0,offsetof(ArenaMatch,MatchID) },
    {"Rank",0,offsetof(ArenaMatch,Rank) },
    {"DownMatching1",0,offsetof(ArenaMatch,DownMatching1) },
    {"DownMatching2",0,offsetof(ArenaMatch,DownMatching2) },
    {"UpMatching1",0,offsetof(ArenaMatch,UpMatching1) },
    {"UpMatching2",0,offsetof(ArenaMatch,UpMatching2) },
    {"SubUpMatching1",0,offsetof(ArenaMatch,SubUpMatching1) },
    {"SubUpMatching2",0,offsetof(ArenaMatch,SubUpMatching2) }
};
KeyType ArenaRewardKeys[]={
    {"ID",0,offsetof(ArenaReward,ID) },
    {"RewardID",0,offsetof(ArenaReward,RewardID) },
    {"Rank",0,offsetof(ArenaReward,Rank) },
    {"RewardItem",5,offsetof(ArenaReward,RewardItem) }
};
KeyType ArenaTopRewardKeys[]={
    {"ID",0,offsetof(ArenaTopReward,ID) },
    {"Rank",0,offsetof(ArenaTopReward,Rank) },
    {"DiamondReward",0,offsetof(ArenaTopReward,DiamondReward) }
};
KeyType ArtifacRankBaseKeys[]={
    {"ID",0,offsetof(ArtifacRankBase,ID) },
    {"Key",1,offsetof(ArtifacRankBase,Key) },
    {"Value",1,offsetof(ArtifacRankBase,Value) },
    {"Des",1,offsetof(ArtifacRankBase,Des) }
};
KeyType ArtifactKeys[]={
    {"Id",0,offsetof(Artifact,Id) },
    {"Type",0,offsetof(Artifact,Type) },
    {"StrengthenId",0,offsetof(Artifact,StrengthenId) },
    {"StarId",0,offsetof(Artifact,StarId) },
    {"SpeHero",3,offsetof(Artifact,SpeHero) },
    {"WashId1",5,offsetof(Artifact,WashId1) },
    {"WashId2",5,offsetof(Artifact,WashId2) },
    {"WashId3",5,offsetof(Artifact,WashId3) },
    {"WashMax",5,offsetof(Artifact,WashMax) },
    {"UpgradeReward",5,offsetof(Artifact,UpgradeReward) },
    {"TeamUnique",0,offsetof(Artifact,TeamUnique) },
    {"BanHero",3,offsetof(Artifact,BanHero) }
};
KeyType ArtifactDropboxKeys[]={
    {"ID",0,offsetof(ArtifactDropbox,ID) },
    {"DropboxID",0,offsetof(ArtifactDropbox,DropboxID) },
    {"ArtifactID",0,offsetof(ArtifactDropbox,ArtifactID) },
    {"ItemType",0,offsetof(ArtifactDropbox,ItemType) },
    {"ItemNum",0,offsetof(ArtifactDropbox,ItemNum) },
    {"Probablity",0,offsetof(ArtifactDropbox,Probablity) },
    {"DropType",0,offsetof(ArtifactDropbox,DropType) }
};
KeyType ArtifactRankKeys[]={
    {"Rank",0,offsetof(ArtifactRank,Rank) },
    {"ItemReward",5,offsetof(ArtifactRank,ItemReward) }
};
KeyType ArtifactSlotKeys[]={
    {"Id",0,offsetof(ArtifactSlot,Id) },
    {"Type",0,offsetof(ArtifactSlot,Type) },
    {"RequiredLevel",0,offsetof(ArtifactSlot,RequiredLevel) }
};
KeyType ArtifactStarKeys[]={
    {"Id",0,offsetof(ArtifactStar,Id) },
    {"Type",0,offsetof(ArtifactStar,Type) },
    {"Star",0,offsetof(ArtifactStar,Star) },
    {"SpeSkillId",0,offsetof(ArtifactStar,SpeSkillId) },
    {"SpeSkillPower",0,offsetof(ArtifactStar,SpeSkillPower) },
    {"SkillId",3,offsetof(ArtifactStar,SkillId) },
    {"SkillPower",0,offsetof(ArtifactStar,SkillPower) },
    {"CostResourse",5,offsetof(ArtifactStar,CostResourse) },
    {"CostItem",5,offsetof(ArtifactStar,CostItem) },
    {"SuccessRate",0,offsetof(ArtifactStar,SuccessRate) },
    {"CostItem2",5,offsetof(ArtifactStar,CostItem2) },
    {"SuccessRate2",0,offsetof(ArtifactStar,SuccessRate2) },
    {"GrowthRate",0,offsetof(ArtifactStar,GrowthRate) },
    {"RequiredStrengthenLevel",0,offsetof(ArtifactStar,RequiredStrengthenLevel) },
    {"UpgradeReward",5,offsetof(ArtifactStar,UpgradeReward) }
};
KeyType ArtifactStrengthenKeys[]={
    {"Id",0,offsetof(ArtifactStrengthen,Id) },
    {"Type",0,offsetof(ArtifactStrengthen,Type) },
    {"Level",0,offsetof(ArtifactStrengthen,Level) },
    {"RequiredLevel",0,offsetof(ArtifactStrengthen,RequiredLevel) },
    {"CostResourse",5,offsetof(ArtifactStrengthen,CostResourse) },
    {"CostItem1",5,offsetof(ArtifactStrengthen,CostItem1) },
    {"SuccessRate1",0,offsetof(ArtifactStrengthen,SuccessRate1) },
    {"CostItem2",5,offsetof(ArtifactStrengthen,CostItem2) },
    {"SuccessRate2",0,offsetof(ArtifactStrengthen,SuccessRate2) },
    {"UpgradeReward",5,offsetof(ArtifactStrengthen,UpgradeReward) },
    {"Prop",5,offsetof(ArtifactStrengthen,Prop) }
};
KeyType ArtifactUpgradeKeys[]={
    {"Id",0,offsetof(ArtifactUpgrade,Id) },
    {"ArtifactLoot",0,offsetof(ArtifactUpgrade,ArtifactLoot) },
    {"SuccessRate",0,offsetof(ArtifactUpgrade,SuccessRate) },
    {"CostResource",5,offsetof(ArtifactUpgrade,CostResource) },
    {"FailReward",3,offsetof(ArtifactUpgrade,FailReward) },
    {"MoreReward",5,offsetof(ArtifactUpgrade,MoreReward) }
};
KeyType ArtifactWashKeys[]={
    {"Id",0,offsetof(ArtifactWash,Id) },
    {"CostResourse",5,offsetof(ArtifactWash,CostResourse) },
    {"CostItem",5,offsetof(ArtifactWash,CostItem) },
    {"PropertyAddition",5,offsetof(ArtifactWash,PropertyAddition) },
    {"PropertyMin",5,offsetof(ArtifactWash,PropertyMin) }
};
KeyType BackBaseKeys[]={
    {"ID",0,offsetof(BackBase,ID) },
    {"Key",1,offsetof(BackBase,Key) },
    {"Value",0,offsetof(BackBase,Value) },
    {"Des",1,offsetof(BackBase,Des) }
};
KeyType BackGiftKeys[]={
    {"ID",0,offsetof(BackGift,ID) },
    {"Level",3,offsetof(BackGift,Level) },
    {"Turn",0,offsetof(BackGift,Turn) },
    {"Price",3,offsetof(BackGift,Price) },
    {"Item",5,offsetof(BackGift,Item) }
};
KeyType BackLoginKeys[]={
    {"ID",0,offsetof(BackLogin,ID) },
    {"Level",3,offsetof(BackLogin,Level) },
    {"Turn",0,offsetof(BackLogin,Turn) },
    {"LoginReward",5,offsetof(BackLogin,LoginReward) }
};
KeyType BackPayKeys[]={
    {"ID",0,offsetof(BackPay,ID) },
    {"Level",3,offsetof(BackPay,Level) },
    {"Cost",0,offsetof(BackPay,Cost) },
    {"Item",5,offsetof(BackPay,Item) }
};
KeyType BossChallengeCostKeys[]={
    {"ChallengeTime",0,offsetof(BossChallengeCost,ChallengeTime) },
    {"Cost",0,offsetof(BossChallengeCost,Cost) }
};
KeyType BossDropKeys[]={
    {"ID",0,offsetof(BossDrop,ID) },
    {"GuildLv",0,offsetof(BossDrop,GuildLv) },
    {"Energy",0,offsetof(BossDrop,Energy) },
    {"DropBoxID",5,offsetof(BossDrop,DropBoxID) }
};
KeyType BossRewardKeys[]={
    {"ID",0,offsetof(BossReward,ID) },
    {"Rank",0,offsetof(BossReward,Rank) },
    {"Reward",5,offsetof(BossReward,Reward) }
};
KeyType BoxKeys[]={
    {"ID",0,offsetof(Box,ID) },
    {"Level",0,offsetof(Box,Level) },
    {"Item",0,offsetof(Box,Item) },
    {"DropBoxID",0,offsetof(Box,DropBoxID) },
    {"ItemGet",5,offsetof(Box,ItemGet) }
};
KeyType BuffListKeys[]={
    {"ID",0,offsetof(BuffList,ID) },
    {"Type",0,offsetof(BuffList,Type) },
    {"BuffID",0,offsetof(BuffList,BuffID) }
};
KeyType BuyDirectKeys[]={
    {"ItemID",0,offsetof(BuyDirect,ItemID) },
    {"Price",0,offsetof(BuyDirect,Price) }
};
KeyType CampActOpenKeys[]={
    {"OpenTime",0,offsetof(CampActOpen,OpenTime) },
    {"ActivityID",3,offsetof(CampActOpen,ActivityID) }
};
KeyType CampBaseKeys[]={
    {"ID",0,offsetof(CampBase,ID) },
    {"Key",1,offsetof(CampBase,Key) },
    {"Value",1,offsetof(CampBase,Value) },
    {"Des",1,offsetof(CampBase,Des) }
};
KeyType CampGrainKeys[]={
    {"ID",0,offsetof(CampGrain,ID) },
    {"GrainName",1,offsetof(CampGrain,GrainName) },
    {"GrainType",0,offsetof(CampGrain,GrainType) },
    {"RewardNum",0,offsetof(CampGrain,RewardNum) },
    {"RobRewardNum",0,offsetof(CampGrain,RobRewardNum) },
    {"NextGrain",0,offsetof(CampGrain,NextGrain) },
    {"NextProb",0,offsetof(CampGrain,NextProb) },
    {"PayType",0,offsetof(CampGrain,PayType) },
    {"PayNum",0,offsetof(CampGrain,PayNum) }
};
KeyType CampMineKeys[]={
    {"ID",0,offsetof(CampMine,ID) },
    {"MineName",1,offsetof(CampMine,MineName) },
    {"MineNum",0,offsetof(CampMine,MineNum) },
    {"PayType",0,offsetof(CampMine,PayType) },
    {"PayNum",0,offsetof(CampMine,PayNum) },
    {"Produce",0,offsetof(CampMine,Produce) },
    {"RobReward",0,offsetof(CampMine,RobReward) },
    {"RobExtraDiamond",0,offsetof(CampMine,RobExtraDiamond) }
};
KeyType CampMineProductionKeys[]={
    {"Id",0,offsetof(CampMineProduction,Id) },
    {"MineType",0,offsetof(CampMineProduction,MineType) },
    {"PlayerLevel",0,offsetof(CampMineProduction,PlayerLevel) },
    {"Award",5,offsetof(CampMineProduction,Award) },
    {"ScoreRate",0,offsetof(CampMineProduction,ScoreRate) },
    {"MaxNum",0,offsetof(CampMineProduction,MaxNum) },
    {"RobedRate",0,offsetof(CampMineProduction,RobedRate) },
    {"DropBox",0,offsetof(CampMineProduction,DropBox) },
    {"DropRatio",0,offsetof(CampMineProduction,DropRatio) }
};
KeyType CampMineScoreKeys[]={
    {"ID",0,offsetof(CampMineScore,ID) },
    {"ScoreRate",0,offsetof(CampMineScore,ScoreRate) },
    {"WinScore",0,offsetof(CampMineScore,WinScore) }
};
KeyType CampMineUnlockKeys[]={
    {"ID",0,offsetof(CampMineUnlock,ID) },
    {"RequiredLevel",0,offsetof(CampMineUnlock,RequiredLevel) },
    {"RequiredVipLevel",0,offsetof(CampMineUnlock,RequiredVipLevel) }
};
KeyType CampMineUpgradeKeys[]={
    {"Id",0,offsetof(CampMineUpgrade,Id) },
    {"MineName",1,offsetof(CampMineUpgrade,MineName) },
    {"LastTime",0,offsetof(CampMineUpgrade,LastTime) },
    {"Price",0,offsetof(CampMineUpgrade,Price) },
    {"Score",0,offsetof(CampMineUpgrade,Score) },
    {"FreeTimes",0,offsetof(CampMineUpgrade,FreeTimes) }
};
KeyType CampOfficeRankKeys[]={
    {"PersonRanking",0,offsetof(CampOfficeRank,PersonRanking) },
    {"Office",0,offsetof(CampOfficeRank,Office) }
};
KeyType CampOfficeRightKeys[]={
    {"ID",0,offsetof(CampOfficeRight,ID) },
    {"ThroughNum",0,offsetof(CampOfficeRight,ThroughNum) },
    {"ThroughOnceMoreNum",0,offsetof(CampOfficeRight,ThroughOnceMoreNum) },
    {"RobMineNum",0,offsetof(CampOfficeRight,RobMineNum) },
    {"GrainTransNum",0,offsetof(CampOfficeRight,GrainTransNum) },
    {"GrainCarColorNum",0,offsetof(CampOfficeRight,GrainCarColorNum) },
    {"RobGrainNum",0,offsetof(CampOfficeRight,RobGrainNum) },
    {"WarNum",0,offsetof(CampOfficeRight,WarNum) }
};
KeyType CampRewardKeys[]={
    {"ID",0,offsetof(CampReward,ID) },
    {"RewardID",0,offsetof(CampReward,RewardID) },
    {"Rank",0,offsetof(CampReward,Rank) },
    {"ItemReward",5,offsetof(CampReward,ItemReward) }
};
KeyType CampRoleRewardKeys[]={
    {"ID",0,offsetof(CampRoleReward,ID) },
    {"RewardID",0,offsetof(CampRoleReward,RewardID) },
    {"Rank",3,offsetof(CampRoleReward,Rank) },
    {"ItemReward",5,offsetof(CampRoleReward,ItemReward) }
};
KeyType CampThroughKeys[]={
    {"ID",0,offsetof(CampThrough,ID) },
    {"ThroughID",0,offsetof(CampThrough,ThroughID) },
    {"NextCustomsID",0,offsetof(CampThrough,NextCustomsID) },
    {"ThroughWeight",0,offsetof(CampThrough,ThroughWeight) },
    {"CoinReward",0,offsetof(CampThrough,CoinReward) },
    {"FlopExpend",0,offsetof(CampThrough,FlopExpend) },
    {"OnceMorePay",0,offsetof(CampThrough,OnceMorePay) },
    {"FlopReward",5,offsetof(CampThrough,FlopReward) }
};
KeyType CampThroughItemKeys[]={
    {"ID",0,offsetof(CampThroughItem,ID) },
    {"Level",0,offsetof(CampThroughItem,Level) },
    {"Through",0,offsetof(CampThroughItem,Through) },
    {"ItemGet",5,offsetof(CampThroughItem,ItemGet) }
};
KeyType CampTurntableKeys[]={
    {"ID",0,offsetof(CampTurntable,ID) },
    {"PositionID",0,offsetof(CampTurntable,PositionID) },
    {"Camp",0,offsetof(CampTurntable,Camp) },
    {"ItemCount",0,offsetof(CampTurntable,ItemCount) },
    {"WhetherNotice",0,offsetof(CampTurntable,WhetherNotice) },
    {"Weight",0,offsetof(CampTurntable,Weight) },
    {"ItemBoxID",0,offsetof(CampTurntable,ItemBoxID) }
};
KeyType CampTurntableItemsKeys[]={
    {"ID",0,offsetof(CampTurntableItems,ID) },
    {"ItemBoxID",0,offsetof(CampTurntableItems,ItemBoxID) },
    {"ItemID",0,offsetof(CampTurntableItems,ItemID) },
    {"Weight",0,offsetof(CampTurntableItems,Weight) }
};
KeyType CampWarStreakRewardKeys[]={
    {"WinTimes",0,offsetof(CampWarStreakReward,WinTimes) },
    {"StreakReward",0,offsetof(CampWarStreakReward,StreakReward) },
    {"StreakEndReward",0,offsetof(CampWarStreakReward,StreakEndReward) }
};
KeyType ChannelBaseKeys[]={
    {"ID",0,offsetof(ChannelBase,ID) },
    {"Key",1,offsetof(ChannelBase,Key) },
    {"Value",0,offsetof(ChannelBase,Value) },
    {"Des",1,offsetof(ChannelBase,Des) }
};
KeyType ChapterKeys[]={
    {"ChapterID",0,offsetof(Chapter,ChapterID) },
    {"SceneLine",0,offsetof(Chapter,SceneLine) },
    {"LastChapters",3,offsetof(Chapter,LastChapters) },
    {"NextChapters",3,offsetof(Chapter,NextChapters) },
    {"OpenLv",0,offsetof(Chapter,OpenLv) },
    {"Boxes",5,offsetof(Chapter,Boxes) },
    {"Fights",3,offsetof(Chapter,Fights) }
};
KeyType ChatBaseKeys[]={
    {"ID",0,offsetof(ChatBase,ID) },
    {"Key",1,offsetof(ChatBase,Key) },
    {"Value",0,offsetof(ChatBase,Value) },
    {"Des",1,offsetof(ChatBase,Des) }
};
KeyType ChatNoticeKeys[]={
    {"ID",0,offsetof(ChatNotice,ID) },
    {"Key",1,offsetof(ChatNotice,Key) },
    {"Content",1,offsetof(ChatNotice,Content) },
    {"Des",1,offsetof(ChatNotice,Des) }
};
KeyType CoinKeys[]={
    {"ID",0,offsetof(Coin,ID) },
    {"OneCoinItemID",0,offsetof(Coin,OneCoinItemID) }
};
KeyType CoinPurchaseKeys[]={
    {"BuyTime",0,offsetof(CoinPurchase,BuyTime) },
    {"Cost",0,offsetof(CoinPurchase,Cost) },
    {"Add",0,offsetof(CoinPurchase,Add) }
};
KeyType CostBaseKeys[]={
    {"ID",0,offsetof(CostBase,ID) },
    {"Key",1,offsetof(CostBase,Key) },
    {"Name",1,offsetof(CostBase,Name) },
    {"Des",1,offsetof(CostBase,Des) },
    {"Value",0,offsetof(CostBase,Value) }
};
KeyType CostSumKeys[]={
    {"Id",0,offsetof(CostSum,Id) },
    {"Sum",0,offsetof(CostSum,Sum) },
    {"ItemReward",5,offsetof(CostSum,ItemReward) }
};
KeyType DailyCostSumKeys[]={
    {"Id",0,offsetof(DailyCostSum,Id) },
    {"Sum",0,offsetof(DailyCostSum,Sum) },
    {"ItemReward",5,offsetof(DailyCostSum,ItemReward) }
};
KeyType DailyLoginKeys[]={
    {"Days",0,offsetof(DailyLogin,Days) },
    {"ItemReward",5,offsetof(DailyLogin,ItemReward) },
    {"Des",1,offsetof(DailyLogin,Des) }
};
KeyType DailyPaySumKeys[]={
    {"Id",0,offsetof(DailyPaySum,Id) },
    {"Sum",0,offsetof(DailyPaySum,Sum) },
    {"ItemReward",5,offsetof(DailyPaySum,ItemReward) }
};
KeyType DailySumPayRewardKeys[]={
    {"Id",0,offsetof(DailySumPayReward,Id) },
    {"Day",0,offsetof(DailySumPayReward,Day) },
    {"Index",0,offsetof(DailySumPayReward,Index) },
    {"PaySum",0,offsetof(DailySumPayReward,PaySum) },
    {"ItemReward",5,offsetof(DailySumPayReward,ItemReward) }
};
KeyType DepreFactorKeys[]={
    {"ID",0,offsetof(DepreFactor,ID) },
    {"Factor",6,offsetof(DepreFactor,Factor) }
};
KeyType DropOtherKeys[]={
    {"DropType",1,offsetof(DropOther,DropType) },
    {"Des",1,offsetof(DropOther,Des) },
    {"DropBox",0,offsetof(DropOther,DropBox) }
};
KeyType DropboxKeys[]={
    {"ID",0,offsetof(Dropbox,ID) },
    {"DropboxID",0,offsetof(Dropbox,DropboxID) },
    {"ItemID",0,offsetof(Dropbox,ItemID) },
    {"ItemType",0,offsetof(Dropbox,ItemType) },
    {"ItemNum",0,offsetof(Dropbox,ItemNum) },
    {"Probablity",0,offsetof(Dropbox,Probablity) },
    {"DropType",0,offsetof(Dropbox,DropType) }
};
KeyType EmailKeys[]={
    {"ID",0,offsetof(Email,ID) },
    {"Key",1,offsetof(Email,Key) },
    {"Titile",1,offsetof(Email,Titile) },
    {"Content",1,offsetof(Email,Content) },
    {"AttachID",3,offsetof(Email,AttachID) },
    {"SenderName",1,offsetof(Email,SenderName) }
};
KeyType EquipKeys[]={
    {"ID",0,offsetof(Equip,ID) },
    {"Valid",0,offsetof(Equip,Valid) },
    {"Job",0,offsetof(Equip,Job) },
    {"Part",0,offsetof(Equip,Part) },
    {"Star",0,offsetof(Equip,Star) },
    {"PropID",3,offsetof(Equip,PropID) },
    {"PropValue",3,offsetof(Equip,PropValue) },
    {"LevelValue",3,offsetof(Equip,LevelValue) },
    {"LevelLimit",0,offsetof(Equip,LevelLimit) },
    {"LevelCostParameters",3,offsetof(Equip,LevelCostParameters) },
    {"CoinCostIndex",0,offsetof(Equip,CoinCostIndex) },
    {"ActivePropID",3,offsetof(Equip,ActivePropID) },
    {"ActivePropLevels",5,offsetof(Equip,ActivePropLevels) },
    {"PlateOpenLevel",0,offsetof(Equip,PlateOpenLevel) },
    {"InitialLevel",0,offsetof(Equip,InitialLevel) },
    {"PlateCostItems",5,offsetof(Equip,PlateCostItems) },
    {"PlateNewID",0,offsetof(Equip,PlateNewID) },
    {"QuenchPropCount",0,offsetof(Equip,QuenchPropCount) },
    {"QuenchPropIndex",0,offsetof(Equip,QuenchPropIndex) },
    {"GemCount",0,offsetof(Equip,GemCount) },
    {"Cost",5,offsetof(Equip,Cost) }
};
KeyType EquipBaseKeys[]={
    {"ID",0,offsetof(EquipBase,ID) },
    {"Key",1,offsetof(EquipBase,Key) },
    {"Value",0,offsetof(EquipBase,Value) },
    {"Des",1,offsetof(EquipBase,Des) }
};
KeyType EquipCoinCostKeys[]={
    {"ID",0,offsetof(EquipCoinCost,ID) },
    {"Parameters",1,offsetof(EquipCoinCost,Parameters) }
};
KeyType EquipMaterialGroupKeys[]={
    {"Id",0,offsetof(EquipMaterialGroup,Id) },
    {"Items",5,offsetof(EquipMaterialGroup,Items) }
};
KeyType EquipRecycleKeys[]={
    {"Id",0,offsetof(EquipRecycle,Id) },
    {"Star",0,offsetof(EquipRecycle,Star) },
    {"Job",0,offsetof(EquipRecycle,Job) },
    {"Part",0,offsetof(EquipRecycle,Part) },
    {"MaterialGroup",3,offsetof(EquipRecycle,MaterialGroup) }
};
KeyType EventRecruitKeys[]={
    {"ID",0,offsetof(EventRecruit,ID) },
    {"HeroID",0,offsetof(EventRecruit,HeroID) }
};
KeyType ExchangeKeys[]={
    {"ID",0,offsetof(Exchange,ID) },
    {"ShopID",0,offsetof(Exchange,ShopID) },
    {"ShopItemID",0,offsetof(Exchange,ShopItemID) },
    {"CostValue",0,offsetof(Exchange,CostValue) },
    {"Count",0,offsetof(Exchange,Count) }
};
KeyType ExchangeBaseKeys[]={
    {"ID",0,offsetof(ExchangeBase,ID) },
    {"Key",1,offsetof(ExchangeBase,Key) },
    {"Value",1,offsetof(ExchangeBase,Value) },
    {"Des",1,offsetof(ExchangeBase,Des) }
};
KeyType FightSetKeys[]={
    {"FightSetID",0,offsetof(FightSet,FightSetID) },
    {"FightName",1,offsetof(FightSet,FightName) },
    {"FightScene",1,offsetof(FightSet,FightScene) },
    {"FightType",0,offsetof(FightSet,FightType) },
    {"IsBoss",0,offsetof(FightSet,IsBoss) },
    {"MonsterLv",0,offsetof(FightSet,MonsterLv) },
    {"Monster1",3,offsetof(FightSet,Monster1) },
    {"Monster2",3,offsetof(FightSet,Monster2) },
    {"Monster3",3,offsetof(FightSet,Monster3) },
    {"Monster4",3,offsetof(FightSet,Monster4) },
    {"Monster5",3,offsetof(FightSet,Monster5) },
    {"Monster6",3,offsetof(FightSet,Monster6) },
    {"Support1",3,offsetof(FightSet,Support1) },
    {"Support2",3,offsetof(FightSet,Support2) },
    {"Support3",3,offsetof(FightSet,Support3) },
    {"Support4",3,offsetof(FightSet,Support4) },
    {"Support5",3,offsetof(FightSet,Support5) },
    {"Support6",3,offsetof(FightSet,Support6) },
    {"RolePosition",0,offsetof(FightSet,RolePosition) }
};
KeyType FormKeys[]={
    {"ID",0,offsetof(Form,ID) },
    {"FormNum",0,offsetof(Form,FormNum) },
    {"RoleLevel",0,offsetof(Form,RoleLevel) }
};
KeyType FormRestrictKeys[]={
    {"ID",0,offsetof(FormRestrict,ID) },
    {"Key",1,offsetof(FormRestrict,Key) },
    {"Restrict",5,offsetof(FormRestrict,Restrict) }
};
KeyType FragConvertKeys[]={
    {"GiftItem",0,offsetof(FragConvert,GiftItem) },
    {"Convert",0,offsetof(FragConvert,Convert) }
};
KeyType FundKeys[]={
    {"ID",0,offsetof(Fund,ID) },
    {"Rewardlevel",0,offsetof(Fund,Rewardlevel) },
    {"AwardItem",5,offsetof(Fund,AwardItem) }
};
KeyType FundBaseKeys[]={
    {"ID",0,offsetof(FundBase,ID) },
    {"ID1",0,offsetof(FundBase,ID1) },
    {"Key",1,offsetof(FundBase,Key) },
    {"Value",1,offsetof(FundBase,Value) },
    {"Des",1,offsetof(FundBase,Des) }
};
KeyType GemKeys[]={
    {"ID",0,offsetof(Gem,ID) },
    {"Level",0,offsetof(Gem,Level) },
    {"PropID",0,offsetof(Gem,PropID) },
    {"PropValue",0,offsetof(Gem,PropValue) },
    {"UseJob",3,offsetof(Gem,UseJob) }
};
KeyType GrowingKeys[]={
    {"ID",0,offsetof(Growing,ID) },
    {"Prob",0,offsetof(Growing,Prob) },
    {"Weight",0,offsetof(Growing,Weight) },
    {"Plus",0,offsetof(Growing,Plus) }
};
KeyType GuildBaseKeys[]={
    {"GuildBaseID",0,offsetof(GuildBase,GuildBaseID) },
    {"Key",1,offsetof(GuildBase,Key) },
    {"Value",1,offsetof(GuildBase,Value) },
    {"Des",1,offsetof(GuildBase,Des) }
};
KeyType GuildBattleChatKeys[]={
    {"ID",0,offsetof(GuildBattleChat,ID) },
    {"Key",1,offsetof(GuildBattleChat,Key) },
    {"Content",1,offsetof(GuildBattleChat,Content) },
    {"Des",1,offsetof(GuildBattleChat,Des) }
};
KeyType GuildBattleCityKeys[]={
    {"CityID",0,offsetof(GuildBattleCity,CityID) },
    {"CityName",1,offsetof(GuildBattleCity,CityName) },
    {"Shop",0,offsetof(GuildBattleCity,Shop) },
    {"ConquerAward",5,offsetof(GuildBattleCity,ConquerAward) },
    {"GateScore",0,offsetof(GuildBattleCity,GateScore) },
    {"SpotScore",5,offsetof(GuildBattleCity,SpotScore) },
    {"SpotHonor",5,offsetof(GuildBattleCity,SpotHonor) }
};
KeyType GuildBattleFightKeys[]={
    {"GateLevel",0,offsetof(GuildBattleFight,GateLevel) },
    {"FightSetId",0,offsetof(GuildBattleFight,FightSetId) }
};
KeyType GuildBattleLogKeys[]={
    {"ID",0,offsetof(GuildBattleLog,ID) },
    {"Key",1,offsetof(GuildBattleLog,Key) },
    {"Language",1,offsetof(GuildBattleLog,Language) },
    {"Content",1,offsetof(GuildBattleLog,Content) }
};
KeyType GuildBattlePersonRankKeys[]={
    {"PersonalRank",0,offsetof(GuildBattlePersonRank,PersonalRank) },
    {"PersonalRankRate",0,offsetof(GuildBattlePersonRank,PersonalRankRate) }
};
KeyType GuildBattleRankKeys[]={
    {"GuildRank",0,offsetof(GuildBattleRank,GuildRank) },
    {"Award",5,offsetof(GuildBattleRank,Award) },
    {"GuildRate",0,offsetof(GuildBattleRank,GuildRate) },
    {"DropBox",5,offsetof(GuildBattleRank,DropBox) }
};
KeyType GuildBattleSeverPersonRankKeys[]={
    {"PersonalRank",0,offsetof(GuildBattleSeverPersonRank,PersonalRank) },
    {"Award",5,offsetof(GuildBattleSeverPersonRank,Award) }
};
KeyType GuildChapterKeys[]={
    {"ID",0,offsetof(GuildChapter,ID) },
    {"OpenGuildLv",0,offsetof(GuildChapter,OpenGuildLv) },
    {"OpenCost",0,offsetof(GuildChapter,OpenCost) },
    {"MaxFightNum",0,offsetof(GuildChapter,MaxFightNum) },
    {"FightCostExploit",0,offsetof(GuildChapter,FightCostExploit) },
    {"FightID",0,offsetof(GuildChapter,FightID) },
    {"LastTime",0,offsetof(GuildChapter,LastTime) }
};
KeyType GuildChapterFightKeys[]={
    {"ID",0,offsetof(GuildChapterFight,ID) },
    {"FightID",0,offsetof(GuildChapterFight,FightID) },
    {"FightSequence",0,offsetof(GuildChapterFight,FightSequence) },
    {"FightSetID",0,offsetof(GuildChapterFight,FightSetID) },
    {"DropBoxID",0,offsetof(GuildChapterFight,DropBoxID) }
};
KeyType GuildDungeonKeys[]={
    {"DungeonId",0,offsetof(GuildDungeon,DungeonId) },
    {"BossGroup",3,offsetof(GuildDungeon,BossGroup) },
    {"FightBackGround",0,offsetof(GuildDungeon,FightBackGround) },
    {"SpotDes",0,offsetof(GuildDungeon,SpotDes) },
    {"Spot",3,offsetof(GuildDungeon,Spot) },
    {"ChallengeAward",5,offsetof(GuildDungeon,ChallengeAward) },
    {"PreDungeonId",0,offsetof(GuildDungeon,PreDungeonId) },
    {"LevelRequired",0,offsetof(GuildDungeon,LevelRequired) }
};
KeyType GuildDungeonAwardKeys[]={
    {"Id",0,offsetof(GuildDungeonAward,Id) },
    {"Dungeon",0,offsetof(GuildDungeonAward,Dungeon) },
    {"Rank",3,offsetof(GuildDungeonAward,Rank) },
    {"Award",5,offsetof(GuildDungeonAward,Award) }
};
KeyType GuildDungeonSpotKeys[]={
    {"SpotId",0,offsetof(GuildDungeonSpot,SpotId) },
    {"FightSetId",0,offsetof(GuildDungeonSpot,FightSetId) },
    {"FightBackGround",0,offsetof(GuildDungeonSpot,FightBackGround) },
    {"StarCondition",0,offsetof(GuildDungeonSpot,StarCondition) },
    {"DropBoxId",0,offsetof(GuildDungeonSpot,DropBoxId) }
};
KeyType GuildFlagKeys[]={
    {"GuildFlagLv",0,offsetof(GuildFlag,GuildFlagLv) },
    {"GuildLvLimit",0,offsetof(GuildFlag,GuildLvLimit) },
    {"UpCost",0,offsetof(GuildFlag,UpCost) }
};
KeyType GuildFlagLvKeys[]={
    {"OwnFlagLv",0,offsetof(GuildFlagLv,OwnFlagLv) },
    {"FlagLv",0,offsetof(GuildFlagLv,FlagLv) },
    {"ProValue",5,offsetof(GuildFlagLv,ProValue) },
    {"UpCost",0,offsetof(GuildFlagLv,UpCost) }
};
KeyType GuildLogKeys[]={
    {"ID",0,offsetof(GuildLog,ID) },
    {"Key",1,offsetof(GuildLog,Key) },
    {"Language",1,offsetof(GuildLog,Language) },
    {"Content",1,offsetof(GuildLog,Content) }
};
KeyType GuildLvKeys[]={
    {"Lv",0,offsetof(GuildLv,Lv) },
    {"GuildExp",0,offsetof(GuildLv,GuildExp) },
    {"MaxMember",0,offsetof(GuildLv,MaxMember) },
    {"BossEnergyMax",0,offsetof(GuildLv,BossEnergyMax) },
    {"BossDrop",5,offsetof(GuildLv,BossDrop) },
    {"BossFightSet",0,offsetof(GuildLv,BossFightSet) },
    {"BossPosition",0,offsetof(GuildLv,BossPosition) },
    {"KillGuildExp",0,offsetof(GuildLv,KillGuildExp) },
    {"KillBossAddFund",0,offsetof(GuildLv,KillBossAddFund) },
    {"BossCoinCost",0,offsetof(GuildLv,BossCoinCost) },
    {"BossCoinExploit",0,offsetof(GuildLv,BossCoinExploit) },
    {"BossCoinEnergy",0,offsetof(GuildLv,BossCoinEnergy) },
    {"BossGoldCost",0,offsetof(GuildLv,BossGoldCost) },
    {"BossGoldExploit",0,offsetof(GuildLv,BossGoldExploit) },
    {"BossGoldEnergy",0,offsetof(GuildLv,BossGoldEnergy) },
    {"BossBattleCostGold",0,offsetof(GuildLv,BossBattleCostGold) },
    {"DonateCoinCost",0,offsetof(GuildLv,DonateCoinCost) },
    {"DonateCoinExploit",0,offsetof(GuildLv,DonateCoinExploit) },
    {"DonateCoinFund",0,offsetof(GuildLv,DonateCoinFund) },
    {"DonateCoinGuildExp",0,offsetof(GuildLv,DonateCoinGuildExp) },
    {"DonateGoldCost",0,offsetof(GuildLv,DonateGoldCost) },
    {"DonateGoldExploit",0,offsetof(GuildLv,DonateGoldExploit) },
    {"DonateGoldFund",0,offsetof(GuildLv,DonateGoldFund) },
    {"DonateGoldGuildExp",0,offsetof(GuildLv,DonateGoldGuildExp) }
};
KeyType GuildMemberKeys[]={
    {"GuildPosition",0,offsetof(GuildMember,GuildPosition) },
    {"PositionExp",0,offsetof(GuildMember,PositionExp) },
    {"ISGuildFight",0,offsetof(GuildMember,ISGuildFight) },
    {"GuildBossCoinNum",0,offsetof(GuildMember,GuildBossCoinNum) },
    {"GuildBossGoldNum",0,offsetof(GuildMember,GuildBossGoldNum) },
    {"GuildBossFightNum",0,offsetof(GuildMember,GuildBossFightNum) },
    {"KickCost",0,offsetof(GuildMember,KickCost) },
    {"GuildDonateCoinNum",0,offsetof(GuildMember,GuildDonateCoinNum) },
    {"GuildDonateGoldNum",0,offsetof(GuildMember,GuildDonateGoldNum) }
};
KeyType HeroKeys[]={
    {"HeroID",0,offsetof(Hero,HeroID) },
    {"Name",1,offsetof(Hero,Name) },
    {"HeroType",0,offsetof(Hero,HeroType) },
    {"ItemColor",0,offsetof(Hero,ItemColor) },
    {"Country",0,offsetof(Hero,Country) },
    {"Job",0,offsetof(Hero,Job) },
    {"StartStar",0,offsetof(Hero,StartStar) },
    {"MaxStar",0,offsetof(Hero,MaxStar) },
    {"Quality",0,offsetof(Hero,Quality) },
    {"Frag",0,offsetof(Hero,Frag) },
    {"Equips",3,offsetof(Hero,Equips) },
    {"Anger",0,offsetof(Hero,Anger) },
    {"MaxAnger",0,offsetof(Hero,MaxAnger) },
    {"HP",0,offsetof(Hero,HP) },
    {"Atk",0,offsetof(Hero,Atk) },
    {"Matk",0,offsetof(Hero,Matk) },
    {"DEF",0,offsetof(Hero,DEF) },
    {"MDEF",0,offsetof(Hero,MDEF) },
    {"Hit",0,offsetof(Hero,Hit) },
    {"Duck",0,offsetof(Hero,Duck) },
    {"Crit",0,offsetof(Hero,Crit) },
    {"CounterCrit",0,offsetof(Hero,CounterCrit) },
    {"CounterATK",0,offsetof(Hero,CounterATK) },
    {"DCounterATK",0,offsetof(Hero,DCounterATK) },
    {"Parry",0,offsetof(Hero,Parry) },
    {"GiftID",0,offsetof(Hero,GiftID) },
    {"CounterATKSkillID",0,offsetof(Hero,CounterATKSkillID) },
    {"ExpIndex",0,offsetof(Hero,ExpIndex) },
    {"LevelBase",0,offsetof(Hero,LevelBase) },
    {"MaxLV",0,offsetof(Hero,MaxLV) },
    {"Valid",0,offsetof(Hero,Valid) },
    {"Male",0,offsetof(Hero,Male) },
    {"Label",3,offsetof(Hero,Label) },
    {"SoulSkill",3,offsetof(Hero,SoulSkill) }
};
KeyType HeroBaseKeys[]={
    {"HeroBaseID",0,offsetof(HeroBase,HeroBaseID) },
    {"Key",1,offsetof(HeroBase,Key) },
    {"Value",6,offsetof(HeroBase,Value) },
    {"Des",1,offsetof(HeroBase,Des) }
};
KeyType HeroExpKeys[]={
    {"ExpID",0,offsetof(HeroExp,ExpID) },
    {"ExpIndex",0,offsetof(HeroExp,ExpIndex) },
    {"Level",0,offsetof(HeroExp,Level) },
    {"BaseRoleLv",0,offsetof(HeroExp,BaseRoleLv) },
    {"Exp",0,offsetof(HeroExp,Exp) },
    {"RecycleExp",0,offsetof(HeroExp,RecycleExp) }
};
KeyType HeroGiftKeys[]={
    {"GiftID",0,offsetof(HeroGift,GiftID) },
    {"NextID",0,offsetof(HeroGift,NextID) },
    {"GiftLv",0,offsetof(HeroGift,GiftLv) },
    {"HpBase",0,offsetof(HeroGift,HpBase) },
    {"PatkBase",0,offsetof(HeroGift,PatkBase) },
    {"MatkBase",0,offsetof(HeroGift,MatkBase) },
    {"PdefBase",0,offsetof(HeroGift,PdefBase) },
    {"MdefBase",0,offsetof(HeroGift,MdefBase) },
    {"SkillID",0,offsetof(HeroGift,SkillID) },
    {"AngerSkillID",0,offsetof(HeroGift,AngerSkillID) },
    {"GiftSkillID",0,offsetof(HeroGift,GiftSkillID) },
    {"StartSkillID",0,offsetof(HeroGift,StartSkillID) },
    {"DieSkillID",0,offsetof(HeroGift,DieSkillID) },
    {"GiftPropId",3,offsetof(HeroGift,GiftPropId) },
    {"GiftLvLimit",0,offsetof(HeroGift,GiftLvLimit) },
    {"GiftItem",5,offsetof(HeroGift,GiftItem) },
    {"NeedStar",0,offsetof(HeroGift,NeedStar) },
    {"Command",0,offsetof(HeroGift,Command) },
    {"Power",0,offsetof(HeroGift,Power) },
    {"IQ",0,offsetof(HeroGift,IQ) },
    {"Cost",5,offsetof(HeroGift,Cost) }
};
KeyType HeroGiftPropKeys[]={
    {"GiftPropId",0,offsetof(HeroGiftProp,GiftPropId) },
    {"PropId",0,offsetof(HeroGiftProp,PropId) },
    {"PropType",0,offsetof(HeroGiftProp,PropType) },
    {"PropValue",0,offsetof(HeroGiftProp,PropValue) },
    {"GiftLv",0,offsetof(HeroGiftProp,GiftLv) },
    {"ActionValue",0,offsetof(HeroGiftProp,ActionValue) }
};
KeyType HeroGiftSkillKeys[]={
    {"ID",0,offsetof(HeroGiftSkill,ID) },
    {"HeroID",0,offsetof(HeroGiftSkill,HeroID) },
    {"GiftLv",0,offsetof(HeroGiftSkill,GiftLv) },
    {"StartSkillID",0,offsetof(HeroGiftSkill,StartSkillID) },
    {"DieSkillID",0,offsetof(HeroGiftSkill,DieSkillID) }
};
KeyType HeroRecycleKeys[]={
    {"Id",0,offsetof(HeroRecycle,Id) },
    {"Grade",0,offsetof(HeroRecycle,Grade) },
    {"Quality",0,offsetof(HeroRecycle,Quality) },
    {"Items",5,offsetof(HeroRecycle,Items) }
};
KeyType HeroSkinKeys[]={
    {"ID",0,offsetof(HeroSkin,ID) },
    {"HeroID",0,offsetof(HeroSkin,HeroID) },
    {"SkinHeroID",0,offsetof(HeroSkin,SkinHeroID) },
    {"Time",0,offsetof(HeroSkin,Time) },
    {"Price",5,offsetof(HeroSkin,Price) },
    {"Marker",0,offsetof(HeroSkin,Marker) },
    {"ItemPrice",5,offsetof(HeroSkin,ItemPrice) }
};
KeyType HeroSoulKeys[]={
    {"SkillID",0,offsetof(HeroSoul,SkillID) },
    {"Cost",0,offsetof(HeroSoul,Cost) }
};
KeyType HeroStarKeys[]={
    {"ID",0,offsetof(HeroStar,ID) },
    {"HeroID",0,offsetof(HeroStar,HeroID) },
    {"Star",0,offsetof(HeroStar,Star) },
    {"GiftItem",5,offsetof(HeroStar,GiftItem) },
    {"HpGrowth",0,offsetof(HeroStar,HpGrowth) },
    {"PatkGrowth",0,offsetof(HeroStar,PatkGrowth) },
    {"MatkGrowth",0,offsetof(HeroStar,MatkGrowth) },
    {"PdefGrowth",0,offsetof(HeroStar,PdefGrowth) },
    {"MdefGrowth",0,offsetof(HeroStar,MdefGrowth) },
    {"Cost",5,offsetof(HeroStar,Cost) }
};
KeyType HeroStarRecycleKeys[]={
    {"Id",0,offsetof(HeroStarRecycle,Id) },
    {"Star",0,offsetof(HeroStarRecycle,Star) },
    {"Quality",0,offsetof(HeroStarRecycle,Quality) },
    {"Frag",0,offsetof(HeroStarRecycle,Frag) }
};
KeyType ItemKeys[]={
    {"ItemID",0,offsetof(Item,ItemID) },
    {"ItemType",0,offsetof(Item,ItemType) },
    {"ItemColor",0,offsetof(Item,ItemColor) },
    {"ItemPropLimit",3,offsetof(Item,ItemPropLimit) },
    {"ItemPropType",0,offsetof(Item,ItemPropType) },
    {"ItemPropCost",5,offsetof(Item,ItemPropCost) },
    {"ItemPropValue",0,offsetof(Item,ItemPropValue) },
    {"ItemEffectValue",0,offsetof(Item,ItemEffectValue) },
    {"Prop",0,offsetof(Item,Prop) },
    {"CombineType",0,offsetof(Item,CombineType) },
    {"CombineResult",0,offsetof(Item,CombineResult) },
    {"CombineCount",0,offsetof(Item,CombineCount) },
    {"CombineRequire",5,offsetof(Item,CombineRequire) },
    {"CombineCost",5,offsetof(Item,CombineCost) },
    {"ItemSave",0,offsetof(Item,ItemSave) },
    {"ItemTips",0,offsetof(Item,ItemTips) },
    {"ErrorType",0,offsetof(Item,ErrorType) },
    {"Recycle",3,offsetof(Item,Recycle) },
    {"RecycleItem",5,offsetof(Item,RecycleItem) },
    {"MaxUse",0,offsetof(Item,MaxUse) },
    {"Artifact",0,offsetof(Item,Artifact) }
};
KeyType LevelUpRewardKeys[]={
    {"Level",0,offsetof(LevelUpReward,Level) },
    {"RewardType",0,offsetof(LevelUpReward,RewardType) },
    {"ItemReward",5,offsetof(LevelUpReward,ItemReward) }
};
KeyType LoginActRewardKeys[]={
    {"ID",0,offsetof(LoginActReward,ID) },
    {"Days",0,offsetof(LoginActReward,Days) },
    {"RewardType",0,offsetof(LoginActReward,RewardType) },
    {"ItemReward",5,offsetof(LoginActReward,ItemReward) }
};
KeyType LotteryKeys[]={
    {"Count",0,offsetof(Lottery,Count) },
    {"VIP",0,offsetof(Lottery,VIP) },
    {"Cost",5,offsetof(Lottery,Cost) },
    {"Get",0,offsetof(Lottery,Get) },
    {"Get1",5,offsetof(Lottery,Get1) }
};
KeyType LotteryBaseKeys[]={
    {"ID",0,offsetof(LotteryBase,ID) },
    {"Key",1,offsetof(LotteryBase,Key) },
    {"Value",0,offsetof(LotteryBase,Value) },
    {"Des",1,offsetof(LotteryBase,Des) }
};
KeyType LuckyTurntableKeys[]={
    {"ItemID",0,offsetof(LuckyTurntable,ItemID) },
    {"PositionID",0,offsetof(LuckyTurntable,PositionID) },
    {"Count",0,offsetof(LuckyTurntable,Count) },
    {"WhetherNotice",0,offsetof(LuckyTurntable,WhetherNotice) },
    {"Strengthen",0,offsetof(LuckyTurntable,Strengthen) }
};
KeyType LuckyTurntableBaseKeys[]={
    {"ID",0,offsetof(LuckyTurntableBase,ID) },
    {"Key",1,offsetof(LuckyTurntableBase,Key) },
    {"Value",1,offsetof(LuckyTurntableBase,Value) }
};
KeyType LuckyTurntableItemsKeys[]={
    {"ID",0,offsetof(LuckyTurntableItems,ID) },
    {"ItemBoxID",0,offsetof(LuckyTurntableItems,ItemBoxID) },
    {"ItemID",0,offsetof(LuckyTurntableItems,ItemID) },
    {"Count",0,offsetof(LuckyTurntableItems,Count) },
    {"Weight",0,offsetof(LuckyTurntableItems,Weight) }
};
KeyType LuckyTurntableValueKeys[]={
    {"ID",0,offsetof(LuckyTurntableValue,ID) },
    {"LuckyValue",0,offsetof(LuckyTurntableValue,LuckyValue) },
    {"ItemBoxID",0,offsetof(LuckyTurntableValue,ItemBoxID) }
};
KeyType MailDoubleKeys[]={
    {"ID",0,offsetof(MailDouble,ID) },
    {"ItemReward",5,offsetof(MailDouble,ItemReward) },
    {"Des",1,offsetof(MailDouble,Des) }
};
KeyType MiscKeys[]={
    {"ID",0,offsetof(Misc,ID) },
    {"Key",1,offsetof(Misc,Key) },
    {"Value",1,offsetof(Misc,Value) },
    {"Des",1,offsetof(Misc,Des) }
};
KeyType MonsterBaseKeys[]={
    {"MonsterID",0,offsetof(MonsterBase,MonsterID) },
    {"Country",0,offsetof(MonsterBase,Country) },
    {"Name",1,offsetof(MonsterBase,Name) },
    {"Star",0,offsetof(MonsterBase,Star) },
    {"Job",0,offsetof(MonsterBase,Job) },
    {"SkillID",0,offsetof(MonsterBase,SkillID) },
    {"AngerSkillID",0,offsetof(MonsterBase,AngerSkillID) },
    {"GiftSkillID",0,offsetof(MonsterBase,GiftSkillID) },
    {"CounterATKSkillID",0,offsetof(MonsterBase,CounterATKSkillID) },
    {"StartSkillID",0,offsetof(MonsterBase,StartSkillID) },
    {"DieSkillID",0,offsetof(MonsterBase,DieSkillID) },
    {"Anger",0,offsetof(MonsterBase,Anger) },
    {"MaxAnger",0,offsetof(MonsterBase,MaxAnger) },
    {"HP",0,offsetof(MonsterBase,HP) },
    {"Atk",0,offsetof(MonsterBase,Atk) },
    {"Matk",0,offsetof(MonsterBase,Matk) },
    {"DEF",0,offsetof(MonsterBase,DEF) },
    {"MDEF",0,offsetof(MonsterBase,MDEF) },
    {"Hit",0,offsetof(MonsterBase,Hit) },
    {"Duck",0,offsetof(MonsterBase,Duck) },
    {"Crit",0,offsetof(MonsterBase,Crit) },
    {"CounterCrit",0,offsetof(MonsterBase,CounterCrit) },
    {"CounterATK",0,offsetof(MonsterBase,CounterATK) },
    {"DCounterATK",0,offsetof(MonsterBase,DCounterATK) },
    {"Parry",0,offsetof(MonsterBase,Parry) },
    {"Label",3,offsetof(MonsterBase,Label) }
};
KeyType MonsterPropertyKeys[]={
    {"ID",0,offsetof(MonsterProperty,ID) },
    {"Job",0,offsetof(MonsterProperty,Job) },
    {"MonsterLv",0,offsetof(MonsterProperty,MonsterLv) },
    {"Job1",0,offsetof(MonsterProperty,Job1) },
    {"HP",0,offsetof(MonsterProperty,HP) },
    {"Atk",0,offsetof(MonsterProperty,Atk) },
    {"Matk",0,offsetof(MonsterProperty,Matk) },
    {"DEF",0,offsetof(MonsterProperty,DEF) },
    {"MDEF",0,offsetof(MonsterProperty,MDEF) },
    {"Hit",0,offsetof(MonsterProperty,Hit) },
    {"Duck",0,offsetof(MonsterProperty,Duck) },
    {"Crit",0,offsetof(MonsterProperty,Crit) },
    {"CounterCrit",0,offsetof(MonsterProperty,CounterCrit) },
    {"CounterATK",0,offsetof(MonsterProperty,CounterATK) },
    {"DCounterATK",0,offsetof(MonsterProperty,DCounterATK) },
    {"Parry",0,offsetof(MonsterProperty,Parry) }
};
KeyType MonsterStrengthKeys[]={
    {"ID",0,offsetof(MonsterStrength,ID) },
    {"HP",0,offsetof(MonsterStrength,HP) },
    {"Atk",0,offsetof(MonsterStrength,Atk) },
    {"Matk",0,offsetof(MonsterStrength,Matk) },
    {"DEF",0,offsetof(MonsterStrength,DEF) },
    {"MDEF",0,offsetof(MonsterStrength,MDEF) },
    {"Hit",0,offsetof(MonsterStrength,Hit) },
    {"Duck",0,offsetof(MonsterStrength,Duck) },
    {"Crit",0,offsetof(MonsterStrength,Crit) },
    {"CounterCrit",0,offsetof(MonsterStrength,CounterCrit) },
    {"CounterATK",0,offsetof(MonsterStrength,CounterATK) },
    {"DCounterATK",0,offsetof(MonsterStrength,DCounterATK) },
    {"Parry",0,offsetof(MonsterStrength,Parry) },
    {"Difficulty",0,offsetof(MonsterStrength,Difficulty) },
    {"Strength",0,offsetof(MonsterStrength,Strength) }
};
KeyType MountsKeys[]={
    {"ID",0,offsetof(Mounts,ID) },
    {"Star",0,offsetof(Mounts,Star) },
    {"EquipCount",0,offsetof(Mounts,EquipCount) },
    {"MaxLevel",0,offsetof(Mounts,MaxLevel) },
    {"Growing",0,offsetof(Mounts,Growing) },
    {"FeedCost",0,offsetof(Mounts,FeedCost) },
    {"PropsCost",3,offsetof(Mounts,PropsCost) },
    {"Prob",0,offsetof(Mounts,Prob) },
    {"Power",5,offsetof(Mounts,Power) },
    {"UpgradeID",0,offsetof(Mounts,UpgradeID) }
};
KeyType MountsEquipKeys[]={
    {"ID",0,offsetof(MountsEquip,ID) },
    {"slot",0,offsetof(MountsEquip,slot) },
    {"Level",0,offsetof(MountsEquip,Level) },
    {"Prop",5,offsetof(MountsEquip,Prop) }
};
KeyType MountsEquipmentKeys[]={
    {"MountsEquipmentId",0,offsetof(MountsEquipment,MountsEquipmentId) },
    {"ItemID",0,offsetof(MountsEquipment,ItemID) },
    {"Prop",5,offsetof(MountsEquipment,Prop) }
};
KeyType MountsStarKeys[]={
    {"MountStar",0,offsetof(MountsStar,MountStar) },
    {"GrowthRate",5,offsetof(MountsStar,GrowthRate) },
    {"RequiredItem",5,offsetof(MountsStar,RequiredItem) }
};
KeyType MountsTrainKeys[]={
    {"MountTrainID",0,offsetof(MountsTrain,MountTrainID) },
    {"Power",5,offsetof(MountsTrain,Power) },
    {"Slot1EquipId",0,offsetof(MountsTrain,Slot1EquipId) },
    {"Slot1RequiredLevel",0,offsetof(MountsTrain,Slot1RequiredLevel) },
    {"Slot2EquipId",0,offsetof(MountsTrain,Slot2EquipId) },
    {"Slot2RequiredLevel",0,offsetof(MountsTrain,Slot2RequiredLevel) },
    {"Slot3EquipId",0,offsetof(MountsTrain,Slot3EquipId) },
    {"Slot3RequiredLevel",0,offsetof(MountsTrain,Slot3RequiredLevel) },
    {"Slot4EquipId",0,offsetof(MountsTrain,Slot4EquipId) },
    {"Slot4RequiredLevel",0,offsetof(MountsTrain,Slot4RequiredLevel) },
    {"Slot5EquipId",0,offsetof(MountsTrain,Slot5EquipId) },
    {"Slot5RequiredLevel",0,offsetof(MountsTrain,Slot5RequiredLevel) },
    {"Slot6EquipId",0,offsetof(MountsTrain,Slot6EquipId) },
    {"Slot6RequiredLevel",0,offsetof(MountsTrain,Slot6RequiredLevel) }
};
KeyType MysticshopKeys[]={
    {"ShopItemID",0,offsetof(Mysticshop,ShopItemID) },
    {"CostValue",3,offsetof(Mysticshop,CostValue) },
    {"Count",0,offsetof(Mysticshop,Count) }
};
KeyType MysticshopRefreshCostKeys[]={
    {"BuyTime",0,offsetof(MysticshopRefreshCost,BuyTime) },
    {"Cost",0,offsetof(MysticshopRefreshCost,Cost) }
};
KeyType NewYearActivityKeys[]={
    {"ID",0,offsetof(NewYearActivity,ID) },
    {"StrengthValue",0,offsetof(NewYearActivity,StrengthValue) },
    {"ItemDrop",5,offsetof(NewYearActivity,ItemDrop) },
    {"Probability",0,offsetof(NewYearActivity,Probability) },
    {"Des",1,offsetof(NewYearActivity,Des) }
};
KeyType NewYearActivityBaseKeys[]={
    {"ID",0,offsetof(NewYearActivityBase,ID) },
    {"Key",1,offsetof(NewYearActivityBase,Key) },
    {"Value",1,offsetof(NewYearActivityBase,Value) },
    {"Des",1,offsetof(NewYearActivityBase,Des) }
};
KeyType NewYearRecycleKeys[]={
    {"ID",0,offsetof(NewYearRecycle,ID) },
    {"CostItem",5,offsetof(NewYearRecycle,CostItem) },
    {"GetItem",5,offsetof(NewYearRecycle,GetItem) },
    {"Gets",0,offsetof(NewYearRecycle,Gets) }
};
KeyType PayKeys[]={
    {"ID",0,offsetof(Pay,ID) },
    {"Paynull",0,offsetof(Pay,Paynull) },
    {"Type",0,offsetof(Pay,Type) },
    {"Gain",0,offsetof(Pay,Gain) },
    {"FirstGain",0,offsetof(Pay,FirstGain) },
    {"GiveGain",0,offsetof(Pay,GiveGain) },
    {"BuyDay",0,offsetof(Pay,BuyDay) },
    {"Return",0,offsetof(Pay,Return) },
    {"VipExp",0,offsetof(Pay,VipExp) },
    {"ItemID",1,offsetof(Pay,ItemID) },
    {"NameID",1,offsetof(Pay,NameID) },
    {"ConnectTask",0,offsetof(Pay,ConnectTask) },
    {"ConnectTaskClear",0,offsetof(Pay,ConnectTaskClear) }
};
KeyType PayRebateKeys[]={
    {"ID",0,offsetof(PayRebate,ID) },
    {"ReturnItem",5,offsetof(PayRebate,ReturnItem) },
    {"Des",1,offsetof(PayRebate,Des) },
    {"PlatformDes",1,offsetof(PayRebate,PlatformDes) },
    {"PlatformID",0,offsetof(PayRebate,PlatformID) },
    {"Times",0,offsetof(PayRebate,Times) }
};
KeyType PaySumKeys[]={
    {"Id",0,offsetof(PaySum,Id) },
    {"Sum",0,offsetof(PaySum,Sum) },
    {"ItemReward",5,offsetof(PaySum,ItemReward) }
};
KeyType PeakArenaKeys[]={
    {"ID",0,offsetof(PeakArena,ID) },
    {"Formattype",0,offsetof(PeakArena,Formattype) },
    {"Name",1,offsetof(PeakArena,Name) },
    {"Divisiontype",0,offsetof(PeakArena,Divisiontype) },
    {"Name1",1,offsetof(PeakArena,Name1) },
    {"Awardnumber",0,offsetof(PeakArena,Awardnumber) },
    {"CorrespondingDivision",0,offsetof(PeakArena,CorrespondingDivision) },
    {"MaximumSelection",0,offsetof(PeakArena,MaximumSelection) },
    {"UpgradeArenaID",0,offsetof(PeakArena,UpgradeArenaID) },
    {"Capacity",0,offsetof(PeakArena,Capacity) },
    {"UpgradeNum",0,offsetof(PeakArena,UpgradeNum) },
    {"OutNum",0,offsetof(PeakArena,OutNum) },
    {"Rewardmode",0,offsetof(PeakArena,Rewardmode) },
    {"OpenTime",5,offsetof(PeakArena,OpenTime) },
    {"OpenDate",3,offsetof(PeakArena,OpenDate) },
    {"WinRewards",5,offsetof(PeakArena,WinRewards) },
    {"LoseRewards",5,offsetof(PeakArena,LoseRewards) }
};
KeyType PeakArenaBaseKeys[]={
    {"ID",0,offsetof(PeakArenaBase,ID) },
    {"Key",1,offsetof(PeakArenaBase,Key) },
    {"Value",1,offsetof(PeakArenaBase,Value) },
    {"Des",1,offsetof(PeakArenaBase,Des) }
};
KeyType PeakArenaFormatKeys[]={
    {"Formattype",0,offsetof(PeakArenaFormat,Formattype) },
    {"MatchHeroNum",0,offsetof(PeakArenaFormat,MatchHeroNum) },
    {"MatchRole",0,offsetof(PeakArenaFormat,MatchRole) },
    {"CannotForm",3,offsetof(PeakArenaFormat,CannotForm) },
    {"JoinJob",5,offsetof(PeakArenaFormat,JoinJob) },
    {"GameTimes",0,offsetof(PeakArenaFormat,GameTimes) },
    {"WinTimes",0,offsetof(PeakArenaFormat,WinTimes) }
};
KeyType PeakArenaMatchKeys[]={
    {"ID",0,offsetof(PeakArenaMatch,ID) },
    {"Divisiontype",0,offsetof(PeakArenaMatch,Divisiontype) },
    {"Rank",0,offsetof(PeakArenaMatch,Rank) },
    {"UpMatching1",0,offsetof(PeakArenaMatch,UpMatching1) },
    {"UpMatching2",0,offsetof(PeakArenaMatch,UpMatching2) },
    {"UpMatching3",0,offsetof(PeakArenaMatch,UpMatching3) },
    {"DownMatching1",0,offsetof(PeakArenaMatch,DownMatching1) }
};
KeyType PeakArenaRewardKeys[]={
    {"ID",0,offsetof(PeakArenaReward,ID) },
    {"RewardsType",0,offsetof(PeakArenaReward,RewardsType) },
    {"Rank",0,offsetof(PeakArenaReward,Rank) },
    {"GetCoin",0,offsetof(PeakArenaReward,GetCoin) },
    {"GetNum",0,offsetof(PeakArenaReward,GetNum) },
    {"GetTime",0,offsetof(PeakArenaReward,GetTime) }
};
KeyType PeakRobotKeys[]={
    {"ID",0,offsetof(PeakRobot,ID) },
    {"GiftID",0,offsetof(PeakRobot,GiftID) },
    {"LeagueForm",0,offsetof(PeakRobot,LeagueForm) },
    {"sex",0,offsetof(PeakRobot,sex) },
    {"RoleID",0,offsetof(PeakRobot,RoleID) },
    {"name",1,offsetof(PeakRobot,name) },
    {"roleLv",0,offsetof(PeakRobot,roleLv) },
    {"FightValue",0,offsetof(PeakRobot,FightValue) },
    {"Hero1",3,offsetof(PeakRobot,Hero1) },
    {"Hero2",3,offsetof(PeakRobot,Hero2) },
    {"Hero3",3,offsetof(PeakRobot,Hero3) },
    {"Hero4",3,offsetof(PeakRobot,Hero4) },
    {"Hero5",3,offsetof(PeakRobot,Hero5) },
    {"Hero6",3,offsetof(PeakRobot,Hero6) },
    {"SkillList",3,offsetof(PeakRobot,SkillList) },
    {"ArenaShowLv",0,offsetof(PeakRobot,ArenaShowLv) }
};
KeyType PeakUseKeys[]={
    {"ID",0,offsetof(PeakUse,ID) },
    {"UpgradeArenaID",0,offsetof(PeakUse,UpgradeArenaID) },
    {"RobotID",0,offsetof(PeakUse,RobotID) },
    {"Rank",0,offsetof(PeakUse,Rank) }
};
KeyType PowerSetKeys[]={
    {"ID",0,offsetof(PowerSet,ID) },
    {"Type",0,offsetof(PowerSet,Type) },
    {"Key",1,offsetof(PowerSet,Key) },
    {"DefaultSwitch",0,offsetof(PowerSet,DefaultSwitch) },
    {"Des",1,offsetof(PowerSet,Des) }
};
KeyType PushMessagesKeys[]={
    {"MessagesID",0,offsetof(PushMessages,MessagesID) },
    {"Key",1,offsetof(PushMessages,Key) },
    {"MessagesDes",1,offsetof(PushMessages,MessagesDes) }
};
KeyType QuenchPropKeys[]={
    {"ID",0,offsetof(QuenchProp,ID) },
    {"Index",0,offsetof(QuenchProp,Index) },
    {"PropID",0,offsetof(QuenchProp,PropID) },
    {"PropTopValue",0,offsetof(QuenchProp,PropTopValue) },
    {"PropWeight",0,offsetof(QuenchProp,PropWeight) }
};
KeyType QuenchRandKeys[]={
    {"ID",0,offsetof(QuenchRand,ID) },
    {"Index",0,offsetof(QuenchRand,Index) },
    {"Percent",0,offsetof(QuenchRand,Percent) },
    {"Weight",0,offsetof(QuenchRand,Weight) },
    {"Key",0,offsetof(QuenchRand,Key) }
};
KeyType QuestionPointsKeys[]={
    {"Countdown",0,offsetof(QuestionPoints,Countdown) },
    {"WinPoints",0,offsetof(QuestionPoints,WinPoints) },
    {"LosePoints",0,offsetof(QuestionPoints,LosePoints) }
};
KeyType QuestionRankKeys[]={
    {"ID",0,offsetof(QuestionRank,ID) },
    {"Rank",3,offsetof(QuestionRank,Rank) },
    {"ItemReward",5,offsetof(QuestionRank,ItemReward) }
};
KeyType RankingKeys[]={
    {"ID",0,offsetof(Ranking,ID) },
    {"RankingID",0,offsetof(Ranking,RankingID) },
    {"RankingType",0,offsetof(Ranking,RankingType) },
    {"RankingMax",0,offsetof(Ranking,RankingMax) },
    {"RankingMin",0,offsetof(Ranking,RankingMin) },
    {"RankingReward",5,offsetof(Ranking,RankingReward) },
    {"ResetType",0,offsetof(Ranking,ResetType) },
    {"RefreshRewardType",0,offsetof(Ranking,RefreshRewardType) }
};
KeyType RecruitBaseKeys[]={
    {"ID",0,offsetof(RecruitBase,ID) },
    {"Key",1,offsetof(RecruitBase,Key) },
    {"Value",1,offsetof(RecruitBase,Value) },
    {"Des",1,offsetof(RecruitBase,Des) }
};
KeyType RisingKeys[]={
    {"ID",0,offsetof(Rising,ID) },
    {"Time",0,offsetof(Rising,Time) },
    {"State",0,offsetof(Rising,State) }
};
KeyType RobotKeys[]={
    {"GiftID",0,offsetof(Robot,GiftID) },
    {"ArenaGroupID",0,offsetof(Robot,ArenaGroupID) },
    {"sex",0,offsetof(Robot,sex) },
    {"name",1,offsetof(Robot,name) },
    {"roleLv",0,offsetof(Robot,roleLv) },
    {"FightValue",0,offsetof(Robot,FightValue) },
    {"Hero1",3,offsetof(Robot,Hero1) },
    {"Hero2",3,offsetof(Robot,Hero2) },
    {"Hero3",3,offsetof(Robot,Hero3) },
    {"Hero4",3,offsetof(Robot,Hero4) },
    {"Hero5",3,offsetof(Robot,Hero5) },
    {"Hero6",3,offsetof(Robot,Hero6) },
    {"SkillList",3,offsetof(Robot,SkillList) },
    {"ArenaShowLv",0,offsetof(Robot,ArenaShowLv) }
};
KeyType RobotEquipKeys[]={
    {"EquipKey",0,offsetof(RobotEquip,EquipKey) },
    {"Equip1",3,offsetof(RobotEquip,Equip1) },
    {"Equip2",3,offsetof(RobotEquip,Equip2) },
    {"Equip3",3,offsetof(RobotEquip,Equip3) },
    {"Equip4",3,offsetof(RobotEquip,Equip4) },
    {"Equip5",3,offsetof(RobotEquip,Equip5) },
    {"Equip6",3,offsetof(RobotEquip,Equip6) }
};
KeyType RoleBaseKeys[]={
    {"ID",0,offsetof(RoleBase,ID) },
    {"Key",1,offsetof(RoleBase,Key) },
    {"Value",1,offsetof(RoleBase,Value) },
    {"Des",1,offsetof(RoleBase,Des) }
};
KeyType RoleExpKeys[]={
    {"Level",0,offsetof(RoleExp,Level) },
    {"ExpNeed",0,offsetof(RoleExp,ExpNeed) },
    {"ExpGetPerSpirit",0,offsetof(RoleExp,ExpGetPerSpirit) },
    {"ExpGetPerStamina",0,offsetof(RoleExp,ExpGetPerStamina) },
    {"ExpGetTask",0,offsetof(RoleExp,ExpGetTask) },
    {"GoldGetTask",0,offsetof(RoleExp,GoldGetTask) },
    {"ExpSpiritHero",0,offsetof(RoleExp,ExpSpiritHero) },
    {"ExpStaminaHero",0,offsetof(RoleExp,ExpStaminaHero) }
};
KeyType RoleNameBaseKeys[]={
    {"ID",0,offsetof(RoleNameBase,ID) },
    {"Key",1,offsetof(RoleNameBase,Key) },
    {"Value",1,offsetof(RoleNameBase,Value) },
    {"Des",1,offsetof(RoleNameBase,Des) }
};
KeyType SceneKeys[]={
    {"ID",0,offsetof(Scene,ID) },
    {"MonsterBornID",0,offsetof(Scene,MonsterBornID) },
    {"FightSetID",3,offsetof(Scene,FightSetID) },
    {"StarNum",0,offsetof(Scene,StarNum) },
    {"DropBoxID",0,offsetof(Scene,DropBoxID) },
    {"SpeDropBoxID",0,offsetof(Scene,SpeDropBoxID) },
    {"SpeDropParam",3,offsetof(Scene,SpeDropParam) },
    {"NumGet",5,offsetof(Scene,NumGet) },
    {"SpiritNeed",0,offsetof(Scene,SpiritNeed) },
    {"FightMaxTimes",0,offsetof(Scene,FightMaxTimes) },
    {"FightResetDiamond",5,offsetof(Scene,FightResetDiamond) },
    {"ExBox",0,offsetof(Scene,ExBox) },
    {"Type",0,offsetof(Scene,Type) }
};
KeyType SevenDayShopKeys[]={
    {"Day",0,offsetof(SevenDayShop,Day) },
    {"Price",3,offsetof(SevenDayShop,Price) },
    {"Item",5,offsetof(SevenDayShop,Item) }
};
KeyType SevenDayTaskKeys[]={
    {"ID",0,offsetof(SevenDayTask,ID) },
    {"Day",0,offsetof(SevenDayTask,Day) },
    {"Task",3,offsetof(SevenDayTask,Task) }
};
KeyType ShopResetKeys[]={
    {"ID",0,offsetof(ShopReset,ID) },
    {"ShopID",0,offsetof(ShopReset,ShopID) },
    {"ResetTime",0,offsetof(ShopReset,ResetTime) },
    {"CostType",3,offsetof(ShopReset,CostType) }
};
KeyType ShopitemKeys[]={
    {"ID",0,offsetof(Shopitem,ID) },
    {"ShopID",0,offsetof(Shopitem,ShopID) },
    {"ShopItemID",0,offsetof(Shopitem,ShopItemID) },
    {"CostValue",3,offsetof(Shopitem,CostValue) },
    {"CostItem",5,offsetof(Shopitem,CostItem) },
    {"CountCondition",0,offsetof(Shopitem,CountCondition) },
    {"Count",0,offsetof(Shopitem,Count) },
    {"Limit",3,offsetof(Shopitem,Limit) }
};
KeyType SignPayKeys[]={
    {"ID",0,offsetof(SignPay,ID) },
    {"SignTime",0,offsetof(SignPay,SignTime) },
    {"Cost",0,offsetof(SignPay,Cost) }
};
KeyType SignRewardKeys[]={
    {"ID",0,offsetof(SignReward,ID) },
    {"Days",0,offsetof(SignReward,Days) },
    {"Month",0,offsetof(SignReward,Month) },
    {"ItemReward",5,offsetof(SignReward,ItemReward) },
    {"VipTimes",3,offsetof(SignReward,VipTimes) }
};
KeyType SkillKeys[]={
    {"ID",0,offsetof(Skill,ID) },
    {"SkillType",0,offsetof(Skill,SkillType) },
    {"TouchValue",0,offsetof(Skill,TouchValue) },
    {"TriggerPara",0,offsetof(Skill,TriggerPara) },
    {"AttackType",0,offsetof(Skill,AttackType) },
    {"SkillEffectType",0,offsetof(Skill,SkillEffectType) },
    {"Country",0,offsetof(Skill,Country) },
    {"Range",0,offsetof(Skill,Range) },
    {"Condition",0,offsetof(Skill,Condition) },
    {"Count",0,offsetof(Skill,Count) },
    {"Element",3,offsetof(Skill,Element) },
    {"Segments",3,offsetof(Skill,Segments) },
    {"NextSkill",0,offsetof(Skill,NextSkill) },
    {"NestedSkillType",0,offsetof(Skill,NestedSkillType) },
    {"NextHappenType",0,offsetof(Skill,NextHappenType) },
    {"NextHappenRatio",0,offsetof(Skill,NextHappenRatio) },
    {"SkillGroup",0,offsetof(Skill,SkillGroup) }
};
KeyType SkillElementKeys[]={
    {"ElementID",0,offsetof(SkillElement,ElementID) },
    {"Formula",0,offsetof(SkillElement,Formula) },
    {"BigType",0,offsetof(SkillElement,BigType) },
    {"SmallType",0,offsetof(SkillElement,SmallType) },
    {"HappenType",0,offsetof(SkillElement,HappenType) },
    {"HappenRatio",0,offsetof(SkillElement,HappenRatio) },
    {"TriggerType",0,offsetof(SkillElement,TriggerType) },
    {"TriggerRatio",0,offsetof(SkillElement,TriggerRatio) },
    {"LastRoundType",0,offsetof(SkillElement,LastRoundType) },
    {"LastRound",0,offsetof(SkillElement,LastRound) },
    {"Overlay",0,offsetof(SkillElement,Overlay) },
    {"Sequence",0,offsetof(SkillElement,Sequence) },
    {"PersentDown",0,offsetof(SkillElement,PersentDown) },
    {"PersentUp",0,offsetof(SkillElement,PersentUp) },
    {"ValueDown",0,offsetof(SkillElement,ValueDown) },
    {"ValueUp",0,offsetof(SkillElement,ValueUp) },
    {"EffectType",0,offsetof(SkillElement,EffectType) }
};
KeyType SkillGiftKeys[]={
    {"ID",0,offsetof(SkillGift,ID) },
    {"GiftOpenLv",0,offsetof(SkillGift,GiftOpenLv) },
    {"SkillOpen",3,offsetof(SkillGift,SkillOpen) },
    {"SkillReset",3,offsetof(SkillGift,SkillReset) }
};
KeyType SkillPointKeys[]={
    {"ID",0,offsetof(SkillPoint,ID) },
    {"Point",0,offsetof(SkillPoint,Point) }
};
KeyType SkillTreeKeys[]={
    {"ID",0,offsetof(SkillTree,ID) },
    {"Sex",0,offsetof(SkillTree,Sex) },
    {"Gift",0,offsetof(SkillTree,Gift) },
    {"PositionID",0,offsetof(SkillTree,PositionID) },
    {"SkillType",0,offsetof(SkillTree,SkillType) },
    {"PrePositionID",0,offsetof(SkillTree,PrePositionID) },
    {"PostPositionID",3,offsetof(SkillTree,PostPositionID) },
    {"SkillId",5,offsetof(SkillTree,SkillId) },
    {"SkillLvLimit",5,offsetof(SkillTree,SkillLvLimit) },
    {"CostPoint",3,offsetof(SkillTree,CostPoint) }
};
KeyType SkinKeys[]={
    {"ID",0,offsetof(Skin,ID) },
    {"Name",1,offsetof(Skin,Name) },
    {"Open",5,offsetof(Skin,Open) }
};
KeyType SnowmanBaseKeys[]={
    {"ID",0,offsetof(SnowmanBase,ID) },
    {"Key",1,offsetof(SnowmanBase,Key) },
    {"Value",1,offsetof(SnowmanBase,Value) },
    {"Des",1,offsetof(SnowmanBase,Des) }
};
KeyType SnowmanFlushTimeKeys[]={
    {"ID",0,offsetof(SnowmanFlushTime,ID) },
    {"FlushTime",0,offsetof(SnowmanFlushTime,FlushTime) }
};
KeyType SnowmanItemKeys[]={
    {"ID",0,offsetof(SnowmanItem,ID) },
    {"Item",5,offsetof(SnowmanItem,Item) },
    {"Get",5,offsetof(SnowmanItem,Get) }
};
KeyType SnowmanQuestionKeys[]={
    {"QuestionID",0,offsetof(SnowmanQuestion,QuestionID) },
    {"AnswerID",0,offsetof(SnowmanQuestion,AnswerID) },
    {"Type",0,offsetof(SnowmanQuestion,Type) }
};
KeyType SoulCostKeys[]={
    {"ID",0,offsetof(SoulCost,ID) },
    {"CostType",0,offsetof(SoulCost,CostType) },
    {"SkillLv",0,offsetof(SoulCost,SkillLv) },
    {"Resource",0,offsetof(SoulCost,Resource) },
    {"Currency",5,offsetof(SoulCost,Currency) },
    {"RecycleResource",0,offsetof(SoulCost,RecycleResource) }
};
KeyType SoulSkillKeys[]={
    {"ID",0,offsetof(SoulSkill,ID) },
    {"SkillID",0,offsetof(SoulSkill,SkillID) },
    {"SkillLv",0,offsetof(SoulSkill,SkillLv) },
    {"Absolute",5,offsetof(SoulSkill,Absolute) },
    {"Percent",5,offsetof(SoulSkill,Percent) },
    {"StartSkill",0,offsetof(SoulSkill,StartSkill) },
    {"fight",0,offsetof(SoulSkill,fight) },
    {"HeroLv",0,offsetof(SoulSkill,HeroLv) },
    {"GiftLv",0,offsetof(SoulSkill,GiftLv) }
};
KeyType SpeBaseKeys[]={
    {"ID",0,offsetof(SpeBase,ID) },
    {"Key",1,offsetof(SpeBase,Key) },
    {"Value",0,offsetof(SpeBase,Value) },
    {"Des",1,offsetof(SpeBase,Des) }
};
KeyType SpeBoxKeys[]={
    {"ID",0,offsetof(SpeBox,ID) },
    {"ItemBoxID",0,offsetof(SpeBox,ItemBoxID) },
    {"Item",5,offsetof(SpeBox,Item) },
    {"Cost",3,offsetof(SpeBox,Cost) },
    {"Probablity",0,offsetof(SpeBox,Probablity) }
};
KeyType SpeRefCostKeys[]={
    {"BuyTime",0,offsetof(SpeRefCost,BuyTime) },
    {"Cost",0,offsetof(SpeRefCost,Cost) }
};
KeyType SpecialShopKeys[]={
    {"ID",0,offsetof(SpecialShop,ID) },
    {"Lv",3,offsetof(SpecialShop,Lv) },
    {"ItemBox1",0,offsetof(SpecialShop,ItemBox1) },
    {"ItemBox2",0,offsetof(SpecialShop,ItemBox2) },
    {"ItemBox3",0,offsetof(SpecialShop,ItemBox3) },
    {"ItemBox4",0,offsetof(SpecialShop,ItemBox4) },
    {"ItemBox5",0,offsetof(SpecialShop,ItemBox5) },
    {"ItemBox6",0,offsetof(SpecialShop,ItemBox6) },
    {"ItemBox7",0,offsetof(SpecialShop,ItemBox7) },
    {"ItemBox8",0,offsetof(SpecialShop,ItemBox8) },
    {"ItemBox9",0,offsetof(SpecialShop,ItemBox9) }
};
KeyType SpiritPurchaseKeys[]={
    {"BuyTime",0,offsetof(SpiritPurchase,BuyTime) },
    {"Cost",0,offsetof(SpiritPurchase,Cost) },
    {"Add",0,offsetof(SpiritPurchase,Add) }
};
KeyType StaminaPurchaseKeys[]={
    {"BuyTime",0,offsetof(StaminaPurchase,BuyTime) },
    {"Cost",0,offsetof(StaminaPurchase,Cost) },
    {"Add",0,offsetof(StaminaPurchase,Add) }
};
KeyType StaminaRewardKeys[]={
    {"ID",0,offsetof(StaminaReward,ID) },
    {"Level",3,offsetof(StaminaReward,Level) },
    {"LuckyValue",3,offsetof(StaminaReward,LuckyValue) },
    {"ItemBoxID",0,offsetof(StaminaReward,ItemBoxID) }
};
KeyType StaminaRewardBaseKeys[]={
    {"ID",0,offsetof(StaminaRewardBase,ID) },
    {"Key",1,offsetof(StaminaRewardBase,Key) },
    {"Value",1,offsetof(StaminaRewardBase,Value) },
    {"Des",1,offsetof(StaminaRewardBase,Des) }
};
KeyType StaminaRewardDropboxKeys[]={
    {"ID",0,offsetof(StaminaRewardDropbox,ID) },
    {"DropboxID",0,offsetof(StaminaRewardDropbox,DropboxID) },
    {"ItemID",0,offsetof(StaminaRewardDropbox,ItemID) },
    {"ItemNum",0,offsetof(StaminaRewardDropbox,ItemNum) },
    {"Probablity",0,offsetof(StaminaRewardDropbox,Probablity) }
};
KeyType StarConditionKeys[]={
    {"Id",0,offsetof(StarCondition,Id) },
    {"Type",0,offsetof(StarCondition,Type) },
    {"Value1",3,offsetof(StarCondition,Value1) },
    {"Value2",3,offsetof(StarCondition,Value2) }
};
KeyType SysSwitchKeys[]={
    {"ID",0,offsetof(SysSwitch,ID) },
    {"Key",1,offsetof(SysSwitch,Key) },
    {"Des",1,offsetof(SysSwitch,Des) },
    {"Default",0,offsetof(SysSwitch,Default) }
};
KeyType TaskKeys[]={
    {"TaskID",0,offsetof(Task,TaskID) },
    {"NextTask",3,offsetof(Task,NextTask) },
    {"RoleLevel",0,offsetof(Task,RoleLevel) },
    {"TypeID",0,offsetof(Task,TypeID) },
    {"Parameters",3,offsetof(Task,Parameters) },
    {"RewardNum",5,offsetof(Task,RewardNum) },
    {"RewardItem",5,offsetof(Task,RewardItem) },
    {"TaskClass",0,offsetof(Task,TaskClass) }
};
KeyType TaskTypeKeys[]={
    {"ID",0,offsetof(TaskType,ID) },
    {"Key",1,offsetof(TaskType,Key) },
    {"CompleteType",0,offsetof(TaskType,CompleteType) },
    {"OpenTime",3,offsetof(TaskType,OpenTime) },
    {"Des",1,offsetof(TaskType,Des) }
};
KeyType ToolResultKeys[]={
    {"ID",0,offsetof(ToolResult,ID) },
    {"Key",1,offsetof(ToolResult,Key) },
    {"Rate",0,offsetof(ToolResult,Rate) },
    {"DropItemSave",3,offsetof(ToolResult,DropItemSave) },
    {"OpenTime",1,offsetof(ToolResult,OpenTime) },
    {"OpenSecond",0,offsetof(ToolResult,OpenSecond) },
    {"CloseTime",1,offsetof(ToolResult,CloseTime) },
    {"CloseSecond",0,offsetof(ToolResult,CloseSecond) },
    {"Talk",1,offsetof(ToolResult,Talk) },
    {"State",0,offsetof(ToolResult,State) },
    {"Des",1,offsetof(ToolResult,Des) },
    {"ToolsShow",0,offsetof(ToolResult,ToolsShow) },
    {"ShowItemType",3,offsetof(ToolResult,ShowItemType) },
    {"RemainOpenTime",0,offsetof(ToolResult,RemainOpenTime) }
};
KeyType TowerKeys[]={
    {"FightsSetId",0,offsetof(Tower,FightsSetId) },
    {"TowerId",0,offsetof(Tower,TowerId) },
    {"AvailableHeroNum",0,offsetof(Tower,AvailableHeroNum) },
    {"MasterAvailable",0,offsetof(Tower,MasterAvailable) },
    {"WinConditionId",0,offsetof(Tower,WinConditionId) },
    {"WinConditionValue",0,offsetof(Tower,WinConditionValue) },
    {"BattleSceneId",0,offsetof(Tower,BattleSceneId) }
};
KeyType TowerAwardKeys[]={
    {"ID",0,offsetof(TowerAward,ID) },
    {"TowerId",0,offsetof(TowerAward,TowerId) },
    {"WinAward",5,offsetof(TowerAward,WinAward) }
};
KeyType TowerNormalAwardKeys[]={
    {"TowerId",0,offsetof(TowerNormalAward,TowerId) },
    {"WinAward",5,offsetof(TowerNormalAward,WinAward) },
    {"FirstWinAward",5,offsetof(TowerNormalAward,FirstWinAward) },
    {"VipAward",5,offsetof(TowerNormalAward,VipAward) }
};
KeyType TrialBaseKeys[]={
    {"ID",0,offsetof(TrialBase,ID) },
    {"Key",1,offsetof(TrialBase,Key) },
    {"Value",1,offsetof(TrialBase,Value) },
    {"Des",1,offsetof(TrialBase,Des) }
};
KeyType TrialFirstMatchingKeys[]={
    {"RoleLevel",0,offsetof(TrialFirstMatching,RoleLevel) },
    {"MatchingLevelMin",0,offsetof(TrialFirstMatching,MatchingLevelMin) },
    {"MatchingLevelMax",0,offsetof(TrialFirstMatching,MatchingLevelMax) }
};
KeyType TrialRewardKeys[]={
    {"ID",0,offsetof(TrialReward,ID) },
    {"Level",0,offsetof(TrialReward,Level) },
    {"changePoint",0,offsetof(TrialReward,changePoint) },
    {"NumGet",5,offsetof(TrialReward,NumGet) },
    {"DropBoxID",0,offsetof(TrialReward,DropBoxID) },
    {"ItemGet",5,offsetof(TrialReward,ItemGet) }
};
KeyType TrialRewardReadKeys[]={
    {"VIPLv",0,offsetof(TrialRewardRead,VIPLv) },
    {"Read",1,offsetof(TrialRewardRead,Read) }
};
KeyType TrialRewardVIPKeys[]={
    {"ID",0,offsetof(TrialRewardVIP,ID) },
    {"Level",0,offsetof(TrialRewardVIP,Level) },
    {"changePoint",0,offsetof(TrialRewardVIP,changePoint) },
    {"NumGet",5,offsetof(TrialRewardVIP,NumGet) },
    {"DropBoxID",0,offsetof(TrialRewardVIP,DropBoxID) },
    {"ItemGet",5,offsetof(TrialRewardVIP,ItemGet) }
};
KeyType UpgradeKeys[]={
    {"Level",0,offsetof(Upgrade,Level) },
    {"Spirit",0,offsetof(Upgrade,Spirit) },
    {"Stamina",0,offsetof(Upgrade,Stamina) }
};
KeyType VipKeys[]={
    {"Level",0,offsetof(Vip,Level) },
    {"Pay",0,offsetof(Vip,Pay) }
};
KeyType VipBaseKeys[]={
    {"ID",0,offsetof(VipBase,ID) },
    {"Key",1,offsetof(VipBase,Key) },
    {"Value",1,offsetof(VipBase,Value) },
    {"Des",1,offsetof(VipBase,Des) }
};
KeyType VipCountKeys[]={
    {"Level",0,offsetof(VipCount,Level) },
    {"Privilege",5,offsetof(VipCount,Privilege) }
};
KeyType VipFunctionKeys[]={
    {"Level",0,offsetof(VipFunction,Level) },
    {"OpenRecruit",0,offsetof(VipFunction,OpenRecruit) }
};
KeyType VipGiftKeys[]={
    {"Level",0,offsetof(VipGift,Level) },
    {"FreeGiftID",0,offsetof(VipGift,FreeGiftID) },
    {"DailyGiftID",0,offsetof(VipGift,DailyGiftID) },
    {"FreeGiftIDServer",5,offsetof(VipGift,FreeGiftIDServer) },
    {"DailyGiftIDServer",5,offsetof(VipGift,DailyGiftIDServer) },
    {"ShopIDServer",5,offsetof(VipGift,ShopIDServer) }
};
KeyType WelfareBaseKeys[]={
    {"ID",0,offsetof(WelfareBase,ID) },
    {"Key",1,offsetof(WelfareBase,Key) },
    {"Value",1,offsetof(WelfareBase,Value) },
    {"Des",1,offsetof(WelfareBase,Des) }
};
BOOL XmlConfig::LoadActiveRecruit()
{
    string pfile=cpath+"ActiveRecruit.xml";
    return  LoadCommon(pfile.c_str(),ActiveRecruitKeys,ARRSIZE(ActiveRecruitKeys),ActiveRecruitMap);
}

BOOL XmlConfig::LoadActiveRecruitTimes()
{
    string pfile=cpath+"ActiveRecruitTimes.xml";
    return  LoadCommon(pfile.c_str(),ActiveRecruitTimesKeys,ARRSIZE(ActiveRecruitTimesKeys),ActiveRecruitTimesMap);
}

BOOL XmlConfig::LoadActiveRecruitbase()
{
    string pfile=cpath+"ActiveRecruitbase.xml";
    return  LoadCommon(pfile.c_str(),ActiveRecruitbaseKeys,ARRSIZE(ActiveRecruitbaseKeys),ActiveRecruitbaseMap);
}

BOOL XmlConfig::LoadActivity()
{
    string pfile=cpath+"Activity.xml";
    return  LoadCommon(pfile.c_str(),ActivityKeys,ARRSIZE(ActivityKeys),ActivityMap);
}

BOOL XmlConfig::LoadActivityBase()
{
    string pfile=cpath+"ActivityBase.xml";
    return  LoadCommon(pfile.c_str(),ActivityBaseKeys,ARRSIZE(ActivityBaseKeys),ActivityBaseMap);
}

BOOL XmlConfig::LoadActivityFight()
{
    string pfile=cpath+"ActivityFight.xml";
    return  LoadCommon(pfile.c_str(),ActivityFightKeys,ARRSIZE(ActivityFightKeys),ActivityFightMap);
}

BOOL XmlConfig::LoadActivityHero()
{
    string pfile=cpath+"ActivityHero.xml";
    return  LoadCommon(pfile.c_str(),ActivityHeroKeys,ARRSIZE(ActivityHeroKeys),ActivityHeroMap);
}

BOOL XmlConfig::LoadActivityOpen()
{
    string pfile=cpath+"ActivityOpen.xml";
    return  LoadCommon(pfile.c_str(),ActivityOpenKeys,ARRSIZE(ActivityOpenKeys),ActivityOpenMap);
}

BOOL XmlConfig::LoadAddArtifact()
{
    string pfile=cpath+"AddArtifact.xml";
    return  LoadCommon(pfile.c_str(),AddArtifactKeys,ARRSIZE(AddArtifactKeys),AddArtifactMap);
}

BOOL XmlConfig::LoadAddRecruit()
{
    string pfile=cpath+"AddRecruit.xml";
    return  LoadCommon(pfile.c_str(),AddRecruitKeys,ARRSIZE(AddRecruitKeys),AddRecruitMap);
}

BOOL XmlConfig::LoadAllRank()
{
    string pfile=cpath+"AllRank.xml";
    return  LoadCommon(pfile.c_str(),AllRankKeys,ARRSIZE(AllRankKeys),AllRankMap);
}

BOOL XmlConfig::LoadArena()
{
    string pfile=cpath+"Arena.xml";
    return  LoadCommon(pfile.c_str(),ArenaKeys,ARRSIZE(ArenaKeys),ArenaMap);
}

BOOL XmlConfig::LoadArenaBase()
{
    string pfile=cpath+"ArenaBase.xml";
    return  LoadCommon(pfile.c_str(),ArenaBaseKeys,ARRSIZE(ArenaBaseKeys),ArenaBaseMap);
}

BOOL XmlConfig::LoadArenaMatch()
{
    string pfile=cpath+"ArenaMatch.xml";
    return  LoadCommon(pfile.c_str(),ArenaMatchKeys,ARRSIZE(ArenaMatchKeys),ArenaMatchMap);
}

BOOL XmlConfig::LoadArenaReward()
{
    string pfile=cpath+"ArenaReward.xml";
    return  LoadCommon(pfile.c_str(),ArenaRewardKeys,ARRSIZE(ArenaRewardKeys),ArenaRewardMap);
}

BOOL XmlConfig::LoadArenaTopReward()
{
    string pfile=cpath+"ArenaTopReward.xml";
    return  LoadCommon(pfile.c_str(),ArenaTopRewardKeys,ARRSIZE(ArenaTopRewardKeys),ArenaTopRewardMap);
}

BOOL XmlConfig::LoadArtifacRankBase()
{
    string pfile=cpath+"ArtifacRankBase.xml";
    return  LoadCommon(pfile.c_str(),ArtifacRankBaseKeys,ARRSIZE(ArtifacRankBaseKeys),ArtifacRankBaseMap);
}

BOOL XmlConfig::LoadArtifact()
{
    string pfile=cpath+"Artifact.xml";
    return  LoadCommon(pfile.c_str(),ArtifactKeys,ARRSIZE(ArtifactKeys),ArtifactMap);
}

BOOL XmlConfig::LoadArtifactDropbox()
{
    string pfile=cpath+"ArtifactDropbox.xml";
    return  LoadCommon(pfile.c_str(),ArtifactDropboxKeys,ARRSIZE(ArtifactDropboxKeys),ArtifactDropboxMap);
}

BOOL XmlConfig::LoadArtifactRank()
{
    string pfile=cpath+"ArtifactRank.xml";
    return  LoadCommon(pfile.c_str(),ArtifactRankKeys,ARRSIZE(ArtifactRankKeys),ArtifactRankMap);
}

BOOL XmlConfig::LoadArtifactSlot()
{
    string pfile=cpath+"ArtifactSlot.xml";
    return  LoadCommon(pfile.c_str(),ArtifactSlotKeys,ARRSIZE(ArtifactSlotKeys),ArtifactSlotMap);
}

BOOL XmlConfig::LoadArtifactStar()
{
    string pfile=cpath+"ArtifactStar.xml";
    if(LoadCommon(pfile.c_str(),ArtifactStarKeys,ARRSIZE(ArtifactStarKeys),ArtifactStarMap)){
        return InitArtifactStarMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadArtifactStrengthen()
{
    string pfile=cpath+"ArtifactStrengthen.xml";
    if(LoadCommon(pfile.c_str(),ArtifactStrengthenKeys,ARRSIZE(ArtifactStrengthenKeys),ArtifactStrengthenMap)){
        return InitArtifactStrengthenMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadArtifactUpgrade()
{
    string pfile=cpath+"ArtifactUpgrade.xml";
    return  LoadCommon(pfile.c_str(),ArtifactUpgradeKeys,ARRSIZE(ArtifactUpgradeKeys),ArtifactUpgradeMap);
}

BOOL XmlConfig::LoadArtifactWash()
{
    string pfile=cpath+"ArtifactWash.xml";
    return  LoadCommon(pfile.c_str(),ArtifactWashKeys,ARRSIZE(ArtifactWashKeys),ArtifactWashMap);
}

BOOL XmlConfig::LoadBackBase()
{
    string pfile=cpath+"BackBase.xml";
    return  LoadCommon(pfile.c_str(),BackBaseKeys,ARRSIZE(BackBaseKeys),BackBaseMap);
}

BOOL XmlConfig::LoadBackGift()
{
    string pfile=cpath+"BackGift.xml";
    return  LoadCommon(pfile.c_str(),BackGiftKeys,ARRSIZE(BackGiftKeys),BackGiftMap);
}

BOOL XmlConfig::LoadBackLogin()
{
    string pfile=cpath+"BackLogin.xml";
    return  LoadCommon(pfile.c_str(),BackLoginKeys,ARRSIZE(BackLoginKeys),BackLoginMap);
}

BOOL XmlConfig::LoadBackPay()
{
    string pfile=cpath+"BackPay.xml";
    return  LoadCommon(pfile.c_str(),BackPayKeys,ARRSIZE(BackPayKeys),BackPayMap);
}

BOOL XmlConfig::LoadBossChallengeCost()
{
    string pfile=cpath+"BossChallengeCost.xml";
    return  LoadCommon(pfile.c_str(),BossChallengeCostKeys,ARRSIZE(BossChallengeCostKeys),BossChallengeCostMap);
}

BOOL XmlConfig::LoadBossDrop()
{
    string pfile=cpath+"BossDrop.xml";
    if(LoadCommon(pfile.c_str(),BossDropKeys,ARRSIZE(BossDropKeys),BossDropMap)){
        return InitBossDropMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadBossReward()
{
    string pfile=cpath+"BossReward.xml";
    return  LoadCommon(pfile.c_str(),BossRewardKeys,ARRSIZE(BossRewardKeys),BossRewardMap);
}

BOOL XmlConfig::LoadBox()
{
    string pfile=cpath+"Box.xml";
    if(LoadCommon(pfile.c_str(),BoxKeys,ARRSIZE(BoxKeys),BoxMap)){
        return InitBoxMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadBuffList()
{
    string pfile=cpath+"BuffList.xml";
    return  LoadCommon(pfile.c_str(),BuffListKeys,ARRSIZE(BuffListKeys),BuffListMap);
}

BOOL XmlConfig::LoadBuyDirect()
{
    string pfile=cpath+"BuyDirect.xml";
    return  LoadCommon(pfile.c_str(),BuyDirectKeys,ARRSIZE(BuyDirectKeys),BuyDirectMap);
}

BOOL XmlConfig::LoadCampActOpen()
{
    string pfile=cpath+"CampActOpen.xml";
    return  LoadCommon(pfile.c_str(),CampActOpenKeys,ARRSIZE(CampActOpenKeys),CampActOpenMap);
}

BOOL XmlConfig::LoadCampBase()
{
    string pfile=cpath+"CampBase.xml";
    return  LoadCommon(pfile.c_str(),CampBaseKeys,ARRSIZE(CampBaseKeys),CampBaseMap);
}

BOOL XmlConfig::LoadCampGrain()
{
    string pfile=cpath+"CampGrain.xml";
    return  LoadCommon(pfile.c_str(),CampGrainKeys,ARRSIZE(CampGrainKeys),CampGrainMap);
}

BOOL XmlConfig::LoadCampMine()
{
    string pfile=cpath+"CampMine.xml";
    return  LoadCommon(pfile.c_str(),CampMineKeys,ARRSIZE(CampMineKeys),CampMineMap);
}

BOOL XmlConfig::LoadCampMineProduction()
{
    string pfile=cpath+"CampMineProduction.xml";
    if(LoadCommon(pfile.c_str(),CampMineProductionKeys,ARRSIZE(CampMineProductionKeys),CampMineProductionMap)){
        return InitCampMineProductionMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadCampMineScore()
{
    string pfile=cpath+"CampMineScore.xml";
    return  LoadCommon(pfile.c_str(),CampMineScoreKeys,ARRSIZE(CampMineScoreKeys),CampMineScoreMap);
}

BOOL XmlConfig::LoadCampMineUnlock()
{
    string pfile=cpath+"CampMineUnlock.xml";
    return  LoadCommon(pfile.c_str(),CampMineUnlockKeys,ARRSIZE(CampMineUnlockKeys),CampMineUnlockMap);
}

BOOL XmlConfig::LoadCampMineUpgrade()
{
    string pfile=cpath+"CampMineUpgrade.xml";
    return  LoadCommon(pfile.c_str(),CampMineUpgradeKeys,ARRSIZE(CampMineUpgradeKeys),CampMineUpgradeMap);
}

BOOL XmlConfig::LoadCampOfficeRank()
{
    string pfile=cpath+"CampOfficeRank.xml";
    return  LoadCommon(pfile.c_str(),CampOfficeRankKeys,ARRSIZE(CampOfficeRankKeys),CampOfficeRankMap);
}

BOOL XmlConfig::LoadCampOfficeRight()
{
    string pfile=cpath+"CampOfficeRight.xml";
    return  LoadCommon(pfile.c_str(),CampOfficeRightKeys,ARRSIZE(CampOfficeRightKeys),CampOfficeRightMap);
}

BOOL XmlConfig::LoadCampReward()
{
    string pfile=cpath+"CampReward.xml";
    if(LoadCommon(pfile.c_str(),CampRewardKeys,ARRSIZE(CampRewardKeys),CampRewardMap)){
        return InitCampRewardMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadCampRoleReward()
{
    string pfile=cpath+"CampRoleReward.xml";
    return  LoadCommon(pfile.c_str(),CampRoleRewardKeys,ARRSIZE(CampRoleRewardKeys),CampRoleRewardMap);
}

BOOL XmlConfig::LoadCampThrough()
{
    string pfile=cpath+"CampThrough.xml";
    return  LoadCommon(pfile.c_str(),CampThroughKeys,ARRSIZE(CampThroughKeys),CampThroughMap);
}

BOOL XmlConfig::LoadCampThroughItem()
{
    string pfile=cpath+"CampThroughItem.xml";
    if(LoadCommon(pfile.c_str(),CampThroughItemKeys,ARRSIZE(CampThroughItemKeys),CampThroughItemMap)){
        return InitCampThroughItemMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadCampTurntable()
{
    string pfile=cpath+"CampTurntable.xml";
    return  LoadCommon(pfile.c_str(),CampTurntableKeys,ARRSIZE(CampTurntableKeys),CampTurntableMap);
}

BOOL XmlConfig::LoadCampTurntableItems()
{
    string pfile=cpath+"CampTurntableItems.xml";
    return  LoadCommon(pfile.c_str(),CampTurntableItemsKeys,ARRSIZE(CampTurntableItemsKeys),CampTurntableItemsMap);
}

BOOL XmlConfig::LoadCampWarStreakReward()
{
    string pfile=cpath+"CampWarStreakReward.xml";
    return  LoadCommon(pfile.c_str(),CampWarStreakRewardKeys,ARRSIZE(CampWarStreakRewardKeys),CampWarStreakRewardMap);
}

BOOL XmlConfig::LoadChannelBase()
{
    string pfile=cpath+"ChannelBase.xml";
    return  LoadCommon(pfile.c_str(),ChannelBaseKeys,ARRSIZE(ChannelBaseKeys),ChannelBaseMap);
}

BOOL XmlConfig::LoadChapter()
{
    string pfile=cpath+"Chapter.xml";
    return  LoadCommon(pfile.c_str(),ChapterKeys,ARRSIZE(ChapterKeys),ChapterMap);
}

BOOL XmlConfig::LoadChatBase()
{
    string pfile=cpath+"ChatBase.xml";
    return  LoadCommon(pfile.c_str(),ChatBaseKeys,ARRSIZE(ChatBaseKeys),ChatBaseMap);
}

BOOL XmlConfig::LoadChatNotice()
{
    string pfile=cpath+"ChatNotice.xml";
    return  LoadCommon(pfile.c_str(),ChatNoticeKeys,ARRSIZE(ChatNoticeKeys),ChatNoticeMap);
}

BOOL XmlConfig::LoadCoin()
{
    string pfile=cpath+"Coin.xml";
    return  LoadCommon(pfile.c_str(),CoinKeys,ARRSIZE(CoinKeys),CoinMap);
}

BOOL XmlConfig::LoadCoinPurchase()
{
    string pfile=cpath+"CoinPurchase.xml";
    return  LoadCommon(pfile.c_str(),CoinPurchaseKeys,ARRSIZE(CoinPurchaseKeys),CoinPurchaseMap);
}

BOOL XmlConfig::LoadCostBase()
{
    string pfile=cpath+"CostBase.xml";
    return  LoadCommon(pfile.c_str(),CostBaseKeys,ARRSIZE(CostBaseKeys),CostBaseMap);
}

BOOL XmlConfig::LoadCostSum()
{
    string pfile=cpath+"CostSum.xml";
    return  LoadCommon(pfile.c_str(),CostSumKeys,ARRSIZE(CostSumKeys),CostSumMap);
}

BOOL XmlConfig::LoadDailyCostSum()
{
    string pfile=cpath+"DailyCostSum.xml";
    return  LoadCommon(pfile.c_str(),DailyCostSumKeys,ARRSIZE(DailyCostSumKeys),DailyCostSumMap);
}

BOOL XmlConfig::LoadDailyLogin()
{
    string pfile=cpath+"DailyLogin.xml";
    return  LoadCommon(pfile.c_str(),DailyLoginKeys,ARRSIZE(DailyLoginKeys),DailyLoginMap);
}

BOOL XmlConfig::LoadDailyPaySum()
{
    string pfile=cpath+"DailyPaySum.xml";
    return  LoadCommon(pfile.c_str(),DailyPaySumKeys,ARRSIZE(DailyPaySumKeys),DailyPaySumMap);
}

BOOL XmlConfig::LoadDailySumPayReward()
{
    string pfile=cpath+"DailySumPayReward.xml";
    if(LoadCommon(pfile.c_str(),DailySumPayRewardKeys,ARRSIZE(DailySumPayRewardKeys),DailySumPayRewardMap)){
        return InitDailySumPayRewardMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadDepreFactor()
{
    string pfile=cpath+"DepreFactor.xml";
    return  LoadCommon(pfile.c_str(),DepreFactorKeys,ARRSIZE(DepreFactorKeys),DepreFactorMap);
}

BOOL XmlConfig::LoadDropOther()
{
    string pfile=cpath+"DropOther.xml";
    return  LoadCommon(pfile.c_str(),DropOtherKeys,ARRSIZE(DropOtherKeys),DropOtherMap);
}

BOOL XmlConfig::LoadDropbox()
{
    string pfile=cpath+"Dropbox.xml";
    if(LoadCommon(pfile.c_str(),DropboxKeys,ARRSIZE(DropboxKeys),DropboxMap)){
        return InitDropboxMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadEmail()
{
    string pfile=cpath+"Email.xml";
    return  LoadCommon(pfile.c_str(),EmailKeys,ARRSIZE(EmailKeys),EmailMap);
}

BOOL XmlConfig::LoadEquip()
{
    string pfile=cpath+"Equip.xml";
    return  LoadCommon(pfile.c_str(),EquipKeys,ARRSIZE(EquipKeys),EquipMap);
}

BOOL XmlConfig::LoadEquipBase()
{
    string pfile=cpath+"EquipBase.xml";
    return  LoadCommon(pfile.c_str(),EquipBaseKeys,ARRSIZE(EquipBaseKeys),EquipBaseMap);
}

BOOL XmlConfig::LoadEquipCoinCost()
{
    string pfile=cpath+"EquipCoinCost.xml";
    return  LoadCommon(pfile.c_str(),EquipCoinCostKeys,ARRSIZE(EquipCoinCostKeys),EquipCoinCostMap);
}

BOOL XmlConfig::LoadEquipMaterialGroup()
{
    string pfile=cpath+"EquipMaterialGroup.xml";
    return  LoadCommon(pfile.c_str(),EquipMaterialGroupKeys,ARRSIZE(EquipMaterialGroupKeys),EquipMaterialGroupMap);
}

BOOL XmlConfig::LoadEquipRecycle()
{
    string pfile=cpath+"EquipRecycle.xml";
    return  LoadCommon(pfile.c_str(),EquipRecycleKeys,ARRSIZE(EquipRecycleKeys),EquipRecycleMap);
}

BOOL XmlConfig::LoadEventRecruit()
{
    string pfile=cpath+"EventRecruit.xml";
    return  LoadCommon(pfile.c_str(),EventRecruitKeys,ARRSIZE(EventRecruitKeys),EventRecruitMap);
}

BOOL XmlConfig::LoadExchange()
{
    string pfile=cpath+"Exchange.xml";
    if(LoadCommon(pfile.c_str(),ExchangeKeys,ARRSIZE(ExchangeKeys),ExchangeMap)){
        return InitExchangeMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadExchangeBase()
{
    string pfile=cpath+"ExchangeBase.xml";
    return  LoadCommon(pfile.c_str(),ExchangeBaseKeys,ARRSIZE(ExchangeBaseKeys),ExchangeBaseMap);
}

BOOL XmlConfig::LoadFightSet()
{
    string pfile=cpath+"FightSet.xml";
    return  LoadCommon(pfile.c_str(),FightSetKeys,ARRSIZE(FightSetKeys),FightSetMap);
}

BOOL XmlConfig::LoadForm()
{
    string pfile=cpath+"Form.xml";
    return  LoadCommon(pfile.c_str(),FormKeys,ARRSIZE(FormKeys),FormMap);
}

BOOL XmlConfig::LoadFormRestrict()
{
    string pfile=cpath+"FormRestrict.xml";
    return  LoadCommon(pfile.c_str(),FormRestrictKeys,ARRSIZE(FormRestrictKeys),FormRestrictMap);
}

BOOL XmlConfig::LoadFragConvert()
{
    string pfile=cpath+"FragConvert.xml";
    return  LoadCommon(pfile.c_str(),FragConvertKeys,ARRSIZE(FragConvertKeys),FragConvertMap);
}

BOOL XmlConfig::LoadFund()
{
    string pfile=cpath+"Fund.xml";
    return  LoadCommon(pfile.c_str(),FundKeys,ARRSIZE(FundKeys),FundMap);
}

BOOL XmlConfig::LoadFundBase()
{
    string pfile=cpath+"FundBase.xml";
    return  LoadCommon(pfile.c_str(),FundBaseKeys,ARRSIZE(FundBaseKeys),FundBaseMap);
}

BOOL XmlConfig::LoadGem()
{
    string pfile=cpath+"Gem.xml";
    return  LoadCommon(pfile.c_str(),GemKeys,ARRSIZE(GemKeys),GemMap);
}

BOOL XmlConfig::LoadGrowing()
{
    string pfile=cpath+"Growing.xml";
    if(LoadCommon(pfile.c_str(),GrowingKeys,ARRSIZE(GrowingKeys),GrowingMap)){
        return InitGrowingMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadGuildBase()
{
    string pfile=cpath+"GuildBase.xml";
    return  LoadCommon(pfile.c_str(),GuildBaseKeys,ARRSIZE(GuildBaseKeys),GuildBaseMap);
}

BOOL XmlConfig::LoadGuildBattleChat()
{
    string pfile=cpath+"GuildBattleChat.xml";
    return  LoadCommon(pfile.c_str(),GuildBattleChatKeys,ARRSIZE(GuildBattleChatKeys),GuildBattleChatMap);
}

BOOL XmlConfig::LoadGuildBattleCity()
{
    string pfile=cpath+"GuildBattleCity.xml";
    return  LoadCommon(pfile.c_str(),GuildBattleCityKeys,ARRSIZE(GuildBattleCityKeys),GuildBattleCityMap);
}

BOOL XmlConfig::LoadGuildBattleFight()
{
    string pfile=cpath+"GuildBattleFight.xml";
    return  LoadCommon(pfile.c_str(),GuildBattleFightKeys,ARRSIZE(GuildBattleFightKeys),GuildBattleFightMap);
}

BOOL XmlConfig::LoadGuildBattleLog()
{
    string pfile=cpath+"GuildBattleLog.xml";
    return  LoadCommon(pfile.c_str(),GuildBattleLogKeys,ARRSIZE(GuildBattleLogKeys),GuildBattleLogMap);
}

BOOL XmlConfig::LoadGuildBattlePersonRank()
{
    string pfile=cpath+"GuildBattlePersonRank.xml";
    return  LoadCommon(pfile.c_str(),GuildBattlePersonRankKeys,ARRSIZE(GuildBattlePersonRankKeys),GuildBattlePersonRankMap);
}

BOOL XmlConfig::LoadGuildBattleRank()
{
    string pfile=cpath+"GuildBattleRank.xml";
    return  LoadCommon(pfile.c_str(),GuildBattleRankKeys,ARRSIZE(GuildBattleRankKeys),GuildBattleRankMap);
}

BOOL XmlConfig::LoadGuildBattleSeverPersonRank()
{
    string pfile=cpath+"GuildBattleSeverPersonRank.xml";
    return  LoadCommon(pfile.c_str(),GuildBattleSeverPersonRankKeys,ARRSIZE(GuildBattleSeverPersonRankKeys),GuildBattleSeverPersonRankMap);
}

BOOL XmlConfig::LoadGuildChapter()
{
    string pfile=cpath+"GuildChapter.xml";
    return  LoadCommon(pfile.c_str(),GuildChapterKeys,ARRSIZE(GuildChapterKeys),GuildChapterMap);
}

BOOL XmlConfig::LoadGuildChapterFight()
{
    string pfile=cpath+"GuildChapterFight.xml";
    if(LoadCommon(pfile.c_str(),GuildChapterFightKeys,ARRSIZE(GuildChapterFightKeys),GuildChapterFightMap)){
        return InitGuildChapterFightMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadGuildDungeon()
{
    string pfile=cpath+"GuildDungeon.xml";
    return  LoadCommon(pfile.c_str(),GuildDungeonKeys,ARRSIZE(GuildDungeonKeys),GuildDungeonMap);
}

BOOL XmlConfig::LoadGuildDungeonAward()
{
    string pfile=cpath+"GuildDungeonAward.xml";
    if(LoadCommon(pfile.c_str(),GuildDungeonAwardKeys,ARRSIZE(GuildDungeonAwardKeys),GuildDungeonAwardMap)){
        return InitGuildDungeonAwardMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadGuildDungeonSpot()
{
    string pfile=cpath+"GuildDungeonSpot.xml";
    return  LoadCommon(pfile.c_str(),GuildDungeonSpotKeys,ARRSIZE(GuildDungeonSpotKeys),GuildDungeonSpotMap);
}

BOOL XmlConfig::LoadGuildFlag()
{
    string pfile=cpath+"GuildFlag.xml";
    return  LoadCommon(pfile.c_str(),GuildFlagKeys,ARRSIZE(GuildFlagKeys),GuildFlagMap);
}

BOOL XmlConfig::LoadGuildFlagLv()
{
    string pfile=cpath+"GuildFlagLv.xml";
    return  LoadCommon(pfile.c_str(),GuildFlagLvKeys,ARRSIZE(GuildFlagLvKeys),GuildFlagLvMap);
}

BOOL XmlConfig::LoadGuildLog()
{
    string pfile=cpath+"GuildLog.xml";
    return  LoadCommon(pfile.c_str(),GuildLogKeys,ARRSIZE(GuildLogKeys),GuildLogMap);
}

BOOL XmlConfig::LoadGuildLv()
{
    string pfile=cpath+"GuildLv.xml";
    return  LoadCommon(pfile.c_str(),GuildLvKeys,ARRSIZE(GuildLvKeys),GuildLvMap);
}

BOOL XmlConfig::LoadGuildMember()
{
    string pfile=cpath+"GuildMember.xml";
    return  LoadCommon(pfile.c_str(),GuildMemberKeys,ARRSIZE(GuildMemberKeys),GuildMemberMap);
}

BOOL XmlConfig::LoadHero()
{
    string pfile=cpath+"Hero.xml";
    return  LoadCommon(pfile.c_str(),HeroKeys,ARRSIZE(HeroKeys),HeroMap);
}

BOOL XmlConfig::LoadHeroBase()
{
    string pfile=cpath+"HeroBase.xml";
    return  LoadCommon(pfile.c_str(),HeroBaseKeys,ARRSIZE(HeroBaseKeys),HeroBaseMap);
}

BOOL XmlConfig::LoadHeroExp()
{
    string pfile=cpath+"HeroExp.xml";
    if(LoadCommon(pfile.c_str(),HeroExpKeys,ARRSIZE(HeroExpKeys),HeroExpMap)){
        return InitHeroExpMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadHeroGift()
{
    string pfile=cpath+"HeroGift.xml";
    return  LoadCommon(pfile.c_str(),HeroGiftKeys,ARRSIZE(HeroGiftKeys),HeroGiftMap);
}

BOOL XmlConfig::LoadHeroGiftProp()
{
    string pfile=cpath+"HeroGiftProp.xml";
    return  LoadCommon(pfile.c_str(),HeroGiftPropKeys,ARRSIZE(HeroGiftPropKeys),HeroGiftPropMap);
}

BOOL XmlConfig::LoadHeroGiftSkill()
{
    string pfile=cpath+"HeroGiftSkill.xml";
    if(LoadCommon(pfile.c_str(),HeroGiftSkillKeys,ARRSIZE(HeroGiftSkillKeys),HeroGiftSkillMap)){
        return InitHeroGiftSkillMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadHeroRecycle()
{
    string pfile=cpath+"HeroRecycle.xml";
    if(LoadCommon(pfile.c_str(),HeroRecycleKeys,ARRSIZE(HeroRecycleKeys),HeroRecycleMap)){
        return InitHeroRecycleMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadHeroSkin()
{
    string pfile=cpath+"HeroSkin.xml";
    return  LoadCommon(pfile.c_str(),HeroSkinKeys,ARRSIZE(HeroSkinKeys),HeroSkinMap);
}

BOOL XmlConfig::LoadHeroSoul()
{
    string pfile=cpath+"HeroSoul.xml";
    return  LoadCommon(pfile.c_str(),HeroSoulKeys,ARRSIZE(HeroSoulKeys),HeroSoulMap);
}

BOOL XmlConfig::LoadHeroStar()
{
    string pfile=cpath+"HeroStar.xml";
    if(LoadCommon(pfile.c_str(),HeroStarKeys,ARRSIZE(HeroStarKeys),HeroStarMap)){
        return InitHeroStarMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadHeroStarRecycle()
{
    string pfile=cpath+"HeroStarRecycle.xml";
    if(LoadCommon(pfile.c_str(),HeroStarRecycleKeys,ARRSIZE(HeroStarRecycleKeys),HeroStarRecycleMap)){
        return InitHeroStarRecycleMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadItem()
{
    string pfile=cpath+"Item.xml";
    return  LoadCommon(pfile.c_str(),ItemKeys,ARRSIZE(ItemKeys),ItemMap);
}

BOOL XmlConfig::LoadLevelUpReward()
{
    string pfile=cpath+"LevelUpReward.xml";
    return  LoadCommon(pfile.c_str(),LevelUpRewardKeys,ARRSIZE(LevelUpRewardKeys),LevelUpRewardMap);
}

BOOL XmlConfig::LoadLoginActReward()
{
    string pfile=cpath+"LoginActReward.xml";
    if(LoadCommon(pfile.c_str(),LoginActRewardKeys,ARRSIZE(LoginActRewardKeys),LoginActRewardMap)){
        return InitLoginActRewardMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadLottery()
{
    string pfile=cpath+"Lottery.xml";
    return  LoadCommon(pfile.c_str(),LotteryKeys,ARRSIZE(LotteryKeys),LotteryMap);
}

BOOL XmlConfig::LoadLotteryBase()
{
    string pfile=cpath+"LotteryBase.xml";
    return  LoadCommon(pfile.c_str(),LotteryBaseKeys,ARRSIZE(LotteryBaseKeys),LotteryBaseMap);
}

BOOL XmlConfig::LoadLuckyTurntable()
{
    string pfile=cpath+"LuckyTurntable.xml";
    return  LoadCommon(pfile.c_str(),LuckyTurntableKeys,ARRSIZE(LuckyTurntableKeys),LuckyTurntableMap);
}

BOOL XmlConfig::LoadLuckyTurntableBase()
{
    string pfile=cpath+"LuckyTurntableBase.xml";
    return  LoadCommon(pfile.c_str(),LuckyTurntableBaseKeys,ARRSIZE(LuckyTurntableBaseKeys),LuckyTurntableBaseMap);
}

BOOL XmlConfig::LoadLuckyTurntableItems()
{
    string pfile=cpath+"LuckyTurntableItems.xml";
    return  LoadCommon(pfile.c_str(),LuckyTurntableItemsKeys,ARRSIZE(LuckyTurntableItemsKeys),LuckyTurntableItemsMap);
}

BOOL XmlConfig::LoadLuckyTurntableValue()
{
    string pfile=cpath+"LuckyTurntableValue.xml";
    return  LoadCommon(pfile.c_str(),LuckyTurntableValueKeys,ARRSIZE(LuckyTurntableValueKeys),LuckyTurntableValueMap);
}

BOOL XmlConfig::LoadMailDouble()
{
    string pfile=cpath+"MailDouble.xml";
    return  LoadCommon(pfile.c_str(),MailDoubleKeys,ARRSIZE(MailDoubleKeys),MailDoubleMap);
}

BOOL XmlConfig::LoadMisc()
{
    string pfile=cpath+"Misc.xml";
    return  LoadCommon(pfile.c_str(),MiscKeys,ARRSIZE(MiscKeys),MiscMap);
}

BOOL XmlConfig::LoadMonsterBase()
{
    string pfile=cpath+"MonsterBase.xml";
    return  LoadCommon(pfile.c_str(),MonsterBaseKeys,ARRSIZE(MonsterBaseKeys),MonsterBaseMap);
}

BOOL XmlConfig::LoadMonsterProperty()
{
    string pfile=cpath+"MonsterProperty.xml";
    if(LoadCommon(pfile.c_str(),MonsterPropertyKeys,ARRSIZE(MonsterPropertyKeys),MonsterPropertyMap)){
        return InitMonsterPropertyMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadMonsterStrength()
{
    string pfile=cpath+"MonsterStrength.xml";
    return  LoadCommon(pfile.c_str(),MonsterStrengthKeys,ARRSIZE(MonsterStrengthKeys),MonsterStrengthMap);
}

BOOL XmlConfig::LoadMounts()
{
    string pfile=cpath+"Mounts.xml";
    return  LoadCommon(pfile.c_str(),MountsKeys,ARRSIZE(MountsKeys),MountsMap);
}

BOOL XmlConfig::LoadMountsEquip()
{
    string pfile=cpath+"MountsEquip.xml";
    return  LoadCommon(pfile.c_str(),MountsEquipKeys,ARRSIZE(MountsEquipKeys),MountsEquipMap);
}

BOOL XmlConfig::LoadMountsEquipment()
{
    string pfile=cpath+"MountsEquipment.xml";
    return  LoadCommon(pfile.c_str(),MountsEquipmentKeys,ARRSIZE(MountsEquipmentKeys),MountsEquipmentMap);
}

BOOL XmlConfig::LoadMountsStar()
{
    string pfile=cpath+"MountsStar.xml";
    return  LoadCommon(pfile.c_str(),MountsStarKeys,ARRSIZE(MountsStarKeys),MountsStarMap);
}

BOOL XmlConfig::LoadMountsTrain()
{
    string pfile=cpath+"MountsTrain.xml";
    return  LoadCommon(pfile.c_str(),MountsTrainKeys,ARRSIZE(MountsTrainKeys),MountsTrainMap);
}

BOOL XmlConfig::LoadMysticshop()
{
    string pfile=cpath+"Mysticshop.xml";
    return  LoadCommon(pfile.c_str(),MysticshopKeys,ARRSIZE(MysticshopKeys),MysticshopMap);
}

BOOL XmlConfig::LoadMysticshopRefreshCost()
{
    string pfile=cpath+"MysticshopRefreshCost.xml";
    return  LoadCommon(pfile.c_str(),MysticshopRefreshCostKeys,ARRSIZE(MysticshopRefreshCostKeys),MysticshopRefreshCostMap);
}

BOOL XmlConfig::LoadNewYearActivity()
{
    string pfile=cpath+"NewYearActivity.xml";
    return  LoadCommon(pfile.c_str(),NewYearActivityKeys,ARRSIZE(NewYearActivityKeys),NewYearActivityMap);
}

BOOL XmlConfig::LoadNewYearActivityBase()
{
    string pfile=cpath+"NewYearActivityBase.xml";
    return  LoadCommon(pfile.c_str(),NewYearActivityBaseKeys,ARRSIZE(NewYearActivityBaseKeys),NewYearActivityBaseMap);
}

BOOL XmlConfig::LoadNewYearRecycle()
{
    string pfile=cpath+"NewYearRecycle.xml";
    return  LoadCommon(pfile.c_str(),NewYearRecycleKeys,ARRSIZE(NewYearRecycleKeys),NewYearRecycleMap);
}

BOOL XmlConfig::LoadPay()
{
    string pfile=cpath+"Pay.xml";
    return  LoadCommon(pfile.c_str(),PayKeys,ARRSIZE(PayKeys),PayMap);
}

BOOL XmlConfig::LoadPayRebate()
{
    string pfile=cpath+"PayRebate.xml";
    return  LoadCommon(pfile.c_str(),PayRebateKeys,ARRSIZE(PayRebateKeys),PayRebateMap);
}

BOOL XmlConfig::LoadPaySum()
{
    string pfile=cpath+"PaySum.xml";
    return  LoadCommon(pfile.c_str(),PaySumKeys,ARRSIZE(PaySumKeys),PaySumMap);
}

BOOL XmlConfig::LoadPeakArena()
{
    string pfile=cpath+"PeakArena.xml";
    return  LoadCommon(pfile.c_str(),PeakArenaKeys,ARRSIZE(PeakArenaKeys),PeakArenaMap);
}

BOOL XmlConfig::LoadPeakArenaBase()
{
    string pfile=cpath+"PeakArenaBase.xml";
    return  LoadCommon(pfile.c_str(),PeakArenaBaseKeys,ARRSIZE(PeakArenaBaseKeys),PeakArenaBaseMap);
}

BOOL XmlConfig::LoadPeakArenaFormat()
{
    string pfile=cpath+"PeakArenaFormat.xml";
    return  LoadCommon(pfile.c_str(),PeakArenaFormatKeys,ARRSIZE(PeakArenaFormatKeys),PeakArenaFormatMap);
}

BOOL XmlConfig::LoadPeakArenaMatch()
{
    string pfile=cpath+"PeakArenaMatch.xml";
    return  LoadCommon(pfile.c_str(),PeakArenaMatchKeys,ARRSIZE(PeakArenaMatchKeys),PeakArenaMatchMap);
}

BOOL XmlConfig::LoadPeakArenaReward()
{
    string pfile=cpath+"PeakArenaReward.xml";
    return  LoadCommon(pfile.c_str(),PeakArenaRewardKeys,ARRSIZE(PeakArenaRewardKeys),PeakArenaRewardMap);
}

BOOL XmlConfig::LoadPeakRobot()
{
    string pfile=cpath+"PeakRobot.xml";
    return  LoadCommon(pfile.c_str(),PeakRobotKeys,ARRSIZE(PeakRobotKeys),PeakRobotMap);
}

BOOL XmlConfig::LoadPeakUse()
{
    string pfile=cpath+"PeakUse.xml";
    return  LoadCommon(pfile.c_str(),PeakUseKeys,ARRSIZE(PeakUseKeys),PeakUseMap);
}

BOOL XmlConfig::LoadPowerSet()
{
    string pfile=cpath+"PowerSet.xml";
    return  LoadCommon(pfile.c_str(),PowerSetKeys,ARRSIZE(PowerSetKeys),PowerSetMap);
}

BOOL XmlConfig::LoadPushMessages()
{
    string pfile=cpath+"PushMessages.xml";
    return  LoadCommon(pfile.c_str(),PushMessagesKeys,ARRSIZE(PushMessagesKeys),PushMessagesMap);
}

BOOL XmlConfig::LoadQuenchProp()
{
    string pfile=cpath+"QuenchProp.xml";
    return  LoadCommon(pfile.c_str(),QuenchPropKeys,ARRSIZE(QuenchPropKeys),QuenchPropMap);
}

BOOL XmlConfig::LoadQuenchRand()
{
    string pfile=cpath+"QuenchRand.xml";
    return  LoadCommon(pfile.c_str(),QuenchRandKeys,ARRSIZE(QuenchRandKeys),QuenchRandMap);
}

BOOL XmlConfig::LoadQuestionPoints()
{
    string pfile=cpath+"QuestionPoints.xml";
    return  LoadCommon(pfile.c_str(),QuestionPointsKeys,ARRSIZE(QuestionPointsKeys),QuestionPointsMap);
}

BOOL XmlConfig::LoadQuestionRank()
{
    string pfile=cpath+"QuestionRank.xml";
    return  LoadCommon(pfile.c_str(),QuestionRankKeys,ARRSIZE(QuestionRankKeys),QuestionRankMap);
}

BOOL XmlConfig::LoadRanking()
{
    string pfile=cpath+"Ranking.xml";
    return  LoadCommon(pfile.c_str(),RankingKeys,ARRSIZE(RankingKeys),RankingMap);
}

BOOL XmlConfig::LoadRecruitBase()
{
    string pfile=cpath+"RecruitBase.xml";
    return  LoadCommon(pfile.c_str(),RecruitBaseKeys,ARRSIZE(RecruitBaseKeys),RecruitBaseMap);
}

BOOL XmlConfig::LoadRising()
{
    string pfile=cpath+"Rising.xml";
    return  LoadCommon(pfile.c_str(),RisingKeys,ARRSIZE(RisingKeys),RisingMap);
}

BOOL XmlConfig::LoadRobot()
{
    string pfile=cpath+"Robot.xml";
    if(LoadCommon(pfile.c_str(),RobotKeys,ARRSIZE(RobotKeys),RobotMap)){
        return InitRobotMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadRobotEquip()
{
    string pfile=cpath+"RobotEquip.xml";
    return  LoadCommon(pfile.c_str(),RobotEquipKeys,ARRSIZE(RobotEquipKeys),RobotEquipMap);
}

BOOL XmlConfig::LoadRoleBase()
{
    string pfile=cpath+"RoleBase.xml";
    return  LoadCommon(pfile.c_str(),RoleBaseKeys,ARRSIZE(RoleBaseKeys),RoleBaseMap);
}

BOOL XmlConfig::LoadRoleExp()
{
    string pfile=cpath+"RoleExp.xml";
    return  LoadCommon(pfile.c_str(),RoleExpKeys,ARRSIZE(RoleExpKeys),RoleExpMap);
}

BOOL XmlConfig::LoadRoleNameBase()
{
    string pfile=cpath+"RoleNameBase.xml";
    return  LoadCommon(pfile.c_str(),RoleNameBaseKeys,ARRSIZE(RoleNameBaseKeys),RoleNameBaseMap);
}

BOOL XmlConfig::LoadScene()
{
    string pfile=cpath+"Scene.xml";
    return  LoadCommon(pfile.c_str(),SceneKeys,ARRSIZE(SceneKeys),SceneMap);
}

BOOL XmlConfig::LoadSevenDayShop()
{
    string pfile=cpath+"SevenDayShop.xml";
    return  LoadCommon(pfile.c_str(),SevenDayShopKeys,ARRSIZE(SevenDayShopKeys),SevenDayShopMap);
}

BOOL XmlConfig::LoadSevenDayTask()
{
    string pfile=cpath+"SevenDayTask.xml";
    if(LoadCommon(pfile.c_str(),SevenDayTaskKeys,ARRSIZE(SevenDayTaskKeys),SevenDayTaskMap)){
        return InitSevenDayTaskMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadShopReset()
{
    string pfile=cpath+"ShopReset.xml";
    if(LoadCommon(pfile.c_str(),ShopResetKeys,ARRSIZE(ShopResetKeys),ShopResetMap)){
        return InitShopResetMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadShopitem()
{
    string pfile=cpath+"Shopitem.xml";
    if(LoadCommon(pfile.c_str(),ShopitemKeys,ARRSIZE(ShopitemKeys),ShopitemMap)){
        return InitShopitemMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadSignPay()
{
    string pfile=cpath+"SignPay.xml";
    return  LoadCommon(pfile.c_str(),SignPayKeys,ARRSIZE(SignPayKeys),SignPayMap);
}

BOOL XmlConfig::LoadSignReward()
{
    string pfile=cpath+"SignReward.xml";
    if(LoadCommon(pfile.c_str(),SignRewardKeys,ARRSIZE(SignRewardKeys),SignRewardMap)){
        return InitSignRewardMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadSkill()
{
    string pfile=cpath+"Skill.xml";
    return  LoadCommon(pfile.c_str(),SkillKeys,ARRSIZE(SkillKeys),SkillMap);
}

BOOL XmlConfig::LoadSkillElement()
{
    string pfile=cpath+"SkillElement.xml";
    return  LoadCommon(pfile.c_str(),SkillElementKeys,ARRSIZE(SkillElementKeys),SkillElementMap);
}

BOOL XmlConfig::LoadSkillGift()
{
    string pfile=cpath+"SkillGift.xml";
    return  LoadCommon(pfile.c_str(),SkillGiftKeys,ARRSIZE(SkillGiftKeys),SkillGiftMap);
}

BOOL XmlConfig::LoadSkillPoint()
{
    string pfile=cpath+"SkillPoint.xml";
    return  LoadCommon(pfile.c_str(),SkillPointKeys,ARRSIZE(SkillPointKeys),SkillPointMap);
}

BOOL XmlConfig::LoadSkillTree()
{
    string pfile=cpath+"SkillTree.xml";
    if(LoadCommon(pfile.c_str(),SkillTreeKeys,ARRSIZE(SkillTreeKeys),SkillTreeMap)){
        return InitSkillTreeMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadSkin()
{
    string pfile=cpath+"Skin.xml";
    return  LoadCommon(pfile.c_str(),SkinKeys,ARRSIZE(SkinKeys),SkinMap);
}

BOOL XmlConfig::LoadSnowmanBase()
{
    string pfile=cpath+"SnowmanBase.xml";
    return  LoadCommon(pfile.c_str(),SnowmanBaseKeys,ARRSIZE(SnowmanBaseKeys),SnowmanBaseMap);
}

BOOL XmlConfig::LoadSnowmanFlushTime()
{
    string pfile=cpath+"SnowmanFlushTime.xml";
    return  LoadCommon(pfile.c_str(),SnowmanFlushTimeKeys,ARRSIZE(SnowmanFlushTimeKeys),SnowmanFlushTimeMap);
}

BOOL XmlConfig::LoadSnowmanItem()
{
    string pfile=cpath+"SnowmanItem.xml";
    return  LoadCommon(pfile.c_str(),SnowmanItemKeys,ARRSIZE(SnowmanItemKeys),SnowmanItemMap);
}

BOOL XmlConfig::LoadSnowmanQuestion()
{
    string pfile=cpath+"SnowmanQuestion.xml";
    return  LoadCommon(pfile.c_str(),SnowmanQuestionKeys,ARRSIZE(SnowmanQuestionKeys),SnowmanQuestionMap);
}

BOOL XmlConfig::LoadSoulCost()
{
    string pfile=cpath+"SoulCost.xml";
    if(LoadCommon(pfile.c_str(),SoulCostKeys,ARRSIZE(SoulCostKeys),SoulCostMap)){
        return InitSoulCostMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadSoulSkill()
{
    string pfile=cpath+"SoulSkill.xml";
    if(LoadCommon(pfile.c_str(),SoulSkillKeys,ARRSIZE(SoulSkillKeys),SoulSkillMap)){
        return InitSoulSkillMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadSpeBase()
{
    string pfile=cpath+"SpeBase.xml";
    return  LoadCommon(pfile.c_str(),SpeBaseKeys,ARRSIZE(SpeBaseKeys),SpeBaseMap);
}

BOOL XmlConfig::LoadSpeBox()
{
    string pfile=cpath+"SpeBox.xml";
    if(LoadCommon(pfile.c_str(),SpeBoxKeys,ARRSIZE(SpeBoxKeys),SpeBoxMap)){
        return InitSpeBoxMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadSpeRefCost()
{
    string pfile=cpath+"SpeRefCost.xml";
    return  LoadCommon(pfile.c_str(),SpeRefCostKeys,ARRSIZE(SpeRefCostKeys),SpeRefCostMap);
}

BOOL XmlConfig::LoadSpecialShop()
{
    string pfile=cpath+"SpecialShop.xml";
    return  LoadCommon(pfile.c_str(),SpecialShopKeys,ARRSIZE(SpecialShopKeys),SpecialShopMap);
}

BOOL XmlConfig::LoadSpiritPurchase()
{
    string pfile=cpath+"SpiritPurchase.xml";
    return  LoadCommon(pfile.c_str(),SpiritPurchaseKeys,ARRSIZE(SpiritPurchaseKeys),SpiritPurchaseMap);
}

BOOL XmlConfig::LoadStaminaPurchase()
{
    string pfile=cpath+"StaminaPurchase.xml";
    return  LoadCommon(pfile.c_str(),StaminaPurchaseKeys,ARRSIZE(StaminaPurchaseKeys),StaminaPurchaseMap);
}

BOOL XmlConfig::LoadStaminaReward()
{
    string pfile=cpath+"StaminaReward.xml";
    return  LoadCommon(pfile.c_str(),StaminaRewardKeys,ARRSIZE(StaminaRewardKeys),StaminaRewardMap);
}

BOOL XmlConfig::LoadStaminaRewardBase()
{
    string pfile=cpath+"StaminaRewardBase.xml";
    return  LoadCommon(pfile.c_str(),StaminaRewardBaseKeys,ARRSIZE(StaminaRewardBaseKeys),StaminaRewardBaseMap);
}

BOOL XmlConfig::LoadStaminaRewardDropbox()
{
    string pfile=cpath+"StaminaRewardDropbox.xml";
    if(LoadCommon(pfile.c_str(),StaminaRewardDropboxKeys,ARRSIZE(StaminaRewardDropboxKeys),StaminaRewardDropboxMap)){
        return InitStaminaRewardDropboxMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadStarCondition()
{
    string pfile=cpath+"StarCondition.xml";
    return  LoadCommon(pfile.c_str(),StarConditionKeys,ARRSIZE(StarConditionKeys),StarConditionMap);
}

BOOL XmlConfig::LoadSysSwitch()
{
    string pfile=cpath+"SysSwitch.xml";
    return  LoadCommon(pfile.c_str(),SysSwitchKeys,ARRSIZE(SysSwitchKeys),SysSwitchMap);
}

BOOL XmlConfig::LoadTask()
{
    string pfile=cpath+"Task.xml";
    if(LoadCommon(pfile.c_str(),TaskKeys,ARRSIZE(TaskKeys),TaskMap)){
        return InitTaskMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadTaskType()
{
    string pfile=cpath+"TaskType.xml";
    return  LoadCommon(pfile.c_str(),TaskTypeKeys,ARRSIZE(TaskTypeKeys),TaskTypeMap);
}

BOOL XmlConfig::LoadToolResult()
{
    string pfile=cpath+"ToolResult.xml";
    return  LoadCommon(pfile.c_str(),ToolResultKeys,ARRSIZE(ToolResultKeys),ToolResultMap);
}

BOOL XmlConfig::LoadTower()
{
    string pfile=cpath+"Tower.xml";
    if(LoadCommon(pfile.c_str(),TowerKeys,ARRSIZE(TowerKeys),TowerMap)){
        return InitTowerMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadTowerAward()
{
    string pfile=cpath+"TowerAward.xml";
    return  LoadCommon(pfile.c_str(),TowerAwardKeys,ARRSIZE(TowerAwardKeys),TowerAwardMap);
}

BOOL XmlConfig::LoadTowerNormalAward()
{
    string pfile=cpath+"TowerNormalAward.xml";
    return  LoadCommon(pfile.c_str(),TowerNormalAwardKeys,ARRSIZE(TowerNormalAwardKeys),TowerNormalAwardMap);
}

BOOL XmlConfig::LoadTrialBase()
{
    string pfile=cpath+"TrialBase.xml";
    return  LoadCommon(pfile.c_str(),TrialBaseKeys,ARRSIZE(TrialBaseKeys),TrialBaseMap);
}

BOOL XmlConfig::LoadTrialFirstMatching()
{
    string pfile=cpath+"TrialFirstMatching.xml";
    return  LoadCommon(pfile.c_str(),TrialFirstMatchingKeys,ARRSIZE(TrialFirstMatchingKeys),TrialFirstMatchingMap);
}

BOOL XmlConfig::LoadTrialReward()
{
    string pfile=cpath+"TrialReward.xml";
    if(LoadCommon(pfile.c_str(),TrialRewardKeys,ARRSIZE(TrialRewardKeys),TrialRewardMap)){
        return InitTrialRewardMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadTrialRewardRead()
{
    string pfile=cpath+"TrialRewardRead.xml";
    return  LoadCommon(pfile.c_str(),TrialRewardReadKeys,ARRSIZE(TrialRewardReadKeys),TrialRewardReadMap);
}

BOOL XmlConfig::LoadTrialRewardVIP()
{
    string pfile=cpath+"TrialRewardVIP.xml";
    if(LoadCommon(pfile.c_str(),TrialRewardVIPKeys,ARRSIZE(TrialRewardVIPKeys),TrialRewardVIPMap)){
        return InitTrialRewardVIPMapMap();
    }
    return 1;
}

BOOL XmlConfig::LoadUpgrade()
{
    string pfile=cpath+"Upgrade.xml";
    return  LoadCommon(pfile.c_str(),UpgradeKeys,ARRSIZE(UpgradeKeys),UpgradeMap);
}

BOOL XmlConfig::LoadVip()
{
    string pfile=cpath+"Vip.xml";
    return  LoadCommon(pfile.c_str(),VipKeys,ARRSIZE(VipKeys),VipMap);
}

BOOL XmlConfig::LoadVipBase()
{
    string pfile=cpath+"VipBase.xml";
    return  LoadCommon(pfile.c_str(),VipBaseKeys,ARRSIZE(VipBaseKeys),VipBaseMap);
}

BOOL XmlConfig::LoadVipCount()
{
    string pfile=cpath+"VipCount.xml";
    return  LoadCommon(pfile.c_str(),VipCountKeys,ARRSIZE(VipCountKeys),VipCountMap);
}

BOOL XmlConfig::LoadVipFunction()
{
    string pfile=cpath+"VipFunction.xml";
    return  LoadCommon(pfile.c_str(),VipFunctionKeys,ARRSIZE(VipFunctionKeys),VipFunctionMap);
}

BOOL XmlConfig::LoadVipGift()
{
    string pfile=cpath+"VipGift.xml";
    return  LoadCommon(pfile.c_str(),VipGiftKeys,ARRSIZE(VipGiftKeys),VipGiftMap);
}

BOOL XmlConfig::LoadWelfareBase()
{
    string pfile=cpath+"WelfareBase.xml";
    return  LoadCommon(pfile.c_str(),WelfareBaseKeys,ARRSIZE(WelfareBaseKeys),WelfareBaseMap);
}

BOOL XmlConfig::InitArtifactStarMapMap()
{
    return InitMapMap(offsetof(ArtifactStar,Type),offsetof(ArtifactStar,Star),ArtifactStarMap,ArtifactStarMapMap);    
}
BOOL XmlConfig::InitArtifactStrengthenMapMap()
{
    return InitMapMap(offsetof(ArtifactStrengthen,Type),offsetof(ArtifactStrengthen,Level),ArtifactStrengthenMap,ArtifactStrengthenMapMap);    
}
BOOL XmlConfig::InitBossDropMapMap()
{
    return InitMapMap(offsetof(BossDrop,GuildLv),offsetof(BossDrop,Energy),BossDropMap,BossDropMapMap);    
}
BOOL XmlConfig::InitBoxMapMap()
{
    return InitMapMap(offsetof(Box,Level),offsetof(Box,Item),BoxMap,BoxMapMap);    
}
BOOL XmlConfig::InitCampMineProductionMapMap()
{
    return InitMapMap(offsetof(CampMineProduction,MineType),offsetof(CampMineProduction,PlayerLevel),CampMineProductionMap,CampMineProductionMapMap);    
}
BOOL XmlConfig::InitCampRewardMapMap()
{
    return InitMapMap(offsetof(CampReward,RewardID),offsetof(CampReward,Rank),CampRewardMap,CampRewardMapMap);    
}
BOOL XmlConfig::InitCampThroughItemMapMap()
{
    return InitMapMap(offsetof(CampThroughItem,Level),offsetof(CampThroughItem,Through),CampThroughItemMap,CampThroughItemMapMap);    
}
BOOL XmlConfig::InitDailySumPayRewardMapMap()
{
    return InitMapMap(offsetof(DailySumPayReward,Day),offsetof(DailySumPayReward,Index),DailySumPayRewardMap,DailySumPayRewardMapMap);    
}
BOOL XmlConfig::InitDropboxMapMap()
{
    return InitMapMap(offsetof(Dropbox,DropboxID),offsetof(Dropbox,ItemID),DropboxMap,DropboxMapMap);    
}
BOOL XmlConfig::InitExchangeMapMap()
{
    return InitMapMap(offsetof(Exchange,ShopItemID),offsetof(Exchange,ID),ExchangeMap,ExchangeMapMap);    
}
BOOL XmlConfig::InitGrowingMapMap()
{
    return InitMapMap(offsetof(Growing,Prob),offsetof(Growing,ID),GrowingMap,GrowingMapMap);    
}
BOOL XmlConfig::InitGuildChapterFightMapMap()
{
    return InitMapMap(offsetof(GuildChapterFight,FightID),offsetof(GuildChapterFight,FightSequence),GuildChapterFightMap,GuildChapterFightMapMap);    
}
BOOL XmlConfig::InitGuildDungeonAwardMapMap()
{
    return InitMapMap(offsetof(GuildDungeonAward,Dungeon),offsetof(GuildDungeonAward,Id),GuildDungeonAwardMap,GuildDungeonAwardMapMap);    
}
BOOL XmlConfig::InitHeroExpMapMap()
{
    return InitMapMap(offsetof(HeroExp,ExpIndex),offsetof(HeroExp,Level),HeroExpMap,HeroExpMapMap);    
}
BOOL XmlConfig::InitHeroGiftSkillMapMap()
{
    return InitMapMap(offsetof(HeroGiftSkill,HeroID),offsetof(HeroGiftSkill,GiftLv),HeroGiftSkillMap,HeroGiftSkillMapMap);    
}
BOOL XmlConfig::InitHeroRecycleMapMap()
{
    return InitMapMap(offsetof(HeroRecycle,Grade),offsetof(HeroRecycle,Quality),HeroRecycleMap,HeroRecycleMapMap);    
}
BOOL XmlConfig::InitHeroStarMapMap()
{
    return InitMapMap(offsetof(HeroStar,HeroID),offsetof(HeroStar,Star),HeroStarMap,HeroStarMapMap);    
}
BOOL XmlConfig::InitHeroStarRecycleMapMap()
{
    return InitMapMap(offsetof(HeroStarRecycle,Star),offsetof(HeroStarRecycle,Quality),HeroStarRecycleMap,HeroStarRecycleMapMap);    
}
BOOL XmlConfig::InitLoginActRewardMapMap()
{
    return InitMapMap(offsetof(LoginActReward,RewardType),offsetof(LoginActReward,Days),LoginActRewardMap,LoginActRewardMapMap);    
}
BOOL XmlConfig::InitMonsterPropertyMapMap()
{
    return InitMapMap(offsetof(MonsterProperty,Job),offsetof(MonsterProperty,MonsterLv),MonsterPropertyMap,MonsterPropertyMapMap);    
}
BOOL XmlConfig::InitRobotMapMap()
{
    return InitMapMap(offsetof(Robot,roleLv),offsetof(Robot,GiftID),RobotMap,RobotMapMap);    
}
BOOL XmlConfig::InitSevenDayTaskMapMap()
{
    return InitMapMap(offsetof(SevenDayTask,Day),offsetof(SevenDayTask,ID),SevenDayTaskMap,SevenDayTaskMapMap);    
}
BOOL XmlConfig::InitShopResetMapMap()
{
    return InitMapMap(offsetof(ShopReset,ShopID),offsetof(ShopReset,ResetTime),ShopResetMap,ShopResetMapMap);    
}
BOOL XmlConfig::InitShopitemMapMap()
{
    return InitMapMap(offsetof(Shopitem,ShopID),offsetof(Shopitem,ShopItemID),ShopitemMap,ShopitemMapMap);    
}
BOOL XmlConfig::InitSignRewardMapMap()
{
    return InitMapMap(offsetof(SignReward,Month),offsetof(SignReward,Days),SignRewardMap,SignRewardMapMap);    
}
BOOL XmlConfig::InitSkillTreeMapMap()
{
    return InitMapMap(offsetof(SkillTree,Sex),offsetof(SkillTree,PositionID),SkillTreeMap,SkillTreeMapMap);    
}
BOOL XmlConfig::InitSoulCostMapMap()
{
    return InitMapMap(offsetof(SoulCost,CostType),offsetof(SoulCost,SkillLv),SoulCostMap,SoulCostMapMap);    
}
BOOL XmlConfig::InitSoulSkillMapMap()
{
    return InitMapMap(offsetof(SoulSkill,SkillID),offsetof(SoulSkill,SkillLv),SoulSkillMap,SoulSkillMapMap);    
}
BOOL XmlConfig::InitSpeBoxMapMap()
{
    return InitMapMap(offsetof(SpeBox,ItemBoxID),offsetof(SpeBox,ID),SpeBoxMap,SpeBoxMapMap);    
}
BOOL XmlConfig::InitStaminaRewardDropboxMapMap()
{
    return InitMapMap(offsetof(StaminaRewardDropbox,DropboxID),offsetof(StaminaRewardDropbox,ID),StaminaRewardDropboxMap,StaminaRewardDropboxMapMap);    
}
BOOL XmlConfig::InitTaskMapMap()
{
    return InitMapMap(offsetof(Task,RoleLevel),offsetof(Task,TaskID),TaskMap,TaskMapMap);    
}
BOOL XmlConfig::InitTowerMapMap()
{
    return InitMapMap(offsetof(Tower,TowerId),offsetof(Tower,FightsSetId),TowerMap,TowerMapMap);    
}
BOOL XmlConfig::InitTrialRewardMapMap()
{
    return InitMapMap(offsetof(TrialReward,Level),offsetof(TrialReward,changePoint),TrialRewardMap,TrialRewardMapMap);    
}
BOOL XmlConfig::InitTrialRewardVIPMapMap()
{
    return InitMapMap(offsetof(TrialRewardVIP,Level),offsetof(TrialRewardVIP,changePoint),TrialRewardVIPMap,TrialRewardVIPMapMap);    
}
XmlConfig::XmlConfig ()
{
   // FileKeys["Buff"]=BuffMap;
}

BOOL XmlConfig::LoadAll()
{
    LoadActiveRecruit();
    LoadActiveRecruitTimes();
    LoadActiveRecruitbase();
    LoadActivity();
    LoadActivityBase();
    LoadActivityFight();
    LoadActivityHero();
    LoadActivityOpen();
    LoadAddArtifact();
    LoadAddRecruit();
    LoadAllRank();
    LoadArena();
    LoadArenaBase();
    LoadArenaMatch();
    LoadArenaReward();
    LoadArenaTopReward();
    LoadArtifacRankBase();
    LoadArtifact();
    LoadArtifactDropbox();
    LoadArtifactRank();
    LoadArtifactSlot();
    LoadArtifactStar();
    LoadArtifactStrengthen();
    LoadArtifactUpgrade();
    LoadArtifactWash();
    LoadBackBase();
    LoadBackGift();
    LoadBackLogin();
    LoadBackPay();
    LoadBossChallengeCost();
    LoadBossDrop();
    LoadBossReward();
    LoadBox();
    LoadBuffList();
    LoadBuyDirect();
    LoadCampActOpen();
    LoadCampBase();
    LoadCampGrain();
    LoadCampMine();
    LoadCampMineProduction();
    LoadCampMineScore();
    LoadCampMineUnlock();
    LoadCampMineUpgrade();
    LoadCampOfficeRank();
    LoadCampOfficeRight();
    LoadCampReward();
    LoadCampRoleReward();
    LoadCampThrough();
    LoadCampThroughItem();
    LoadCampTurntable();
    LoadCampTurntableItems();
    LoadCampWarStreakReward();
    LoadChannelBase();
    LoadChapter();
    LoadChatBase();
    LoadChatNotice();
    LoadCoin();
    LoadCoinPurchase();
    LoadCostBase();
    LoadCostSum();
    LoadDailyCostSum();
    LoadDailyLogin();
    LoadDailyPaySum();
    LoadDailySumPayReward();
    LoadDepreFactor();
    LoadDropOther();
    LoadDropbox();
    LoadEmail();
    LoadEquip();
    LoadEquipBase();
    LoadEquipCoinCost();
    LoadEquipMaterialGroup();
    LoadEquipRecycle();
    LoadEventRecruit();
    LoadExchange();
    LoadExchangeBase();
    LoadFightSet();
    LoadForm();
    LoadFormRestrict();
    LoadFragConvert();
    LoadFund();
    LoadFundBase();
    LoadGem();
    LoadGrowing();
    LoadGuildBase();
    LoadGuildBattleChat();
    LoadGuildBattleCity();
    LoadGuildBattleFight();
    LoadGuildBattleLog();
    LoadGuildBattlePersonRank();
    LoadGuildBattleRank();
    LoadGuildBattleSeverPersonRank();
    LoadGuildChapter();
    LoadGuildChapterFight();
    LoadGuildDungeon();
    LoadGuildDungeonAward();
    LoadGuildDungeonSpot();
    LoadGuildFlag();
    LoadGuildFlagLv();
    LoadGuildLog();
    LoadGuildLv();
    LoadGuildMember();
    LoadHero();
    LoadHeroBase();
    LoadHeroExp();
    LoadHeroGift();
    LoadHeroGiftProp();
    LoadHeroGiftSkill();
    LoadHeroRecycle();
    LoadHeroSkin();
    LoadHeroSoul();
    LoadHeroStar();
    LoadHeroStarRecycle();
    LoadItem();
    LoadLevelUpReward();
    LoadLoginActReward();
    LoadLottery();
    LoadLotteryBase();
    LoadLuckyTurntable();
    LoadLuckyTurntableBase();
    LoadLuckyTurntableItems();
    LoadLuckyTurntableValue();
    LoadMailDouble();
    LoadMisc();
    LoadMonsterBase();
    LoadMonsterProperty();
    LoadMonsterStrength();
    LoadMounts();
    LoadMountsEquip();
    LoadMountsEquipment();
    LoadMountsStar();
    LoadMountsTrain();
    LoadMysticshop();
    LoadMysticshopRefreshCost();
    LoadNewYearActivity();
    LoadNewYearActivityBase();
    LoadNewYearRecycle();
    LoadPay();
    LoadPayRebate();
    LoadPaySum();
    LoadPeakArena();
    LoadPeakArenaBase();
    LoadPeakArenaFormat();
    LoadPeakArenaMatch();
    LoadPeakArenaReward();
    LoadPeakRobot();
    LoadPeakUse();
    LoadPowerSet();
    LoadPushMessages();
    LoadQuenchProp();
    LoadQuenchRand();
    LoadQuestionPoints();
    LoadQuestionRank();
    LoadRanking();
    LoadRecruitBase();
    LoadRising();
    LoadRobot();
    LoadRobotEquip();
    LoadRoleBase();
    LoadRoleExp();
    LoadRoleNameBase();
    LoadScene();
    LoadSevenDayShop();
    LoadSevenDayTask();
    LoadShopReset();
    LoadShopitem();
    LoadSignPay();
    LoadSignReward();
    LoadSkill();
    LoadSkillElement();
    LoadSkillGift();
    LoadSkillPoint();
    LoadSkillTree();
    LoadSkin();
    LoadSnowmanBase();
    LoadSnowmanFlushTime();
    LoadSnowmanItem();
    LoadSnowmanQuestion();
    LoadSoulCost();
    LoadSoulSkill();
    LoadSpeBase();
    LoadSpeBox();
    LoadSpeRefCost();
    LoadSpecialShop();
    LoadSpiritPurchase();
    LoadStaminaPurchase();
    LoadStaminaReward();
    LoadStaminaRewardBase();
    LoadStaminaRewardDropbox();
    LoadStarCondition();
    LoadSysSwitch();
    LoadTask();
    LoadTaskType();
    LoadToolResult();
    LoadTower();
    LoadTowerAward();
    LoadTowerNormalAward();
    LoadTrialBase();
    LoadTrialFirstMatching();
    LoadTrialReward();
    LoadTrialRewardRead();
    LoadTrialRewardVIP();
    LoadUpgrade();
    LoadVip();
    LoadVipBase();
    LoadVipCount();
    LoadVipFunction();
    LoadVipGift();
    LoadWelfareBase();

    return true;
}

XmlConfig& XmlConfig::Instance()
{
    static XmlConfig config;
    return config;
}

XmlConfig::XmlConfig (const string &path)
{
   cpath=path;
   if(access(path.c_str(),0)==1)
   {
       cout<<"config dir not exists"<<endl;
       exit(1);
   }
}
BOOL
XmlConfig::LoadFile (const char*file)
{
  string pfile=cpath+"HeroProperty.xml";
  //return  LoadCommon(pfile.c_str(),HeroPropertyKeys,ARRSIZE(HeroPropertyKeys),HeroPropertyMap);
  return true;
}

static UINT64
transfer (const char* src)
{

#ifdef OLD_VER_TRANS
  uint64_t ret = 0;
  int len = strlen (src);
  for (int i = 0; i < len; i += 2)
    {
      int t = 0;
      if (src[i] >= '0' && src[i] <= '9' && src[i + 1] >= '0'
          && src[i + 1] <= '9')
        {
          t = (src[i] - '0') * 16 + (src[i + 1] - '0');
        }
      else if (src[i] >= 'a' && src[i] <= 'f' && src[i + 1] >= 'a'
          && src[i + 1] <= 'f')
        {
          t = (src[i] - 'a') * 16 + (src[i + 1] - 'a');
        }

      ret = ret * 10 + t;
    }
  return ret;
#else
  uint64_t ret = 0;
  int len = strlen (src);
  for (int i = len/2; i < len; i += 2)
    {
      int t1 = 0, t2 = 0;
      if(src[i] >= '0' && src[i] <= '9')
          t1 = src[i] - '0';
      else if(src[i] >= 'a' && src[i] <= 'f')
          t1 = src[i] - 'a';
      else if(src[i] >= 'A' && src[i] <= 'F')
          t1 = src[i] - 'A';

      if(src[i+1] >= '0' && src[i+1] <= '9')
          t2 = src[i+1] - '0';
      else if(src[i+1] >= 'a' && src[i+1] <= 'f')
          t2 = src[i+1] - 'a';
      else if(src[i+1] >= 'A' && src[i+1] <= 'F')
          t2 = src[i+1] - 'A';
      ret = ret * 100 + t1 * 16 + t2;
    }
  return ret;


#endif

}
UINT64
XmlConfig::UUID ()
{
    static boost::uuids::random_generator gen;
    boost::uuids::uuid uuid_t(gen());
    std::string LCardUUID;
    LCardUUID.reserve(2*uuid_t.size());

    char temp[4] = {0};
    for (size_t i = 0,n=uuid_t.size(); i < n; i++)
    {
        sprintf (temp, "%02X", uuid_t.data[i]);
        LCardUUID.append(temp);
    }

    UINT64 value = transfer (LCardUUID.c_str());
    return value;
}

template<class T>
BOOL
XmlConfig::LoadCommon (const char* file, const KeyType *keys, UINT32 keylen,
                       unordered_map<UINT32, T> &t1)
{

    BOOL bRet = true;

	t1.clear();
    TiXmlDocument doc(file);
    if (!doc.LoadFile(file))
    {
        return bRet;
    }
    TiXmlElement *ti = doc.RootElement();

    if (ti)
    {
        TiXmlElement *p = ti->FirstChildElement();
        int row = 0;
        while (p)
        {

            T t;
            int len = keylen;
            UINT8 *ui = (UINT8*) &t;
            string *s = nullptr;
            vector<float> *vf=nullptr;
            vector<int> *vi=nullptr;
            vector<string> *vs=nullptr;
            vector<IdCount> *vid=nullptr;
            for (int i = 0; i < len; ++i)
            {

                const char *val = p->Attribute(keys[i].name.c_str());
                if (val)
                {
                    string sval(val);
                    vector<string> lv;
                    vector<INT32> lvi;
                    switch (keys[i].type)
                    {
                        case 0:
                            *(UINT32*) (ui + keys[i].addr ) = atoi(val);
                            break;
                        case 1:
                            s = (string*) (ui + keys[i].addr );
                            if (s)
                            {
                                s->assign(val);
                            }
                            break;
                        case 3:
                            if(sval=="null"||sval=="0")
                            {
                                continue;
                            }
                            vi = (vector<int>*) (ui + keys[i].addr );
                            if (vi)
                            {
                                if(!SplitStringInt(val,',',*vi))
                                {
                                    cout << "wrong config xml format file=" << file
                                    << " key=" << keys[i].name << "  row=" << row
                                    << endl;
                                }
                            }
                            break;
                        case 4:
                            if(sval=="null"||sval=="0")
                            {
                                continue;
                            }
                            vs = (vector<string>*) (ui + keys[i].addr );
                            if (vi)
                            {
                                if(!SplitString(val,',',*vs))
                                {
                                    cout << "wrong config xml format file=" << file
                                    << " key=" << keys[i].name << "  row=" << row
                                    << endl;
                                }
                            }
                            break;
                        case 5:
                            if(sval=="null"||sval=="0")
                            {
                                continue;
                            }
                            vid = (vector<IdCount>*) (ui + keys[i].addr );
                            if (vid)
                            {
                                if(!SplitIdCount(val,',',':',*vid))
                                {
                                    cout << "wrong config xml format file=" << file
                                    << " key=" << keys[i].name << "  row=" << row
                                    << endl;
                                }

                            }
                            break;
                        case 6:
                            *(float*) (ui + keys[i].addr)=stof(sval);
                            break;
                        case 7:
                            if(sval=="null"||sval=="0")
                            {
                                continue;
                            }
                            vf = (vector<float>*) (ui + keys[i].addr );
                            if (vi)
                            {
                                if(!SplitStringFloat(val,',',*vf))
                                {
                                    cout << "wrong config xml format file=" << file
                                    << " key=" << keys[i].name << "  row=" << row
                                    << endl;
                                }
                            }
                           break;
                        default:
                            break;
                    }
                }
                else
                {
//                    cout<<keys[i-1].name<<endl;
//                    cout<<keys[i].addr<<endl;
//                    cout<<i<<endl;
//                    cout<<keylen<<endl;
//                    cout<<keys[i].type<<endl;

                    cout << "wrong config xml format file=" << file
                            << " key=" << keys[i].name << "  row=" << row
                            << endl;
                }
            }

            t1[*(UINT32*) ui] = t;
            p = p->NextSiblingElement();
            row++;
        }
    }
    return true;
}
template<class T>
BOOL XmlConfig::InitMapMap(UINT32 koffset1,UINT32 koffset2, unordered_map<UINT32, T>& smap,
        unordered_map<UINT32, unordered_map<UINT32,T> >& vecMap)
{

    UINT8 *p=nullptr;
    vecMap.clear();
    for(auto &m:smap)
    {
        p=(UINT8*)&m.second;
        UINT32 key1=*(UINT32*)(p+koffset1);
        UINT32 key2=*(UINT32*)(p+koffset2);
        auto &vm=vecMap[key1];
        vm[key2]=m.second;
    }
    return true;
}

std::unordered_map<string,std::function<BOOL(XmlConfig*)>> loaders={
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActiveRecruit",std::mem_fun(&XmlConfig::LoadActiveRecruit)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActiveRecruitTimes",std::mem_fun(&XmlConfig::LoadActiveRecruitTimes)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActiveRecruitbase",std::mem_fun(&XmlConfig::LoadActiveRecruitbase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Activity",std::mem_fun(&XmlConfig::LoadActivity)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActivityBase",std::mem_fun(&XmlConfig::LoadActivityBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActivityFight",std::mem_fun(&XmlConfig::LoadActivityFight)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActivityHero",std::mem_fun(&XmlConfig::LoadActivityHero)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ActivityOpen",std::mem_fun(&XmlConfig::LoadActivityOpen)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("AddArtifact",std::mem_fun(&XmlConfig::LoadAddArtifact)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("AddRecruit",std::mem_fun(&XmlConfig::LoadAddRecruit)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("AllRank",std::mem_fun(&XmlConfig::LoadAllRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Arena",std::mem_fun(&XmlConfig::LoadArena)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArenaBase",std::mem_fun(&XmlConfig::LoadArenaBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArenaMatch",std::mem_fun(&XmlConfig::LoadArenaMatch)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArenaReward",std::mem_fun(&XmlConfig::LoadArenaReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArenaTopReward",std::mem_fun(&XmlConfig::LoadArenaTopReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifacRankBase",std::mem_fun(&XmlConfig::LoadArtifacRankBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Artifact",std::mem_fun(&XmlConfig::LoadArtifact)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactDropbox",std::mem_fun(&XmlConfig::LoadArtifactDropbox)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactRank",std::mem_fun(&XmlConfig::LoadArtifactRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactSlot",std::mem_fun(&XmlConfig::LoadArtifactSlot)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactStar",std::mem_fun(&XmlConfig::LoadArtifactStar)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactStrengthen",std::mem_fun(&XmlConfig::LoadArtifactStrengthen)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactUpgrade",std::mem_fun(&XmlConfig::LoadArtifactUpgrade)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ArtifactWash",std::mem_fun(&XmlConfig::LoadArtifactWash)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BackBase",std::mem_fun(&XmlConfig::LoadBackBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BackGift",std::mem_fun(&XmlConfig::LoadBackGift)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BackLogin",std::mem_fun(&XmlConfig::LoadBackLogin)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BackPay",std::mem_fun(&XmlConfig::LoadBackPay)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BossChallengeCost",std::mem_fun(&XmlConfig::LoadBossChallengeCost)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BossDrop",std::mem_fun(&XmlConfig::LoadBossDrop)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BossReward",std::mem_fun(&XmlConfig::LoadBossReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Box",std::mem_fun(&XmlConfig::LoadBox)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BuffList",std::mem_fun(&XmlConfig::LoadBuffList)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("BuyDirect",std::mem_fun(&XmlConfig::LoadBuyDirect)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampActOpen",std::mem_fun(&XmlConfig::LoadCampActOpen)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampBase",std::mem_fun(&XmlConfig::LoadCampBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampGrain",std::mem_fun(&XmlConfig::LoadCampGrain)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampMine",std::mem_fun(&XmlConfig::LoadCampMine)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampMineProduction",std::mem_fun(&XmlConfig::LoadCampMineProduction)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampMineScore",std::mem_fun(&XmlConfig::LoadCampMineScore)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampMineUnlock",std::mem_fun(&XmlConfig::LoadCampMineUnlock)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampMineUpgrade",std::mem_fun(&XmlConfig::LoadCampMineUpgrade)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampOfficeRank",std::mem_fun(&XmlConfig::LoadCampOfficeRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampOfficeRight",std::mem_fun(&XmlConfig::LoadCampOfficeRight)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampReward",std::mem_fun(&XmlConfig::LoadCampReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampRoleReward",std::mem_fun(&XmlConfig::LoadCampRoleReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampThrough",std::mem_fun(&XmlConfig::LoadCampThrough)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampThroughItem",std::mem_fun(&XmlConfig::LoadCampThroughItem)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampTurntable",std::mem_fun(&XmlConfig::LoadCampTurntable)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampTurntableItems",std::mem_fun(&XmlConfig::LoadCampTurntableItems)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CampWarStreakReward",std::mem_fun(&XmlConfig::LoadCampWarStreakReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ChannelBase",std::mem_fun(&XmlConfig::LoadChannelBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Chapter",std::mem_fun(&XmlConfig::LoadChapter)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ChatBase",std::mem_fun(&XmlConfig::LoadChatBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ChatNotice",std::mem_fun(&XmlConfig::LoadChatNotice)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Coin",std::mem_fun(&XmlConfig::LoadCoin)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CoinPurchase",std::mem_fun(&XmlConfig::LoadCoinPurchase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CostBase",std::mem_fun(&XmlConfig::LoadCostBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("CostSum",std::mem_fun(&XmlConfig::LoadCostSum)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("DailyCostSum",std::mem_fun(&XmlConfig::LoadDailyCostSum)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("DailyLogin",std::mem_fun(&XmlConfig::LoadDailyLogin)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("DailyPaySum",std::mem_fun(&XmlConfig::LoadDailyPaySum)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("DailySumPayReward",std::mem_fun(&XmlConfig::LoadDailySumPayReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("DepreFactor",std::mem_fun(&XmlConfig::LoadDepreFactor)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("DropOther",std::mem_fun(&XmlConfig::LoadDropOther)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Dropbox",std::mem_fun(&XmlConfig::LoadDropbox)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Email",std::mem_fun(&XmlConfig::LoadEmail)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Equip",std::mem_fun(&XmlConfig::LoadEquip)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("EquipBase",std::mem_fun(&XmlConfig::LoadEquipBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("EquipCoinCost",std::mem_fun(&XmlConfig::LoadEquipCoinCost)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("EquipMaterialGroup",std::mem_fun(&XmlConfig::LoadEquipMaterialGroup)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("EquipRecycle",std::mem_fun(&XmlConfig::LoadEquipRecycle)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("EventRecruit",std::mem_fun(&XmlConfig::LoadEventRecruit)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Exchange",std::mem_fun(&XmlConfig::LoadExchange)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ExchangeBase",std::mem_fun(&XmlConfig::LoadExchangeBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("FightSet",std::mem_fun(&XmlConfig::LoadFightSet)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Form",std::mem_fun(&XmlConfig::LoadForm)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("FormRestrict",std::mem_fun(&XmlConfig::LoadFormRestrict)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("FragConvert",std::mem_fun(&XmlConfig::LoadFragConvert)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Fund",std::mem_fun(&XmlConfig::LoadFund)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("FundBase",std::mem_fun(&XmlConfig::LoadFundBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Gem",std::mem_fun(&XmlConfig::LoadGem)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Growing",std::mem_fun(&XmlConfig::LoadGrowing)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBase",std::mem_fun(&XmlConfig::LoadGuildBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattleChat",std::mem_fun(&XmlConfig::LoadGuildBattleChat)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattleCity",std::mem_fun(&XmlConfig::LoadGuildBattleCity)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattleFight",std::mem_fun(&XmlConfig::LoadGuildBattleFight)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattleLog",std::mem_fun(&XmlConfig::LoadGuildBattleLog)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattlePersonRank",std::mem_fun(&XmlConfig::LoadGuildBattlePersonRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattleRank",std::mem_fun(&XmlConfig::LoadGuildBattleRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildBattleSeverPersonRank",std::mem_fun(&XmlConfig::LoadGuildBattleSeverPersonRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildChapter",std::mem_fun(&XmlConfig::LoadGuildChapter)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildChapterFight",std::mem_fun(&XmlConfig::LoadGuildChapterFight)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildDungeon",std::mem_fun(&XmlConfig::LoadGuildDungeon)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildDungeonAward",std::mem_fun(&XmlConfig::LoadGuildDungeonAward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildDungeonSpot",std::mem_fun(&XmlConfig::LoadGuildDungeonSpot)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildFlag",std::mem_fun(&XmlConfig::LoadGuildFlag)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildFlagLv",std::mem_fun(&XmlConfig::LoadGuildFlagLv)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildLog",std::mem_fun(&XmlConfig::LoadGuildLog)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildLv",std::mem_fun(&XmlConfig::LoadGuildLv)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("GuildMember",std::mem_fun(&XmlConfig::LoadGuildMember)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Hero",std::mem_fun(&XmlConfig::LoadHero)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroBase",std::mem_fun(&XmlConfig::LoadHeroBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroExp",std::mem_fun(&XmlConfig::LoadHeroExp)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroGift",std::mem_fun(&XmlConfig::LoadHeroGift)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroGiftProp",std::mem_fun(&XmlConfig::LoadHeroGiftProp)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroGiftSkill",std::mem_fun(&XmlConfig::LoadHeroGiftSkill)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroRecycle",std::mem_fun(&XmlConfig::LoadHeroRecycle)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroSkin",std::mem_fun(&XmlConfig::LoadHeroSkin)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroSoul",std::mem_fun(&XmlConfig::LoadHeroSoul)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroStar",std::mem_fun(&XmlConfig::LoadHeroStar)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("HeroStarRecycle",std::mem_fun(&XmlConfig::LoadHeroStarRecycle)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Item",std::mem_fun(&XmlConfig::LoadItem)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LevelUpReward",std::mem_fun(&XmlConfig::LoadLevelUpReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LoginActReward",std::mem_fun(&XmlConfig::LoadLoginActReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Lottery",std::mem_fun(&XmlConfig::LoadLottery)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LotteryBase",std::mem_fun(&XmlConfig::LoadLotteryBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LuckyTurntable",std::mem_fun(&XmlConfig::LoadLuckyTurntable)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LuckyTurntableBase",std::mem_fun(&XmlConfig::LoadLuckyTurntableBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LuckyTurntableItems",std::mem_fun(&XmlConfig::LoadLuckyTurntableItems)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("LuckyTurntableValue",std::mem_fun(&XmlConfig::LoadLuckyTurntableValue)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MailDouble",std::mem_fun(&XmlConfig::LoadMailDouble)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Misc",std::mem_fun(&XmlConfig::LoadMisc)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MonsterBase",std::mem_fun(&XmlConfig::LoadMonsterBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MonsterProperty",std::mem_fun(&XmlConfig::LoadMonsterProperty)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MonsterStrength",std::mem_fun(&XmlConfig::LoadMonsterStrength)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Mounts",std::mem_fun(&XmlConfig::LoadMounts)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MountsEquip",std::mem_fun(&XmlConfig::LoadMountsEquip)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MountsEquipment",std::mem_fun(&XmlConfig::LoadMountsEquipment)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MountsStar",std::mem_fun(&XmlConfig::LoadMountsStar)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MountsTrain",std::mem_fun(&XmlConfig::LoadMountsTrain)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Mysticshop",std::mem_fun(&XmlConfig::LoadMysticshop)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("MysticshopRefreshCost",std::mem_fun(&XmlConfig::LoadMysticshopRefreshCost)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("NewYearActivity",std::mem_fun(&XmlConfig::LoadNewYearActivity)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("NewYearActivityBase",std::mem_fun(&XmlConfig::LoadNewYearActivityBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("NewYearRecycle",std::mem_fun(&XmlConfig::LoadNewYearRecycle)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Pay",std::mem_fun(&XmlConfig::LoadPay)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PayRebate",std::mem_fun(&XmlConfig::LoadPayRebate)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PaySum",std::mem_fun(&XmlConfig::LoadPaySum)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakArena",std::mem_fun(&XmlConfig::LoadPeakArena)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakArenaBase",std::mem_fun(&XmlConfig::LoadPeakArenaBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakArenaFormat",std::mem_fun(&XmlConfig::LoadPeakArenaFormat)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakArenaMatch",std::mem_fun(&XmlConfig::LoadPeakArenaMatch)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakArenaReward",std::mem_fun(&XmlConfig::LoadPeakArenaReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakRobot",std::mem_fun(&XmlConfig::LoadPeakRobot)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PeakUse",std::mem_fun(&XmlConfig::LoadPeakUse)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PowerSet",std::mem_fun(&XmlConfig::LoadPowerSet)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("PushMessages",std::mem_fun(&XmlConfig::LoadPushMessages)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("QuenchProp",std::mem_fun(&XmlConfig::LoadQuenchProp)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("QuenchRand",std::mem_fun(&XmlConfig::LoadQuenchRand)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("QuestionPoints",std::mem_fun(&XmlConfig::LoadQuestionPoints)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("QuestionRank",std::mem_fun(&XmlConfig::LoadQuestionRank)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Ranking",std::mem_fun(&XmlConfig::LoadRanking)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("RecruitBase",std::mem_fun(&XmlConfig::LoadRecruitBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Rising",std::mem_fun(&XmlConfig::LoadRising)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Robot",std::mem_fun(&XmlConfig::LoadRobot)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("RobotEquip",std::mem_fun(&XmlConfig::LoadRobotEquip)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("RoleBase",std::mem_fun(&XmlConfig::LoadRoleBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("RoleExp",std::mem_fun(&XmlConfig::LoadRoleExp)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("RoleNameBase",std::mem_fun(&XmlConfig::LoadRoleNameBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Scene",std::mem_fun(&XmlConfig::LoadScene)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SevenDayShop",std::mem_fun(&XmlConfig::LoadSevenDayShop)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SevenDayTask",std::mem_fun(&XmlConfig::LoadSevenDayTask)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ShopReset",std::mem_fun(&XmlConfig::LoadShopReset)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Shopitem",std::mem_fun(&XmlConfig::LoadShopitem)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SignPay",std::mem_fun(&XmlConfig::LoadSignPay)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SignReward",std::mem_fun(&XmlConfig::LoadSignReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Skill",std::mem_fun(&XmlConfig::LoadSkill)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SkillElement",std::mem_fun(&XmlConfig::LoadSkillElement)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SkillGift",std::mem_fun(&XmlConfig::LoadSkillGift)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SkillPoint",std::mem_fun(&XmlConfig::LoadSkillPoint)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SkillTree",std::mem_fun(&XmlConfig::LoadSkillTree)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Skin",std::mem_fun(&XmlConfig::LoadSkin)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SnowmanBase",std::mem_fun(&XmlConfig::LoadSnowmanBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SnowmanFlushTime",std::mem_fun(&XmlConfig::LoadSnowmanFlushTime)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SnowmanItem",std::mem_fun(&XmlConfig::LoadSnowmanItem)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SnowmanQuestion",std::mem_fun(&XmlConfig::LoadSnowmanQuestion)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SoulCost",std::mem_fun(&XmlConfig::LoadSoulCost)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SoulSkill",std::mem_fun(&XmlConfig::LoadSoulSkill)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SpeBase",std::mem_fun(&XmlConfig::LoadSpeBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SpeBox",std::mem_fun(&XmlConfig::LoadSpeBox)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SpeRefCost",std::mem_fun(&XmlConfig::LoadSpeRefCost)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SpecialShop",std::mem_fun(&XmlConfig::LoadSpecialShop)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SpiritPurchase",std::mem_fun(&XmlConfig::LoadSpiritPurchase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("StaminaPurchase",std::mem_fun(&XmlConfig::LoadStaminaPurchase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("StaminaReward",std::mem_fun(&XmlConfig::LoadStaminaReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("StaminaRewardBase",std::mem_fun(&XmlConfig::LoadStaminaRewardBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("StaminaRewardDropbox",std::mem_fun(&XmlConfig::LoadStaminaRewardDropbox)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("StarCondition",std::mem_fun(&XmlConfig::LoadStarCondition)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("SysSwitch",std::mem_fun(&XmlConfig::LoadSysSwitch)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Task",std::mem_fun(&XmlConfig::LoadTask)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TaskType",std::mem_fun(&XmlConfig::LoadTaskType)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("ToolResult",std::mem_fun(&XmlConfig::LoadToolResult)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Tower",std::mem_fun(&XmlConfig::LoadTower)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TowerAward",std::mem_fun(&XmlConfig::LoadTowerAward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TowerNormalAward",std::mem_fun(&XmlConfig::LoadTowerNormalAward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TrialBase",std::mem_fun(&XmlConfig::LoadTrialBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TrialFirstMatching",std::mem_fun(&XmlConfig::LoadTrialFirstMatching)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TrialReward",std::mem_fun(&XmlConfig::LoadTrialReward)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TrialRewardRead",std::mem_fun(&XmlConfig::LoadTrialRewardRead)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("TrialRewardVIP",std::mem_fun(&XmlConfig::LoadTrialRewardVIP)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Upgrade",std::mem_fun(&XmlConfig::LoadUpgrade)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("Vip",std::mem_fun(&XmlConfig::LoadVip)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("VipBase",std::mem_fun(&XmlConfig::LoadVipBase)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("VipCount",std::mem_fun(&XmlConfig::LoadVipCount)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("VipFunction",std::mem_fun(&XmlConfig::LoadVipFunction)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("VipGift",std::mem_fun(&XmlConfig::LoadVipGift)),
std::pair<string,std::function<BOOL(XmlConfig*)>>("WelfareBase",std::mem_fun(&XmlConfig::LoadWelfareBase)),
};


BOOL ReloadXmlConfig(string &file)
{
    auto loader=loaders.find(file);
    if(loader!=loaders.end())
    {
        loader->second(&XmlConfig::Instance());
        return true;
    }
    return false;
}
