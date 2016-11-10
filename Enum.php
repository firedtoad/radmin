<?php
header("Content-Type:text/html;charset=UTF8");
$folder='F:/work/sanguo/src/configs/gameserver/configs/';
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
$pushmsg=$folder.'PushMessages.xml';
$GuildBattleChat=$folder.'GuildBattleChat.xml';
$SpeBase=$folder.'SpeBase.xml';
$lotterybase=$folder.'LotteryBase.xml';
$TopArenaBase=$folder.'PeakArenaBase.xml';
$sysSwitch=$folder.'SysSwitch.xml';
$warefarebase=$folder.'WelfareBase.xml';
$powersetBase=$folder.'PowerSet.xml';
$SnowmanBase=$folder.'SnowmanBase.xml';
$formstri=$folder.'FormRestrict.xml';
$exchge=$folder.'ExchangeBase.xml';
$activerecruit=$folder.'ActiveRecruitbase.xml';
$luckybase=$folder.'LuckyTurntableBase.xml';
$StaminaRB=$folder.'StaminaRewardBase.xml';
$ArtifacRankBase=$folder.'ArtifacRankBase.xml';

/**
 * @var $xml SimpleXMLElement
 */
function enum($dir,$key='Des',$kid='ID'){
$xml=simplexml_load_file($dir);
$base=strtoupper(str_replace(".xml",'',basename($dir)))."_";
$ess="enum {\n";
$first=1;
$len=80;
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
$pushss=enum($pushmsg,'MessagesDes','MessagesID');
$GuildBattleChatEnum=enum($GuildBattleChat);
$specialbase=enum($SpeBase);
$ltorrybase=enum($lotterybase);
$TopArenaBaseEnum=enum($TopArenaBase);
$syssss=enum($sysSwitch,'Key','ID');
$wsss=enum($warefarebase);
$psss=enum($powersetBase);
$snowss=enum($SnowmanBase);
$forms=enum($formstri);
$acsss=enum($activerecruit);
$expchange=enum($exchge);
$lksss=enum($luckybase);
$starmrb=enum($StaminaRB);
$ArtifacRankBaseVal=enum($ArtifacRankBase);
//echo $hss;
