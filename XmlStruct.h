#ifndef __XMLSTRUCT_H__
#define __XMLSTRUCT_H__
#ifndef ARRSIZE
#define ARRSIZE(a) sizeof(a)/sizeof(a[0])
#endif
#include "CoreCode/CoreDef.h"
#include "Protocol/PubFunDef.h"
#include "CoreCode/CoreDateTime.h"
#include "unistd.h"
#include "unordered_map"
#include <fstream>
using namespace PubFunDef;
#pragma pack(push,1)
enum {
    ROLEBASE_INIGOLD=1,                                                         //角色初始元宝
    ROLEBASE_MAXGOLD=2,                                                         //角色金币最大携带
    ROLEBASE_INICOIN=3,                                                         //角色初始铜币
    ROLEBASE_MAXCOIN=4,                                                         //角色铜币最大携带
    ROLEBASE_INIGONG=5,                                                         //角色初始帮贡
    ROLEBASE_MAXGONG=6,                                                         //角色帮贡最大携带
    ROLEBASE_INIHONOUR=7,                                                       //角色初始声望
    ROLEBASE_MAXHONOUR=8,                                                       //角色声望最大携带
    ROLEBASE_INIROLEEXPERIENCE=9,                                               //角色初始经验
    ROLEBASE_INIROLELEVEL=10,                                                   //角色初始等级
    ROLEBASE_MAXROLELEVEL=11,                                                   //角色最大等级
    ROLEBASE_INIJADE=12,                                                        //角色初始魂玉
    ROLEBASE_MAXJADE=13,                                                        //角色魂玉最大携带
    ROLEBASE_INISPIRIT=14,                                                      //角色初始体力
    ROLEBASE_MAXSPIRIT=15,                                                      //角色最大体力
    ROLEBASE_RECOVERSPIRITGAP=16,                                               //体力恢复时间间隔
    ROLEBASE_RECOVERSPIRITVALUE=17,                                             //体力恢复数量
    ROLEBASE_RECOVERSPIRITTIMING=18,                                            //每日定时恢复体力时间（11：55，17：55）
    ROLEBASE_RECOVERSPIRITTVALUE=19,                                            //每日定时恢复体力数量
    ROLEBASE_GETSPIRITMIDDAY=20,                                                //中午可以领取体力的时间
    ROLEBASE_GETSPIRITMIDDAYVALUE=21,                                           //可领取的体力值
    ROLEBASE_GETSPIRITNIGHT=22,                                                 //晚上可以领取体力的时间
    ROLEBASE_GETSPIRITNIGHTVALUE=23,                                            //可领取的体力值
    ROLEBASE_INISTAMINA=24,                                                     //角色初始耐力
    ROLEBASE_MAXSTAMINA=25,                                                     //角色最大耐力
    ROLEBASE_RECOVERSTAMINAGAP=26,                                              //耐力恢复时间间隔
    ROLEBASE_RECOVERSTAMINAVALUE=27,                                            //耐力恢复数量
    ROLEBASE_RECOVERSTAMINATIMING=28,                                           //每日定时恢复耐力时间（12：00，20：00）
    ROLEBASE_RECOVERSTAMINATVALUE=29,                                           //每日定时恢复耐力数量
    ROLEBASE_INIHEROLIST=30,                                                    //初始化武将列表
    ROLEBASE_INIITEMLIST=31,                                                    //初始化道具列表
    ROLEBASE_MAN=32,                                                            //男主角初始解锁天赋ID
    ROLEBASE_WOMAN=33,                                                          //女主角初始解锁天赋ID
    ROLEBASE_SKILLS=34,                                                         //5个技能栏解锁对应主角等级
    ROLEBASE_SKILLRESETLEVEL=35,                                                //技能重置免费等级（大于等于该技能后需要元宝）
    ROLEBASE_SKILLRESETCOST=36,                                                 //技能重置消耗元宝数量
    ROLEBASE_SKILLRESETMAN=37,                                                  //男主角重置后保留技能
    ROLEBASE_SKILLRESETWOMAN=38,                                                //女主角重置后保留技能
    ROLEBASE_CHANGEGIFTLV=39,                                                   //切换天赋功能解锁等级
    ROLEBASE_SWEEPRUNE=40,                                                      //扫荡符ID
    ROLEBASE_MALEROLEID=41,                                                     //男主角ID
    ROLEBASE_FAMALEROLEID=42,                                                   //女主角ID
    ROLEBASE_SHOPREFRESHCD=43,                                                  //神秘商店自动刷新时间间隔
    ROLEBASE_UNLOCKSKILL=44,                                                    //解锁天赋技能道具ID
    ROLEBASE_UPDATESKILL=45,                                                    //升级天赋技能道具ID
    ROLEBASE_SHOPREFRESH=46,                                                    //神秘商店自动刷新道具数量
    ROLEBASE_REFRESHCOST=47,                                                    //神秘商店手动刷新消耗的元宝数量
    ROLEBASE_LINEOPENLEVEL=48,                                                  //副本幕开启等级
    ROLEBASE_FIGHTINGGRADE=49,                                                  //战斗评级
    ROLEBASE_OPENLIMIT=50,                                                      //武将试炼副本系统开启等级
    ROLEBASE_RESURRECTIONNUM=51,                                                //武将试炼每天复活令数量
    ROLEBASE_RESETTIME=52,                                                      //武将试炼系统重置时间
    ROLEBASE_RESETTIMES=53,                                                     //武将试炼重置次数
    ROLEBASE_CHALLENGESTAMINA=54,                                               //武将试炼挑战消耗耐力
    ROLEBASE_CHALLENGEGOLD=55,                                                  //武将试炼重置消耗元宝数量
    ROLEBASE_CHALLENGEFIGHTNUM=56,                                              //竞技长每个进度下战斗节点数
    ROLEBASE_FIGHTSCENE=57,                                                     //武将试炼战斗场景ID
    ROLEBASE_PVESPIRITEXPEND=58,                                                //副本战斗体力消耗
    ROLEBASE_RESURRECTIONGOLD=59,                                               //复活令价格
    ROLEBASE_MOUNTSOPENLEVEL=60,                                                //坐骑功能解锁等级
    ROLEBASE_DEFAULTMOUNTS=61,                                                  //默认坐骑ID
    ROLEBASE_EXPRATE=62,                                                        //炼化武将经验兑换将魂比率，1点将魂对应多少经验
    ROLEBASE_GUOGONGITEMID=63,                                                  //国贡道具ID
    ROLEBASE_FEEDITEMID=64,                                                     //坐骑饲料道具ID
    ROLEBASE_TRAILMATCHINGNUM=65,                                               //试炼每次匹配对手数量
    ROLEBASE_TRIALSCENE=66,                                                     //武将试炼场景ID
    ROLEBASE_TRIALSCENEID=67,                                                   //武将试炼场景ID
    ROLEBASE_TRIALFIGHTSCENEID=68,                                              //武将试炼战斗场景ID
    ROLEBASE_FIRSTTASKID=69,                                                    //首任务ID
    ROLEBASE_HEROOPENLV=70,                                                     //下导航武将功能开放等级
    ROLEBASE_BAGOPENLV=71,                                                      //下导航背包功能开放等级
    ROLEBASE_SKILLTREEOPENLV=72,                                                //下导航技能功能开放等级
    ROLEBASE_EQUIPOPENLV=73,                                                    //下导航装备功能开放等级
    ROLEBASE_EMBATTLEOPENLV=74,                                                 //下导航布阵功能开放等级
    ROLEBASE_APITEMID=75,                                                       //体力1点
    ROLEBASE_STAMINAITEMID=76,                                                  //耐力1点
    ROLEBASE_APONCEBUYNUM=77,                                                   //每次购买体力点数
    ROLEBASE_STAMINAONCEBUYNUM=78,                                              //每次购买耐力点数
    ROLEBASE_MAXFIGHTROUND=79,                                                  //战斗最大回合数，超过该回合战斗强制结束
    ROLEBASE_ROLEPOSITION1=80,                                                  //男主角
    ROLEBASE_ROLEPOSITION2=81,                                                  //女主角
    ROLEBASE_ROLEINIPOSITION=82,                                                //主角初始位置
    ROLEBASE_WINWORDS=83,                                                       //胜利名词
    ROLEBASE_HORSEOPENLV=84,                                                    //下导航坐骑功能开放等级
    ROLEBASE_DAILYTASKINIOPEN=85,                                               //每日任务初始开放任务
    ROLEBASE_FIRSTRECRUITHERO=86,                                               //第一次招募武将掉落库
    ROLEBASE_TRAILMATCHINGLEVEL=87,                                             //试炼数据录入等级
    ROLEBASE_TRAILMATCHINGDOWNLEVEL=88,                                         //试炼向下匹配等级
    ROLEBASE_TRAILMATCHINGUPLEVEL=89,                                           //试炼向上匹配等级
    ROLEBASE_TRAILMATCHINGEVERYLEVELNUM=90,                                     //每个等级匹配数量
    ROLEBASE_FIRSTTENTHRECRUITHERO=91,                                          //第一次十连抽武将掉落库
    ROLEBASE_LOSEREWARD=92,                                                     //试炼失败奖励阅历
    ROLEBASE_PLOTLIST=93,                                                       //新手剧情SceneID
    ROLEBASE_PLOTMOUNTS=94,                                                     //男主默认坐骑ID
    ROLEBASE_PLOTMOUNTSFE=95,                                                   //女主默认坐骑ID
    ROLEBASE_PLOTCAMPMALE=96,                                                   //序章男主角官职
    ROLEBASE_PLOTCAMPFEMALE=97,                                                 //序章女主角官职
    ROLEBASE_MOUNTSCRITNUM=98,                                                  //坐骑成长值大于999表现暴击
    ROLEBASE_SWEEPOPENLV=99,                                                    //扫荡开启等级
    ROLEBASE_NOFIGHTHINTLV=100,                                                 //主城提示战斗消失等级
    ROLEBASE_DEFAULTMOUNTSSKIN=101,                                             //默认坐骑皮肤ID
    ROLEBASE_SWEEPSTARSLIMIT=102,                                               //可扫荡关卡星数
    ROLEBASE_PLOTPASSSTARS=103,                                                 //剧情过关星数
    ROLEBASE_SHOPRESETTIME=104,                                                 //商店自动重置时间：每日22:00
    ROLEBASE_SHOPRESETDEGREE=105,                                               //商店手动重置次数
    ROLEBASE_INISOUL=106,                                                       //角色初始将魂
    ROLEBASE_MAXSOUL=107,                                                       //角色将魂最大携带
    ROLEBASE_EMAILPRESERVEMAXNUM=108,                                           //邮件保存最大数量
    ROLEBASE_DIAMONDITEMID=109,                                                 //元宝道具ID
    ROLEBASE_EXPLOITITEMID=110,                                                 //功勋道具ID
    ROLEBASE_ACTIVITYFIGHTSCENESOUND=111,                                       //活动副本战斗场景音乐
    ROLEBASE_CAMPMINESCENESOUND=112,                                            //阵营抢矿战斗场景音乐
    ROLEBASE_CAMPGRAINSCENESOUND=113,                                           //阵营劫粮战斗场景音乐
    ROLEBASE_CAMPWARSCENESOUND=114,                                             //阵营战战斗场景音乐
    ROLEBASE_ARENAWARSCENESOUND=115,                                            //竞技场战斗场景音乐
    ROLEBASE_FIGHTSCENESOUND=116,                                               //PVE副本战斗场景音乐
    ROLEBASE_BOSSSCENESOUND=117,                                                //军团神兽战斗场景音乐
    ROLEBASE_CHALLENGESCENESOUND=118,                                           //军团副本战斗场景音乐
    ROLEBASE_TRIALFIGHTSCENESOUND=119,                                          //试炼战斗场景音乐
    ROLEBASE_MAINSCENESOUND=120,                                                //主城场景音乐
    ROLEBASE_TRIALSCENESOUNDSOUND=121,                                          //试炼场景音乐
    ROLEBASE_KUANGBGM=122,                                                      //矿山背景音乐
    ROLEBASE_LIANGBGM=123,                                                      //运粮背景音乐
    ROLEBASE_KUANGSOUND=124,                                                    //矿山环境音
    ROLEBASE_LIANGSOUND=125,                                                    //运粮环境音
    ROLEBASE_DAILYTASKUNLOCKLV=126,                                             //每日任务解锁等级
    ROLEBASE_CHOOSEBGM=127,                                                     //角色选择界面背景音乐
    ROLEBASE_FIGHTSPEED=128,                                                    //战斗二倍速开启等级
    ROLEBASE_REFRESHSIGNTIME=129,                                               //每月1号刷新可补签次数
    ROLEBASE_PAYRENEWDAY=130,                                                   //月卡天数小于等于30天可继续续买一张
    ROLEBASE_MOUNTCARDID=131,                                                   //月卡ID
    ROLEBASE_LIFTTIMECARDID=132,                                                //终身卡ID
    ROLEBASE_FIRSTPAYAWARD=133,                                                 //首充礼包奖励
    ROLEBASE_DAILYPAYPAYAWARD=134,                                              //每日首充礼包奖励
    ROLEBASE_APBUYREFRESHTIME=135,                                              //购买体力次数刷新时间
    ROLEBASE_STAMINABUYREFRESHTIME=136,                                         //购买体力次数刷新时间
    ROLEBASE_PVEEXTERMINATORREFRESHTIME=137,                                    //PVE副本扫荡次数刷新时间
    ROLEBASE_DAILYTASKREFRESH=138,                                              //每日任务刷新时间
    ROLEBASE_GETSPIRITMIDDAYAS=139,                                             //中午可以领取体力的时间
    ROLEBASE_GETSPIRITNIGHTAS=140,                                              //晚上可以领取体力的时间
    ROLEBASE_BBQSHOWTIME=141,                                                   //烤肉提示出现时间
    ROLEBASE_BBQSTOPTIME=142,                                                   //烤肉提示停留时间
    ROLEBASE_MYSTICSHOPREFRESHTIME=143,                                         //神秘商店购买次数刷新时间
    ROLEBASE_GUILDBATTLESOUND=144,                                              //矿山背景音乐
    ROLEBASE_FIGHTSPEEDLV=145,                                                  //战斗三倍速开启玩家等级
    ROLEBASE_FIGHTSPEEDVIP=146,                                                 //战斗三倍速开启VIP等级
    ROLEBASE_ELITESCENELINE=147,                                                //精英副本线路
    ROLEBASE_NEWMAXSTAMINA=148,                                                 //1.3.0版本修复旧角色最大耐力
    ROLEBASE_OPENCLASS=149,                                                     //功能开启等级
    ROLEBASE_PURCHASECOST=150,                                                  //购买消耗
    ROLEBASE_ITEMRECYCLETABSUNLOCKLV=151,                                       //炼化道具页签开启等级
    ROLEBASE_TOWERAUTOFIGHTRESETTIME=152,                                       //爬塔扫荡重置时间
    ROLEBASE_TOWERUNLOCKLEVEL=153,                                              //爬塔解锁等级
    ROLEBASE_TOWERMOREGETVIPLEVEL=154,                                          //爬塔额外掉落Vip等级
    ROLEBASE_TOWERTOPFLOOR=155,                                                 //爬塔最高层数
    ROLEBASE_MYSTICSHOPREFRESHITEMID=156,                                       //魂玉商店刷新代金券道具ID
    ROLEBASE_ARTIFACTUNLOCKLEVEL=161,                                           //神兵解锁等级
    ROLEBASE_ARTIFACTSTARUNLOCKLEVEL=162,                                       //神兵升星解锁等级
    ROLEBASE_ARTIFACTWASHUNLOCKLEVEL=163,                                       //神兵百炼解锁等级
    ROLEBASE_ARTIFACTINHERITUNLOCKLEVEL=164,                                    //神兵继承解锁等级
    ROLEBASE_ARTIFACTUPGRADEUNLOCKLEVEL=165,                                    //神兵炼化解锁等级
    ROLEBASE_ARTIFACTINHERITPRICE=166,                                          //继承价格
    ROLEBASE_ARTIFACTSTRENGTHENBLESSMAX=167,                                    //神兵强化祝福值上限
    ROLEBASE_ARTIFACTSTRENGTHENBLESS=168,                                       //神兵强化祝福值
    ROLEBASE_ARTIFACTSTARBLESSMAX=169,                                          //神兵升星祝福值上限
    ROLEBASE_ARTIFACTSTARBLESS=170,                                             //神兵升星祝福值
    ROLEBASE_ARTIFACTMAXPACK=171,                                               //神兵背包最大值
    ROLEBASE_ARTIFACTGOLDTREASURENORMALLOOT=172,                                //神兵元宝普通掉落库
    ROLEBASE_ARTIFACTGOLDTREASURESPECIALLOOT=173,                               //神兵元宝特殊掉落库
    ROLEBASE_ARTIFACTGOLDTREASURESUPERGETTIME=174,                              //神兵元宝第N次特殊掉落
    ROLEBASE_ARTIFACTGOLDTREASUREONCECOST=175,                                  //神兵元宝单抽花费
    ROLEBASE_ARTIFACTGOLDTREASURECD=176,                                        //神兵元宝单抽CD
    ROLEBASE_ARTIFACTGOLDTREASURETENCOST=177,                                   //神兵元宝十连抽花费
    ROLEBASE_ARTIFACTGOLDTREASURETENCOSTITEM=178,                               //神兵元宝十连抽抵用券Id
    ROLEBASE_ARTIFACTGOLDTREASURELUCK=179,                                      //神兵元宝每次抽取幸运值
    ROLEBASE_ARTIFACTMONEYTREASURENORMALLOOT=180,                               //神兵铜币普通掉落库
    ROLEBASE_ARTIFACTMONEYTREASURESPECIALLOOT=181,                              //神兵铜币特殊掉落库
    ROLEBASE_ARTIFACTMONEYTREASURESUPERGETTIME=182,                             //神兵铜币第N次特殊掉落
    ROLEBASE_ARTIFACTMONEYTREASUREONCECOST=183,                                 //神兵铜币单抽花费
    ROLEBASE_ARTIFACTMONEYTREASURECD=184,                                       //神兵铜币单抽CD
    ROLEBASE_ARTIFACTMONEYTREASURETENCOST=185,                                  //神兵铜币十连抽花费
    ROLEBASE_ARTIFACTMONEYTREASURELUCK=186,                                     //神兵铜币每次抽取幸运值
    ROLEBASE_ARTIFACTMONEYTREASUREONCETIMESMAX=187,                             //神兵铜币单抽每日上限次数
    ROLEBASE_ARTIFACTMONEYTREASURETENTIMESMAX=188,                              //神兵铜币十连抽每日上限次数（废弃）
    ROLEBASE_ARTIFACTWASHTIMES=189,                                             //百炼次数档位
    ROLEBASE_SEVENDAYOPENLV=190,                                                //5天开放等级
    ROLEBASE_SEVENDAYTIME=191,                                                  //5天持续时间
    ROLEBASE_BACKREWARDOPENLV=192,                                              //回归奖励开放等级
};
enum {
    HEROBASE_COMMANDHP=1,                                                       //生命加成系数
    HEROBASE_POWERATK=2,                                                        //物攻加成系数
    HEROBASE_POWERDEF=3,                                                        //物防加成系数
    HEROBASE_IQMATK=4,                                                          //法功加成系数
    HEROBASE_IQMDEF=5,                                                          //法防加成系数
    HEROBASE_HPFTG=6,                                                           //生命战力
    HEROBASE_ATKFTG=7,                                                          //物攻战力
    HEROBASE_DEFFTG=8,                                                          //物防战力
    HEROBASE_MATKFTG=9,                                                         //法攻战力
    HEROBASE_MDEFFTG=10,                                                        //法防战力
    HEROBASE_HITFTG=11,                                                         //命中战力
    HEROBASE_DUCKFTG=12,                                                        //闪避战力
    HEROBASE_CRITFTG=13,                                                        //暴击战力
    HEROBASE_COUNTERCRITFTG=14,                                                 //抗暴战力
    HEROBASE_COUNTERATKFTG=15,                                                  //反击战力
    HEROBASE_DCOUNTERATKFTG=16,                                                 //破挡战力
    HEROBASE_PARRYFTG=17,                                                       //格挡战力
    HEROBASE_EQUIPLVLIMIT=18,                                                   //装备最大等级为当前主角等级的倍数
    HEROBASE_TREASURELVLIMIT=19,                                                //宝物最大等级为当前主角等级的倍数
    HEROBASE_UPGRADEOPENLEVEL=20,                                               //武将升级的开放等级
    HEROBASE_BREAKUPOPENLEVEL=21,                                               //武将培养页签的开放等级
    HEROBASE_HITREAL=22,                                                        //命中数值战斗系数
    HEROBASE_DUCKREAL=23,                                                       //闪避数值战斗系数
    HEROBASE_CRITREAL=24,                                                       //暴击数值战斗系数
    HEROBASE_COUNTERCRITREAL=25,                                                //抗暴数值战斗系数
    HEROBASE_COUNTERATKREAL=26,                                                 //反击数值战斗系数
    HEROBASE_DCOUNTERATKREAL=27,                                                //破挡数值战斗系数
    HEROBASE_PARRYREAL=28,                                                      //格挡数值战斗系数
    HEROBASE_HITLIMIT=29,                                                       //命中数值上限
    HEROBASE_DUCKLIMIT=30,                                                      //闪避数值上限
    HEROBASE_CRITLIMIT=31,                                                      //暴击数值上限
    HEROBASE_COUNTERCRITLIMIT=32,                                               //抗暴数值上限
    HEROBASE_COUNTERATKLIMIT=33,                                                //反击数值上限
    HEROBASE_DCOUNTERATKLIMIT=34,                                               //破挡数值上限
    HEROBASE_PARRYLIMIT=35,                                                     //格挡数值上限
    HEROBASE_PROMPTOPEN=36,                                                     //装备绿点提示等级
    HEROBASE_HEROSTAROPEN=37,                                                   //大于等于该等级武将出现升星提示
    HEROBASE_FRAGITEM=38,                                                       //万能碎片ID
}; 
enum {
    EMAIL_ARENAREWARD=1,                                                        //TitleArenaReward
    EMAIL_ARENAUPGRADE=2,                                                       //TitleArenaUpgrade
    EMAIL_ARENAOUT=3,                                                           //TitleArenaOut
    EMAIL_CAMPGRAINROBBED=4,                                                    //TitleCampGrainRobbed
    EMAIL_CAMPGRAINREWARD=5,                                                    //TitleCampGrainReward
    EMAIL_GRAINCAMPRANKREWARD=6,                                                //TitleGrainCampRankReward
    EMAIL_GRAINPERSONREWARD=7,                                                  //TitleGrainPersonReward
    EMAIL_MINECAMPRANKREWARD=8,                                                 //TitleMineCampRankReward
    EMAIL_MINEPERSONREWARD=9,                                                   //TitleMinePersonReward
    EMAIL_WARCAMPRANKREWARD=10,                                                 //TitleWarCampRankReward
    EMAIL_TURNTABLEPERSONREWARD=11,                                             //TitleTurntablePersonReward
    EMAIL_GUILDBOSSEXTRADROP=12,                                                //TitleGuildBossExtraDrop
    EMAIL_TASKCOMPLETEREWARD=13,                                                //TitleTaskCompleteReward
    EMAIL_CAMPWARPERSONREWARD=14,                                               //TitleCampWarPersonReward
    EMAIL_MINECAMPMAXREWARD=15,                                                 //TitleMineCampMaxReward
    EMAIL_MINECAMPROBBEDREWARD=16,                                              //TitleMineCampRobbedReward
    EMAIL_MINECAMPGIVEUPREWARD=17,                                              //TitleMineCampGiveupReward
    EMAIL_MINECAMPOVERREWARD=18,                                                //TitleMineCampOverReward
    EMAIL_VIPDAILYGIFTREWARD=19,                                                //TitleVipDailyGiftReward
    EMAIL_ARENATOPREWARD=20,                                                    //TitleArenaTopReward
    EMAIL_BOSSFEEDREBATE=21,                                                    //TitleBossFeedRebate
    EMAIL_BOSSDAMAGEREWARD=22,                                                  //TitleBossDamageReward
    EMAIL_PACKAGEREWARD=23,                                                     //TitlePackageReward
    EMAIL_GUILDKICKOUT=24,                                                      //TitleGuildKickOut
    EMAIL_PAYREBATE=25,                                                         //TitlePayRebate
    EMAIL_NEWARMY=26,                                                           //TitleNewArmy
    EMAIL_OLDARMY=27,                                                           //TitleOldArmy
    EMAIL_GUILDBATTLEPERSONAWARD=28,                                            //TitleGuildBattlePersonAward
    EMAIL_GUILDBATTLEJOINAWARD=29,                                              //TitleGuildBattleJoinAward
    EMAIL_GUILDBATTLECONQUERAWARD=30,                                           //TitleGuildBattleConquerAward
    EMAIL_GUILDBATTLEPUBLICITEMGET=31,                                          //TitleGuildBattlePublicItemGet
    EMAIL_GUILDBATTLESERVERPERSONAWARD=32,                                      //TitleGuildBattleServerPersonAward
    EMAIL_PEAKARENAREWARD=33,                                                   //PeakTitleArenaReward
    EMAIL_DAILYFIRSTPAYREFOUND=34,                                              //TitleDailyFirstPayRefound
    EMAIL_DAILYSUMPAYREFOUND=35,                                                //TitleDailySumPayRefound
    EMAIL_PEAKARENATSREWARD=36,                                                 //PeakTitleArenaTsReward
    EMAIL_DAILYSUMCOSTREFOUND=37,                                               //TitleDailySumCostRefound
    EMAIL_SNOWMANRANKREFOUND=38,                                                //TitleSnowmanRankRefound
    EMAIL_GUILDDUNGEONRANKAWARD=39,                                             //TitleGuildDungeonRankAward
    EMAIL_GUILDDUNGEONSHUTAWARD=40,                                             //TitleGuildDungeonShutAward
    EMAIL_GUILDDUNGEONLOSEAWARD=41,                                             //TitleGuildDungeonLoseAward
    EMAIL_GUILDDUNGEONWINAWARD=42,                                              //TitleGuildDungeonWinAward
    EMAIL_PEAKARENAMERGEREWARD=43,                                              //TitlePeakArenaMergeReward
    EMAIL_ARTIFACTPACKAGEMAXREFIND=44,                                          //TitleArtifactPackageMaxRefind
};
enum {
    MISC_PERCOEFFICIENT=1,                                                      //百分比系数
    MISC_FIRSTCHAPTER=2,                                                        //新账号默认打开第一个关卡
    MISC_MAXPROBABLY=3,                                                         //随机数最大值
    MISC_CHARGEOPEN=4,                                                          //是否开启充值
    MISC_PUSHURL=5,                                                             //推送功能URL
    MISC_CHANNEL=6,                                                             //渠道前缀
    MISC_CODEOPEN=7,                                                            //是否开启兑换码
    MISC_CODEURL=8,                                                             //兑换码URL
    MISC_DOUBLEFIRST=9,                                                         //是否开启首冲双倍
};
enum {
    EQUIPBASE_QUENCHOPENCOST=1,                                                 //每拥有1条淬火项消耗淬火项参数
    EQUIPBASE_QUENCHLOCKCOST=2,                                                 //锁定每项消耗淬火石参数
    EQUIPBASE_QUENCHCOSTITEM=3,                                                 //淬火石
    EQUIPBASE_EQUIP1OPENLEVEL=4,                                                //武将武器解锁【和主角等级相关】
    EQUIPBASE_EQUIP2OPENLEVEL=5,                                                //武将铠甲解锁等级【和主角等级相关】
    EQUIPBASE_EQUIP3OPENLEVEL=6,                                                //武将头盔解锁等级【和主角等级相关】
    EQUIPBASE_EQUIP4OPENLEVEL=7,                                                //武将战靴解锁等级【和主角等级相关】
    EQUIPBASE_EQUIP5OPENLEVEL=8,                                                //武将戒指解锁等级【和主角等级相关】
    EQUIPBASE_EQUIP6OPENLEVEL=9,                                                //武将项链解锁等级【和主角等级相关】
    EQUIPBASE_INTENSIFYOPENLEVEL=10,                                            //强化开放等级
    EQUIPBASE_PLATEOPENLEVEL=11,                                                //打造开放等级
    EQUIPBASE_QUENCHOPENLEVEL=12,                                               //淬火开放等级
    EQUIPBASE_GEMOPENLEVEL=13,                                                  //镶嵌开放等级
    EQUIPBASE_QUENCHCRITKEY=14,                                                 //等Key为5是播放淬火暴击特效
    EQUIPBASE_QUENCH1UNLOCK=15,                                                 //第一条淬火属性项解锁条件
    EQUIPBASE_QUENCH2UNLOCK=16,                                                 //第二条淬火属性项解锁条件
    EQUIPBASE_QUENCH3UNLOCK=17,                                                 //第三条淬火属性项解锁条件
    EQUIPBASE_EQUIP5GEM1UNLOCK=18,                                              //戒指第一个宝石槽
    EQUIPBASE_EQUIP5GEM2UNLOCK=19,                                              //戒指第二个宝石槽
    EQUIPBASE_EQUIP5GEM3UNLOCK=20,                                              //戒指第三个宝石槽
    EQUIPBASE_EQUIP6GEM1UNLOCK=21,                                              //项链第一个宝石槽
    EQUIPBASE_EQUIP6GEM2UNLOCK=22,                                              //项链第二个宝石槽
    EQUIPBASE_EQUIP6GEM3UNLOCK=23,                                              //项链第三个宝石槽
};
enum {
    VIPBASE_MAXSPIRIT=1,                                                        //1.体力值上限，文字提示：体力上限{0}
    VIPBASE_BUYSPIRITCOUNT=2,                                                   //2.购买体力次数，文字提示：每日可购买{0}次\n
    VIPBASE_MAXSTAMINA=3,                                                       //3.耐力值上限，文字提示：耐力上限{0}
    VIPBASE_BUYSTAMINACOUNT=4,                                                  //4.购买耐力次数,文字提示：每日可购买{0}次\n
    VIPBASE_BUYMYSTICSHOPREFRESHCOUNT=5,                                        //5.神秘商店购买刷新次数，文字提示：神秘商店可刷新{0}次
    VIPBASE_BUYMONEYCOUNT=6,                                                    //6.购买铜币次数，文字提示：铜币可购买{0}次\n
    VIPBASE_BUYARENAFIGHTCOUNT=7,                                               //7.竞技场挑战购买次数，文字提示：竞技场挑战可挑战{0}次\n
    VIPBASE_BUYTRIALSRESETCOUNT=8,                                              //8.武将试炼重置购买次数，文字提示：试炼重置可购买{0}次\n
    VIPBASE_BUYCAMPTHROUGHONCEMORENUM=9,                                        //9.购买阵营闯关再来一次次数,文字提示：阵营闯关再来一次可购买{0}次\n
    VIPBASE_BUYCAMPGRAINCOLORNUM=10,                                            //10.元宝刷新木牛流马品质次数上限，文字提示：粮车刷新可购买{0}次\n
    VIPBASE_BUYCAMPGRAINTRANSNUM=11,                                            //11.购买木牛流马运粮次数上限，文字提示：运粮可购买{0}次
    VIPBASE_BUYCAMPGRAINROBNUM=12,                                              //12.木牛流马元宝劫粮次数上限，文字提示：劫粮可购买{0}次\n
    VIPBASE_BUYCAMPMINEROBNUM=13,                                               //13.阵营资源战元宝抢夺次数上限，文字提示：资源站可抢夺{0}次
    VIPBASE_BUYCAMPWARFIGHTNUM=14,                                              //14.阵营战元宝挑战次数上限，文字提示：阵营战可挑战{0}次\n
    VIPBASE_BUYGUILDDONATEGOLDNUM=15,                                           //15.元宝捐献次数，文字提示：军团可捐献{0}次\n
    VIPBASE_BUYGUILDBOSSGOLDNUM=16,                                             //16.元宝喂养神兽次数，文字提示：神兽喂养可购买{0}次
    VIPBASE_BUYGUILDBOSSFIGHTNUM=17,                                            //17.挑战神兽次数，文字提示：挑战可购买{0}次
    VIPBASE_BUYSIGNREWARDNUM=18,                                                //18.签到可预签奖励次数，文字提示：签到可预签奖励次数 {0}次
    VIPBASE_MINECHALLENGEREVIVETIMES=19,                                        //19.矿山挑战主角复活次数，文字提示：签到可预签奖励次数 {0}次
    VIPBASE_TOWEREXACTAWARD=20,                                                 //20.爬塔额外掉落，文字提示：爬塔可额外掉落珍稀物品
    VIPBASE_TOWERAUTOFIGHTTIMES=21,                                             //21.爬塔每日扫荡次数，文字提示：爬塔每日可扫荡{0}次
};
enum {
    ARENABASE_REWARDTIME=1,                                                     //奖励发放时间
    ARENABASE_CHALLENGESTAMINA=2,                                               //挑战消耗耐力
    ARENABASE_UPLOCKLEVEL=3,                                                    //竞技场解锁等级
    ARENABASE_ARENACHALLENGENUM=4,                                              //每天挑战次数
    ARENABASE_ARENAREPORTNUM=5,                                                 //保存战报数量
    ARENABASE_REWARDRESETTIME=6,                                                //发奖重置时间
    ARENABASE_ARENAWARSCENE=7,                                                  //竞技场战斗场景
    ARENABASE_ARENAWARSCENEID=8,                                                //竞技场战斗场景
    ARENABASE_DOWNMATCHINGNUM=9,                                                //向下匹配数量
    ARENABASE_UPMATCHINGNUM=10,                                                 //向上匹配数量
    ARENABASE_SUBUPMATCHINGNUM=11,                                              //大幅向上匹配数量
    ARENABASE_ARENACHALLENGEDIAMOND=12,                                         //挑战次数购买单价
    ARENABASE_ARENAFIGHTWINDROPBOXID=13,                                        //竞技场战斗胜利奖励包
    ARENABASE_ARENAFIGHTLOSEDROPBOXID=14,                                       //竞技场战斗失败奖励包
    ARENABASE_REPORTPRESERVENUM=15,                                             //战报保存数量
    ARENABASE_REPORTPRESERVETIME=16,                                            //战报保存最长时间
    ARENABASE_MAXRANK=17,                                                       //超过这个名次按照下面两条规则取目标
    ARENABASE_MATCHVALUE=18,                                                    //每个区间取玩家数量
    ARENABASE_MATCHRANK=19,                                                     //取敌人排名区间
    ARENABASE_UPGRADEREWARD1=20,                                                //初次晋级精英赛区奖励元宝
    ARENABASE_UPGRADEREWARD2=21,                                                //初次晋级典将赛区奖励元宝
    ARENABASE_ONEDAYCOUNT=22,                                                   //每日可进行晋级挑战次数
    ARENABASE_UPGRADEFIGHTREFRESHTIME=23,                                       //晋级机会刷新时间
    ARENABASE_CLOSECHALLENGEBUTTON=24,                                          //在该赛区关闭晋级挑战按钮
    ARENABASE_ARENA1=25,                                                        //青龙一区编号
    ARENABASE_ARENA2=26,                                                        //青龙二区编号
    ARENABASE_ARENA3=27,                                                        //朱雀一区编号
    ARENABASE_ARENA4=28,                                                        //朱雀二区编号
    ARENABASE_ARENA5=29,                                                        //白虎一区编号
    ARENABASE_ARENA6=30,                                                        //白虎二区编号
    ARENABASE_ARENA7=31,                                                        //玄武一区编号
    ARENABASE_ARENA8=32,                                                        //玄武二区编号
    ARENABASE_ARENA9=33,                                                        //青龙精英编号
    ARENABASE_ARENA10=34,                                                       //朱雀精英编号
    ARENABASE_ARENA11=35,                                                       //白虎精英编号
    ARENABASE_ARENA12=36,                                                       //玄武精英编号
    ARENABASE_ARENA13=37,                                                       //典将精英编号
    ARENABASE_ELITEARENAID=38,                                                  //大于并且小于13的均为精英赛区
};
enum {
    RECRUITBASE_FREETIME=1,                                                     //免费抽取时间
    RECRUITBASE_NORMALPRICE=2,                                                  //普通抽取价格
    RECRUITBASE_TENPRICE=3,                                                     //十连抽价格
    RECRUITBASE_OPENLEVEL=4,                                                    //招募开启等级
    RECRUITBASE_COSTPRICE=5,                                                    //原价
    RECRUITBASE_NORMALDROP=6,                                                   //抽取掉落库选择，0为普通抽取，1为必掉紫卡
    RECRUITBASE_EVENTNORMALPRICE=7,                                             //活动单抽价格
    RECRUITBASE_EVENTTENPRICE=8,                                                //活动十连抽价格
    RECRUITBASE_EVENTCOSTPRICE=9,                                               //活动十连抽原价
    RECRUITBASE_OPENWEEK=10,                                                    //开启周
    RECRUITBASE_CHIPDROPID=11,                                                  //碎片掉落ID
    RECRUITBASE_EXTRACTIONSNUM=12,                                              //抽取数量
    RECRUITBASE_EVENTHEROPROB=13,                                               //抽取碎片时掉落活动武将的概率
    RECRUITBASE_EVENTDROP=14,                                                   //抽取活动将间隔
    RECRUITBASE_RECRUITHERO=15,                                                 //招募品质小于等于
    RECRUITBASE_FIRSTRECRUIT=16,                                                //抽次十连抽武将ID
    RECRUITBASE_FIRSTRECRUITTIME=17,                                            //第一次招募倒计时
    RECRUITBASE_EVENTGAP=18,                                                    //限时招募间隔
    RECRUITBASE_EVENTOPENVIP=19,                                                //限时招募开放的VIP等级
    RECRUITBASE_RECRUITITEMID=20,                                               //普通招募代金券道具ID
    RECRUITBASE_EVENTRECRUITITEMID=21,                                          //限时招募代金券道具ID
};
enum {
    CAMPBASE_RANDOMCAMP=1,                                                      //随机阵营奖励
    CAMPBASE_CHANGECAMP=2,                                                      //更换阵营消耗元宝
    CAMPBASE_CUSTOMSCLEARANCE=3,                                                //阵营闯关通关奖励
    CAMPBASE_ONCEMORE=4,                                                        //阵营闯关铜币再来一次消耗
    CAMPBASE_TURNTABLEONCE=5,                                                   //每次转盘消耗国贡
    CAMPBASE_TURNTABLERANKING=6,                                                //转盘排行榜ID
    CAMPBASE_MINEREFRESH=7,                                                     //刷新矿山消耗铜币
    CAMPBASE_MINECAMPRANKING=8,                                                 //矿山争霸阵营排名国贡奖励
    CAMPBASE_MINETOTALREWARD=9,                                                 //矿山争霸总国贡奖励
    CAMPBASE_CHANGECOLOR1=10,                                                   //木牛流马刷新品质消耗铜币
    CAMPBASE_CHANGECOLOR2=11,                                                   //木牛流马刷新品质消耗元宝
    CAMPBASE_DIRECTGOLD=12,                                                     //一键暗金消耗元宝
    CAMPBASE_DIRECTGOLDID=13,                                                   //一键暗金粮车编号
    CAMPBASE_GRAINREFRESH=14,                                                   //刷新木牛流马消耗铜币
    CAMPBASE_GRAINCAMP=15,                                                      //木牛流马阵营排名国贡奖励
    CAMPBASE_GRAINTOTALREWARD=16,                                               //木牛流马总国贡奖励
    CAMPBASE_WARMATCHING=17,                                                    //阵营战匹配消耗铜币
    CAMPBASE_INITIALSCORE=18,                                                   //阵营战玩家初始积分
    CAMPBASE_WARWIN=19,                                                         //阵营战胜利加分
    CAMPBASE_WARLOSE=20,                                                        //阵营战失败减分
    CAMPBASE_WARREWARD=21,                                                      //阵营战胜利奖励
    CAMPBASE_WARCAMPRANKING=22,                                                 //阵营战阵营排名国贡奖励
    CAMPBASE_PLAYERRANKINGNUM=23,                                               //排行榜玩家排名显示数量
    CAMPBASE_CAMPOUTOFFICE=24,                                                  //排行榜以外玩家官职
    CAMPBASE_GETGRAINONCETIME=25,                                               //单次运粮消耗时间
    CAMPBASE_GRAINOPENTIME=26,                                                  //运粮开启时间时间
    CAMPBASE_STARTCUSTOMS=27,                                                   //阵营闯关起始关卡
    CAMPBASE_ENDINGCUSTOMS=28,                                                  //阵营闯关结束关卡
    CAMPBASE_MINEREFRESHTIME=29,                                                //矿山争霸排行榜刷新时间
    CAMPBASE_CAMPWARSCENE=30,                                                   //阵营活动战斗场景
    CAMPBASE_GUOGONGITEMID=31,                                                  //国贡道具ID
    CAMPBASE_MINENUM=32,                                                        //同屏矿山显示数量
    CAMPBASE_TURNRANKOPENDAYS=33,                                               //转盘排行榜开放时间
    CAMPBASE_CAMPWARSCENEID=34,                                                 //阵营战战斗场景
    CAMPBASE_THROUGHRESETNUM=35,                                                //阵营闯关重置次数
    CAMPBASE_THROUGHRESETDIAMOND=36,                                            //阵营闯关重置价格
    CAMPBASE_GRAINROBBEDMAX=37,                                                 //粮车被劫最大次数
    CAMPBASE_GRAINTRANSDIAMOND=38,                                              //购买运粮次数单价
    CAMPBASE_GRAINROBDIAMOND=39,                                                //购买抢粮次数单价
    CAMPBASE_GRAININITIALCARID=40,                                              //初始粮车品质
    CAMPBASE_WARCHALLENGEDIAMOND=41,                                            //阵营战挑战次数单价
    CAMPBASE_MINETOTALREWARDPAR=42,                                             //矿山争霸总国贡奖励参数
    CAMPBASE_GRAINTOTALREWARDPAR=43,                                            //木牛流马总国贡奖励参数
    CAMPBASE_WARTOTALREWARDPAR=44,                                              //阵营战总国贡奖励参数
    CAMPBASE_MINEOCCUPATIONLIMIT=45,                                            //矿山争霸每日占矿时间上限
    CAMPBASE_MINESETTLEMENTTIME=46,                                             //占矿结算时间
    CAMPBASE_COINID=47,                                                         //1铜币道具id（用于矿区奖励发放）
    CAMPBASE_CAMPMINESCENEID=48,                                                //抢矿战斗场景
    CAMPBASE_CAMPGRAINSCENEID=49,                                               //劫粮战斗场景
    CAMPBASE_THROUGHMAP=50,                                                     //阵营闯关活动地图
    CAMPBASE_GRAINNUM=51,                                                       //同屏粮车显示数量
    CAMPBASE_FIGHTSTAMINA=52,                                                   //阵营战斗耐力消耗
    CAMPBASE_FIGHTWINGUOGONG=53,                                                //阵营战斗胜利国贡奖励
    CAMPBASE_FIGHTLOSEGUOGONG=54,                                               //阵营战斗失败国贡奖励
    CAMPBASE_WARMATCHDIAMOND=55,                                                //阵营战匹配消耗元宝数量
    CAMPBASE_CAMPMINEROBGOLDFACTOR=56,                                          //抢矿获得铜币比例
    CAMPBASE_CAMPMINEROBGOLDLEVELFACTOR=57,                                     //抢矿等级保护系数
    CAMPBASE_CAMPTURNTABLESURPRISETIMES=58,                                     //国贡大转盘获得惊喜奖励转盘次数
    CAMPBASE_CAMPTURNTABLESURPRISEITEMS=59,                                     //国贡大转盘惊喜奖励
    CAMPBASE_GRAINREFRESHCDTIME=60,                                             //刷新粮车冷却时间
    CAMPBASE_GRAINFREETIMES=61,                                                 //免费运粮次数
    CAMPBASE_HEROPROPERTYADDPERCENT=62,                                         //阵营相关战斗武将属性加成
    CAMPBASE_CAMPFIGHTWINDROPBOXID=63,                                          //阵营战斗胜利奖励包
    CAMPBASE_CAMPFIGHTLOSEDROPBOXID=64,                                         //阵营战斗失败奖励包
    CAMPBASE_TURNTABLEOPENTIME=65,                                              //转盘开放时间
    CAMPBASE_MINESWITCHTIMEOUT=66,                                              //同一矿区换矿CD时间
    CAMPBASE_MINERANKINGNUM=67,                                                 //矿山争霸个人排行榜显示数量
    CAMPBASE_GRAINRANKINGNUM=68,                                                //木牛流马个人排行榜显示数量
    CAMPBASE_WARRANKINGNUM=69,                                                  //阵营战个人排行榜显示数量
    CAMPBASE_THROUGHREFRESHTIME=70,                                             //阵营闯关刷新时间
    CAMPBASE_TURNTABLEFREEREFRESHTIME=71,                                       //大转盘免费次数刷新时间
    CAMPBASE_THROUGHOPENLV=72,                                                  //阵营闯过开放等级
    CAMPBASE_TURNTABLEOPENLV=73,                                                //大转盘开放等级
    CAMPBASE_CAMPFIGHTOPENLV=74,                                                //军团战开放等级
    CAMPBASE_MINEOPENLV=75,                                                     //矿山争霸开放等级
    CAMPBASE_GRAINOPENLV=76,                                                    //木牛流马开放等级
    CAMPBASE_MINEOPENTIME=77,                                                   //矿山开放时间
    CAMPBASE_WAROPENTIME=78,                                                    //阵营战开放时间
    CAMPBASE_MINETOTALREWARDPARTIME=79,                                         //矿山争霸个人排行榜发放奖励时间
    CAMPBASE_GRAINTOTALREWARDPARTIME=80,                                        //木牛流马个人排行榜发放奖励时间
    CAMPBASE_WARTOTALREWARDPARTIME=81,                                          //阵营战个人排放航榜发放奖励时间
    CAMPBASE_MINECAMPRANKINGTIME=82,                                            //矿山争霸阵营排行榜发放奖励时间
    CAMPBASE_GRAINCAMPRANKINGTIME=83,                                           //木牛流马阵营排行榜发放奖励时间
    CAMPBASE_WARCAMPRANKINGTIME=84,                                             //阵营战阵营排放航榜发放奖励时间
    CAMPBASE_GRAINGIVE=85,                                                      //运粮奖励的魂玉Item
    CAMPBASE_TURNTABLEGIVEREFRESHTIME=86,                                       //大转盘奖励刷新时间
    CAMPBASE_MINEROBMONEYCONVERTRATE=90,                                        //矿山铜币积分转换比
    CAMPBASE_MINEROBSOULCONVERTRATE=91,                                         //矿山将魂积分转换比
    CAMPBASE_MINEROBGEMCONVERTRATE=92,                                          //矿山宝石积分转换比
    CAMPBASE_GETRATIO=93,                                                       //矿山获得频率
    CAMPBASE_MINE2UNLOCKCONDITION=94,                                           //矿2开启条件
    CAMPBASE_MINE3UNLOCK=95,                                                    //矿3开启条件
    CAMPBASE_ONCEROBTIMES=96,                                                   //矿山主角复活次数
    CAMPBASE_MINEREFRESHPRICE=97,                                               //矿山刷新售价
    CAMPBASE_MINECHALLENGETIME=98,                                              //矿山被挑战限时
    CAMPBASE_MINEUPGRADERATE=99,                                                //矿山升级加速倍率
    CAMPBASE_MINEROBPROTECTCD=100,                                              //矿山被抢夺保护CD
    CAMPBASE_MINESEARCHSECTIONUP=101,                                           //矿山匹配等级上区间
    CAMPBASE_MINESEARCHSECTIONDOWN=102,                                         //矿山匹配等级下区间
    CAMPBASE_MINEUPGRADEFREETIMES=103,                                          //矿山每日免费次数
    CAMPBASE_MINEUPGRADEFREETIMESRESTTIME=104,                                  //矿山每日免费次数重置时间
    CAMPBASE_MINEOPENLEVEL=105,                                                 //矿山功能开放等级
    CAMPBASE_MINECHALLENGECOSTSTAMINA=106,                                      //抢矿消耗耐力
    CAMPBASE_MINECHALLENGEWINDROPBOXID=107,                                     //抢矿战胜掉落包
    CAMPBASE_MINECHALLENGEFAILDROPBOXID=108,                                    //抢矿战败掉落包
    CAMPBASE_MINESEARCHMINTIME=109,                                             //矿山被匹配最低生产时间
    CAMPBASE_MINEREFRESHPRICEC=110,                                             //矿山刷新售价(客户端）
    CAMPBASE_MINEROBWINSCORE=111,                                               //矿山战胜积分
    CAMPBASE_MINEROBPREPARETIME=112,                                            //矿山匹配准备时间
    CAMPBASE_MINEROBREVENGEPRICE=113,                                           //矿山复仇价格
};
enum {
    GUILDBASE_CREATGUILDCOST=1,                                                 //创建军团消耗元宝
    GUILDBASE_OUTGUILDTIMELIMIT=2,                                              //禁止退团时间
    GUILDBASE_GUILDORIGINALLV=3,                                                //军团默认初始等级
    GUILDBASE_GUILDMAXLV=4,                                                     //军团最大等级
    GUILDBASE_GUILDORIGINALMONEY=5,                                             //军团默认初始资金
    GUILDBASE_GUILDORIGINALEXP=6,                                               //军团默认初始经验
    GUILDBASE_GUILDBOSSORIGINALLV =7,                                           //军团神兽默认初始等级
    GUILDBASE_GUILDBOSSMAXLV =8,                                                //军团神兽最大等级等级
    GUILDBASE_BOSSID=9,                                                         //神兽id
    GUILDBASE_BOSSNAME=10,                                                      //神兽名字
    GUILDBASE_REJOINTIMELIMIT=11,                                               //退团再加入冷却时间
    GUILDBASE_ANNOUNCEMENTCOST=12,                                              //发招募公告消耗元宝
    GUILDBASE_FLAGORIGINALLV =13,                                               //军团战旗初始等级
    GUILDBASE_FLAGMAXLV =14,                                                    //军团战旗最大等级
    GUILDBASE_ORIGINALVALUELV=15,                                               //战旗属性初始等级
    GUILDBASE_ORIGINALVALUEMAXLV=16,                                            //战旗属性最大等级
    GUILDBASE_GUILDDATAREFRESHTIME=17,                                          //军团数据刷新时间CD
    GUILDBASE_MEMBERDATAREFRESHTIME=18,                                         //成员数据刷新时间CD
    GUILDBASE_CHALLENGETIME=19,                                                 //军团副本可挑战时间
    GUILDBASE_CREATLEVELNEED=20,                                                //创建军团所需玩家最低等级
    GUILDBASE_BOSSFEEDOPENTIME=21,                                              //神兽喂养开启时间
    GUILDBASE_DATARESETTIME=22,                                                 //喂养榜，挑战榜，活力值清空时间
    GUILDBASE_GUILDFLAGCOLOUR=23,                                               //军团战旗颜色
    GUILDBASE_GUILDFLAGSTYLE=24,                                                //军团战旗样式
    GUILDBASE_GUILDFLAGBADGE=25,                                                //军团战旗徽章
    GUILDBASE_HALLLISTNUM=26,                                                   //军团大厅列表显示条数
    GUILDBASE_THEREVIEWNUM=27,                                                  //审核列表显示条数
    GUILDBASE_GUILDLOGLISTNUM=28,                                               //军团日志保存条数
    GUILDBASE_THEOTHERGUILDLISTNUM=29,                                          //其他军团列表显示条数
    GUILDBASE_ACTIVELISTNUM=30,                                                 //活跃军团列表显示条数
    GUILDBASE_NEWBUILDLISTNUM=31,                                               //新建军团列表显示条数
    GUILDBASE_NEWBUILDTIME=32,                                                  //定义新建帮派的时间
    GUILDBASE_ORIGINALPOSITIONLV=33,                                            //加入军团默认官职等级
    GUILDBASE_BOSSSCENEID=34,                                                   //军团神兽战斗场景
    GUILDBASE_CHALLENGESCENEID=35,                                              //军团副本战斗场景
    GUILDBASE_MAXAPPLYNUM=36,                                                   //可申请加入军团最大个数
    GUILDBASE_APPLYACTIVETIME=37,                                               //申请消息有效时间
    GUILDBASE_DONATEADDVALUE=38,                                                //1次捐献增加的军团活跃度（用于活跃军团推荐）
    GUILDBASE_FEEDADDVALUE=39,                                                  //1次喂养增加的军团活跃度（用于活跃军团推荐）
    GUILDBASE_EXTRAEXPLOITREBATEVALUE=40,                                       //根据活力值返还功勋的比例（用于喂养排名奖励）
    GUILDBASE_TRANSFERTIME=41,                                                  //自动转让团长时间（计算团长不在线时间）
    GUILDBASE_CHANGENAMECOST=42,                                                //改军团名消耗元宝
    GUILDBASE_GUILDAPPLYMAXNUM=43,                                              //军团申请最大上限
    GUILDBASE_GUILDNAMEMAXLENGTH=44,                                            //帮派名称字符最大长度
    GUILDBASE_REFRESHTIME=45,                                                   //推荐活跃军团刷新时间（单位秒）
    GUILDBASE_GUILDFLAGBADGECOLOUR=46,                                          //战旗徽章颜色
    GUILDBASE_KICKOUTMAXNUM=47,                                                 //每日最大踢人上限
    GUILDBASE_INACTIVETIME=48,                                                  //非活跃成员定义时间（天）
    GUILDBASE_KICKOUTPERCENT=49,                                                //踢出军团扣除军团行动力比例
    GUILDBASE_DONATEREFRESHTIME=50,                                             //军团捐献次数刷新时间
    GUILDBASE_DONATEOPENLV=51,                                                  //军团捐献开放等级
    GUILDBASE_CHALLENGEOPENLV=52,                                               //军团副本开放等级
    GUILDBASE_GUILDBATTLEOPENDAYS=53,                                           //军团战开启周数
    GUILDBASE_GUILDBATTLEOPENTIME=54,                                           //军团战开启时间
    GUILDBASE_GUILDBATTLEENDTIME=55,                                            //军团战结束时间
    GUILDBASE_GUILDBATTLEDEFEATEXPLOIT=56,                                      //战败战功
    GUILDBASE_GUILDBATTLEEND5KILLEXPLOIT=57,                                    //终结5连杀战功
    GUILDBASE_GUILDBATTLEEND10KILLEXPLOIT=58,                                   //终结10连杀战功
    GUILDBASE_GUILDBATTLEGATEDAMAGEEXPLOIT=59,                                  //对城门造成伤害战功比（废弃）
    GUILDBASE_GUILDBATTLEGATEBREAKEXPLOIT=60,                                   //攻破城门战功
    GUILDBASE_GUILDBATTLEPUTSHADOWEXPLOIT=61,                                   //放置分身战功
    GUILDBASE_GUILDBATTLESTOCKSCORE=62,                                         //粮仓产出积分
    GUILDBASE_GUILDBATTLESTABLESCORE=63,                                        //马厩产出积分
    GUILDBASE_GUILDBATTLEHALLSCORE=64,                                          //内府产出积分
    GUILDBASE_GUILDBATTLESCOREPERIOD=65,                                        //积分产出间隔秒数
    GUILDBASE_GUILDBATTLEREVIVEPRICE=66,                                        //复活价格
    GUILDBASE_GUILDBATTLESHADOWPRICE=67,                                        //分身价格
    GUILDBASE_GUILDBATTLEUNLOCKLEVEL=68,                                        //军团战开放等级
    GUILDBASE_GUILDBATTLEDIEDAMAGERATE=69,                                      //军团战自爆系数
    GUILDBASE_GUILDBATTLEJOINAWARD=70,                                          //军团战参与奖励
    GUILDBASE_GUILDBATTLECONQUERGATEAWARD=71,                                   //军团战破城奖励
    GUILDBASE_GUILDBATTLEFORECASTTIME=72,                                       //军团战预告时间
    GUILDBASE_GUILDBATTLEWINSCORE=73,                                           //内城战胜利积分
    GUILDBASE_GUILDOFFLINEDAY=74,                                               //军团长连续不在线时间（秒）
    GUILDBASE_ADJUTANTPRIORITYDAY=75,                                           //副团长优先申请时间（秒）
    GUILDBASE_ADJUTANTPRICE=76,                                                 //副团长接管军团消耗
    GUILDBASE_MEMBERPRICE=77,                                                   //团员接管军团消耗
    GUILDBASE_APPLYTIME=78,                                                     //开启申请时间
    GUILDBASE_ADJUTANTNUM=79,                                                   //军团中拥有的副团长数量
    GUILDBASE_GUILDBATTLESHADOWMAXNUM=81,                                       //幻影同时存在个数
    GUILDBASE_GUILDBATTLEPERSONALRANKRESOURCEID=82,                             //军团战个人排名奖励货币
    GUILDBASE_GUILDBATTLECOHORTSDAMAGERATE=83,                                  //军团战投石车伤害比例
    GUILDBASE_GUILDBATTLECOHORTSATTACKPACE=84,                                  //军团战投石车攻击间隔
    GUILDBASE_GUILDBATTLESTANDARDNUM=85,                                        //军团战基准人数（废弃）
    GUILDBASE_GUILDBATTLEINSIDEWARCOUNTDOWN=86,                                 //军团战内城战开启倒计时（秒）
    GUILDBASE_GUILDBATTLEJOINREQUIREDLEVEL=87,                                  //军团战军团等级需要
    GUILDBASE_GUILDBATTLEOPERATIONPACE=88,                                      //军团战操作频率限制
    GUILDBASE_GUILDBATTLEDEFEATCD=89,                                           //军团战复活CD
    GUILDBASE_GUILDBATTLELEAVECD=90,                                            //军团战离开城市CD
    GUILDBASE_GUILDBATTLELISTNUM=91,                                            //军团战玩家列表单次数量
    GUILDBASE_GUILDBATTLEGATEFIGHTPOSITION=92,                                  //军团战城门怪物阵位
    GUILDBASE_GUILDBATTLEGATEBACKGROUND=93,                                     //军团战外城战背景
    GUILDBASE_GUILDBATTLECITYBACKGROUND=94,                                     //军团战内城战背景
    GUILDBASE_GUILDBATTLEMINJOINNUM=95,                                         //军团战最小参战人数（废弃）
    GUILDBASE_GUILDBATTLEFIRSTDAYRATE=96,                                       //军团战首日血量倍率
    GUILDBASE_GUILDBATTLEFAMEITEMID=97,                                         //军团战功勋道具Id
    GUILDBASE_GUILDBATTLEREFRESHPACE=98,                                        //军团战城门战刷新按钮CD
    GUILDBASE_GUILDBATTLEDEFENDFAMEGETPACE=99,                                  //军团战城门战守方战功累计间隔（秒）
    GUILDBASE_GUILDBATTLEDEFENDFAMEGETVALUE=100,                                //军团战城门战守方战功累计值
    GUILDBASE_GUILDBATTLECONQUERCITYAWARDREFRESHTIME=101,                       //军团战占城奖励重置点
    GUILDBASE_GUILDBATTLERANKLISTNUM=102,                                       //军团战排行榜列表单次数量
    GUILDBASE_GUILDBATTLEEMPTYCITYLEVELADDITION=103,                            //军团战空城等级加成
    GUILDBASE_MEMBERTIME=104,                                                   //团员可申请时间（秒）
    GUILDBASE_GUILDBATTLESHADOWITEMID=105,                                      //军团战幻影道具
    GUILDBASE_GUILDBATTLERELIVEITEMID=106,                                      //军团战买活道具
    GUILDBASE_GUILDBATTLEFAMEMAX=107,                                           //军团战单次获得战功最大值
    GUILDBASE_GUILDDUNGEONRESETDAY=108,                                         //军团副本重置时间（每周第几天）
    GUILDBASE_GUILDDUNGEONRESETTIME=109,                                        //军团副本重置时间（当天具体秒数）
    GUILDBASE_GUILDDUNGEONSTARTTIME=110,                                        //军团副本每天开启时间
    GUILDBASE_GUILDDUNGEONENDTIME=111,                                          //军团副本每天结束时间
    GUILDBASE_GUILDDUNGEONDAILYSPOTTIMES=112,                                   //军团副本每日挑战据点有效次数
    GUILDBASE_GUILDDUNGEONDAILYBOSSTIMES=113,                                   //军团副本每日挑战Boss机会
    GUILDBASE_GUILDDUNGEONAUTOSTARTDAY=114,                                     //军团副本自动开启时间（每周第几天）
    GUILDBASE_GUILDDUNGEONAUTOSTARTTIME=115,                                    //军团副本自动开启时间（当天具体秒数）
    GUILDBASE_GUILDDUNGEONCHALLENGERESETTIME=116,                               //军团副本每日挑战次数重置时间
    GUILDBASE_GUILDBATTLEQUITCD=117,                                            //军团战退团CD（天）
    GUILDBASE_GUILDBATTLEINSIDEHONORPACE=118,                                   //军团战内城战产出积分间隔（秒）
    GUILDBASE_GUILDDUNGEONRESETCHANGEGETTIMEHOUR=119,                           //军团副本重置次数获得时间（天）
    GUILDBASE_GUILDDUNGEONRESETCHANGEGETTIMESECOND=120,                         //军团副本重置次数获得时间（当天秒数）
    GUILDBASE_GUILDDUNGEONRESETCHANGEMAXNUM=121,                                //军团副本重置次数最大值
    GUILDBASE_GUILDDUNGEONQUITCD=122,                                           //军团副本退团CD（天）
    GUILDBASE_GUILDDUNGEONLASTBLOODAWARD=123,                                   //军团副本击杀奖励
    GUILDBASE_GUILDDUNGEONWINAWARD=124,                                         //军团副本全团击杀奖励
    GUILDBASE_GUILDDUNGEONFAILAWARD=125,                                        //军团副本失败安慰奖
};
enum {
    TASKTYPE_STARCARBON=1,                                                      //【S1】/【X2】星通过关卡【X1】
    TASKTYPE_STARCHAPTER=2,                                                     //【S1】/【X2】星通过章节【X1】
    TASKTYPE_CARBONTIMES=3,                                                     //挑战【X1】关卡【S1】/【X3】次
    TASKTYPE_ARENATIMES=4,                                                      //挑战竞技场【S1】/【X3】次
    TASKTYPE_TRIALTIMES=5,                                                      //挑战试练【S1】/【X3】次
    TASKTYPE_SWEEPCARBON=6,                                                     //扫荡【X1】副本【S1】/【X3】次
    TASKTYPE_GETCHAPTERBOX=7,                                                   //领取【X1】章节的第【X2】个宝箱
    TASKTYPE_CARBONANYTIMES=8,                                                  //挑战任意副本【S1】/【X3】次
    TASKTYPE_HEROLEVELUP=9,                                                     //将武将【X1】提升至【S1】/【X2】级
    TASKTYPE_HEROGRADEUP=10,                                                    //将武将【X1】突破至【S1】/【X2】级
    TASKTYPE_MOUNTLEVELUP=11,                                                   //将坐骑提升至【S1】/【X2】阶
    TASKTYPE_HAVELEVELHERO=12,                                                  //拥有【S1】/【X3】个【X2】级武将
    TASKTYPE_HAVEGRADEHERO=13,                                                  //拥有【S1】/【X3】个【X2】阶武将
    TASKTYPE_HAVESTARHERO=14,                                                   //拥有【S1】/【X3】个【X2】星武将
    TASKTYPE_HAVEPOWERHERO=15,                                                  //拥有【S1】/【X3】个【X2】战力武将
    TASKTYPE_HEROEQUIPUP=16,                                                    //将【X1】武将的【X2】装备强化至【S1】/【X3】
    TASKTYPE_HEROEQUIPFORGE=17,                                                 //将【X1】武将的【X2】装备打造至【S1】/【X3】
    TASKTYPE_RECRUITHERO=18,                                                    //抽取武将【S1】/【X3】个
    TASKTYPE_EQUIPUP=19,                                                        //强化装备【S1】/【X3】次
    TASKTYPE_EQUIPFORGE=20,                                                     //打造装备【S1】/【X3】次
    TASKTYPE_EQUIPQUENCH=21,                                                    //淬火装备【S1】/【X3】次
    TASKTYPE_SKILLUP=22,                                                        //将【X1】位置技能提升至【S1】/【X2】级
    TASKTYPE_FORMUP=23,                                                         //将【S1】/【X3】个武将布置上阵
    TASKTYPE_FEEDMOUNT=24,                                                      //将坐骑升至【S1】/【X2】星
    TASKTYPE_INSERTGEM=25,                                                      //镶嵌【S1】/【X3】次宝石
    TASKTYPE_MOUNTUPEQUIP=26,                                                   //穿戴【S1】/【X3】件坐骑装备
    TASKTYPE_UPGEM=27,                                                          //合成宝石【S1】/【X3】次
    TASKTYPE_MOUNTEQUIPUP=28,                                                   //合成坐骑装备【S1】/【X3】次
    TASKTYPE_HAVELEVELEQUIP=29,                                                 //拥有【S1】/【X3】件【X1】强化等级的【X2】装备
    TASKTYPE_HAVEFORGEEQUIP=30,                                                 //拥有【S1】/【X3】件【X1】打造等级的【X2】装备
    TASKTYPE_HAVECURRENCY=31,                                                   //获得【X2】货币【S1】/【X3】数量
    TASKTYPE_HAVEITEM=32,                                                       //获得【X2】道具【S1】/【X3】数量
    TASKTYPE_CAMPTHROUGH=33,                                                    //阵容闯关【S1】/【X3】次
    TASKTYPE_CAMPTURN=34,                                                       //阵营转盘【S1】/【X3】次
    TASKTYPE_CAMPGRAIN=35,                                                      //阵营运镖【S1】/【X3】次
    TASKTYPE_CAMPGRAINROB=36,                                                   //阵营劫镖【S1】/【X3】次
    TASKTYPE_CAMPMINE=37,                                                       //阵营抢矿【S1】/【X3】次
    TASKTYPE_CAMPFIGHT=38,                                                      //阵营战【S1】/【X3】次
    TASKTYPE_JOINCAMP=39,                                                       //加入一个阵营
    TASKTYPE_GUILDFEEDBOSS=40,                                                  //喂养军团BOS1S1【S1】/【X3】次
    TASKTYPE_GUILDBOSSFIGHT=41,                                                 //挑战军团BOS1S1【S1】/【X3】次
    TASKTYPE_GUILDCARBON=42,                                                    //挑战军团副本【S1】/【X3】次
    TASKTYPE_GUILDDONATE=43,                                                    //完成军团捐献【S1】/【X3】次
    TASKTYPE_GUILDFLAG=44,                                                      //将军团战旗提升至【S1】/【X3】级
    TASKTYPE_CREATEJOINGUILD=45,                                                //加入或创建一个公会
    TASKTYPE_RECYCLEHERO=46,                                                    //炼化【S1】/【X3】个武将
    TASKTYPE_RECYCLEITEM=47,                                                    //炼化【S1】/【X3】个道具
    TASKTYPE_PASSCARBON=48,                                                     //通过【X1】章节的关卡【X2】
    TASKTYPE_ROLELEVELUP=49,                                                    //将主角提升至【S1】/【X2】级
    TASKTYPE_ROLEGRADEUP=50,                                                    //将主角突破至【S1】/【X2】阶
    TASKTYPE_ROLEEQUIPUP=51,                                                    //将主角的【X2】装备强化至【S1】/【X3】
    TASKTYPE_ROLEEQUIPFORGE=52,                                                 //将主角的【X2】装备打造至【S1】/【X3】
    TASKTYPE_CRUSADE=53,                                                        //进行【S1】/【X3】次[X1]活动副本
    TASKTYPE_NOMONTHCARD=54,                                                    //未拥有月卡时的提示，每天可以领取【X3】元宝
    TASKTYPE_MONTHCARD=55,                                                      //月卡，剩余天数【S1】，每天可以领取【X3】元宝
    TASKTYPE_NOLIFETIMECARD=56,                                                 //未拥有终生卡时的提示，每天可以领取【X3】元宝
    TASKTYPE_LIFETIMECARD=57,                                                   //终生卡，每天可以领取【X3】元宝
    TASKTYPE_TEAMSWORDS=58,                                                     //团队战斗力达到【X3】
    TASKTYPE_PEERLESSTIMES=59,                                                  //挑战无双【S1】/【X3】次
    TASKTYPE_QUESTION=60,                                                       //进行【S1】/【X3】次问答游戏
    TASKTYPE_TOWER=61,                                                          //扫荡【S1】/【X3】次天梯
};
enum {
    CHANNELBASE_WORLD=1,                                                        //世界频道
    CHANNELBASE_PRIVATE=2,                                                      //私聊频道
    CHANNELBASE_GUILD=3,                                                        //军团频道
    CHANNELBASE_SYSTEM=4,                                                       //系统频道
    CHANNELBASE_NOTICE=5,                                                       //系统广播
    CHANNELBASE_MAINTAIN=6,                                                     //维护公告
    CHANNELBASE_CAMP=7,                                                         //阵营频道
};
enum {
    CHATBASE_CHATMAXWORD=1,                                                     //聊天内容的最大存储字符数量
    CHATBASE_WORLDCHANNELMAXBAR=2,                                              //世界频道可查看的最大聊天条目
    CHATBASE_PTECHANNELMAXBAR=3,                                                //私聊的最大存储聊天记录条目
    CHATBASE_PTECHANNELSAVETIME=4,                                              //私聊删除时间
    CHATBASE_GUILDCHANNELMAXBAR=5,                                              //军团频道可查看的最大聊天条目
    CHATBASE_CHATTALKLEVEL=6,                                                   //可聊天等级
    CHATBASE_WORLDCHANNELFREETALK=7,                                            //每日免费聊天次数
    CHATBASE_WORLDCHANNELTALKPAY=8,                                             //聊天花费【货币,数量】
    CHATBASE_SYSCHANNELSTAYTIME=9,                                              //系统发送的系统消息在主界面停留的时间
    CHATBASE_NOTICETIME=10,                                                     //公告间隔
    CHATBASE_SYSCHANNELTIME=11,                                                 //玩家行为系统消息在主界面停留的时间
    CHATBASE_EQUIPSTAR=12,                                                      //装备打造等级达到20级或20级以上播放公告【极限值不生效】
    CHATBASE_HEROQUALITY=13,                                                    //完美武将
    CHATBASE_HEROGIFTLV=14,                                                     //突破到10级或10级以上【极限值不生效】
    CHATBASE_GEMLV=15,                                                          //宝石合成在5级或5级以上
    CHATBASE_ARENARANK=16,                                                      //打败竞技场前3名播报公告
    CHATBASE_MOUNTSSTAR=17,                                                     //喂养到5星或5星以上坐骑
    CHATBASE_MOUNTSEQUIPLV=18,                                                  //坐骑装备合成到5级或5级以上【极限值不生效】
    CHATBASE_CAMPCHANNELFREETALK=19,                                            //阵营每日免费聊天次数
    CHATBASE_CAMPCHANNELTALKPAY=20,                                             //阵营聊天花费【货币,数量】
    CHATBASE_GUILDCHANNELSAVETIME=21,                                           //军团私聊删除时间
    CHATBASE_CHATTALKTIMEWORLD=22,                                              //连续聊天间隔世界
    CHATBASE_CHATTALKTIMEPTE=23,                                                //连续聊天间隔私聊
    CHATBASE_CHATTALKTIMEGUILD=24,                                              //连续聊天间隔军团
    CHATBASE_CHATTALKTIMECAMP=25,                                               //连续聊天间隔阵营
};
enum {
    TRIALBASE_OPENLIMIT=1,                                                      //武将试炼副本系统开启等级
    TRIALBASE_RESURRECTIONNUM=2,                                                //武将试炼每天复活次数
    TRIALBASE_RESETTIME=3,                                                      //武将试炼系统重置时间
    TRIALBASE_RESETTIMES=4,                                                     //武将试炼免费重置次数
    TRIALBASE_CHALLENGESTAMINA=5,                                               //武将试炼挑战消耗耐力
    TRIALBASE_CHALLENGEGOLD=6,                                                  //武将试炼重置消耗元宝数量
    TRIALBASE_CHALLENGEFIGHTNUM=7,                                              //每个进度下战斗节点数
    TRIALBASE_FIGHTSCENE=8,                                                     //武将试炼战斗场景ID
    TRIALBASE_TRAILSCENE=9,                                                     //武将试炼场景ID
    TRIALBASE_TRAILHEROMINLEVEL=10,                                             //武将试炼能够上阵武将的最低等级
    TRIALBASE_LOSEREWARD=11,                                                    //试练失败奖励阅历
    TRIALBASE_TRAILMATCHINGLEVEL=12,                                            //试炼数据录入等级
    TRIALBASE_TRAILMATCHINGDOWNLEVEL=13,                                        //试炼向下匹配等级
    TRIALBASE_TRAILMATCHINGUPLEVEL=14,                                          //试炼向上匹配等级
    TRIALBASE_TRAILMATCHINGEVERYLEVELNUM=15,                                    //每个等级匹配数量
    TRIALBASE_TRAILMATCHFIRSTLEVELMAX=16,                                       //第一波匹配最大等级差
    TRIALBASE_TRAILMATCHFIRSTLEVELMIN=17,                                       //第一波匹配最小等级差
    TRIALBASE_TRAILMATCHSECONDLEVELMAX=18,                                      //第二波匹配最大等级差
    TRIALBASE_TRAILMATCHSECONDLEVELMIN=19,                                      //第二波匹配最小等级差
    TRIALBASE_TRAILMATCHTHIRDLEVELMAX=20,                                       //第三波匹配最大等级差
    TRIALBASE_TRAILMATCHTHIRDLEVELMIN=21,                                       //第三波匹配最小等级差
    TRIALBASE_TRAILFIGHTMAXNUM=22,                                              //试炼最大战斗波数
    TRIALBASE_TRAILFIGHTWINDROPBOXID=23,                                        //试炼战斗胜利奖励包
    TRIALBASE_TRAILFIGHTLOSEDROPBOXID=24,                                       //试炼战斗失败奖励包
    TRIALBASE_RESETBASETIMES=25,                                                //试炼基础重置次数
};
enum {
    ROLENAMEBASE_ROLENAMEMINLENGTH=1,                                           //昵称字符最小长度
    ROLENAMEBASE_ROLENAMEMAXLENGTH=2,                                           //昵称字符最大长度
    ROLENAMEBASE_MALEINIPOSITION=3,                                             //男主初始位置
    ROLENAMEBASE_FEMALEINIPOSITION=4,                                           //女主初始位置
    ROLENAMEBASE_SELECTEDPOSITION=5,                                            //选中角色位置
    ROLENAMEBASE_CHANGENAMEDIAMOND=6,                                           //改名花费
    ROLENAMEBASE_FIRSTCHANGENAMELEVEL=7,                                        //首次改名等级
};
enum {
    CHATNOTICE_MOUNTLVUP=1,                                                     //坐骑升星，当玩家的坐骑升到4星之后每次升星时系统会播放公告--好马易得，伯乐难寻！恭喜慧眼识马的【玩家名】将坐骑升到了【N】星！【空】【空】
    CHATNOTICE_CHAPTERUNLOCK=2,                                                 //每当玩家解锁一个新幕时播放公告--经过【玩家名】的不懈努力，终于解锁了第【N】幕关卡。新的征程由此展开！【空】【空】
    CHATNOTICE_TRIALCLEAR=3,                                                    //当玩家完成试炼挑战后播放公告--哎呦不得了！听说【玩家名】一路过关斩将，勇不可挡，将试炼塔掀了个底朝天！【空】【空】【空】
    CHATNOTICE_FINALHIT=4,                                                      //军团boss被公会成员击杀--兄弟齐心，其利断金！【军团名】军团众志成城，合力推倒了军团神兽：赤焰凤凰！【空】【空】【空】
    CHATNOTICE_HEROBREAK=5,                                                     //玩家完美武将突破到+2或以上会播放公告--三国快报~【玩家名】战力爆表，将麾下大将【武将名】突破至+【N】！【空】
    CHATNOTICE_EQUIPFORGE=6,                                                    //装备+4后系统公告装备提升--三国快报~【玩家名】鬼斧神工，大锤一挥将【武器名】打造至+【N】！【空】
    CHATNOTICE_GEMCOMPOUND=7,                                                   //宝石合成到5级之后发公告--三国快报~【玩家名】一掷千金，得到了【宝石名】，真是羡煞旁人！【空】【空】
    CHATNOTICE_ARENARANK=8,                                                     //竞技场前3名名次变化--【玩家名】击败了竞技场第【名次】名，谁来挑战他【空】【空】
    CHATNOTICE_MOUNTSEQUIP=9,                                                   //三国快报~【玩家名】一番苦功后，获得了【坐骑装备名】，从此如虎添翼！【空】【空】
    CHATNOTICE_GUILDBOSSOPENCHAR=10,                                            //军团快报~神兽已经觉醒了，极品装备一点就爆啊，大家快去进攻吧！【是否前往按钮】【空】【空】
    CHATNOTICE_GUILDCHAPTEROPENCHAR=11,                                         //军团快报~ 团长 【团长名称】 开放了【副本名称】，同志们快去刷吧！【是否前往按钮】【空】
    CHATNOTICE_GUILDNOTICECHANGECHAR=12,                                        //新公告：{0}{1}{2}{3}
    CHATNOTICE_CAMPOFFICEONLINECHAT=13,                                         //阵营-【阵营】 帝王【玩家名称】 上线啦！掌声在哪里，鲜花在哪里？一大波“生孩子”党在哪里~~【空】【空】
    CHATNOTICE_GUILDBATTLEALARM=14,                                             //军团战即将在{0}分钟后开启，请大家做好准备！~~【空】【空】【空】
    CHATNOTICE_GUILDBATTLESTART=15,                                             //军团战已经开启，冲锋吧弟兄们！~~【空】【空】【空】【空】
    CHATNOTICE_GUILDBATTLEKILL=16,                                              //【玩家名称】刚刚在军团战完成了{数字}连杀，在千军里取人首级如探囊取物！【空】【空】
    CHATNOTICE_GUILDBATTLEENDKILL=17,                                           //【玩家名称】在军团战终结了{玩家名称}的{数字}连杀！【空】
    CHATNOTICE_GUILDBATTLECITYBREAK=18,                                         //【玩家名称】在军团战攻破了{城池名称}的城门，启动了内城战【空】【空】
    CHATNOTICE_GUILDBATTLEWIN=19,                                               //【军团名称】军团在军团战大获全胜，占领了{城池名称},获得占城奖励【空】【空】
    CHATNOTICE_GUILDBATTLEEND=20,                                               //本次军团战已结束，军团排名奖励已经发送到各军团的仓库，其余奖励已通过邮件发放【空】【空】【空】【空】
    CHATNOTICE_GUILDBATTLECITYAUTOBREAK=21,                                     //【城池名称】的城门已被攻破，启动了内城战！【空】【空】【空】
    CHATNOTICE_GUILDBATTLESTOREALLOT=22,                                        //团长【玩家名称】将【数量】个【道具名】分配给了团员【玩家名称】！
    CHATNOTICE_GUILDDUNGEONSTART=23,                                            //军团中的南华仙人洞已经开启，主公们快组队探索吧！
    CHATNOTICE_GUILDDUNGEONBOSSOPEN=24,                                         //来自远古的魔物出现在军团里的南华仙人洞！
    CHATNOTICE_GUILDDUNGEONBOSSEND=25,                                          //南华仙人洞中的魔物已被击杀，奖励将通过邮件发放！
};
enum {
    ALLRANK_TEAMCOMBAT=1,                                                       //大标题：战斗力 小标题：小队战力 实时显示，无需数据重置
    ALLRANK_LORDCOMBAT=2,                                                       //大标题：战斗力 小标题：主公战力 实时显示，无需数据重置
    ALLRANK_FBSTAR=3,                                                           //大标题：副本 小标题：副本星级 实时显示，无需数据重置
    ALLRANK_TRIALNUM=4,                                                         //大标题：试练塔 小标题：爬塔层数 实时显示，同试炼开放时间
    ALLRANK_FINALS=5,                                                           //大标题：竞技场 小标题：典将赛区 实时显示，无需数据重置
    ALLRANK_SEMIFINALS1=6,                                                      //大标题：竞技场 小标题：青龙赛区 实时显示，无需数据重置
    ALLRANK_SEMIFINALS2=7,                                                      //大标题：竞技场 小标题：白虎赛区 实时显示，无需数据重置
    ALLRANK_SEMIFINALS3=8,                                                      //大标题：竞技场 小标题：玄武赛区 实时显示，无需数据重置
    ALLRANK_SEMIFINALS4=9,                                                      //大标题：竞技场 小标题：朱雀赛区 实时显示，无需数据重置
    ALLRANK_GUILD=10,                                                           //大标题：军团 小标题：公会排行 实时显示，无需数据重置
    ALLRANK_CAMPMINE=11,                                                        //大标题：阵容 小标题：矿山争霸 显示上次开放该系统时的列表，模块开放时重置
    ALLRANK_CAMPGRAIN=12,                                                       //大标题：阵容 小标题：木牛流马 显示上次开放该系统时的列表，模块开放时重置
    ALLRANK_CAMPFIGHT=13,                                                       //大标题：阵容 小标题：阵营战 显示上次开放该系统时的列表，模块开放时重置
    ALLRANK_RECRUIT=14,                                                         //大标题：招募 小标题：名将榜 实时显示，无需数据重置
};
enum {
    GUILDLOG_JOIN=1,                                                            //[b][4F392C]加入了军团！[-]
    GUILDLOG_EXIT=2,                                                            //[b][4F392C]退出了军团！[-]
    GUILDLOG_COINDONATE=3,                                                      //[b][4F392C]捐献了[ffffff]{0}[-]铜币！[-]
    GUILDLOG_GOLDDONATE=4,                                                      //[b][4F392C]捐献了[ffffff]{0}[-]元宝！[-]
    GUILDLOG_POSITIONUP=5,                                                      //[b][4F392C]因功勋卓越，官职提升至[ffffff]{0}[-]！[-]
    GUILDLOG_GUILDLVUP=6,                                                       //[b][4F392C]军团升至[ffffff]{0}[-]级！[-]
    GUILDLOG_GUILDFLAGUP=7,                                                     //[b][4F392C]军团战旗提升至[ffffff]{0}[-]级！[-]
    GUILDLOG_EXPADD=8,                                                          //[b][4F392C]击杀神兽，为军团增加[ffffff]{0}[-]经验！[-]
    GUILDLOG_FUNDADD=9,                                                         //[b][4F392C]击杀神兽，为增加军团[ffffff]{0}[-]行动力！[-]
    GUILDLOG_HEADCHANGE=10,                                                     //[b][4F392C]成为了新任团长！[-]
    GUILDLOG_CHAPTERGETITEM=11,                                                 //[b][4F392C]在[ffffff]{0}[-]中获得了[ffffff]{1}[-]*[ffffff]{2}[-]！[-]
    GUILDLOG_BOSSGETITEM=12,                                                    //[b][4F392C]挑战神兽获得了[ffffff]{0}[-]*[ffffff]{1}[-]！[-]
    GUILDLOG_KILLBOSSPLAYER=13,                                                 //[b][4F392C]击杀神兽，获得了神秘宝箱！[-]
    GUILDLOG_KICKOUT=14,                                                        //[b][4F392C]被团长踢出了军团！[-]
    GUILDLOG_DEVIDEITEM=15,                                                     //军团长将{0}个{1}分配给了{2}！[-]
};
enum {
    ACTIVITYBASE_ACTIVITY1OPENLIMIT=1,                                          //战役（资源）副本开放等级
    ACTIVITYBASE_ACTIVITY2OPENLIMIT=2,                                          //讨伐（材料）副本开放等级
    ACTIVITYBASE_ACTIVITYBATTLE=3,                                              //战役（资源）副本类型编号
    ACTIVITYBASE_ACTIVITYCRUSADE=4,                                             //讨伐（材料）副本类型编号
    ACTIVITYBASE_LEVELREWARDVALID=5,                                            //等级礼包可领取倒计时天数
    ACTIVITYBASE_DAILYSUMPAYREWARDVALID=6,                                      //每日累充礼包可领取天数
    ACTIVITYBASE_ACTIVITY1REFRESHTIME=7,                                        //战役次数重置
    ACTIVITYBASE_ACTIVITY2REFRESHTIME=8,                                        //讨伐次数重置
    ACTIVITYBASE_RESETTIME=9,                                                   //兑换状态重置时间
};
enum {
    COSTBASE_GOLD=1,                                                            //游戏中的增值货币，充值获得，用于购买道具和其他付费行为
    COSTBASE_SILVER=2,                                                          //游戏中的基础货币，用于游戏中的基础消耗
    COSTBASE_AP=3,                                                              //游戏中进行PVE行为需要消耗的货币
    COSTBASE_STAMINA=4,                                                         //游戏中进行PVP行为需要消耗的货币
    COSTBASE_EXPLOIT=5,                                                         //玩家参加试炼获得的奖励货币，用于试炼商店的道具兑换
    COSTBASE_HONOUR=6,                                                          //玩家参加竞技场获得的奖励货币，用于竞技场商店的道具兑换
    COSTBASE_EXP=7,                                                             //玩家在游戏中获得的数值，用于提升角色等级
    COSTBASE_JADE=8,                                                            //玩家在游戏中回收道具后获得的货币，用于神秘商店的道具兑换
    COSTBASE_FODDER=9,                                                          //玩家在进化坐骑时使用的基本道具
    COSTBASE_SOUL=10,                                                           //玩家用户给武将提升等级的的资源
    COSTBASE_GUOGONG=11,                                                        //玩家参加阵营活动获得的奖励货币，用于阵营商店的道具兑换
    COSTBASE_BANGGONG=12,                                                       //玩家参加军团活动获得的奖励货币，用于军团商店的道具兑换
    COSTBASE_VIPEXP=13,                                                         //Vip经验用来提升vip等级
    COSTBASE_GENERALEXPERIENCE=14,                                              //副本通关给予武将的经验值
    COSTBASE_PEERLESS=15,                                                       //无双演武场产出货币，用于无双演武场商店购买道具
    COSTBASE_EXPMONEY=16,                                                       //用于经验阁的道具
    COSTBASE_ARTIFACTLUCK=17,                                                   //神兵十连抽积攒用以兑换超级神兵的货币
};
enum {
    TOOLRESULT_DUALPVE=1,                                                       //普通出征双倍
    TOOLRESULT_DUALARENA=2,                                                     //擂台道具双倍
    TOOLRESULT_DUALTRIALS=3,                                                    //试炼道具双倍
    TOOLRESULT_DUALLEAGUEBOSS=4,                                                //军团神兽道具双倍
    TOOLRESULT_DUALLEAGUECARBON=5,                                              //军团副本道具双倍
    TOOLRESULT_DUALCAMPWAR=6,                                                   //阵营战道具双倍
    TOOLRESULT_DUALCAMPGRAIN=7,                                                 //木牛流马道具双倍
    TOOLRESULT_DUALCAMPMINE=8,                                                  //矿山争霸道具掉落
    TOOLRESULT_DUALACTIVITY=9,                                                  //讨伐材料双倍
    TOOLRESULT_DUALACTIVITYBATTLE=10,                                           //战役资源双倍
    TOOLRESULT_DUALELITEPVE=14,                                                 //精英出征双倍
    TOOLRESULT_DAILYLOGIN=101,                                                  //累计登陆奖励
    TOOLRESULT_ADDPAY=201,                                                      //累计充值返利
    TOOLRESULT_PAYREBATE=301,                                                   //充值返利
    TOOLRESULT_ADDCOST=401,                                                     //累计消耗活动
    TOOLRESULT_DAILYADDCOST=501,                                                //每日累计消耗活动
    TOOLRESULT_DAILYADDPAY=601,                                                 //每日累计充值活动
    TOOLRESULT_DUALTRIALSREWARD=1001,                                           //擂台奖励双倍
    TOOLRESULT_DUALCAMPGRAINREWARD=2001,                                        //木牛流马奖励双倍
    TOOLRESULT_DUALCAMPMINEREWARD=3001,                                         //矿山争霸奖励双倍
    TOOLRESULT_EDITEVENT=4001,                                                  //可编辑类型活动
    TOOLRESULT_ADDRECRUIT=5001,                                                 //累计招募
    TOOLRESULT_LOTTERY=6001,                                                    //聚宝盆
    TOOLRESULT_ACTIVERECRUIT=7001,                                              //名将阁
    TOOLRESULT_NEWYEARACTIVITY=8001,                                            //新年活动
    TOOLRESULT_LUCKYTURNTABLE=9001,                                             //幸运大转盘
    TOOLRESULT_NEWLUCKYTURNTABLE=10001,                                         //新幸运大转盘
    TOOLRESULT_ADDARTIFACT=20001,                                               //神兵招募
    TOOLRESULT_ARTIFACTRANK=30001,                                              //神兵排行
};
enum {
    PUSHMESSAGES_SPIRITMAX=1,                                                   //主公大人体力爆满啦！快和貂蝉妹妹一起私奔到三国里大展雄威吧~人家，人家等不及了啦~
    PUSHMESSAGES_STAMINAMAX=2,                                                  //主公大人耐力爆满啦！小伙伴们摩拳擦掌，战意昂扬，就等你回来一声令下！~
    PUSHMESSAGES_AMGETSPIRIT=3,                                                 //嗯？哪里飘来的香味？原来是吃烤肉领体力的时间到啦！赶紧来尝尝，凉了就不好吃啦~
    PUSHMESSAGES_PMGETSPIRIT=4,                                                 //嗯？哪里飘来的香味？原来是吃烤肉领体力的时间到啦！赶紧来尝尝，凉了就不好吃啦~
    PUSHMESSAGES_GUILDCHAPTEROPEN=5,                                            //飞鸽传书：军团长开启了军团副本，海量宝物唾手可得！是时候向小伙伴们展现你的实力了！
    PUSHMESSAGES_CHARPRIVATELY=6,                                               //【来自《私奔到三国》的私聊】
    PUSHMESSAGES_ARENACHANGE=7,                                                 //距离擂台排名结算时间只剩10分钟了！我知道，你等的就是这一刻。（坏笑）
    PUSHMESSAGES_GUILDNOTICE=8,                                                 //军团长大人今日兴致大发，更改了军团公告！
    PUSHMESSAGES_CAMPOPEN=9,                                                    //一日之计在于晨。丰富多彩的阵营活动已开启，主公快快去为自己阵营的发展贡献一份力量吧！
    PUSHMESSAGES_RECALL48=10,                                                   //主公大人！不要放弃山河大业啊！
    PUSHMESSAGES_RECALL72=11,                                                   //主公大人！貂蝉妹妹好想你啊...…QAQ
    PUSHMESSAGES_RECALL168=12,                                                  //主公大人……貂蝉妹妹会一直等你回来的……
    PUSHMESSAGES_AMFGETSPIRIT=13,                                               //主公！再不吃烤肉都快凉了！
    PUSHMESSAGES_PMFGETSPIRIT=14,                                               //主公！再不吃烤肉都快凉了！
    PUSHMESSAGES_GUILDBATTLEALARM=15,                                           //新一轮的军团战要开战了，主公大人的队友都在等你噢！
};
enum {
    GUILDBATTLECHAT_GUILDBATTLECHALLENGEWIN=1,                                  //您击败了【玩家名】，剩余【N】%血量。    +【N】战功图标【空】
    GUILDBATTLECHAT_GUILDBATTLECHALLENGEWINBEKILLED=2,                          //您击败了【玩家名】，但是主角阵亡，进入复活时间。    +【N】战功图标【空】【空】
    GUILDBATTLECHAT_GUILDBATTLECHALLENGEFAIL=3,                                 //您挑战【玩家名】失败，进入复活时间。    +【N】战功图标【空】【空】
    GUILDBATTLECHAT_GUILDBATTLEWIN=4,                                           //您击退了【玩家名】的攻击，剩余【N】%血量。    +【N】战功图标【空】
    GUILDBATTLECHAT_GUILDBATTLEWINBEKILLED=5,                                   //您击退了【玩家名】的攻击，但是主角阵亡，进入复活时间。    +【N】战功图标【空】【空】
    GUILDBATTLECHAT_GUILDBATTLEDEFEAT=6,                                        //您被【玩家名】击败，进入复活时间。    +【N】战功图标【空】【空】
    GUILDBATTLECHAT_GUILDBATTLEGATEBREAK=7,                                     //军团【军团名】攻破了【城池名】的城门，开启了内城战。【空】【空】
    GUILDBATTLECHAT_GUILDBATTLEEND=8,                                           //军团【军团名】攻占了【城池名】。【空】【空】
    GUILDBATTLECHAT_GUILDBATTLEGATEAUTOBREAK=9,                                 //【城池名】的城门已被攻破，开启了内城战。【空】【空】【空】
    GUILDBATTLECHAT_GUILDBATTLEATTACKGATE=10,                                   //您猛拍城门被保安抬了下去，造成了【N】伤害，并进入复活时间。【空】【空】【空】
    GUILDBATTLECHAT_GUILDBATTLECHALLENGESHADOWWIN=11,                           //您击败了【玩家名】的幻影，剩余【N】%血量。    +【N】战功图标【空】
    GUILDBATTLECHAT_GUILDBATTLECHALLENGESHADOWWINBEKILLED=12,                   //您击败了【玩家名】的幻影，但是主角阵亡，进入复活时间。    +【N】战功图标【空】【空】
    GUILDBATTLECHAT_GUILDBATTLECHALLENGESHADOWFAIL=13,                          //您挑战【玩家名】的幻影失败，进入复活时间。    +【N】战功图标【空】【空】
};
enum {
    SPEBASE_OPENLV=1,                                                           //开放等级
    SPEBASE_REFSPIRIT=2,                                                        //刷新体力
    SPEBASE_PRIVIP=3,                                                           //VIP特权等级
    SPEBASE_PAYREF=4,                                                           //付费次数刷新次数
    SPEBASE_STAYTIME=5,                                                         //停留时间
};
enum {
    LOTTERYBASE_TALKTIME=1,                                                     //吐槽间隔时间
    LOTTERYBASE_ROLLTIME=2,                                                     //玩家滚动间隔
    LOTTERYBASE_CATCHNUM=3,                                                     //提取最高奖励玩家数量
};
enum {
    PEAKARENABASE_CHALLENGESTAMINA=1,                                           //挑战消耗耐力
    PEAKARENABASE_UPLOCKLEVEL=2,                                                //竞技场解锁等级
    PEAKARENABASE_PEAKARENAREPORTNUM=3,                                         //保存战报数量
    PEAKARENABASE_PEAKARENAWARSCENE=4,                                          //竞技场战斗场景
    PEAKARENABASE_PEAKARENAWARSCENEID=5,                                        //竞技场战斗场景
    PEAKARENABASE_DOWNMATCHINGNUM=6,                                            //向下匹配数量
    PEAKARENABASE_UPMATCHINGNUM=7,                                              //向上匹配数量
    PEAKARENABASE_SUBUPMATCHINGNUM=8,                                           //大幅向上匹配数量
    PEAKARENABASE_REPORTPRESERVETIME=9,                                         //战报保存最长时间
    PEAKARENABASE_MAXRANK=10,                                                   //超过这个名次按照下面两条规则取目标
    PEAKARENABASE_MATCHRANK=11,                                                 //一定排名外（1000名）取敌人排名区间
    PEAKARENABASE_PEAKARENA1=12,                                                //3v3对决
    PEAKARENABASE_PEAKARENA2=13,                                                //5v5对决
    PEAKARENABASE_PEAKARENA3=14,                                                //1v1对决
    PEAKARENABASE_PEAKARENANAME11=15,                                           //典将赛区
    PEAKARENABASE_PEAKARENANAME12=16,                                           //精英赛区
    PEAKARENABASE_PEAKARENANAME13=17,                                           //普通赛区
    PEAKARENABASE_MAXPECKICON=18,                                               //存储巅峰币上限
    PEAKARENABASE_PROMOTION=19,                                                 //每日可最大晋级次数
    PEAKARENABASE_ADDPEOPLE=20,                                                 //赛区可加人（流水ID）
    PEAKARENABASE_CLEARINGTIME=21,                                              //结算时间点（秒）
    PEAKARENABASE_NUMBER=22,                                                    //单页显示数量
    PEAKARENABASE_SUBNUMBER=23,                                                 //最大显示个数
    PEAKARENABASE_RESETTIME=24,                                                 //晋级挑战次数重置时间点
    PEAKARENABASE_PEERLESS=25,                                                  //无双币
    PEAKARENABASE_MAXIMUM=26,                                                   //最大可获得名次
    PEAKARENABASE_TRIGGERVALUE=27,                                              //无双币达到数值，按纽增加红点
    PEAKARENABASE_CHARACTERLIMIT=28,                                            //宣言最大字符数
    PEAKARENABASE_DEFAULTPOSITION=29,                                           //6 vs6 主角默认位置
    PEAKARENABASE_BUTTONHIDE=30,                                                //晋级挑战按钮在哪个赛区是隐藏的
    PEAKARENABASE_PEERLESSITEM=31,                                              //无双币道具ID
};
enum {
    SYSSWITCH_MUSIC=1,                                                          //Music
    SYSSWITCH_SOUNDEFFECT=2,                                                    //SoundEffect
    SYSSWITCH_FIGHTEFFECT=3,                                                    //FightEffect
    SYSSWITCH_SPIRITMAX=4,                                                      //SpiritMax
    SYSSWITCH_STAMINAMAX=5,                                                     //StaminaMax
    SYSSWITCH_GETSPIRIT=6,                                                      //GetSpirit
    SYSSWITCH_GUILDCHAPTEROPEN=7,                                               //GuildChapterOpen
    SYSSWITCH_CHARPRIVATELY=8,                                                  //CharPrivately
    SYSSWITCH_ARENACHANGE=9,                                                    //ArenaChange
    SYSSWITCH_GUILDNOTICE=10,                                                   //GuildNotice
    SYSSWITCH_MINEROB=11,                                                       //MineRob
    SYSSWITCH_TALKVIP=12,                                                       //TalkVIP
    SYSSWITCH_WORLD=13,                                                         //World
    SYSSWITCH_PRIVATE=14,                                                       //Private
    SYSSWITCH_GUILD=15,                                                         //Guild
    SYSSWITCH_CAMP=16,                                                          //Camp
    SYSSWITCH_GUILDWAR=17,                                                      //GuildWar
};
enum {
    WELFAREBASE_PAYVALUE=1,                                                     //充值金额【人民币】
    WELFAREBASE_GETTIMES=2,                                                     //领取天数
    WELFAREBASE_GETVALUE=3,                                                     //领取金额【元宝】
};
enum {
    POWERSET_ACCEPT=1,                                                          //入团审批
    POWERSET_KICK=2,                                                            //踢除军团成员（不包括团长和副团长）
    POWERSET_CARBON=3,                                                          //开启副本
    POWERSET_EDIT=4,                                                            //编辑宣言
    POWERSET_ALLOCATION=5,                                                      //军团奖励分配
};
enum {
    SNOWMANBASE_OPENLV=1,                                                       //雪人功能开启等级
    SNOWMANBASE_QUESTIONREFRESH=2,                                              //刷新问题时间
    SNOWMANBASE_RANKTIME=3,                                                     //出现兑换道具的概率
    SNOWMANBASE_RIGHTBASEGIFT=4,                                                //基本答对奖励
    SNOWMANBASE_QUESTIONNUM=5,                                                  //答题数量
    SNOWMANBASE_RANKREFOUNDTIME=6,                                              //发送排名奖励时间
    SNOWMANBASE_QUESTIONTIME=7,                                                 //问答时间
};
enum {
    FORMRESTRICT_FORM=1,                                                        //
    FORMRESTRICT_TRIALFORM=2,                                                   //
    FORMRESTRICT_ARENAGUARDFORM=11,                                             //
    FORMRESTRICT_MINEGUARDFORM1=21,                                             //
    FORMRESTRICT_MINEGUARDFORM2=22,                                             //
    FORMRESTRICT_MINEGUARDFORM3=23,                                             //
    FORMRESTRICT_MINEGUARDFORM4=24,                                             //
    FORMRESTRICT_MINEGUARDFORM5=25,                                             //
    FORMRESTRICT_TOWERFORM=31,                                                  //
};
enum {
    ACTIVERECRUITBASE_DESENODROP=1,                                             //招募武将库
    ACTIVERECRUITBASE_ONEPRICE=2,                                               //单抽花费
    ACTIVERECRUITBASE_TENPRICE=3,                                               //十连抽花费
    ACTIVERECRUITBASE_SPECIALDROPCOUNT=4,                                       //第N次掉指定将
    ACTIVERECRUITBASE_DEFAULTHEROID=5,                                          //如果GM工具没有配置默认使用武将-甘宁
};
enum {
    EXCHANGEBASE_LEVELCAP=1,                                                    //转化等级
    EXCHANGEBASE_RESETTIME=2,                                                   //道具刷新时间
};
enum {
    LUCKYTURNTABLEBASE_LUCKYINITIALVALUE=1,                                     //
    LUCKYTURNTABLEBASE_EACHADD=2,                                               //
    LUCKYTURNTABLEBASE_LUCKYVALUEUPPERLIMIT=3,                                  //
    LUCKYTURNTABLEBASE_PULLRECORDNUMBER=4,                                      //
    LUCKYTURNTABLEBASE_RESETTIME=5,                                             //
    LUCKYTURNTABLEBASE_LOTTERYITEMID=6,                                         //
    LUCKYTURNTABLEBASE_LOTTERYNORMALPRICE=7,                                    //
    LUCKYTURNTABLEBASE_LOTTERYTENPRICE=8,                                       //
};
enum {
    STAMINAREWARDBASE_OPENLV=1,                                                 //达到该等级后开启
    STAMINAREWARDBASE_LUCKYINITIALVALUE=2,                                      //初始幸运值
    STAMINAREWARDBASE_EACHADD=3,                                                //每抽一次增加值
    STAMINAREWARDBASE_LUCKYVALUEUPPERLIMIT=4,                                   //幸运值上限
};
enum {
    ARTIFACRANKBASE_ARTIFACTRANKBASECONT=1,                                     //最低招募次数
    ARTIFACRANKBASE_ARTIFACTRANKTIME=2,                                         //结算排行时间
};
BOOL ReloadXmlConfig(string &file);
class noncopy
{
protected:
    noncopy() {}
  ~noncopy() {}
private:
  noncopy( const noncopy& );
  noncopy& operator=( const noncopy& );
};
struct Dummy{
};
struct KeyType
{
    string name;
    UINT8 type;
    UINT16 addr;
    bool operator==(const KeyType &e)
    {
       return name==e.name;
    }
};

