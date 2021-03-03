#include <LiquidCrystal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "inc/tm4c123gh6pm.h"

const int button_1 = PB_2; 
const int button_2 = PE_0;     
const int button_3 = PF_0;     
const int button_4 = PB_7;     
const int button_5 = PB_6;     
const int button_6 = PA_4;     
const int button_reset = PUSH2;


const int ledPin =  PE_2;
const int ledPin_yesil  =  PE_3;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

int buttonState_1 = 0; 
int buttonState_2 = 0;
int buttonState_3 = 0;
int buttonState_4 = 0;
int buttonState_5 = 0;
int buttonState_6 = 0;
int buttonState_7 = 0;
int buttonState_8 = 0;
int buttonState_9 = 0;
int buttonState_10 = 0;
int buttonState_reset = 0;

int para[3] = { 20, 20, 10 };
int stok[5] = { 30, 20, 15, 50, 100 };

int bir=0;
int elli=0;
int krs_25=0;
int degisken=0;
int degisken_1=0;
int degisken_2=0;
int degisken_3=0;
int degisken_4=0;
int degisken_5=0;
int degisken_6=0;
int degisken_7=0;
int degisken_8=0;
int degisken_reset=0;

int su=0;
int cay=0;
int kahve=0;
int cikolata=0;
int biskuvi=0;
int bitis=0;

float kalan=0;
float kasa_toplam = ( para[0]*0.25 ) + ( para[1]*0.5 ) + ( para[2]*1 );
int rastgele=0; 
float toplam=0;
float urun_toplam=0;
int para_ustu=0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16, 2);
  lcd.println("|----OTOMAT----|");
  lcd.setCursor(0, 1);
  lcd.print("---Para Atiniz---");
  Serial.begin(9600);
    
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin_yesil, OUTPUT);      
  
  pinMode(button_1, INPUT_PULLUP);     
  pinMode(button_2, INPUT_PULLUP);     
  pinMode(button_3, INPUT_PULLUP);     
  pinMode(button_4, INPUT_PULLUP);     
  pinMode(button_5, INPUT_PULLUP);     
  pinMode(button_6, INPUT_PULLUP);   
  pinMode(button_reset, INPUT_PULLUP);     

}


