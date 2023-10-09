#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// Replace with your network credentials
const char* ssid = "Micromax HS2";
const char* password = "Micromax";
String data = "";
WiFiServer server(80);
WiFiClient client;

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int RXPin = D1;
int TXPin = D2;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);

unsigned long myChannelNumber = 2071751;
const char* myWriteAPIKey = "456GNAXF78N9C9MW";

const char* host = "maker.ifttt.com";

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  delay(1000);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println((WiFi.localIP()));

  // Start the server
  server.begin();
  Serial.println("Server started");

  dht.begin();
  gpsSerial.begin(9600);
  ThingSpeak.begin(client);
  Serial.println("Email from IFTTT");
}


void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature(); // Replace with your sensor reading function
  float humidity = dht.readHumidity(); // Replace with your sensor reading function
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(1000);
  int x = ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
  x = ThingSpeak.writeField(myChannelNumber, 4, temperature, myWriteAPIKey);
  Serial.println("Channel update successful.");

  while (gpsSerial.available() > 0)
    if (gps.encode(gpsSerial.read()))
      // displayInfo();

  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    while(true);
  }

  WiFiClient client; 
      const int httpPort = 80;  
      if (!client.connect(host, httpPort)) 
      {  
         Serial.println("connection failed");  
         return;
      }         
         
         if (temperature > 30 && humidity > 75)
        {    
            String url = "/trigger/Cyclone_Arrival/json/with/key/cg4figw1WAkZDkQP2ujsvE"; 
            Serial.print("Requesting URL: ");
            Serial.println(url);                 
            client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");    
         }                     
          else
          {
            // Serial.println("We Might Expect a Cyclone !!!");            
          }          
       delay(1000);  

}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}
