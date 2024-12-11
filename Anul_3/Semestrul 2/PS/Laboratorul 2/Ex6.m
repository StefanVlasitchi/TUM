% Definirea frecvenței de eșantionare
fd = 1000; % 1000 eșantioane pe secundă (Hz)

% Definirea intervalului de timp
t = 0:(1/fd):1; % De la 0 la 1 secundă cu frecvența de eșantionare specificată

% Calculul semnalului exponențial a) 5 * exp(-6t)
semnal_a = 5 * exp(-6*t);

% Afișarea semnalului exponențial a)
subplot(2, 1, 1);
plot(t, semnal_a, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Semnal Exponențial a) 5 * exp(-6t)');
grid on;

% Calculul semnalului exponențial b) exp(5t)
semnal_b = exp(5*t);

% Afișarea semnalului exponențial b)
subplot(2, 1, 2);
plot(t, semnal_b, 'r', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Semnal Exponențial b) exp(5t)');
grid on;
