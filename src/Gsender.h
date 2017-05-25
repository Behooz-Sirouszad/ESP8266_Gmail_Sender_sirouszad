//This Library written and Compiled by :Behrooz Sirouszad ITPro.ir  b.sirouszad@gmail.com 5.25.2017
#ifndef G_SENDER
#define G_SENDER
#define GS_SERIAL_LOG_1         // Print to Serial only server responce
//#define GS_SERIAL_LOG_2       //  Print to Serial client commands and server responce
#include <WiFiClientSecure.h>

class Gsender
{
    public:
        Gsender();
    public:
         int SMTP_PORT= 465 ;
        const char* SMTP_SERVER ;
        const char* EMAILBASE64_LOGIN ;
        const char* EMAILBASE64_PASSWORD  ;
        const char* FROM  ;
        const char* _error = nullptr;
        char* _subject = nullptr;
        String _serverResponce;
        static Gsender* _instance;
        bool AwaitSMTPResponse(WiFiClientSecure &client, const String &resp = "", uint16_t timeOut = 10000);
        static Gsender* Instance();
        Gsender* Subject(const char* subject);
        Gsender* Subject(const String &subject);
        bool Send(const String &to, const String &message);
        String getLastResponce();
        const char* getError();
};
#endif // G_SENDER
