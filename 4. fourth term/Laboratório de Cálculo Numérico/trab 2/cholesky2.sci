function[sim] = simetrica(A)
    sim = 0;
    B = A';
    if(B==A)then
        sim = 1;
        disp("Matriz simétrica!");
    else
        disp("Matriz não-simétrica.");
    end
endfunction
function[x] = somatorio1(G,i)
    x=0;
    for k=1:i-1
        x=x+G(k,i)**2;
    end
endfunction
function[y] = somatorio2(i,j,G)
    y=0;
    for k=1:i-1
        y = y+G(k,i)*G(k,j);
    end
endfunction 
function[G,x] = cholesky2(A,b)
    if(simetrica(A)==1)then
        n = input("Qual a dimensao da matriz? ");
        G = zeros(n,n);
        soma = 0;
        soma2 = 0;
        G(1,1) = sqrt(A(1,1));
        for j=2:n
            G(1,j) = A(1,j)/G(1,1);
        end
        for i=2:n
            soma = somatorio1(G,i);
            G(i,i) = sqrt(A(i,i)-soma);
            for j=i+1:n
                soma2 = somatorio2(i,j,G);
                G(i,j) = (A(i,j) - soma2)/G(i,i);
            end
        
        end
        disp("Matriz A:");
        disp(A);
        disp("Matriz G:");
        disp(G);
        disp("Matriz Gt:");
        disp(G');
        disp("vetor b:");
        disp(b);
        
        y(1)=b(1)/G'(1,1);
        for i = 2:n
           y(i) = (b(i)-G'(i,1:i-1)*y(1:i-1))/G'(i,i);
        end
        
    
        x = zeros(n,1);
        x(n) = y(n)/G(n,n);
        for i = n-1:-1:1
           x(i) = (y(i)-G(i,i+1:n)*x(i+1:n))/G(i,i);
        end
        disp("Vetor Solução:");
        disp(x);
        else
            break
    end
endfunction
