
var arr=["31","28","31","30","31","30","31","31","30","31","30","31"];

function f()
{
    var a=new Date(document.getElementById("1").value);
    var b=new Date(document.getElementById("2").value);
   /* alert(a);
    alert(a.getMonth());
    alert(b.getMonth());*/
    for(var i=a.getMonth();i<=b.getMonth();i++)
    {
       //var newElem=document.createElement("table");
       document.write('<table border="1px">');
       document.write('<tr>');
       document.write('<td>');
       document.write("Sun");
       document.write('</td>');
       document.write('<td>');
       document.write("Mon");
       document.write('</td>');
       document.write('<td>');
       document.write("Tue");
       document.write('</td>');
       document.write('<td>');
       document.write("Wed");
       document.write('</td>');
       document.write('<td>');
       document.write("Thu");
       document.write('</td>');
       document.write('<td>');
       document.write("Fri");
       document.write('</td>');
       document.write('<td>');
       document.write("Sat");
       document.write('</td>');
       document.write('</tr>');
       var c=new Date(2017,i,1);
       var count=0;
       var f;
       if(i==6)
       f=6;
       else f=5;
        for(var j=0;j<f;j++)
        {
          //  var newRow=newElem.insertRow(j+i);
          document.write('<tr border="1px" padding="3px" rules="cols" height="20px">');
          if((b.getMonth()-a.getMonth())>0)
            for(k=0;k<7;k++)
            {
                //var cell=newRow.insertCell(k);
                //cell.innerHTML="cell";
                document.write('<td border="1px" padding="3px" >');
                if(count+1<=arr[i])
                {if(i>a.getMonth() && i<b.getMonth())
                {
                    if(j==0)
                    {
                        if(k<c.getDay())
                        document.write(" ");
                        else
                       { document.write(count+1);
                           count++;}
                    }
                    else
                    {document.write(count+1);
                    count++}
                }
                else if(i==a.getMonth()){
                 if(j==0)
                    {
                        if(k<c.getDay())
                        document.write(" ");
                         else if(count+1<a.getDate())
                    {
                        document.write(" ");
                        count++;
                    }
                    else
                    {
                        document.write(count+1);
                        count++;
                    }
                }
              else if(count+1<a.getDate())
                    {
                        document.write(" ");
                        count++;
                    }
                    else
                    {
                        document.write(count+1);
                        count++;
                    }}
                else
                {
                    if(j==0)
                    {
                        if(k<c.getDay())
                        document.write(" ");
                   else if(count+1>b.getDate())
                    {
                        document.write(" ");
                    }
                    else
                    {
                        document.write(count+1);
                        count++;
                    }
                    }
                   else if(count+1>b.getDate())
                    {
                        document.write(" ");
                    }
                    else
                    {
                        document.write(count+1);
                        count++;
                    }
                }
            }
            else
                    document.write(" ");
                document.write('</td>');
            }
            else
            {
               for(k=0;k<7;k++)
               {
                   document.write('<td>');
                   if(j==0)
                   {
                      
                        if(k<c.getDay())
                        document.write(" ");
                         else if(count+1<a.getDate())
                    {
                        document.write(" ");
                        count++;
                    } 
                    else if(count+1>b.getDate())
                    {
                        document.write(" ");
                    }
    else
    {
        document.write(count+1);
        count++;
    }
                   }
                    else if(count+1<a.getDate())
                    {
                        document.write(" ");
                        count++;
                    } 
                    else if(count+1>b.getDate())
                    {
                        document.write(" ");
                    }
    else
    {
        document.write(count+1);
        count++;
    }
              
             } 
             document.write('</td>')
            }
            document.write('</tr>');
        }
            document.write('</table>');
            document.write('<br>');
            count=0;
    }
}