struct IdCount
{
    UINT32 id;
    UINT32 count;
    bool operator==(const IdCount &e)
    {
       return id==e.id&&count==e.count;
    }
};

template<class T>
void print_struct(T &t,KeyType *k,UINT32 kl)
{
    UINT32 i=0;
    UINT8 *p=(UINT8*)&t;
    vector<int> *pv=NULL;
    vector<string> *ps=NULL;
    for(;i<kl;++i)
    {
        if(k[i].type==0)
        {
            cout<<k[i].name<<"="<<*(UINT32*)(p+k[i].addr)<<endl;
        }else if(k[i].type==1)
        {
            cout<<k[i].name<<"="<<((string*)(p+k[i].addr))->c_str()<<endl;
        }else if(k[i].type==3)
        {
            cout<<"vector<int>:"<<k[i].name<<"="<<endl;
            pv=(vector<int>*)(p+k[i].addr);
            if(pv)
            {
                for(UINT32 ii: *pv)
                {
                     cout<<ii<<endl;
                }
            }

        }else if(k[i].type==4)
        {
            cout<<"vector<string>:"<<k[i].name<<"="<<endl;
            ps=(vector<string>*)(p+k[i].addr);
            if(ps)
            {
                for(string &s: *ps)
                {
                      cout<<s<<endl;
                }
            }

        }

    }
}
struct ActiveRecruit {
    UINT32 ID;                          //流水Id
    UINT32 HeroID;                      //武将ID
    string Des;                         //备注
};
struct ActiveRecruitTimes {
    UINT32 RecruitTimes;                //招募次数
    vector<IdCount> Job1;               //防御型累计奖励
    vector<IdCount> Job2;               //物攻型累计奖励
    vector<IdCount> Job3;               //狙杀型累计奖励
    vector<IdCount> Job4;               //辅助型累计奖励
    vector<IdCount> Job5;               //法术型累计奖励
    UINT32 FragTimes;                   //武将碎片数量
};
struct ActiveRecruitbase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct Activity {
    UINT32 ID;                          //序号
    vector<IdCount> FightID;            //难度
    UINT32 SpiritExpend;                //单次体力消耗
    UINT32 FightNum;                    //战斗次数
    UINT32 OpenTime;                    //开放时间
    UINT32 ContinueTime;                //持续时间
    vector<int> Limit;                  //上阵限制
    UINT32 ActivityFightType;           //活动副本类型
};
struct ActivityBase {
    UINT32 ID;                          //参数ID
    string Key;                         //Key
    UINT32 Value;                       //值
    string Des;                         //备注
};
struct ActivityFight {
    UINT32 FightID;                     //难度
    vector<int> FightSetID;             //战斗ID
    UINT32 DropBoxID;                   //掉落ID
    vector<IdCount> RewardNum;          //数值奖励
    UINT32 FightScene;                  //战斗场景ID
};
struct ActivityHero {
    UINT32 ID;                          //上阵类型
    vector<int> HeroID;                 //武将ID
};
struct ActivityOpen {
    UINT32 OpenTime;                    //开放时间
    vector<IdCount> Activity1ID;        //战役（资源）副本ID
    vector<IdCount> Activity2ID;        //讨伐（材料）副本ID
};
struct AddArtifact {
    UINT32 Id;                          //流水Id
    UINT32 ArtifactTimes;               //稀世珍宝数量
    vector<IdCount> ItemReward;         //道具奖励
};
struct AddRecruit {
    UINT32 Id;                          //流水Id
    UINT32 RecruitNum;                  //累计招募次数
    vector<IdCount> ItemReward;         //道具奖励
};
struct AllRank {
    UINT32 ID;                          //小标题ID
    string Key;                         //Key
    UINT32 Title;                       //大标题
    UINT32 OpenLv;                      //开放等级
    string Des;                         //注释
    UINT32 Value;                       //服务器保存条目
    UINT32 CountLv;                     //统计等级
    UINT32 Show;                        //是否显示
};
struct Arena {
    UINT32 ID;                          //流水ID
    UINT32 RobotGroupID;                //机器人组别
    UINT32 Level;                       //赛区类型
    string Name;                        //赛区名称
    UINT32 Capacity;                    //赛区人数上限
    UINT32 UpgradeArenaID;              //晋级赛区ID
    UINT32 UpgradeNum;                  //赛区可晋级排名
    UINT32 OutNum;                      //赛区被挑战排名
    UINT32 RankNum;                     //排行榜显示名次
    UINT32 RankRewardID;                //奖励ID
    vector<IdCount> WinRewardValue;     //胜利数值奖励
    vector<IdCount> LoseRewardValue;    //失败数值奖励
    UINT32 MatchID;                     //匹配ID
    UINT32 Notice;                      //是否公告
};
struct ArenaBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct ArenaMatch {
    UINT32 ID;                          //流水ID
    UINT32 MatchID;                     //匹配ID
    UINT32 Rank;                        //名次区间
    UINT32 DownMatching1;               //向下匹配排名1
    UINT32 DownMatching2;               //向下匹配排名2
    UINT32 UpMatching1;                 //向上匹配排名1
    UINT32 UpMatching2;                 //向上匹配排名2
    UINT32 SubUpMatching1;              //大幅向上匹配排名1
    UINT32 SubUpMatching2;              //大幅向上匹配排名2
};
struct ArenaReward {
    UINT32 ID;                          //流水ID
    UINT32 RewardID;                    //奖励ID
    UINT32 Rank;                        //名次区间
    vector<IdCount> RewardItem;         //道具奖励
};
struct ArenaTopReward {
    UINT32 ID;                          //流水ID
    UINT32 Rank;                        //实际名次区间
    UINT32 DiamondReward;               //每个名次奖励元宝数
};
struct ArtifacRankBase {
    UINT32 ID;                          //ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //注释
};
struct Artifact {
    UINT32 Id;                          //ID
    UINT32 Type;                        //类型
    UINT32 StrengthenId;                //神器强化Id
    UINT32 StarId;                      //神器升星Id
    vector<int> SpeHero;                //宿运武将
    vector<IdCount> WashId1;            //百炼类型1ID
    vector<IdCount> WashId2;            //百炼类型2ID
    vector<IdCount> WashId3;            //百炼类型3ID
    vector<IdCount> WashMax;            //百炼属性最大值
    vector<IdCount> UpgradeReward;      //合成返还
    UINT32 TeamUnique;                  //队伍冲突
    vector<int> BanHero;                //限制武将
};
struct ArtifactDropbox {
    UINT32 ID;                          //流水ID
    UINT32 DropboxID;                   //掉落库ID
    UINT32 ArtifactID;                  //道具ID
    UINT32 ItemType;                    //道具类型
    UINT32 ItemNum;                     //道具数量
    UINT32 Probablity;                  //掉落概率
    UINT32 DropType;                    //掉落类型
};
struct ArtifactRank {
    UINT32 Rank;                        //排名
    vector<IdCount> ItemReward;         //道具奖励
};
struct ArtifactSlot {
    UINT32 Id;                          //位置Id
    UINT32 Type;                        //类型
    UINT32 RequiredLevel;               //需要主角等级
};
struct ArtifactStar {
    UINT32 Id;                          //流水Id
    UINT32 Type;                        //类型Id
    UINT32 Star;                        //星级
    UINT32 SpeSkillId;                  //宿运技能
    UINT32 SpeSkillPower;               //宿运技能战力
    vector<int> SkillId;                //神兵技能
    UINT32 SkillPower;                  //技能战斗力
    vector<IdCount> CostResourse;       //消耗货币
    vector<IdCount> CostItem;           //消耗道具
    UINT32 SuccessRate;                 //成功率
    vector<IdCount> CostItem2;          //消耗道具
    UINT32 SuccessRate2;                //成功率
    UINT32 GrowthRate;                  //成长率
    UINT32 RequiredStrengthenLevel;     //需要强化等级
    vector<IdCount> UpgradeReward;      //合成返还
};
struct ArtifactStrengthen {
    UINT32 Id;                          //流水Id
    UINT32 Type;                        //类型Id
    UINT32 Level;                       //强化等级
    UINT32 RequiredLevel;               //需要主角等级
    vector<IdCount> CostResourse;       //消耗货币
    vector<IdCount> CostItem1;          //消耗道具
    UINT32 SuccessRate1;                //成功率
    vector<IdCount> CostItem2;          //消耗道具
    UINT32 SuccessRate2;                //成功率
    vector<IdCount> UpgradeReward;      //合成返还
    vector<IdCount> Prop;               //增加属性
};
struct ArtifactUpgrade {
    UINT32 Id;                          //品质Id
    UINT32 ArtifactLoot;                //神兵掉落库
    UINT32 SuccessRate;                 //成功率
    vector<IdCount> CostResource;       //消耗货币
    vector<int> FailReward;             //失败返还数量
    vector<IdCount> MoreReward;         //额外返还道具
};
struct ArtifactWash {
    UINT32 Id;                          //洗炼Id
    vector<IdCount> CostResourse;       //消耗货币
    vector<IdCount> CostItem;           //消耗道具
    vector<IdCount> PropertyAddition;   //属性增加值
    vector<IdCount> PropertyMin;        //属性类型最小值
};
struct BackBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    UINT32 Value;                       //值
    string Des;                         //注释
};
struct BackGift {
    UINT32 ID;                          //流水ID
    vector<int> Level;                  //等级
    UINT32 Turn;                        //顺序
    vector<int> Price;                  //售价
    vector<IdCount> Item;               //道具
};
struct BackLogin {
    UINT32 ID;                          //流水ID
    vector<int> Level;                  //等级
    UINT32 Turn;                        //次序
    vector<IdCount> LoginReward;        //登陆奖励
};
struct BackPay {
    UINT32 ID;                          //流水ID
    vector<int> Level;                  //等级
    UINT32 Cost;                        //花费金额
    vector<IdCount> Item;               //道具
};
struct BossChallengeCost {
    UINT32 ChallengeTime;               //神兽挑战次数
    UINT32 Cost;                        //消耗元宝
};
struct BossDrop {
    UINT32 ID;                          //流水ID
    UINT32 GuildLv;                     //军团等级
    UINT32 Energy;                      //活力值区间
    vector<IdCount> DropBoxID;          //击打与掉落库ID
};
struct BossReward {
    UINT32 ID;                          //流水ID
    UINT32 Rank;                        //名次
    vector<IdCount> Reward;             //功勋奖励
};
struct Box {
    UINT32 ID;                          //流水ID
    UINT32 Level;                       //主角等级
    UINT32 Item;                        //宝箱id
    UINT32 DropBoxID;                   //额外奖励
    vector<IdCount> ItemGet;            //固定奖励
};
struct BuffList {
    UINT32 ID;                          //序号
    UINT32 Type;                        //净化/驱散
    UINT32 BuffID;                      //元素ID
};
struct BuyDirect {
    UINT32 ItemID;                      //道具ID
    UINT32 Price;                       //单价
};
struct CampActOpen {
    UINT32 OpenTime;                    //活动开放时间
    vector<int> ActivityID;             //开放活动ID
};
struct CampBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct CampGrain {
    UINT32 ID;                          //流水ID
    string GrainName;                   //粮车名称
    UINT32 GrainType;                   //粮车品质
    UINT32 RewardNum;                   //运粮奖励
    UINT32 RobRewardNum;                //劫粮奖励
    UINT32 NextGrain;                   //下一品质编号
    UINT32 NextProb;                    //下一品质概率
    UINT32 PayType;                     //开启货币
    UINT32 PayNum;                      //开启价格
};
struct CampMine {
    UINT32 ID;                          //流水ID
    string MineName;                    //矿名
    UINT32 MineNum;                     //矿山数量
    UINT32 PayType;                     //消耗货币类型
    UINT32 PayNum;                      //消耗货币数量
    UINT32 Produce;                     //铜币产出
    UINT32 RobReward;                   //抢夺奖励
    UINT32 RobExtraDiamond;             //抢夺元宝价格
};
struct CampMineProduction {
    UINT32 Id;                          //流水Id
    UINT32 MineType;                    //矿山类型
    UINT32 PlayerLevel;                 //玩家等级
    vector<IdCount> Award;              //单位间隔产出
    UINT32 ScoreRate;                   //积分兑换比
    UINT32 MaxNum;                      //矿山最大值
    UINT32 RobedRate;                   //被抢比例
    UINT32 DropBox;                     //额外道具掉落包
    UINT32 DropRatio;                   //掉落间隔
};
struct CampMineScore {
    UINT32 ID;                          //流水ID
    UINT32 ScoreRate;                   //积分兑换比
    UINT32 WinScore;                    //战胜积分兑换比
};
struct CampMineUnlock {
    UINT32 ID;                          //矿ID
    UINT32 RequiredLevel;               //主公等级
    UINT32 RequiredVipLevel;            //Vip等级
};
struct CampMineUpgrade {
    UINT32 Id;                          //流水Id
    string MineName;                    //卡片名称
    UINT32 LastTime;                    //持续时间
    UINT32 Price;                       //售价
    UINT32 Score;                       //产出积分
    UINT32 FreeTimes;                   //是否有免费次数
};
struct CampOfficeRank {
    UINT32 PersonRanking;               //个人排名
    UINT32 Office;                      //官职
};
struct CampOfficeRight {
    UINT32 ID;                          //流水ID
    UINT32 ThroughNum;                  //阵营闯关次数
    UINT32 ThroughOnceMoreNum;          //翻牌张数
    UINT32 RobMineNum;                  //资源抢夺次数
    UINT32 GrainTransNum;               //运粮次数
    UINT32 GrainCarColorNum;            //木牛流马刷新品质次数
    UINT32 RobGrainNum;                 //劫粮次数
    UINT32 WarNum;                      //阵营战挑战次数
};
struct CampReward {
    UINT32 ID;                          //流水ID
    UINT32 RewardID;                    //阵营玩法ID
    UINT32 Rank;                        //阵营排名
    vector<IdCount> ItemReward;         //道具奖励
};
struct CampRoleReward {
    UINT32 ID;                          //流水ID
    UINT32 RewardID;                    //奖励ID
    vector<int> Rank;                   //名次区间
    vector<IdCount> ItemReward;         //道具奖励
};
struct CampThrough {
    UINT32 ID;                          //关卡ID
    UINT32 ThroughID;                   //通过凭证ID
    UINT32 NextCustomsID;               //后置关卡ID
    UINT32 ThroughWeight;               //通关权重
    UINT32 CoinReward;                  //通关货币奖励
    UINT32 FlopExpend;                  //翻牌消耗元宝
    UINT32 OnceMorePay;                 //再来一次价格
    vector<IdCount> FlopReward;         //翻牌奖励
};
struct CampThroughItem {
    UINT32 ID;                          //流水ID
    UINT32 Level;                       //主角等级
    UINT32 Through;                     //关卡
    vector<IdCount> ItemGet;            //道具奖励
};
struct CampTurntable {
    UINT32 ID;                          //流水ID
    UINT32 PositionID;                  //位置ID
    UINT32 Camp;                        //阵营
    UINT32 ItemCount;                   //道具数量
    UINT32 WhetherNotice;               //是否公告
    UINT32 Weight;                      //权重
    UINT32 ItemBoxID;                   //道具包ID
};
struct CampTurntableItems {
    UINT32 ID;                          //流水ID
    UINT32 ItemBoxID;                   //掉落库
    UINT32 ItemID;                      //道具ID
    UINT32 Weight;                      //权重
};
struct CampWarStreakReward {
    UINT32 WinTimes;                    //胜利场数
    UINT32 StreakReward;                //连胜奖励
    UINT32 StreakEndReward;             //终结奖励
};
struct ChannelBase {
    UINT32 ID;                          //频道ID
    string Key;                         //key
    UINT32 Value;                       //值
    string Des;                         //描述备注
};
struct Chapter {
    UINT32 ChapterID;                   //章节ID
    UINT32 SceneLine;                   //剧情线路
    vector<int> LastChapters;           //章节开启前缀
    vector<int> NextChapters;           //章节开启后缀
    UINT32 OpenLv;                      //章节开启等级
    vector<IdCount> Boxes;              //星星数：奖励宝箱
    vector<int> Fights;                 //战斗点
};
struct ChatBase {
    UINT32 ID;                          //聊天ID
    string Key;                         //Key
    UINT32 Value;                       //值
    string Des;                         //备注
};
struct ChatNotice {
    UINT32 ID;                          //军团日志ID
    string Key;                         //关键词
    string Content;                     //日志内容
    string Des;                         //公告说明
};
struct Coin {
    UINT32 ID;                          //货币编号
    UINT32 OneCoinItemID;               //单位道具ID
};
struct CoinPurchase {
    UINT32 BuyTime;                     //铜币购买次数
    UINT32 Cost;                        //购买价格(元宝）
    UINT32 Add;                         //增加铜币
};
struct CostBase {
    UINT32 ID;                          //属性ID
    string Key;                         //Key
    string Name;                        //属性名称
    string Des;                         //属性描述
    UINT32 Value;                       //属性值
};
struct CostSum {
    UINT32 Id;                          //流水Id
    UINT32 Sum;                         //累计消耗元宝
    vector<IdCount> ItemReward;         //道具奖励
};
struct DailyCostSum {
    UINT32 Id;                          //流水Id
    UINT32 Sum;                         //累计消耗元宝
    vector<IdCount> ItemReward;         //道具奖励
};
struct DailyLogin {
    UINT32 Days;                        //天数
    vector<IdCount> ItemReward;         //道具奖励
    string Des;                         //道具奖励
};
struct DailyPaySum {
    UINT32 Id;                          //流水Id
    UINT32 Sum;                         //累计充值额度
    vector<IdCount> ItemReward;         //道具奖励
};
struct DailySumPayReward {
    UINT32 Id;                          //流水Id
    UINT32 Day;                         //天数
    UINT32 Index;                       //序列
    UINT32 PaySum;                      //累计充值额度
    vector<IdCount> ItemReward;         //道具奖励
};
struct DepreFactor {
    UINT32 ID;                          //流水ID
    float Factor;                       //贬值系数
};
struct DropOther {
    string DropType;                    //要掉落的掉落类型
    string Des;                         //说明备注
    UINT32 DropBox;                     //使用的掉落包
};
struct Dropbox {
    UINT32 ID;                          //流水ID
    UINT32 DropboxID;                   //掉落库ID
    UINT32 ItemID;                      //道具ID
    UINT32 ItemType;                    //道具类型
    UINT32 ItemNum;                     //道具数量
    UINT32 Probablity;                  //掉落概率
    UINT32 DropType;                    //掉落类型
};
struct Email {
    UINT32 ID;                          //邮件流水ID
    string Key;                         //邮件类型关键词
    string Titile;                      //邮件标题
    string Content;                     //邮件内容
    vector<int> AttachID;               //邮件附件引用ID
    string SenderName;                  //发件人
};
struct Equip {
    UINT32 ID;                          //装备id
    UINT32 Valid;                       //生效
    UINT32 Job;                         //装备职业
    UINT32 Part;                        //装备部位
    UINT32 Star;                        //装备星级
    vector<int> PropID;                 //装备属性类型
    vector<int> PropValue;              //初始属性值
    vector<int> LevelValue;             //强化加成值
    UINT32 LevelLimit;                  //强化等级上限
    vector<int> LevelCostParameters;    //强化铜币消耗参数
    UINT32 CoinCostIndex;               //强化铜币消耗索引
    vector<int> ActivePropID;           //潜藏属性类型
    vector<IdCount> ActivePropLevels;   //增加属性值
    UINT32 PlateOpenLevel;              //打造开启等级
    UINT32 InitialLevel;                //初始等级
    vector<IdCount> PlateCostItems;     //打造消耗道具
    UINT32 PlateNewID;                  //打造后装备ID
    UINT32 QuenchPropCount;             //淬火解锁数量
    UINT32 QuenchPropIndex;             //淬火属性库
    UINT32 GemCount;                    //宝石槽解锁数量
    vector<IdCount> Cost;               //升星消耗
};
struct EquipBase {
    UINT32 ID;                          //装备锁定ID
    string Key;                         //Key
    UINT32 Value;                       //值
    string Des;                         //备注
};
struct EquipCoinCost {
    UINT32 ID;                          //索引ID
    string Parameters;                  //等级参数
};
struct EquipMaterialGroup {
    UINT32 Id;                          //ID
    vector<IdCount> Items;              //返还道具
};
struct EquipRecycle {
    UINT32 Id;                          //ID
    UINT32 Star;                        //星级
    UINT32 Job;                         //职业
    UINT32 Part;                        //装备部位
    vector<int> MaterialGroup;          //返还道具
};
struct EventRecruit {
    UINT32 ID;                          //开放周ID
    UINT32 HeroID;                      //活动武将ID
};
struct Exchange {
    UINT32 ID;                          //流水ID
    UINT32 ShopID;                      //商城类别
    UINT32 ShopItemID;                  //商城道具ID
    UINT32 CostValue;                   //道具单价
    UINT32 Count;                       //可购买数量
};
struct ExchangeBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct FightSet {
    UINT32 FightSetID;                  //战斗ID
    string FightName;                   //战斗名称
    string FightScene;                  //战斗场景图
    UINT32 FightType;                   //战斗类型
    UINT32 IsBoss;                      //BOSS镜头
    UINT32 MonsterLv;                   //怪物等级
    vector<int> Monster1;               //前排左列
    vector<int> Monster2;               //前排钟中列
    vector<int> Monster3;               //前排右列
    vector<int> Monster4;               //后排左列
    vector<int> Monster5;               //后排中列
    vector<int> Monster6;               //后排右列
    vector<int> Support1;               //前排左列
    vector<int> Support2;               //前排钟中列
    vector<int> Support3;               //前排右列
    vector<int> Support4;               //后排左列
    vector<int> Support5;               //后排中列
    vector<int> Support6;               //后排右列
    UINT32 RolePosition;                //主角位置
};
struct Form {
    UINT32 ID;                          //id
    UINT32 FormNum;                     //阵位数
    UINT32 RoleLevel;                   //角色等级
};
struct FormRestrict {
    UINT32 ID;                          //流水ID
    string Key;                         //阵型Key
    vector<IdCount> Restrict;           //限制的职业及数量
};
struct FragConvert {
    UINT32 GiftItem;                    //升星消耗道具
    UINT32 Convert;                     //兑换消耗道具
};
struct Fund {
    UINT32 ID;                          //流水ID
    UINT32 Rewardlevel;                 //奖励等级
    vector<IdCount> AwardItem;          //奖励物品
};
struct FundBase {
    UINT32 ID;                          //流水ID
    UINT32 ID1;                         //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct Gem {
    UINT32 ID;                          //宝石ID
    UINT32 Level;                       //宝石等级
    UINT32 PropID;                      //宝石类型
    UINT32 PropValue;                   //加成属性值
    vector<int> UseJob;                 //可使用职业
};
struct Growing {
    UINT32 ID;                          //流水
    UINT32 Prob;                        //暴击属性库
    UINT32 Weight;                      //权重
    UINT32 Plus;                        //增加成长值
};
struct GuildBase {
    UINT32 GuildBaseID;                 //帮派参数ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct GuildBattleChat {
    UINT32 ID;                          //军团战日志ID
    string Key;                         //关键词
    string Content;                     //日志内容
    string Des;                         //公告说明
};
struct GuildBattleCity {
    UINT32 CityID;                      //城池
    string CityName;                    //城池名称
    UINT32 Shop;                        //商店Id
    vector<IdCount> ConquerAward;       //攻克奖励
    UINT32 GateScore;                   //城门总战功
    vector<IdCount> SpotScore;          //据点产出积分
    vector<IdCount> SpotHonor;          //据点产出战功
};
struct GuildBattleFight {
    UINT32 GateLevel;                   //城门等级
    UINT32 FightSetId;                  //战斗Id
};
struct GuildBattleLog {
    UINT32 ID;                          //军团日志ID
    string Key;                         //关键词
    string Language;                    //对应语言包
    string Content;                     //日志内容
};
struct GuildBattlePersonRank {
    UINT32 PersonalRank;                //个人排名
    UINT32 PersonalRankRate;            //个人排名系数
};
struct GuildBattleRank {
    UINT32 GuildRank;                   //军团排名
    vector<IdCount> Award;              //奖励
    UINT32 GuildRate;                   //军团基数
    vector<IdCount> DropBox;            //随机掉落包
};
struct GuildBattleSeverPersonRank {
    UINT32 PersonalRank;                //个人排名
    vector<IdCount> Award;              //奖励
};
struct GuildChapter {
    UINT32 ID;                          //流水ID
    UINT32 OpenGuildLv;                 //开启帮派等级限制
    UINT32 OpenCost;                    //开启消耗帮派资金
    UINT32 MaxFightNum;                 //最大挑战数量
    UINT32 FightCostExploit;            //挑战消耗功勋
    UINT32 FightID;                     //战斗库
    UINT32 LastTime;                    //开启持续时间
};
struct GuildChapterFight {
    UINT32 ID;                          //流水ID
    UINT32 FightID;                     //战斗库
    UINT32 FightSequence;               //战斗顺序
    UINT32 FightSetID;                  //战斗ID
    UINT32 DropBoxID;                   //掉落库ID
};
struct GuildDungeon {
    UINT32 DungeonId;                   //副本Id
    vector<int> BossGroup;              //Boss序列
    UINT32 FightBackGround;             //战斗背景
    UINT32 SpotDes;                     //召唤需要星级
    vector<int> Spot;                   //据点
    vector<IdCount> ChallengeAward;     //挑战奖励
    UINT32 PreDungeonId;                //前置副本
    UINT32 LevelRequired;               //需要开启者等级
};
struct GuildDungeonAward {
    UINT32 Id;                          //流水Id
    UINT32 Dungeon;                     //军团副本Id
    vector<int> Rank;                   //排名
    vector<IdCount> Award;              //奖励
};
struct GuildDungeonSpot {
    UINT32 SpotId;                      //战斗点Id
    UINT32 FightSetId;                  //怪物Id
    UINT32 FightBackGround;             //战斗背景
    UINT32 StarCondition;               //星级条件Id
    UINT32 DropBoxId;                   //掉落库ID
};
struct GuildFlag {
    UINT32 GuildFlagLv;                 //帮派军旗等级
    UINT32 GuildLvLimit;                //升级军旗需要帮派等级
    UINT32 UpCost;                      //升级消耗帮派资金
};
struct GuildFlagLv {
    UINT32 OwnFlagLv;                   //帮派军旗等级
    UINT32 FlagLv;                      //升级需要军旗等级
    vector<IdCount> ProValue;           //等级属性效果
    UINT32 UpCost;                      //升级消耗功勋
};
struct GuildLog {
    UINT32 ID;                          //军团日志ID
    string Key;                         //关键词
    string Language;                    //对应语言包
    string Content;                     //日志内容
};
struct GuildLv {
    UINT32 Lv;                          //帮派等级
    UINT32 GuildExp;                    //帮派升级所需经验
    UINT32 MaxMember;                   //帮派最大人数
    UINT32 BossEnergyMax;               //神兽活力值上限
    vector<IdCount> BossDrop;           //击杀神兽奖励宝箱
    UINT32 BossFightSet;                //神兽战斗ID
    UINT32 BossPosition;                //boss阵容位置
    UINT32 KillGuildExp;                //击杀神兽帮派经验
    UINT32 KillBossAddFund;             //击杀神兽增加军团资金
    UINT32 BossCoinCost;                //铜币喂养神兽消耗
    UINT32 BossCoinExploit;             //铜币喂养神兽功勋获得
    UINT32 BossCoinEnergy;              //铜币喂养活力值增加
    UINT32 BossGoldCost;                //元宝喂养神兽消耗
    UINT32 BossGoldExploit;             //元宝喂养神兽功勋获得
    UINT32 BossGoldEnergy;              //元宝喂养活力值增加
    UINT32 BossBattleCostGold;          //挑战神兽消耗元宝
    UINT32 DonateCoinCost;              //捐献消耗铜币
    UINT32 DonateCoinExploit;           //铜币捐献获得功勋
    UINT32 DonateCoinFund;              //铜币捐献增加资金
    UINT32 DonateCoinGuildExp;          //铜币捐献增加军团经验
    UINT32 DonateGoldCost;              //捐献消耗元宝
    UINT32 DonateGoldExploit;           //元宝捐献获得功勋
    UINT32 DonateGoldFund;              //元宝捐献增加资金
    UINT32 DonateGoldGuildExp;          //铜币捐献增加军团经验
};
struct GuildMember {
    UINT32 GuildPosition;               //帮派职位
    UINT32 PositionExp;                 //职位经验
    UINT32 ISGuildFight;                //是否可以参加帮派战
    UINT32 GuildBossCoinNum;            //帮派神兽铜币喂养次数
    UINT32 GuildBossGoldNum;            //帮派神兽元宝喂养次数
    UINT32 GuildBossFightNum;           //帮派神兽挑战次数
    UINT32 KickCost;                    //踢人扣除帮派资金
    UINT32 GuildDonateCoinNum;          //铜币捐献次数
    UINT32 GuildDonateGoldNum;          //元宝捐献次数
};
struct Hero {
    UINT32 HeroID;                      //ID
    string Name;                        //武将名称
    UINT32 HeroType;                    //武将类型
    UINT32 ItemColor;                   //武将颜色
    UINT32 Country;                     //阵营
    UINT32 Job;                         //职业
    UINT32 StartStar;                   //武将初始星级
    UINT32 MaxStar;                     //武将最大星级
    UINT32 Quality;                     //武将品质
    UINT32 Frag;                        //武将碎片
    vector<int> Equips;                 //装备ID
    UINT32 Anger;                       //怒气
    UINT32 MaxAnger;                    //最大怒气
    UINT32 HP;                          //生命
    UINT32 Atk;                         //物理攻击
    UINT32 Matk;                        //法术攻击
    UINT32 DEF;                         //物防
    UINT32 MDEF;                        //法防
    UINT32 Hit;                         //命中
    UINT32 Duck;                        //闪避
    UINT32 Crit;                        //暴击
    UINT32 CounterCrit;                 //抗暴
    UINT32 CounterATK;                  //反击
    UINT32 DCounterATK;                 //破挡
    UINT32 Parry;                       //格挡
    UINT32 GiftID;                      //天赋ID
    UINT32 CounterATKSkillID;           //反击技能
    UINT32 ExpIndex;                    //经验引索
    UINT32 LevelBase;                   //初始等级
    UINT32 MaxLV;                       //最大等级
    UINT32 Valid;                       //生效
    UINT32 Male;                        //武将性别
    vector<int> Label;                  //标签
    vector<int> SoulSkill;              //战魂技能Id
};
struct HeroBase {
    UINT32 HeroBaseID;                  //英雄属性计算基数
    string Key;                         //KeyID
    float Value;                        //值
    string Des;                         //备注
};
struct HeroExp {
    UINT32 ExpID;                       //流水ID
    UINT32 ExpIndex;                    //经验引索
    UINT32 Level;                       //武将等级
    UINT32 BaseRoleLv;                  //主角等级限制
    UINT32 Exp;                         //升级所需经验
    UINT32 RecycleExp;                  //返还将魂
};
struct HeroGift {
    UINT32 GiftID;                      //ID
    UINT32 NextID;                      //突破后ID
    UINT32 GiftLv;                      //天赋等级
    UINT32 HpBase;                      //生命资质
    UINT32 PatkBase;                    //物攻资质
    UINT32 MatkBase;                    //法攻资质
    UINT32 PdefBase;                    //物防资质
    UINT32 MdefBase;                    //法防资质
    UINT32 SkillID;                     //普攻技能ID
    UINT32 AngerSkillID;                //怒气技能
    UINT32 GiftSkillID;                 //天赋技能
    UINT32 StartSkillID;                //开场技能
    UINT32 DieSkillID;                  //死亡技能
    vector<int> GiftPropId;             //增加属性
    UINT32 GiftLvLimit;                 //突破等级限制
    vector<IdCount> GiftItem;           //突破物品
    UINT32 NeedStar;                    //突破需要星级
    UINT32 Command;                     //统帅
    UINT32 Power;                       //武力
    UINT32 IQ;                          //智慧
    vector<IdCount> Cost;               //升星消耗
};
struct HeroGiftProp {
    UINT32 GiftPropId;                  //ID
    UINT32 PropId;                      //属性类型
    UINT32 PropType;                    //加成类型
    UINT32 PropValue;                   //数值
    UINT32 GiftLv;                      //解锁天赋等级
    UINT32 ActionValue;                 //战斗力
};
struct HeroGiftSkill {
    UINT32 ID;                          //流水ID
    UINT32 HeroID;                      //武将ID
    UINT32 GiftLv;                      //天赋等级
    UINT32 StartSkillID;                //开场技能
    UINT32 DieSkillID;                  //死亡技能
};
struct HeroRecycle {
    UINT32 Id;                          //ID
    UINT32 Grade;                       //进阶程度
    UINT32 Quality;                     //武将品质
    vector<IdCount> Items;              //返还道具
};
struct HeroSkin {
    UINT32 ID;                          //流水ID
    UINT32 HeroID;                      //武将ID
    UINT32 SkinHeroID;                  //皮肤武将ID
    UINT32 Time;                        //皮肤时效
    vector<IdCount> Price;              //货币价格
    UINT32 Marker;                      //时效标记
    vector<IdCount> ItemPrice;          //道具价格
};
struct HeroSoul {
    UINT32 SkillID;                     //技能ID
    UINT32 Cost;                        //消耗类型
};
struct HeroStar {
    UINT32 ID;                          //流水ID
    UINT32 HeroID;                      //武将ID
    UINT32 Star;                        //武将星级
    vector<IdCount> GiftItem;           //消耗物品
    UINT32 HpGrowth;                    //生命成长
    UINT32 PatkGrowth;                  //物攻成长
    UINT32 MatkGrowth;                  //法攻成长
    UINT32 PdefGrowth;                  //物防成长
    UINT32 MdefGrowth;                  //法防成长
    vector<IdCount> Cost;               //升星消耗
};
struct HeroStarRecycle {
    UINT32 Id;                          //ID
    UINT32 Star;                        //武将星级
    UINT32 Quality;                     //武将品质
    UINT32 Frag;                        //武将碎片
};
struct Item {
    UINT32 ItemID;                      //道具ID
    UINT32 ItemType;                    //道具类型
    UINT32 ItemColor;                   //道具品质
    vector<int> ItemPropLimit;          //使用道具限制
    UINT32 ItemPropType;                //道具使用效果类型
    vector<IdCount> ItemPropCost;       //使用道具消耗
    UINT32 ItemPropValue;               //数值参数
    UINT32 ItemEffectValue;             //道具使用效果参数
    UINT32 Prop;                        //是否直接使用
    UINT32 CombineType;                 //合成类型
    UINT32 CombineResult;               //合成后道具
    UINT32 CombineCount;                //合成武将/装备数量
    vector<IdCount> CombineRequire;     //合成需要道具
    vector<IdCount> CombineCost;        //合成消耗货币
    UINT32 ItemSave;                    //道具分页签
    UINT32 ItemTips;                    //道具Tips类型
    UINT32 ErrorType;                   //对应模块
    vector<int> Recycle;                //道具回收价格
    vector<IdCount> RecycleItem;        //道具回收返还道具
    UINT32 MaxUse;                      //最大使用数量
    UINT32 Artifact;                    //神兵Id
};
struct LevelUpReward {
    UINT32 Level;                       //主将等级
    UINT32 RewardType;                  //奖励类型
    vector<IdCount> ItemReward;         //道具奖励
};
struct LoginActReward {
    UINT32 ID;                          //流水ID
    UINT32 Days;                        //天数
    UINT32 RewardType;                  //奖励类型
    vector<IdCount> ItemReward;         //道具奖励
};
struct Lottery {
    UINT32 Count;                       //聚宝次数
    UINT32 VIP;                         //最低VIP
    vector<IdCount> Cost;               //聚宝金额
    UINT32 Get;                         //活动的货币
    vector<IdCount> Get1;               //获得金额
};
struct LotteryBase {
    UINT32 ID;                          //ID
    string Key;                         //Key
    UINT32 Value;                       //值
    string Des;                         //备注
};
struct LuckyTurntable {
    UINT32 ItemID;                      //道具ID
    UINT32 PositionID;                  //位置ID
    UINT32 Count;                       //数量
    UINT32 WhetherNotice;               //是否公告
    UINT32 Strengthen;                  //是否强化
};
struct LuckyTurntableBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
};
struct LuckyTurntableItems {
    UINT32 ID;                          //流水ID
    UINT32 ItemBoxID;                   //掉落库
    UINT32 ItemID;                      //道具ID
    UINT32 Count;                       //数量
    UINT32 Weight;                      //权重
};
struct LuckyTurntableValue {
    UINT32 ID;                          //流水ID
    UINT32 LuckyValue;                  //幸运值
    UINT32 ItemBoxID;                   //掉落库
};
struct MailDouble {
    UINT32 ID;                          //活动ID
    vector<IdCount> ItemReward;         //道具奖励
    string Des;                         //道具奖励
};
struct Misc {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct MonsterBase {
    UINT32 MonsterID;                   //ID
    UINT32 Country;                     //阵营
    string Name;                        //怪物名称
    UINT32 Star;                        //怪物星级
    UINT32 Job;                         //职业
    UINT32 SkillID;                     //普攻技能ID
    UINT32 AngerSkillID;                //怒气技能
    UINT32 GiftSkillID;                 //天赋技能
    UINT32 CounterATKSkillID;           //反击技能
    UINT32 StartSkillID;                //开场技能
    UINT32 DieSkillID;                  //死亡技能
    UINT32 Anger;                       //初始怒气
    UINT32 MaxAnger;                    //最大怒气
    UINT32 HP;                          //生命
    UINT32 Atk;                         //物理攻击
    UINT32 Matk;                        //法术攻击
    UINT32 DEF;                         //物防
    UINT32 MDEF;                        //法防
    UINT32 Hit;                         //命中
    UINT32 Duck;                        //闪避
    UINT32 Crit;                        //暴击
    UINT32 CounterCrit;                 //抗暴
    UINT32 CounterATK;                  //反击
    UINT32 DCounterATK;                 //破挡
    UINT32 Parry;                       //格挡
    vector<int> Label;                  //标签
};
struct MonsterProperty {
    UINT32 ID;                          //流水id
    UINT32 Job;                         //怪物职业
    UINT32 MonsterLv;                   //怪物等级
    UINT32 Job1;                        //怪物职业
    UINT32 HP;                          //生命
    UINT32 Atk;                         //物理攻击
    UINT32 Matk;                        //法术攻击
    UINT32 DEF;                         //物防
    UINT32 MDEF;                        //法防
    UINT32 Hit;                         //命中
    UINT32 Duck;                        //闪避
    UINT32 Crit;                        //暴击
    UINT32 CounterCrit;                 //抗暴
    UINT32 CounterATK;                  //反击
    UINT32 DCounterATK;                 //破挡
    UINT32 Parry;                       //格挡
};
struct MonsterStrength {
    UINT32 ID;                          //流水编号
    UINT32 HP;                          //生命
    UINT32 Atk;                         //物理攻击
    UINT32 Matk;                        //法术攻击
    UINT32 DEF;                         //物防
    UINT32 MDEF;                        //法防
    UINT32 Hit;                         //命中
    UINT32 Duck;                        //闪避
    UINT32 Crit;                        //暴击
    UINT32 CounterCrit;                 //抗暴
    UINT32 CounterATK;                  //反击
    UINT32 DCounterATK;                 //破挡
    UINT32 Parry;                       //格挡
    UINT32 Difficulty;                  //难度
    UINT32 Strength;                    //强度
};
struct Mounts {
    UINT32 ID;                          //坐骑ID
    UINT32 Star;                        //坐骑星级
    UINT32 EquipCount;                  //装备槽数量
    UINT32 MaxLevel;                    //可穿装备最大等级
    UINT32 Growing;                     //成长值上限
    UINT32 FeedCost;                    //饲料消耗
    vector<int> PropsCost;              //道具消耗
    UINT32 Prob;                        //概率库
    vector<IdCount> Power;              //基础属性
    UINT32 UpgradeID;                   //进化后ID
};
struct MountsEquip {
    UINT32 ID;                          //马具ID
    UINT32 slot;                        //装备槽
    UINT32 Level;                       //马具等级
    vector<IdCount> Prop;               //加成属性
};
struct MountsEquipment {
    UINT32 MountsEquipmentId;           //坐骑装备Id
    UINT32 ItemID;                      //对应道具
    vector<IdCount> Prop;               //加成主角属性
};
struct MountsStar {
    UINT32 MountStar;                   //星级
    vector<IdCount> GrowthRate;         //成长率
    vector<IdCount> RequiredItem;       //升星需要道具
};
struct MountsTrain {
    UINT32 MountTrainID;                //培养等级
    vector<IdCount> Power;              //基础属性
    UINT32 Slot1EquipId;                //栏位1装备
    UINT32 Slot1RequiredLevel;          //栏位1需要等级
    UINT32 Slot2EquipId;                //栏位2装备
    UINT32 Slot2RequiredLevel;          //栏位2需要等级
    UINT32 Slot3EquipId;                //栏位3装备
    UINT32 Slot3RequiredLevel;          //栏位3需要等级
    UINT32 Slot4EquipId;                //栏位4装备
    UINT32 Slot4RequiredLevel;          //栏位4需要等级
    UINT32 Slot5EquipId;                //栏位5装备
    UINT32 Slot5RequiredLevel;          //栏位5需要等级
    UINT32 Slot6EquipId;                //栏位6装备
    UINT32 Slot6RequiredLevel;          //栏位6需要等级
};
struct Mysticshop {
    UINT32 ShopItemID;                  //商城道具ID
    vector<int> CostValue;              //货币兑换消耗
    UINT32 Count;                       //可购买数量
};
struct MysticshopRefreshCost {
    UINT32 BuyTime;                     //购买次数
    UINT32 Cost;                        //消耗元宝数量
};
struct NewYearActivity {
    UINT32 ID;                          //流水ID
    UINT32 StrengthValue;               //体力
    vector<IdCount> ItemDrop;           //值
    UINT32 Probability;                 //掉落概率
    string Des;                         //备注
};
struct NewYearActivityBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct NewYearRecycle {
    UINT32 ID;                          //流水ID
    vector<IdCount> CostItem;           //消耗道具
    vector<IdCount> GetItem;            //兑换道具
    UINT32 Gets;                        //获取次数
};
struct Pay {
    UINT32 ID;                          //ID
    UINT32 Paynull;                     //付费金额
    UINT32 Type;                        //充值类型
    UINT32 Gain;                        //获得元宝
    UINT32 FirstGain;                   //首次购买额外获得
    UINT32 GiveGain;                    //常规购买额外获得
    UINT32 BuyDay;                      //买断天数
    UINT32 Return;                      //上线返还
    UINT32 VipExp;                      //获得的VIP经验值
    string ItemID;                      //道具ID
    string NameID;                      //充值金额名字
    UINT32 ConnectTask;                 //关联未完成任务
    UINT32 ConnectTaskClear;            //关联完成任务
};
struct PayRebate {
    UINT32 ID;                          //充值ID
    vector<IdCount> ReturnItem;         //额外赠送道具
    string Des;                         //描述
    string PlatformDes;                 //平台备注
    UINT32 PlatformID;                  //平台ID
    UINT32 Times;                       //购买次数
};
struct PaySum {
    UINT32 Id;                          //流水Id
    UINT32 Sum;                         //累计充值额度
    vector<IdCount> ItemReward;         //道具奖励
};
struct PeakArena {
    UINT32 ID;                          //流水ID
    UINT32 Formattype;                  //赛制类型
    string Name;                        //赛制名称
    UINT32 Divisiontype;                //赛区类型
    string Name1;                       //赛区名称
    UINT32 Awardnumber;                 //赛区最多奖励人数
    UINT32 CorrespondingDivision;       //对应赛区
    UINT32 MaximumSelection;            //最大可被挑战名次
    UINT32 UpgradeArenaID;              //晋级赛区ID
    UINT32 Capacity;                    //赛区人数上限
    UINT32 UpgradeNum;                  //赛区可晋级排名
    UINT32 OutNum;                      //赛区被挑战排名
    UINT32 Rewardmode;                  //奖励类型
    vector<IdCount> OpenTime;           //开放时间
    vector<int> OpenDate;               //开放日期
    vector<IdCount> WinRewards;         //挑战胜利奖励
    vector<IdCount> LoseRewards;        //挑战失败奖励
};
struct PeakArenaBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct PeakArenaFormat {
    UINT32 Formattype;                  //赛制类型
    UINT32 MatchHeroNum;                //参赛武将数量
    UINT32 MatchRole;                   //主角是否参赛
    vector<int> CannotForm;             //不可上阵的位置
    vector<IdCount> JoinJob;            //可用职业
    UINT32 GameTimes;                   //比赛回合数
    UINT32 WinTimes;                    //比赛场次
};
struct PeakArenaMatch {
    UINT32 ID;                          //流水ID
    UINT32 Divisiontype;                //赛区类型
    UINT32 Rank;                        //名次区间
    UINT32 UpMatching1;                 //大幅向上匹配排名1
    UINT32 UpMatching2;                 //中幅向上匹配排名2
    UINT32 UpMatching3;                 //小幅向上向上匹配排名3
    UINT32 DownMatching1;               //向下匹配排名1
};
struct PeakArenaReward {
    UINT32 ID;                          //流水ID
    UINT32 RewardsType;                 //奖励类型
    UINT32 Rank;                        //名次区间
    UINT32 GetCoin;                     //产出货币ID
    UINT32 GetNum;                      //一次产出货币数量
    UINT32 GetTime;                     //单位产出货币时间
};
struct PeakRobot {
    UINT32 ID;                          //流水ID
    UINT32 GiftID;                      //角色ID
    UINT32 LeagueForm;                  //保存阵型
    UINT32 sex;                         //性别
    UINT32 RoleID;                      //主角
    string name;                        //名字
    UINT32 roleLv;                      //角色等级
    UINT32 FightValue;                  //战斗力
    vector<int> Hero1;                  //武将1
    vector<int> Hero2;                  //武将2
    vector<int> Hero3;                  //武将3
    vector<int> Hero4;                  //武将4
    vector<int> Hero5;                  //武将5
    vector<int> Hero6;                  //武将6
    vector<int> SkillList;              //技能清单
    UINT32 ArenaShowLv;                 //竞技场展示等级
};
struct PeakUse {
    UINT32 ID;                          //流水ID
    UINT32 UpgradeArenaID;              //晋级赛区ID
    UINT32 RobotID;                     //机器人ID
    UINT32 Rank;                        //名次
};
struct PowerSet {
    UINT32 ID;                          //流水ID
    UINT32 Type;                        //成员类型
    string Key;                         //Key
    UINT32 DefaultSwitch;               //默认开关
    string Des;                         //备注
};
struct PushMessages {
    UINT32 MessagesID;                  //流水ID
    string Key;                         //Key
    string MessagesDes;                 //消息内容
};
struct QuenchProp {
    UINT32 ID;                          //流水号
    UINT32 Index;                       //淬火属性库
    UINT32 PropID;                      //属性
    UINT32 PropTopValue;                //上限值
    UINT32 PropWeight;                  //权重
};
struct QuenchRand {
    UINT32 ID;                          //流水号
    UINT32 Index;                       //淬火属性库
    UINT32 Percent;                     //百分比
    UINT32 Weight;                      //权重
    UINT32 Key;                         //暴击数
};
struct QuestionPoints {
    UINT32 Countdown;                   //剩余秒
    UINT32 WinPoints;                   //胜利获得积分
    UINT32 LosePoints;                  //失败获得积分
};
struct QuestionRank {
    UINT32 ID;                          //流水ID
    vector<int> Rank;                   //名次区间
    vector<IdCount> ItemReward;         //道具奖励
};
struct Ranking {
    UINT32 ID;                          //流水ID
    UINT32 RankingID;                   //排行榜ID
    UINT32 RankingType;                 //排行榜类型
    UINT32 RankingMax;                  //排名上限
    UINT32 RankingMin;                  //排名下限
    vector<IdCount> RankingReward;      //排名奖励
    UINT32 ResetType;                   //重置方式
    UINT32 RefreshRewardType;           //奖励刷新方式
};
struct RecruitBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct Rising {
    UINT32 ID;                          //属性ID
    UINT32 Time;                        //切换时间
    UINT32 State;                       //切换状态
};
struct Robot {
    UINT32 GiftID;                      //角色ID
    UINT32 ArenaGroupID;                //竞技场组别
    UINT32 sex;                         //性别
    string name;                        //名字
    UINT32 roleLv;                      //角色等级
    UINT32 FightValue;                  //战斗力
    vector<int> Hero1;                  //武将1
    vector<int> Hero2;                  //武将2
    vector<int> Hero3;                  //武将3
    vector<int> Hero4;                  //武将4
    vector<int> Hero5;                  //武将5
    vector<int> Hero6;                  //武将6
    vector<int> SkillList;              //技能清单
    UINT32 ArenaShowLv;                 //竞技场展示等级
};
struct RobotEquip {
    UINT32 EquipKey;                    //装备Key
    vector<int> Equip1;                 //装备1
    vector<int> Equip2;                 //装备2
    vector<int> Equip3;                 //装备3
    vector<int> Equip4;                 //装备4
    vector<int> Equip5;                 //装备5
    vector<int> Equip6;                 //装备6
};
struct RoleBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct RoleExp {
    UINT32 Level;                       //等级
    UINT32 ExpNeed;                     //升级所需经验
    UINT32 ExpGetPerSpirit;             //行动力战斗获得经验
    UINT32 ExpGetPerStamina;            //耐力战斗获得经验
    UINT32 ExpGetTask;                  //每日任务获得经验
    UINT32 GoldGetTask;                 //每日任务获得银币
    UINT32 ExpSpiritHero;               //行动力战斗获得经验
    UINT32 ExpStaminaHero;              //耐力战斗获得经验
};
struct RoleNameBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct Scene {
    UINT32 ID;                          //剧情唯一ID
    UINT32 MonsterBornID;               //怪物出生ID
    vector<int> FightSetID;             //战斗ID
    UINT32 StarNum;                     //星星数量上限
    UINT32 DropBoxID;                   //掉落库ID
    UINT32 SpeDropBoxID;                //特殊掉落
    vector<int> SpeDropParam;           //特殊掉落参数
    vector<IdCount> NumGet;             //战斗铜币获得
    UINT32 SpiritNeed;                  //关卡消耗体力
    UINT32 FightMaxTimes;               //最大战斗次数
    vector<IdCount> FightResetDiamond;  //战斗重置价格
    UINT32 ExBox;                       //解锁宝箱
    UINT32 Type;                        //副本类型
};
struct SevenDayShop {
    UINT32 Day;                         //天数
    vector<int> Price;                  //售价
    vector<IdCount> Item;               //道具
};
struct SevenDayTask {
    UINT32 ID;                          //流水ID
    UINT32 Day;                         //天数
    vector<int> Task;                   //任务
};
struct ShopReset {
    UINT32 ID;                          //流水ID
    UINT32 ShopID;                      //商城类别
    UINT32 ResetTime;                   //重置次数
    vector<int> CostType;               //重置消耗
};
struct Shopitem {
    UINT32 ID;                          //商品ID
    UINT32 ShopID;                      //商城类别
    UINT32 ShopItemID;                  //商城道具ID
    vector<int> CostValue;              //货币兑换消耗1
    vector<IdCount> CostItem;           //道具兑换消耗2
    UINT32 CountCondition;              //道具刷新
    UINT32 Count;                       //可购买数量
    vector<int> Limit;                  //购买条件
};
struct SignPay {
    UINT32 ID;                          //流水ID
    UINT32 SignTime;                    //补签次数
    UINT32 Cost;                        //补签花费
};
struct SignReward {
    UINT32 ID;                          //流水ID
    UINT32 Days;                        //天数
    UINT32 Month;                       //月份
    vector<IdCount> ItemReward;         //道具奖励
    vector<int> VipTimes;               //VIP获得倍数
};
struct Skill {
    UINT32 ID;                          //技能ID
    UINT32 SkillType;                   //技能类型
    UINT32 TouchValue;                  //技能触发条件
    UINT32 TriggerPara;                 //技能触发参数
    UINT32 AttackType;                  //攻击类型
    UINT32 SkillEffectType;             //技能的效果类型
    UINT32 Country;                     //目标阵营
    UINT32 Range;                       //选取方式
    UINT32 Condition;                   //选取子类
    UINT32 Count;                       //目标数量
    vector<int> Element;                //技能元素
    vector<int> Segments;               //多段攻击
    UINT32 NextSkill;                   //嵌套技能ID
    UINT32 NestedSkillType;             //嵌套技能类型
    UINT32 NextHappenType;              //嵌套触发类型
    UINT32 NextHappenRatio;             //嵌套触发参数
    UINT32 SkillGroup;                  //技能组
};
struct SkillElement {
    UINT32 ElementID;                   //元素ID
    UINT32 Formula;                     //数值依据
    UINT32 BigType;                     //大类编号
    UINT32 SmallType;                   //小类编号
    UINT32 HappenType;                  //元素触发类型
    UINT32 HappenRatio;                 //元素触发参数
    UINT32 TriggerType;                 //触发类型
    UINT32 TriggerRatio;                //触发参数
    UINT32 LastRoundType;               //生效及计时方式
    UINT32 LastRound;                   //持续回合数
    UINT32 Overlay;                     //是否可叠加
    UINT32 Sequence;                    //替换权重
    UINT32 PersentDown;                 //百分比下限
    UINT32 PersentUp;                   //百分比上限
    UINT32 ValueDown;                   //数值下限
    UINT32 ValueUp;                     //数值上限
    UINT32 EffectType;                  //效果类型
};
struct SkillGift {
    UINT32 ID;                          //流水ID
    UINT32 GiftOpenLv;                  //解锁等级
    vector<int> SkillOpen;              //解锁技能
    vector<int> SkillReset;             //重置后保留技能
};
struct SkillPoint {
    UINT32 ID;                          //等级
    UINT32 Point;                       //点数
};
struct SkillTree {
    UINT32 ID;                          //流水ID
    UINT32 Sex;                         //性别
    UINT32 Gift;                        //天赋
    UINT32 PositionID;                  //位置编号
    UINT32 SkillType;                   //该位置技能类型
    UINT32 PrePositionID;               //前置位置
    vector<int> PostPositionID;         //后置位置
    vector<IdCount> SkillId;            //技能ID/所需等级
    vector<IdCount> SkillLvLimit;       //升级所需技能等级
    vector<int> CostPoint;              //消耗技能点
};
struct Skin {
    UINT32 ID;                          //坐骑ID
    string Name;                        //坐骑名称
    vector<IdCount> Open;               //解锁条件
};
struct SnowmanBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct SnowmanFlushTime {
    UINT32 ID;                          //流水ID
    UINT32 FlushTime;                   //刷新时间
};
struct SnowmanItem {
    UINT32 ID;                          //流水ID
    vector<IdCount> Item;               //需求道具
    vector<IdCount> Get;                //返还道具
};
struct SnowmanQuestion {
    UINT32 QuestionID;                  //问题ID
    UINT32 AnswerID;                    //正确答案ID
    UINT32 Type;                        //问题标签
};
struct SoulCost {
    UINT32 ID;                          //流水ID
    UINT32 CostType;                    //消耗类型
    UINT32 SkillLv;                     //技能等级
    UINT32 Resource;                    //消耗碎片
    vector<IdCount> Currency;           //消耗物品
    UINT32 RecycleResource;             //返还碎片
};
struct SoulSkill {
    UINT32 ID;                          //流水ID
    UINT32 SkillID;                     //技能ID
    UINT32 SkillLv;                     //技能等级
    vector<IdCount> Absolute;           //绝对值
    vector<IdCount> Percent;            //百分比
    UINT32 StartSkill;                  //开场技能
    UINT32 fight;                       //战斗力
    UINT32 HeroLv;                      //武将等级
    UINT32 GiftLv;                      //天赋等级
};
struct SpeBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    UINT32 Value;                       //值
    string Des;                         //备注
};
struct SpeBox {
    UINT32 ID;                          //ID
    UINT32 ItemBoxID;                   //物品库ID
    vector<IdCount> Item;               //道具及数量
    vector<int> Cost;                   //花费
    UINT32 Probablity;                  //出现概率
};
struct SpeRefCost {
    UINT32 BuyTime;                     //购买次数
    UINT32 Cost;                        //消耗元宝数量
};
struct SpecialShop {
    UINT32 ID;                          //流水ID
    vector<int> Lv;                     //等级
    UINT32 ItemBox1;                    //物品1
    UINT32 ItemBox2;                    //物品2
    UINT32 ItemBox3;                    //物品3
    UINT32 ItemBox4;                    //物品4
    UINT32 ItemBox5;                    //物品5
    UINT32 ItemBox6;                    //物品6
    UINT32 ItemBox7;                    //物品7
    UINT32 ItemBox8;                    //物品8
    UINT32 ItemBox9;                    //物品9
};
struct SpiritPurchase {
    UINT32 BuyTime;                     //体力购买次数
    UINT32 Cost;                        //购买价格(元宝）
    UINT32 Add;                         //增加体力
};
struct StaminaPurchase {
    UINT32 BuyTime;                     //耐力购买次数
    UINT32 Cost;                        //购买价格(元宝）
    UINT32 Add;                         //增加体力耐力
};
struct StaminaReward {
    UINT32 ID;                          //流水ID
    vector<int> Level;                  //玩家等级
    vector<int> LuckyValue;             //幸运值
    UINT32 ItemBoxID;                   //掉落库
};
struct StaminaRewardBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct StaminaRewardDropbox {
    UINT32 ID;                          //流水ID
    UINT32 DropboxID;                   //掉落库ID
    UINT32 ItemID;                      //道具ID
    UINT32 ItemNum;                     //道具数量
    UINT32 Probablity;                  //掉落概率
};
struct StarCondition {
    UINT32 Id;                          //流水Id
    UINT32 Type;                        //条件类型
    vector<int> Value1;                 //参数1
    vector<int> Value2;                 //参数2
};
struct SysSwitch {
    UINT32 ID;                          //ID
    string Key;                         //Key
    string Des;                         //注释
    UINT32 Default;                     //默认开关
};
struct Task {
    UINT32 TaskID;                      //任务ID
    vector<int> NextTask;               //后置任务
    UINT32 RoleLevel;                   //角色等级
    UINT32 TypeID;                      //任务条件
    vector<int> Parameters;             //任务参数
    vector<IdCount> RewardNum;          //数值奖励
    vector<IdCount> RewardItem;         //道具奖励
    UINT32 TaskClass;                   //任务大类
};
struct TaskType {
    UINT32 ID;                          //任务条件ID
    string Key;                         //Key
    UINT32 CompleteType;                //完成类型
    vector<int> OpenTime;               //开启时间
    string Des;                         //任务描述
};
struct ToolResult {
    UINT32 ID;                          //ID
    string Key;                         //Key
    UINT32 Rate;                        //倍率
    vector<int> DropItemSave;           //多倍掉落的页签
    string OpenTime;                    //开始时间
    UINT32 OpenSecond;                  //开始时间
    string CloseTime;                   //结束时间
    UINT32 CloseSecond;                 //结束时间
    string Talk;                        //文本内容
    UINT32 State;                       //开启状态
    string Des;                         //服务端标题
    UINT32 ToolsShow;                   //是否在工具中显示
    vector<int> ShowItemType;           //显示可配置道具类型
    UINT32 RemainOpenTime;              //提前显示活动的天数
};
struct Tower {
    UINT32 FightsSetId;                 //怪物组ID
    UINT32 TowerId;                     //层数Id
    UINT32 AvailableHeroNum;            //可上阵人数
    UINT32 MasterAvailable;             //主角可用
    UINT32 WinConditionId;              //通关条件
    UINT32 WinConditionValue;           //条件参数
    UINT32 BattleSceneId;               //战斗场景Id
};
struct TowerAward {
    UINT32 ID;                          //流水Id
    UINT32 TowerId;                     //层数Id
    vector<IdCount> WinAward;           //通关奖励展示
};
struct TowerNormalAward {
    UINT32 TowerId;                     //层数Id
    vector<IdCount> WinAward;           //通关奖励
    vector<IdCount> FirstWinAward;      //首次通关奖励
    vector<IdCount> VipAward;           //Vip额外奖励
};
struct TrialBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
struct TrialFirstMatching {
    UINT32 RoleLevel;                   //角色等级
    UINT32 MatchingLevelMin;            //首次匹配对手最低等级
    UINT32 MatchingLevelMax;            //首次匹配对手最高等级
};
struct TrialReward {
    UINT32 ID;                          //流水ID
    UINT32 Level;                       //主角等级
    UINT32 changePoint;                 //节点变化
    vector<IdCount> NumGet;             //货币奖励
    UINT32 DropBoxID;                   //宝箱奖励
    vector<IdCount> ItemGet;            //道具奖励
};
struct TrialRewardRead {
    UINT32 VIPLv;                       //VIP
    string Read;                        //掉落读表
};
struct TrialRewardVIP {
    UINT32 ID;                          //流水ID
    UINT32 Level;                       //主角等级
    UINT32 changePoint;                 //节点变化
    vector<IdCount> NumGet;             //货币奖励
    UINT32 DropBoxID;                   //宝箱奖励
    vector<IdCount> ItemGet;            //道具奖励
};
struct Upgrade {
    UINT32 Level;                       //主公等级
    UINT32 Spirit;                      //奖励体力
    UINT32 Stamina;                     //奖励耐力
};
struct Vip {
    UINT32 Level;                       //VIP等级
    UINT32 Pay;                         //累积消费
};
struct VipBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //注释
};
struct VipCount {
    UINT32 Level;                       //VIP等级
    vector<IdCount> Privilege;          //特权
};
struct VipFunction {
    UINT32 Level;                       //VIP等级
    UINT32 OpenRecruit;                 //功能-限时招募
};
struct VipGift {
    UINT32 Level;                       //VIP等级
    UINT32 FreeGiftID;                  //VIP等级礼包
    UINT32 DailyGiftID;                 //VIP每日奖励
    vector<IdCount> FreeGiftIDServer;   //VIP等级礼包内容
    vector<IdCount> DailyGiftIDServer;  //VIP每日奖励内容
    vector<IdCount> ShopIDServer;       //VIP限购礼包内容
};
struct WelfareBase {
    UINT32 ID;                          //流水ID
    string Key;                         //Key
    string Value;                       //值
    string Des;                         //备注
};
#pragma pack(pop)


