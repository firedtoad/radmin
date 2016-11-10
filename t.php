<?php
include "Rsa.class.php";
include "MyRsa.class.php";
class testController
{
    public function Appreturn()
    {
         $public_key='-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA9k9+YKARWfM3l7pxK1W2
gco3BoGva2ddaLWyiJ1csdRSueN9Cm3Ao8cnFOmdXTLRJMvGuO5tVIU58CzGvy9X
FavW1WAT+oZRGJ06xP6URiRAU7+Vxh7f8LpsWZOCXtnv3oWcRnb7j6q7QrvoIz3Z
y3aA22jFp2p8TZUI4gAmMXASKvkEflu553dN3gVF0GRkJADTAW+AvpWYRgJtlR7k
KUxNEBU/RoGnQT4Zu2y5QI1DJhvdB2KS+af3Y0uhS6kNBPtMOc9Ygj+GPRwJIFgS
bj+qOaEv7ECFkbUrzHKTWcFhw9Hix5vM+tlZnqlFj5hOqsLaRq1YfXfVs4Ll6iEB
rQIDAQAB
-----END PUBLIC KEY-----';

        $notify_data = 'eIWn3moVTUEvGOkwJU1ttgTzL7l0EqDGUhCzz1LxbXFTNuUz2JFcpdjjEoTHnOb07KyODE/8z7AQZlbxagSMo9kCzkXLnJSWgXxBKY3Jy2q5JClBytfsNUiPZmmr3lJcoF4uBJngZQoDk0n2P35fzW2pu2IpBxqvO1doDYn36KlI/ivVrGyHOvbBw2gVnHNM/s5rksQ4S0NQF4ygHaTI7NLZgyoAfDbjko7TojFULr9WmFZgy6vXjYZm7t0Am/LT/VOB9XgVMd/fWhrXQhYZNE34mBespxBXBskrFQ+J0354/lxSHAJAsWR6e6Sz1PaSn6SrpsE0+KUYzIGmnd2tMw==';
        print_r(self::getrsa($notify_data,$public_key));exit;
    }
     
public function getrsa($privatedata, $public_key){
        //$privatedata = urldecode($privatedata);
        $privatebackdata = base64_decode($privatedata);
        $MyRsa = new MyRsa;
        $data = $MyRsa->publickey_decodeing($privatebackdata, $public_key);
//        var_dump($data);exit;
        return json_decode($data,true);
 }
}

//testController::Appreturn();
$c=new testController();
$c->Appreturn();