import cv2
import numpy as np
import matplotlib.pyplot as plt
# import

color = 0
# color = 1
image = cv2.imread(
    "W:\\MIV\\TAI\\TP1\\Solution\\fyc-45_3-016.png", cv2.IMREAD_GRAYSCALE)

plt.imshow(image)
plt.title('')
# plt.show()
# print(np.unique(image))

# Trouvez les coordonnées du point le plus haut à gauche (coin supérieur gauche)
y1, x1 = None, None

for y in range(image.shape[0]):
    for x in range(image.shape[1]):
        if image[y, x] > 0:
            y1, x1 = y, x
            break
    if y1 is not None:
        break

# Trouvez les coordonnées du point le plus bas à droite (coin inférieur droit)
y2, x2 = None, None

for y in range(image.shape[0] - 1, -1, -1):
    for x in range(image.shape[1] - 1, -1, -1):
        if image[y, x] > 0:
            y2, x2 = y, x
            break
    if y2 is not None:
        break


print(x1, y1, x2, y2)
# Dessinez un cercle rouge sur le point le plus haut à gauche
cv2.circle(image, (x1, y1), 5, (0, 0, 255), -1)  # -1 pour remplir le cercle

# Dessinez un cercle rouge sur le point le plus bas à droite

cv2.circle(image, (x2, y2), 5, (0, 0, 255), -1)

# Sauvegardez l'image résultante avec les cercles
cv2.imwrite('silhouette_with_circles.png', image)
plt.imshow(image)
plt.title('')
plt.show()
