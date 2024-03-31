#include <TFT.h>
#include <SPI.h>

// pin definition for Arduino UNO
#define cs 10
#define dc 9
#define rst 12


// pin definition for Joystick Shield
#define pin_x A0
#define pin_y A1

#define ST7735_GREY 0x8410

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

void setup() {

  //initialize the library
  TFTscreen.begin();
  

  // clear the screen with a black background
  TFTscreen.background(0,0,0);

  //set the text size
  TFTscreen.setTextSize(1);
  Serial.begin(9600);
  randomSeed(analogRead(2));
  TFTscreen.setRotation(1);

  //Red and white stripes (building part)
  for (int y = 0; y < 135; y += 27) {
    TFTscreen.fillRect(0, y, 10, 25, ST7735_GREY);
    TFTscreen.fillRect(0, y + 25, 10, 2, ST7735_WHITE);
  }
}

void loop() {
  int p = analogRead(pin_x);
  Serial.print("x = ");
  Serial.println((p - 340) / 8 + 55);
  int x = (p - 340) / 8 + 55;
  TFTscreen.fillRect(x, 125, 30, 25, ST7735_BLUE);

  Serial.print("y = ");
  int randomNumber = random(1, 5);
  Serial.println(randomNumber);


  static int y = 0;
  static int score = -1;

  if (y == 0) {
    int lag = random(0,3);
    delay(1000*lag);

    switch (3) {
      case 1:
       y =  1;
        break;

      case 2:
        y = 2;
        break;

      case 3:
        y = 3;
        break;

      case 4:
        y = 4;
        break;
    }
    score += 1;
  }

   Serial.print("y");
   Serial.println(y);
   Serial.print("score");
   Serial.println(score);
  if (y == 1){
    y = path1(score);
  }
  if (y == 2) {
    y = path2(score);
  }
  if (y == 3) {
    y = path3(score);
  }
  if (y == 4) {
    y = path4(score);
  }

}
int path1(int u) {
  int w=1;
  static float j = 7;
  int p = analogRead(pin_x);

  static int q = 0;
  int a;
  if (j < 47) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j,102.2281+0.0157*j*j, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j,102.2281+0.0157*j*j, 2, ST7735_RED);
    j += 3;
  }
  int x = (p - 340) / 8 + 55;
  if ((j == 49) && (x > 10) && (x < 50)) {
    q = 1;
  }
   if(j==49&&x>50){
    gameover(u);
    w=10;
  }

  if (q== 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_RED);
    j += 3;
    if (j > 100) {
      q = 0;
    }
  }

  static int r = 0;
  if (j == 103 && x > 65 && x <= 100) {
    r = 1;
  }
  if ((j==103)&&(x<65)){
    gameover(u);
    w=10;
  }
  if(r == 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_RED);
    j += 3;
    if (j > 135) {
      r = 0;
      w = 0;
      j = 7;
    }
  }

  return w;
}

int path2(int u) {
  
  int w=2;
  static float j = 7;
  int p = analogRead(pin_x);

  static int q = 0;
  int a;
  if (j < 47) {
    TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 74.6656+0.0272*j*j, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j,  74.6656+0.0272*j*j, 2, ST7735_RED);
    j += 3;
  }
  int x = (p - 340) / 8 + 55;
  if ((j == 49) && (x > 10) && (x < 50)) {
    q = 1;
  }
   if(j==49&&x>50){
    gameover(u);
    w=10;
  }

  if (q== 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_RED);
    j += 3;
    if (j > 100) {
      q = 0;
    }
  }

  static int r = 0;
  if (j == 103 && x > 65 && x <= 100) {
    r = 1;
  }
  if ((j==103)&&(x<65)){
    gameover(u);
    w=10;
  }
  if(r == 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_RED);
    j += 3;
    if (j > 135) {
      r = 0;
      w = 0;
      j = 7;
    }
  }

  return w;
}
int path3(int u) {
  int w=3;
 static float j = 7;
  int p = analogRead(pin_x);

  static int q = 0;
  int a;
  if (j < 47) {
    TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j,47.1031+0.0387*j*j, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 47.1031+0.0387*j*j, 2, ST7735_RED);
    j += 3;
  }
  int x = (p - 340) / 8 + 55;
  if ((j == 49) && (x > 10) && (x < 50)) {
    q = 1;
  }
  
  if(j==49&&x>50){
    gameover(u);
    w =10;
    
  }

  if (q== 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_RED);
    j += 3;
    if (j > 100) {
      q = 0;
    }
  }

  static int r = 0;
  if (j == 103 && x > 65 && x <= 100) {
    r = 1;
  }
  if ((j==103)&&(x<65)){
    gameover(u);
    w=10;
   
  }
  if(r == 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_RED);
    j += 3;
    if (j > 130) {
      r = 0;
      w = 0;
      j = 7;
    }
  }

  return w;
}

int path4(int u) {
  int w=4;
  static float j = 7;
  int p = analogRead(pin_x);

  static int q = 0;
  int a;
  if (j < 47) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 20 + 0.05 * j * j, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 20 + 0.05 * j * j, 2, ST7735_RED);
    j += 3;
  }
  int x = (p - 340) / 8 + 55;
  if ((j == 49) && (x > 10) && (x < 50)) {
    q = 1;
  }
   if(j==49&&x>50){
    gameover(u);
    w=10;
  }

  if (q== 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.07 * j * j - 9.59 * j + 385.52, 2, ST7735_RED);
    j += 3;
    if (j > 100) {
      q = 0;
    }
  }

  static int r = 0;
  if (j == 103 && x > 65 && x <= 100) {
    r = 1;
  }
  if ((j==103)&&(x<65)){
    gameover(u);
    w=10;
  }
  if(r == 1) {
      TFTscreen.fillRect(10, 0, 125, 135, ST7735_BLACK);
    TFTscreen.drawCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_WHITE);
    TFTscreen.fillCircle(j, 0.08 * j * j - 21.43 * j + 1410 + 60, 2, ST7735_RED);
    j += 3;
    if (j > 135) {
      r = 0;
      w = 0;
      j = 7;
    }
  }

  return w;
}

void gameover(int s){
   TFTscreen.background(0,0,0);
  TFTscreen.fillScreen(ST7735_BLACK);
  TFTscreen.setCursor(25, 50); // Set cursor position for "GAME OVER"
  TFTscreen.setTextColor(ST7735_WHITE);
  TFTscreen.setTextSize(2);
  TFTscreen.print("Oh No!");

  TFTscreen.setCursor(25, 70); // Set cursor position for "Score : <score>"
  TFTscreen.setTextSize(1);
  TFTscreen.print("Your Score : ");
  TFTscreen.print(s);
}
