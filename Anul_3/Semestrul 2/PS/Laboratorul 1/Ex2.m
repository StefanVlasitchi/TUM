% Generare vector cu elemente aleatoare cu distribuție normală
n = 100; % Numărul de elemente în vector
mu = 0; % Media distribuției normale
sigma = 1; % Deviația standard a distribuției normale

% Generarea vectorului cu distribuție normală
random_vector = mu + sigma * randn(n, 1);

% Afișarea elementelor negative ale vectorului
negative_elements = random_vector(random_vector < 0);
disp('Elemente negative ale vectorului:');
disp(negative_elements);

% Verificați dacă directorul există și, dacă nu, creați-l
folder_path = 'd:/student/pns/nrgrupa/';
if ~exist(folder_path, 'dir')
    mkdir(folder_path);
    disp(['Directorul ' folder_path ' a fost creat.']);
end

% Salvați vectorul în fișier
file_name = 'vector_normal.txt';
full_file_path = fullfile(folder_path, file_name);
dlmwrite(full_file_path, random_vector, 'precision', '%.6f');
disp(['Vectorul a fost salvat în fișierul ' full_file_path]);
