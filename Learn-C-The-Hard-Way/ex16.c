<<<<<<< HEAD
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
=======
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

/**
    使用用于内存分配的malloc来向OS申请一块原始的内存。
    向malloc传递sizeof(struct Person)参数，它计算结构体的大小，包含其中的所有成员。
    使用了assert来确保从malloc得到一块有效的内存。有一个特殊的常量叫做NULL，表示“未设置或无效的指针”。这个assert大致检查了malloc是否会返回NULL。
    使用x->y语法来初始化struct Person的每个成员，它指明了所初始化的成员。
    使用strdup来复制字符串name，是为了确保结构体真正拥有它。strdup的行为实际上类似malloc但是它同时会将原来的字符串复制到新创建的内存。
*/
struct Person *Person_create(char *name, int age, int height, int weight)
{    
    struct Person *who = malloc(sizeof(struct Person));
    //malloc()动态分配内存空间
   
    assert(who != NULL);
     /*宏assert()用于错误检测。
        如果表达式的结果为零，宏写错误信息到STDERR并退出程序执行。
        如果宏NDEBUG已经定义，宏assert()将被忽略
        */

    who ->name = strdup(name);
    /*strdup()函数将串拷贝到新建的位置处，在内部调用了malloc()为变量分配内存，
    不需要使用返回的字符串时，需要free()释放相应的内存空间，否则会造成内存泄露。
    返回一个指针，指向为复制字符串分配的空间
    */
    who ->age = age;
    who->height = height;
    who ->weight = weight;

    return who;
}

/**
    如果定义了创建函数，那么一定需要一个销毁函数，它会销毁Person结构体。
    再一次使用了assert来确保不会得到错误的输入。
    接着使用了free函数来交还通过malloc和strdup得到的内存。
    如果你不这么做则会出现“内存泄露”。
*/
void Person_destroy(struct Person *who){
    assert(who != NULL);
    //void free(void *ptr)函数用来释放动态分配的内存空间。
    //可以释放malloc()、calloc()、realloc()分配的内存空间
    free(who ->name);
    free(who);
}

/**
    接下来我需要一个方法来打印出人们的信息，这就是这个函数所做的事情。
    它用了相同的x->y语法从结构体中获取成员来打印。
*/
void Person_print(struct Person *who){
    printf("Name:%s\n",who->name);
    printf("\tAge:%d\n", who->age);
    printf("\tHeight:%d\n", who->height);
    printf("\tWeight:%d\n", who->weight);
}

/**
    创建了两个人：joe和frank。
    把它们打印出来，注意我用了%p占位符，所以你可以看到程序实际上把结构体放到了哪里。
    把它们的年龄增加20岁，同时增加它们的体重。
    之后打印出每个人。
    最后销毁结构体，以正确的方式清理它们。
*/
int main(int argc,char *argv[]){
    //make two people structures
    struct Person *joe = Person_create("Joe Alex",32,64,148);
    //调用Person_create()函数，返回Person结构体的指针
    struct Person *frank = Person_create("Frank Blank",20,72,180);

    //print them out and where they are in memory
    printf("Joe is at memory location %p:\n",joe);
    //打印joe的地址
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    //打印frank的地址
    Person_print(frank);

    printf("===============================\n");

    //make everyone age 20 years and print the again
    joe ->age += 20;
    joe ->height -= 2;
    joe ->weight +=40;
    Person_print(joe);

    frank ->age +=20;
    frank ->weight += 20;
    Person_print(frank);

    /**
        释放内存
    */
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
   
}
>>>>>>> ae373b81bd460f8e1de493e7f92eae00ba5501ae
