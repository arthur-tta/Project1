dic = {26:'1', 60:'2', 82:'3', 144:'4', 166:'5',
    98:'6', 106:'7', 110:'8', 118:'9', 94:'0'}


class Number():
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
        print(fingers)
        if len(fingers) == 5:
            fx = fingers[0] * 11 + fingers[1] * 13 + fingers[2] * 17 + fingers[3] * 19 + fingers[4] * 23
            if fx in dic:
                return dic[fx]
            else:
                return ''
        else:
            return ''
        
        
      
        
       
        
       
        
       
            