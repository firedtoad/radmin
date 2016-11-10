<?php
include_once 'Enum.php';

$vecMap=array(
'Shopitem'=>array('key1'=>'ShopID','key2'=>'ShopItemID'),
'HeroExp'=>array('key1'=>'ExpIndex','key2'=>'Level'),
'Dropbox'=>array('key1'=>'DropboxID','key2'=>'ItemID'),
'TrialReward'=>array('key1'=>'Level','key2'=>'changePoint'),
'Growing'=>array('key1'=>'Prob','key2'=>'ID'),
'HeroRecycle'=>array('key1'=>'Grade','key2'=>'Quality'),
'GuildChapterFight'=>array('key1'=>'FightID','key2'=>'FightSequence'),
'BossDrop'=>array('key1'=>'GuildLv','key2'=>'Energy'),
'MonsterProperty'=>array('key1'=>'Job','key2'=>'MonsterLv'),
'SkillTree'=>array('key1'=>'Sex','key2'=>'PositionID'),
'Task'=>array('key1'=>'RoleLevel','key2'=>'TaskID'),
'LoginActReward'=>array('key1'=>'RewardType','key2'=>'Days'),
'SignReward'=>array('key1'=>'Month','key2'=>'Days'),
'Robot'=>array('key1'=>'roleLv','key2'=>'GiftID'),
'ShopReset'=>array('key1'=>'ShopID','key2'=>'ResetTime'),
'CampThroughItem'=>array('key1'=>'Level','key2'=>'Through'),
'DailySumPayReward'=>array('key1'=>'Day','key2'=>'Index'),
'Box'=>array('key1'=>'Level','key2'=>'Item'),
'Box'=>array('key1'=>'Level','key2'=>'Item'),
'DailySumPayReward'=>array('key1'=>'Day','key2'=>'Index'),
'CampReward'=>array('key1'=>'RewardID','key2'=>'Rank'),
'CampMineProduction'=>array('key1'=>'MineType','key2'=>'PlayerLevel'),
'TrialRewardVIP'=>array('key1'=>'Level','key2'=>'changePoint'),
'HeroStar'=>array('key1'=>'HeroID','key2'=>'Star'),
'HeroStarRecycle'=>array('key1'=>'Star','key2'=>'Quality'),
'SpeBox'=>array('key1'=>'ItemBoxID','key2'=>'ID'),
'Tower'=>array('key1'=>'TowerId','key2'=>'FightsSetId'),
'HeroGiftSkill'=>array('key1'=>'HeroID','key2'=>'GiftLv'),
'Exchange'=>array('key1'=>'ShopItemID','key2'=>'ID'),
'GuildDungeonAward'=>array('key1'=>'Dungeon','key2'=>'Id'),
'SoulSkill'=>array('key1'=>'SkillID','key2'=>'SkillLv'),
'SoulCost'=>array('key1'=>'CostType','key2'=>'SkillLv'),
'StaminaRewardDropbox'=>array('key1'=>'DropboxID','key2'=>'ID'),
'SevenDayTask'=>array('key1'=>'Day','key2'=>'ID'),
'ArtifactStrengthen'=>array('key1'=>'Type','key2'=>'Level'),
'ArtifactStar'=>array('key1'=>'Type','key2'=>'Star'),
);

header ( "Content-Type:text/html;charset=UTF8" );
$dir = $folder.'*';
$d = glob ( $dir );
$str = '';
$kst = '';
$est = "\n\n";
$tmap='';
$len=40;
$str_len=1;
$vector_len=3;
$def='private:'."\n";
$loaders='';
$call_loaders='';
$load_def='';

$init_declare='';
$init_define='';
$vecmap_typedef='';
$vecmap_define='';
$getvecmap='';
$getvecmap_2param='';
$call_init_define='';


$find_func='';
$getmap='';

