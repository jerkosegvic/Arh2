#include<cstdio>
#include<ctime>
#include<cstdlib>

#define l1sz (1<<17) //s1
#define l2sz (1<<20) //s2
#define l3sz 6*(1<<20) //s3
// b1, b2 i b3 su svi po 64

void init(char *niz, int n){
    for (int i = 0; i < n; i++){
        *(niz + i) = 0;
    }
}

double zbroji(char *niz, int n){
    double rv = 0;
    for (int i = 0; i < n; i++){
        rv += *(niz + i);
    }
    return rv;
}

double ukr = 0;

double a(){ 
    int cons = 500000;
    char *niz = (char *)malloc( l1sz * sizeof(char));
    double pocetak, kraj, ukupno;
	double rv = 0;
	init(niz, l1sz);
	pocetak = clock();
	for (int i = 0; i < cons; i++)	{
		for (int j = 0; j < l1sz; j++) {
		    *(niz + j) += 1;	
	    }
	}
	kraj = clock();
	ukr += zbroji(niz, l1sz);
	ukupno = (kraj - pocetak) / CLOCKS_PER_SEC;
	printf(" ->    Ukupno vrijeme od a je %.3lf\n", ukupno);
	rv = cons * l1sz / ukupno / (1<<20);
	free(niz);
	
    return rv;
}

double b(){
    int delta = 8;
    int cons = 100000;
    char *niz = (char *)malloc(delta * 2 * l1sz * sizeof(char));
    double pocetak, kraj, ukupno;
	double rv = 0;
	init(niz, l1sz * 2 * delta);
	pocetak = clock();
	for (int i = 0; i < cons; i++)	{
		for (int j = 0; j < l1sz * delta * 2; j+= 64 * delta) {
		    *(niz + j) += 1;	
	    }
	}
	kraj = clock();
	ukr += zbroji(niz, l1sz * 2 * delta);
	ukupno = (kraj - pocetak) / CLOCKS_PER_SEC;
	printf(" ->    Ukupno vrijeme od b je %.3lf\n", ukupno);
	rv = (double) cons * l1sz * delta * 2 / (64 * 8) / ukupno / (1<<20);
	free(niz);
	
    return rv;
}

double c(){
    int delta = 8;
    int cons = 10000;
    char *niz = (char *)malloc(delta * 2 * l2sz * sizeof(char));
    double pocetak, kraj, ukupno;
	double rv = 0;
	init(niz, l2sz * 2 * delta);
	pocetak = clock();
	for (int i = 0; i < cons; i++)	{
		for (int j = 0; j < l2sz * delta * 2; j+= 64 * delta) {
		    *(niz + j) += 1;	
	    }
	}
	kraj = clock();
	ukr += zbroji(niz, l2sz * 2 * delta);
	ukupno = (kraj - pocetak) / CLOCKS_PER_SEC;
	printf(" ->    Ukupno vrijeme od c je %.3lf\n", ukupno);
	rv = (double) cons * l2sz * delta * 2 / (64 * delta) / ukupno / (1<<20);
	free(niz);
	
    return rv;
}

double d(){
    int delta = 128;
    int cons = 1000;
    char *niz = (char *)malloc(delta * 2 * l3sz * sizeof(char));
    double pocetak, kraj, ukupno;
	double rv = 0;
	init(niz, l3sz * 2 * delta);
	pocetak = clock();
	for (int i = 0; i < cons; i++)	{
		for (int j = 0; j < l3sz * delta * 2; j+= 64 * delta) {
		    *(niz + j) += 1;	
	    }
	}
	kraj = clock();
	ukr += zbroji(niz, l3sz * 2 * delta);
	ukupno = (kraj - pocetak) / CLOCKS_PER_SEC;
	printf(" ->    Ukupno vrijeme od d je %.3lf\n", ukupno);
	rv = (double) cons * l3sz * delta * 2 / (64 * delta) / ukupno / (1<<20);
	free(niz);
	
    return rv;
}


int main(){
    double a_prop = a();
    double b_prop = b();
    double c_prop = c(); 
    double d_prop = d();
    printf("Propusnost od a je %.2lf MiB/sekundi \n", a_prop);
    printf("Propusnost od b je %.2lf MiB/sekundi \n", b_prop);
    printf("Propusnost od c je %.2lf MiB/sekundi \n", c_prop);
    printf("Propusnost od d je %.2lf MiB/sekundi \n", d_prop);   
    
    printf("L1/L2 = %lf\n", a_prop/b_prop);
	printf("L2/RAM = %lf\n", b_prop/d_prop);
     
    printf("%lf\n" , ukr);
    return 0;
}
