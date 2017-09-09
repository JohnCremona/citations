#include <tools/String.h>

#include <include/constant.h>
string supress_slash(string& S)
{
  string s = S ;
  gsub(s,"~","") ;
  gsub(s,"&nbsp;","") ;
  gsub(s,"\\ ","") ;
  return s ;
}
void filter_string(string& S)
{
  gsub(S,"--","-") ;
  gsub(S,"~"," ") ;
  gsub(S,"  "," ") ;


  // toutes les chaine de caractere ci-apres contiennent un slach
  if (instring(S, "\\"))
  {
    if (instring(S, "\\\""))
    {
      gsub(S,"\\\"a","�") ;
      gsub(S,"\\\"u","�") ;
      gsub(S,"\\\"A","�") ;
      gsub(S,"\\\"U","�") ;
      gsub(S,"\\\"o","�") ;
    }

    if (instring(S, "\\'"))
    {
      gsub(S,"\\'e","�") ;
      gsub(S,"\\'E","�") ;
      gsub(S,"\\'{e}","�") ;
    }


    gsub(S,"\\aa","a") ;
    gsub(S,"\\oe ","oe") ;
    gsub(S,"\\AA","A") ;
    gsub(S,"\\OE ","OE") ;

    if (instring(S, "\\`"))
    {
      gsub(S,"\\`E","�") ;
      gsub(S,"\\`A","�") ;
      gsub(S,"\\`e","�") ;
      gsub(S,"\\`{e}","�") ;
      gsub(S,"\\`a","�") ;
      gsub(S,"\\`{a}","�") ;
      gsub(S,"\\`u","�") ;
      gsub(S,"\\`{u}","�") ;
      gsub(S,"\\`{A}","�") ;
      gsub(S,"\\`U","�") ;
      gsub(S,"\\`{U}","�") ;
    }

    if (instring(S, "\\^"))
    {
      gsub(S,"\\^a","�") ;
      gsub(S,"\\^e","�") ;
      gsub(S,"\\^\\i","�") ;
      gsub(S,"\\^{\\i}","�") ;
      gsub(S,"\\^o","�") ;
      gsub(S,"\\^{o}","�") ;
      gsub(S,"\\^u","�") ;
      gsub(S,"\\^{u}","�") ;
    }

    gsub(S,"\\^A","�") ;
    gsub(S,"\\^E","�") ;
    gsub(S,"\\^\\I","�") ;
    gsub(S,"\\^{\\I}","�") ;

    gsub(S,"\\,c","�") ;
    gsub(S,"\\,{c}","�") ;



    gsub(S,"\\,C","�") ;
    gsub(S,"\\,{C}","�") ;
    gsub(S,"\\^U","�") ;
    gsub(S,"\\^{O}","�") ;
    gsub(S,"\\^U","�") ;
    gsub(S,"\\^{U}","�") ;
    gsub(S,"\\v Z","Z") ;
    gsub(S,"\\v z","z") ;
    gsub(S,"\\v U","U") ;
    gsub(S,"\\v u","u") ;
    gsub(S,"\\' c","c") ;
    gsub(S,"\\' C","C") ;
    gsub(S,"\\v v","v") ;
    gsub(S,"\\v s","s") ;
    gsub(S,"\\v r","r") ;

    gsub(S,"\\.a","a") ;

    if (instring(S, "{\\"))
    {
      gsub(S,"{\\.a}","a") ;
      gsub(S,"{\\'e}","�") ;
      gsub(S,"{\\\"a}","�") ;
      gsub(S,"{\\aa}","a") ;
      gsub(S,"{\\\"u}","�") ;
      gsub(S,"{\\oe}","oe") ;

      gsub(S,"{\\\"A}","�") ;
      gsub(S,"{\\AA}","A") ;
      gsub(S,"{\\\"U}","�") ;
      gsub(S,"{\\OE}","OE") ;

      gsub(S,"{\\'E}","�") ;
      gsub(S,"{\\`E}","�") ;
      gsub(S,"{\\`A}","�") ;
      gsub(S,"{\\`e}","�") ;
      gsub(S,"{\\`a}","�") ;
      gsub(S,"{\\^a}","�") ;
      gsub(S,"{\\^e}","�") ;
      gsub(S,"{\\^\\i}","�") ;
      gsub(S,"{\\,c}","�") ;
      gsub(S,"{\\`u}","�") ;
      gsub(S,"{\\^o}","�") ;
      gsub(S,"{\\\"o}","�") ;
      gsub(S,"{\\^u}","�") ;
      gsub(S,"{\\~g}","g") ;
      gsub(S,"{\\~n}","�") ;
      gsub(S,"\\~n","�") ;
      gsub(S,"{\\'o}","�") ;
      gsub(S,"\\'o","�") ;

      gsub(S,"{\\^A}","�") ;
      gsub(S,"{\\^E}","�") ;
      gsub(S,"{\\^\\I}","�") ;
      gsub(S,"{\\,C}","�") ;
      gsub(S,"{\\`U}","�") ;
      gsub(S,"{\\^U}","�") ;
      gsub(S,"{\\^U}","�") ;
      gsub(S,"{\\v Z}","Z") ;
      gsub(S,"{\\v z}","z") ;
      gsub(S,"{\\v U}","U") ;
      gsub(S,"{\\v u}","u") ;
      gsub(S,"{\\' c}","c") ;
      gsub(S,"{\\' C}","C") ;
    }


    gsub(S,"\\sc ","") ;
    gsub(S,"\\em ","") ;
    gsub(S,"\\bf ","") ;
    gsub(S,"\\mbox","") ;
    gsub(S,"\\&","&") ;
  }
}

string suppressaccent(string& S)
{
  bool find = false ;
  unsigned int i ;
  for (i=0 ; i < S.length() ; i++)
    // Le code des caracteres accentuees est > a 208
    if (S[i] >= '�')
    {
      find = true ;
      break ;
    }
  if (find==true)
  {
    gsub(S,"�","e") ;
    gsub(S,"�","e") ;
    gsub(S,"�","e") ;
    gsub(S,"�","E") ;
    gsub(S,"�","E") ;
    gsub(S,"�","E") ;
    gsub(S,"�","a") ;
    gsub(S,"�","a") ;
    gsub(S,"�","a") ;
    gsub(S,"�","A") ;
    gsub(S,"�","a") ;
    gsub(S,"�","A") ;
    gsub(S,"�","u") ;
    gsub(S,"�","U") ;
    gsub(S,"�","u") ;
    gsub(S,"�","U") ;
    gsub(S,"�","u") ;
    gsub(S,"�","U") ;
    gsub(S,"�","i") ;
    gsub(S,"�","i") ;
    gsub(S,"�","c") ;
    gsub(S,"�","C") ;
    gsub(S,"�","o") ;
    gsub(S,"�","O") ;
  }
  return S ;
}
