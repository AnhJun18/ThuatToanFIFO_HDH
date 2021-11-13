#pragma once
#include "Define.h"

struct TienTrinh{
	char name[10];
	float TG_den_RL, TG_XuLy;
    float timeIN, timeOUT;
	float timewait; 
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
			tt.TG_den_RL = 0;
			tt.TG_XuLy = 0;	
			tt.timeIN = 0;
			tt.timeOUT = 0;
			tt.timewait = 0;
	
}

bool checktt(TienTrinh &tt){
	
	if(strlen(tt.name) == 0)  {
	    MessageBox(NULL,"Ten Tien Trinh Khong Duoc De Trong","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false;
	}
	if(tt.TG_XuLy == 0) {
		 MessageBox(NULL,"Thoi Gian Su Dung CPU Khong Duoc De Trong","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false;
	}
	return true;
}
void delete_ds(DSTienTrinh &dstt){
	for(int i=0;i<MAXTIENTRINH;i++){
		if(dstt.data[i] == NULL)
	      return;
		delete dstt.data[i];
	}
}