void loop()
{

//////////////////////////////// krs_25 
    buttonState_1 = digitalRead(button_1);

  if (buttonState_1 == HIGH) {         
  } 
  else {
    delay(500);
    degisken++;
  }
    if(degisken>0)
  {
    krs_25++;
    degisken=0;
    para[0]=para[0]+1;
  }

//////////////////////////////// 50 krs 
  buttonState_2 = digitalRead(button_2);

  if (buttonState_2 == HIGH) {      
  } 
  else {
    delay(500);
    degisken_1++;
  }
    if(degisken_1>0)
  {
    elli++;
    degisken_1=0;
    para[1]=para[1]+1;
  }

//////////////////////////////// bir tl
  buttonState_3 = digitalRead(button_3);


  if (buttonState_3 == HIGH) {     
   } 
  else {
    delay(500);
    degisken_2++;
  }
    if(degisken_2>0)
  {
  bir++;
  degisken_2=0;
  para[2]=para[2]+1;
  }

  ///// bitiş
    buttonState_4 = digitalRead(button_4);

  if (buttonState_4 == HIGH) {     
  } 
  else {
    
    toplam= toplam + (krs_25*0.25);
    toplam= toplam + (elli*0.5);
    toplam= toplam + bir;
    
    delay(500);
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print((int)toplam);
    lcd.setCursor(1, 0);
    lcd.print(toplam,2);
    lcd.setCursor(1, 0);
    lcd.print("TL");
    lcd.setCursor(5,0);
    lcd.print("Krs Attiniz");

    lcd.setCursor(0, 1);
    lcd.println("--Urun Seciniz--");
    while(1)
    {
      delay(400);
 
 while(1)
 {
///////reset
buttonState_reset = digitalRead(button_reset);

  if (buttonState_reset == HIGH) {         
  } 
  else {
    delay(500);
    bir=0;
    elli=0;
    krs_25=0;
    su=0;
    cay=0;
    kahve=0;
    cikolata=0;
    biskuvi=0;
    goto basa_don;
  }
  
  ////su
 buttonState_5 = digitalRead(button_1);

  if (buttonState_5 == HIGH) {       
  } 
  else {
    delay(500);
    degisken_3++;
  }
    if(degisken_3>0)
  {
    su++;
    degisken_3=0;
  }

/////////////cay
 buttonState_6 = digitalRead(button_2);

  if (buttonState_6 == HIGH) {         
  } 
  else {
    delay(500);
    degisken_4++;
  }
    if(degisken_4>0)
  {
    cay++;
    degisken_4=0;
  }

/////////kahve
 buttonState_7 = digitalRead(button_3);

  if (buttonState_7 == HIGH) {       
  } 
  else {
    delay(500);
    degisken_5++;
  }
    if(degisken_5>0)
  {
    kahve++;
    degisken_5=0;
  }

//cikolata
 buttonState_8 = digitalRead(button_4);

  if (buttonState_8 == HIGH) {      
  } 
  else {
    delay(500);
    degisken_6++;
  }
    if(degisken_6>0)
  {
    cikolata++;
    degisken_6=0;
  }

////// bisküvi
 buttonState_9 = digitalRead(button_5);

  if (buttonState_9 == HIGH) {     
  } 
  else {
    delay(500);
    degisken_7++;
  }
    if(degisken_7>0)
  {
    biskuvi++;
    degisken_7=0;
  }
  
/// bitiş
 buttonState_10 = digitalRead(button_6);
 
  if (buttonState_10 == HIGH) {      
  } 
  else {
    delay(500);
    
  lcd.clear();
  lcd.println("|----OTOMAT----|");
  lcd.setCursor(0, 1);
  lcd.println("-----Bitti-----");
  break;
 }
 }
 
  randomSeed(analogRead(A2));
  rastgele=random(0,5);

  if (rastgele == 2) {     
  digitalWrite(ledPin, HIGH);  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("PARANIZ SIKISTI!");
  lcd.setCursor(0, 1);
  lcd.println("--GERI ALINIZ!--");
    para[0]=para[0]-krs_25;
    para[1]=para[1]-elli;
    para[2]=para[2]-bir;
    bir=0;
    elli=0;
    krs_25=0;
    su=0;
    cay=0;
    kahve=0;
    cikolata=0;
    biskuvi=0;
  delay(2000);
  break;
  } 
  else {
  digitalWrite(ledPin_yesil, HIGH); 
  urun_toplam=  urun_toplam + (su*0.50);
   urun_toplam=  urun_toplam + (cay*1);
    urun_toplam=  urun_toplam + (kahve*1.5);
     urun_toplam=  urun_toplam + (cikolata*1.75);
       urun_toplam=  urun_toplam + (biskuvi*2);
  Serial.print("Urunlerin Fiyat Toplami: ");
  Serial.println(urun_toplam);
  
  if( urun_toplam > toplam)
  {
  lcd.setCursor(0, 0);
  lcd.println("YETERSIZ BAKIYE!");
  lcd.setCursor(0, 1);
  lcd.println("--GERI ALINIZ!--");
  bir=0;
  elli=0;
  krs_25=0;
  break;
  }
  if( urun_toplam <= toplam)
  {
  kalan = toplam - urun_toplam;
  Serial.print("Atilan Para Toplami: ");
  Serial.println(toplam);
  Serial.print("Para Ustu Miktari: ");
  Serial.println(kalan);
  para_ustu = kalan / 1;
    if(para_ustu>para[2])
  {
     
  }
  else
  {
    para[2]=para[2] - para_ustu;  
    kalan = kalan - (para_ustu*1);
  }
  para_ustu = kalan / 0.5;
   if(para_ustu>para[1])
  {
     
  }
  else
  {
    para[1]=para[1] - para_ustu;  
    kalan = kalan - (para_ustu*0.5);
  } 
  para_ustu = kalan / 0.25;
    if(para_ustu>para[0])
  {
  lcd.setCursor(0, 0);
  lcd.println("KASADA PARA YOK!");
  }
  else
  {
    para[0]=para[0] - para_ustu;  
    kalan = kalan - (para_ustu*0.25);
  }

  stok[0] = stok[0] - su;
  stok[1] = stok[1] - cay;
  stok[2] = stok[2] - kahve;
  stok[3] = stok[3] - cikolata;
  stok[4] = stok[4] - biskuvi;

  basa_don: ;
  
  Serial.println("Para Miktari: ");
  Serial.println(para[0]);
  Serial.println(para[1]);
  Serial.println(para[2]);
  Serial.println("Stok Durumu: ");
  Serial.println(stok[0]);
  Serial.println(stok[1]);
  Serial.println(stok[2]);
  Serial.println(stok[3]);
  Serial.println(stok[4]);
  bir=0;
  elli=0;
  krs_25=0;
  lcd.setCursor(0, 0);
  lcd.println("|----OTOMAT----|");
  lcd.setCursor(0, 1);
  lcd.print("---Para Atiniz---");
  break;
    }
  }
}
}
}
