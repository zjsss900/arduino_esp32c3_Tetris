
/*
  本程序使用合宙esp32c3开发板及合宙80*160tft模块进行开发，
理论上修改相应针脚后应该也可以运行于ESP32系列的板子上。
本版本还有一些BUG未修改，但不影响继续游戏。
                                  方布块
                              2022年8月25日

*/


#include <Adafruit_ST7735.h> 

//**********************************

#define LCD_BUTTON_UP         5       //定义按钮针脚
#define LCD_BUTTON_L         13
#define LCD_BUTTON_R          8
#define LCD_BUTTON_CENTER     4
#define LCD_BUTTON_DOWN       9
#define LCD_W                80       //定义屏幕宽高像素
#define LCD_H               160
//***********************************

#define LCD_BL               11       //定义LCD的针脚
#define LCD_CS                7
#define LCD_DC                6
#define LCD_RES              10
#define LCD_SDA               3
#define LCD_SCLK              2 
#define LCD_LD               30       //背光亮度百分比0-100%
//***********************************

#define blockup                1        // 按钮返回值定义
#define blockdown              2        //
#define blocklift              4        //
#define blockright             3        //
#define blockc                 5        //

//**********Tetris********************

#define blockxy                6        //设置方块长宽为6个像素
#define changdi_w             10        //设置游戏场地10个方块宽
#define changdi_h             20        //设置游戏场地20个方块高
#define next_blockx           12        //设置展示下一个方块的X位置
#define next_blocky           15        //设置展示下一个方块的Y位置
#define def_n_x                1        //去掉方框后，游戏场地的起始X坐标
#define def_n_y               39        //去掉方框后，游戏场地的起始X坐标
#define lv2                 1000        //定义等级2所需分数，方块下落每步移动2像素
#define lv3                10000        //定义等级3所需分数，方块下落每步移动3像素

int16_t changd[changdi_w][changdi_h];       //记录场地中每一个方块位置是否被占用（游戏场地坐标）
int16_t next_block[3]={0,0,0};        //记录下一个方块的类型和状态
int16_t now_block[3]={0,0,0};       //记录当前方块的类型和状态
int fs=0;                               //用于记录总分数
int realx=blockxy*4+1,realy=def_n_y-blockxy;        //当前方块的初始XY真实坐标
long t1=0,t2=0,t3=0;        //millis()函数比对，定时运行。
int16_t zuobiao[4][2]={0,0,0,0,0,0,0,0};        //当前方块中4个小方块的真实坐标
int8_t steps=0,level=1;       //steps记录游戏运行步骤

void a_block(int16_t x,int16_t y,int16_t color,bool nn);        //绘制单个小方块
void a_l(int16_t x,int16_t y,int16_t color,int8_t state,bool nn);       //绘制竖条方块
void a_o(int16_t x,int16_t y,int16_t color,bool nn);        //绘制田型方块
void a_z(int16_t x,int16_t y,int16_t color,int8_t state,bool nn);         //绘制Z方块
void a_s(int16_t x,int16_t y,int16_t color,int8_t state,bool nn);         //绘制S方块
void a_t(int16_t x,int16_t y,int16_t color,int8_t state,bool nn);         //绘制T方块
void a_ll(int16_t x,int16_t y,int16_t color,int8_t state,bool nn);        //绘制左向L方块
void a_rl(int16_t x,int16_t y,int16_t color,int8_t state,bool nn);        //绘制L方块
void fangkuang();       //游戏开始时绘制场地方框
void add_scoretext(int add);        //根据add值添加分数至屏幕
void scoretext();       //初始化分数栏score:000000
bool check_a_line(int8_t line);       //检测场地里的line行是否占满方块
void dispel_movedown(int8_t line);    //消除被占满的行，写入屏幕，并增加分数
void r_next_block();        //随机生成下一个方块
void draw_block_color(int16_t x,int16_t y,bool nn);       //根据坐标绘制相应色彩的方块，nn区分当前或下一个方块
void draw_block_black(int16_t x,int16_t y,bool nn);       //根据坐标绘制黑色方块用于擦除方块运动痕迹
void set_nowblock();        //读取下一个方块信息至当前方块
void csh_changdi();         //初始化游戏场地素组，
int8_t block_check(int8_t i);       //检测方块是否碰到边界或其他方块
void fall_speed_up();       //当下键按下时，增加方块下落速度
void block_state(int8_t allstate);        //记录方块每一个方向状态
void change_state();        //当上键按下时，改变当前方块的方向状态
void move_block_rl(bool i);       //方块左右移动       
void block_fall();        //控制当前方块下落
void kongzhi();       //按钮控制检测，如果不按下则方块下落
void start_game();        //游戏初始化
void draw_level(int8_t i);        //绘制等级        
void display_game_over();         //绘制游戏结束时GAME OVER
void check_level_change();        //检测是否达到难度等级相应分数，达到则升级难度

//*****frame********************

int16_t n_frame[LCD_W][LCD_H];        //当前帧。用此数组储存屏幕当前显示的每一个像素的颜色
int16_t f_frame[LCD_W][LCD_H];        //叫下一帧或者叫未来帧，用此数组储存屏幕即将要显示的每个像素的颜色

void csh_p();       //初始化两个帧数组
bool compare_nf(int16_t x,int16_t y);       //比较当前帧和未来帧每个对应像素的颜色是否有变化，有变化就返回1,无就返回0
void write_changed_to_tft();        //将未来帧中有变化的像素颜色写入当前帧数组中，并发送给屏幕。

//*******keys*******************

void setup_buttons();       //设置方向按钮的pin脚为输出并上拉
unsigned int down_up();       //检测按钮是否被按下，并返回相应的数值

//*********lcd***********************

void bl_pwm(int16_t bfb);        //bfb（百分比）,背光亮度调节
void tft_setup();       //屏幕初始化

//*******************************

Adafruit_ST7735 tft = Adafruit_ST7735(LCD_CS,LCD_DC,LCD_SDA,LCD_SCLK,LCD_RES);  
void(* resetFunc) (void) = 0;         //开发板重启，用于重新开始游戏

//***********************************



//***********************************

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  tft_setup(); 
  start_game();

}

void loop() {
  // put your main code here, to run repeatedly:
  int a=0,b=0;
  if(steps==0){
    set_nowblock();
    r_next_block();
    steps=1;
  }
  if(steps==1){
    kongzhi();    
  }
  if(steps==2){
    for(b=0;b<4;b++){
      dispel_movedown((zuobiao[b][1]-def_n_y)/blockxy);  
    }
    steps=0;  
  }
  if(steps==3){
    display_game_over();
    steps=4;
  }
  if(steps==4){
    if(millis()>=t3+180){
    a=down_up();
    t3=millis();
    }
    if(a==blockc){
      resetFunc();
    }
  }
}
  
