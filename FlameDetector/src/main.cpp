#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <credentials.h>
int FS = A0;

WiFiClient espClient;
PubSubClient client(espClient);

void connect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("2523452", mqttUser, mqttPassword))
    {
      Serial.println("connected");
    }
    else 
    {
      Serial.println("failed with state: ");
      Serial.print(client.state());
      Serial.println("trying again in 5 seconds");
      delay(1000);
    }
  }
};

void setup()
{
  Serial.begin(115200);
  pinMode(FS, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Waiting to connect to WiFi");
  }
  randomSeed(micros());
  Serial.println("WiFi is connected");
  Serial.println(WiFi.localIP());

  client.setServer(mqttServer, mqttPort);
  //client.setCallback(callback);

  connect();
}

void loop()
{
  int firesensorAnalog = analogRead(FS);
  
  if (!client.connected())
  {
    Serial.print(WiFi.status());
    connect();
  }

  Serial.print(firesensorAnalog);

  if (firesensorAnalog > 50)
  {
    client.publish(mqttTopic, "on");
    delay(3000);
  }

  client.loop();
  delay(1000);
 
  //Read value from fire sensor
  //if value = 1 then write client.publish("bomb", "on");
}