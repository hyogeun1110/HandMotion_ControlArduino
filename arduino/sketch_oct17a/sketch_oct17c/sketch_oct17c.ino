#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

int cur=0;
char charBuf[50];

long time_prev=0;
long time_cur=0;

char key_01 = ' ';
char key_02 = ' ';

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  mySerial.begin(9600);
  
  init_dotmatrix();
}
char originSign = '9';

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){ // Serial.available()는 아두이노가 받은 데이터가 있는지 확인하는 명령어.
    char sign = Serial.read();
    if(sign == '1' && sign != originSign){
        display_h_fix("A1:ONE");
        originSign = '1';
    }
    else if(sign == '2' && sign != originSign){
       display_h_fix("A1:TWO");
       originSign = '2';
    }
    else if(sign == '3' && sign != originSign){
       display_h_fix("A1:THREE");
       originSign = '3';
    }
    else if(sign == '4' && sign != originSign){
       display_h_fix("A1:FOUR");
       originSign = '4';
    }
    else if(sign == '5' && sign != originSign){
       display_h_fix("A1:FIVE");
       originSign = '5';
    }
    else if(sign == '6' && sign != originSign){
       display_h_fix("A1:연성대학교");
       originSign = '6';
    }
    else if(sign == '7' && sign != originSign){
       display_h_fix("A1:긴급전화");
       originSign = '7';
    }
    else if(sign == '8' && sign != originSign){
       display_h_fix("A1:확인");
       originSign = '8';
    }
    else if(sign == '0' && sign != originSign){
       display_h_fix("A1:");
       originSign = '0';
    }
   }
}

void init_dotmatrix()
{
  Serial.println("1: ");
  hdot_println("'<0,0,1: '>");
}

void display_h_fix(String arg_msg)
{
  String str_result = "'<0,0,"+arg_msg+"'>";
  Serial.println(arg_msg);
  hdot_println(str_result);
}

void display_h_shift(String arg_msg)
{
  String str_result = "'<0,1,"+arg_msg+"'>";
  Serial.println(arg_msg);  
  hdot_println(str_result);
}

void set_speed(int arg_value)
{
  if(arg_value == 1)
    hdot_println("'<2,0,1: '>");
  else if(arg_value == 2)
    hdot_println("'<2,1,1: '>");
  else if(arg_value == 3)
    hdot_println("'<2,2,1: '>");
}

void display_v_fix(String arg_msg)
{
  String str_result = "'<1,0,"+arg_msg+"'>";
  Serial.println(arg_msg);
  
  hdot_println(str_result);
}

void display_v_shift(String arg_msg)
{
  String str_result = "'<1,1,"+arg_msg+"'>";
  Serial.println(arg_msg);
  
  hdot_println(str_result);
}

void hdot_println(String arg_msg) {
  time_cur = millis();
  mySerial.println(arg_msg);
  delay(1000);
  recv_check(); 
}

void recv_check() {
  
  while(1)
  {
    key_01 = key_02;
    key_02 = mySerial.read();      
    
    if(key_02 != 0xFFFF)
    {
      Serial.print(key_02);
    }
    
    if(key_01 == 'o' && key_02 == 'k')
    {
      time_prev = time_cur;
      time_cur = millis();
      long time_value = time_cur-time_prev;
      Serial.print(" =========> ");
      Serial.println(time_value);
      Serial.print("\n");
      break;
    }
    delay(1);
  }

  while(mySerial.read() != -1);

}
