import numpy as np
import matplotlib.pyplot as plt

# Parametrii semnalului
frecventa_50hz = 50
frecventa_70hz = 70
faza_50hz = 0
faza_70hz = np.pi / 4
amplitudinea = 1
durata_semnalului = 1
frecventa_esantionarii = 1000

# Generarea timpului
timp = np.arange(0, durata_semnalului, 1 / frecventa_esantionarii)

# Generarea semnalului ca o suprapunere de sinusoide
semnal = amplitudinea * np.sin(2 * np.pi * frecventa_50hz * timp + faza_50hz) + \
         amplitudinea * np.sin(2 * np.pi * frecventa_70hz * timp + faza_70hz)

# Calculul Transformatei Fourier
transformata_fourier = np.fft.fft(semnal)
frecvente = np.fft.fftfreq(len(transformata_fourier), 1 / frecventa_esantionarii)

# Reconstruirea semnalului din spectrul de amplitudini
semnal_reconstruit = np.fft.ifft(transformata_fourier)

# Generarea al doilea semnal identic cu semnalul reconstruit
semnal_identical = np.real(semnal_reconstruit)

# Afișarea ambelor semnale și a transformatei Fourier
plt.figure(figsize=(12, 8))

plt.subplot(3, 1, 1)
plt.plot(timp, semnal)
plt.title('Semnal ca suprapunere de 50 Hz și 70 Hz')
plt.xlabel('Timp (s)')
plt.ylabel('Amplitudine')
plt.grid(True)

plt.subplot(3, 1, 2)
plt.plot(frecvente, np.abs(transformata_fourier))
plt.title('Transformata Fourier')
plt.xlabel('Frecvență (Hz)')
plt.ylabel('abs(DFT(semnal))')
plt.xlim(0, 250)
plt.grid(True)

plt.subplot(3, 1, 3)
plt.plot(timp, semnal_identical)
plt.title('Semnal identic cu semnalul reconstruit')
plt.xlabel('Timp (s)')
plt.ylabel('Amplitudine')
plt.grid(True)

plt.tight_layout()
plt.show()
