from skimage import io, img_as_float
from skimage.util import random_noise
from scipy import ndimage, signal
import numpy as np
from matplotlib import pyplot as plt

img = io.imread("1.jpg")
rotated_img = ndimage.rotate(img, angle=45, reshape=False)
rescaled_image = ndimage.zoom(img, zoom=(1 / 20, 1 / 20, 1))

noisy_image = random_noise(img, mode="gaussian", var=0.1)

gaussian_filtered = ndimage.gaussian_filter(noisy_image, sigma=1)
median_filtered = ndimage.median_filter(noisy_image, size=3)
wiener_filtered = np.abs(signal.wiener(noisy_image))

plt.subplot(2, 4, 1)
plt.imshow(img, cmap="Blues")
plt.axis("off")
plt.title("Imagine originală")

plt.subplot(2, 4, 2)
plt.imshow(rotated_img, cmap="Blues")
plt.axis("off")
plt.title("Imagine rotită la 45 de grade")

plt.subplot(2, 4, 3)
plt.imshow(rescaled_image, cmap="gray")
plt.axis("off")
plt.title("Imagine redimensionată")

plt.subplot(2, 4, 4)
plt.imshow(noisy_image, cmap="gray")
plt.axis("off")
plt.title("Imagine cu zgomot")

plt.subplot(2, 4, 5)
plt.imshow(gaussian_filtered, cmap="gray")
plt.axis("off")
plt.title("Filtru Gaussian")

plt.subplot(2, 4, 6)
plt.imshow(median_filtered, cmap="gray")
plt.axis("off")
plt.title("Filtru Median")

plt.subplot(2, 4, 7)
plt.imshow(wiener_filtered, cmap="gray")
plt.axis("off")
lt.title("Filtru Wiener")

# Ajustează distanța dintre subgrafice
plt.subplots_adjust(wspace=0.5, hspace=0.5)

plt.show()
