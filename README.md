# DiGi Cracker
DiGi Cracker is literally, a digital cracker. Normal crackers suck cus of pollution so I made this.

# Using it
## Requirements
- Python3
- PlatformIO
- ESP8266
- An MQTT Server

## Procedure
- Clone the code
```bash
# Git CLI
git clone https://github.com/techno021/DiGiCracker

# Github CLI
gh repo clone techno021/DiGiCracker
```

- Plug in the credentials
  - `./FlameDetector/src/credentials.h`
    - Change `ssid` to your WiFi ssid
    - Change `password` to your WiFi password
    - Change `mqttServer` to your MQTT Server domain
    - Change `mqttPort` to your MQTT Server port
    - Change `mqttUser` to your MQTT Username
    - Change `mqttPassword` to your MQTT Password
    - Change `mqttTopic` to yout MQTT Topic

  - `./NoiseMachine/credentials.py`
    - Change `server` to your MQTT Server domain
    - Change `port` to your MQTT Server port
    - Change `user` to your MQTT Username
    - Change `password` to your MQTT Password
    - Change `topic` to yout MQTT Topic

- Run it!
  ```bash
  # I'm assuming you are at the project root
  cd ./FlameDetector
  pio run

  # In a different terminal
  cd ./NoiseMachine
  python init.py
  ```

# Lisence
This Project is LISENCED under the MIT LISENCE. More details [here](https://github.com/techno021/DiGiCracker/blob/main/LICENSE.md).

# Credits
- [@Techno021](https://github.com/techno021) - Did basically everything