extern KeyType ActiveRecruitKeys[3];

extern KeyType ActiveRecruitTimesKeys[7];

extern KeyType ActiveRecruitbaseKeys[4];

extern KeyType ActivityKeys[8];

extern KeyType ActivityBaseKeys[4];

extern KeyType ActivityFightKeys[5];

extern KeyType ActivityHeroKeys[2];

extern KeyType ActivityOpenKeys[3];

extern KeyType AddArtifactKeys[3];

extern KeyType AddRecruitKeys[3];

extern KeyType AllRankKeys[8];

extern KeyType ArenaKeys[14];

extern KeyType ArenaBaseKeys[4];

extern KeyType ArenaMatchKeys[9];

extern KeyType ArenaRewardKeys[4];

extern KeyType ArenaTopRewardKeys[3];

extern KeyType ArtifacRankBaseKeys[4];

extern KeyType ArtifactKeys[12];

extern KeyType ArtifactDropboxKeys[7];

extern KeyType ArtifactRankKeys[2];

extern KeyType ArtifactSlotKeys[3];

extern KeyType ArtifactStarKeys[15];

extern KeyType ArtifactStrengthenKeys[11];

extern KeyType ArtifactUpgradeKeys[6];

extern KeyType ArtifactWashKeys[5];

extern KeyType BackBaseKeys[4];

