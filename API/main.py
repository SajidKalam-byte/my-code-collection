import pyttsx3
import speech_recognition
import requests
from bs4 import BeautifulSoup
import datetime
import os

engine = pyttsx3.init("sapi5")
voices = engine.getProperty("voices")

# Set the voice to "Microsoft Zira Desktop" (Female voice)
engine.setProperty("voice", voices[1].id)
engine.setProperty("rate", 170)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def takeCommand():
    r = speech_recognition.Recognizer()
    with speech_recognition.Microphone() as source:
        print("listening. . . .")
        r.pause_threshold = 1
        r.energy_threshold = 300
        audio = r.listen(source, 0, 4)

    try:
        print("Understanding...")
        query = r.recognize_google(audio, language='en-in')
        print(f"You Said: {query}\n")
    except Exception as e:
        print("Say that again")
        return "None"
    return query

def alarm(query):
    timehere = open("Alarmtext.txt", "a")
    timehere.write(query)
    timehere.close()
    os.startfile("alarm.py")

if __name__ == "__main__":
    while True:
        query = takeCommand().lower()
        if "wake up" in query or "hey" in query or "hello" in query or "hi" in query:
            from GreetMe import greetMe
            greetMe()

            while True:
                query = takeCommand().lower()
                if "go to sleep" in query or 'break le lo' in query or "break lelo" in query:
                    speak("chuuppp lawde")
                    #speak("Ok sir, You can call me anytime")
                    break
                
                elif "hello" in query:
                    speak("hello sir, how are you ?")
                elif "I am fine" in query:
                    speak("that's great sir")
                elif "how are you" in query or "how r u" in query:
                    speak("perfect sir")
                elif "thank you" in query:
                    speak("you are welcome sir")
                elif "what are you doing now " in query: 
                    speak("waiting your command sir")
                elif "jarvis" in query:
                    speak("yes sir")

                elif "open" in query:
                    from Dictapp import openappweb
                    openappweb(query)
                elif "close" in query:
                    from Dictapp import closeappweb
                    closeappweb(query)
                    
                elif "google" in query:
                    from SearchNow import searchGoogle
                    searchGoogle(query)
                elif "youtube" in query:
                    from SearchNow import searchYoutube
                    searchYoutube(query)
                elif "wikipedia" in query:
                    from SearchNow import searchWikipedia
                    searchWikipedia(query)
                    
                elif "temperature" in query or "temperature koto okhane" in query:
                    search = "temperature in siliguri"
                    url = f"https://www.google.com/search?q={search}"
                    r = requests.get(url)
                    data = BeautifulSoup(r.text, "html.parser")
                    temp = data.find("div", class_ = "BNeawe").text
                    speak(f"current{search} is {temp}")
                elif "weather" in query:
                    search = "temperature in siliguri"
                    url = f"https://www.google.com/search?q={search}"
                    r = requests.get(url)
                    data = BeautifulSoup(r.text, "html.parser")
                    temp = data.find("div", class_ = "BNeawe").text
                    speak(f"current{search} is {temp}")

                elif "set alarm" in query:
                    speak("Set please tell me the time to set alarm. for example, set alarm to 5:30 am")
                    a = input("please tell the time :- ")
                    alarm(a)
                    speak("done sir")

                elif "the time" in query:
                    strTime = datetime.datetime.now().strftime("%H:%M")
                    speak(f"sir, the time is now {strTime}")
                elif "turn off" in query or "sleep mode on" in query or "turn off karo" in query or "ghumiye por" in query:
                    speak("turn off my system, sir")
                    exit()
                elif "tell me a joke" in query:
                    speak("Why couldn't the bicycle find its way home? Because it lost its bearings!")
                elif "sing a song" in query:
                    speak("I'm sorry, I'm not programmed to sing. But I can play a song for you!")
                elif "play music" in query:
                    speak("Playing music for you.")
                    # Code to play music goes here
                    
                elif "tell me a fact" in query:
                    speak("Did you know that honey never spoils? Archaeologists have found pots of honey in ancient Egyptian tombs that are over 3000 years old and still perfectly edible!")
                elif "tell me a story" in query:
                    speak("Once upon a time, in a faraway land...")
                    # Code to narrate a story goes here
                elif "send email" in query:
                    speak("Sure, please provide the email address and the message you want to send.")
                    # Code to send an email goes here
                elif "take a screenshot" in query:
                    speak("Taking a screenshot.")
                    # Code to take a screenshot goes here
                elif "open camera" in query:
                    speak("Opening camera.")
                    # Code to open camera goes here
                elif "where am I" in query:
                    speak("You are currently in your home.")
                elif "tell me a riddle" in query:
                    speak("I am taken from a mine, and shut up in a wooden case, from which I am never released, and yet I am used by almost every person. What am I?")
                elif "translate" in query:
                    speak("Sure, please provide the text you want to translate and the language you want to translate it to.")
                    # Code to translate text goes here
                elif "tell me a quote" in query:
                    speak("In the end, we will remember not the words of our enemies, but the silence of our friends. - Martin Luther King Jr.")
                elif "tell me the news" in query:
                    speak("Here are the latest headlines...")
                    # Code to fetch and read news headlines goes here
                elif "tell me a fun fact" in query:
                    speak("Did you know that a group of flamingos is called a flamboyance?")
                elif "open calculator" in query:
                    speak("Opening calculator.")
                    # Code to open calculator goes here
                elif "remind me" in query:
                    speak("Sure, please provide the reminder details.")
                    # Code to set a reminder goes here
                elif "tell me a tongue twister" in query:
                    speak("How much wood would a woodchuck chuck if a woodchuck could chuck wood?")
                elif "open map" in query:
                    speak("Opening map.")
                    # Code to open map goes here
                elif "tell me a science fact" in query:
                    speak("Did you know that a day on Venus is longer than a year on Venus?")
                elif "open notes" in query:
                    speak("Opening notes.")
                    # Code to open notes app goes here
                elif "tell me a historical fact" in query:
                    speak("Did you know that the Great Wall of China is over 13,000 miles long?")
                elif "open calendar" in query:
                    speak("Opening calendar.")
                    # Code to open calendar goes here
                elif "tell me a joke" in query:
                    speak("Why couldn't the bicycle find its way home? Because it lost its bearings!")
                elif "sing a song" in query:
                    speak("I'm sorry, I'm not programmed to sing. But I can play a song for you!")
