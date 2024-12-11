% Definirea perioadei T, frecvenței f și a pasului de variație dt
T = 1;
f = 1/T;
dt1 = 0.01;
dt2 = 0.0002;

% Definirea vectorului de timp t
t1 = 0:dt1:3*T;
t2 = 0:dt2:3*T;

% Generarea semnalului sinusoidal
x1 = sin(2*pi*f*t1);
x2 = sin(2*pi*f*t2);

% Plasarea semnalului sinusoidal pe grafic
figure;
subplot(2,1,1);
plot(t1,x1,'b');
title('Semnal sinusoidal cu pas de variație dt=0.01');
xlabel('Timp [s]');
ylabel('Amplitudine');
grid on;

subplot(2,1,2);
plot(t2,x2,'b');
title('Semnal sinusoidal cu pas de variație dt=0.0002');
xlabel('Timp [s]');
ylabel('Amplitudine');
grid on;

% Calcularea perioadei semnalului sinusoidal
[maxima1, ~] = find(x1(1:end-2) > x1(2:end-1) & x1(1:end-2) > x1(3:end));
T1 = mean(diff(maxima1))*dt1;

[maxima2, ~] = find(x2(1:end-2) > x2(2:end-1) & x2(1:end-2) > x2(3:end));
T2 = mean(diff(maxima2))*dt2;

disp(['Perioada semnalului sinusoidal cu pas de variație dt=0.01 este: ', num2str(T1), ' s']);
disp(['Perioada semnalului sinusoidal cu pas de variație dt=0.0002 este: ', num2str(T2), ' s']);

% Generarea semnalului cosinusoidal
x3 = cos(2*pi*20*t1);

% Plasarea semnalului cosinusoidal peste semnalul sinusoidal
figure;
plot(t1,x1,'b',t1,x3,'r');
title('Semnal sinusoidal și semnal cosinusoidal');
xlabel('Timp [s]');
ylabel('Amplitudine');
grid on;

