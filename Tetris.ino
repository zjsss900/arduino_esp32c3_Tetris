
void a_block(int16_t x,int16_t y,int16_t color,bool nn){
  int8_t ax,ay;
  for(ax=0;ax<blockxy;ax++){
    for(ay=0;ay<blockxy;ay++){
      if((nn==1 && y+ay<LCD_H-changdi_h*blockxy-1) || (nn==1 && y+ay>=LCD_H-1)){
          f_frame[x+ax][y+ay]=n_frame[x+ax][y+ay];
      }else{
        if((ax==1 && ay!=0 && ay!=blockxy-1)|| (ax==blockxy-2 && ay!=0 && ay!=blockxy-1) || (ay==1 && ax!=0 && ax!=blockxy-1) || (ay==blockxy-2 && ax!=0 && ax!=blockxy-1)){
          f_frame[x+ax][y+ay]=ST7735_BLACK;
        }else{
          f_frame[x+ax][y+ay]=color;
        }        
      }
    }
  }
}

void a_l(int16_t x,int16_t y,int16_t color,int8_t state,bool nn){
  int8_t a;
  if(state==0){
    for(a=0;a<4;a++){
      a_block(x+a*blockxy,y,color,nn);
      if(nn==1){
        zuobiao[a][0]=x+a*blockxy;
        zuobiao[a][1]=y;
      }
    }  
  }else if(state==1){
    for(a=0;a<4;a++){
      a_block(x,y+a*blockxy,color,nn);
      if(nn==1){
        zuobiao[a][0]=x;
        zuobiao[a][1]=y+a*blockxy;
      }      
    }      
  }
}

void a_o(int16_t x,int16_t y,int16_t color,bool nn){
  int8_t ax,ay,a=0;
  for(ax=0;ax<2;ax++){
    for(ay=0;ay<2;ay++){
      a_block(x+ax*blockxy,y+ay*blockxy,color,nn);
      if(nn==1){
        zuobiao[a][0]=x+ax*blockxy;
        zuobiao[a][1]=y+ay*blockxy;
        a++;
      }
    }
  }
}

void a_z(int16_t x,int16_t y,int16_t color,int8_t state,bool nn){
  if(state==0){
    a_block(x,y,color,nn);
    a_block(x+blockxy,y,color,nn);
    a_block(x+blockxy,y+blockxy,color,nn);
    a_block(x+blockxy*2,y+blockxy,color,nn);
    if(nn==1){
      zuobiao[0][0]=x;
      zuobiao[0][1]=y;
      zuobiao[1][0]=x+blockxy;
      zuobiao[1][1]=y;
      zuobiao[2][0]=x+blockxy;
      zuobiao[2][1]=y+blockxy;
      zuobiao[3][0]=x+blockxy*2;
      zuobiao[3][1]=y+blockxy;
    }
  }else if(state==1){
    a_block(x+blockxy,y,color,nn);
    a_block(x,y+blockxy,color,nn);
    a_block(x+blockxy,y+blockxy,color,nn);
    a_block(x,y+blockxy*2,color,nn); 
    if(nn==1){
      zuobiao[0][0]=x+blockxy;
      zuobiao[0][1]=y;
      zuobiao[1][0]=x;
      zuobiao[1][1]=y+blockxy;
      zuobiao[2][0]=x+blockxy;
      zuobiao[2][1]=y+blockxy;
      zuobiao[3][0]=x;
      zuobiao[3][1]=y+blockxy*2;
    }       
  }
}

void a_s(int16_t x,int16_t y,int16_t color,int8_t state,bool nn){
    if(state==0){
    a_block(x+blockxy,y,color,nn);
    a_block(x+blockxy*2,y,color,nn);
    a_block(x,y+blockxy,color,nn);
    a_block(x+blockxy,y+blockxy,color,nn);
    if(nn==1){
      zuobiao[0][0]=x+blockxy;
      zuobiao[0][1]=y;
      zuobiao[1][0]=x+blockxy*2;
      zuobiao[1][1]=y;
      zuobiao[2][0]=x;
      zuobiao[2][1]=y+blockxy;
      zuobiao[3][0]=x+blockxy;
      zuobiao[3][1]=y+blockxy;
    }
  }else if(state==1){
    a_block(x,y,color,nn);
    a_block(x,y+blockxy,color,nn);
    a_block(x+blockxy,y+blockxy,color,nn);
    a_block(x+blockxy,y+blockxy*2,color,nn);
    if(nn==1){
      zuobiao[0][0]=x;
      zuobiao[0][1]=y;
      zuobiao[1][0]=x;
      zuobiao[1][1]=y+blockxy;
      zuobiao[2][0]=x+blockxy;
      zuobiao[2][1]=y+blockxy;
      zuobiao[3][0]=x+blockxy;
      zuobiao[3][1]=y+blockxy*2;
    }        
  }
}

