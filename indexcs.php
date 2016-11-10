<?php

header ( "Content-Type:text/html;charset=UTF8" );
$dir = 'F:/Design/data/*';
$d = glob ( $dir );
$str = '';
$kst = '';
$est = '';
$tmap='private:'."\n";
$len=35;
$len_new=55;
$vector_len=3;
$len_new_new=80;
$str_len=1;
$def='private:'."\n";
$loaders='';
$call_loaders='';
$load_def='';
$find_func='';
$dics='';
foreach ( $d as $f ) {
 $bname = basename ( $f );
 $bname = str_replace ( ".xml", '', $bname );
 $xml = simplexml_load_file ( $f );
 $keys = array_keys ( ( array ) $xml );
 $et = "extern KeyType $bname" . "Keys[#];\n\n";
 $kt = "KeyType[] $bname" . "Keys=new KeyType[]{\n";

 $st = "public class  $bname \n{\n";
 $lmap = 'typedef map&lt'.'UINT32,'."$bname> C$bname"."Map;\n";
 $ldef="C$bname"."Map $bname"."Map;\n";
 $keys_name=$bname."Keys";
 $map_name=$bname."Map";
 $lloader_def="BOOL Load$bname();\n";
 $llfind="$bname get$bname(int id)\n{\n    $bname val;\n    m$bname"."Dic.TryGetValue(id, out val);\n    return val;\n}\n";
 $loader="BOOL Load$bname()\n{\n    string pfile=cpath+\"$bname.xml\";\n    return  LoadCommon(pfile,$keys_name,m$bname"."Dic,$bname);\n}\n\n";
 $call_loader="Load$bname();\n";
 $ldic="private Dictionary&ltint, $bname&gt "; 
 $ldic.=str_repeat(' ',$len_new-strlen($ldic));
 $ldic.="m$bname"."Dic";
 $ldic.=str_repeat(' ',$len_new_new-strlen($ldic));
 $ldic.="= new Dictionary&ltint, $bname&gt();\n";
 $dics.=$ldic;
 $find_func.=$llfind;
 $call_loaders.=$call_loader;
 $load_def.=$lloader_def;
 $loaders.=$loader;
 $file = file_get_contents ( $f );
 $sp=strpos($file,'<!--');
 $ep=strpos($file,'-->');
 $file=substr($file,$sp, $ep-$sp);
 $file=explode("\n",$file);
// echo $f;
// print_r($file);
 $ss=explode(" ",$file[1]);
 $stype=explode(' ', $file[2]);
 foreach ( $xml->$keys [0] as $kx => $r ) {
  
  $i = 0;
  $j = 0;
  $si=0;
  $m=0;
  foreach ( $r->attributes () as $k => $v ) {
   $type = gettype ( $v );
  
   switch($stype[$m++])
   {
   	case 'int':
   		    $ust = "    UINT32 " . $k . ";"; 
			$ust.=str_repeat(' ',$len-strlen($ust));
			
			$st.=$ust."//".$ss[$si++]."\n";
		    $kt .= '    {"' . $k . '",0,' . $i ++ . '},' . "\n";
   		break;
   	case 'String':
   	case 'string':
   		 $ust = "    string " . $k . ";";    //".$ss[$si++]."\n";
	     $ust.=str_repeat(' ',$len-strlen($ust));
		 $st.=$ust."//".$ss[$si++]."\n";
	     $kt .= '    {"' . $k . '",1,' . $i . '},' . "\n";
	    $i += $str_len;
   		break;
   	case 'List:int':
   	case 'List:Int':
   		 $ust = "    vector<int> " . $k . ";";    //".$ss[$si++]."\n";
	     $ust.=str_repeat(' ',$len-strlen($ust));
		 $st.=$ust."//".$ss[$si++]."\n";
	     $kt .= '    {"' . $k . '",3,' . $i . '},' . "\n";
	     $i += $vector_len;
   		break;
   	case 'List:string':
   	case 'List:String':
   		 $ust = "    vector<string> " . $k . ";";    //".$ss[$si++]."\n";
	     $ust.=str_repeat(' ',$len-strlen($ust));
		 $st.=$ust."//".$ss[$si++]."\n";
	     $kt .= '    {"' . $k . '",4,' . $i . '},' . "\n";
	     $i += $vector_len;
   		break;
   		default:break;
   }
//   if (is_numeric ( ( string ) $v )) {
//    $ust = "    public int " . $k . ";";     
//	$ust.=str_repeat(' ',$len-strlen($ust));
//	$st.=$ust."//".$ss[$si++]."\n";
//    $kt .= '    new KeyType("' . $k . '",0,' . $i ++ . '),' . "\n";
//    // echo "num";
//   } else {
//    $ust = "    public string " . $k . ";";    //".$ss[$si++]."\n";
//    $ust.=str_repeat(' ',$len-strlen($ust));
//	$st.=$ust."//".$ss[$si++]."\n";
//    $kt .= '    new KeyType("' . $k . '",1,' . $i . '),' . "\n";
//    $i += $str_len;
//    // echo "string";
//   }
//   // echo $k,'=',$v,"</br>";
  }
  $et = str_replace ( "#", $j, $et );
   $j ++;
  break;
 }
 
 $kt = substr ( $kt, 0, strlen ( $kt ) - 2 );
 $st .= "};\n\n";
 $kt .= "\n};\n</br>";
 $tmap.=$lmap;
 $def.=$ldef;
 $est .= $et;
 $kst .= $kt;
 $str .= $st;
 
 // break;
}

echo "<pre>";
echo $str;
echo $dics;
echo $kst;
//echo $est;
//echo $tmap;
//echo $def;
/*echo $loaders;
echo $call_loaders;*/
//echo $load_def;
echo $find_func;
echo "</pre>";