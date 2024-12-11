% Generarea vectorilor x și y
x = 1:100;
y = 2:2:200;

% a) Reprezentarea grafică a lui y în funcție de x folosind funcția stem
figure;
stem(x, y);
title('a) Reprezentarea grafică a lui y în funcție de x folosind stem');
xlabel('x');
ylabel('y');

% b) Reprezentarea grafică a lui y în funcție de x folosind funcția plot
figure;
plot(x, y);
title('b) Reprezentarea grafică a lui y în funcție de x folosind plot');
xlabel('x');
ylabel('y');

% c) Reprezentarea grafică a lui y și x folosind plot și stem în aceeași figură
figure;
plot(x, y, 'r'); % y în funcție de x folosit plot
hold on;
stem(x, y, 'filled'); % y în funcție de x folosit stem
title('c) Reprezentarea grafică a lui y și x folosind plot și stem');
xlabel('x');
ylabel('y');
legend('plot', 'stem');
hold off;

% d) Reprezentarea grafică a lui y și x folosind plot și stem în sisteme de coordonate diferite
figure;
subplot(2, 1, 1);
plot(x, y, 'r');
title('d) Reprezentarea grafică a lui y în funcție de x folosind plot');
xlabel('x');
ylabel('y');

subplot(2, 1, 2);
stem(x, y, 'filled');
title('d) Reprezentarea grafică a lui y în funcție de x folosind stem');
xlabel('x');
ylabel('y');