void a_t(int16_t x,int16_t y,int16_t color,int8_t state,bool nn){
  int a;
  switch(state){
    case 0:{
      for(a=0;a<3;a++){
        a_block(x+blockxy*a,y+blockxy,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy*a;
          zuobiao[a][1]=y+blockxy;
        }
      }
      a_block(x+blockxy,y,color,nn);
      if(nn==1){
        zuobiao[3][0]=x+blockxy;
        zuobiao[3][1]=y;
      }      
      break;
    }
    case 2:{
      for(a=0;a<3;a++){
        a_block(x+blockxy*a,y+blockxy,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy*a;
          zuobiao[a][1]=y+blockxy;
        }        
      }      
      a_block(x+blockxy,y+2*blockxy,color,nn);
      if(nn==1){
        zuobiao[3][0]=x+blockxy;
        zuobiao[3][1]=y+2*blockxy;
      }     
      break;
    }
    case 1:{
      for(a=0;a<3;a++){
        a_block(x+blockxy,y+blockxy*a,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy;
          zuobiao[a][1]=y+blockxy*a;
        }           
      }      
      a_block(x+2*blockxy,y+blockxy,color,nn);    
      if(nn==1){
        zuobiao[3][0]=x+2*blockxy;
        zuobiao[3][1]=y+blockxy;
      }             
      break;
    }
    case 3:{
      for(a=0;a<3;a++){
        a_block(x+blockxy,y+blockxy*a,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy;
          zuobiao[a][1]=y+blockxy*a;
        }        
      }      
      a_block(x,y+blockxy,color,nn);  
      if(nn==1){
        zuobiao[3][0]=x;
        zuobiao[3][1]=y+blockxy;
      }              
      break;
    }
  }
}

void a_ll(int16_t x,int16_t y,int16_t color,int8_t state,bool nn){
  int a;
  switch(state){
    case 0:{
      for(a=0;a<3;a++){
        a_block(x+blockxy*a,y,color,nn);  
        if(nn==1){
          zuobiao[a][0]=x+blockxy*a;
          zuobiao[a][1]=y;
        }             
      }
      a_block(x+blockxy*2,y+blockxy,color,nn);
      if(nn==1){
        zuobiao[3][0]=x+blockxy*2;
        zuobiao[3][1]=y+blockxy;
      }           
      break;
    }
    case 3:{
      for(a=0;a<3;a++){
        a_block(x,y+blockxy*a,color,nn);
        if(nn==1){
          zuobiao[a][0]=x;
          zuobiao[a][1]=y+blockxy*a;
        }           
      }
      a_block(x+blockxy,y,color,nn);
      if(nn==1){
        zuobiao[3][0]=x+blockxy;
        zuobiao[3][1]=y;
      }            
      break;
    }
    case 2:{
      for(a=0;a<3;a++){
        a_block(x+blockxy*a,y+blockxy,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy*a;
          zuobiao[a][1]=y+blockxy;
        }       
      }
      a_block(x,y,color,nn);   
      if(nn==1){
        zuobiao[3][0]=x;
        zuobiao[3][1]=y;
      }        
      break;         
    }
    case 1:{
      for(a=0;a<3;a++){
        a_block(x+blockxy,y+blockxy*a,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy;
          zuobiao[a][1]=y+blockxy*a;
        }         
      }
      a_block(x,y+blockxy*2,color,nn);   
      if(nn==1){
        zuobiao[3][0]=x;
        zuobiao[3][1]=y+blockxy*2;
      }       
      break;                 
    }
  }
}

