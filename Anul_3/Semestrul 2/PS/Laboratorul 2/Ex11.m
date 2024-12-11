% Definirea parametrilor semnalului
A = 1; % Amplitudinea semnalului (±1)
omega = pi/4; % Viteza unghiulară (π/4)
duty_cycle = 0.3; % Coeficientul de umplere (30%)

% Definirea intervalului de timp
t = -10:0.01:10; % De la -10s la 10s cu un pas de eșantionare de 0.01s

% Inițializarea semnalului dreptunghiular
semnal = zeros(size(t));

% Calculul semnalului dreptunghiular
for i = 1:length(t)
    if mod(t(i), 2*pi/omega) <= (2*pi/omega) * duty_cycle
        semnal(i) = A;
    elseif mod(t(i), 2*pi/omega) >= (2*pi/omega) * (1 - duty_cycle)
        semnal(i) = -A;
    end
end

% Afișarea semnalului dreptunghiular
plot(t, semnal, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Succesiune Periodică de Impulsuri Dreptunghiulare');
grid on;
