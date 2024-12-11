% Generare vector cu elemente complexe
n = 5; % Numărul de elemente în vector
complex_vector = randn(n, 1) + 1i * randn(n, 1); % Elemente complexe aleatoare

% Apelarea funcției și afișarea rezultatelor
[media_real, vector_patrat, rezultat_inmultire] = functie_operatii(complex_vector);
disp('Media aritmetică a părților reale ale elementelor:');
disp(media_real);
disp('Vectorul cu elementele inițiale ridicate la pătrat:');
disp(vector_patrat);
disp('Matricea obținută din înmulțirea vectorului inițial cu transpusul său:');
disp(rezultat_inmultire);

function [media_real, vector_patrat, rezultat_inmultire] = functie_operatii(complex_vector)
    % Calculează media aritmetică a părților reale ale elementelor vectorului
    media_real = mean(real(complex_vector));

    % Ridică la pătrat elementele vectorului inițial
    vector_patrat = complex_vector .^ 2;

    % Calculează înmulțirea vectorului inițial cu transpusul său
    rezultat_inmultire = complex_vector * complex_vector';

    % Returnează rezultatele ca parametri de ieșire
end
