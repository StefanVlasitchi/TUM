% Definirea expresiei semnalului sinusoidal
A = 2; % Amplitudinea semnalului
f = 1/6; % Frecvența semnalului (1 perioadă la fiecare 6 secunde)
omega = 2*pi*f; % Pulsatia semnalului

% Definirea intervalului de timp
t = -10:0.01:10; % De la -10 la 10 secunde, cu pasul de eșantionare de 0.01 secunde

% Calculul semnalului sinusoidal
x = A * sin(omega * t);

% Afișarea semnalului sinusoidal
plot(t, x, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Semnal Sinusoidal');
grid on;