void a_rl(int16_t x,int16_t y,int16_t color,int8_t state,bool nn){
  int a;
  switch(state){
    case 0:{
      for(a=0;a<3;a++){
        a_block(x+blockxy*a,y,color,nn); 
        if(nn==1){
          zuobiao[a][0]=x+blockxy*a;
          zuobiao[a][1]=y;
        }             
      }
      a_block(x,y+blockxy,color,nn);
      if(nn==1){
        zuobiao[3][0]=x;
        zuobiao[3][1]=y+blockxy;
      }         
      break;
    }
    case 1:{
      for(a=0;a<3;a++){
        a_block(x+blockxy,y+blockxy*a,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy;
          zuobiao[a][1]=y+blockxy*a;
        }         
      }
      a_block(x,y,color,nn);
      if(nn==1){
        zuobiao[3][0]=x;
        zuobiao[3][1]=y;
      }   
      break;
    }
    case 2:{
      for(a=0;a<3;a++){
        a_block(x+blockxy*a,y+blockxy,color,nn);
        if(nn==1){
          zuobiao[a][0]=x+blockxy*a;
          zuobiao[a][1]=y+blockxy;
        }          
      }
      a_block(x+2*blockxy,y,color,nn);
      if(nn==1){
        zuobiao[3][0]=x+2*blockxy;
        zuobiao[3][1]=y;
      }         
      break;         
    }
    case 3:{
      for(a=0;a<3;a++){
        a_block(x,y+blockxy*a,color,nn);
        if(nn==1){
          zuobiao[a][0]=x;
          zuobiao[a][1]=y+blockxy*a;
        }        
      }
      a_block(x+blockxy,y+blockxy*2,color,nn);   
      if(nn==1){
        zuobiao[3][0]=x+blockxy;
        zuobiao[3][1]=y+blockxy*2;
      }       
      break;                 
    }    
  }
}

void scoretext(){
  char a[12]={'S','C','O','R','E',':','0','0','0','0','0','0'};
  int b;
  for(b=0;b<6;b++){
    tft.drawChar(b*6,0,a[b],ST7735_BLUE,ST7735_BLACK,1);
  }
  for(b=6;b<12;b++){
    tft.drawChar(b*6,0,a[b],ST7735_WHITE,ST7735_BLACK,1);
  } 
}

void add_scoretext(int add){
  char n[10]={'0','1','2','3','4','5','6','7','8','9'};
  int b,c[6]={0,0,0,0,0,0},r=0;
  if(add!=0){
    fs=fs+add;
    if(fs<=999999){
      r=fs;
    }else{
      fs=fs-999999;
      r=fs;
    }
   for(b=0;b<6;b++){
      if(r!=0){
        if(r>=10){
          c[5-b]=r%10;
          r=(r-r%10)/10;
        }else if(r<10){
          c[5-b]=r;
          r=0;
        }
      }else{
        c[5-b]=0;
      }
      tft.drawChar((6+5-b)*6,0,n[c[5-b]],ST7735_WHITE,ST7735_BLACK,1);  
    }
  }      
}

void fangkuang(){
  tft.drawRect(0,LCD_H-changdi_h*blockxy-2,changdi_w*blockxy+2,changdi_h*blockxy+2,ST7735_WHITE);
}

bool check_a_line(int8_t line){
  int8_t a=0;
  for(int8_t x=0;x<changdi_w;x++){
    if(changd[x][line]==1){
      a++;       
    }
  }
  if(a==changdi_w){
    return 1;
  }else{
    return 0;
  }
}

void dispel_movedown(int8_t line){
  int a=0,b=0,c=0,ax=0,ay=0;
  if(check_a_line(line)==1){
    for(a=0;a<changdi_w;a++){
      changd[a][line]=0;
      a_block(def_n_x+a*blockxy,def_n_y+line*blockxy,ST7735_BLACK,1);
    }
    write_changed_to_tft();
    delay(100);
    for(b=0;b<line-1;b++){
      for(a=0;a<changdi_w;a++){
        changd[a][line-b]=changd[a][line-b-1];
        for(ax=0;ax<blockxy;ax++){
          for(ay=0;ay<blockxy;ay++){
            f_frame[(def_n_x+a*blockxy)+ax][(def_n_y+(line-b)*blockxy)+ay]=n_frame[(def_n_x+a*blockxy)+ax][(def_n_y+(line-b-1)*blockxy)+ay];
          }
        }
      }
    }
    for(a=0;a<changdi_w;a++){
      changd[a][0]=0;
      a_block(def_n_x+a*blockxy,def_n_y,ST7735_BLACK,0);
    }
    write_changed_to_tft();
    delay(100);
    add_scoretext(10);
    check_level_change();
  }
}

