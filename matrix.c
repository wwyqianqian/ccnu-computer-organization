#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define m 2000
#define n 1000
#define p 2000

//创建矩阵数组
int A[m][n];
int B[n][p];
int C[m][p];

int main() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            B[i][j] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }


    struct timeval st, et;

    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("ijk time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);


    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("kij time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);


    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < p; j++) {
            for (int i = 0; i < m; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("kji time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);


    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < p; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("ikj time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);

    
    //输出结果
/*    for(int i=0; i<m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f",A[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("*\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<p; j++) {
            printf("%.0f",B[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("=\n");
    for(int i=0; i<m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%.0f",C[i][j]);
            printf(" ");
        }
        printf("\n");
    }*/
    return 0;
}



//  ~/Desktop  gcc mx.c -o mx
//  ~/Desktop  ./mx
// ijk time: 15.744352 sec
// kij time: 9.360390 sec
// kji time: 39.164687 sec
// ikj time: 9.909856 sec