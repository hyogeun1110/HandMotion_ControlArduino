#include<Adafruit_NeoPixel.h>                        //네오픽셀 라이브레리
#define ledPin 6                                     //아두이노의 디지털 6번핀을 "ledPin"로 지정 (네오픽셀이 아두이노에 연결된 핀)
#define numLeds 12                                   //12(네오픽셀의 led개수) 를 "numLeds"로 지정
Adafruit_NeoPixel strip(numLeds, ledPin, NEO_GRB + NEO_KHZ800); 

// NEO_GRB 네오픽셀들이 GRB 비트스트림으로 연결되어있음 (비트스트림 : 한번에 한비트씩 직렬 통신선로를 통해 연속적으로 전송되는 데이터의 흐름)
// NEO_KHZ800 800KHz의 비트스트림

void setup() {
  Serial.begin(9600);
  strip.begin();                 //작동시작
  strip.show();                  //초기값 (LED 모두꺼짐)
  strip.setBrightness(255);      // 밝기지정 (0~255 값이 있으며 255 일 때 가장 밝다))
}

void loop() {
  while (Serial.available() > 0){ // Serial.available()는 아두이노가 받은 데이터가 있는지 확인하는 명령어.
    char sign = Serial.read();
    if(sign == '4'){
        strip.setPixelColor(0,255,0,0);     // 0번째 (=네오픽셀에서는 1번째) LED를 R:255, G:0, B:0 의밝기로 켠다
        strip.setPixelColor(1,255,0,0);
        strip.setPixelColor(2,255,50,0);     // 0번째 (=네오픽셀에서는 1번째) LED를 R:255, G:0, B:0 의밝기로 켠다
        strip.setPixelColor(3,255,50,0);
        strip.setPixelColor(4,255,0,100);     // 0번째 (=네오픽셀에서는 1번째) LED를 R:255, G:0, B:0 의밝기로 켠다
        strip.setPixelColor(5,255,0,100);
        strip.setPixelColor(6,255,100,100);     // 0번째 (=네오픽셀에서는 1번째) LED를 R:255, G:0, B:0 의밝기로 켠다
        strip.setPixelColor(7,255,100,100);
        strip.setPixelColor(8,255,150,100);
        strip.setPixelColor(9,255,100,150);
        strip.setPixelColor(10,255,200,100);
        strip.setPixelColor(11,255,100,200);
        strip.show();
    }
   else if(sign == '2'){
      strip.setPixelColor(0,255,0,0);     
      strip.setPixelColor(1,255,0,0);
      strip.setPixelColor(2,255,0,0);    
      strip.setPixelColor(3,255,0,0);
      strip.setPixelColor(4,255,0,0);     
      strip.setPixelColor(5,255,0,0);
      strip.setPixelColor(6,255,0,0);    
      strip.setPixelColor(7,255,0,0);
      strip.setPixelColor(8,255,0,0);
      strip.setPixelColor(9,255,0,0);      
      strip.setPixelColor(10,255,0,0);
      strip.setPixelColor(11,255,0,0); 
      strip.show();  
   }
   else if(sign == '1'){
     strip.setPixelColor(0,0,255,0);     
     strip.setPixelColor(1,0,255,0);
     strip.setPixelColor(2,0,255,0);    
     strip.setPixelColor(3,0,255,0);
     strip.setPixelColor(4,0,255,0);     
     strip.setPixelColor(5,0,255,0);
     strip.setPixelColor(6,0,255,0);    
     strip.setPixelColor(7,0,255,0);
     strip.setPixelColor(8,0,255,0);
     strip.setPixelColor(9,0,255,0);      
     strip.setPixelColor(10,0,255,0);
     strip.setPixelColor(11,0,255,0); 
     strip.show();              
   }
   else if(sign == '3'){
     strip.setPixelColor(0,255,0,255);     
     strip.setPixelColor(1,0,255,255);
     strip.setPixelColor(2,255,0,255);    
     strip.setPixelColor(3,0,255,255);
     strip.setPixelColor(4,255,0,255);     
     strip.setPixelColor(5,0,255,255);
     strip.setPixelColor(6,255,0,255);    
     strip.setPixelColor(7,0,255,255);
     strip.setPixelColor(8,255,0,255);
     strip.setPixelColor(9,0,255,255);      
     strip.setPixelColor(10,255,0,255);
     strip.setPixelColor(11,0,255,255); 
     strip.show();              
   }
      else if(sign == '5'){
     strip.setPixelColor(0,0,0,0);     
     strip.setPixelColor(1,0,0,0);
     strip.setPixelColor(2,0,0,0);    
     strip.setPixelColor(3,0,0,0);
     strip.setPixelColor(4,0,0,0);     
     strip.setPixelColor(5,0,0,0);
     strip.setPixelColor(6,0,0,0);    
     strip.setPixelColor(7,0,0,0);
     strip.setPixelColor(8,0,0,0);
     strip.setPixelColor(9,0,0,0);      
     strip.setPixelColor(10,0,0,0);
     strip.setPixelColor(11,0,0,0); 
     strip.show();              
   }
    else if(sign == '0'){
      Serial.println("off");
      strip.setPixelColor(0,0,0,0);     
      strip.setPixelColor(1,0,0,0);
      strip.setPixelColor(2,0,0,0);    
      strip.setPixelColor(3,0,0,0);
      strip.setPixelColor(4,0,0,0);     
      strip.setPixelColor(5,0,0,0);
      strip.setPixelColor(6,0,0,0);    
      strip.setPixelColor(7,0,0,0);
      strip.setPixelColor(8,0,0,0);
      strip.setPixelColor(9,0,0,0);      
      strip.setPixelColor(10,0,0,0);
      strip.setPixelColor(11,0,0,0); 
      strip.show();                       // 색 설정 후에는 반드시 show()를 해주어야한다 (업데이트)
    }
  }
}
