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