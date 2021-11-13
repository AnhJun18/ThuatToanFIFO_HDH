
void setID(int id,int x1,int y1, int x2,int y2,unsigned short int ** mapID){
	
	for(int i = y1 ; i <= y2 ; i++)
		for(int j = x1; j <= x2; j++)
			mapID[i][j] = id ;
		
}

void Button(int id, int x1, int y1, int x2, int y2, unsigned short int **mapID, int mauVien, int mauText , int mauBG , char *text){
	
		setcolor(mauVien);
		setfillstyle(1, mauBG);
		bar(x1, y1, x2, y2);
		rectangle(x1, y1, x2, y2);
		
		setcolor(mauText);
		setbkcolor(mauBG);
		outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);
		
		setID(id,x1,y1,x2,y2,mapID);
	
}
void EditText(int id, int x1, int y1, int x2, int y2, unsigned short int **mapID, int mauVien, int mauBG){
	
		setcolor(mauVien);
		setfillstyle(1, mauBG);
		bar(x1, y1, x2, y2);
		rectangle(x1, y1, x2, y2);
		setID(id, x1, y1, x2, y2, mapID);
	
}

void Lable(int x1, int y1, int x2, int y2, int mauVien,int mauText, int mauBG, char* text){
	
		setcolor(mauVien);
		setfillstyle(1, mauBG);
		bar(x1, y1, x2, y2);
		rectangle(x1, y1, x2, y2);
		setcolor(mauText);
		setbkcolor(mauBG);
		outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);	
}

void resetMH(unsigned short int **mapID){
	
		setfillstyle(1,MAU_KHUNG);
		bar(560,80,1010,380);
		rectangle(560,80,1010,380);
		EditText(ID_NAME,220,75,380,105,mapID,BLUE,WHITE);
		EditText(ID_TIMERL,220,125,380,155,mapID,BLUE,WHITE);
		EditText(ID_TIMECPU,220,175,380,205,mapID,BLUE,WHITE);
		setfillstyle(1,MAU_BG);	
		bar(0,410,WD_WIDTH,WD_HEIGHT);		
    
}

void veKhungNhapXuat( unsigned short int **mapID){
	
	setfillstyle(1, MAU_KHUNG);
	bar(80, 20, 450, 300);	
    settextstyle(8, 0, 0);
	Lable(160, 10, 370, 40, 0, 0, 9, "Nhap Tien Trinh");
	
	setcolor(0);
	setbkcolor(MAU_KHUNG);
    outtextxy(100, 80,"TenTienTrinh");
    outtextxy(100, 130,"ThoiDiemVaoRL");
    outtextxy(100, 180,"ThoiGianXuLy");
    EditText(ID_NAME , 220, 75, 380, 105, mapID, BLUE, WHITE);
    EditText(ID_TIMERL, 220, 125, 380, 155, mapID, BLUE, WHITE);
    EditText(ID_TIMECPU, 220, 175, 380, 205, mapID, BLUE, WHITE);
    Button(ID_ADD, 220, 240, 310, 280, mapID, BLUE, BLACK, GRAY, "THEM");
}

void veKhungDS(unsigned short int **mapID){
	
	setfillstyle(1, MAU_KHUNG);
    bar (560, 20, 1010, 400);
    rectangle(560, 50, 1010, 380);
    line(560, 80, 1010, 80);
	line(710, 50, 710, 80);
	line(860, 50, 860, 80);
    Lable(670, 10, 900, 40,BLACK,BLACK,LIGHTBLUE,"Danh Sach Tien Trinh");
	setbkcolor(MAU_KHUNG);
	outtextxy(635-textwidth("Ten Tien Trinh")/2, 55,"Ten Tien Trinh");
	outtextxy(785-textwidth("Thoi Gian Vao RL")/2, 55,"Thoi Gian Vao RL");
	outtextxy(935-textwidth("Thoi Gian Xu Ly")/2, 55,"Thoi Gian Xu Ly");
}