extern KeyType BackGiftKeys[5];

extern KeyType BackLoginKeys[4];

extern KeyType BackPayKeys[4];

extern KeyType BossChallengeCostKeys[2];

extern KeyType BossDropKeys[4];

extern KeyType BossRewardKeys[3];

extern KeyType BoxKeys[5];

extern KeyType BuffListKeys[3];

extern KeyType BuyDirectKeys[2];

extern KeyType CampActOpenKeys[2];

extern KeyType CampBaseKeys[4];

extern KeyType CampGrainKeys[9];

extern KeyType CampMineKeys[8];

extern KeyType CampMineProductionKeys[9];

extern KeyType CampMineScoreKeys[3];

extern KeyType CampMineUnlockKeys[3];

extern KeyType CampMineUpgradeKeys[6];

extern KeyType CampOfficeRankKeys[2];

extern KeyType CampOfficeRightKeys[8];

extern KeyType CampRewardKeys[4];

extern KeyType CampRoleRewardKeys[4];

extern KeyType CampThroughKeys[8];

extern KeyType CampThroughItemKeys[4];

extern KeyType CampTurntableKeys[7];

extern KeyType CampTurntableItemsKeys[4];

extern KeyType CampWarStreakRewardKeys[3];

extern KeyType ChannelBaseKeys[4];

