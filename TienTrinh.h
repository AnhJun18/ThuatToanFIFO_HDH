#pragma once
#include "Define.h"

struct TienTrinh{
	char name[10];
	float timeDenRL, timeXuLy;
    float timeIn, timeOut;
	float timeWait; 
};

struct DSTienTrinh{
	TienTrinh *data[MAXTIENTRINH];
	int soluong = 0;
};

TienTrinh *newTT(TienTrinh tienTrinh){

	TienTrinh *temp = new TienTrinh;
    *temp  = tienTrinh;
	return temp;
}

void themTtVaoDS(DSTienTrinh &dstt, TienTrinh &tt){
	dstt.data[dstt.soluong] = newTT(tt);
	dstt.soluong ++;
}

bool isDSEmpty(DSTienTrinh &dstt){
	
	return(dstt.soluong == 0 ? true : false);
}

bool isDSFull(DSTienTrinh &dstt){
	
	return(dstt.soluong  >= MAXTIENTRINH ? true : false);
}

void resetTienTrinh(TienTrinh &tt){
			tt.name[0] = '\0';	
			tt.timeDenRL = 0;
			tt.timeXuLy = 0;	
			tt.timeIn = 0;
			tt.timeOut = 0;
			tt.timeWait = 0;
	
}

bool isProcessValid(TienTrinh &tt){
	
	if(strlen(tt.name) == 0)  {
	    MessageBox(NULL,"Ten Tien Trinh Khong Duoc De Trong","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false;
	}
	if(tt.timeXuLy == 0) {
		 MessageBox(NULL,"Thoi Gian Su Dung CPU Khong Duoc De Trong","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false;
	}
	return true;
}
void delete_ds(DSTienTrinh &dstt){
	dstt.soluong = 0;	
}
