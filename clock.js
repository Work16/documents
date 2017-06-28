
var p=new Array();
//var c=new Date();
function f()
{
    var a=document.getElementById('h').value;
    var b=document.getElementById('m').value;
    //p.push(a);
    //p.push(b);
   var c= new Date();
  //  while(a!=c.getHours || b!=c.getMinutes)
  //  {}
 if(a!=c.getHours || b!=c.getMinutes)
   // alert('Time');
   document.getElementById("mes").value="Time";
}

/*function g()
{
for(var i=0;i<p.length;i+=2)
{
    if(p[i]!=c.getHours || p[i++]!=c.getMinutes)
    {
        document.getElementById("mes").value="Time";
        var j=-5;
        while(j)
        j++;
    }
}
}*/