extern KeyType ChapterKeys[7];

extern KeyType ChatBaseKeys[4];

extern KeyType ChatNoticeKeys[4];

extern KeyType CoinKeys[2];

extern KeyType CoinPurchaseKeys[3];

extern KeyType CostBaseKeys[5];

extern KeyType CostSumKeys[3];

extern KeyType DailyCostSumKeys[3];

extern KeyType DailyLoginKeys[3];

extern KeyType DailyPaySumKeys[3];

extern KeyType DailySumPayRewardKeys[5];

extern KeyType DepreFactorKeys[2];

extern KeyType DropOtherKeys[3];

extern KeyType DropboxKeys[7];

extern KeyType EmailKeys[6];

extern KeyType EquipKeys[21];

extern KeyType EquipBaseKeys[4];

extern KeyType EquipCoinCostKeys[2];

extern KeyType EquipMaterialGroupKeys[2];

extern KeyType EquipRecycleKeys[5];

extern KeyType EventRecruitKeys[2];

extern KeyType ExchangeKeys[5];

extern KeyType ExchangeBaseKeys[4];

extern KeyType FightSetKeys[19];

extern KeyType FormKeys[3];

extern KeyType FormRestrictKeys[3];

extern KeyType FragConvertKeys[2];

extern KeyType FundKeys[3];

extern KeyType FundBaseKeys[5];

extern KeyType GemKeys[5];

extern KeyType GrowingKeys[4];

extern KeyType GuildBaseKeys[4];

extern KeyType GuildBattleChatKeys[4];

extern KeyType GuildBattleCityKeys[7];

extern KeyType GuildBattleFightKeys[2];

extern KeyType GuildBattleLogKeys[4];

extern KeyType GuildBattlePersonRankKeys[2];

extern KeyType GuildBattleRankKeys[4];

extern KeyType GuildBattleSeverPersonRankKeys[2];

extern KeyType GuildChapterKeys[7];

extern KeyType GuildChapterFightKeys[5];

extern KeyType GuildDungeonKeys[8];

extern KeyType GuildDungeonAwardKeys[4];

extern KeyType GuildDungeonSpotKeys[5];

extern KeyType GuildFlagKeys[3];

extern KeyType GuildFlagLvKeys[4];

extern KeyType GuildLogKeys[4];

extern KeyType GuildLvKeys[24];

extern KeyType GuildMemberKeys[9];

extern KeyType HeroKeys[34];

extern KeyType HeroBaseKeys[4];

extern KeyType HeroExpKeys[6];

extern KeyType HeroGiftKeys[21];

extern KeyType HeroGiftPropKeys[6];

extern KeyType HeroGiftSkillKeys[5];

extern KeyType HeroRecycleKeys[4];

extern KeyType HeroSkinKeys[7];

extern KeyType HeroSoulKeys[2];

extern KeyType HeroStarKeys[10];

extern KeyType HeroStarRecycleKeys[4];

extern KeyType ItemKeys[21];

extern KeyType LevelUpRewardKeys[3];

extern KeyType LoginActRewardKeys[4];

extern KeyType LotteryKeys[5];

extern KeyType LotteryBaseKeys[4];

extern KeyType LuckyTurntableKeys[5];

extern KeyType LuckyTurntableBaseKeys[3];

extern KeyType LuckyTurntableItemsKeys[5];

extern KeyType LuckyTurntableValueKeys[3];

extern KeyType MailDoubleKeys[3];

extern KeyType MiscKeys[4];

extern KeyType MonsterBaseKeys[26];

extern KeyType MonsterPropertyKeys[16];

extern KeyType MonsterStrengthKeys[15];

extern KeyType MountsKeys[10];

extern KeyType MountsEquipKeys[4];

extern KeyType MountsEquipmentKeys[3];

extern KeyType MountsStarKeys[3];

extern KeyType MountsTrainKeys[14];

extern KeyType MysticshopKeys[3];

extern KeyType MysticshopRefreshCostKeys[2];

extern KeyType NewYearActivityKeys[5];

extern KeyType NewYearActivityBaseKeys[4];

extern KeyType NewYearRecycleKeys[4];

extern KeyType PayKeys[13];

extern KeyType PayRebateKeys[6];

extern KeyType PaySumKeys[3];

extern KeyType PeakArenaKeys[17];

extern KeyType PeakArenaBaseKeys[4];

extern KeyType PeakArenaFormatKeys[7];

extern KeyType PeakArenaMatchKeys[7];

extern KeyType PeakArenaRewardKeys[6];

extern KeyType PeakRobotKeys[16];

extern KeyType PeakUseKeys[4];

extern KeyType PowerSetKeys[5];

extern KeyType PushMessagesKeys[3];

extern KeyType QuenchPropKeys[5];

extern KeyType QuenchRandKeys[5];

extern KeyType QuestionPointsKeys[3];

extern KeyType QuestionRankKeys[3];

extern KeyType RankingKeys[8];

extern KeyType RecruitBaseKeys[4];

extern KeyType RisingKeys[3];

extern KeyType RobotKeys[14];

extern KeyType RobotEquipKeys[7];

extern KeyType RoleBaseKeys[4];

extern KeyType RoleExpKeys[8];

extern KeyType RoleNameBaseKeys[4];

extern KeyType SceneKeys[13];

extern KeyType SevenDayShopKeys[3];

extern KeyType SevenDayTaskKeys[3];

extern KeyType ShopResetKeys[4];

extern KeyType ShopitemKeys[8];

extern KeyType SignPayKeys[3];

extern KeyType SignRewardKeys[5];

extern KeyType SkillKeys[17];

extern KeyType SkillElementKeys[17];

extern KeyType SkillGiftKeys[4];

extern KeyType SkillPointKeys[2];

extern KeyType SkillTreeKeys[10];

extern KeyType SkinKeys[3];

extern KeyType SnowmanBaseKeys[4];

extern KeyType SnowmanFlushTimeKeys[2];

extern KeyType SnowmanItemKeys[3];

extern KeyType SnowmanQuestionKeys[3];

extern KeyType SoulCostKeys[6];

extern KeyType SoulSkillKeys[9];

extern KeyType SpeBaseKeys[4];

extern KeyType SpeBoxKeys[5];

extern KeyType SpeRefCostKeys[2];

extern KeyType SpecialShopKeys[11];

extern KeyType SpiritPurchaseKeys[3];

extern KeyType StaminaPurchaseKeys[3];

extern KeyType StaminaRewardKeys[4];

extern KeyType StaminaRewardBaseKeys[4];

extern KeyType StaminaRewardDropboxKeys[5];

extern KeyType StarConditionKeys[4];

extern KeyType SysSwitchKeys[4];

extern KeyType TaskKeys[8];

extern KeyType TaskTypeKeys[5];

extern KeyType ToolResultKeys[14];

extern KeyType TowerKeys[7];

extern KeyType TowerAwardKeys[3];

extern KeyType TowerNormalAwardKeys[4];

extern KeyType TrialBaseKeys[4];

extern KeyType TrialFirstMatchingKeys[3];

extern KeyType TrialRewardKeys[6];

extern KeyType TrialRewardReadKeys[2];

extern KeyType TrialRewardVIPKeys[6];

extern KeyType UpgradeKeys[3];

extern KeyType VipKeys[2];

extern KeyType VipBaseKeys[4];

extern KeyType VipCountKeys[2];

extern KeyType VipFunctionKeys[2];

extern KeyType VipGiftKeys[6];

extern KeyType WelfareBaseKeys[4];

