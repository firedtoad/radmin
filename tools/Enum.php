<?php
header("Content-Type:text/html;charset=UTF8");
$folder='../../configs/gameserver/configs/';
$dir = $folder.'RoleBase.xml';
$hdir = $folder.'HeroBase.xml';
$mdir = $folder.'Email.xml';
$msdir = $folder.'Misc.xml';
$equipdir = $folder.'EquipBase.xml';
$vipdir = $folder.'VipBase.xml';
$arenadir = $folder.'ArenaBase.xml';
$recruitdir = $folder.'RecruitBase.xml';
$campdir = $folder.'CampBase.xml';
$guilddir = $folder.'GuildBase.xml';
$tdir = $folder.'TaskType.xml';
$tchannel = $folder.'ChannelBase.xml';
$tchat = $folder.'ChatBase.xml';
$triabase = $folder.'TrialBase.xml';
$namebase = $folder.'RoleNameBase.xml';
$noticebase = $folder.'ChatNotice.xml';
$rankbase = $folder.'AllRank.xml';
$logbase = $folder.'GuildLog.xml';
$activebase = $folder.'ActivityBase.xml';
$costbase = $folder.'CostBase.xml';
$toolresult=$folder.'ToolResult.xml';
/**
 * @var $xml SimpleXMLElement
 */
function enum($dir,$key='Des',$kid='ID'){
$xml=simplexml_load_file($dir);
$base=strtoupper(str_replace(".xml",'',basename($dir)))."_";
$ess="enum {\n";
$first=1;
$len=45;
foreach ($xml as $k=>$v)
{
    $sx=($v->attributes()->Key);
    $id=($v->attributes()->$kid);
    $sd=($v->attributes()->$key);
    $sx=strtoupper($sx);
    $ls='';
    if($first)
    {
         $ls.="    $base$sx=$id,";
         $ls.=str_repeat(' ',$len-strlen($ls));
         $ls.="//$sd\n";
        $first=0;
    }else{
        $ls="    $base$sx=$id,";
        $ls.=str_repeat(' ',$len-strlen($ls));
         $ls.="//$sd\n";
    }
    $ess.=$ls;
}
$ess.="};";
return $ess;
}

$ess=enum($dir);
$hss=enum($hdir,'Des','HeroBaseID');
$mss=enum($mdir,"Titile");
$msss=enum($msdir);
$esss=enum($equipdir);
$vsss=enum($vipdir);
$asss=enum($arenadir);
$rsss=enum($recruitdir);
$csss=enum($campdir);
$gsss=enum($guilddir,'Des','GuildBaseID');
$tsss=enum($tdir,'Des','ID');
$chsss=enum($tchannel);
$ctsss=enum($tchat);
$trsss=enum($triabase);
$nasss=enum($namebase);
$cnsss=enum($noticebase);
$rksss=enum($rankbase);
$lgsss=enum($logbase,'Content','ID');
$actsss=enum($activebase);
$cosss=enum($costbase);
$tolss=enum($toolresult);
//echo $hss;
