% a)
z = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0];

% Creăm prima figură cu subplot
subplot(2, 1, 1)
stem(0:20,z) % asigurăm că z are aceeași lungime cu n
title('Vectorul z în funcție de n=0:20')

% Creăm a doua figură cu subplot
subplot(2, 1, 2)
stem((-5:15), z) % asigurăm că z începe de la indicele corespunzător din m
title('Vectorul z în funcție de m=-5:15')

% b)
% Definim vectorul t
t = abs(10-(0:20));
% Reprezentăm grafic vectorul t
stem(0:20,t)
title('Vectorul t in functie de n=0:20')

%c)