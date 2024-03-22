#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "actions.h"

// 网络配置
const char* ssid = "Lemon-Dev";
const char* password = "lagrengedev";

// MQTT服务器配置
const char* mqtt_server = "10.25.5.110";
const int mqtt_port = 1883; // 通常是1883端口，但你的服务器配置可能不同
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  // 连接WiFi网络
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);
  if (String(topic) == "dog_in_actions") {
    if (message == "forward") {
        forward();
    } else if (message == "back") {
    } else if (message == "turn_left") {

    } else if (message == "turn_right") {

    } else if (message == "stop") {
        down();
    }
  }
}

void reconnect() {
  // 循环直到连接成功
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // 尝试连接
    if (client.connect("dog1", "siria", "z13547842355")) {
      Serial.println("connected");
      // 一旦连接，发布一个公告...
      client.publish("outTopic", "hello world");
      // ...并重新订阅
      client.subscribe("dog_in_actions");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // 等待5秒后重试
      delay(5000);
    }
  }
}

void setup() {
    Serial.begin(115200);
    s1.attach(18);
    s2.attach(17);
    s3.attach(26);
    s4.attach(27);

    down();

    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

