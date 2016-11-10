<?php
print_r($_POST);
print_r($_REQUEST);

file_put_contents('vivo.log', json_encode($_POST)."\n",FILE_APPEND);
file_put_contents('vivo.log', json_encode($_REQUEST)."\n",FILE_APPEND);