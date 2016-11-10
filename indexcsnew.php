<?php

header ( "Content-Type:text/html;charset=UTF8" );
$dir = 'F:/pri/*.xml';
$d = glob ( $dir );
$str = '';
$kst = '';
$est = '';
$tmap='private:'."\n";
$len=50;
$len_new=55;
$vector_len=3;
$len_new_new=85;
$str_len=1;
$def='private:'."\n";
$loaders='';
$call_loaders='';
$load_def='';
$find_func='';
$dics='';
$getDircFuncs = "";
foreach ( $d as $f ) {
 $bname = basename ( $f );
 $bname = str_replace ( ".xml", '', $bname );
 $xml = simplexml_load_file ( $f );
 
 $keys = array_keys ( ( array ) $xml );
  $file = file_get_contents ( $f );
 $sp=strpos($file,'<!--');
 $ep=strpos($file,'-->');
 $file=substr($file,$sp, $ep-$sp);
 $file=explode("\n",$file);
 $ss=explode(' ',$file[1]);
 $stype=explode(' ', $file[2]);
// print_r($stype);
 $mtype=strtolower($stype[0]);
 $et = "extern KeyType $bname" . "Keys[#];\n\n";
 $kt = "    KeyType[] $bname" . "Keys=new KeyType[]{\n";

 $st = "public class  $bname \n{\n";
 $lmap = 'typedef map&lt'.'UINT32,'."$bname> C$bname"."Map;\n";
 $ldef="C$bname"."Map $bname"."Map;\n";
 $keys_name=$bname."Keys";
 $map_name=$bname."Map";
 $lloader_def="public bool Load$bname();\n";
 $llfind="    public $bname get$bname($mtype id)\n    {\n        $bname val;\n        m$bname"."Dic.TryGetValue(id, out val);\n        return val;\n    }\n\n";
 $loader="    bool Load$bname()\n    {\n        string pfile=dbPath+\"$bname\";\n        m$bname"."Dic.Clear();\n        return  LoadCommon(pfile, m$bname"."Dic, typeof($bname));\n    }\n\n";
 $call_loader="        Load$bname();\n";
 $ldic="    private Dictionary&lt$mtype, $bname&gt "; 
 $getDircFunc="    public Dictionary&lt$mtype, $bname&gt $bname"."Dic()\n    {\n        return m$bname"."Dic;\n    }\n\n";
 $ldic.=str_repeat(' ',$len_new-strlen($ldic));
 $ldic.="m$bname"."Dic";
 $ldic.=str_repeat(' ',$len_new_new-strlen($ldic));
 $ldic.="= new Dictionary&lt$mtype, $bname&gt();\n";
 $dics.=$ldic;
 $find_func.=$llfind;
 $call_loaders.=$call_loader;
 $getDircFuncs.=$getDircFunc;
 $load_def.=$lloader_def;
 $loaders.=$loader;

// echo $f;
// print_r($file);
//echo $bname;

 $ns = "using UnityEngine;\nusing System;\nusing System.IO;\nusing System.Collections;\nusing System.Collections.Generic;\nusing Mono.Xml;\nusing System.Security;\nusing System.Reflection;\n\n";
 
 foreach ( $xml->$keys [0] as $kx => $r ) {
  
  $i = 0;
  $j = 0;
  $si=0;
  $m=0;
  foreach ( $r->attributes () as $k => $v ) {
   $type = gettype ( $v );
   $j ++;
	switch(strtolower($stype[$m++]))
   {
   	case 'int':
		$ust = "    public int " . $k . ";"; 
		$ust.=str_repeat(' ',$len-strlen($ust));		
		$st.=$ust."//".$ss[$si++]."\n";
		$kt .= '    {"' . $k . '",0,' . $i ++ . '},' . "\n";
   		break;
   	case 'string':
   		 $ust = "    public string " . $k . ";";    //".$ss[$si++]."\n";
	     $ust.=str_repeat(' ',$len-strlen($ust));
		 $st.=$ust."//".$ss[$si++]."\n";
	     $kt .= '    {"' . $k . '",1,' . $i . '},' . "\n";
	    $i += $str_len;
   		break;
   	case 'list:int':
   		 $ust = "    public List&ltint&gt " . $k . ";";    //".$ss[$si++]."\n";
	     $ust.=str_repeat(' ',$len-strlen($ust));
		 $st.=$ust."//".$ss[$si++]."\n";
	     $kt .= '    {"' . $k . '",3,' . $i . '},' . "\n";
	     $i += $vector_len;
   		break;
   	case 'list:string':
   		 $ust = "    public List&ltstring&gt " . $k . ";";    //".$ss[$si++]."\n";
	     $ust.=str_repeat(' ',$len-strlen($ust));
		 $st.=$ust."//".$ss[$si++]."\n";
	     $kt .= '    {"' . $k . '",4,' . $i . '},' . "\n";
	     $i += $vector_len;
   		break;
	case 'float':
		$ust = "    public float " . $k . ";"; 
		$ust.=str_repeat(' ',$len-strlen($ust));		
		$st.=$ust."//".$ss[$si++]."\n";
		$kt .= '    {"' . $k . '",5,' . $i ++ . '},' . "\n";
   		break;
	case 'list:idcount':
		$ust = "    public List&ltIDCount&gt " . $k . ";"; 
		$ust.=str_repeat(' ',$len-strlen($ust));		
		$st.=$ust."//".$ss[$si++]."\n";
		$kt .= '    {"' . $k . '",5,' . $i ++ . '},' . "\n";
		break;
   	default:break;	
   }
  }
  $et = str_replace ( "#", $j, $et );
  break;
 }
 
 $kt = substr ( $kt, 0, strlen ( $kt ) - 2 );
 $st .= "};\n\n";
 $kt .= "\n    };\n</br>";
 $tmap.=$lmap;
 $def.=$ldef;
 $est .= $et;
 $kst .= $kt;
 $str .= $st;
 
 // break;
}

