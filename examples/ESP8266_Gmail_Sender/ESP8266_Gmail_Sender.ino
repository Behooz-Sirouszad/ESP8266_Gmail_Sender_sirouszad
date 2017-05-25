//This Library and Example is written By: BSIZ1757( Behrooz Sirouszad) ITPro.ir 5.25.2017 b.sirouszad@gmail.com
//this will send a simple email to your email address
#include <Gsender.h>
#include <ESP8266WiFi.h>

Gsender *gsender = Gsender::Instance(); // Getting pointer to class instance
//WiFi Setup
const char* ssid ="YourSSID";
const char* password= "Your Password";
//Gmail Setup
int Gamil_smtp_port =465;
const char* Gmail_server_address = "smtp.gmail.com"; 
const char* Gmail_Login = "YourBase64 User";
const char* Gmail_password = "YourBase64 Password";
String Gmail_subject = "Your subject";
const char* Gmail_from= "**youremail**@gmail.com";
String Destination_address="your Destionation email address";
String Message =" your Message";

 
void setup() {

  
  Serial.begin(115200);
  WiFi.begin(ssid,password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
send_gmail();
}

void loop() {
  


  
}

void send_gmail(){
   
  
    gsender->SMTP_PORT=Gamil_smtp_port;
    gsender->SMTP_SERVER = Gmail_server_address;
    gsender->EMAILBASE64_LOGIN = Gmail_Login;
    gsender->EMAILBASE64_PASSWORD = Gmail_password;
    gsender->FROM = Gmail_from;
    if(gsender->Subject(Gmail_subject)->Send(Destination_address, Message)) {
        Serial.println("Message is Sent");
    } else {
        Serial.print("Error sending message: ");
        Serial.println(gsender->getError());
    }
}

