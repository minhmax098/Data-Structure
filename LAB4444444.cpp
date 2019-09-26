#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctime>


#define N 10000

int a[N];

// Xay dung ham con hoan vi dung de hoan vi 2 phan tu x va y cho nhau bang cach su dung bien trung gian tg cung kieu va thuc hien 3 phep gan
void hoanvi(int &x, int &y)
{
	float tg;
	tg = x;
	x = y;
	y = tg;
}
// 1. Selection sort
void selectionSort(int a[], int n)
{
	int vt;     // Chi so phan tu nho nhat trong day hien hanh
	for(int i=0; i<=n-1; i++)
	{
		vt = i;   // Tam thoi xem phan tu nho nhat tai vi tri thu i 
		for(int j=i+1; j<=n; j++)
			if(a[vt] > a[j]) vt=j;
			hoanvi(a[i], a[vt]);
	}
}

void selectionSort2(int a[], int n)
{
	int vt;     // Chi so phan tu nho nhat trong day hien hanh
	for(int i=0; i<=n-1; i++)
	{
		//vt = i;   // Tam thoi xem phan tu nho nhat tai vi tri thu i 
		for(int j=i+1; j<=n; j++)
			if(a[i] > a[j]) hoanvi(a[i], a[j]);
	}
}
// 2.insertion sort
void insertionSort(float a[], int n)
{
	for(int i=2; i<=n; i++)     // i=2, xem nhu doan a[1] da duoc sap xep
	{
		int x = a[i], j= i-1;  // Tim vi tri j+1 thich hop trong doan [1..i-1] de chen a[i] vao
		while ((j>=1) && (x<a[j]) )
		{
			a[j+1] = a[j]; // Doi cho cac phan tu a[j+1] den a[i-1] sang phai de gianh cho cho a[i]
			j--;
		}
		a[j+1] = x;   // doan a[1..i] da duoc sap xep, chen phan tu x vao sau phan tu thu j 
	}
}

//3. bubble sort 
void bubbleSort(int a[], int n )
{
	int i,j;    
	for(int i = 1; i<=n-1; i++)  // i=1 : lan xu li dau tien ; j= n: duyet tu cuoi day nguoc ve vi tri i 
	{
		for(int j =n; j >= i+1; j-- )   //j>=i+1 thuc hien 
		if(a[j-1] > a[j]) hoanvi(a[j-1], a[j]);   //neu a[j-1] > a[i] thi hoan vi a[j-1] voi a[j]
	}
}

//4.quick sort
void quickSort(int a[], int t, int p)
{
	if(t<p)
	{
		int i = t, j = p;   // Chon tuy y mot phan tu a[k] trong day la gia tri chot , chot = a[k],; i=t,j=p
		float chot;
		chot = a[(t+p)/2];   // Chon phan tu o giua lam CHOT
		while (i < j)
		{
			while (a[i] < chot ) i++;
			while (a[i] > chot )  j--;
			if(i <= j)
			{
				hoanvi(a[i], a[j]);  // a[i]>= chot >= a[j] ma a[j] dung sau a[i] thi hoan vi 
				i++;
				j--;
			}
		}
		quickSort(a,t,j);
		quickSort(a,i,p);
	}
}

//5. merge sort
void merge(float a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* Tao cac mang tam. */
    int L[n1], R[n2];
 
    /* Copy du lieu sang cac mang tam */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
 
    /* gop hai mang tam vua roi vao mang arr*/
    i = 0; // Khoi tao chi so bat dau cua mang con dau tien
    j = 0; // Khoi tao chi so bat dau cua mang con thu hai
    k = l; // Khoi tao chi so bat dau cua mang luu ket qua
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy cac phan tu con lai cua mang L vao arr neu co */
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy cac phan tu con lai cua mang R vao arr neu co */
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
/* l la chi so trai va r la chi so phai cua mang can duoc sap xep */
void mergeSort(float a[], int l, int r)
{
    if (l < r)
    {
        // Tuong tu (l+r)/2, nhung cach nay tranh' tran` so' khi l va` r lon'
        int m = l+(r-l)/2;
 
        // Goi ham de quy tiep tuc chia doi tung mang
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
 
        merge(a, l, m, r);
    }
}


void Random(int a[] , int n) {
	//printf("Cac phan tu da nhap vao la: \n");
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		a[i] = rand()%100;
		}
	}
	
void printArray(int a[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("a[%d] = %d \n ", i,a[i]);
   
} 

int main()
 {
 	int n;
    float b[N], c[N], d[N], e[N], f[N];     	
	printf("Nhap n: ");
	scanf("%d",&n);
	Random(a, n);
	printArray(a, n);
	
//	int q =1;
//	int p=2;
//	hoanvi(q,p);
//	printf("%d %d", q, p);
	
	// test buble sort
//	printf("Bubble sort \n");
//	bubbleSort(a, n);
//	printArray(a, n);
	
	// test selection 
	printf("Thoi gian thuc thi cua thuat toan selection sort la: \n");
	printf("Semlection sort \n");
	clock_t start1 = clock();
	selectionSort2(a,n);
	clock_t finish1 = clock();
	printArray(a,n);
	double duration1 = (double)((finish1 - start1) / CLOCKS_PER_SEC);
	printf("\n Selection sort = %.6f" ,duration1," ms");
	
//	printf("Thoi gian thuc thi cua thuat toan selection sort la: \n");
//	clock_t start1 = clock();
////	selectionSort(b,n);
//	clock_t finish1 = clock();
//	double duration1 = (double)((finish1 - start1) / CLOCKS_PER_SEC);
//	printf("\n Selection sort = %.60f" ,duration1," ms");
	
	printf("Thoi gian thuc thi cua thuat toan insertion sort la: \n");
	clock_t start2 = clock();
	insertionSort(c,n);
	clock_t finish2 = clock();
	double duration2 = (double)((finish2 - start2))/ CLOCKS_PER_SEC);
	printf("\n Insertion sort = %.60f" ,duration2," ms");

	printf("Thoi gian thuc thi cua thuat toan bubble sort la: \n");
	clock_t start3 = clock();
	insertionSort(d,n);
	clock_t finish3 = clock();
	double duration3 = (double)((finish3 - start3) / CLOCKS_PER_SEC);
	printf("\n Bubble sort = %.60f", duration3, " ms");
	
	printf("Thoi gian thuc thi cua thuat toan quick sort la: \n");
	clock_t start4 = clock();
//	bubbleSort(d,n);
	clock_t finish4 = clock();
	double duration4 = (double)((finish4 - start4) / CLOCKS_PER_SEC);
	printf("\n Quick sort = %.60f", duration4, " ms");
	
	printf("Thoi gian thuc thi cua thuat toan merge sort la: \n");
	clock_t start5 = clock();
	insertionSort(e,n);
	clock_t finish5 = clock();
	double duration5 = (double)((finish5 - start5) / CLOCKS_PER_SEC);
	printf("\n Merge sort = %.60f", duration5," ms");
	
	return 0;
}

/*so sanh thoi gian chay
	Chung ta se xem toc do sap xep cua cac thuat toan dua theo du lieu dau vao
	Theo kinh nghiem, thoi gian chay. : quick sort < merge sort < insertion sort < selection sort <buble sort
	*/
