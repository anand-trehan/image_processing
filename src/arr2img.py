import cv2
import numpy as np


#f to array
f1 = open("mario_decrypt.txt", "r")
r = int(f1.readline())
c = int(f1.readline())
h = int(f1.readline())
arr2img = np.zeros((r,c,h))
for i in range(r):
    for j in range(c):
        arr2img[i][j][0] = int(f1.readline())
for i in range(r):
    for j in range(c):
        arr2img[i][j][1] = int(f1.readline())
for i in range(r):
    for j in range(c):
        arr2img[i][j][2] = int(f1.readline())
f1.close()



img_n = cv2.normalize(src=arr2img, dst=None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_8U)


cv2.imshow('image',img_n)
cv2.waitKey(0)
cv2.destroyAllWindows()
