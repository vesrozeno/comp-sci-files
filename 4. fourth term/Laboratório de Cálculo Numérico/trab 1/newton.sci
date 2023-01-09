deff('y=f(x)','y=sin((pi*(x+1))/8)+0.23*x-1.5')
deff('y=z(x)','y=0.3926*cos(0.3926*(x+1))+0.23')
a=input("Enter value of interval a:")
b=input("Enter value of interval b:")
n=input("Enter the number of iteration n:")
x0=(a+b)/2
for i=1:n
    disp([i,x0])
    x1=x0-f(x0)/z(x0)
    if abs(x1-x0)<0.00001 then
        disp("We get required accuracy")
        break;
    end
    x0=x1
end
