
function areaOfTriangle(obj){
  var a=obj.st1.value;
  var b=obj.st2.value;
  var c=obj.st3.value;
  var p=(a+b+c)/2;  
  var s=Math.sqrt(p*(p-a)*(p-b)*(p-c));
  obj.res.value=s;
}
 
    