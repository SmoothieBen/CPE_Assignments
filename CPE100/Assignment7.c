//ข้อที่ 1
#include <stdio.h>

int findMinimum(int num1, int num2)
{
    if (num1 > num2)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}

void findMaximum(int num1, int num2, int *max)
{
    if (num1 > num2)
    {
        *max = num1;
    }

    else
    {
        *max = num2;
    }
}

int main()
{
    int num1, num2, option = 0, min, max;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
    while (option != 3)
    {
        printf("Choose what to do from options below");
        printf("\n1. Find minimum");
        printf("\n2. Find maximum");
        printf("\n3. Exit program");
        printf("\nEnter option no.: ");
        scanf("%d", &option);
        if (option == 1)
        {
            min = findMinimum(num1, num2);
            printf("Minimum value is: %d\n", min);
        }
        else if (option == 2)
        {
            findMaximum(num1, num2, &max);
            printf("Maximum value is: %d\n", max);
        }
    }
    printf("End of program. Goodbye.");
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------

//ข้อที่ 2

#include <stdio.h>

void printMatrix(int M[][10], int row, int col) {
  int i, j;
  printf("\nPrint Matrix:\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      printf("%d", M[i][j]);
    }
    if (i != row - 1)
      printf("\n");
  }
  printf("\n");
}

void readMatrix(int M[][10], int *row, int *col) {
  int i, j;
  printf("\nEnter no. of rows and columns of matrix: ");
  scanf("%d%d", row, col);
  printf("\nInput elements of matrix [%d %d]:\n", *row, *col);
  for (i = 0; i < *row; i++) {
    for (j = 0; j < *col; j++) {
      printf("M[%d][%d]: ", i, j);
      scanf("%d", &M[i][j]);
    }
  }
  printMatrix(M, *row, *col);
}

int main() {
  int M1[10][10], M2[10][10];
  int rowM1, colM1, rowM2, colM2;
  printf("Read Matrix M1:\n");
  readMatrix(M1, &rowM1, &colM1);
  printf("Read Matrix M2:\n");
  readMatrix(M2, &rowM2, &colM2);
  printf("\nM1 dimension: row = %d, col = %d", rowM1, colM1);
  printf("\nM2 dimension: row = %d, col = %d", rowM2, colM2);
  return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------

ข้อที่ 3

 67070501031_Benjamin Garforth
#include <stdio.h>
#include <string.h>

void test_function()
{
     int a;
     printf("Address of a in the Test Function is %p\n", &a); // แสดงที่อยู่หน่วยความจำของ 'a' ->> address : 0x7ffd5b91456c
}

int main() 
{
     // Part 1
     double num[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; // ประกาศ array ชนิด double ข้อมูล จำนวน 5 ค่า
     double *p = num;   // สร้างตัวแปร pointer 'p' ที่ชี้ไปยัง array [num] หรือ เก็บที่อยู๋ของ num

     // แสดงที่อยู่ของ pointer 'p' และ array[num]
     printf("p is %p\n", p);     // Format Specifiers ที่ใช้เป็น '%p' สำหรับการเรียกดู pointer ->> address : 0x7ffd5b9145a0
     printf("num is %p\n", num); // Format Specifiers ที่ใช้เป็น '%p' สำหรับการเรียกดู pointer ->> address : 0x7ffd5b9145a0

     // แสดงที่อยู่ของแต่ละสมาชิกใน Array
     printf("Address of num[0] is %p\n", &num[0]); // ใส่ & ในการพิมพ์ค่า address ->> address : 0x7ffd5b9145a0
     printf("Address of num[1] is %p\n", &num[1]); // ใส่ & ในการพิมพ์ค่า address ->> address : 0x7ffd5b9145a8
     printf("Address of num[2] is %p\n", &num[2]); // ใส่ & ในการพิมพ์ค่า address ->> address : 0x7ffd5b9145b0

     // ใช้ pointer เพื่อเข้าถึงค่าใน Array
     printf("Value of num[0] is %lf\n", *p);       // ค่า num[0] จะเท่ากับ 1.1
     printf("Value of num[1] is %lf\n", *(p + 1)); // ค่า num[1] จะเท่ากับ 2.2 เป็นการเลื่อนมา 1 ตำแหน่ง จาก p
     printf("Value of num[2] is %lf\n", *(p + 2)); // ค่า num[2] จะเท่ากับ 3.3 เป็นการเลื่อนมา 2 ตำแหน่ง จาก p

     // ใช้ pointer กับชื่อ Array โดยตรง
     printf("Value of num[0] is %lf\n", *num);       // ค่า num[0] เท่ากับ 1.1
     printf("Value of num[1] is %lf\n", *(num + 1)); // ค่า num[1] เท่ากับ 2.2 เป็นการเลื่อนมา 1 ตำแหน่ง จาก Array ของ num ที่ตำแหน่งเดิม
     printf("Value of num[2] is %lf\n", *(num + 2)); // ค่า num[2] เท่ากับ 3.3 เป็นการเลื่อนมา 2 ตำแหน่ง จาก Array ของ num ที่ตำแหน่งเดิม

     // Part 2
     int a;
     printf("Address of a in the Main Function is %p\n", &a); // แสดง address ของ 'a' ในฟังก์ชัน main ->> address : 0x7ffd5b91459c
     test_function(); // เรียกใช้งาน test_function ฟังก์ชัน --> เมื่อเรียกใช้งาน function นี้ จะมีการสร้าง พื้นที่นึงขึ้นมาโดยที่จะเป็นพื้นที่สำหรับตัวแปร a -> (stack memory)
     // เมื่อสิ้นสุดการทำงานของ function ตัวแปร a ที่ถูกเก็บอยู่ในพื้นที่ที่สร้างขึ้นมาใน stack memory จะถูกลบทิ้งออกไป และ address ของ a ที่อยู่ใน function นี้จะไม่สามารถเข้าถึงได้อีก
     int b;
     printf("Address of b in the Main Function is %p\n", &b); // แสดง address ของ 'b' ในฟังก์ชัน main ->> address : 0x7ffd5b914598

     // Part 3
     char word[3][5]; // ประกาศ Array [word] เก็บคำ 3 คำ คำละ 5 characters
     strcpy(word[0], "Ben");
     strcpy(word[1], "ja"); //ใช้คำสั่งstrcpy เพื่อนำค่า stringไปเก็บไว้ใน word[]
     strcpy(word[2], "min");
     printf("Address of word[0] is %p\n", word[0]); // แสดงที่อยู่ของ word[0] ->> address : 0x7ffd5b914589
     printf("Address of word[1] is %p\n", word[1]); // แสดงที่อยู่ของ word[1] ->> address : 0x7ffd5b91458e
     printf("Address of word[2] is %p\n", word[2]); // แสดงที่อยู่ของ word[2] ->> address : 0x7ffd5b914593

     // เนื่องจากยังไม่ได้กำหนดค่าให้ Array [word] ผลลัพธ์ที่แสดงจึงว่างเปล่า
     printf("Value of word[0] is %s\n", word[0]); //แสดงค่า string แต่ละตัว
     printf("Value of word[1] is %s\n", word[1]); // แสดงค่า string แต่ละตัว
     printf("Value of word[2] is %s\n", word[2]); // แสดงค่า string แต่ละตัว

     return 0;
}




