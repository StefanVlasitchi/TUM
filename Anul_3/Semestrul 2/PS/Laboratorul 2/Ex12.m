% Definirea intervalului de timp
t = -10:0.01:10; % De la -10s la 10s cu un pas de eșantionare de 0.01s

% Calculul semnalului exponențial complex
x = exp((-0.1 + 0.3j) * t);

% Afișarea partii reale și a părții imaginară în figuri separate
figure;

% Afișarea părții reale
subplot(2, 1, 1);
plot(t, real(x), 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Parte Reală');
title('Partea Reală a Semnalului Exponențial Complex');
grid on;

% Afișarea părții imaginară
subplot(2, 1, 2);
plot(t, imag(x), 'r', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Parte Imaginară');
title('Partea Imaginară a Semnalului Exponențial Complex');
grid on;
