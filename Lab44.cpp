
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//1.Sap xep chen: dyyet het cac phan tu va chen tung phan do vao dung vi tri cua mang con 
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;  // Tim vi tri j+1 thich hop trong doan [1..i-1] de chen arr[i] vao
       // Di chuyen cac phan tu co gia tri lon hon gia tri key ve sau mot vi tri so voi vi tri ban dau 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];  //Doi cho cac phan tu arr[j+1] den arr[i-1] sang phai de gianh cho cho arr[i]
           j = j-1;
       }
       arr[j+1] = key;  // doan arr[1..i] da duoc sap xep, chen phan tu  vao sau phan tu thu j 
   }
}

//2.Sap xep chon : chon phan tu nho nhat cua doan chua sap xep doi cho cho phan tu dau tien cua doan chua sap xep voi thuc hien hien tiep 

//Xay dung ham con hoan vi dung de hoan vi 2 phan tu xp va yp cho nhau bang cach su dung bien trung gian temp cung kieu va thuc hien 3 phep gan
void hoanvi(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
// Ham sap xep chon
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // Di chuyen ranh gioi cua mang da sap xep va chua sap xep
    for (i = 0; i < n-1; i++)
    {
    // Tim phan tu nho nhat trong mang chua duoc sap xep
    min_idx = i;   // Tam thoi xem vi tri nho nhat tai vi tri thu i
    for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
        min_idx = j;
    // Doi cho phan tu nho nhat voi phan tu dau tien : hoan vi phan tu nho nhat voi phan tu thu i 
        hoanvi(arr[min_idx], arr[i]);
    }
}

//3.Sap xep noi bot: y tuong la xuat phat tu cuoi day , doi cho cac phan tu ke can de dua vi tro nho hon ve vi tri dung dau day
void bubbleSort(int arr[], int &n)
{
  	for (int i = 0; i<n; i++) {
 	for (int j = n - 1; j>i; j--)  //// i=1 : lan xu li dau tien ; j= n: duyet tu cuoi day nguoc ve vi tri i 
 		if (arr[j - 1] > arr[j]) {  ////neu arr[j-1] > arr[i] thi hoan vi arr[j-1] voi arr[j]
 			int temp = arr[j - 1];
 			arr[j - 1] = arr[j];
 			arr[j] = temp;
 		}
 	}
}

//4.Sap xep nhanh  : chon khoa o cuoi , cac pha tu nho hon o ben trai , cac phan tu lon hon o ben phai 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot : chot , chon vi tri cao nhat
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        hoanvi(arr[left], arr[right]);
        left++;
        right--;
    }
    hoanvi(arr[left], arr[high]);
    return left;
}

// Ham thuc hien giai thuat Quick sort 
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        // pi là chi so noi phan tu nay da dung dung vi tri va la phan tu chia mang lam 2 mang con trai va phai
        int pi = partition(a, low, high);
 
        // Goi de quy sap xep 2 mang con trai va phai
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

//5. Sap xep tron : merge sort : chia than 2 mang, moi mang chia tiep , chia den luc con 1 phan tu roi sap xep
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* Tao cac mang tam. */
    int L[n1], R[n2];
 
    /* Copy du lieu sang cac mang tam */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* gop hai mang tam vua roi vao mang arr*/
    i = 0; // Khoi tao chi so bat dau cua mang con dau tien
    j = 0; // Khoi tao chi so bat dau cua mang con thu hai
    k = l; // Khoi tao chi so bat dau cua mang luu ket qua
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy cac phan tu con lai cua mang L vao arr neu co */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy cac phan tu con lai cua mang R vao arr neu co */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


 
/* l la chi so trai va r la chi so phai cua mang can duoc sap xep */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tuong tu (l+r)/2, nhung cach nay tranh' tran` so' khi l va` r lon'
        int m = l+(r-l)/2;
 
        // Goi ham de quy tiep tuc chia doi tung mang
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

//
void Random(int arr[], int n) {
	printf("Cac phan tu da nhap vao la: \n");
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i] = rand()%100;
		}
	}
	
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
int main() {
    clock_t start, end;
    double duration;
	int n;             	
	printf("Nhap n: ");
	scanf("%d",&n);
	int arr[n];
	Random(arr, n);
////test insertion sort
// printf("Insertion sort \n");
//insertionSort(arr, n);
// printArray(arr, n);
//	
//// test selection sort 
//printf("Selection sort \n");
//selectionSort(arr,n);
//printArray(arr,n);
//	
//
//// test buble sort
//	printf("Bubble sort \n");
//	bubbleSort(arr, n);
//	printArray(arr, n);

// test quick sort
//	printf("Quick sort \n");
//	quickSort(arr, n);
//	printArray(arr, n);

// test merge sort
//	printf("Merge sort \n");
//	mergeSort(arr, n);
//	printArray(arr, n);


	
	// Tinh thoi gian thuc thi cua insertion sort
	clock_t start1 = clock();  // ham dem thoi gian thuc hien
	int *b = new int[n];
	for( int i = 0; i < n; i++)
	{
		b[i] = arr[i];
	}
	insertionSort(b, n);
	clock_t finish1 = clock();     // ham dem thoi gian ket thuc 
	double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc thi  cua insertion sort: %.2lf \n", duration1);
    
    // Tinh thoi gian thuc thi cua selection sort
    clock_t start2 = clock();
   	int *c = new int[n];
	for( int i = 0; i < n; i++)
	{
		c[i] = arr[i];
	}
    selectionSort(c, n);
    clock_t finish2 = clock();
	double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
	printf("Thoi gian thuc thi cua selection sort: %.2lf \n", duration2);
	
	// Tinh thoi gian thuc thi cua bubble sort
	clock_t start3 = clock();
	int *d = new int[n];
	for( int i = 0; i < n; i++)
	{
		d[i] = arr[i];
	}
	bubbleSort(d, n);
	clock_t finish3 = clock();
	double duration3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
	printf("Thoi gian thuc thi cua bubble sort: %.2lf \n", duration3);
	
	clock_t start4 = clock();
	quickSort(arr, 0, n-1);
	clock_t finish4 = clock();
	double duration4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc thi cua quick sort: %.2lf \n", duration4);
    
    // Tinh thoi gian thuc thi cua merge sort
    clock_t start5 = clock();
    int *e = new int[n];
	for( int i = 0; i < n; i++)
	{
		e[i] = arr[i];
	}
    mergeSort(arr, 0, n - 1);
    clock_t finish5 = clock();
	double duration5 = (double)(finish5 - start5) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc thi cua merge sort: %.2lf \n", duration5);
    
    return 0;
}

/*so sanh thoi gian chay
	Chung ta se xem toc do sap xep cua cac thuat toan dua theo du lieu dau vao
	Theo kinh nghiem, thoi gian chay. : quick sort < merge sort < insertion sort < selection sort <buble sort
	*/


