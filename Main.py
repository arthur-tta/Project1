import cv2
import time
import HandTrackingModule
import Count
import Alpha
import Number


cap = cv2.VideoCapture(0)
handetector = HandTrackingModule.handDetector()
count = Count.CountAlpha()
alpha = Alpha.Alpha()
number = Number.Number()

# mode = 1 => chu cai, mode = 2 => chu so
mode = 2

# fps
fps = 30
timePerTick = 1 / fps
delta = 0
lastTime = time.time()
now = 0

# list answer
times = 0
answerList = ''
answer = ''

while True:
    success, img = cap.read()
    img = handetector.findHands(img)
    lmList = handetector.findPosition(img)
    now = time.time()
    delta = delta + (now - lastTime) / timePerTick
    lastTime = now
    if delta >= 1:
        if len(lmList) != 0:
            if mode == 1:
                answer = alpha.solve(lmList)
            elif mode == 2:
                answer = number.solve(lmList)
            
            if answer != '':
                overLayout = cv2.imread(f'Image/{answer}.png')
                h, w, c = overLayout.shape
                img[0:h, 0:w] = overLayout
            
            times = times + 1
            answerList = answerList + answer
            if times == fps:
                count.read(answerList)
                answerList = ''
                times = 0
            
            
        delta = 0

    cv2.imshow("img", img)
    if cv2.waitKey(1) == ord('q'):
        break


cap.release()
cv2.destroyAllWindows()
