#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define ID_NUM1 1
#define ID_NUM2 2
#define ID_NUM3 3
#define ID_NUM4 4
#define ID_NUM5 5
#define ID_NUM6 6
#define ID_NUM7 9
#define ID_NUM8 10
#define ID_NUM9 11
#define ID_NUM10 12
#define ID_NUM11 13
#define ID_NUM12 14
#define ID_NUM13 15
#define ID_NUM14 16
#define ID_NUM15 17
#define ID_NUM16 18

Dynamixel Dxl(DXL_BUS_SERIAL3);
const long interval = 100;
unsigned long previousTime = 0;

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.jointMode(ID_NUM1); 
  Dxl.jointMode(ID_NUM2); 
  //Serial.begin(9600);
}



void loop() 
{ 
  if (SerialUSB.available() > 0) 
  { 
    char data = SerialUSB.read();
    if (data == 'A') 
    {
      berdiri_tegak();
    }
    
    else if (data == 'B') 
    {
      melambaikan();
    delay(10000);

    }
    
     else if (data == 'C')
     {
       kuda_kuda();
    delay(10000);
     }
     
     else if (data == 'D')
     {
       pukul();
    delay(10000);
     }  
     
     else if (data == 'E')
     {
      senam_tangan();
    delay(10000);
     }
     
     else if (data == 'F')
     {
      berjalan();
    delay(10000);
     }
     
     else if (data == 'G')
     {
      jalan_ditempat();
    delay(10000);
     }   
     
  }
    
}

void berdiri_tegak()
{
  // kaki kanan
 Dxl.setPosition(ID_NUM7,530,50);
  Dxl.setPosition(ID_NUM9,670,50);
  Dxl.setPosition(ID_NUM11,612,50);
   Dxl.setPosition(ID_NUM13,512,50);
   Dxl.setPosition(ID_NUM15,530,50);
    // kaki kiri
 Dxl.setPosition(ID_NUM8,500,50);
 Dxl.setPosition(ID_NUM10,364,50);
 Dxl.setPosition(ID_NUM12,412,50);
 Dxl.setPosition(ID_NUM14,512,50);
 Dxl.setPosition(ID_NUM16,500,50);
 //tangankanandankiri
   Dxl.setPosition(ID_NUM1,515,50);
  delay(2000);
  Dxl.setPosition(ID_NUM3,550,50);
  Dxl.setPosition(ID_NUM5,315,50);
  //----
    Dxl.setPosition(ID_NUM2,515,50);
    delay(2000);
    Dxl.setPosition(ID_NUM4,460,50);
    Dxl.setPosition(ID_NUM6,715,50);
 
}

void berjalan()
{
    //setup
    delay(250);
  Dxl.setPosition(13, 622, 50); //tambah tinggi tambah nekuk(722)
  Dxl.setPosition(14, 302, 50); //tambah rendah tambah nekuk(302)
  Dxl.setPosition(17, 572, 50); //makin tinggi maskin ke dalam(522)
  Dxl.setPosition(18, 552, 50); //makin rendah makin kedalam(502)
  Dxl.setPosition(15, 612, 50); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 412, 50); //tambah rendah tambah kedepan(412)
  delay(500);
  Dxl.setPosition(13, 622, 50); //tambah tinggi tambah nekuk(722) //wasting
  Dxl.setPosition(14, 302, 50); //tambah rendah tambah nekuk(302) //wasting
  Dxl.setPosition(15, 412, 50); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 412, 50); //tambah rendah tambah kedepan(412)
  delay(500);
  //paha maju
  Dxl.setPosition(11, 702, 50); //tambah tinggi tambah maju(672)
  Dxl.setPosition(12, 352, 50); //tambah tinggi tambah mundur(352)
  Dxl.setPosition(15, 512, 100); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 412, 100); //tambah rendah tambah kedepan(412)
  delay(500);
  //telapak normal
  Dxl.setPosition(17, 522, 50); //makin tinggi makin ke dalam(522)
  Dxl.setPosition(18, 502, 50); //makin rendah makin ke dalam(502)
  Dxl.setPosition(15, 532, 100); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 392, 100); //tambah rendah tambah kedepan(412)
  delay(500);
  //support
  Dxl.setPosition(11, 722, 25); //tambah tinggi tambah maju(672)
  Dxl.setPosition(12, 302, 25); //tambah tinggi tambah mundur(352)
  delay(1000);
  Dxl.setPosition(17, 472, 50); //makin tinggi makin ke dalam(522)
  Dxl.setPosition(18, 452, 50); //makin rendah makin ke dalam(502)
  Dxl.setPosition(15, 532, 150); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 552, 150); //tambah rendah tambah kedepan(412)
  delay(500);
  Dxl.setPosition(15, 532, 150); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 472, 150); //tambah rendah tambah kedepan(412)
  delay(500);
  Dxl.setPosition(13, 622, 50); //tambah tinggi tambah nekuk(722)
  Dxl.setPosition(14, 402, 100); //tambah rendah tambah nekuk(302)
  delay(500);
  //menapak
  Dxl.setPosition(17, 522, 50); //makin tinggi makin kedalam(522)
  Dxl.setPosition(18, 502, 50); //makin rendah makin kedalam(502)
  delay(250);
  Dxl.setPosition(11, 672, 50); //tambah tinggi tambah maju(672)
  Dxl.setPosition(12, 352, 50); //tambah tinggi tambah mundur(352)
  Dxl.setPosition(13, 622, 50); //tambah tinggi tambah nekuk(722)
  Dxl.setPosition(14, 402, 50); //tambah rendah tambah nekuk(302)
  Dxl.setPosition(15, 532, 100); ////tambah tinggi tambah kedepan(612)
  Dxl.setPosition(16, 502, 100); //tambah rendah tambah kedepan(412)
}

