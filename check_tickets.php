<?php
ini_set('output_buffering','off');
define('MYSQL_IP','123.59.44.152');
define('MYSQL_USER','sg');
define('MYSQL_PWD','f3%DEc*io7');
define('MYSQL_PORT','3306');
define('MYSQL_DB','PayCenter_ios');
define('MYSQL_TABLE','tickets');
define('MYSQL_CHARSET','UTF-8');
define('CHECK_URL_SANDBOX' , 'https://sandbox.itunes.apple.com/verifyReceipt');
define('CHECK_URL','https://buy.itunes.apple.com/verifyReceipt');
define('PAY_KEY' , '4ae4f0e2b72246de9a95d183e2503e64');
$link=NULL;

function GetMySql()
{
    global $link;
    if($link==NULL||!mysql_ping($link))
    {
        $link=mysql_connect(MYSQL_IP.':'.MYSQL_PORT,MYSQL_USER,MYSQL_PWD);
        mysql_set_charset(MYSQL_CHARSET);
        mysql_select_db(MYSQL_DB);
    }
    return $link;
}

function ping()
{
    global $link;
    mysql_ping($link);
}

function query($sql)
{
    global $link;
    GetMySql();
    return mysql_query($sql,$link);
}

function getList($sql)
{
    $res=query($sql);
    $ret=array();
    while($row=mysql_fetch_assoc($res))
    {
        $ret[]=$row;
    }
    return $ret;
}


function check_tickets($ticket)
{
        $str='';
        $data=array(
        'receipt-data'=>$ticket,
        'password'=>PAY_KEY,
        );
        $ch = curl_init(CHECK_URL_SANDBOX);
        curl_setopt($ch, CURLOPT_POST,TRUE);
        curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($data));
        curl_setopt($ch, CURLOPT_USERAGENT, 'DJChargeRobot_1.0');
        curl_setopt($ch, CURLOPT_TIMEOUT, 60); 
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
        curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
        $str = curl_exec($ch);
        $ret=json_decode($str,true);
        return $ret;
}
$ping_count=200;
$count=0;
while(1)
{
    $sql='select * from '.MYSQL_TABLE.' where status is null';
    $list=getList($sql);
    if(!count($list))
    {
        usleep(500000);
        if($count++>$ping_count)
        {
            $count=0;
            ping();
        }
    }
  
    foreach ($list as $k=>$v)
    {
        echo "start check order:".$v['orderid']."\n";
        $st=microtime(true);
        $ret=check_tickets($v['ticket']);
        $ed=microtime(true);
        echo "end check order:".$v['orderid']."\n";
        echo "check order cost time:".($ed-$st),"\n";
        if(isset($ret['status']))
        {  echo "order status:".$ret['status'],"\n";
            query(sprintf("update %s set `status`='%d',`appreturn`='%s' where `orderid`='%s'",MYSQL_TABLE,$ret['status'],json_encode($ret),$v['orderid']));
            echo "update order:".$v['orderid']."\n";
        }
    }
    
}