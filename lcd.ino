void bl_pwm(int16_t bfb){   //bfb（百分比）为(0,100)
    int16_t t=int(255*bfb/100);
    analogWrite(LCD_BL,t);
}


void tft_setup(){
  setup_buttons();
  tft.initR(INITR_MINI160x80); 
  tft.setRotation(2);
  pinMode(LCD_BL,OUTPUT);
  bl_pwm(LCD_LD);
  tft.fillScreen(ST7735_BLACK);  
}
