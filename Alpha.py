dic = {23:'a', 144:'b', 72:'c', 65:'d', 3:'e', 131:'f', 
    48:'g', 102:'h', 46:'i', 87:'j', 82:'k', 
    27:'l', 49:'m', 30:'n', 94:'o', 2:'p', 1:'q', 
    61:'r', 25:'s', 24:'t', 62:'u', 63:'v', 98:'w', 
    35:'x', 68:'y', 28:'z'}


class Alpha():
    def solve(self, lmList):
        fingers = []
        # thumb
        if lmList[4][2] < lmList[9][2]:
            fingers.append(2)
        else:
            fingers.append(0)

        # index_finger
        for i in range(1, 5):    
            if lmList[i * 4 + 4][2] > lmList[i * 4 + 1][2]:
                fingers.append(0)
            elif lmList[i * 4 + 4][2] > lmList[i * 4 + 2][2]:
                fingers.append(1)
            else:
                fingers.append(2) 

        # trang thai phu
        if fingers[0] == 2 and fingers[1] == 0 and fingers[2] == 0 and fingers[3] == 0 and fingers[4] == 0:
            #a
            if lmList[4][1] < lmList[6][1]:
                fingers.append(1)
            #t
            elif lmList[4][1] > lmList[6][1] and lmList[4][1] < lmList[9][1]:
                fingers.append(2)
            #s
            elif lmList[4][1] > lmList[9][1]:
                fingers.append(3)
        elif fingers[0] == 0 and fingers[1] == 2 and fingers[2] == 0 and fingers[3] == 0 and fingers[4] == 0:
            #l
            if lmList[4][1] < lmList[5][1]:
                fingers.append(1)
            #z
            elif lmList[4][1] > lmList[5][1]:
                fingers.append(2)
         # p, q, e
        elif fingers[0] == 0 and fingers[1] == 0 and fingers[2] == 0 and fingers[3] == 0 and fingers[4] == 0:
            #q
            if lmList[4][2] > lmList[5][2] and lmList[6][2] > lmList[5][2] and lmList[12][2] < lmList[10][2] and lmList[16][2] < lmList[14][2] and lmList[20][2] < lmList[18][2]:
                fingers.append(1)
            #p
            elif lmList[4][2] > lmList[5][2] and lmList[6][2] > lmList[5][2] and lmList[10][2] > lmList[9][2] and lmList[16][2] < lmList[14][2] and lmList[20][2] < lmList[18][2]:
                fingers.append(2)
            #e
            elif lmList[6][2] < lmList[5][2] and lmList[10][2] < lmList[9][2] and lmList[14][2] < lmList[13][2] and lmList[18][2] < lmList[17][2]:
                fingers.append(3)
        elif fingers[0] == 0 and fingers[1] == 2 and fingers[2] == 2 and fingers[3] == 0 and fingers[4] == 0:
            if lmList[8][1] >= lmList[5][1]:
                # r
                if lmList[8][1] >= lmList[11][1]:
                    fingers.append(1)
                # u
                else:
                    fingers.append(2)
            # v
            elif lmList[8][1] < lmList[5][1]:
                fingers.append(3)
        else:
            fingers.append(0)

        print(fingers)
        
        if len(fingers) == 6:
            fx = fingers[0] * 11 + fingers[1] * 13 + fingers[2] * 17 + fingers[3] * 19 + fingers[4] * 23 + fingers[5]
            if fx in dic:
                return dic[fx]
            else:
                return ''
        else:
            return ''
        
       
        
       
        
       
            