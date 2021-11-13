#include <winbgim.h>
#include <iostream>  
#include <iomanip>
#include "Color.h"
#include "Define.h"
#include "XuLy.h"
#include "TienTrinh.h"
#include "DoHoa.h"

void thuatToanFIFO(DSTienTrinh &dstt) {
	
    DSTienTrinh RL ;
    int min_idx = -1;
    for (int i  = 0; i < dstt.soluong; i++){
    	
	    min_idx = i;
	    for (int j = i+1; j < dstt.soluong; j++)
	        if (dstt.data[j]->timeDenRL < dstt.data[min_idx]->timeDenRL)
	       		 min_idx = j;
	       		 
		themTtVaoDS(RL, *dstt.data[min_idx]);  		 
		swap(dstt.data[i], dstt.data[min_idx]);
	}
	
	float timeRun = 0;
	for (int i = 0; i < RL.soluong; i++) {
		if (timeRun <= RL.data[i]->timeDenRL) {
			timeRun =RL.data[i]->timeDenRL + RL.data[i]->timeXuLy;
			RL.data[i]->timeIn =RL.data[i]->timeDenRL;
			} 
	    else {
			timeRun += RL.data[i]->timeXuLy;
			RL.data[i]->timeIn = RL.data[i-1]->timeOut;
		}
		
		RL.data[i]->timeOut = timeRun;
		RL.data[i]->timeWait = RL.data[i]->timeOut - (RL.data[i]->timeDenRL + RL.data[i]->timeXuLy);	

	}
	dstt = RL;
}


float tinhThoiGianChoTB(DSTienTrinh &dstt){
			
	float sumTimeWait = 0  ;
	
    for (int i = 0;i < dstt.soluong; i++){
	  sumTimeWait += dstt.data[i]->timeWait;
	
	}
	return sumTimeWait/dstt.soluong;
}

void bangThoiGiandoi(DSTienTrinh &dstt){
		
		setfillstyle(1, MAU_KHUNG);
		setbkcolor(MAU_KHUNG);
	    bar(700,430,1010,460+dstt.soluong*30);	
	    rectangle(700,430,1010,460+dstt.soluong*30);
	    line(700,460,1010,460);
		line(860,430,860,460);
	    outtextxy(780-textwidth("Tien Trinh")/2,435,"Tien Trinh");
		outtextxy(935-textwidth("Thoi Gian Doi")/2,435,"Thoi Gian Doi");
		
 		for( int i = 0; i < dstt.soluong; i++){
			line(700,490+i*30,1010,490+i*30);
			line(860,460+i*30,860,490+i*30);
			outtextxy(780-textwidth( dstt.data[i]->name)/2,465+i*30,dstt.data[i]->name);
			outtextxy(935-textwidth(ftoa(dstt.data[i]->timeWait))/2,465+i*30,ftoa(dstt.data[i]->timeWait));
			
		}
}

void Demo(DSTienTrinh &dstt){
   
    float timeout = dstt.data[dstt.soluong-1]->timeOut;
	int k = 0;
	int loadding = 20;
	int in = 20;
	int f = 600/timeout;
	
	setcolor(WHITE);
	setbkcolor(MAU_BG);
	rectangle(20,548,f*timeout+20,600);
	
	outtextxy(20,530,"0");
	
	
	for(int j = 0; j < dstt.soluong; j++){
		
		in= dstt.data[j] -> timeIn*f+20;
		setbkcolor(MAU_BG);
		setcolor(WHITE);	
		outtextxy(in,530,ftoa(dstt.data[j]->timeIn));
		
		loadding = in;
		setfillstyle(1,++k);
		for(int i = 0; i < dstt.data[j]->timeXuLy; i++){
		
			if(dstt.data[j]->timeXuLy-i >= 1){
				delay(1000);
				bar(in,550,loadding+f,600);
				setbkcolor(k);
				setcolor(BLACK);
				outtextxy(in+(loadding+f-in)/2-textwidth(dstt.data[j]->name)/2,570,dstt.data[j]->name);
				loadding = loadding+f;
				}
			else {
				delay(1000);
				bar(in, 550, loadding+f*(dstt.data[j]->timeXuLy-i), 600);	
				outtextxy(in+(f*dstt.data[j]->timeXuLy)/2-textwidth(dstt.data[j]->name)/2,570,dstt.data[j]->name);
				loadding = loadding+f*(dstt.data[j]->timeXuLy-i);
			
			}
	 	}
	}
	setbkcolor(MAU_BG);
	setcolor(WHITE);
	outtextxy(f*timeout+20,530,ftoa(dstt.data[dstt.soluong-1]->timeOut));	
}

void output_FIFO(DSTienTrinh &dstt) {
	cout<<endl<<"========================Thuat Toan FIFO - [First In First Out]========================"<<endl<<endl;
	cout << setw(5)<< "Name" << setw(15) << "timeDenRL" << setw(15)
				 << "timeXuLy" << setw(15) << "timeIn" << setw(15) 
				 << "TimeOut"<< setw(15) << "Timewait"  << endl;
	for (int i = 0; i < dstt.soluong; i++)
	   cout << setw(5)<< dstt.data[i]->name << setw(15) 
			<< dstt.data[i]->timeDenRL << setw(15)
			<< dstt.data[i]->timeXuLy  << setw(15)
			<< dstt.data[i]->timeIn << setw(15) 
			<< dstt.data[i]->timeOut << setw(15)
			<< dstt.data[i]->timeWait << endl;
}

