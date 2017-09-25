<?php
//Copy this file to config.inc.php and make changes to that file to customize your configuration.

$config = array(
  'servers' => array(

   [
     'host'=>'cluster:172.18.10.1:7001-7006',
     'hosts'=>['tcp://172.18.10.1:7001', 'tcp://172.18.10.1:7002', 'tcp://172.18.10.1:7003','tcp://172.18.10.1:7004','tcp://172.18.10.1:7005','tcp://172.18.10.1:7006'],
     'options'=>['cluster'=>'redis']

   ],
    [
     'host'=>'cluster:172.18.40.3:7001-7006',
     'hosts'=>['tcp://172.18.40.3:7001','tcp://172.18.40.3:7002', 'tcp://172.18.40.3:7003','tcp://172.18.40.3:7004','tcp://172.18.40.3:7005','tcp://172.18.40.3:7006'],
     'options'=>['cluster'=>'redis']
   ],
   [ 
      'name' => '172.18.40.3',
      'host' => '172.18.40.3',
      'port' => 6379,
      'filter' => '*',
    ],
       [ 
      'name' => '172.18.10.1',
      'host' => '172.18.10.1',
      'port' => 6379,
      'filter' => '*',
    ],
    /*array(
      'host' => 'localhost',
      'port' => 6380
    ),*/

    /*array(
      'name' => 'local db 2',
      'host' => 'localhost',
      'port' => 6379,
      'db'   => 1 // Optional database number, see http://redis.io/commands/select
      'filter' => 'something:*' // Show only parts of database for speed or security reasons
      'seperator' => '/', // Use a different seperator on this database
      'flush' => false, // Set to true to enable the flushdb button for this instance.
      'encoding' => 'cp1251', // Set for view values in other encoding
    )*/
  ),


  'seperator' => ':',


  // Uncomment to show less information and make phpRedisAdmin fire less commands to the Redis server. Recommended for a really busy Redis server.
  //'faster' => true,


  // Uncomment to enable HTTP authentication
  /*'login' => array(
    // Username => Password
    // Multiple combinations can be used
    'admin' => array(
      'password' => 'adminpassword',
    ),
    'guest' => array(
      'password' => '',
      'servers'  => array(1) // Optional list of servers this user can access.
    )
  ),*/


  // You can ignore settings below this point.

  'maxkeylen'           => 100,
  'count_elements_page' => 100
);

?>