void r_next_block(){
  next_block[0]=random(1,8);
  //next_block[0]=1;
  draw_block_color(10,15,0);
  write_changed_to_tft();
}

void draw_block_color(int16_t x,int16_t y,bool nn){
  int i;
  int16_t a[3]={0,0,0};
  if(nn==0){
    for(i=0;i<3;i++){
      a[i]=next_block[i];
    }
  }else if(nn==1){
    for(i=0;i<3;i++){
      a[i]=now_block[i];
    }
  }
  switch(a[0]){
    case 0: {
      break;
    }
    case 1:{
      a_l(x,y,ST7735_RED,a[2],nn);
      break;
    }
    case 2:{
      a_o(x,y,ST7735_YELLOW,nn);    
      break;
    }
    case 3:{
      a_z(x,y,ST7735_GREEN,a[2],nn);
      break;      
    }
    case 4:{
      a_s(x,y,0xFE1C,a[2],nn);
      break;      
    }
    case 5:{
      a_t(x,y,ST7735_ORANGE,a[2],nn);
      break;      
    }
    case 6:{
      a_ll(x,y,ST7735_MAGENTA,a[2],nn);
      break;      
    }
    case 7:{
      a_rl(x,y,ST7735_CYAN,a[2],nn);
      break;      
    }
  }
}

void draw_block_black(int16_t x,int16_t y,bool nn){
  int i;
  int16_t a[3]={0,0,0};
  if(nn==0){
    for(i=0;i<3;i++){
      a[i]=next_block[i];
    }
    
  }else if(nn==1){
    for(i=0;i<3;i++){
      a[i]=now_block[i];
    }
  }
  a[1]=ST7735_BLACK;
  switch(a[0]){
    case 0:{
      break;
    }
    case 1:{
      a_l(x,y,a[1],a[2],nn);
      break;
    }
    case 2:{
      a_o(x,y,a[1],nn);
      break;
    }
    case 3:{
      a_z(x,y,a[1],a[2],nn);
      break;      
    }
    case 4:{
      a_s(x,y,a[1],a[2],nn);
      break;      
    }
    case 5:{
      a_t(x,y,a[1],a[2],nn);
      break;      
    }
    case 6:{
      a_ll(x,y,a[1],a[2],nn);
      break;      
    }
    case 7:{
      a_rl(x,y,a[1],a[2],nn);
      break;      
    }
  }
}

void set_nowblock(){
    for(int i=0;i<3;i++){
      now_block[i]=next_block[i];
    }
    draw_block_black(10,15,0);
    write_changed_to_tft();
}

void csh_changdi(){
  for(int a=0;a<changdi_w;a++){
    for(int b=0;b<changdi_h;b++){
      changd[a][b]=0;
    }
  }
}