$reloaders='std::unordered_map<string,std::function<BOOL(XmlConfig*)>> loaders={'."\n";
foreach ( $d as $f ) {
    if(is_dir($f))
    {
        continue;
    }
 $bname = basename ( $f );
 $bname = str_replace ( ".xml", '', $bname );
 $xml = simplexml_load_file ( $f );
 $keys = array_keys ( ( array ) $xml );
// print_r($keys[0]);
// echo $keys[0]===0;
// if($keys[0]===0)continue;
 $et = "extern KeyType $bname" . "Keys[#];\n\n";
 $kt = "KeyType $bname" . "Keys[]={\n";
 $st = "struct $bname {\n";
 $lmap = 'typedef unordered_map<'.'UINT32,'."$bname> C$bname"."Map;\n";
 $ldef="    C$bname"."Map $bname"."Map;\n";
 $keys_name=$bname."Keys";
 $map_name=$bname."Map";
 $lloader_def="    BOOL Load$bname();\n";
 $reloaders.="std::pair<string,std::function<BOOL(XmlConfig*)>>(\"$bname\",std::mem_fun(&XmlConfig::Load$bname)),\n";
 $llfind="    const $bname* get$bname(UINT32 id)\n    {\n        const C$bname"."Map::iterator &it=$bname"."Map.find(id);\n        if(it!=$bname"."Map.end())\n        {\n            return &it->second;\n        }else{\n            return nullptr;\n        }\n    }\n";
 if(!isset($vecMap[$bname]))
 {
 $loader="BOOL XmlConfig::Load$bname()\n{\n    string pfile=cpath+\"$bname.xml\";\n    return  LoadCommon(pfile.c_str(),$keys_name,ARRSIZE($keys_name),$map_name);\n}\n\n";
 }else{
     $loader="BOOL XmlConfig::Load$bname()\n{\n    string pfile=cpath+\"$bname.xml\";\n    if(LoadCommon(pfile.c_str(),$keys_name,ARRSIZE($keys_name),$map_name)){\n        return Init$bname"."MapMap();\n    }\n    return 1;\n}\n\n";
 }
 
 $lgetmap="    const C$map_name& get$map_name() const
    {
        return $map_name;
    }\n";
if(isset($vecMap[$bname]))
{
    $key1=$vecMap[$bname]['key1'];
    $key2=$vecMap[$bname]['key2'];
    $lvecmap_typedef = 'typedef unordered_map<'.'UINT32,unordered_map<UINT32,'."$bname>> C$bname"."VectorMap;\n";
    $lvecmap_define="    C$bname"."VectorMap $bname"."MapMap;\n";
    $linit_declare="    BOOL Init$bname"."MapMap();\n";
    $linit_define="BOOL XmlConfig::Init$bname"."MapMap()\n{\n    return InitMapMap(offsetof($bname,$key1),offsetof($bname,$key2),$bname"."Map,$bname"."MapMap);    \n}\n";
    $lgetvecmap="    unordered_map<UINT32,$bname>& get$bname"."MapBy$key1(UINT32 id)\n    {\n        return $bname"."MapMap[id];    \n    }\n";
    $lgetvecmap_2param="    const $bname* get$bname"."by$key1"."And$key2(UINT32 $key1,UINT32 $key2)\n    {
        auto &mp=$bname"."MapMap[$key1];
        if(mp.size()>0)
        {
            auto it=mp.find($key2);
            if(it!=mp.end())
            {
                return &it->second;
            }else{
                return nullptr;
            }
        }   
        return nullptr;
    }\n";
    $init_declare.=$linit_declare;
    $init_define.=$linit_define;
    $vecmap_typedef.=$lvecmap_typedef;
    $vecmap_define.=$lvecmap_define;
    $getvecmap.=$lgetvecmap;
    $getvecmap_2param.=$lgetvecmap_2param;
    $lcall_init_define="    Init$bname"."MapMap();\n";
    //$call_init_define.=$lcall_init_define;
} 

 $getmap.=$lgetmap;
 $call_loader="    Load$bname();\n";
 $find_func.=$llfind;
 $call_loaders.=$call_loader;
 $load_def.=$lloader_def;
 $loaders.=$loader;
 $file = file_get_contents ( $f );
 $sp=strpos($file,'<!--');
 $ep=strpos($file,'-->');
 $file=substr($file,$sp, $ep-$sp);
 $file=explode("\n",$file);
// echo $f,"\n";
//// print_r($file);
//print_r($file);
 $ss=preg_split('/ {1,}/',$file[1]);
 $stype=preg_split('/ {1,}/', $file[2]);

