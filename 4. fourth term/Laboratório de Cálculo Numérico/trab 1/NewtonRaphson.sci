function[raiz,x,iter,ea]=NewtonRaphson(x0,f,fp,tol,imax)
    iter=0;
    xr=x0;
    x(iter+1)=x0;
    while(1)
        xrold=xr;
        xr=xrold-f(xrold)/fp(xrold);
        iter=iter+1;
        x(iter+1)=xr;
        if(xr~=0)then
            ea(iter)=abs((xr-xrold)/xr);
        end;
        if(ea(iter)<= tol) then
            raiz=xr;
            return;
        end;
        if(iter>=imax) then
            error('Número Máximo de Iterações Alcançado');
        end;
    end;
endfunction