int main(int argc, char *argv[]){
	
	
    unsigned short int **mapID = new unsigned short int *[WD_HEIGHT];
    
	for(int i = 0; i <= WD_HEIGHT; i++)
	 	mapID[i]= new unsigned short int[WD_WIDTH];
	 	
	setID(0,0,0,WD_WIDTH,WD_HEIGHT,mapID); 	
	
	initwindow(WD_WIDTH,WD_HEIGHT);	
	setwindowtitle("DEMO_FIFO");							
   	cleardevice();
	setfillstyle(1,MAU_BG);	
	bar(0,0,WD_WIDTH,WD_HEIGHT);		
	setusercharsize(1, 2, 1, 2);

	
	veKhungNhapXuat(mapID);
  	veKhungDS(mapID);
  	
  	Button(ID_RESET,80,340,250,400,mapID,BLUE,BLACK,LIGHTRED,"RESET");
    Button(ID_SUBMIT,280,340,450,400,mapID,BLUE,BLACK,GREEN,"SUBMIT");
    Button(ID_ABOUT,1030,745,1070,785,mapID,BLACK,WHITE,DARKGRAY,"!");
    
    
    int x,y; 	
	int id = 0;
	bool kt = false;
	char charRL[100] = "";
	char charCPU[100] = "";
	char charWaitTB[100] = "";
	
	
	DSTienTrinh dstt;
    TienTrinh tt;
    resetTienTrinh(tt); 
    char chargarbage ;
	while(true){
		
		delay(100);
		id = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		 }
		
place:	switch(id){
	
			case ID_NAME:
				Input(225,80, NAME,tt.name,MAXLENGHT_TIME,id,mapID,kt);
			
				if(kt == true) goto place;
				
			case ID_TIMERL:
				Input(225,130,NUMBER,charRL,MAXLENGHT_TIME,id,mapID,kt);
				tt.timeDenRL = atof(charRL);
				if(kt == true) goto place;
				
			case ID_TIMECPU:
				Input(225,180,NUMBER,charCPU,MAXLENGHT_TIME,id,mapID,kt);
				tt.timeXuLy = atof(charCPU);
				if(kt == true) goto place;
			
			case ID_ADD:
				if(   isDSFull(dstt) ){
					
						MessageBox(NULL,"DS Tien Trinh Da FULL! \n" ,"THONG BAO",MB_ICONWARNING|MB_OK);
				}
				else 
					if( isProcessValid (tt)){
						themTtVaoDS(dstt,tt);
					   
						EditText(ID_NAME,220,75,380,105, mapID, BLUE, WHITE);
						EditText(ID_TIMERL,220,125,380,155, mapID, BLUE, WHITE);
						EditText(ID_TIMECPU,220,175,380,205, mapID, BLUE, WHITE);
						setcolor(BLACK);
						line(560,80+dstt.soluong*30,1010,80+dstt.soluong*30);
						line(710,50+dstt.soluong*30,710,80+dstt.soluong*30);
						line(860,50+dstt.soluong*30,860,80+dstt.soluong*30);
						
						setbkcolor(MAU_KHUNG);
						outtextxy(635-textwidth(tt.name)/2,80+(dstt.soluong-1)*30+10,tt.name);
						outtextxy(785-textwidth(charRL)/2,80+(dstt.soluong-1)*30+10,charRL );
						outtextxy(935-textwidth(charCPU)/2,80+(dstt.soluong-1)*30+10,charCPU);
						
						resetTienTrinh(tt);
						charRL[0] = '\0';
						charCPU[0] = '\0';
					}
				break;
				
			case ID_SUBMIT:
				
				setfillstyle(1,MAU_BG);	
				bar(0,460,WD_WIDTH,WD_HEIGHT);	
			    if( isDSEmpty(dstt) == true){
					 MessageBox(NULL,"Chua co Tien Trinh Nao Trong DS! \n"
					                 "  Vui long nhap va thu lai!","THONG BAO",MB_ICONWARNING|MB_OK);
				}
				else{
					
					thuatToanFIFO(dstt);
					output_FIFO(dstt);
			       	bangThoiGiandoi(dstt);
			    	Demo(dstt);    
			    	
				    Lable(80,700,320,750,BLUE,BLACK,GRAY,"Thoi Gian Cho Trung Binh");
				    sprintf(charWaitTB,"%.2f(s)", tinhThoiGianChoTB(dstt));
				    Lable(320,700,400,750, BLUE, BLACK, DARKGRAY, charWaitTB);
				    charWaitTB[0] = '\0';
				}
					break;
					
			case ID_ABOUT:
				setfillstyle(1,MAU_KHUNG);
				bar(800,655,1030,765);
				
				Lable(880,640,950,665,MAU_KHUNG,BLACK,GRAY,"About");
				setbkcolor(MAU_KHUNG);
				setcolor(BLACK);
				outtextxy(810,670,"Ho Va Ten: Le Phuong Anh");
				outtextxy(810,700,"MSSV: N19DCCN006");
				outtextxy(810,730,"Lop: D19CQCN03-N");
				delay(2000);
				setfillstyle(1,MAU_BG);
				bar(800,640,1030,765);
				break;	
					
			case ID_RESET:
			
				resetMH(mapID);
				delete_ds(dstt);
				system("cls");
				resetTienTrinh(tt);
				charRL[0] = '\0';
				charCPU[0] = '\0';
				break;
			default:
				 if (kbhit()){    
					chargarbage = getch();
					break;
				}	
			}
		
	}
	
	while(!kbhit()) delay(1);	
	return 0;
}
