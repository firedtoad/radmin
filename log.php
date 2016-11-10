<?php
ini_set('memory_limit', '512M');
header("Content-Type:text/html;charset=UTF8");
//$file='D:\\info';
//echo '<pre>';
//$strs=file($file);
//$g_arr=array();
//$g_keys=array();
//foreach ($strs as $str)
//{
//    
//    $mc=array();
//    if(preg_match_all('/ (\w+)\[([\w]+|[\W]+)\]/', $str, $mc))
//    {
//        $mm=array(); 
//        if(preg_match_all('/- \[(\w+)\] (\w+)/', $str,$mm))
//        {
//            $mc[1]=array_map('strtolower',$mc[1]);
//            array_unshift($mc[1], 'action');
//            array_unshift($mc[2], strtolower($mm[2][0]));
//            array_unshift($mc[1], 'module');
//            array_unshift($mc[2], strtolower($mm[1][0]));
//            foreach($mc[1] as $k)
//            {
//                $g_keys[$k]=1;
//            }
//            $g_arr[]=array_combine($mc[1], $mc[2]);
//        }
////        echo $str,"\n";
//    }
//}
//print_r($g_keys);
//print_r($g_arr);
$key='012345678';
$data="hello world";
echo $o=hash_hmac('md5', $data, $key);
//foreach (range(0,strlen($o)-1) as $i) {
//    $dt=unpack('Cdt',$o[$i]);
//    printf('%x ',$dt['dt']);
//}
var_dump($o);
echo '</pre>'; 