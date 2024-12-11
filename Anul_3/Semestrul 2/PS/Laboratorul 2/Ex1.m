% Secvența x1[n] = 0.8 δ[n], -15≤n≤15
n1 = -15:15;
x1 = 0.8 * (n1 == 0);
figure;
stem(n1, x1);
xlabel('n');
ylabel('x1[n]');
title('Secvența x1[n]');

% Secvența x2[n] = 0.9 δ [n-5], 1≤n≤20
n2 = 1:20;
x2 = 0.9 * ((n2 - 5) == 0);
figure;
stem(n2, x2);
xlabel('n');
ylabel('x2[n]');
title('Secvența x2[n]');

% Secvența x3[n] = 1.5 δ [n-333], 300≤n≤350
n3 = 300:350;
x3 = 1.5 * ((n3 - 333) == 0);
figure;
stem(n3, x3);
xlabel('n');
ylabel('x3[n]');
title('Secvența x3[n]');

% Secvența x4[n] = 4.9 δ [n+7], -10≤n≤0
n4 = -10:0;
x4 = 4.9 * ((n4 + 7) == 0);
figure;
stem(n4, x4);
xlabel('n');
ylabel('x4[n]');
title('Secvența x4[n]');

% Secvența x5[n] = 4 u[n], -10≤n≤10
n5 = -10:10;
x5 = 4 * (n5 >= 0);
figure;
stem(n5, x5);
xlabel('n');
ylabel('x5[n]');
title('Secvența x5[n]');

% Secvența x6[n] = 1.4 u[n-7], -5≤n≤20
n6 = -5:20;
x6 = 1.4 * ((n6 - 7) >= 0);
figure;
stem(n6, x6);
xlabel('n');
ylabel('x6[n]');
title('Secvența x6[n]');

% Secvența x7[n] = 2.3 u[n+5], -15≤n≤10
n7 = -15:10;
x7 = 2.3 * ((n7 + 5) >= 0);
figure;
stem(n7, x7);
xlabel('n');
ylabel('x7[n]');
title('Secvența x7[n]');

% Perioada pentru x1[n] este 1, deoarece avem un singur impuls la fiecare pas
perioada_x1 = 1;

% Generarea trenului de impulsuri pentru x1[n]
n_x1 = 0:perioada_x1:15; % Stabilim intervalul de timp pentru o perioadă
x1_periodic = 0.8 * (mod(n_x1, perioada_x1) == 0); % Generăm impulsuri la fiecare perioadă

% Afișarea trenului de impulsuri pentru x1[n]
figure;
stem(n_x1, x1_periodic, 'filled', 'MarkerSize', 5);
xlabel('n');
ylabel('x1[n]');
title('Tren de impulsuri pentru x1[n]');

% Perioada pentru x2[n] este 20, deoarece avem un impuls la fiecare 20 de eșantioane
perioada_x2 = 20;

% Generarea trenului de impulsuri pentru x2[n]
n_x2 = 1:perioada_x2:100; % Stabilim intervalul de timp pentru o perioadă
x2_periodic = 0.9 * (mod(n_x2 - 1, perioada_x2) == 0); % Generăm impulsuri la fiecare perioadă

% Afișarea trenului de impulsuri pentru x2[n]
figure;
stem(n_x2, x2_periodic, 'filled', 'MarkerSize', 5);
xlabel('n');
ylabel('x2[n]');
title('Tren de impulsuri pentru x2[n]');

% Perioada pentru x3[n] este 1, deoarece avem un singur impuls la fiecare pas
perioada_x3 = 1;

% Generarea trenului de impulsuri pentru x3[n]
n_x3 = 300:perioada_x3:350; % Stabilim intervalul de timp pentru o perioadă
x3_periodic = 1.5 * (mod(n_x3 - 300, perioada_x3) == 0); % Generăm impulsuri la fiecare perioadă

% Afișarea trenului de impulsuri pentru x3[n]
figure;
stem(n_x3, x3_periodic, 'filled', 'MarkerSize', 5);
xlabel('n');
ylabel('x3[n]');
title('Tren de impulsuri pentru x3[n]');

