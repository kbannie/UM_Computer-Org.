#include <iostream>
#include <chrono>


int main(){

    // ** STATIC MEMORY ALLOCATION **

    int i,j;
    int dst[1024][1024];
    int src[1024][1024];


    //Version 1
    auto begin_static_1=std::chrono::high_resolution_clock::now();

    for (i=0; i<1024; i++)
        for (j=0; j<1024; j++)
            dst[j][i]=src[j][i];

    auto end_static_1=std::chrono::high_resolution_clock::now();
    auto elapsed_static_1=std::chrono::duration_cast<std::chrono::nanoseconds>(end_static_1-begin_static_1);

    printf("Time of Version 1 with static memmory allocation measured: %.5f millieseconds.\n", elapsed_static_1.count()* 1e-6);


    //Version 2
    auto begin_static_2=std::chrono::high_resolution_clock::now();

    for (j=0; j<1024; j++)
        for (i=0; i<1024; i++)
            dst[j][i]=src[j][i];

    auto end_static_2=std::chrono::high_resolution_clock::now();
    auto elapsed_static_2=std::chrono::duration_cast<std::chrono::nanoseconds>(end_static_2-begin_static_2);

    printf("Time of Version 2 with static memory allocation measured: %.5f millieseconds.\n", elapsed_static_2.count()* 1e-6);


    //Compare Version1 and Version2
    if(elapsed_static_1.count()>elapsed_static_2.count()){
        printf("Version 2 is faster than Version 1 by %.5f millieseconds.\n", (elapsed_static_1.count()* 1e-6)-(elapsed_static_2.count()* 1e-6));
    }
    else
        printf("Version 1 is faster than Version 2 by %.5f millieseconds.\n", (elapsed_static_2.count()* 1e-6)-(elapsed_static_1.count()* 1e-6));   


    
    
    // **DYNAMIC MEMORY ALLOCATION **
    int ** dst_dynamic=new int*[1024];
    int ** src_dynamic=new int*[1024];
    for(int i=0; i<1024;i++){
        dst_dynamic[i]=new int[1024];
        src_dynamic[i]=new int[1024];
    }


    //Version 1
    auto begin_dynamic_1=std::chrono::high_resolution_clock::now();

    for (i=0; i<1024; i++)
        for (j=0; j<1024; j++)
            dst_dynamic[j][i]=src_dynamic[j][i];

    auto end_dynamic_1=std::chrono::high_resolution_clock::now();
    auto elapsed_dynamic_1=std::chrono::duration_cast<std::chrono::nanoseconds>(end_dynamic_1-begin_dynamic_1);

    printf("Time of Verstion 1 with dynamic memory allocation measured: %.5f millieseconds.\n", elapsed_dynamic_1.count()* 1e-6);


    //Version 2
    auto begin_dynamic_2=std::chrono::high_resolution_clock::now();

    for (j=0; j<1024; j++)
        for (i=0; i<1024; i++)
            dst_dynamic[j][i]=src_dynamic[j][i];

    auto end_dynamic_2=std::chrono::high_resolution_clock::now();
    auto elapsed_dynamic_2=std::chrono::duration_cast<std::chrono::nanoseconds>(end_dynamic_2-begin_dynamic_2);

    printf("Time of Version 2 with dynamic memory allocation measured: %.5f millieseconds.\n", elapsed_dynamic_2.count()* 1e-6);


    //Compare Version1 and Version2
    if(elapsed_dynamic_1.count()>elapsed_dynamic_2.count()){
        printf("Version 2 is faster than Version 1 by %.5f millieseconds.", (elapsed_dynamic_1.count()* 1e-6)-(elapsed_dynamic_2.count()* 1e-6));
    }
    else
        printf("Version 1 is faster than Version 2 by %.5f millieseconds.", (elapsed_dynamic_2.count()* 1e-6)-(elapsed_dynamic_1.count()* 1e-6));   


    //Dynamic Memory Deallocation 
    for (int i=0; i<1024; i++){
        delete[] dst_dynamic[i];
        delete[] src_dynamic[i];
    }

    delete[] dst_dynamic;
    delete[] src_dynamic;

    return 0;

}