int8_t block_check(int8_t i){  //u1 d2 l3 r4
  int a[4][2],c=0,d=0;
  for(int b=0;b<4;b++){
    if((zuobiao[b][1]-def_n_y)%blockxy==0){
      a[b][0]=(zuobiao[b][0]-def_n_x)/blockxy;
      a[b][1]=(zuobiao[b][1]-def_n_y)/blockxy;
      c=3;
    }else if((zuobiao[b][1]-def_n_y)%blockxy!=0 && zuobiao[b][1]+blockxy<LCD_H-1){
      a[b][0]=(zuobiao[b][0]-def_n_x)/blockxy;
      a[b][1]=(zuobiao[b][1]-def_n_y-(zuobiao[b][1]-def_n_y)%blockxy)/blockxy;
      c=2;
    }
  }
  switch(i){
    case 1:{
      break;
    }
    case 2:{
      if(c==3){
        if((a[0][1]+1!=a[1][1] && a[0][1]+1!=a[2][1] && a[0][1]+1!=a[3][1]) || a[1][1]+1!=a[0][1] && a[1][1]+1!=a[2][1] && a[1][1]+1!=a[3][1] || (a[2][1]+1!=a[0][1] && a[2][1]+1!=a[1][1] && a[2][1]+1!=a[3][1]) || (a[3][1]+1!=a[0][1] && a[3][1]+1!=a[1][1] && a[3][1]+1!=a[2][1])){
          if((changd[a[0][0]][a[0][1]+1]==1 || a[0][1]+1==changdi_h) || (changd[a[1][0]][a[1][1]+1]==1 || a[1][1]+1==changdi_h) || (changd[a[2][0]][a[2][1]+1]==1 || a[2][1]+1==changdi_h) || (changd[a[3][0]][a[3][1]+1]==1 || a[3][1]+1==changdi_h)){
             d=2;        
          }       
        }
      }
      return d;
      break; 
    }
    case 3:{
      if(a[0][0]==0 || a[1][0]==0 || a[2][0]==0 || a[3][0]==0){
        d=3;      
      }else if((a[0][0]-1!=a[1][0] && a[0][0]-1!=a[2][0] && a[0][0]-1!=a[3][0]) || (a[1][0]-1!=a[0][0] && a[1][0]-1!=a[2][0] && a[1][0]-1!=a[3][0]) || (a[2][0]-1!=a[0][0] && a[2][0]-1!=a[1][0] && a[2][0]-1!=a[3][0]) || (a[3][0]-1!=a[0][0] && a[3][0]-1!=a[1][0] && a[3][0]-1!=a[2][0])){
        if(c==3){
          if(changd[a[0][0]-1][a[0][1]]==1 || changd[a[1][0]-1][a[1][1]]==1 || changd[a[2][0]-1][a[2][1]]==1 || changd[a[3][0]-1][a[3][1]]==1){
            d=3;                   
          }
        }else if(c==2){
          if((changd[a[0][0]-1][a[0][1]]==1 || changd[a[0][0]-1][a[0][1]+1]==1) || (changd[a[1][0]-1][a[1][1]]==1 || changd[a[1][0]-1][a[1][1]+1]==1) || (changd[a[2][0]-1][a[2][1]]==1 || changd[a[2][0]-1][a[2][1]+1]==1) || (changd[a[3][0]-1][a[3][1]]==1 || changd[a[3][0]-1][a[3][1]+1]==1)){
            d=3;           
          }
        }
      }
      return d;
      break; 
    }
    case 4:{
      if(a[0][0]==changdi_w-1 || a[1][0]==changdi_w-1 || a[2][0]==changdi_w-1 || a[3][0]==changdi_w-1){
        d=4;
      }else if((a[0][0]+1!=a[1][0] && a[0][0]+1!=a[2][0] && a[0][0]+1!=a[3][0]) || (a[1][0]+1!=a[0][0] && a[1][0]+1!=a[2][0] && a[1][0]+1!=a[3][0]) || (a[2][0]+1!=a[0][0] && a[2][0]+1!=a[1][0] && a[2][0]+1!=a[3][0]) || (a[3][0]+1!=a[0][0] && a[3][0]+1!=a[1][0] && a[3][0]+1!=a[2][0])){
        if(c==3){
          if(changd[a[0][0]+1][a[0][1]]==1 || changd[a[1][0]+1][a[1][1]]==1 || changd[a[2][0]+1][a[2][1]]==1 || changd[a[3][0]+1][a[3][1]]==1){
            d=4;                   
          }
        }else if(c==2){
          if((changd[a[0][0]+1][a[0][1]]==1 || changd[a[0][0]+1][a[0][1]+1]==1) || (changd[a[1][0]+1][a[1][1]]==1 || changd[a[1][0]+1][a[1][1]+1]==1) || (changd[a[2][0]+1][a[2][1]]==1 || changd[a[2][0]+1][a[2][1]+1]==1) || (changd[a[3][0]+1][a[3][1]]==1 || changd[a[3][0]+1][a[3][1]+1]==1)){
            d=4;           
          }
        }
      }
      return d;
      break;         
    }
    case 5:{
      if(c==3 || c==2){
        if((a[0][1]+2!=a[1][1] && a[0][1]+2!=a[2][1] && a[0][1]+2!=a[3][1]) || a[1][1]+2!=a[0][1] && a[1][1]+2!=a[2][1] && a[1][1]+2!=a[3][1] || (a[2][1]+2!=a[0][1] && a[2][1]+2!=a[1][1] && a[2][1]+2!=a[3][1]) || (a[3][1]+2!=a[0][1] && a[3][1]+2!=a[1][1] && a[3][1]+2!=a[2][1])){
          if((changd[a[0][0]][a[0][1]+2]==1 || a[0][1]+2==changdi_h) || (changd[a[1][0]][a[1][1]+2]==1 || a[1][1]+2==changdi_h) || (changd[a[2][0]][a[2][1]+2]==1 || a[2][1]+2==changdi_h) || (changd[a[3][0]][a[3][1]+2]==1 || a[3][1]+2==changdi_h)){
             d=5;        
          }       
        }
      }
      return d;
      break; 
    }
  }
}