typedef unordered_map<UINT32,ActiveRecruit> CActiveRecruitMap;
typedef unordered_map<UINT32,ActiveRecruitTimes> CActiveRecruitTimesMap;
typedef unordered_map<UINT32,ActiveRecruitbase> CActiveRecruitbaseMap;
typedef unordered_map<UINT32,Activity> CActivityMap;
typedef unordered_map<UINT32,ActivityBase> CActivityBaseMap;
typedef unordered_map<UINT32,ActivityFight> CActivityFightMap;
typedef unordered_map<UINT32,ActivityHero> CActivityHeroMap;
typedef unordered_map<UINT32,ActivityOpen> CActivityOpenMap;
typedef unordered_map<UINT32,AddArtifact> CAddArtifactMap;
typedef unordered_map<UINT32,AddRecruit> CAddRecruitMap;
typedef unordered_map<UINT32,AllRank> CAllRankMap;
typedef unordered_map<UINT32,Arena> CArenaMap;
typedef unordered_map<UINT32,ArenaBase> CArenaBaseMap;
typedef unordered_map<UINT32,ArenaMatch> CArenaMatchMap;
typedef unordered_map<UINT32,ArenaReward> CArenaRewardMap;
typedef unordered_map<UINT32,ArenaTopReward> CArenaTopRewardMap;
typedef unordered_map<UINT32,ArtifacRankBase> CArtifacRankBaseMap;
typedef unordered_map<UINT32,Artifact> CArtifactMap;
typedef unordered_map<UINT32,ArtifactDropbox> CArtifactDropboxMap;
typedef unordered_map<UINT32,ArtifactRank> CArtifactRankMap;
typedef unordered_map<UINT32,ArtifactSlot> CArtifactSlotMap;
typedef unordered_map<UINT32,ArtifactStar> CArtifactStarMap;
typedef unordered_map<UINT32,ArtifactStrengthen> CArtifactStrengthenMap;
typedef unordered_map<UINT32,ArtifactUpgrade> CArtifactUpgradeMap;
typedef unordered_map<UINT32,ArtifactWash> CArtifactWashMap;
typedef unordered_map<UINT32,BackBase> CBackBaseMap;
typedef unordered_map<UINT32,BackGift> CBackGiftMap;
typedef unordered_map<UINT32,BackLogin> CBackLoginMap;
typedef unordered_map<UINT32,BackPay> CBackPayMap;
typedef unordered_map<UINT32,BossChallengeCost> CBossChallengeCostMap;
typedef unordered_map<UINT32,BossDrop> CBossDropMap;
typedef unordered_map<UINT32,BossReward> CBossRewardMap;
typedef unordered_map<UINT32,Box> CBoxMap;
typedef unordered_map<UINT32,BuffList> CBuffListMap;
typedef unordered_map<UINT32,BuyDirect> CBuyDirectMap;
typedef unordered_map<UINT32,CampActOpen> CCampActOpenMap;
typedef unordered_map<UINT32,CampBase> CCampBaseMap;
typedef unordered_map<UINT32,CampGrain> CCampGrainMap;
typedef unordered_map<UINT32,CampMine> CCampMineMap;
typedef unordered_map<UINT32,CampMineProduction> CCampMineProductionMap;
typedef unordered_map<UINT32,CampMineScore> CCampMineScoreMap;
typedef unordered_map<UINT32,CampMineUnlock> CCampMineUnlockMap;
typedef unordered_map<UINT32,CampMineUpgrade> CCampMineUpgradeMap;
typedef unordered_map<UINT32,CampOfficeRank> CCampOfficeRankMap;
typedef unordered_map<UINT32,CampOfficeRight> CCampOfficeRightMap;
typedef unordered_map<UINT32,CampReward> CCampRewardMap;
typedef unordered_map<UINT32,CampRoleReward> CCampRoleRewardMap;
typedef unordered_map<UINT32,CampThrough> CCampThroughMap;
typedef unordered_map<UINT32,CampThroughItem> CCampThroughItemMap;
typedef unordered_map<UINT32,CampTurntable> CCampTurntableMap;
typedef unordered_map<UINT32,CampTurntableItems> CCampTurntableItemsMap;
typedef unordered_map<UINT32,CampWarStreakReward> CCampWarStreakRewardMap;
typedef unordered_map<UINT32,ChannelBase> CChannelBaseMap;
typedef unordered_map<UINT32,Chapter> CChapterMap;
typedef unordered_map<UINT32,ChatBase> CChatBaseMap;
typedef unordered_map<UINT32,ChatNotice> CChatNoticeMap;
typedef unordered_map<UINT32,Coin> CCoinMap;
typedef unordered_map<UINT32,CoinPurchase> CCoinPurchaseMap;
typedef unordered_map<UINT32,CostBase> CCostBaseMap;
typedef unordered_map<UINT32,CostSum> CCostSumMap;
typedef unordered_map<UINT32,DailyCostSum> CDailyCostSumMap;
typedef unordered_map<UINT32,DailyLogin> CDailyLoginMap;
typedef unordered_map<UINT32,DailyPaySum> CDailyPaySumMap;
typedef unordered_map<UINT32,DailySumPayReward> CDailySumPayRewardMap;
typedef unordered_map<UINT32,DepreFactor> CDepreFactorMap;
typedef unordered_map<UINT32,DropOther> CDropOtherMap;
typedef unordered_map<UINT32,Dropbox> CDropboxMap;
typedef unordered_map<UINT32,Email> CEmailMap;
typedef unordered_map<UINT32,Equip> CEquipMap;
typedef unordered_map<UINT32,EquipBase> CEquipBaseMap;
typedef unordered_map<UINT32,EquipCoinCost> CEquipCoinCostMap;
typedef unordered_map<UINT32,EquipMaterialGroup> CEquipMaterialGroupMap;
typedef unordered_map<UINT32,EquipRecycle> CEquipRecycleMap;
typedef unordered_map<UINT32,EventRecruit> CEventRecruitMap;
typedef unordered_map<UINT32,Exchange> CExchangeMap;
typedef unordered_map<UINT32,ExchangeBase> CExchangeBaseMap;
typedef unordered_map<UINT32,FightSet> CFightSetMap;
typedef unordered_map<UINT32,Form> CFormMap;
typedef unordered_map<UINT32,FormRestrict> CFormRestrictMap;
typedef unordered_map<UINT32,FragConvert> CFragConvertMap;
typedef unordered_map<UINT32,Fund> CFundMap;
typedef unordered_map<UINT32,FundBase> CFundBaseMap;
typedef unordered_map<UINT32,Gem> CGemMap;
typedef unordered_map<UINT32,Growing> CGrowingMap;
typedef unordered_map<UINT32,GuildBase> CGuildBaseMap;
typedef unordered_map<UINT32,GuildBattleChat> CGuildBattleChatMap;
typedef unordered_map<UINT32,GuildBattleCity> CGuildBattleCityMap;
typedef unordered_map<UINT32,GuildBattleFight> CGuildBattleFightMap;
typedef unordered_map<UINT32,GuildBattleLog> CGuildBattleLogMap;
typedef unordered_map<UINT32,GuildBattlePersonRank> CGuildBattlePersonRankMap;
typedef unordered_map<UINT32,GuildBattleRank> CGuildBattleRankMap;
typedef unordered_map<UINT32,GuildBattleSeverPersonRank> CGuildBattleSeverPersonRankMap;
typedef unordered_map<UINT32,GuildChapter> CGuildChapterMap;
typedef unordered_map<UINT32,GuildChapterFight> CGuildChapterFightMap;
typedef unordered_map<UINT32,GuildDungeon> CGuildDungeonMap;
typedef unordered_map<UINT32,GuildDungeonAward> CGuildDungeonAwardMap;
typedef unordered_map<UINT32,GuildDungeonSpot> CGuildDungeonSpotMap;
typedef unordered_map<UINT32,GuildFlag> CGuildFlagMap;
typedef unordered_map<UINT32,GuildFlagLv> CGuildFlagLvMap;
typedef unordered_map<UINT32,GuildLog> CGuildLogMap;
typedef unordered_map<UINT32,GuildLv> CGuildLvMap;
typedef unordered_map<UINT32,GuildMember> CGuildMemberMap;
typedef unordered_map<UINT32,Hero> CHeroMap;
typedef unordered_map<UINT32,HeroBase> CHeroBaseMap;
typedef unordered_map<UINT32,HeroExp> CHeroExpMap;
typedef unordered_map<UINT32,HeroGift> CHeroGiftMap;
typedef unordered_map<UINT32,HeroGiftProp> CHeroGiftPropMap;
typedef unordered_map<UINT32,HeroGiftSkill> CHeroGiftSkillMap;
typedef unordered_map<UINT32,HeroRecycle> CHeroRecycleMap;
typedef unordered_map<UINT32,HeroSkin> CHeroSkinMap;
typedef unordered_map<UINT32,HeroSoul> CHeroSoulMap;
typedef unordered_map<UINT32,HeroStar> CHeroStarMap;
typedef unordered_map<UINT32,HeroStarRecycle> CHeroStarRecycleMap;
typedef unordered_map<UINT32,Item> CItemMap;
typedef unordered_map<UINT32,LevelUpReward> CLevelUpRewardMap;
typedef unordered_map<UINT32,LoginActReward> CLoginActRewardMap;
typedef unordered_map<UINT32,Lottery> CLotteryMap;
typedef unordered_map<UINT32,LotteryBase> CLotteryBaseMap;
typedef unordered_map<UINT32,LuckyTurntable> CLuckyTurntableMap;
typedef unordered_map<UINT32,LuckyTurntableBase> CLuckyTurntableBaseMap;
typedef unordered_map<UINT32,LuckyTurntableItems> CLuckyTurntableItemsMap;
typedef unordered_map<UINT32,LuckyTurntableValue> CLuckyTurntableValueMap;
typedef unordered_map<UINT32,MailDouble> CMailDoubleMap;
typedef unordered_map<UINT32,Misc> CMiscMap;
typedef unordered_map<UINT32,MonsterBase> CMonsterBaseMap;
typedef unordered_map<UINT32,MonsterProperty> CMonsterPropertyMap;
typedef unordered_map<UINT32,MonsterStrength> CMonsterStrengthMap;
typedef unordered_map<UINT32,Mounts> CMountsMap;
typedef unordered_map<UINT32,MountsEquip> CMountsEquipMap;
typedef unordered_map<UINT32,MountsEquipment> CMountsEquipmentMap;
typedef unordered_map<UINT32,MountsStar> CMountsStarMap;
typedef unordered_map<UINT32,MountsTrain> CMountsTrainMap;
typedef unordered_map<UINT32,Mysticshop> CMysticshopMap;
typedef unordered_map<UINT32,MysticshopRefreshCost> CMysticshopRefreshCostMap;
typedef unordered_map<UINT32,NewYearActivity> CNewYearActivityMap;
typedef unordered_map<UINT32,NewYearActivityBase> CNewYearActivityBaseMap;
typedef unordered_map<UINT32,NewYearRecycle> CNewYearRecycleMap;
typedef unordered_map<UINT32,Pay> CPayMap;
typedef unordered_map<UINT32,PayRebate> CPayRebateMap;
typedef unordered_map<UINT32,PaySum> CPaySumMap;
typedef unordered_map<UINT32,PeakArena> CPeakArenaMap;
typedef unordered_map<UINT32,PeakArenaBase> CPeakArenaBaseMap;
typedef unordered_map<UINT32,PeakArenaFormat> CPeakArenaFormatMap;
typedef unordered_map<UINT32,PeakArenaMatch> CPeakArenaMatchMap;
typedef unordered_map<UINT32,PeakArenaReward> CPeakArenaRewardMap;
typedef unordered_map<UINT32,PeakRobot> CPeakRobotMap;
typedef unordered_map<UINT32,PeakUse> CPeakUseMap;
typedef unordered_map<UINT32,PowerSet> CPowerSetMap;
typedef unordered_map<UINT32,PushMessages> CPushMessagesMap;
typedef unordered_map<UINT32,QuenchProp> CQuenchPropMap;
typedef unordered_map<UINT32,QuenchRand> CQuenchRandMap;
typedef unordered_map<UINT32,QuestionPoints> CQuestionPointsMap;
typedef unordered_map<UINT32,QuestionRank> CQuestionRankMap;
typedef unordered_map<UINT32,Ranking> CRankingMap;
typedef unordered_map<UINT32,RecruitBase> CRecruitBaseMap;
typedef unordered_map<UINT32,Rising> CRisingMap;
typedef unordered_map<UINT32,Robot> CRobotMap;
typedef unordered_map<UINT32,RobotEquip> CRobotEquipMap;
typedef unordered_map<UINT32,RoleBase> CRoleBaseMap;
typedef unordered_map<UINT32,RoleExp> CRoleExpMap;
typedef unordered_map<UINT32,RoleNameBase> CRoleNameBaseMap;
typedef unordered_map<UINT32,Scene> CSceneMap;
typedef unordered_map<UINT32,SevenDayShop> CSevenDayShopMap;
typedef unordered_map<UINT32,SevenDayTask> CSevenDayTaskMap;
typedef unordered_map<UINT32,ShopReset> CShopResetMap;
typedef unordered_map<UINT32,Shopitem> CShopitemMap;
typedef unordered_map<UINT32,SignPay> CSignPayMap;
typedef unordered_map<UINT32,SignReward> CSignRewardMap;
typedef unordered_map<UINT32,Skill> CSkillMap;
typedef unordered_map<UINT32,SkillElement> CSkillElementMap;
typedef unordered_map<UINT32,SkillGift> CSkillGiftMap;
typedef unordered_map<UINT32,SkillPoint> CSkillPointMap;
typedef unordered_map<UINT32,SkillTree> CSkillTreeMap;
typedef unordered_map<UINT32,Skin> CSkinMap;
typedef unordered_map<UINT32,SnowmanBase> CSnowmanBaseMap;
typedef unordered_map<UINT32,SnowmanFlushTime> CSnowmanFlushTimeMap;
typedef unordered_map<UINT32,SnowmanItem> CSnowmanItemMap;
typedef unordered_map<UINT32,SnowmanQuestion> CSnowmanQuestionMap;
typedef unordered_map<UINT32,SoulCost> CSoulCostMap;
typedef unordered_map<UINT32,SoulSkill> CSoulSkillMap;
typedef unordered_map<UINT32,SpeBase> CSpeBaseMap;
typedef unordered_map<UINT32,SpeBox> CSpeBoxMap;
typedef unordered_map<UINT32,SpeRefCost> CSpeRefCostMap;
typedef unordered_map<UINT32,SpecialShop> CSpecialShopMap;
typedef unordered_map<UINT32,SpiritPurchase> CSpiritPurchaseMap;
typedef unordered_map<UINT32,StaminaPurchase> CStaminaPurchaseMap;
typedef unordered_map<UINT32,StaminaReward> CStaminaRewardMap;
typedef unordered_map<UINT32,StaminaRewardBase> CStaminaRewardBaseMap;
typedef unordered_map<UINT32,StaminaRewardDropbox> CStaminaRewardDropboxMap;
typedef unordered_map<UINT32,StarCondition> CStarConditionMap;
typedef unordered_map<UINT32,SysSwitch> CSysSwitchMap;
typedef unordered_map<UINT32,Task> CTaskMap;
typedef unordered_map<UINT32,TaskType> CTaskTypeMap;
typedef unordered_map<UINT32,ToolResult> CToolResultMap;
typedef unordered_map<UINT32,Tower> CTowerMap;
typedef unordered_map<UINT32,TowerAward> CTowerAwardMap;
typedef unordered_map<UINT32,TowerNormalAward> CTowerNormalAwardMap;
typedef unordered_map<UINT32,TrialBase> CTrialBaseMap;
typedef unordered_map<UINT32,TrialFirstMatching> CTrialFirstMatchingMap;
typedef unordered_map<UINT32,TrialReward> CTrialRewardMap;
typedef unordered_map<UINT32,TrialRewardRead> CTrialRewardReadMap;
typedef unordered_map<UINT32,TrialRewardVIP> CTrialRewardVIPMap;
typedef unordered_map<UINT32,Upgrade> CUpgradeMap;
typedef unordered_map<UINT32,Vip> CVipMap;
typedef unordered_map<UINT32,VipBase> CVipBaseMap;
typedef unordered_map<UINT32,VipCount> CVipCountMap;
typedef unordered_map<UINT32,VipFunction> CVipFunctionMap;
typedef unordered_map<UINT32,VipGift> CVipGiftMap;
typedef unordered_map<UINT32,WelfareBase> CWelfareBaseMap;
typedef unordered_map<UINT32,unordered_map<UINT32,ArtifactStar>> CArtifactStarVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,ArtifactStrengthen>> CArtifactStrengthenVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,BossDrop>> CBossDropVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Box>> CBoxVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,CampMineProduction>> CCampMineProductionVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,CampReward>> CCampRewardVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,CampThroughItem>> CCampThroughItemVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,DailySumPayReward>> CDailySumPayRewardVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Dropbox>> CDropboxVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Exchange>> CExchangeVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Growing>> CGrowingVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,GuildChapterFight>> CGuildChapterFightVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,GuildDungeonAward>> CGuildDungeonAwardVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,HeroExp>> CHeroExpVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,HeroGiftSkill>> CHeroGiftSkillVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,HeroRecycle>> CHeroRecycleVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,HeroStar>> CHeroStarVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,HeroStarRecycle>> CHeroStarRecycleVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,LoginActReward>> CLoginActRewardVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,MonsterProperty>> CMonsterPropertyVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Robot>> CRobotVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,SevenDayTask>> CSevenDayTaskVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,ShopReset>> CShopResetVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Shopitem>> CShopitemVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,SignReward>> CSignRewardVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,SkillTree>> CSkillTreeVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,SoulCost>> CSoulCostVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,SoulSkill>> CSoulSkillVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,SpeBox>> CSpeBoxVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,StaminaRewardDropbox>> CStaminaRewardDropboxVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Task>> CTaskVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,Tower>> CTowerVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,TrialReward>> CTrialRewardVectorMap;
typedef unordered_map<UINT32,unordered_map<UINT32,TrialRewardVIP>> CTrialRewardVIPVectorMap;
class XmlConfig :public noncopy
{
private:
    CActiveRecruitMap ActiveRecruitMap;
    CActiveRecruitTimesMap ActiveRecruitTimesMap;
    CActiveRecruitbaseMap ActiveRecruitbaseMap;
    CActivityMap ActivityMap;
    CActivityBaseMap ActivityBaseMap;
    CActivityFightMap ActivityFightMap;
    CActivityHeroMap ActivityHeroMap;
    CActivityOpenMap ActivityOpenMap;
    CAddArtifactMap AddArtifactMap;
    CAddRecruitMap AddRecruitMap;
    CAllRankMap AllRankMap;
    CArenaMap ArenaMap;
    CArenaBaseMap ArenaBaseMap;
    CArenaMatchMap ArenaMatchMap;
    CArenaRewardMap ArenaRewardMap;
    CArenaTopRewardMap ArenaTopRewardMap;
    CArtifacRankBaseMap ArtifacRankBaseMap;
    CArtifactMap ArtifactMap;
    CArtifactDropboxMap ArtifactDropboxMap;
    CArtifactRankMap ArtifactRankMap;
    CArtifactSlotMap ArtifactSlotMap;
    CArtifactStarMap ArtifactStarMap;
    CArtifactStrengthenMap ArtifactStrengthenMap;
    CArtifactUpgradeMap ArtifactUpgradeMap;
    CArtifactWashMap ArtifactWashMap;
    CBackBaseMap BackBaseMap;
    CBackGiftMap BackGiftMap;
    CBackLoginMap BackLoginMap;
    CBackPayMap BackPayMap;
    CBossChallengeCostMap BossChallengeCostMap;
    CBossDropMap BossDropMap;
    CBossRewardMap BossRewardMap;
    CBoxMap BoxMap;
    CBuffListMap BuffListMap;
    CBuyDirectMap BuyDirectMap;
    CCampActOpenMap CampActOpenMap;
    CCampBaseMap CampBaseMap;
    CCampGrainMap CampGrainMap;
    CCampMineMap CampMineMap;
    CCampMineProductionMap CampMineProductionMap;
    CCampMineScoreMap CampMineScoreMap;
    CCampMineUnlockMap CampMineUnlockMap;
    CCampMineUpgradeMap CampMineUpgradeMap;
    CCampOfficeRankMap CampOfficeRankMap;
    CCampOfficeRightMap CampOfficeRightMap;
    CCampRewardMap CampRewardMap;
    CCampRoleRewardMap CampRoleRewardMap;
    CCampThroughMap CampThroughMap;
    CCampThroughItemMap CampThroughItemMap;
    CCampTurntableMap CampTurntableMap;
    CCampTurntableItemsMap CampTurntableItemsMap;
    CCampWarStreakRewardMap CampWarStreakRewardMap;
    CChannelBaseMap ChannelBaseMap;
    CChapterMap ChapterMap;
    CChatBaseMap ChatBaseMap;
    CChatNoticeMap ChatNoticeMap;
    CCoinMap CoinMap;
    CCoinPurchaseMap CoinPurchaseMap;
    CCostBaseMap CostBaseMap;
    CCostSumMap CostSumMap;
    CDailyCostSumMap DailyCostSumMap;
    CDailyLoginMap DailyLoginMap;
    CDailyPaySumMap DailyPaySumMap;
    CDailySumPayRewardMap DailySumPayRewardMap;
    CDepreFactorMap DepreFactorMap;
    CDropOtherMap DropOtherMap;
    CDropboxMap DropboxMap;
    CEmailMap EmailMap;
    CEquipMap EquipMap;
    CEquipBaseMap EquipBaseMap;
    CEquipCoinCostMap EquipCoinCostMap;
    CEquipMaterialGroupMap EquipMaterialGroupMap;
    CEquipRecycleMap EquipRecycleMap;
    CEventRecruitMap EventRecruitMap;
    CExchangeMap ExchangeMap;
    CExchangeBaseMap ExchangeBaseMap;
    CFightSetMap FightSetMap;
    CFormMap FormMap;
    CFormRestrictMap FormRestrictMap;
    CFragConvertMap FragConvertMap;
    CFundMap FundMap;
    CFundBaseMap FundBaseMap;
    CGemMap GemMap;
    CGrowingMap GrowingMap;
    CGuildBaseMap GuildBaseMap;
    CGuildBattleChatMap GuildBattleChatMap;
    CGuildBattleCityMap GuildBattleCityMap;
    CGuildBattleFightMap GuildBattleFightMap;
    CGuildBattleLogMap GuildBattleLogMap;
    CGuildBattlePersonRankMap GuildBattlePersonRankMap;
    CGuildBattleRankMap GuildBattleRankMap;
    CGuildBattleSeverPersonRankMap GuildBattleSeverPersonRankMap;
    CGuildChapterMap GuildChapterMap;
    CGuildChapterFightMap GuildChapterFightMap;
    CGuildDungeonMap GuildDungeonMap;
    CGuildDungeonAwardMap GuildDungeonAwardMap;
    CGuildDungeonSpotMap GuildDungeonSpotMap;
    CGuildFlagMap GuildFlagMap;
    CGuildFlagLvMap GuildFlagLvMap;
    CGuildLogMap GuildLogMap;
    CGuildLvMap GuildLvMap;
    CGuildMemberMap GuildMemberMap;
    CHeroMap HeroMap;
    CHeroBaseMap HeroBaseMap;
    CHeroExpMap HeroExpMap;
    CHeroGiftMap HeroGiftMap;
    CHeroGiftPropMap HeroGiftPropMap;
    CHeroGiftSkillMap HeroGiftSkillMap;
    CHeroRecycleMap HeroRecycleMap;
    CHeroSkinMap HeroSkinMap;
    CHeroSoulMap HeroSoulMap;
    CHeroStarMap HeroStarMap;
    CHeroStarRecycleMap HeroStarRecycleMap;
    CItemMap ItemMap;
    CLevelUpRewardMap LevelUpRewardMap;
    CLoginActRewardMap LoginActRewardMap;
    CLotteryMap LotteryMap;
    CLotteryBaseMap LotteryBaseMap;
    CLuckyTurntableMap LuckyTurntableMap;
    CLuckyTurntableBaseMap LuckyTurntableBaseMap;
    CLuckyTurntableItemsMap LuckyTurntableItemsMap;
    CLuckyTurntableValueMap LuckyTurntableValueMap;
    CMailDoubleMap MailDoubleMap;
    CMiscMap MiscMap;
    CMonsterBaseMap MonsterBaseMap;
    CMonsterPropertyMap MonsterPropertyMap;
    CMonsterStrengthMap MonsterStrengthMap;
    CMountsMap MountsMap;
    CMountsEquipMap MountsEquipMap;
    CMountsEquipmentMap MountsEquipmentMap;
    CMountsStarMap MountsStarMap;
    CMountsTrainMap MountsTrainMap;
    CMysticshopMap MysticshopMap;
    CMysticshopRefreshCostMap MysticshopRefreshCostMap;
    CNewYearActivityMap NewYearActivityMap;
    CNewYearActivityBaseMap NewYearActivityBaseMap;
    CNewYearRecycleMap NewYearRecycleMap;
    CPayMap PayMap;
    CPayRebateMap PayRebateMap;
    CPaySumMap PaySumMap;
    CPeakArenaMap PeakArenaMap;
    CPeakArenaBaseMap PeakArenaBaseMap;
    CPeakArenaFormatMap PeakArenaFormatMap;
    CPeakArenaMatchMap PeakArenaMatchMap;
    CPeakArenaRewardMap PeakArenaRewardMap;
    CPeakRobotMap PeakRobotMap;
    CPeakUseMap PeakUseMap;
    CPowerSetMap PowerSetMap;
    CPushMessagesMap PushMessagesMap;
    CQuenchPropMap QuenchPropMap;
    CQuenchRandMap QuenchRandMap;
    CQuestionPointsMap QuestionPointsMap;
    CQuestionRankMap QuestionRankMap;
    CRankingMap RankingMap;
    CRecruitBaseMap RecruitBaseMap;
    CRisingMap RisingMap;
    CRobotMap RobotMap;
    CRobotEquipMap RobotEquipMap;
    CRoleBaseMap RoleBaseMap;
    CRoleExpMap RoleExpMap;
    CRoleNameBaseMap RoleNameBaseMap;
    CSceneMap SceneMap;
    CSevenDayShopMap SevenDayShopMap;
    CSevenDayTaskMap SevenDayTaskMap;
    CShopResetMap ShopResetMap;
    CShopitemMap ShopitemMap;
    CSignPayMap SignPayMap;
    CSignRewardMap SignRewardMap;
    CSkillMap SkillMap;
    CSkillElementMap SkillElementMap;
    CSkillGiftMap SkillGiftMap;
    CSkillPointMap SkillPointMap;
    CSkillTreeMap SkillTreeMap;
    CSkinMap SkinMap;
    CSnowmanBaseMap SnowmanBaseMap;
    CSnowmanFlushTimeMap SnowmanFlushTimeMap;
    CSnowmanItemMap SnowmanItemMap;
    CSnowmanQuestionMap SnowmanQuestionMap;
    CSoulCostMap SoulCostMap;
    CSoulSkillMap SoulSkillMap;
    CSpeBaseMap SpeBaseMap;
    CSpeBoxMap SpeBoxMap;
    CSpeRefCostMap SpeRefCostMap;
    CSpecialShopMap SpecialShopMap;
    CSpiritPurchaseMap SpiritPurchaseMap;
    CStaminaPurchaseMap StaminaPurchaseMap;
    CStaminaRewardMap StaminaRewardMap;
    CStaminaRewardBaseMap StaminaRewardBaseMap;
    CStaminaRewardDropboxMap StaminaRewardDropboxMap;
    CStarConditionMap StarConditionMap;
    CSysSwitchMap SysSwitchMap;
    CTaskMap TaskMap;
    CTaskTypeMap TaskTypeMap;
    CToolResultMap ToolResultMap;
    CTowerMap TowerMap;
    CTowerAwardMap TowerAwardMap;
    CTowerNormalAwardMap TowerNormalAwardMap;
    CTrialBaseMap TrialBaseMap;
    CTrialFirstMatchingMap TrialFirstMatchingMap;
    CTrialRewardMap TrialRewardMap;
    CTrialRewardReadMap TrialRewardReadMap;
    CTrialRewardVIPMap TrialRewardVIPMap;
    CUpgradeMap UpgradeMap;
    CVipMap VipMap;
    CVipBaseMap VipBaseMap;
    CVipCountMap VipCountMap;
    CVipFunctionMap VipFunctionMap;
    CVipGiftMap VipGiftMap;
    CWelfareBaseMap WelfareBaseMap;
    CArtifactStarVectorMap ArtifactStarMapMap;
    CArtifactStrengthenVectorMap ArtifactStrengthenMapMap;
    CBossDropVectorMap BossDropMapMap;
    CBoxVectorMap BoxMapMap;
    CCampMineProductionVectorMap CampMineProductionMapMap;
    CCampRewardVectorMap CampRewardMapMap;
    CCampThroughItemVectorMap CampThroughItemMapMap;
    CDailySumPayRewardVectorMap DailySumPayRewardMapMap;
    CDropboxVectorMap DropboxMapMap;
    CExchangeVectorMap ExchangeMapMap;
    CGrowingVectorMap GrowingMapMap;
    CGuildChapterFightVectorMap GuildChapterFightMapMap;
    CGuildDungeonAwardVectorMap GuildDungeonAwardMapMap;
    CHeroExpVectorMap HeroExpMapMap;
    CHeroGiftSkillVectorMap HeroGiftSkillMapMap;
    CHeroRecycleVectorMap HeroRecycleMapMap;
    CHeroStarVectorMap HeroStarMapMap;
    CHeroStarRecycleVectorMap HeroStarRecycleMapMap;
    CLoginActRewardVectorMap LoginActRewardMapMap;
    CMonsterPropertyVectorMap MonsterPropertyMapMap;
    CRobotVectorMap RobotMapMap;
    CSevenDayTaskVectorMap SevenDayTaskMapMap;
    CShopResetVectorMap ShopResetMapMap;
    CShopitemVectorMap ShopitemMapMap;
    CSignRewardVectorMap SignRewardMapMap;
    CSkillTreeVectorMap SkillTreeMapMap;
    CSoulCostVectorMap SoulCostMapMap;
    CSoulSkillVectorMap SoulSkillMapMap;
    CSpeBoxVectorMap SpeBoxMapMap;
    CStaminaRewardDropboxVectorMap StaminaRewardDropboxMapMap;
    CTaskVectorMap TaskMapMap;
    CTowerVectorMap TowerMapMap;
    CTrialRewardVectorMap TrialRewardMapMap;
    CTrialRewardVIPVectorMap TrialRewardVIPMapMap;
    string cpath;
    static XmlConfig* instance;
    XmlConfig();
    XmlConfig(const string &path);
public:
    void setPath(const string &path)
    {
        cpath = path;
        if(access(path.c_str(),0)==1)
        {
            cout<<"config dir not exists"<<endl;
            exit(1);
        }
    }
    
    void writeConfig(const string &file,const string& content)
    {
        string pfile=cpath+file;
        if(access(pfile.c_str(),0)==1)
        {
            cout<<"config file not exists"<<endl;
            return;
        }
        std::fstream fs(pfile.c_str(),ios_base::trunc|ios_base::out);
        fs<<content.c_str();
        fs.close();
    }
    
    static XmlConfig& Instance();
    BOOL LoadFile (const char*file);
    BOOL
    LoadAll();
    UINT64 UUID();
    template<class T>
    BOOL InitMapMap(UINT32 koffset1,UINT32 koffset2,unordered_map<UINT32,T> &smap,unordered_map<UINT32,unordered_map<UINT32,T>> &vecMap);
    template<class T>
    BOOL
    LoadCommon(const char *file, const KeyType *keys, UINT32 keylen,
            unordered_map<UINT32, T> &t1);
    FLOAT getCoefficient(UINT32 c)
    {
        auto cf=getHeroBase(c);
        if(cf!=nullptr)
        {
            return cf->Value;
        }
        return 0.0;
    }
    
    UINT32 getInnerCoinType(UINT32 type)
    {
         auto coin=getCostBase(type);
         if(coin!=nullptr)
         {
             return coin->Value;
         }
         return 0;
    }
    
    vector<Mysticshop> getRandomShopItems(UINT16 count)
    {
        vector<Mysticshop> items;
        static  vector<UINT32> keys;
        auto &shop_items=getMysticshopMap();
        if(keys.size()==0)
        {
            for(auto &shop:shop_items)
            {
                keys.push_back(shop.second.ShopItemID);
            }
        }
        random_shuffle(keys.begin(),keys.end());
        if(keys.size()>count)
        {
            for(UINT16 i=0;i<count;++i)
            {
                auto shop=getMysticshop(keys[i]);
                items.push_back(*shop);
            }
        }
        return items;
    }
    
    //uType 1 int 2 string 3 vector<int> 4 vector<string>
    template<typename TOUT>
    const void getRoleBase(UINT32 unID, UINT8 uType, TOUT *t)
    {
        const CRoleBaseMap::iterator &it=RoleBaseMap.find(unID);
       if(it!=RoleBaseMap.end())
       {
           UINT32 *p=nullptr;
           string *sp=nullptr;
           vector<INT32> *vp=nullptr;
           vector<string> *vsp=nullptr;
		   vector<IdCount> *vid=nullptr;
           switch(uType)
           {
               case 1:
                   p=(UINT32*)t;
                   *p=atol(it->second.Value.c_str());
                   break;
               case 2:
                   sp=(string*)t;
                   sp->assign(it->second.Value);
                   break;
               case 3:
                   vp=(vector<INT32>*)t;
                   SplitStringInt(it->second.Value.c_str(),',',*vp);
                   break;
               case 4:
                   vsp=(vector<string>*)t;
                   SplitString(it->second.Value.c_str(),',',*vsp);
                   break;
               case 5:
                   vid=(vector<IdCount>*)t;
                   SplitIdCount(it->second.Value.c_str(),',',':',*vid);
                   break;
               default:break;
           }
       }
    }
    
     void _getRecoverDate(vector<Core::CDateTime> &tim,UINT32 type)
    {
        auto rst=getRoleBase(type);
        if(rst!=nullptr)
        {
            vector<string> times;
            SplitString(rst->Value.c_str(),',',times);
            if(times.size()==2)
            {
                tm t={0};
                memset(&t, 0, sizeof(tm));
#ifdef __linux__
                strptime(times[0].c_str(),"%H:%M",&t);
                time_t tt=mktime(&t);
                Core::CDateTime lt(tt);
                tim.push_back(lt);
                memset(&t, 0, sizeof(tm));
                strptime(times[1].c_str(),"%H:%M",&t);
                time_t tt1=mktime(&t);
                Core::CDateTime lt1(tt1);
                tim.push_back(lt1);
#endif
            }
        }
    }

    void  _getRecoverSpiritValue(vector<INT32> &value)
    {
        auto rst=getRoleBase(ROLEBASE_RECOVERSPIRITTVALUE);
        if(nullptr!=rst)
        {
            SplitStringInt(rst->Value.c_str(),',',value);
        }
    }

    void  _getRecoverStaminaValue(vector<INT32> &value)
    {
        auto rst=getRoleBase(ROLEBASE_RECOVERSTAMINATVALUE);
        if(nullptr!=rst)
        {
            SplitStringInt(rst->Value.c_str(),',',value);
        }
    }
    
    //type 0=Spirit 1=Stamina
    
