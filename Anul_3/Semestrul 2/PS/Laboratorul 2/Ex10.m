% Definirea rezoluției temporale și intervalului de timp
dt = 0.002; % Rezoluția temporală (2ms)
t = -1:dt:1; % Intervalul de timp de la -1s la 1s

% Inițializarea impulsului dreptunghiular
impuls = zeros(size(t));

% Identificarea indexului pentru t = -0.5s
index_tau_minus_05 = find(t == -0.5);

% Identificarea indexului pentru t = 0.5s
index_tau_plus_05 = find(t == 0.5);

% Setarea amplitudinii impulsului în intervalul dorit
impuls(index_tau_minus_05:index_tau_plus_05) = 1;

% Afișarea impulsului dreptunghiular
plot(t, impuls, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Impuls Dreptunghiular');
grid on;
