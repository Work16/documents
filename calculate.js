function f()
{
var l=document.getElementById("para2").value;
l=String(l);
var a="",b="",c="";
var i=0;
while (l[i]!='*'&& l[i]!='/' && l[i]!='+'&& l[i]!='-' && l[i]!='^')
{
    a+=l[i];
    i++;
}
b=l[i];
i++;
while(i<l.length)
{
    c+=l[i];
    i++;
}
if(b=='+')
document.getElementById("para4").value=a*1+c*1;
if (b=='-')
document.getElementById("para4").value=a*1-c*1;
if(b=="*")
document.getElementById("para4").value=a*c;
if(b=="/")
document.getElementById("para4").value=a/c;
if(b=="%")
document.getElementById("para4").value=a%c;
if(b=="^")
{
document.getElementById("para4").value=a;
for(var i=1;i<c;i++)
{document.getElementById("para4").value*=a;}}
}