<?php
header("Content-Type:text/html;charset=UTF8");
$src_dir='F:/work/sanguo/src/gameserver';
$data_dir='F:/work/sanguo/src/datacenter';
$f='F:/work/sanguo/src/Protocol/ErrorCode.h';
$f1='F:/work/sanguo/src/Protocol/ErrorsArena.h';
$f2='F:/work/sanguo/src/Protocol/ErrorsCamp.h';
$f3='F:/work/sanguo/src/Protocol/ErrorsCommon.h';
$f4='F:/work/sanguo/src/Protocol/ErrorsCurrency.h';
$f5='F:/work/sanguo/src/Protocol/ErrorsMail.h';
$f6='F:/work/sanguo/src/Protocol/ErrorsBattleReport.h';
$f7='F:/work/sanguo/src/gameserver/battle/Errors.h';
$root=new DOMDocument("1.0", 'UTF-8');
$children=$root->createElement("ErrorCode");
$g_arr=array();

function main($f)
{
    global $children;
    global $root;
    global $g_arr;
    $arr=array();
    $ctx=file_get_contents($f);
    preg_match_all('/\w+_.*=.*/', $ctx, $arr);
    
//        print_r($arr);
    foreach ($arr[0] as $k=>$v) 
    {
        $g=array();
        preg_match('/(.*) {0,}=.*?\/\/\s{0,}(.*?)\s(.*)/', $v, $g);
//        print_r($g);
        if(count($g))
        {
            $g[1]=str_replace(' ', '', $g[1]);
            $g[1]=preg_replace('/\t/', '', $g[1]);
            $g[3]=str_replace(' ', '', $g[3]);
            $g[3]=preg_replace('/\t/', '', $g[3]);
            $child=$root->createElement("row");
            $child->setAttribute("CodeID", $g[2]);
            $child->setAttribute("ErrorDes", $g[1]);
            $child->setAttribute("ErrorDesc", $g[3]);
//            $child->setAttribute("ErrorType", 5);
//            $child->setAttribute("JumpUI", 'null');
            $g_arr[$g[2]]=array('CodeID'=>$g[2],'ErrorDesc'=>$g[3],'ErrorDes'=>$g[1]);
//            $children->appendChild($child);
        }
    }    
}

function cmpfunc($a,$b)
{
    return $a['CodeID']>$b['CodeID'];
}

main($f);
main($f1);
main($f2);
main($f3);
main($f4);
main($f5);
main($f6);
main($f7);
usort($g_arr,'cmpfunc');

function search($file,$cxt)
{   
    $matches=array();
    if(preg_match_all("/$cxt/", file_get_contents($file), $matches))
    {
        return $file;
    }
    return false;
}
function search_all($file,&$files,$cxt)
{
//    echo $file;
   
    if(is_dir($file))
    {
        $tfiles=glob($file.'/*');
        foreach ($tfiles as $k=>$v)
        {
            search_all($v,$files,$cxt);
        }
    }else if(strncasecmp(substr($file, -3,3),'cpp',3)==0){
        $ret=search($file, $cxt);
        if($ret)
        {
            $files[]=$ret;
        }
    }
}

foreach($g_arr as $k=>$v)
{ 
    $files=array();
    search_all($src_dir,$files,$v['ErrorDes']);
    search_all($data_dir,$files,$v['ErrorDes']);
    if(count($files)==0)
    {
        $files[]=$v['ErrorDes'];
          print_r($files);
          continue;
    }
    $child=$root->createElement("row");
    $child->setAttribute("CodeID", $v['CodeID']);
    $child->setAttribute("ErrorDesc", $v['ErrorDesc']);
    $child->setAttribute("ErrorDes", $v['ErrorDes']);
    $children->appendChild($child);
    
}
echo '<pre>';

$root->formatOutput=true;
$root->appendChild($children);
$root->save("D:\\t.xml",LIBXML_NOBLANKS);
echo '</pre>';