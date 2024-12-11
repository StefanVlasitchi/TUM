% Definirea variabilei temporale pentru x1
n1 = -15:25;
x1 = sin(pi/17 * n1);

% Definirea variabilei temporale pentru x2
n2 = 0:50;
x2 = cos(pi/sqrt(23) * n2);

% Reprezentarea celor două secvențe în aceeași figură folosind plot
figure;
plot(n1, x1, 'r', n2, x2, 'b');
title('Reprezentarea celor două secvențe în același sistem de coordonate');
xlabel('n');
ylabel('Amplitudine');
legend('x1 = sin(pi/17 * n)', 'x2 = cos(pi/sqrt(23) * n)');

% Reprezentarea celor două secvențe în două miniferestre folosind subplot și plot
figure;
subplot(2, 1, 1);
plot(n1, x1, 'r');
title('Reprezentarea secvenței x1 = sin(pi/17 * n)');
xlabel('n');
ylabel('Amplitudine');

subplot(2, 1, 2);
plot(n2, x2, 'b');
title('Reprezentarea secvenței x2 = cos(pi/sqrt(23) * n)');
xlabel('n');
ylabel('Amplitudine');

% Reprezentarea celor două secvențe în aceeași figură folosind stem
figure;
stem(n1, x1, 'r', 'filled');
hold on;
stem(n2, x2, 'b', 'filled');
hold off;
title('Reprezentarea celor două secvențe folosind stem');
xlabel('n');
ylabel('Amplitudine');
legend('x1 = sin(pi/17 * n)', 'x2 = cos(pi/sqrt(23) * n)');

% Reprezentarea celor două secvențe în două miniferestre folosind subplot și stem
figure;
subplot(2, 1, 1);
stem(n1, x1, 'r', 'filled');
title('Reprezentarea secvenței x1 = sin(pi/17 * n) folosind stem');
xlabel('n');
ylabel('Amplitudine');

subplot(2, 1, 2);
stem(n2, x2, 'b', 'filled');
title('Reprezentarea secvenței x2 = cos(pi/sqrt(23) * n) folosind stem');
xlabel('n');
ylabel('Amplitudine');
