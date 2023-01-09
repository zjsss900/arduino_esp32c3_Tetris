
void csh_p(){
  int16_t a,b;
  for(a=0;a<LCD_W;a++){
    for(b=0;b<LCD_H;b++){
      n_frame[a][b]=0;
      f_frame[a][b]=0; 
    }
  }
}


bool compare_nf(int16_t x,int16_t y){
  if(f_frame[x][y]!=n_frame[x][y]){
    return 1;
  }else{
    return 0;
  }
}

void write_changed_to_tft(){
  int16_t a=0,ax=0,ay=0;
  for(ax=0;ax<LCD_W;ax++){
    for(ay=0;ay<LCD_H;ay++){
      if(compare_nf(ax,ay)==1){
        tft.drawPixel(ax,ay,f_frame[ax][ay]);
        n_frame[ax][ay]=f_frame[ax][ay];
      }
    }
  }
}
