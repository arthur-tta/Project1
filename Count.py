import PlaySound

p = PlaySound.playSound()

class CountAlpha():
    def read(self, str):
        count={}
        for i in str:
            if i in count:
                count[i] +=1
            else:
                count[i] = 1
        
        sorted(count, key=count.get, reverse=True)
        
        for i in count:
            p.play(i)
            break
           