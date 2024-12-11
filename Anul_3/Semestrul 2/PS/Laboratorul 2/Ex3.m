% Definirea parametrilor semnalului dreptunghiular
durata_stare_superioara = 0.25; % Durata în care semnalul este la nivelul superior
durata_perioada = 0.5; % Perioada semnalului
amplitudine_superioara = 2; % Amplitudinea nivelului superior
amplitudine_inferioara = -2; % Amplitudinea nivelului inferior

% Generarea vectorului de timp
timp = linspace(0, 2, 1000); % Generăm 1000 de puncte în intervalul de timp

% Inițializarea semnalului dreptunghiular cu valori de amplitudine inferioare
semnal_dreptunghiular = amplitudine_inferioara * ones(size(timp));

% Calculul semnalului dreptunghiular
for i = 1:length(timp)
    if mod(timp(i), durata_perioada) <= durata_stare_superioara
        semnal_dreptunghiular(i) = amplitudine_superioara;
    end
end

% Afișarea semnalului dreptunghiular
figure;
plot(timp, semnal_dreptunghiular, 'b', 'LineWidth', 2);
xlabel('Timp');
ylabel('Amplitudine');
title('Semnal dreptunghiular');
grid on;
