function [z]=g1(X)
    z = X.^0
endfunction

function [z]=g2(X)
    z = X
endfunction

function [z]=g3(X)
    z = X.^2
endfunction

exec('quadrados_minimos.sci');
// definindo os pontos tabelados da função
X = [0, 0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2]
F = [-1.8, -1.2, -0.4, 0.4, 1.1, 2.1, 3.0, 3.9, 5.0] 

GLista=list(g1,g2,g3)      
[a] = quadrados_minimos(X,F,GLista)
mprintf('parabola')
disp(a)

GListaReta = list(g1,g2)
[b] = quadrados_minimos(X,F,GListaReta)
mprintf('reta')
disp(b)

// gráfico parábola
x=linspace(0,2,101);
G = a(1) + a(2)*x + a(3)*x.^2;   
subplot(2,1,1) 
plot(x,G,'b', 'LineWidth', 1);
subplot(2,1,1) 
plot(X,F,'ro');

// gráfico reta
x=linspace(0,2,101);
Gr = b(1) + b(2)*x;    
subplot(2,1,1) 
plot(x,Gr,'r', 'LineWidth', 1);
subplot(2,1,1) 
legend(["reta G(x)", ,"F","parábola G(x)"], 2);

// calculo do erro parabola
GX = a(1) + a(2)*X + a(3)*X.^2;
Yp = F-GX;
Ep = Yp*Yp'
mprintf('erro')
disp(Ep)
subplot(2,1,2)
plot(X,GX,'k', 'LineWidth', 1);

// calculo do erro reta
GXr = b(1) + b(2)*X;
Yr = F-GXr;
Er = Yr*Yr'
mprintf('erro')
disp(Er)
subplot(2,1,2)
plot(X,GXr,'r', 'LineWidth', 1);
subplot(2,1,2) 
plot(X,F,'ro');

legend(["erro parábola ","erro reta"],"F",2);
