% Definirea parametrilor oscilației armonice
amplitudine = 1; % Amplitudinea unitate
perioada = 50; % Perioada T = 50 sec
faza_initiala = pi/3; % Faza inițială 𝜋/3

% Definirea intervalului de timp
t = 0:0.1:256; % De la 0 la 256 secunde cu un pas de 0.1 secunde

% Calculul oscilației armonice
oscilatie_armonica = amplitudine * sin(2*pi*(1/perioada)*t + faza_initiala);

% Afișarea oscilației armonice
plot(t, oscilatie_armonica, 'b', 'LineWidth', 2);
xlabel('Timp (s)');
ylabel('Amplitudine');
title('Oscilație armonică');
grid on;
