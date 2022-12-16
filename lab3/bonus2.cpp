#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>

void init(char *niz, int n){
    for (int i = 0; i < n; i++){
        *(niz + i) = 0;
    }
}

double s = 0;

double zbroji(char *niz, int n){
    double rv = 0;
    for (int i = 0; i < n; i++){
        rv += *(niz + i);
    }
    return rv;
}

double funk(int n){
int cons = 1000;
    char *niz = (char *)malloc(n * sizeof(char));
    init(niz,n);
    double pocetak = clock();
    for(int j = 0; j < cons; j++){
        for(int i = 0; i < n; i++){
            *(niz + i) += 5;        
        }
    }
    double kraj = clock();   
    double rv = (kraj - pocetak) / CLOCKS_PER_SEC;
    double r = zbroji(niz, n);
    s += r;
    return rv;
}   

int main(){
    double last = 0;
    double test = 6 * 1024 * 1024;
    for(int i = test - 5; i < test + 5; i++){
        double r = funk(i);
        if (i == test) printf("NA TESTU ");
        printf("i  je %d -> r je %lf , razlika je %lf\n" , i , r, r - last);
        
        last = r;
    }
    return 0;
}
