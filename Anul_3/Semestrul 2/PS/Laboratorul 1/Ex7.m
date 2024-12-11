% a) Aproximarea derivatei de ordinul I folosind diferențe finite progresive
x = [-2 -1.5 0 0.5 2.5 3];
y = [6 9 11 10 7 5];
df = diff(y) ./ diff(x); % Calculul aproximării derivatei

% Afisarea derivatei în punctele dorite
vx1 = [-2 0 2.5];
for i = 1:length(vx1)
    % Determinarea poziției pe care se află vx(i) în x
    k = find(x == vx1(i));
    % Afisarea derivatei cu diferențe progresive
    disp(['f''(' num2str(vx1(i)) ') = ' num2str(df(k))])
end

% b) Aproximarea derivatei de ordinul I folosind diferențe finite regresive
vx2 = [-1.5 0 3];
for i = 1:length(vx2)
    % Determinarea poziției pe care se află vx(i) în x
    k = find(x == vx2(i));
    % Afisarea derivatei cu diferențe regresive
    disp(['f''(' num2str(vx2(i)) ') = ' num2str(df(k-1))])
end

% c) Aproximarea derivatei de ordinul I folosind diferențe finite centrale
vx3 = [-0.75 0.25 0.5 1];
n = length(x);
der = spline(x(1:n-1), df, vx3); % Interpolare pentru a găsi derivatele în punctele dorite
for i = 1:length(der)
    disp(['f''(' num2str(vx3(i)) ') = ' num2str(der(i))])
end

% d) Calculul derivatei funcției polinomiale și reprezentarea grafică
c = [1 13 -7 1];
dc = polyder(c);
vx4 = [-2 -1.3 0.1 2.45];
der = polyval(dc, vx4); % Calculul derivatei pentru valorile date
disp('Derivatele functiei polinomiale:');
disp(der);

% Reprezentarea grafică a derivatei pe intervalul [-2, 3]
x_plot = -2:0.1:3;
df_plot = polyval(dc, x_plot);
plot(x_plot, df_plot);
title('Reprezentarea grafica a derivatei pe [-2,3]');

% Calculul integralei definite
for j = 1:11
    x(j) = -1.1 + 0.1 * j;
    y(j) = j * x(j)^2 / (x(j) - 1) - 2 / (j + 1);
end
integrala_definita = trapz(x, y);
disp('Integrala definita a functiei f(x):');
disp(integrala_definita);

% Calculul integralei definite pentru functia data
f = @(x) 1 ./ (sin(x) + cos(x));
integrala_definita2 = integral(f, pi/3, pi/2);
disp('Integrala definita a functiei 1 / (sin(x) + cos(x)) in intervalul [pi/3, pi/2]:');
disp(integrala_definita2);
