

import cv2
import numpy as np

img = cv2.imread('1.jpg',cv2.IMREAD_COLOR)


f = open("mario.txt", "w")


f.write(str(img.shape[0])+"\n")
f.write(str(img.shape[1])+"\n")
f.write(str(img.shape[2])+"\n")
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        f.write(str(img[i][j][0])+"\n")
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        f.write(str(img[i][j][1])+"\n")
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        f.write(str(img[i][j][2])+"\n")
f.close()


'''
cv2.imshow('image',img_n)
cv2.waitKey(0)
cv2.destroyAllWindows()
'''
