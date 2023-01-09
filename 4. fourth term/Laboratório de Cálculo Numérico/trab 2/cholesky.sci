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
function[G] = cholesky(A)
    if(simetrica(A)==1)then
        n = input("Qual a dimensao da matriz? ");
        G = zeros(n,n);
        for i=1:n
            for j=0:i
                soma = 0;
                if(j==i)then
                    for k=1:j
                        soma = soma + G(j,k)*G(j,k);
                        G(j,j) = sqrt(A(j,j)-soma);
                    end
                else
                    for k=1:j
                        soma = soma + G(i,k)*G(j,k);
                        G(i,j) = (A(i,j)-soma)/G(j,j);
                    end
                end
            end
        end
        disp(A);
        disp(G);
        disp(G');
    else
        break
    end
endfunction