if(count($ss)!=count($stype))
{
    print_r($ss);
    print_r($stype);
    echo $f;
    echo "comment don't match types";
//	continue;
}
 foreach ( $xml->{$keys [0]} as $kx => $r ) {
  
  $i = 0;
  $j = 0;
  $si=0;
  $m=0;
//     print_r($r->attributes ());
  foreach ( $r->attributes () as $k => $v ) {
   $type = gettype ( $v );

   $j++;
   if(!isset($stype[$m]))
   {
        print_r($r->attributes ());
       print_r($stype);
       print_r($file);
//   	   exit();
   }

   
   switch(strtolower($stype[$m++]))
   {
        
//    case 'in':
    case 'int':
        $ust = "    UINT32 " . $k . ";"; 
        $ust.=str_repeat(' ',$len-strlen($ust));
        
        $st.=$ust."//".$ss[$si++]."\n";
        $kt .= '    {"' . $k . '",0,' . "offsetof($bname,$k) ". '},' . "\n";
    break;
    case 'string':
     $ust = "    string " . $k . ";";    //".$ss[$si++]."\n";
        $ust.=str_repeat(' ',$len-strlen($ust));
        $st.=$ust."//".$ss[$si++]."\n";
         $kt .= '    {"' . $k . '",1,' . "offsetof($bname,$k) " . '},' . "\n";
    break;
    case 'list:int':
         $ust = "    vector<int> " . $k . ";";    //".$ss[$si++]."\n";
         $ust.=str_repeat(' ',$len-strlen($ust));
         $st.=$ust."//".$ss[$si++]."\n";
         $kt .= '    {"' . $k . '",3,' . "offsetof($bname,$k) " . '},' . "\n";
        break;
   	case 'list:string':
         $ust = "    vector<string> " . $k . ";";    //".$ss[$si++]."\n";
         $ust.=str_repeat(' ',$len-strlen($ust));
         $st.=$ust."//".$ss[$si++]."\n";
         $kt .= '    {"' . $k . '",4,' . "offsetof($bname,$k) " . '},' . "\n";
        break;
   	case 'list:idcount':
         $ust = "    vector<IdCount> " . $k . ";";    //".$ss[$si++]."\n";
         $ust.=str_repeat(' ',$len-strlen($ust));
         $st.=$ust."//".$ss[$si++]."\n";
         $kt .= '    {"' . $k . '",5,' . "offsetof($bname,$k) " . '},' . "\n";
        break;
   	case 'float':
         $ust = "    float " . $k . ";";    //".$ss[$si++]."\n";
         $ust.=str_repeat(' ',$len-strlen($ust));
         $st.=$ust."//".$ss[$si++]."\n";
         $kt .= '    {"' . $k . '",6,' . "offsetof($bname,$k) " . '},' . "\n";
        break;
   	case 'list:float':
         $ust = "    vector<float> " . $k . ";";    //".$ss[$si++]."\n";
         $ust.=str_repeat(' ',$len-strlen($ust));
         $st.=$ust."//".$ss[$si++]."\n";
         $kt .= '    {"' . $k . '",7,' . "offsetof($bname,$k) " . '},' . "\n";
        break;
        default:
            print_r($ss);
            print_r($stype);
            echo $stype[$m-1];
            break;
   }
   
  }
  $et = str_replace ( "#", $j, $et );
    
  break;
 }
 
 $kt = substr ( $kt, 0, strlen ( $kt ) - 2 );
 $st .= "};\n";
 $kt .= "\n};\n";

 $tmap.=$lmap;
 $def.=$ldef;
 $est .= $et;
 $kst .= $kt;
 $str .= $st;
 
 // break;
}
 $reloaders .= "};\n";
global $hss;
global $mss;
global $msss;
global $esss;
global $vsss;
global $asss;
global $rsss;
global $csss;
global $gsss;
global $tsss;
global $chsss;
global $ctsss;
global $trsss;
global $nasss;
global $cnsss;
global $rksss;
global $lgsss;
global $actsss;
global $cosss;
global $tolss;
global $pushss;
global $GuildBattleChatEnum;
global $specialbase;
global $ltorrybase;
global $TopArenaBaseEnum;
global $syssss;
global $wsss;
global $psss;
global $snowss;
global $forms;
global $acsss;
global $expchange;
global $lksss;
global $starmrb;
global $ArtifacRankBaseVal;
$header=<<<EOT
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
$ess
$hss 
$mss
$msss
$esss
$vsss
$asss
$rsss
$csss
$gsss
$tsss
$chsss
$ctsss
$trsss
$nasss
$cnsss
$rksss
$lgsss
$actsss
$cosss
$tolss
$pushss
$GuildBattleChatEnum
$specialbase
$ltorrybase
$TopArenaBaseEnum
$syssss
$wsss
$psss
$snowss
$forms
$acsss
$expchange
$lksss
$starmrb
$ArtifacRankBaseVal
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

EOT;

$header_cpp=<<<EOT
#include"TinyXml/tinystr.h"
#include"TinyXml/tinyxml.h"
#include"XmlStruct.h"
#include <string.h>
#include<stddef.h>
#include "Protocol/PubFunDef.h"
#include <boost/uuid/random_generator.hpp>
using namespace PubFunDef;

EOT;

$mid=<<<EOT
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

EOT;

$pop="#pragma pack(pop)\n";

$cpp_mid=<<<EOT
XmlConfig::XmlConfig ()
{
   // FileKeys["Buff"]=BuffMap;
}

BOOL XmlConfig::LoadAll()
{
#LOADERS
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

$reloaders

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

EOT;
echo "<pre>";
$class_def="class XmlConfig :public noncopy
{\n";

echo $str;
echo $kst;
echo $est;
echo $tmap;
echo $vecmap_typedef;
echo $def;
echo $vecmap_define;
echo $loaders;
echo $getvecmap;
echo $call_loaders;
echo $load_def;
echo $init_declare;
echo $find_func;
echo $init_define;
echo $reloaders;





$headstr=$header.$str;

$cpp_mid=str_replace('#LOADERS', $call_loaders.$call_init_define, $cpp_mid);
file_put_contents("XmlStruct.h", $headstr.$pop.$est.$tmap.$vecmap_typedef.$class_def.$def.$vecmap_define.$mid.$load_def.$init_declare.$getmap.$getvecmap.$getvecmap_2param.$find_func."\n};\n#endif");
file_put_contents("XmlStruct.cpp", $header_cpp.$kst.$loaders.$init_define.$cpp_mid);


echo "</pre>";
