#include "Arduino.h"
#include "WiFiMulti.h"
#include "Audio.h"

#define I2S_DOUT      16
#define I2S_BCLK      15
#define I2S_LRC       18

Audio audio;
WiFiMulti wifiMulti;
String ssid =     "";
String password = "";


void setup() {
    Serial.begin(921600);
    WiFi.mode(WIFI_STA);
    wifiMulti.addAP(ssid.c_str(), password.c_str());
    wifiMulti.run();
    if(WiFi.status() != WL_CONNECTED){
        WiFi.disconnect(true);
        wifiMulti.run();
    }
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(5); // 0...21

//    audio.connecttoFS(SD, "test.wav");
//    audio.connecttohost("http://www.wdr.de/wdrlive/media/einslive.m3u");
//    audio.connecttohost("http://somafm.com/wma128/missioncontrol.asx"); //  asx
   // audio.connecttohost("http://mp3.ffh.de/radioffh/hqlivestream.aac"); //  128k aac
      //audio.connecttohost("http://mp3.ffh.de/radioffh/hqlivestream.mp3"); //  128k mp3
      audio.connecttohost("https://regiocast.streamabc.net/regc-80s80sparty9936054-mp3-192-1227605?sABC=66pnr83r%230%23on85q0r5sqso653s9q3nr915911n1po4%23fgernzf.80f80f.qr&aw_0_1st.playerid=streams.80s80s.de&amsparams=playerid:streams.80s80s.de;skey:1724573758");
     
}

void loop()
{
    audio.loop();
    /*
    if(Serial.available()){ // put streamURL in serial monitor
        audio.stopSong();
        String r=Serial.readString(); r.trim();
        if(r.length()>5) audio.connecttohost(r.c_str());
        log_i("free heap=%i", ESP.getFreeHeap());
    }
    */
}

// optional
void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char *info){  //id3 metadata
    Serial.print("id3data     ");Serial.println(info);
}
void audio_eof_mp3(const char *info){  //end of file
    Serial.print("eof_mp3     ");Serial.println(info);
}
void audio_showstation(const char *info){
    Serial.print("station     ");Serial.println(info);
}
void audio_showstreamtitle(const char *info){
    Serial.print("streamtitle ");Serial.println(info);
}
void audio_bitrate(const char *info){
    Serial.print("bitrate     ");Serial.println(info);
}
void audio_commercial(const char *info){  //duration in sec
    Serial.print("commercial  ");Serial.println(info);
}
void audio_icyurl(const char *info){  //homepage
    Serial.print("icyurl      ");Serial.println(info);
}
void audio_lasthost(const char *info){  //stream URL played
    Serial.print("lasthost    ");Serial.println(info);
}
