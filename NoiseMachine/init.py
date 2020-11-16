import paho.mqtt.client as mqtt
from pygame import mixer
from credentials import credentials

mixer.init()
mqttc = mqtt.Client()
mqttc.username_pw_set(credentials["user"], credentials["password"])

# Loading the song
mixer.music.load("song.mp3")

# Setting the volume
mixer.music.set_volume(0.7)

def on_connect(client, userdata, flags, rc):
  print(f"Connected with result code {str(rc)}")
  client.subscribe(credentials["topic"])


def on_message(client, userdata, msg):
  print(msg.topic+" "+str(msg.payload))
  if str(msg.payload) == "b'on'":
    mixer.music.play()


mqttc.on_connect = on_connect
mqttc.on_message = on_message
mqttc.connect(credentials["server"], credentials["port"], 60)

mqttc.loop_forever()