    void  getRecoverValue(vector<INT32> &value,UINT32 type=0)
    {
        switch(type)
        {
            case 0:
                _getRecoverSpiritValue(value);
                break;
            case 1:
                _getRecoverStaminaValue(value);
                break;
        }
    }
    void  getRecoverSpiritTimeDate(vector<Core::CDateTime> &tim)
    {
        _getRecoverDate(tim,ROLEBASE_RECOVERSPIRITTIMING);
    }
    void  getRecoverStaminaDate(vector<Core::CDateTime> &tim)
    {
        _getRecoverDate(tim,ROLEBASE_RECOVERSTAMINATIMING);
    }
    const UINT32 getRoleLevelUpByCurrentLevel(UINT32 unCurrentLevel)
    {
        const CRoleExpMap::iterator &itr = RoleExpMap.find(unCurrentLevel);
        if(itr != RoleExpMap.end()){
            return itr->second.ExpNeed;
        }else{
            return 0;
        }
    }
    BOOL LoadActiveRecruit();
    BOOL LoadActiveRecruitTimes();
    BOOL LoadActiveRecruitbase();
    BOOL LoadActivity();
    BOOL LoadActivityBase();
    BOOL LoadActivityFight();
    BOOL LoadActivityHero();
    BOOL LoadActivityOpen();
    BOOL LoadAddArtifact();
    BOOL LoadAddRecruit();
    BOOL LoadAllRank();
    BOOL LoadArena();
    BOOL LoadArenaBase();
    BOOL LoadArenaMatch();
    BOOL LoadArenaReward();
    BOOL LoadArenaTopReward();
    BOOL LoadArtifacRankBase();
    BOOL LoadArtifact();
    BOOL LoadArtifactDropbox();
    BOOL LoadArtifactRank();
    BOOL LoadArtifactSlot();
    BOOL LoadArtifactStar();
    BOOL LoadArtifactStrengthen();
    BOOL LoadArtifactUpgrade();
    BOOL LoadArtifactWash();
    BOOL LoadBackBase();
    BOOL LoadBackGift();
    BOOL LoadBackLogin();
    BOOL LoadBackPay();
    BOOL LoadBossChallengeCost();
    BOOL LoadBossDrop();
    BOOL LoadBossReward();
    BOOL LoadBox();
    BOOL LoadBuffList();
    BOOL LoadBuyDirect();
    BOOL LoadCampActOpen();
    BOOL LoadCampBase();
    BOOL LoadCampGrain();
    BOOL LoadCampMine();
    BOOL LoadCampMineProduction();
    BOOL LoadCampMineScore();
    BOOL LoadCampMineUnlock();
    BOOL LoadCampMineUpgrade();
    BOOL LoadCampOfficeRank();
    BOOL LoadCampOfficeRight();
    BOOL LoadCampReward();
    BOOL LoadCampRoleReward();
    BOOL LoadCampThrough();
    BOOL LoadCampThroughItem();
    BOOL LoadCampTurntable();
    BOOL LoadCampTurntableItems();
    BOOL LoadCampWarStreakReward();
    BOOL LoadChannelBase();
    BOOL LoadChapter();
    BOOL LoadChatBase();
    BOOL LoadChatNotice();
    BOOL LoadCoin();
    BOOL LoadCoinPurchase();
    BOOL LoadCostBase();
    BOOL LoadCostSum();
    BOOL LoadDailyCostSum();
    BOOL LoadDailyLogin();
    BOOL LoadDailyPaySum();
    BOOL LoadDailySumPayReward();
    BOOL LoadDepreFactor();
    BOOL LoadDropOther();
    BOOL LoadDropbox();
    BOOL LoadEmail();
    BOOL LoadEquip();
    BOOL LoadEquipBase();
    BOOL LoadEquipCoinCost();
    BOOL LoadEquipMaterialGroup();
    BOOL LoadEquipRecycle();
    BOOL LoadEventRecruit();
    BOOL LoadExchange();
    BOOL LoadExchangeBase();
    BOOL LoadFightSet();
    BOOL LoadForm();
    BOOL LoadFormRestrict();
    BOOL LoadFragConvert();
    BOOL LoadFund();
    BOOL LoadFundBase();
    BOOL LoadGem();
    BOOL LoadGrowing();
    BOOL LoadGuildBase();
    BOOL LoadGuildBattleChat();
    BOOL LoadGuildBattleCity();
    BOOL LoadGuildBattleFight();
    BOOL LoadGuildBattleLog();
    BOOL LoadGuildBattlePersonRank();
    BOOL LoadGuildBattleRank();
    BOOL LoadGuildBattleSeverPersonRank();
    BOOL LoadGuildChapter();
    BOOL LoadGuildChapterFight();
    BOOL LoadGuildDungeon();
    BOOL LoadGuildDungeonAward();
    BOOL LoadGuildDungeonSpot();
    BOOL LoadGuildFlag();
    BOOL LoadGuildFlagLv();
    BOOL LoadGuildLog();
    BOOL LoadGuildLv();
    BOOL LoadGuildMember();
    BOOL LoadHero();
    BOOL LoadHeroBase();
    BOOL LoadHeroExp();
    BOOL LoadHeroGift();
    BOOL LoadHeroGiftProp();
    BOOL LoadHeroGiftSkill();
    BOOL LoadHeroRecycle();
    BOOL LoadHeroSkin();
    BOOL LoadHeroSoul();
    BOOL LoadHeroStar();
    BOOL LoadHeroStarRecycle();
    BOOL LoadItem();
    BOOL LoadLevelUpReward();
    BOOL LoadLoginActReward();
    BOOL LoadLottery();
    BOOL LoadLotteryBase();
    BOOL LoadLuckyTurntable();
    BOOL LoadLuckyTurntableBase();
    BOOL LoadLuckyTurntableItems();
    BOOL LoadLuckyTurntableValue();
    BOOL LoadMailDouble();
    BOOL LoadMisc();
    BOOL LoadMonsterBase();
    BOOL LoadMonsterProperty();
    BOOL LoadMonsterStrength();
    BOOL LoadMounts();
    BOOL LoadMountsEquip();
    BOOL LoadMountsEquipment();
    BOOL LoadMountsStar();
    BOOL LoadMountsTrain();
    BOOL LoadMysticshop();
    BOOL LoadMysticshopRefreshCost();
    BOOL LoadNewYearActivity();
    BOOL LoadNewYearActivityBase();
    BOOL LoadNewYearRecycle();
    BOOL LoadPay();
    BOOL LoadPayRebate();
    BOOL LoadPaySum();
    BOOL LoadPeakArena();
    BOOL LoadPeakArenaBase();
    BOOL LoadPeakArenaFormat();
    BOOL LoadPeakArenaMatch();
    BOOL LoadPeakArenaReward();
    BOOL LoadPeakRobot();
    BOOL LoadPeakUse();
    BOOL LoadPowerSet();
    BOOL LoadPushMessages();
    BOOL LoadQuenchProp();
    BOOL LoadQuenchRand();
    BOOL LoadQuestionPoints();
    BOOL LoadQuestionRank();
    BOOL LoadRanking();
    BOOL LoadRecruitBase();
    BOOL LoadRising();
    BOOL LoadRobot();
    BOOL LoadRobotEquip();
    BOOL LoadRoleBase();
    BOOL LoadRoleExp();
    BOOL LoadRoleNameBase();
    BOOL LoadScene();
    BOOL LoadSevenDayShop();
    BOOL LoadSevenDayTask();
    BOOL LoadShopReset();
    BOOL LoadShopitem();
    BOOL LoadSignPay();
    BOOL LoadSignReward();
    BOOL LoadSkill();
    BOOL LoadSkillElement();
    BOOL LoadSkillGift();
    BOOL LoadSkillPoint();
    BOOL LoadSkillTree();
    BOOL LoadSkin();
    BOOL LoadSnowmanBase();
    BOOL LoadSnowmanFlushTime();
    BOOL LoadSnowmanItem();
    BOOL LoadSnowmanQuestion();
    BOOL LoadSoulCost();
    BOOL LoadSoulSkill();
    BOOL LoadSpeBase();
    BOOL LoadSpeBox();
    BOOL LoadSpeRefCost();
    BOOL LoadSpecialShop();
    BOOL LoadSpiritPurchase();
    BOOL LoadStaminaPurchase();
    BOOL LoadStaminaReward();
    BOOL LoadStaminaRewardBase();
    BOOL LoadStaminaRewardDropbox();
    BOOL LoadStarCondition();
    BOOL LoadSysSwitch();
    BOOL LoadTask();
    BOOL LoadTaskType();
    BOOL LoadToolResult();
    BOOL LoadTower();
    BOOL LoadTowerAward();
    BOOL LoadTowerNormalAward();
    BOOL LoadTrialBase();
    BOOL LoadTrialFirstMatching();
    BOOL LoadTrialReward();
    BOOL LoadTrialRewardRead();
    BOOL LoadTrialRewardVIP();
    BOOL LoadUpgrade();
    BOOL LoadVip();
    BOOL LoadVipBase();
    BOOL LoadVipCount();
    BOOL LoadVipFunction();
    BOOL LoadVipGift();
    BOOL LoadWelfareBase();
    BOOL InitArtifactStarMapMap();
    BOOL InitArtifactStrengthenMapMap();
    BOOL InitBossDropMapMap();
    BOOL InitBoxMapMap();
    BOOL InitCampMineProductionMapMap();
    BOOL InitCampRewardMapMap();
    BOOL InitCampThroughItemMapMap();
    BOOL InitDailySumPayRewardMapMap();
    BOOL InitDropboxMapMap();
    BOOL InitExchangeMapMap();
    BOOL InitGrowingMapMap();
    BOOL InitGuildChapterFightMapMap();
    BOOL InitGuildDungeonAwardMapMap();
    BOOL InitHeroExpMapMap();
    BOOL InitHeroGiftSkillMapMap();
    BOOL InitHeroRecycleMapMap();
    BOOL InitHeroStarMapMap();
    BOOL InitHeroStarRecycleMapMap();
    BOOL InitLoginActRewardMapMap();
    BOOL InitMonsterPropertyMapMap();
    BOOL InitRobotMapMap();
    BOOL InitSevenDayTaskMapMap();
    BOOL InitShopResetMapMap();
    BOOL InitShopitemMapMap();
    BOOL InitSignRewardMapMap();
    BOOL InitSkillTreeMapMap();
    BOOL InitSoulCostMapMap();
    BOOL InitSoulSkillMapMap();
    BOOL InitSpeBoxMapMap();
    BOOL InitStaminaRewardDropboxMapMap();
    BOOL InitTaskMapMap();
    BOOL InitTowerMapMap();
    BOOL InitTrialRewardMapMap();
    BOOL InitTrialRewardVIPMapMap();
    const CActiveRecruitMap& getActiveRecruitMap() const
    {
        return ActiveRecruitMap;
    }
    const CActiveRecruitTimesMap& getActiveRecruitTimesMap() const
    {
        return ActiveRecruitTimesMap;
    }
    const CActiveRecruitbaseMap& getActiveRecruitbaseMap() const
    {
        return ActiveRecruitbaseMap;
    }
    const CActivityMap& getActivityMap() const
    {
        return ActivityMap;
    }
    const CActivityBaseMap& getActivityBaseMap() const
    {
        return ActivityBaseMap;
    }
    const CActivityFightMap& getActivityFightMap() const
    {
        return ActivityFightMap;
    }
    const CActivityHeroMap& getActivityHeroMap() const
    {
        return ActivityHeroMap;
    }
    const CActivityOpenMap& getActivityOpenMap() const
    {
        return ActivityOpenMap;
    }
    const CAddArtifactMap& getAddArtifactMap() const
    {
        return AddArtifactMap;
    }
    const CAddRecruitMap& getAddRecruitMap() const
    {
        return AddRecruitMap;
    }
    const CAllRankMap& getAllRankMap() const
    {
        return AllRankMap;
    }
    const CArenaMap& getArenaMap() const
    {
        return ArenaMap;
    }
    const CArenaBaseMap& getArenaBaseMap() const
    {
        return ArenaBaseMap;
    }
    const CArenaMatchMap& getArenaMatchMap() const
    {
        return ArenaMatchMap;
    }
    const CArenaRewardMap& getArenaRewardMap() const
    {
        return ArenaRewardMap;
    }
    const CArenaTopRewardMap& getArenaTopRewardMap() const
    {
        return ArenaTopRewardMap;
    }
    const CArtifacRankBaseMap& getArtifacRankBaseMap() const
    {
        return ArtifacRankBaseMap;
    }
    const CArtifactMap& getArtifactMap() const
    {
        return ArtifactMap;
    }
    const CArtifactDropboxMap& getArtifactDropboxMap() const
    {
        return ArtifactDropboxMap;
    }
    const CArtifactRankMap& getArtifactRankMap() const
    {
        return ArtifactRankMap;
    }
    const CArtifactSlotMap& getArtifactSlotMap() const
    {
        return ArtifactSlotMap;
    }
    const CArtifactStarMap& getArtifactStarMap() const
    {
        return ArtifactStarMap;
    }
    const CArtifactStrengthenMap& getArtifactStrengthenMap() const
    {
        return ArtifactStrengthenMap;
    }
    const CArtifactUpgradeMap& getArtifactUpgradeMap() const
    {
        return ArtifactUpgradeMap;
    }
    const CArtifactWashMap& getArtifactWashMap() const
    {
        return ArtifactWashMap;
    }
    const CBackBaseMap& getBackBaseMap() const
    {
        return BackBaseMap;
    }
    const CBackGiftMap& getBackGiftMap() const
    {
        return BackGiftMap;
    }
    const CBackLoginMap& getBackLoginMap() const
    {
        return BackLoginMap;
    }
    const CBackPayMap& getBackPayMap() const
    {
        return BackPayMap;
    }
    const CBossChallengeCostMap& getBossChallengeCostMap() const
    {
        return BossChallengeCostMap;
    }
    const CBossDropMap& getBossDropMap() const
    {
        return BossDropMap;
    }
    const CBossRewardMap& getBossRewardMap() const
    {
        return BossRewardMap;
    }
    const CBoxMap& getBoxMap() const
    {
        return BoxMap;
    }
    const CBuffListMap& getBuffListMap() const
    {
        return BuffListMap;
    }
    const CBuyDirectMap& getBuyDirectMap() const
    {
        return BuyDirectMap;
    }
    const CCampActOpenMap& getCampActOpenMap() const
    {
        return CampActOpenMap;
    }
    const CCampBaseMap& getCampBaseMap() const
    {
        return CampBaseMap;
    }
    const CCampGrainMap& getCampGrainMap() const
    {
        return CampGrainMap;
    }
    const CCampMineMap& getCampMineMap() const
    {
        return CampMineMap;
    }
    const CCampMineProductionMap& getCampMineProductionMap() const
    {
        return CampMineProductionMap;
    }
    const CCampMineScoreMap& getCampMineScoreMap() const
    {
        return CampMineScoreMap;
    }
    const CCampMineUnlockMap& getCampMineUnlockMap() const
    {
        return CampMineUnlockMap;
    }
    const CCampMineUpgradeMap& getCampMineUpgradeMap() const
    {
        return CampMineUpgradeMap;
    }
    const CCampOfficeRankMap& getCampOfficeRankMap() const
    {
        return CampOfficeRankMap;
    }
    const CCampOfficeRightMap& getCampOfficeRightMap() const
    {
        return CampOfficeRightMap;
    }
    const CCampRewardMap& getCampRewardMap() const
    {
        return CampRewardMap;
    }
    const CCampRoleRewardMap& getCampRoleRewardMap() const
    {
        return CampRoleRewardMap;
    }
    const CCampThroughMap& getCampThroughMap() const
    {
        return CampThroughMap;
    }
    const CCampThroughItemMap& getCampThroughItemMap() const
    {
        return CampThroughItemMap;
    }
    const CCampTurntableMap& getCampTurntableMap() const
    {
        return CampTurntableMap;
    }
    const CCampTurntableItemsMap& getCampTurntableItemsMap() const
    {
        return CampTurntableItemsMap;
    }
    const CCampWarStreakRewardMap& getCampWarStreakRewardMap() const
    {
        return CampWarStreakRewardMap;
    }
    const CChannelBaseMap& getChannelBaseMap() const
    {
        return ChannelBaseMap;
    }
    const CChapterMap& getChapterMap() const
    {
        return ChapterMap;
    }
    const CChatBaseMap& getChatBaseMap() const
    {
        return ChatBaseMap;
    }
    const CChatNoticeMap& getChatNoticeMap() const
    {
        return ChatNoticeMap;
    }
    const CCoinMap& getCoinMap() const
    {
        return CoinMap;
    }
    const CCoinPurchaseMap& getCoinPurchaseMap() const
    {
        return CoinPurchaseMap;
    }
    const CCostBaseMap& getCostBaseMap() const
    {
        return CostBaseMap;
    }
    const CCostSumMap& getCostSumMap() const
    {
        return CostSumMap;
    }
    const CDailyCostSumMap& getDailyCostSumMap() const
    {
        return DailyCostSumMap;
    }
    const CDailyLoginMap& getDailyLoginMap() const
    {
        return DailyLoginMap;
    }
    const CDailyPaySumMap& getDailyPaySumMap() const
    {
        return DailyPaySumMap;
    }
    const CDailySumPayRewardMap& getDailySumPayRewardMap() const
    {
        return DailySumPayRewardMap;
    }
    const CDepreFactorMap& getDepreFactorMap() const
    {
        return DepreFactorMap;
    }
    const CDropOtherMap& getDropOtherMap() const
    {
        return DropOtherMap;
    }
    const CDropboxMap& getDropboxMap() const
    {
        return DropboxMap;
    }
    const CEmailMap& getEmailMap() const
    {
        return EmailMap;
    }
    const CEquipMap& getEquipMap() const
    {
        return EquipMap;
    }
    const CEquipBaseMap& getEquipBaseMap() const
    {
        return EquipBaseMap;
    }
    const CEquipCoinCostMap& getEquipCoinCostMap() const
    {
        return EquipCoinCostMap;
    }
    const CEquipMaterialGroupMap& getEquipMaterialGroupMap() const
    {
        return EquipMaterialGroupMap;
    }
    const CEquipRecycleMap& getEquipRecycleMap() const
    {
        return EquipRecycleMap;
    }
    const CEventRecruitMap& getEventRecruitMap() const
    {
        return EventRecruitMap;
    }
    const CExchangeMap& getExchangeMap() const
    {
        return ExchangeMap;
    }
    const CExchangeBaseMap& getExchangeBaseMap() const
    {
        return ExchangeBaseMap;
    }
    const CFightSetMap& getFightSetMap() const
    {
        return FightSetMap;
    }
    const CFormMap& getFormMap() const
    {
        return FormMap;
    }
    const CFormRestrictMap& getFormRestrictMap() const
    {
        return FormRestrictMap;
    }
    const CFragConvertMap& getFragConvertMap() const
    {
        return FragConvertMap;
    }
    const CFundMap& getFundMap() const
    {
        return FundMap;
    }
    const CFundBaseMap& getFundBaseMap() const
    {
        return FundBaseMap;
    }
    const CGemMap& getGemMap() const
    {
        return GemMap;
    }
    const CGrowingMap& getGrowingMap() const
    {
        return GrowingMap;
    }
    const CGuildBaseMap& getGuildBaseMap() const
    {
        return GuildBaseMap;
    }
    const CGuildBattleChatMap& getGuildBattleChatMap() const
    {
        return GuildBattleChatMap;
    }
    const CGuildBattleCityMap& getGuildBattleCityMap() const
    {
        return GuildBattleCityMap;
    }
    const CGuildBattleFightMap& getGuildBattleFightMap() const
    {
        return GuildBattleFightMap;
    }
    const CGuildBattleLogMap& getGuildBattleLogMap() const
    {
        return GuildBattleLogMap;
    }
    const CGuildBattlePersonRankMap& getGuildBattlePersonRankMap() const
    {
        return GuildBattlePersonRankMap;
    }
    const CGuildBattleRankMap& getGuildBattleRankMap() const
    {
        return GuildBattleRankMap;
    }
    const CGuildBattleSeverPersonRankMap& getGuildBattleSeverPersonRankMap() const
    {
        return GuildBattleSeverPersonRankMap;
    }
    const CGuildChapterMap& getGuildChapterMap() const
    {
        return GuildChapterMap;
    }
    const CGuildChapterFightMap& getGuildChapterFightMap() const
    {
        return GuildChapterFightMap;
    }
    const CGuildDungeonMap& getGuildDungeonMap() const
    {
        return GuildDungeonMap;
    }
    const CGuildDungeonAwardMap& getGuildDungeonAwardMap() const
    {
        return GuildDungeonAwardMap;
    }
    const CGuildDungeonSpotMap& getGuildDungeonSpotMap() const
    {
        return GuildDungeonSpotMap;
    }
    const CGuildFlagMap& getGuildFlagMap() const
    {
        return GuildFlagMap;
    }
    const CGuildFlagLvMap& getGuildFlagLvMap() const
    {
        return GuildFlagLvMap;
    }
    const CGuildLogMap& getGuildLogMap() const
    {
        return GuildLogMap;
    }
    const CGuildLvMap& getGuildLvMap() const
    {
        return GuildLvMap;
    }
    const CGuildMemberMap& getGuildMemberMap() const
    {
        return GuildMemberMap;
    }
    const CHeroMap& getHeroMap() const
    {
        return HeroMap;
    }
    const CHeroBaseMap& getHeroBaseMap() const
    {
        return HeroBaseMap;
    }
    const CHeroExpMap& getHeroExpMap() const
    {
        return HeroExpMap;
    }
    const CHeroGiftMap& getHeroGiftMap() const
    {
        return HeroGiftMap;
    }
    const CHeroGiftPropMap& getHeroGiftPropMap() const
    {
        return HeroGiftPropMap;
    }
    const CHeroGiftSkillMap& getHeroGiftSkillMap() const
    {
        return HeroGiftSkillMap;
    }
    const CHeroRecycleMap& getHeroRecycleMap() const
    {
        return HeroRecycleMap;
    }
    const CHeroSkinMap& getHeroSkinMap() const
    {
        return HeroSkinMap;
    }
    const CHeroSoulMap& getHeroSoulMap() const
    {
        return HeroSoulMap;
    }
    const CHeroStarMap& getHeroStarMap() const
    {
        return HeroStarMap;
    }
    const CHeroStarRecycleMap& getHeroStarRecycleMap() const
    {
        return HeroStarRecycleMap;
    }
    const CItemMap& getItemMap() const
    {
        return ItemMap;
    }
    const CLevelUpRewardMap& getLevelUpRewardMap() const
    {
        return LevelUpRewardMap;
    }
    const CLoginActRewardMap& getLoginActRewardMap() const
    {
        return LoginActRewardMap;
    }
    const CLotteryMap& getLotteryMap() const
    {
        return LotteryMap;
    }
    const CLotteryBaseMap& getLotteryBaseMap() const
    {
        return LotteryBaseMap;
    }
    const CLuckyTurntableMap& getLuckyTurntableMap() const
    {
        return LuckyTurntableMap;
    }
    const CLuckyTurntableBaseMap& getLuckyTurntableBaseMap() const
    {
        return LuckyTurntableBaseMap;
    }
    const CLuckyTurntableItemsMap& getLuckyTurntableItemsMap() const
    {
        return LuckyTurntableItemsMap;
    }
    const CLuckyTurntableValueMap& getLuckyTurntableValueMap() const
    {
        return LuckyTurntableValueMap;
    }
    const CMailDoubleMap& getMailDoubleMap() const
    {
        return MailDoubleMap;
    }
    const CMiscMap& getMiscMap() const
    {
        return MiscMap;
    }
    const CMonsterBaseMap& getMonsterBaseMap() const
    {
        return MonsterBaseMap;
    }
    const CMonsterPropertyMap& getMonsterPropertyMap() const
    {
        return MonsterPropertyMap;
    }
    const CMonsterStrengthMap& getMonsterStrengthMap() const
    {
        return MonsterStrengthMap;
    }
    const CMountsMap& getMountsMap() const
    {
        return MountsMap;
    }
    const CMountsEquipMap& getMountsEquipMap() const
    {
        return MountsEquipMap;
    }
    const CMountsEquipmentMap& getMountsEquipmentMap() const
    {
        return MountsEquipmentMap;
    }
    const CMountsStarMap& getMountsStarMap() const
    {
        return MountsStarMap;
    }
    const CMountsTrainMap& getMountsTrainMap() const
    {
        return MountsTrainMap;
    }
    const CMysticshopMap& getMysticshopMap() const
    {
        return MysticshopMap;
    }
    const CMysticshopRefreshCostMap& getMysticshopRefreshCostMap() const
    {
        return MysticshopRefreshCostMap;
    }
    const CNewYearActivityMap& getNewYearActivityMap() const
    {
        return NewYearActivityMap;
    }
    const CNewYearActivityBaseMap& getNewYearActivityBaseMap() const
    {
        return NewYearActivityBaseMap;
    }
    const CNewYearRecycleMap& getNewYearRecycleMap() const
    {
        return NewYearRecycleMap;
    }
    const CPayMap& getPayMap() const
    {
        return PayMap;
    }
    const CPayRebateMap& getPayRebateMap() const
    {
        return PayRebateMap;
    }
    const CPaySumMap& getPaySumMap() const
    {
        return PaySumMap;
    }
    const CPeakArenaMap& getPeakArenaMap() const
    {
        return PeakArenaMap;
    }
    const CPeakArenaBaseMap& getPeakArenaBaseMap() const
    {
        return PeakArenaBaseMap;
    }
    const CPeakArenaFormatMap& getPeakArenaFormatMap() const
    {
        return PeakArenaFormatMap;
    }
    const CPeakArenaMatchMap& getPeakArenaMatchMap() const
    {
        return PeakArenaMatchMap;
    }
    const CPeakArenaRewardMap& getPeakArenaRewardMap() const
    {
        return PeakArenaRewardMap;
    }
    const CPeakRobotMap& getPeakRobotMap() const
    {
        return PeakRobotMap;
    }
    const CPeakUseMap& getPeakUseMap() const
    {
        return PeakUseMap;
    }
    const CPowerSetMap& getPowerSetMap() const
    {
        return PowerSetMap;
    }
    const CPushMessagesMap& getPushMessagesMap() const
    {
        return PushMessagesMap;
    }
    const CQuenchPropMap& getQuenchPropMap() const
    {
        return QuenchPropMap;
    }
    const CQuenchRandMap& getQuenchRandMap() const
    {
        return QuenchRandMap;
    }
    const CQuestionPointsMap& getQuestionPointsMap() const
    {
        return QuestionPointsMap;
    }
    const CQuestionRankMap& getQuestionRankMap() const
    {
        return QuestionRankMap;
    }
    const CRankingMap& getRankingMap() const
    {
        return RankingMap;
    }
    const CRecruitBaseMap& getRecruitBaseMap() const
    {
        return RecruitBaseMap;
    }
    const CRisingMap& getRisingMap() const
    {
        return RisingMap;
    }
    const CRobotMap& getRobotMap() const
    {
        return RobotMap;
    }
    const CRobotEquipMap& getRobotEquipMap() const
    {
        return RobotEquipMap;
    }
    const CRoleBaseMap& getRoleBaseMap() const
    {
        return RoleBaseMap;
    }
    const CRoleExpMap& getRoleExpMap() const
    {
        return RoleExpMap;
    }
    const CRoleNameBaseMap& getRoleNameBaseMap() const
    {
        return RoleNameBaseMap;
    }
    const CSceneMap& getSceneMap() const
    {
        return SceneMap;
    }
    const CSevenDayShopMap& getSevenDayShopMap() const
    {
        return SevenDayShopMap;
    }
    const CSevenDayTaskMap& getSevenDayTaskMap() const
    {
        return SevenDayTaskMap;
    }
    const CShopResetMap& getShopResetMap() const
    {
        return ShopResetMap;
    }
    const CShopitemMap& getShopitemMap() const
    {
        return ShopitemMap;
    }
    const CSignPayMap& getSignPayMap() const
    {
        return SignPayMap;
    }
    const CSignRewardMap& getSignRewardMap() const
    {
        return SignRewardMap;
    }
    const CSkillMap& getSkillMap() const
    {
        return SkillMap;
    }
    const CSkillElementMap& getSkillElementMap() const
    {
        return SkillElementMap;
    }
    const CSkillGiftMap& getSkillGiftMap() const
    {
        return SkillGiftMap;
    }
    const CSkillPointMap& getSkillPointMap() const
    {
        return SkillPointMap;
    }
    const CSkillTreeMap& getSkillTreeMap() const
    {
        return SkillTreeMap;
    }
    const CSkinMap& getSkinMap() const
    {
        return SkinMap;
    }
    const CSnowmanBaseMap& getSnowmanBaseMap() const
    {
        return SnowmanBaseMap;
    }
    const CSnowmanFlushTimeMap& getSnowmanFlushTimeMap() const
    {
        return SnowmanFlushTimeMap;
    }
    const CSnowmanItemMap& getSnowmanItemMap() const
    {
        return SnowmanItemMap;
    }
    const CSnowmanQuestionMap& getSnowmanQuestionMap() const
    {
        return SnowmanQuestionMap;
    }
    const CSoulCostMap& getSoulCostMap() const
    {
        return SoulCostMap;
    }
    const CSoulSkillMap& getSoulSkillMap() const
    {
        return SoulSkillMap;
    }
    const CSpeBaseMap& getSpeBaseMap() const
    {
        return SpeBaseMap;
    }
    const CSpeBoxMap& getSpeBoxMap() const
    {
        return SpeBoxMap;
    }
    const CSpeRefCostMap& getSpeRefCostMap() const
    {
        return SpeRefCostMap;
    }
    const CSpecialShopMap& getSpecialShopMap() const
    {
        return SpecialShopMap;
    }
    const CSpiritPurchaseMap& getSpiritPurchaseMap() const
    {
        return SpiritPurchaseMap;
    }
    const CStaminaPurchaseMap& getStaminaPurchaseMap() const
    {
        return StaminaPurchaseMap;
    }
    const CStaminaRewardMap& getStaminaRewardMap() const
    {
        return StaminaRewardMap;
    }
    const CStaminaRewardBaseMap& getStaminaRewardBaseMap() const
    {
        return StaminaRewardBaseMap;
    }
    const CStaminaRewardDropboxMap& getStaminaRewardDropboxMap() const
    {
        return StaminaRewardDropboxMap;
    }
    const CStarConditionMap& getStarConditionMap() const
    {
        return StarConditionMap;
    }
    const CSysSwitchMap& getSysSwitchMap() const
    {
        return SysSwitchMap;
    }
    const CTaskMap& getTaskMap() const
    {
        return TaskMap;
    }
    const CTaskTypeMap& getTaskTypeMap() const
    {
        return TaskTypeMap;
    }
    const CToolResultMap& getToolResultMap() const
    {
        return ToolResultMap;
    }
    const CTowerMap& getTowerMap() const
    {
        return TowerMap;
    }
    const CTowerAwardMap& getTowerAwardMap() const
    {
        return TowerAwardMap;
    }
    const CTowerNormalAwardMap& getTowerNormalAwardMap() const
    {
        return TowerNormalAwardMap;
    }
    const CTrialBaseMap& getTrialBaseMap() const
    {
        return TrialBaseMap;
    }
    const CTrialFirstMatchingMap& getTrialFirstMatchingMap() const
    {
        return TrialFirstMatchingMap;
    }
    const CTrialRewardMap& getTrialRewardMap() const
    {
        return TrialRewardMap;
    }
    const CTrialRewardReadMap& getTrialRewardReadMap() const
    {
        return TrialRewardReadMap;
    }
    const CTrialRewardVIPMap& getTrialRewardVIPMap() const
    {
        return TrialRewardVIPMap;
    }
    const CUpgradeMap& getUpgradeMap() const
    {
        return UpgradeMap;
    }
    const CVipMap& getVipMap() const
    {
        return VipMap;
    }
    const CVipBaseMap& getVipBaseMap() const
    {
        return VipBaseMap;
    }
    const CVipCountMap& getVipCountMap() const
    {
        return VipCountMap;
    }
    const CVipFunctionMap& getVipFunctionMap() const
    {
        return VipFunctionMap;
    }
    const CVipGiftMap& getVipGiftMap() const
    {
        return VipGiftMap;
    }
    const CWelfareBaseMap& getWelfareBaseMap() const
    {
        return WelfareBaseMap;
    }
    unordered_map<UINT32,ArtifactStar>& getArtifactStarMapByType(UINT32 id)
    {
        return ArtifactStarMapMap[id];    
    }
    unordered_map<UINT32,ArtifactStrengthen>& getArtifactStrengthenMapByType(UINT32 id)
    {
        return ArtifactStrengthenMapMap[id];    
    }
    unordered_map<UINT32,BossDrop>& getBossDropMapByGuildLv(UINT32 id)
    {
        return BossDropMapMap[id];    
    }
    unordered_map<UINT32,Box>& getBoxMapByLevel(UINT32 id)
    {
        return BoxMapMap[id];    
    }
    unordered_map<UINT32,CampMineProduction>& getCampMineProductionMapByMineType(UINT32 id)
    {
        return CampMineProductionMapMap[id];    
    }
    unordered_map<UINT32,CampReward>& getCampRewardMapByRewardID(UINT32 id)
    {
        return CampRewardMapMap[id];    
    }
    unordered_map<UINT32,CampThroughItem>& getCampThroughItemMapByLevel(UINT32 id)
    {
        return CampThroughItemMapMap[id];    
    }
    unordered_map<UINT32,DailySumPayReward>& getDailySumPayRewardMapByDay(UINT32 id)
    {
        return DailySumPayRewardMapMap[id];    
    }
    unordered_map<UINT32,Dropbox>& getDropboxMapByDropboxID(UINT32 id)
    {
        return DropboxMapMap[id];    
    }
    unordered_map<UINT32,Exchange>& getExchangeMapByShopItemID(UINT32 id)
    {
        return ExchangeMapMap[id];    
    }
    unordered_map<UINT32,Growing>& getGrowingMapByProb(UINT32 id)
    {
        return GrowingMapMap[id];    
    }
    unordered_map<UINT32,GuildChapterFight>& getGuildChapterFightMapByFightID(UINT32 id)
    {
        return GuildChapterFightMapMap[id];    
    }
    unordered_map<UINT32,GuildDungeonAward>& getGuildDungeonAwardMapByDungeon(UINT32 id)
    {
        return GuildDungeonAwardMapMap[id];    
    }
    unordered_map<UINT32,HeroExp>& getHeroExpMapByExpIndex(UINT32 id)
    {
        return HeroExpMapMap[id];    
    }
    unordered_map<UINT32,HeroGiftSkill>& getHeroGiftSkillMapByHeroID(UINT32 id)
    {
        return HeroGiftSkillMapMap[id];    
    }
    unordered_map<UINT32,HeroRecycle>& getHeroRecycleMapByGrade(UINT32 id)
    {
        return HeroRecycleMapMap[id];    
    }
    unordered_map<UINT32,HeroStar>& getHeroStarMapByHeroID(UINT32 id)
    {
        return HeroStarMapMap[id];    
    }
    unordered_map<UINT32,HeroStarRecycle>& getHeroStarRecycleMapByStar(UINT32 id)
    {
        return HeroStarRecycleMapMap[id];    
    }
    unordered_map<UINT32,LoginActReward>& getLoginActRewardMapByRewardType(UINT32 id)
    {
        return LoginActRewardMapMap[id];    
    }
    unordered_map<UINT32,MonsterProperty>& getMonsterPropertyMapByJob(UINT32 id)
    {
        return MonsterPropertyMapMap[id];    
    }
    unordered_map<UINT32,Robot>& getRobotMapByroleLv(UINT32 id)
    {
        return RobotMapMap[id];    
    }
    unordered_map<UINT32,SevenDayTask>& getSevenDayTaskMapByDay(UINT32 id)
    {
        return SevenDayTaskMapMap[id];    
    }
    unordered_map<UINT32,ShopReset>& getShopResetMapByShopID(UINT32 id)
    {
        return ShopResetMapMap[id];    
    }
    unordered_map<UINT32,Shopitem>& getShopitemMapByShopID(UINT32 id)
    {
        return ShopitemMapMap[id];    
    }
    unordered_map<UINT32,SignReward>& getSignRewardMapByMonth(UINT32 id)
    {
        return SignRewardMapMap[id];    
    }
    unordered_map<UINT32,SkillTree>& getSkillTreeMapBySex(UINT32 id)
    {
        return SkillTreeMapMap[id];    
    }
    unordered_map<UINT32,SoulCost>& getSoulCostMapByCostType(UINT32 id)
    {
        return SoulCostMapMap[id];    
    }
    unordered_map<UINT32,SoulSkill>& getSoulSkillMapBySkillID(UINT32 id)
    {
        return SoulSkillMapMap[id];    
    }
    unordered_map<UINT32,SpeBox>& getSpeBoxMapByItemBoxID(UINT32 id)
    {
        return SpeBoxMapMap[id];    
    }
    unordered_map<UINT32,StaminaRewardDropbox>& getStaminaRewardDropboxMapByDropboxID(UINT32 id)
    {
        return StaminaRewardDropboxMapMap[id];    
    }
    unordered_map<UINT32,Task>& getTaskMapByRoleLevel(UINT32 id)
    {
        return TaskMapMap[id];    
    }
    unordered_map<UINT32,Tower>& getTowerMapByTowerId(UINT32 id)
    {
        return TowerMapMap[id];    
    }
    unordered_map<UINT32,TrialReward>& getTrialRewardMapByLevel(UINT32 id)
    {
        return TrialRewardMapMap[id];    
    }
    unordered_map<UINT32,TrialRewardVIP>& getTrialRewardVIPMapByLevel(UINT32 id)
    {
        return TrialRewardVIPMapMap[id];    
    }
    const ArtifactStar* getArtifactStarbyTypeAndStar(UINT32 Type,UINT32 Star)
    {
        auto &mp=ArtifactStarMapMap[Type];
        if(mp.size()>0)
        {
            auto it=mp.find(Star);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const ArtifactStrengthen* getArtifactStrengthenbyTypeAndLevel(UINT32 Type,UINT32 Level)
    {
        auto &mp=ArtifactStrengthenMapMap[Type];
        if(mp.size()>0)
        {
            auto it=mp.find(Level);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const BossDrop* getBossDropbyGuildLvAndEnergy(UINT32 GuildLv,UINT32 Energy)
    {
        auto &mp=BossDropMapMap[GuildLv];
        if(mp.size()>0)
        {
            auto it=mp.find(Energy);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Box* getBoxbyLevelAndItem(UINT32 Level,UINT32 Item)
    {
        auto &mp=BoxMapMap[Level];
        if(mp.size()>0)
        {
            auto it=mp.find(Item);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const CampMineProduction* getCampMineProductionbyMineTypeAndPlayerLevel(UINT32 MineType,UINT32 PlayerLevel)
    {
        auto &mp=CampMineProductionMapMap[MineType];
        if(mp.size()>0)
        {
            auto it=mp.find(PlayerLevel);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const CampReward* getCampRewardbyRewardIDAndRank(UINT32 RewardID,UINT32 Rank)
    {
        auto &mp=CampRewardMapMap[RewardID];
        if(mp.size()>0)
        {
            auto it=mp.find(Rank);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const CampThroughItem* getCampThroughItembyLevelAndThrough(UINT32 Level,UINT32 Through)
    {
        auto &mp=CampThroughItemMapMap[Level];
        if(mp.size()>0)
        {
            auto it=mp.find(Through);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const DailySumPayReward* getDailySumPayRewardbyDayAndIndex(UINT32 Day,UINT32 Index)
    {
        auto &mp=DailySumPayRewardMapMap[Day];
        if(mp.size()>0)
        {
            auto it=mp.find(Index);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Dropbox* getDropboxbyDropboxIDAndItemID(UINT32 DropboxID,UINT32 ItemID)
    {
        auto &mp=DropboxMapMap[DropboxID];
        if(mp.size()>0)
        {
            auto it=mp.find(ItemID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Exchange* getExchangebyShopItemIDAndID(UINT32 ShopItemID,UINT32 ID)
    {
        auto &mp=ExchangeMapMap[ShopItemID];
        if(mp.size()>0)
        {
            auto it=mp.find(ID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Growing* getGrowingbyProbAndID(UINT32 Prob,UINT32 ID)
    {
        auto &mp=GrowingMapMap[Prob];
        if(mp.size()>0)
        {
            auto it=mp.find(ID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const GuildChapterFight* getGuildChapterFightbyFightIDAndFightSequence(UINT32 FightID,UINT32 FightSequence)
    {
        auto &mp=GuildChapterFightMapMap[FightID];
        if(mp.size()>0)
        {
            auto it=mp.find(FightSequence);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const GuildDungeonAward* getGuildDungeonAwardbyDungeonAndId(UINT32 Dungeon,UINT32 Id)
    {
        auto &mp=GuildDungeonAwardMapMap[Dungeon];
        if(mp.size()>0)
        {
            auto it=mp.find(Id);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const HeroExp* getHeroExpbyExpIndexAndLevel(UINT32 ExpIndex,UINT32 Level)
    {
        auto &mp=HeroExpMapMap[ExpIndex];
        if(mp.size()>0)
        {
            auto it=mp.find(Level);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const HeroGiftSkill* getHeroGiftSkillbyHeroIDAndGiftLv(UINT32 HeroID,UINT32 GiftLv)
    {
        auto &mp=HeroGiftSkillMapMap[HeroID];
        if(mp.size()>0)
        {
            auto it=mp.find(GiftLv);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const HeroRecycle* getHeroRecyclebyGradeAndQuality(UINT32 Grade,UINT32 Quality)
    {
        auto &mp=HeroRecycleMapMap[Grade];
        if(mp.size()>0)
        {
            auto it=mp.find(Quality);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const HeroStar* getHeroStarbyHeroIDAndStar(UINT32 HeroID,UINT32 Star)
    {
        auto &mp=HeroStarMapMap[HeroID];
        if(mp.size()>0)
        {
            auto it=mp.find(Star);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const HeroStarRecycle* getHeroStarRecyclebyStarAndQuality(UINT32 Star,UINT32 Quality)
    {
        auto &mp=HeroStarRecycleMapMap[Star];
        if(mp.size()>0)
        {
            auto it=mp.find(Quality);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const LoginActReward* getLoginActRewardbyRewardTypeAndDays(UINT32 RewardType,UINT32 Days)
    {
        auto &mp=LoginActRewardMapMap[RewardType];
        if(mp.size()>0)
        {
            auto it=mp.find(Days);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const MonsterProperty* getMonsterPropertybyJobAndMonsterLv(UINT32 Job,UINT32 MonsterLv)
    {
        auto &mp=MonsterPropertyMapMap[Job];
        if(mp.size()>0)
        {
            auto it=mp.find(MonsterLv);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Robot* getRobotbyroleLvAndGiftID(UINT32 roleLv,UINT32 GiftID)
    {
        auto &mp=RobotMapMap[roleLv];
        if(mp.size()>0)
        {
            auto it=mp.find(GiftID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const SevenDayTask* getSevenDayTaskbyDayAndID(UINT32 Day,UINT32 ID)
    {
        auto &mp=SevenDayTaskMapMap[Day];
        if(mp.size()>0)
        {
            auto it=mp.find(ID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const ShopReset* getShopResetbyShopIDAndResetTime(UINT32 ShopID,UINT32 ResetTime)
    {
        auto &mp=ShopResetMapMap[ShopID];
        if(mp.size()>0)
        {
            auto it=mp.find(ResetTime);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Shopitem* getShopitembyShopIDAndShopItemID(UINT32 ShopID,UINT32 ShopItemID)
    {
        auto &mp=ShopitemMapMap[ShopID];
        if(mp.size()>0)
        {
            auto it=mp.find(ShopItemID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const SignReward* getSignRewardbyMonthAndDays(UINT32 Month,UINT32 Days)
    {
        auto &mp=SignRewardMapMap[Month];
        if(mp.size()>0)
        {
            auto it=mp.find(Days);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const SkillTree* getSkillTreebySexAndPositionID(UINT32 Sex,UINT32 PositionID)
    {
        auto &mp=SkillTreeMapMap[Sex];
        if(mp.size()>0)
        {
            auto it=mp.find(PositionID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const SoulCost* getSoulCostbyCostTypeAndSkillLv(UINT32 CostType,UINT32 SkillLv)
    {
        auto &mp=SoulCostMapMap[CostType];
        if(mp.size()>0)
        {
            auto it=mp.find(SkillLv);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const SoulSkill* getSoulSkillbySkillIDAndSkillLv(UINT32 SkillID,UINT32 SkillLv)
    {
        auto &mp=SoulSkillMapMap[SkillID];
        if(mp.size()>0)
        {
            auto it=mp.find(SkillLv);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const SpeBox* getSpeBoxbyItemBoxIDAndID(UINT32 ItemBoxID,UINT32 ID)
    {
        auto &mp=SpeBoxMapMap[ItemBoxID];
        if(mp.size()>0)
        {
            auto it=mp.find(ID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const StaminaRewardDropbox* getStaminaRewardDropboxbyDropboxIDAndID(UINT32 DropboxID,UINT32 ID)
    {
        auto &mp=StaminaRewardDropboxMapMap[DropboxID];
        if(mp.size()>0)
        {
            auto it=mp.find(ID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Task* getTaskbyRoleLevelAndTaskID(UINT32 RoleLevel,UINT32 TaskID)
    {
        auto &mp=TaskMapMap[RoleLevel];
        if(mp.size()>0)
        {
            auto it=mp.find(TaskID);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const Tower* getTowerbyTowerIdAndFightsSetId(UINT32 TowerId,UINT32 FightsSetId)
    {
        auto &mp=TowerMapMap[TowerId];
        if(mp.size()>0)
        {
            auto it=mp.find(FightsSetId);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const TrialReward* getTrialRewardbyLevelAndchangePoint(UINT32 Level,UINT32 changePoint)
    {
        auto &mp=TrialRewardMapMap[Level];
        if(mp.size()>0)
        {
            auto it=mp.find(changePoint);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const TrialRewardVIP* getTrialRewardVIPbyLevelAndchangePoint(UINT32 Level,UINT32 changePoint)
    {
        auto &mp=TrialRewardVIPMapMap[Level];
        if(mp.size()>0)
        {
            auto it=mp.find(changePoint);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }
    const ActiveRecruit* getActiveRecruit(UINT32 id)
    {
        const CActiveRecruitMap::iterator &it=ActiveRecruitMap.find(id);
        if(it!=ActiveRecruitMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ActiveRecruitTimes* getActiveRecruitTimes(UINT32 id)
    {
        const CActiveRecruitTimesMap::iterator &it=ActiveRecruitTimesMap.find(id);
        if(it!=ActiveRecruitTimesMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ActiveRecruitbase* getActiveRecruitbase(UINT32 id)
    {
        const CActiveRecruitbaseMap::iterator &it=ActiveRecruitbaseMap.find(id);
        if(it!=ActiveRecruitbaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Activity* getActivity(UINT32 id)
    {
        const CActivityMap::iterator &it=ActivityMap.find(id);
        if(it!=ActivityMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ActivityBase* getActivityBase(UINT32 id)
    {
        const CActivityBaseMap::iterator &it=ActivityBaseMap.find(id);
        if(it!=ActivityBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ActivityFight* getActivityFight(UINT32 id)
    {
        const CActivityFightMap::iterator &it=ActivityFightMap.find(id);
        if(it!=ActivityFightMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ActivityHero* getActivityHero(UINT32 id)
    {
        const CActivityHeroMap::iterator &it=ActivityHeroMap.find(id);
        if(it!=ActivityHeroMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ActivityOpen* getActivityOpen(UINT32 id)
    {
        const CActivityOpenMap::iterator &it=ActivityOpenMap.find(id);
        if(it!=ActivityOpenMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const AddArtifact* getAddArtifact(UINT32 id)
    {
        const CAddArtifactMap::iterator &it=AddArtifactMap.find(id);
        if(it!=AddArtifactMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const AddRecruit* getAddRecruit(UINT32 id)
    {
        const CAddRecruitMap::iterator &it=AddRecruitMap.find(id);
        if(it!=AddRecruitMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const AllRank* getAllRank(UINT32 id)
    {
        const CAllRankMap::iterator &it=AllRankMap.find(id);
        if(it!=AllRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Arena* getArena(UINT32 id)
    {
        const CArenaMap::iterator &it=ArenaMap.find(id);
        if(it!=ArenaMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArenaBase* getArenaBase(UINT32 id)
    {
        const CArenaBaseMap::iterator &it=ArenaBaseMap.find(id);
        if(it!=ArenaBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArenaMatch* getArenaMatch(UINT32 id)
    {
        const CArenaMatchMap::iterator &it=ArenaMatchMap.find(id);
        if(it!=ArenaMatchMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArenaReward* getArenaReward(UINT32 id)
    {
        const CArenaRewardMap::iterator &it=ArenaRewardMap.find(id);
        if(it!=ArenaRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArenaTopReward* getArenaTopReward(UINT32 id)
    {
        const CArenaTopRewardMap::iterator &it=ArenaTopRewardMap.find(id);
        if(it!=ArenaTopRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifacRankBase* getArtifacRankBase(UINT32 id)
    {
        const CArtifacRankBaseMap::iterator &it=ArtifacRankBaseMap.find(id);
        if(it!=ArtifacRankBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Artifact* getArtifact(UINT32 id)
    {
        const CArtifactMap::iterator &it=ArtifactMap.find(id);
        if(it!=ArtifactMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactDropbox* getArtifactDropbox(UINT32 id)
    {
        const CArtifactDropboxMap::iterator &it=ArtifactDropboxMap.find(id);
        if(it!=ArtifactDropboxMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactRank* getArtifactRank(UINT32 id)
    {
        const CArtifactRankMap::iterator &it=ArtifactRankMap.find(id);
        if(it!=ArtifactRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactSlot* getArtifactSlot(UINT32 id)
    {
        const CArtifactSlotMap::iterator &it=ArtifactSlotMap.find(id);
        if(it!=ArtifactSlotMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactStar* getArtifactStar(UINT32 id)
    {
        const CArtifactStarMap::iterator &it=ArtifactStarMap.find(id);
        if(it!=ArtifactStarMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactStrengthen* getArtifactStrengthen(UINT32 id)
    {
        const CArtifactStrengthenMap::iterator &it=ArtifactStrengthenMap.find(id);
        if(it!=ArtifactStrengthenMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactUpgrade* getArtifactUpgrade(UINT32 id)
    {
        const CArtifactUpgradeMap::iterator &it=ArtifactUpgradeMap.find(id);
        if(it!=ArtifactUpgradeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ArtifactWash* getArtifactWash(UINT32 id)
    {
        const CArtifactWashMap::iterator &it=ArtifactWashMap.find(id);
        if(it!=ArtifactWashMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BackBase* getBackBase(UINT32 id)
    {
        const CBackBaseMap::iterator &it=BackBaseMap.find(id);
        if(it!=BackBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BackGift* getBackGift(UINT32 id)
    {
        const CBackGiftMap::iterator &it=BackGiftMap.find(id);
        if(it!=BackGiftMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BackLogin* getBackLogin(UINT32 id)
    {
        const CBackLoginMap::iterator &it=BackLoginMap.find(id);
        if(it!=BackLoginMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BackPay* getBackPay(UINT32 id)
    {
        const CBackPayMap::iterator &it=BackPayMap.find(id);
        if(it!=BackPayMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BossChallengeCost* getBossChallengeCost(UINT32 id)
    {
        const CBossChallengeCostMap::iterator &it=BossChallengeCostMap.find(id);
        if(it!=BossChallengeCostMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BossDrop* getBossDrop(UINT32 id)
    {
        const CBossDropMap::iterator &it=BossDropMap.find(id);
        if(it!=BossDropMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BossReward* getBossReward(UINT32 id)
    {
        const CBossRewardMap::iterator &it=BossRewardMap.find(id);
        if(it!=BossRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Box* getBox(UINT32 id)
    {
        const CBoxMap::iterator &it=BoxMap.find(id);
        if(it!=BoxMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BuffList* getBuffList(UINT32 id)
    {
        const CBuffListMap::iterator &it=BuffListMap.find(id);
        if(it!=BuffListMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const BuyDirect* getBuyDirect(UINT32 id)
    {
        const CBuyDirectMap::iterator &it=BuyDirectMap.find(id);
        if(it!=BuyDirectMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampActOpen* getCampActOpen(UINT32 id)
    {
        const CCampActOpenMap::iterator &it=CampActOpenMap.find(id);
        if(it!=CampActOpenMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampBase* getCampBase(UINT32 id)
    {
        const CCampBaseMap::iterator &it=CampBaseMap.find(id);
        if(it!=CampBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampGrain* getCampGrain(UINT32 id)
    {
        const CCampGrainMap::iterator &it=CampGrainMap.find(id);
        if(it!=CampGrainMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampMine* getCampMine(UINT32 id)
    {
        const CCampMineMap::iterator &it=CampMineMap.find(id);
        if(it!=CampMineMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampMineProduction* getCampMineProduction(UINT32 id)
    {
        const CCampMineProductionMap::iterator &it=CampMineProductionMap.find(id);
        if(it!=CampMineProductionMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampMineScore* getCampMineScore(UINT32 id)
    {
        const CCampMineScoreMap::iterator &it=CampMineScoreMap.find(id);
        if(it!=CampMineScoreMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampMineUnlock* getCampMineUnlock(UINT32 id)
    {
        const CCampMineUnlockMap::iterator &it=CampMineUnlockMap.find(id);
        if(it!=CampMineUnlockMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampMineUpgrade* getCampMineUpgrade(UINT32 id)
    {
        const CCampMineUpgradeMap::iterator &it=CampMineUpgradeMap.find(id);
        if(it!=CampMineUpgradeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampOfficeRank* getCampOfficeRank(UINT32 id)
    {
        const CCampOfficeRankMap::iterator &it=CampOfficeRankMap.find(id);
        if(it!=CampOfficeRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampOfficeRight* getCampOfficeRight(UINT32 id)
    {
        const CCampOfficeRightMap::iterator &it=CampOfficeRightMap.find(id);
        if(it!=CampOfficeRightMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampReward* getCampReward(UINT32 id)
    {
        const CCampRewardMap::iterator &it=CampRewardMap.find(id);
        if(it!=CampRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampRoleReward* getCampRoleReward(UINT32 id)
    {
        const CCampRoleRewardMap::iterator &it=CampRoleRewardMap.find(id);
        if(it!=CampRoleRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampThrough* getCampThrough(UINT32 id)
    {
        const CCampThroughMap::iterator &it=CampThroughMap.find(id);
        if(it!=CampThroughMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampThroughItem* getCampThroughItem(UINT32 id)
    {
        const CCampThroughItemMap::iterator &it=CampThroughItemMap.find(id);
        if(it!=CampThroughItemMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampTurntable* getCampTurntable(UINT32 id)
    {
        const CCampTurntableMap::iterator &it=CampTurntableMap.find(id);
        if(it!=CampTurntableMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampTurntableItems* getCampTurntableItems(UINT32 id)
    {
        const CCampTurntableItemsMap::iterator &it=CampTurntableItemsMap.find(id);
        if(it!=CampTurntableItemsMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CampWarStreakReward* getCampWarStreakReward(UINT32 id)
    {
        const CCampWarStreakRewardMap::iterator &it=CampWarStreakRewardMap.find(id);
        if(it!=CampWarStreakRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ChannelBase* getChannelBase(UINT32 id)
    {
        const CChannelBaseMap::iterator &it=ChannelBaseMap.find(id);
        if(it!=ChannelBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Chapter* getChapter(UINT32 id)
    {
        const CChapterMap::iterator &it=ChapterMap.find(id);
        if(it!=ChapterMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ChatBase* getChatBase(UINT32 id)
    {
        const CChatBaseMap::iterator &it=ChatBaseMap.find(id);
        if(it!=ChatBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ChatNotice* getChatNotice(UINT32 id)
    {
        const CChatNoticeMap::iterator &it=ChatNoticeMap.find(id);
        if(it!=ChatNoticeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Coin* getCoin(UINT32 id)
    {
        const CCoinMap::iterator &it=CoinMap.find(id);
        if(it!=CoinMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CoinPurchase* getCoinPurchase(UINT32 id)
    {
        const CCoinPurchaseMap::iterator &it=CoinPurchaseMap.find(id);
        if(it!=CoinPurchaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CostBase* getCostBase(UINT32 id)
    {
        const CCostBaseMap::iterator &it=CostBaseMap.find(id);
        if(it!=CostBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const CostSum* getCostSum(UINT32 id)
    {
        const CCostSumMap::iterator &it=CostSumMap.find(id);
        if(it!=CostSumMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const DailyCostSum* getDailyCostSum(UINT32 id)
    {
        const CDailyCostSumMap::iterator &it=DailyCostSumMap.find(id);
        if(it!=DailyCostSumMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const DailyLogin* getDailyLogin(UINT32 id)
    {
        const CDailyLoginMap::iterator &it=DailyLoginMap.find(id);
        if(it!=DailyLoginMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const DailyPaySum* getDailyPaySum(UINT32 id)
    {
        const CDailyPaySumMap::iterator &it=DailyPaySumMap.find(id);
        if(it!=DailyPaySumMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const DailySumPayReward* getDailySumPayReward(UINT32 id)
    {
        const CDailySumPayRewardMap::iterator &it=DailySumPayRewardMap.find(id);
        if(it!=DailySumPayRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const DepreFactor* getDepreFactor(UINT32 id)
    {
        const CDepreFactorMap::iterator &it=DepreFactorMap.find(id);
        if(it!=DepreFactorMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const DropOther* getDropOther(UINT32 id)
    {
        const CDropOtherMap::iterator &it=DropOtherMap.find(id);
        if(it!=DropOtherMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Dropbox* getDropbox(UINT32 id)
    {
        const CDropboxMap::iterator &it=DropboxMap.find(id);
        if(it!=DropboxMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Email* getEmail(UINT32 id)
    {
        const CEmailMap::iterator &it=EmailMap.find(id);
        if(it!=EmailMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Equip* getEquip(UINT32 id)
    {
        const CEquipMap::iterator &it=EquipMap.find(id);
        if(it!=EquipMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const EquipBase* getEquipBase(UINT32 id)
    {
        const CEquipBaseMap::iterator &it=EquipBaseMap.find(id);
        if(it!=EquipBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const EquipCoinCost* getEquipCoinCost(UINT32 id)
    {
        const CEquipCoinCostMap::iterator &it=EquipCoinCostMap.find(id);
        if(it!=EquipCoinCostMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const EquipMaterialGroup* getEquipMaterialGroup(UINT32 id)
    {
        const CEquipMaterialGroupMap::iterator &it=EquipMaterialGroupMap.find(id);
        if(it!=EquipMaterialGroupMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const EquipRecycle* getEquipRecycle(UINT32 id)
    {
        const CEquipRecycleMap::iterator &it=EquipRecycleMap.find(id);
        if(it!=EquipRecycleMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const EventRecruit* getEventRecruit(UINT32 id)
    {
        const CEventRecruitMap::iterator &it=EventRecruitMap.find(id);
        if(it!=EventRecruitMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Exchange* getExchange(UINT32 id)
    {
        const CExchangeMap::iterator &it=ExchangeMap.find(id);
        if(it!=ExchangeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ExchangeBase* getExchangeBase(UINT32 id)
    {
        const CExchangeBaseMap::iterator &it=ExchangeBaseMap.find(id);
        if(it!=ExchangeBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const FightSet* getFightSet(UINT32 id)
    {
        const CFightSetMap::iterator &it=FightSetMap.find(id);
        if(it!=FightSetMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Form* getForm(UINT32 id)
    {
        const CFormMap::iterator &it=FormMap.find(id);
        if(it!=FormMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const FormRestrict* getFormRestrict(UINT32 id)
    {
        const CFormRestrictMap::iterator &it=FormRestrictMap.find(id);
        if(it!=FormRestrictMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const FragConvert* getFragConvert(UINT32 id)
    {
        const CFragConvertMap::iterator &it=FragConvertMap.find(id);
        if(it!=FragConvertMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Fund* getFund(UINT32 id)
    {
        const CFundMap::iterator &it=FundMap.find(id);
        if(it!=FundMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const FundBase* getFundBase(UINT32 id)
    {
        const CFundBaseMap::iterator &it=FundBaseMap.find(id);
        if(it!=FundBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Gem* getGem(UINT32 id)
    {
        const CGemMap::iterator &it=GemMap.find(id);
        if(it!=GemMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Growing* getGrowing(UINT32 id)
    {
        const CGrowingMap::iterator &it=GrowingMap.find(id);
        if(it!=GrowingMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBase* getGuildBase(UINT32 id)
    {
        const CGuildBaseMap::iterator &it=GuildBaseMap.find(id);
        if(it!=GuildBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattleChat* getGuildBattleChat(UINT32 id)
    {
        const CGuildBattleChatMap::iterator &it=GuildBattleChatMap.find(id);
        if(it!=GuildBattleChatMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattleCity* getGuildBattleCity(UINT32 id)
    {
        const CGuildBattleCityMap::iterator &it=GuildBattleCityMap.find(id);
        if(it!=GuildBattleCityMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattleFight* getGuildBattleFight(UINT32 id)
    {
        const CGuildBattleFightMap::iterator &it=GuildBattleFightMap.find(id);
        if(it!=GuildBattleFightMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattleLog* getGuildBattleLog(UINT32 id)
    {
        const CGuildBattleLogMap::iterator &it=GuildBattleLogMap.find(id);
        if(it!=GuildBattleLogMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattlePersonRank* getGuildBattlePersonRank(UINT32 id)
    {
        const CGuildBattlePersonRankMap::iterator &it=GuildBattlePersonRankMap.find(id);
        if(it!=GuildBattlePersonRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattleRank* getGuildBattleRank(UINT32 id)
    {
        const CGuildBattleRankMap::iterator &it=GuildBattleRankMap.find(id);
        if(it!=GuildBattleRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildBattleSeverPersonRank* getGuildBattleSeverPersonRank(UINT32 id)
    {
        const CGuildBattleSeverPersonRankMap::iterator &it=GuildBattleSeverPersonRankMap.find(id);
        if(it!=GuildBattleSeverPersonRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildChapter* getGuildChapter(UINT32 id)
    {
        const CGuildChapterMap::iterator &it=GuildChapterMap.find(id);
        if(it!=GuildChapterMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildChapterFight* getGuildChapterFight(UINT32 id)
    {
        const CGuildChapterFightMap::iterator &it=GuildChapterFightMap.find(id);
        if(it!=GuildChapterFightMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildDungeon* getGuildDungeon(UINT32 id)
    {
        const CGuildDungeonMap::iterator &it=GuildDungeonMap.find(id);
        if(it!=GuildDungeonMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildDungeonAward* getGuildDungeonAward(UINT32 id)
    {
        const CGuildDungeonAwardMap::iterator &it=GuildDungeonAwardMap.find(id);
        if(it!=GuildDungeonAwardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildDungeonSpot* getGuildDungeonSpot(UINT32 id)
    {
        const CGuildDungeonSpotMap::iterator &it=GuildDungeonSpotMap.find(id);
        if(it!=GuildDungeonSpotMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildFlag* getGuildFlag(UINT32 id)
    {
        const CGuildFlagMap::iterator &it=GuildFlagMap.find(id);
        if(it!=GuildFlagMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildFlagLv* getGuildFlagLv(UINT32 id)
    {
        const CGuildFlagLvMap::iterator &it=GuildFlagLvMap.find(id);
        if(it!=GuildFlagLvMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildLog* getGuildLog(UINT32 id)
    {
        const CGuildLogMap::iterator &it=GuildLogMap.find(id);
        if(it!=GuildLogMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildLv* getGuildLv(UINT32 id)
    {
        const CGuildLvMap::iterator &it=GuildLvMap.find(id);
        if(it!=GuildLvMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const GuildMember* getGuildMember(UINT32 id)
    {
        const CGuildMemberMap::iterator &it=GuildMemberMap.find(id);
        if(it!=GuildMemberMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Hero* getHero(UINT32 id)
    {
        const CHeroMap::iterator &it=HeroMap.find(id);
        if(it!=HeroMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroBase* getHeroBase(UINT32 id)
    {
        const CHeroBaseMap::iterator &it=HeroBaseMap.find(id);
        if(it!=HeroBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroExp* getHeroExp(UINT32 id)
    {
        const CHeroExpMap::iterator &it=HeroExpMap.find(id);
        if(it!=HeroExpMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroGift* getHeroGift(UINT32 id)
    {
        const CHeroGiftMap::iterator &it=HeroGiftMap.find(id);
        if(it!=HeroGiftMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroGiftProp* getHeroGiftProp(UINT32 id)
    {
        const CHeroGiftPropMap::iterator &it=HeroGiftPropMap.find(id);
        if(it!=HeroGiftPropMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroGiftSkill* getHeroGiftSkill(UINT32 id)
    {
        const CHeroGiftSkillMap::iterator &it=HeroGiftSkillMap.find(id);
        if(it!=HeroGiftSkillMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroRecycle* getHeroRecycle(UINT32 id)
    {
        const CHeroRecycleMap::iterator &it=HeroRecycleMap.find(id);
        if(it!=HeroRecycleMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroSkin* getHeroSkin(UINT32 id)
    {
        const CHeroSkinMap::iterator &it=HeroSkinMap.find(id);
        if(it!=HeroSkinMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroSoul* getHeroSoul(UINT32 id)
    {
        const CHeroSoulMap::iterator &it=HeroSoulMap.find(id);
        if(it!=HeroSoulMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroStar* getHeroStar(UINT32 id)
    {
        const CHeroStarMap::iterator &it=HeroStarMap.find(id);
        if(it!=HeroStarMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const HeroStarRecycle* getHeroStarRecycle(UINT32 id)
    {
        const CHeroStarRecycleMap::iterator &it=HeroStarRecycleMap.find(id);
        if(it!=HeroStarRecycleMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Item* getItem(UINT32 id)
    {
        const CItemMap::iterator &it=ItemMap.find(id);
        if(it!=ItemMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LevelUpReward* getLevelUpReward(UINT32 id)
    {
        const CLevelUpRewardMap::iterator &it=LevelUpRewardMap.find(id);
        if(it!=LevelUpRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LoginActReward* getLoginActReward(UINT32 id)
    {
        const CLoginActRewardMap::iterator &it=LoginActRewardMap.find(id);
        if(it!=LoginActRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Lottery* getLottery(UINT32 id)
    {
        const CLotteryMap::iterator &it=LotteryMap.find(id);
        if(it!=LotteryMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LotteryBase* getLotteryBase(UINT32 id)
    {
        const CLotteryBaseMap::iterator &it=LotteryBaseMap.find(id);
        if(it!=LotteryBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LuckyTurntable* getLuckyTurntable(UINT32 id)
    {
        const CLuckyTurntableMap::iterator &it=LuckyTurntableMap.find(id);
        if(it!=LuckyTurntableMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LuckyTurntableBase* getLuckyTurntableBase(UINT32 id)
    {
        const CLuckyTurntableBaseMap::iterator &it=LuckyTurntableBaseMap.find(id);
        if(it!=LuckyTurntableBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LuckyTurntableItems* getLuckyTurntableItems(UINT32 id)
    {
        const CLuckyTurntableItemsMap::iterator &it=LuckyTurntableItemsMap.find(id);
        if(it!=LuckyTurntableItemsMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const LuckyTurntableValue* getLuckyTurntableValue(UINT32 id)
    {
        const CLuckyTurntableValueMap::iterator &it=LuckyTurntableValueMap.find(id);
        if(it!=LuckyTurntableValueMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MailDouble* getMailDouble(UINT32 id)
    {
        const CMailDoubleMap::iterator &it=MailDoubleMap.find(id);
        if(it!=MailDoubleMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Misc* getMisc(UINT32 id)
    {
        const CMiscMap::iterator &it=MiscMap.find(id);
        if(it!=MiscMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MonsterBase* getMonsterBase(UINT32 id)
    {
        const CMonsterBaseMap::iterator &it=MonsterBaseMap.find(id);
        if(it!=MonsterBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MonsterProperty* getMonsterProperty(UINT32 id)
    {
        const CMonsterPropertyMap::iterator &it=MonsterPropertyMap.find(id);
        if(it!=MonsterPropertyMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MonsterStrength* getMonsterStrength(UINT32 id)
    {
        const CMonsterStrengthMap::iterator &it=MonsterStrengthMap.find(id);
        if(it!=MonsterStrengthMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Mounts* getMounts(UINT32 id)
    {
        const CMountsMap::iterator &it=MountsMap.find(id);
        if(it!=MountsMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MountsEquip* getMountsEquip(UINT32 id)
    {
        const CMountsEquipMap::iterator &it=MountsEquipMap.find(id);
        if(it!=MountsEquipMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MountsEquipment* getMountsEquipment(UINT32 id)
    {
        const CMountsEquipmentMap::iterator &it=MountsEquipmentMap.find(id);
        if(it!=MountsEquipmentMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MountsStar* getMountsStar(UINT32 id)
    {
        const CMountsStarMap::iterator &it=MountsStarMap.find(id);
        if(it!=MountsStarMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MountsTrain* getMountsTrain(UINT32 id)
    {
        const CMountsTrainMap::iterator &it=MountsTrainMap.find(id);
        if(it!=MountsTrainMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Mysticshop* getMysticshop(UINT32 id)
    {
        const CMysticshopMap::iterator &it=MysticshopMap.find(id);
        if(it!=MysticshopMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const MysticshopRefreshCost* getMysticshopRefreshCost(UINT32 id)
    {
        const CMysticshopRefreshCostMap::iterator &it=MysticshopRefreshCostMap.find(id);
        if(it!=MysticshopRefreshCostMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const NewYearActivity* getNewYearActivity(UINT32 id)
    {
        const CNewYearActivityMap::iterator &it=NewYearActivityMap.find(id);
        if(it!=NewYearActivityMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const NewYearActivityBase* getNewYearActivityBase(UINT32 id)
    {
        const CNewYearActivityBaseMap::iterator &it=NewYearActivityBaseMap.find(id);
        if(it!=NewYearActivityBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const NewYearRecycle* getNewYearRecycle(UINT32 id)
    {
        const CNewYearRecycleMap::iterator &it=NewYearRecycleMap.find(id);
        if(it!=NewYearRecycleMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Pay* getPay(UINT32 id)
    {
        const CPayMap::iterator &it=PayMap.find(id);
        if(it!=PayMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PayRebate* getPayRebate(UINT32 id)
    {
        const CPayRebateMap::iterator &it=PayRebateMap.find(id);
        if(it!=PayRebateMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PaySum* getPaySum(UINT32 id)
    {
        const CPaySumMap::iterator &it=PaySumMap.find(id);
        if(it!=PaySumMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakArena* getPeakArena(UINT32 id)
    {
        const CPeakArenaMap::iterator &it=PeakArenaMap.find(id);
        if(it!=PeakArenaMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakArenaBase* getPeakArenaBase(UINT32 id)
    {
        const CPeakArenaBaseMap::iterator &it=PeakArenaBaseMap.find(id);
        if(it!=PeakArenaBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakArenaFormat* getPeakArenaFormat(UINT32 id)
    {
        const CPeakArenaFormatMap::iterator &it=PeakArenaFormatMap.find(id);
        if(it!=PeakArenaFormatMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakArenaMatch* getPeakArenaMatch(UINT32 id)
    {
        const CPeakArenaMatchMap::iterator &it=PeakArenaMatchMap.find(id);
        if(it!=PeakArenaMatchMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakArenaReward* getPeakArenaReward(UINT32 id)
    {
        const CPeakArenaRewardMap::iterator &it=PeakArenaRewardMap.find(id);
        if(it!=PeakArenaRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakRobot* getPeakRobot(UINT32 id)
    {
        const CPeakRobotMap::iterator &it=PeakRobotMap.find(id);
        if(it!=PeakRobotMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PeakUse* getPeakUse(UINT32 id)
    {
        const CPeakUseMap::iterator &it=PeakUseMap.find(id);
        if(it!=PeakUseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PowerSet* getPowerSet(UINT32 id)
    {
        const CPowerSetMap::iterator &it=PowerSetMap.find(id);
        if(it!=PowerSetMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const PushMessages* getPushMessages(UINT32 id)
    {
        const CPushMessagesMap::iterator &it=PushMessagesMap.find(id);
        if(it!=PushMessagesMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const QuenchProp* getQuenchProp(UINT32 id)
    {
        const CQuenchPropMap::iterator &it=QuenchPropMap.find(id);
        if(it!=QuenchPropMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const QuenchRand* getQuenchRand(UINT32 id)
    {
        const CQuenchRandMap::iterator &it=QuenchRandMap.find(id);
        if(it!=QuenchRandMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const QuestionPoints* getQuestionPoints(UINT32 id)
    {
        const CQuestionPointsMap::iterator &it=QuestionPointsMap.find(id);
        if(it!=QuestionPointsMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const QuestionRank* getQuestionRank(UINT32 id)
    {
        const CQuestionRankMap::iterator &it=QuestionRankMap.find(id);
        if(it!=QuestionRankMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Ranking* getRanking(UINT32 id)
    {
        const CRankingMap::iterator &it=RankingMap.find(id);
        if(it!=RankingMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const RecruitBase* getRecruitBase(UINT32 id)
    {
        const CRecruitBaseMap::iterator &it=RecruitBaseMap.find(id);
        if(it!=RecruitBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Rising* getRising(UINT32 id)
    {
        const CRisingMap::iterator &it=RisingMap.find(id);
        if(it!=RisingMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Robot* getRobot(UINT32 id)
    {
        const CRobotMap::iterator &it=RobotMap.find(id);
        if(it!=RobotMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const RobotEquip* getRobotEquip(UINT32 id)
    {
        const CRobotEquipMap::iterator &it=RobotEquipMap.find(id);
        if(it!=RobotEquipMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const RoleBase* getRoleBase(UINT32 id)
    {
        const CRoleBaseMap::iterator &it=RoleBaseMap.find(id);
        if(it!=RoleBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const RoleExp* getRoleExp(UINT32 id)
    {
        const CRoleExpMap::iterator &it=RoleExpMap.find(id);
        if(it!=RoleExpMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const RoleNameBase* getRoleNameBase(UINT32 id)
    {
        const CRoleNameBaseMap::iterator &it=RoleNameBaseMap.find(id);
        if(it!=RoleNameBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Scene* getScene(UINT32 id)
    {
        const CSceneMap::iterator &it=SceneMap.find(id);
        if(it!=SceneMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SevenDayShop* getSevenDayShop(UINT32 id)
    {
        const CSevenDayShopMap::iterator &it=SevenDayShopMap.find(id);
        if(it!=SevenDayShopMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SevenDayTask* getSevenDayTask(UINT32 id)
    {
        const CSevenDayTaskMap::iterator &it=SevenDayTaskMap.find(id);
        if(it!=SevenDayTaskMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ShopReset* getShopReset(UINT32 id)
    {
        const CShopResetMap::iterator &it=ShopResetMap.find(id);
        if(it!=ShopResetMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Shopitem* getShopitem(UINT32 id)
    {
        const CShopitemMap::iterator &it=ShopitemMap.find(id);
        if(it!=ShopitemMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SignPay* getSignPay(UINT32 id)
    {
        const CSignPayMap::iterator &it=SignPayMap.find(id);
        if(it!=SignPayMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SignReward* getSignReward(UINT32 id)
    {
        const CSignRewardMap::iterator &it=SignRewardMap.find(id);
        if(it!=SignRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Skill* getSkill(UINT32 id)
    {
        const CSkillMap::iterator &it=SkillMap.find(id);
        if(it!=SkillMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SkillElement* getSkillElement(UINT32 id)
    {
        const CSkillElementMap::iterator &it=SkillElementMap.find(id);
        if(it!=SkillElementMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SkillGift* getSkillGift(UINT32 id)
    {
        const CSkillGiftMap::iterator &it=SkillGiftMap.find(id);
        if(it!=SkillGiftMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SkillPoint* getSkillPoint(UINT32 id)
    {
        const CSkillPointMap::iterator &it=SkillPointMap.find(id);
        if(it!=SkillPointMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SkillTree* getSkillTree(UINT32 id)
    {
        const CSkillTreeMap::iterator &it=SkillTreeMap.find(id);
        if(it!=SkillTreeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Skin* getSkin(UINT32 id)
    {
        const CSkinMap::iterator &it=SkinMap.find(id);
        if(it!=SkinMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SnowmanBase* getSnowmanBase(UINT32 id)
    {
        const CSnowmanBaseMap::iterator &it=SnowmanBaseMap.find(id);
        if(it!=SnowmanBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SnowmanFlushTime* getSnowmanFlushTime(UINT32 id)
    {
        const CSnowmanFlushTimeMap::iterator &it=SnowmanFlushTimeMap.find(id);
        if(it!=SnowmanFlushTimeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SnowmanItem* getSnowmanItem(UINT32 id)
    {
        const CSnowmanItemMap::iterator &it=SnowmanItemMap.find(id);
        if(it!=SnowmanItemMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SnowmanQuestion* getSnowmanQuestion(UINT32 id)
    {
        const CSnowmanQuestionMap::iterator &it=SnowmanQuestionMap.find(id);
        if(it!=SnowmanQuestionMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SoulCost* getSoulCost(UINT32 id)
    {
        const CSoulCostMap::iterator &it=SoulCostMap.find(id);
        if(it!=SoulCostMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SoulSkill* getSoulSkill(UINT32 id)
    {
        const CSoulSkillMap::iterator &it=SoulSkillMap.find(id);
        if(it!=SoulSkillMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SpeBase* getSpeBase(UINT32 id)
    {
        const CSpeBaseMap::iterator &it=SpeBaseMap.find(id);
        if(it!=SpeBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SpeBox* getSpeBox(UINT32 id)
    {
        const CSpeBoxMap::iterator &it=SpeBoxMap.find(id);
        if(it!=SpeBoxMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SpeRefCost* getSpeRefCost(UINT32 id)
    {
        const CSpeRefCostMap::iterator &it=SpeRefCostMap.find(id);
        if(it!=SpeRefCostMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SpecialShop* getSpecialShop(UINT32 id)
    {
        const CSpecialShopMap::iterator &it=SpecialShopMap.find(id);
        if(it!=SpecialShopMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SpiritPurchase* getSpiritPurchase(UINT32 id)
    {
        const CSpiritPurchaseMap::iterator &it=SpiritPurchaseMap.find(id);
        if(it!=SpiritPurchaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const StaminaPurchase* getStaminaPurchase(UINT32 id)
    {
        const CStaminaPurchaseMap::iterator &it=StaminaPurchaseMap.find(id);
        if(it!=StaminaPurchaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const StaminaReward* getStaminaReward(UINT32 id)
    {
        const CStaminaRewardMap::iterator &it=StaminaRewardMap.find(id);
        if(it!=StaminaRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const StaminaRewardBase* getStaminaRewardBase(UINT32 id)
    {
        const CStaminaRewardBaseMap::iterator &it=StaminaRewardBaseMap.find(id);
        if(it!=StaminaRewardBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const StaminaRewardDropbox* getStaminaRewardDropbox(UINT32 id)
    {
        const CStaminaRewardDropboxMap::iterator &it=StaminaRewardDropboxMap.find(id);
        if(it!=StaminaRewardDropboxMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const StarCondition* getStarCondition(UINT32 id)
    {
        const CStarConditionMap::iterator &it=StarConditionMap.find(id);
        if(it!=StarConditionMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const SysSwitch* getSysSwitch(UINT32 id)
    {
        const CSysSwitchMap::iterator &it=SysSwitchMap.find(id);
        if(it!=SysSwitchMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Task* getTask(UINT32 id)
    {
        const CTaskMap::iterator &it=TaskMap.find(id);
        if(it!=TaskMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TaskType* getTaskType(UINT32 id)
    {
        const CTaskTypeMap::iterator &it=TaskTypeMap.find(id);
        if(it!=TaskTypeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const ToolResult* getToolResult(UINT32 id)
    {
        const CToolResultMap::iterator &it=ToolResultMap.find(id);
        if(it!=ToolResultMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Tower* getTower(UINT32 id)
    {
        const CTowerMap::iterator &it=TowerMap.find(id);
        if(it!=TowerMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TowerAward* getTowerAward(UINT32 id)
    {
        const CTowerAwardMap::iterator &it=TowerAwardMap.find(id);
        if(it!=TowerAwardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TowerNormalAward* getTowerNormalAward(UINT32 id)
    {
        const CTowerNormalAwardMap::iterator &it=TowerNormalAwardMap.find(id);
        if(it!=TowerNormalAwardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TrialBase* getTrialBase(UINT32 id)
    {
        const CTrialBaseMap::iterator &it=TrialBaseMap.find(id);
        if(it!=TrialBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TrialFirstMatching* getTrialFirstMatching(UINT32 id)
    {
        const CTrialFirstMatchingMap::iterator &it=TrialFirstMatchingMap.find(id);
        if(it!=TrialFirstMatchingMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TrialReward* getTrialReward(UINT32 id)
    {
        const CTrialRewardMap::iterator &it=TrialRewardMap.find(id);
        if(it!=TrialRewardMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TrialRewardRead* getTrialRewardRead(UINT32 id)
    {
        const CTrialRewardReadMap::iterator &it=TrialRewardReadMap.find(id);
        if(it!=TrialRewardReadMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const TrialRewardVIP* getTrialRewardVIP(UINT32 id)
    {
        const CTrialRewardVIPMap::iterator &it=TrialRewardVIPMap.find(id);
        if(it!=TrialRewardVIPMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Upgrade* getUpgrade(UINT32 id)
    {
        const CUpgradeMap::iterator &it=UpgradeMap.find(id);
        if(it!=UpgradeMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const Vip* getVip(UINT32 id)
    {
        const CVipMap::iterator &it=VipMap.find(id);
        if(it!=VipMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const VipBase* getVipBase(UINT32 id)
    {
        const CVipBaseMap::iterator &it=VipBaseMap.find(id);
        if(it!=VipBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const VipCount* getVipCount(UINT32 id)
    {
        const CVipCountMap::iterator &it=VipCountMap.find(id);
        if(it!=VipCountMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const VipFunction* getVipFunction(UINT32 id)
    {
        const CVipFunctionMap::iterator &it=VipFunctionMap.find(id);
        if(it!=VipFunctionMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const VipGift* getVipGift(UINT32 id)
    {
        const CVipGiftMap::iterator &it=VipGiftMap.find(id);
        if(it!=VipGiftMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }
    const WelfareBase* getWelfareBase(UINT32 id)
    {
        const CWelfareBaseMap::iterator &it=WelfareBaseMap.find(id);
        if(it!=WelfareBaseMap.end())
        {
            return &it->second;
        }else{
            return nullptr;
        }
    }

};
#endif