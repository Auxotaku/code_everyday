#include <stdio.h>
int ebx,ecx,esi,eax;
unsigned int edx;
void func4(int ecx,int ebx,int esi){
    eax = esi;
    eax -= ebx;
    edx = eax;
    edx = edx >> 31;
    eax += edx;
    eax /= 2;
    edx = eax + ebx*1;
    if(edx > ecx){
        edx -= 1;
        func4(ecx,ebx,edx);
        eax = eax*2;
    }
    eax = 0;
    if(edx < ecx){
        edx += 1;
        func4(ecx,edx,esi);
        eax = eax+eax+1;
    }
}
int main(){
    for(int i=0;i<=14;i++){
        eax,ebx,ecx,edx,esi = 0;
        func4(i,0,14);
        printf("%d\n",eax);
    }
    return 0;
}