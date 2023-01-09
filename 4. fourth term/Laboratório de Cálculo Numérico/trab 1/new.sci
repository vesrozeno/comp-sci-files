deff('y=f(x)','y=sin((pi*(x+1))/8)+0.23*x-1.5');//definir função
deff('z=f1(x)','z=0.3926*cos(0.3926*(x+1))+0.23');//definir derivada
a=2;b=2.5;//definir intervalo
x=(a+b)/2;  
i=1; 
while(i<=3)  
    x=(x-(f(x)/f1(x)));  
    i=i+1;
    [x]  
end;
