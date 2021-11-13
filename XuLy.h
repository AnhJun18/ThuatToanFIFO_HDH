#include<conio.h>
#include<math.h>
#include<string.h>
using namespace std;
bool isLetter(char c){
	
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ))
		return 1;
		
	return 0;	 
}

bool isNum(char c){
	if(c >= '0' && c <= '9')
		return 1;
		
	return 0;	 
}


char* ftoa(float &n){

	char* res = new char[100];
    int nguyen = (int)n; 
    itoa(nguyen,res,10);
     int thapphan = (int)(n  *10) %10;
    
    int a=strlen(res);
    if(thapphan != 0){
    	res[a]='.';
    	res[++a] = thapphan +48;
    	res[++a] = '\0';
	}
	else{
		res[a] ='\0';
	}
	
	return res; 
}

void Input(int x, int y, int kieuNhapLieu, char s[], int n, int &id, unsigned short int **mapID, bool &kt){
	
	kt = 0;
	char c;
	int idtmp = id;
	int h,k;
	setbkcolor(WHITE);
	setcolor(BLACK);
	while(true){
	
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, h, k);
				idtmp = mapID[k][h];
				clearmouseclick(WM_LBUTTONDOWN);
	      	  }
	      	  
	      	if(id != idtmp) {
			 	kt = 1;
			  	id=idtmp;
			  	if(s[strlen(s)-1] == ' ')
			    	s[strlen(s)-1] = '\0';
			  	return ;
			  }
	      	
		    if (kbhit()){
				c = getch();
				if(c != 13){
						if(c == 8 && strlen(s) != 0)  {    // An Phim Backspace
							outtextxy(x+textwidth(s),y," ");
							s[strlen(s)-1] = '\0';	
						  }
					   else	{   // Nhan Phim Hop Le
					 		 	if(kieuNhapLieu == NUMBER){
									if((isNum(c)  || c == '.') && strlen(s)<n){
										strncat(s, &c , 1);
										}
									}
								else 
									if(kieuNhapLieu == NAME)  	{
											if((isNum(c) || isLetter(c)) && strlen(s)<n && c != ' '){
												c = toupper(c);
												strncat(s, &c , 1);
				
												}
											}

 								outtextxy(x,y,s);  				   
					   	}
					}
				else {    // Neu Nhan Phin Enter
						if(s[strlen(s)-1] == ' ')
		    				s[strlen(s)-1] = '\0';
						return ;
					}
				}
			else {        // neu ko co phim dc nhan thi xuat con tro
					outtextxy(x+textwidth(s),y,"|");
					outtextxy(x+textwidth(s),y," ");	
				}
	}	
}


