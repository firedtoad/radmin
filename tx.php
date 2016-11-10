<?php
$a=array('a'=>1,'b'=>2,'c'=>3);
$fmt='c/c/c';
$ufmt='ca/cb/cc';
$dt=pack($fmt,$a['a'],$a['b'],$a['c']);
var_dump($dt);
$data=unpack($ufmt, $dt);
var_dump($data);