$IdCountClass = "    public class IDCount\n    {\n        public int id;\n        public int count;\n    }\n"; 
echo "<pre>";
echo $ns;
echo "namespace SanGuo.DB {\n";
echo $IdCountClass;
echo $str;
echo "public class DBStore\n{\n    private string dbPath = \"DB/\";\n";
echo "    public static readonly DBStore instance = new DBStore();\n";
echo $dics."\n";
echo "    private DBStore(){}\n\n";
echo $getDircFuncs;
//echo $kst;
//echo $est;
//echo $tmap;
//echo $def;

echo $loaders;
echo "    public void LoadAll()\n    {\n";
echo $call_loaders;
echo "    }\n\n";
//echo $load_def;
echo $find_func;
echo "    bool LoadCommon&ltT&gt(string file, Dictionary&ltint, T&gt t1, Type itemType)
    {
        SecurityElement se = CXmlRead.GetRootElement(file);
        int row = 0;
        if (se == null)
        {
            Debug.Log(\"config xml file=\" + file + \"not find\");
            return false;
        }
        foreach (SecurityElement child in se.Children)
        {
            if (child.Tag == \"row\")
            {
                row++;
                object[] constructParms = new object[] { };
                object item = Activator.CreateInstance(itemType, constructParms);
                FieldInfo[] fieldInfos = itemType.GetFields();
                foreach (FieldInfo fieldInfo in fieldInfos)
                {
                    string val = child.Attribute(fieldInfo.Name);
                    if (val != \"\" && val != null)
                    {
                       if (fieldInfo.FieldType.FullName.Equals(typeof(System.Int32).FullName))
                        {
                            int tempVal = 0;
                            bool result = int.TryParse(val, out tempVal);
                            if (!result)
                            {
                                Debug.Log(\"wrong config xml format file=\" + file + \" key=\" + fieldInfo.Name + \"  row=\" + row);
                            }
                            fieldInfo.SetValue(item, tempVal);
                        }
						
						if (fieldInfo.FieldType.FullName.Equals(typeof(System.Single).FullName))
                        {
                            float tempVal = 0;
                            bool result = float.TryParse(val, out tempVal);
                            if (!result)
                            {
                                Debug.Log(\"wrong config xml format file=\" + file + \" key=\" + fieldInfo.Name + \"  row=\" + row);
                            }
                            fieldInfo.SetValue(item, tempVal);
                        }
						
                        if (fieldInfo.FieldType.FullName.Equals(typeof(System.String).FullName))
                        {
							if( string.Compare(val.ToLower(), \"null\") == 0)
							{
								val = \"\";
							}
							fieldInfo.SetValue(item, val);
                            
                        }
						
                        if (fieldInfo.FieldType.FullName.Equals(typeof(List&ltint&gt).FullName))
                        {
                            List&ltint> list = new List&ltint&gt();
                            if (val != \"null\")
                            {
                                CommonFunc.StringSplitListValue(val, list);
                            }
                            fieldInfo.SetValue(item, list);
                        }

                        if (fieldInfo.FieldType.FullName.Equals(typeof(List&ltstring&gt).FullName))
                        {
                            List&ltstring&gt strList = new List&ltstring&gt();
                            if (val != \"null\")
                            {
                                CommonFunc.StringSplitListValue(val, strList);
                            }
                            fieldInfo.SetValue(item, strList);
                        }
						if(fieldInfo.FieldType.FullName.Equals(typeof(List&ltIDCount&gt).FullName))
						{
							List&ltIDCount&gt idCountList = new List&ltIDCount&gt();
							if(val != null)
							{
								StringSplitIDCountListValue(val, idCountList);
							}
							fieldInfo.SetValue(item, idCountList);
						}
                    }
                    else
                    {
                        Debug.Log(\"wrong config xml format file=\" + file + \" key=\" + fieldInfo.Name + \"  row=\" + row);
                    }
                }
               try
                {
                    t1.Add(fieldInfos[0].GetValue(item), (T)item);
                }
                catch (Exception e)
                {
                    Debug.Log(\"wrong config xml Add Dic file=\" + file + \"  row=\" + row);
                } 
            }
        }

        se = null;
        return true;
    }
	
    public static void StringSplitIDCountListValue(string val, List&ltIDCount&gt values)
    {
        if(val.Length > 0)
        {
            List&ltstring> strList = new List&ltstring&gt();
            CommonFunc.StringSplitListValue(val, strList);

            foreach(string str in strList)
            {
                string[] result = str.Split(new char[] { ' ', ':' });
                if(result.Length == 2)
                {
                    SanGuo.DB.IDCount idCount = new SanGuo.DB.IDCount();
                    idCount.id = int.Parse(result[0]);
                    idCount.count = int.Parse(result[1]);

                    values.Add(idCount);
                }
            }
        }
    }\n";
echo "}\n}";
echo "</pre>";