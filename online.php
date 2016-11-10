<?php
function insertMySql($sql)
{
    $ip='211.95.2.222:3306';
    $u='root';
    $p='root';
    $db='GM';
    $charset='UTF-8';
    mysql_connect($ip,$u,$p);
    mysql_set_charset($charset);
    mysql_select_db($db);
    mysql_query($sql);
    mysql_close();
}
while(1)
{
    `grep  -o -P "ServerType.* (\w+):(\d+)" log.log >info`;
    $str=file('info');
    $info=array();
    $flen=0;
    if(file_exists('flen'))
    {
        $flen=intval(file_get_contents('flen'));
        if(count($str)<$flen)
        {
            $flen=0;
        }
    }
    $i=0;
    foreach ($str as $value) {
        if($i++<$flen)continue;
        $mc=array();
        if(preg_match_all('/(\w+):(\d+)/', $value, $mc))
        {
            $arr=array();
            foreach ($mc[1] as $k=>$v) 
            {
                $arr[$v]=$mc[2][$k];
            }
            $arr['Time']=sprintf('%d%02d%02d',$arr['Today'],$arr['Hour'],$arr['Minute']);
            unset($arr['Hour'],$arr['Minute'],$arr['Today']);
            $info[]=$arr;
        }
    }
    file_put_contents('flen', count($str));
    $sql='REPLACE INTO GMonline(`ServerType`,`OnlinePlayers`,`Time`) VALUES ';
    if(count($info))
    {
        foreach ($info as $value) {
        $sql.= '('.join(',',$value).'),';
        }
        $sql=substr($sql,0, -1);
        insertMySql($sql);
    }
    sleep(300);

}