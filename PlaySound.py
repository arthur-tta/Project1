from pygame import mixer
import time

class playSound():
    def __init__(self) -> None:
        pass
    def play(self, key):
        mixer.init()
        mixer.music.load(f'sound/{key}.mp3')
        mixer.music.play()

        


