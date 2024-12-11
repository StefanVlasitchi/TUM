% Definirea intervalului de timp
t = -10:0.01:10; % De la -10 la 10 secunde, cu un pas de eșantionare de 0.01 secunde

% Definirea expresiei semnalului sinusoidal
A = 2; % Amplitudinea semnalului
f = 1/6; % Frecvența semnalului (1 perioadă la fiecare 6 secunde)
omega = 2*pi*f; % Pulsatia semnalului
semnal_sinusoidal = A * sin(omega * t);

% Definirea expresiei semnalului exponențial atenuator
B = 1; % Amplitudinea exponențialului
r = 0.8; % Rata de decădere exponențială
exponetial_atenuator = B * r .^ t;

% Calculul semnalului sinusoidal atenuat
semnal_sinusoidal_atenuat = semnal_sinusoidal .* exponetial_atenuator;

% Afișarea semnalului sinusoidal atenuat
plot(t, semnal_sinusoidal_atenuat, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Semnal Sinusoidal Atenuat');
grid on;
