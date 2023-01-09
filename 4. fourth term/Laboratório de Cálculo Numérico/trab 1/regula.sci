clear
clc
 
function f = f(x)
    f = sin((pi*(x+1))/8)+0.23*x-1.5
endfunction
 
 
disp("Sample input: regulaFalsi(1,2,10^-4, 100)")
 
function regulaFalsi(a,b,TOL,N)
    i = 1
    FA = f(a)
    finalOutput = [i, a, b, a + (b-a)/2, f(a + (b-a)/2)]
     
    printf("%-20s %-20s %-20s %-20s %-20s \n","n","a_n","b_n","p_n","f(p_n)")
    
    while(i <= N),
        p = (a*f(b)-b*f(a))/(f(b) - f(a))
        FP = f(p)
         
         
        if(FP == 0 | abs(f(p)) < TOL) then
            break
        else
             printf("%-20.8g %-20.8g %-20.8g %-20.8g %-20.8g\n", i, a, b, p, f(p))
        end
         
        i = i + 1
         
        if(FA*FP > 0) then
            a = p
        else
            b = p
        end
    end
     
    disp(finalOutput)
     
endfunction
