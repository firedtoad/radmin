<?php
header("Content-Type:text/html;charset=UTF8");
$file_str = file_get_contents("XmlStruct.h");
//print_r($file_str);
$matchs = array();
preg_match_all('/struct .*?\{.*?\}/s', $file_str, $matchs);
//unset($matchs[0][0]);
$all = array();
foreach ($matchs[0] as $v) {
    $mc = array();
    //	echo $v;
    preg_match_all(
    '/ {1,}(.*?) {1,}(.*) {1,}(\/\/.*)/', $v, $mc);
    $ms = array();
    preg_match_all('/struct (.*) {\n/', $v, $ms);
    //	print_r($ms);
    //	print_r($mc);
    $arr = array();
    if (isset($ms[1][0])) {
        $arr['name'] = trim($ms[1][0]);
        $value = array();
        foreach ($mc[2] as $k => $v) {
            if (isset(
            $mc[1][$k]) &&
             isset($mc[3][$k])) {
                $v = trim(
                $v, 
                ' ;');
                $value[$v] = array(
                'type' => $mc[1][$k], 
                'comment' => $mc[3][$k]);
            }
        }
        $arr['value'] = $value;
        $all[$arr['name']] = $arr;
    }
    //	print_r($mc);
}
$f_arr = array('Name', 'DescID', 'ID', 'NameID', 'Icon');
$f_comment = array("成长", "解锁");
function insection ($arr1, $arr2)
{
    global $f_arr;
    global $f_comment;
    //	print_r($arr1);
    //	print_r($arr2);
    $arr = array();
    //	print_r($arr2);
    foreach ($arr1['value'] as $k => $v) {
        //		$v=trim($v,' ;');
        if (strstr(
        $v['comment'], $f_comment[1]) ||
         strstr($v['comment'], $f_comment[0])) {
            continue;
        }
        if (isset($arr2['value'][$k])) {
            if (! in_array($k, 
            $f_arr)) {
                $arr[$k] = $v;
            }
        } else {
            $arr[$k] = $v;
        }
    }
    foreach ($arr2['value'] as $k => $v) {
        //		$v=trim($v,' ;');
        //		print_r($v);
        if (strstr(
        $v['comment'], $f_comment[1]) ||
         strstr($v['comment'], $f_comment[0])) {
            continue;
        }
        if (isset($arr1['value'][$k])) {
            if (! in_array($k, 
            $f_arr)) {
                $arr[$k] = $v;
            }
        } else {
            $arr[$k] = $v;
        }
    }
    //	print_r ( $arr );
    return $arr;
}
$len = 40;
$ar = insection($all['HeroEquip'], $all['HeroBaby']);
$struct = 'struct EquipProperty' . "\n{\n";
$key = "KeyType EquipPropertyKeys[#N]={\n";
$i = 0;
foreach ($ar as $k => $v) {
    $s = "    " . $v['type'] . " $k;";
    //	echo $len-strlen($s);
    $s .= str_repeat(' ', $len - strlen($s));
    $struct .= $s . $v['comment'] . "\n";
    $i ++;
    $key .= "    {\"$k\",0,offsetof(EquipProperty,$k)},\n";
}
$key = str_replace('#N', $i, $key);
$key .= "};\n";
$struct .= "};\n";
echo $key;
echo $struct;