import speech_recognition as sr
from .tts import tts as speak

class SpeechHandler:
    def __init__(self):
        self.recognizer = sr.Recognizer()

    def record(self):
        """录制语音并返回文本。"""
        with sr.Microphone() as source:
            print("请说话:")
            audio = self.recognizer.listen(source)
            try:
                print(self.recognizer.recognize_google(audio, language='zh-CN'))
                return self.recognizer.recognize_google(audio, language='zh-CN')
            except sr.UnknownValueError:
                print("无法识别语音")
                return ""
            except sr.RequestError as e:
                print(f"无法连接到语音识别服务: {e}")
                return ""

    def speak(self, text):
        print(f"回答: {text}")
        speak(text)