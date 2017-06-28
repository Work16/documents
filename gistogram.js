function f()
{
 var a=document.getElementById("1").value;
 var b=document.createElement("div");
 b.innerHTML=String(a);
 b.style.height=String(a)+"px";
 b.style.backgroundColor="red";
 b.style.position="relative";
 b.style.top=String(500-a)+"px";
 b.style.border="0.5px solid black";
 document.getElementById("scene").appendChild(b);
}