void jalan_ditempat()
{
    Dxl.setPosition(ID_NUM1,815,100);
    Dxl.setPosition(ID_NUM3,415,100);
    Dxl.setPosition(ID_NUM5,215,100);
    Dxl.setPosition(ID_NUM2,215,100);
    Dxl.setPosition(ID_NUM4,415,100);
    Dxl.setPosition(ID_NUM6,515,100);
    delay(1000);
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,615,300);
    Dxl.setPosition(ID_NUM6,515,300);
    delay(1000);
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(3000);
    //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(3000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(3000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
        //kanan
    Dxl.setPosition(ID_NUM11,562,50);
    Dxl.setPosition(ID_NUM12,412,50);
    delay(1000);
    //kiri
    Dxl.setPosition(ID_NUM11,612,50);
    Dxl.setPosition(ID_NUM12,362,50);
    delay(1000);
}

void kuda_kuda()
{
     // kaki kanan
 Dxl.setPosition(ID_NUM7,530,50);
  Dxl.setPosition(ID_NUM9,670,50);
  Dxl.setPosition(ID_NUM11,612,50);
   Dxl.setPosition(ID_NUM13,450,50);
   Dxl.setPosition(ID_NUM15,530,50);
    // kaki kiri
 Dxl.setPosition(ID_NUM8,500,50);
 Dxl.setPosition(ID_NUM10,574,50);
 Dxl.setPosition(ID_NUM12,412,50);
 Dxl.setPosition(ID_NUM14,352,50);
 Dxl.setPosition(ID_NUM16,500,50);
 //tangan kanan
   Dxl.setPosition(ID_NUM1,615,50);
  delay(2000);
  Dxl.setPosition(ID_NUM3,515,50);
  Dxl.setPosition(ID_NUM5,215,50);
  //tangan kiri
    Dxl.setPosition(ID_NUM2,415,50);
    delay(2000);
    Dxl.setPosition(ID_NUM4,515,50);
    Dxl.setPosition(ID_NUM6,515,50);
}

void melambaikan()
{
  Dxl.setPosition(ID_NUM1,1023,300);
  delay(2000);
  Dxl.setPosition(ID_NUM3,315,100);
  Dxl.setPosition(ID_NUM5,15,100);
  delay(1000);
  Dxl.setPosition(ID_NUM3,315,300);
  delay(1000);
  Dxl.setPosition(ID_NUM3,515,300);
   delay(1000);
  Dxl.setPosition(ID_NUM3,315,300);
  delay(1000);
  Dxl.setPosition(ID_NUM3,515,300);
    delay(1000);
  Dxl.setPosition(ID_NUM3,315,300);
  delay(1000);
  Dxl.setPosition(ID_NUM3,615,300);
  delay(1000);
  Dxl.setPosition(ID_NUM1,515,100);
  Dxl.setPosition(ID_NUM3,615,100);
  Dxl.setPosition(ID_NUM5,15,100);
  
} 

void pukul()
{
   Dxl.setPosition(ID_NUM1,615,100);
  Dxl.setPosition(ID_NUM3,615,100);
  Dxl.setPosition(ID_NUM5,215,100);
  delay(1000);
  
  Dxl.setPosition(ID_NUM1,515,200);
  Dxl.setPosition(ID_NUM3,615,100);
  Dxl.setPosition(ID_NUM5,215,100);
  delay(1000);
  Dxl.setPosition(ID_NUM1,815,400);
  Dxl.setPosition(ID_NUM3,615,100);
  Dxl.setPosition(ID_NUM5,215,100);
  delay(1000);
  Dxl.setPosition(ID_NUM1,615,300);
  Dxl.setPosition(ID_NUM3,615,100);
  Dxl.setPosition(ID_NUM5,215,100);
}

void senam_tangan()
{
  //tangan kiri
    Dxl.setPosition(ID_NUM1,815,100);
    Dxl.setPosition(ID_NUM3,415,100);
    Dxl.setPosition(ID_NUM5,215,100);
  //tangan kiri
    Dxl.setPosition(ID_NUM2,215,100);
    Dxl.setPosition(ID_NUM4,515,100);
    Dxl.setPosition(ID_NUM6,515,100);
    delay(1000);
  //gerakan 1
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,415,300);
    Dxl.setPosition(ID_NUM6,515,300);
    delay(1000);
  // gerakan 2
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,615,300);
    Dxl.setPosition(ID_NUM6,515,300);
    delay(1000);
  // gerakan 3 
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,415,300);
    Dxl.setPosition(ID_NUM6,515,300);
    delay(1000);
    // gerakan 4
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,615,300);
    Dxl.setPosition(ID_NUM6,515,300);
    delay(1000);
    //gerakan 5
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,415,300);
    Dxl.setPosition(ID_NUM6,515,300);
    delay(1000);
    //gerakan 6
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,415,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,615,300);
    delay(1000);
    //gerakan 7
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,315,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,415,300);
    delay(1000);
    //gerakan 8
    Dxl.setPosition(ID_NUM1,815,300);
    Dxl.setPosition(ID_NUM3,315,300);
    Dxl.setPosition(ID_NUM5,215,300);
    
    Dxl.setPosition(ID_NUM2,215,300);
    Dxl.setPosition(ID_NUM4,615,300);
    delay(1000);
    
    // gerakan selesai
    Dxl.setPosition(ID_NUM3,515,300);
    Dxl.setPosition(ID_NUM5,15,300);
    Dxl.setPosition(ID_NUM4,415,300);
    Dxl.setPosition(ID_NUM6,715,300);
    delay(500);
    Dxl.setPosition(ID_NUM1,515,300);
    Dxl.setPosition(ID_NUM2,515,300);

}

