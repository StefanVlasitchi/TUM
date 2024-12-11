% Definirea parametrilor semnalului exponențial
B = 1; % Amplitudinea impulsului
r = 0.8; % Rata de decădere exponențială

% Definirea intervalului de timp
t = -10:0.01:10; % De la -10 la 10 secunde, cu pasul de eșantionare de 0.01 secunde

% Calculul semnalului exponențial
x = B * r .^ t;

% Afișarea semnalului exponențial
plot(t, x, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Impuls Exponențial');
grid on;