void fall_speed_up(){
  if(realy-def_n_y>=0 && (realy-def_n_y)%blockxy==0 && block_check(5)!=5){
    realy+=blockxy;
  }else if(realy-def_n_y>=0 && (realy-def_n_y)%blockxy!=0 && block_check(5)!=5){
    realy+=(realy-def_n_y)%blockxy;
  }
}

void block_state(int8_t allstate){
  if(now_block[2]<allstate-1){
    now_block[2]=now_block[2]+1;
  }else if(now_block[2]==allstate-1){
    now_block[2]=0;
  }
}

void change_state(){
  switch(now_block[0]){
    case 0:{
      break;
    }
    case 1:{
      block_state(2);
      break;
    }
    case 2:{
      break;
    }
    case 3:{
      block_state(2);
      break;
    }
    case 4:{
      block_state(2);
      break;
    }
    case 5:{
      block_state(4);
      break;
    }
    case 6:{
      block_state(4);
      break;
    }
    case 7:{
      block_state(4);
      break;
    }
  }
}

void move_block_rl(bool i){
  int a,b;
  if(i==0){
    if(block_check(3)!=3 && block_check(2)!=2){
      realx=realx-blockxy;
    }
  }else if(i==1){
    if(block_check(4)!=4 && block_check(2)!=2){
      realx=realx+blockxy;
    }
  }
}


void block_fall(){
    draw_block_color(realx,realy,1);
    write_changed_to_tft();
    draw_block_black(realx,realy,1);
  if(block_check(2)!=2){    
    realy+=level;
  }else{
    for(int a=0;a<4;a++){
      if((zuobiao[a][1]-def_n_y)/blockxy>=0){
        changd[(zuobiao[a][0]-def_n_x)/blockxy][(zuobiao[a][1]-def_n_y)/blockxy]=1;
        steps=2;
      }else{
        steps=3;
      }
    }
    //s_test();  
    draw_block_color(realx,realy,1);
    write_changed_to_tft();
    realy=def_n_y-blockxy;
    realx=blockxy*4+1;    
  }
}

void kongzhi(){
 int a=0;
 if(millis()>=t2+80){
   block_fall();
   t2=millis();
 } 
  if(millis()>=t1+180){
    a=down_up();
    t1=millis();
  }
    switch(a){
      case 0:{  
        
        break;
      }
      case blockdown:{
        fall_speed_up();
        break;
      }
      case blockup:{
        change_state();
        break;
      }
      case blockright:{
        move_block_rl(1);
        break;
      }
      case blocklift:{
        move_block_rl(0);
        break;
      }
      case blockc:{
        resetFunc();
        break;        
      }
    }
}

void start_game(){
  fangkuang();
  draw_level(1);
  scoretext();
  csh_p();
  csh_changdi();
  randomSeed(666);
  r_next_block();
}

void draw_level(int8_t i){
  if(i==1){
    tft.setTextSize(2);
    tft.setTextWrap(false);
    tft.setTextColor(0xFFDF);
    tft.setCursor(55,15);
    tft.print("LV");
    tft.drawChar(65+4,40,'1',0xFFDF,ST7735_BLACK,2);
  }else{
    if(i==2){
      tft.drawChar(65+4,40,'2',0xFFDF,ST7735_BLACK,2);
    }else if(i==3){
      tft.drawChar(65+4,40,'3',0xFFDF,ST7735_BLACK,2);
    }
  }
}

void display_game_over(){
    tft.setTextSize(2);
    tft.setTextWrap(false);
    tft.setTextColor(0x6AD9);
    tft.setCursor(8+2,70+2);
    tft.print("GAME");
    tft.setTextColor(0x6AD9);
    tft.setCursor(8+2,90+2);
    tft.print("OVER");
    tft.setTextColor(ST7735_WHITE);
    tft.setCursor(8,70);
    tft.print("GAME");
    tft.setTextColor(ST7735_WHITE);
    tft.setCursor(8,90);
    tft.print("OVER");
}

void check_level_change(){
  if(fs>=lv2 && fs<lv3){
    level=2;
    draw_level(level);    
  }else if(fs>=lv3){
    level=3;
    draw_level(level);    
  }
}
