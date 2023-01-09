function[raiz,x,iter,ea] = FalsaPosicao(xl,xu,f,tol,imax)
    iter = 0;
    xr = xu-(f(xu)*(xl-xu))/(f(xl)-f(xu));
    if(f(xl)*f(xr)<0) then
        xu=xr;
    elseif f(xl)*f(xr)>0 then
        xl=xr;
    else 
        ea = 0;
    end;
    xrold = xr;
    while(ea>tol & iter<imax)
        xr = xu-(f(xu)*(xl-xu))/(f(xl)-f(xu));
        iter = iter+1;
        ea = pmodulo((xr-xrold),xr);
        if (f(xl)*f(xr)<0) then
            xu=xr;
        elseif f(xl)*f(xr)>0 then
            xl=xr;
        else
            ea=0;
        end;
        xrold=xr;
    end;
endfunction
