% Definirea parametrilor semnalului sinusoidal
amplitudine_min = 3; % Amplitudinea minimă
amplitudine_max = 7; % Amplitudinea maximă
frecventa = 4; % Frecvența semnalului (numărul de cicluri pe unitate de timp)
faza = pi/2; % Faza semnalului în radiani
numar_puncte = 1000; % Numărul de puncte pentru a obține o reprezentare netedă

% Generarea vectorului de timp între 0 și 2
timp = linspace(0, 2, numar_puncte);

% Calcularea semnalului sinusoidal
semnal_sinusoidal = (amplitudine_max + amplitudine_min) / 2 + ...
    (amplitudine_max - amplitudine_min) / 2 * sin(2 * pi * frecventa * timp + faza);
 
% Afișarea semnalului sinusoidal
figure;
plot(timp, semnal_sinusoidal, 'b', 'LineWidth', 2);
xlabel('Timp');
ylabel('Amplitudine');
title('Semnal sinusoidal');
grid on;

