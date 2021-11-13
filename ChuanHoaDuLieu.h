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
    	res[++a]=thapphan +48;
    	res[++a]='\0';
	}
	else{
		res[a]='\0';
	}
	
	return res; 
}

void Nhap(int x,int y,int kieuChuanHoa, char c, char *s, int n){

	if(kieuChuanHoa == NUMBER)
	{
		if((isNum(c)  || c == '.') && strlen(s)<n){
				strncat(s, &c , 1);
		}
	}
	else 
		if(kieuChuanHoa== INHOA_VIETLIEN)       
		{
			if((isNum(c) || isLetter(c)) && strlen(s)<n && c != ' '){
					c = toupper(c);
					strncat(s, &c , 1);
				
			}
		}

 	outtextxy(x,y,s);	
}

