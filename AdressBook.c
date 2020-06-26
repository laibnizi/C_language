#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define  MIN 6               //密码最小长度 
#define MAX 12                //密码最大长度 

struct node         //node 结构体名 
                       //在这个结构体中，有姓名，性别，电话，邮编，地址等数据，用数组实现数据的存储 
{
	char name[10];
	char sex[5];
	char phone [12];
	char postcode[7];
	char adder [50];
	
	struct node *next;      // 储存地址的结构体指针 
	
 } mvp;                                            //定义struct node类型的结构体变量mvp 
 
 struct node *p1,*p2,*head;                  // 定义 指向结构体类struct node 对象的指针变量p1,p2,head
 
 FILE *fp;                           //定义一个指向文件的指针，通过操作这个指针进行文件读写，打开,关闭
 void menu(){
system("cls");
 	system("color bc");                //调用dos命令设置Dos窗口颜色,前面的 4设置窗口背景颜色，f 设置窗口字体颜色（前景          
	 
 /* 0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       A = 淡绿色
    3 = 湖蓝色     B = 淡浅绿色
    4 = 红色       C = 淡红色
    5 = 紫色       D = 淡紫色
    6 = 黄色       E = 淡黄色
    7 = 白色       F = 亮白色
	 */
	 
	         
 	printf("*********                                   ***********\n");
 	printf(" **       **        $ 欢迎使用通讯录 $     **       **\n");
 	printf("  **       **                             **   O   **\n");
 	printf("   **   O   **      我是 — 秦始皇       **       **\n");
 	printf("    **       **                         **       **\n");
 	printf("     **       ***************************       **\n");
 	printf("      **                                       **\n");
 	printf("       **         1---->>>新建联系人          **\n");
 	printf("        **        2---->>>按姓名查询         **\n");
 	printf("         **       3---->>>显示某某某        **\n");
 	printf("          **      4---->>>删除或修改       **\n");
 	printf("           **     5---->>>退出通讯录      **\n");
 	printf("            **    6---->>>按电话查询     **\n");
 	printf("             **    0----->>>>删除       **\n"); 
	printf("              **          W            **\n");
 	printf("              **                      **\n");
 	printf("               **    *        *      **\n");
 	printf("                **     * * **       **\n");
 	printf("                  **               **\n");
 	printf("                   **             **\n");
 	printf("                    **           **\n");
 	printf("                      **        **\n");
 	printf("                       **      **\n");
 	printf("                         **  **\n");
 	printf("                           ** \n");
 	
 }
 
 void HeadShow()
 {
 	printf("@@------->>>>       联系是情感的桥梁      ------->>>>%%%\n");
 	printf("                                                        \n");
 	printf("***************         通讯录         ****************\n"); 
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  } 
  
  
  
  void Loading()                  ///////////////////////  //加载 、装入 ////////////////////////////////////////////////////////////////////////////////////////////////////
  {
  	if((fp=fopen("txl.dat","rb"))==NULL)      //判断打开文件是否成功，判断以读二进制的方式打开文件txl.dat，文件句柄保存到fp，fp是否为空,如果为空，就是打开文件失败，否则打开文件成功
  	
  	                                             
												    /*在文件I/O中，要从一个文件读取数据，应用程序首先要调用操作系统函数并传送文件名，并选一个到该文件的路径来打开文件。
  	                                              
													该函数取回一个顺序号，即文件句柄（file handle），该文件句柄对于打开的文件是唯一的识别依据。
													
													要从文件中读取一块数据，应用程序需要调用函数ReadFile，并将文件句柄在内存中的地址和要拷贝的字节数传送给操作系统。
													
													当完成任务后，再通过调用系统函数来关闭该文件。__________文件句柄*/
  	
  	
	  {
	  	printf("操作错误！");
		  Sleep(3000);
		  exit(1);          //异常退出 
	   } 
	   
	   
	   
	   p1=(struct node *)malloc(sizeof( struct node));       /*  为P1 申请内存空间       
	                                                              1.sizeof(struct node )就是求 struct node 这个结构体占用的字节数。
	   
                                                                2.  malloc(sizeof(struct node))
                                                                  申请 struct node 这个结构体占用字节数大小的空间
                                                                  
                                                                3. (struct node *) malloc(sizeof(struct node))
                                                                       将申请的空间的地址强制转化为 struct node * 指针类型
                                                                       
                                                                4. p1=(struct node *) malloc(sizeof(struct node))
                                                                        将那个强制转化的地址赋值给 p1.        */

 
	    
	    p1->next=NULL;                //将P1的下一个节点置为空 ，即为带插入节点P1的指针域赋值为空指针 
		head=p1;                            //将P1作为头结点 
		
		while(!feof(fp))       //判断文件指针是否达到末尾，没有则执行下面的步骤
		                              
		                              //feof(file stream)文件指针到达文件末尾
                                        //!feof(fp) 表示没有到达末尾
		
		                            //feof是C语言标准库函数，其原型在stdio.h中，
									//其功能是检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0，文件结束符只能被clearerr()清除。（这里的检测流上的文件结束符就相当于声卡检测电流信号的一个过程） 
		                            
		{
			if(fread(p1,sizeof(struct node),1,fp)!=1)     //从fp中读取一个数据项单位长度是sizeof(steuct node)的字节，并将其存到P1指向的内存；返回单位长度数，将其与1 比较 
		
			break;                                         //如果返回值不为1，则跳出循环体,读取失败 
			                                                   //fread是一个函数，它从文件流中读数据，最多读取count个项，每个项size个字节，如果调用成功返回实际读取到的项个数,这里为1 
			
			 p2=(struct node*)malloc(sizeof(struct node));
			                                            //为P2申请内存 
			
			p2->next=NULL;                          /////带插入节点P2的指针域赋值为空指针 
			p1->next=p2;            //将P1的下一个数据置为P2 
			p1=p2;                              //将p2给P1 
		 } 
		 fclose(fp);
  }
  
  
  void Tiajia()  
{     
    char ch;   
    //if((fp==fopen("txl.dat","ab+"))!=1)  //另一种打开和判断的范式 
    fp=fopen("txl.dat","ab+");                //以读写的方式打开二进制文件 txt.dat ,保留原文件的所有内容，向其文件末尾添加数据
	                                           //dat,格式的好处据我发现，这些文件不能直接打开，也不能转换成文本文件，用这个扩展名保存数据，安全，用TXT则可被查看 
    if(fp==NULL)
    {  
        printf("文件打开失败");  
        exit(1);  
    }  
    
    
    while(1)  
    {   system("cls");  /*清屏，顾名思义，就是清除屏幕输出的作用。
                             当调用清屏时，屏幕上所有输出都会被清掉，相当于重新提供了一个画布，供软件自由输出。
                   清屏一般用在以下几种情况：
                       1 上一个功能执行完毕，输出不再重要，需要显示新的内容或者菜单时。
                              2 出于加密考虑，比如一些记忆类的游戏，在显示若干秒后，清除所有输出。
                                                 3 要显示大段关键数据，为避免之前打印信息的影响，执行清屏操作。
                                                    C语言中清屏一般使用
                                                                 system("cls");     */
    
    
    
    
        printf("请输入————\n");  
        p2=(struct node*)malloc(sizeof(struct node));    //申请分配内存 
        
        p2->next=NULL;         //将P2的下个节点置为空 
        
        printf("姓名：");scanf("%s",mvp.name);  
        
             printf("性别：");scanf("%s",mvp.sex);  
        
                   printf("电话号码：");scanf("%s",mvp.phone);  
                              printf("邮编：");scanf("%s",mvp.postcode);  
                                 printf("地址：");scanf("%s",mvp.adder);  
                                 
                                   strcpy(p1->name,mvp.name);  //将结构体变量成员name的值拷贝给地址指针 
                                  strcpy(p1->sex,mvp.sex);  
        
                           strcpy(p1->phone,mvp.phone);  
                   strcpy(p1->postcode,mvp.postcode);  
             strcpy(p1->adder,mvp.adder);  
             
        p1->next=p2;  
        p1=p2;          
        if(fwrite(&mvp,sizeof(struct node),1,fp)!=1)            //将mvp变量所指向的内容输入到fp这个文件中，
		                                                            //每次输出的数据单元占sizeof(struct node)个字节，总共输出1次

                                                                    // 如果输出正确，应该是返回1的，因为fwrite返回值是返回正确输出了几个数据单元
                                                                  
            printf("写入错误");  
            
        printf("按Enter继续添加--- |---- k结束输入");                        //结束输入的语句 
        
        getchar();  
        ch=getchar();  
        if(ch==' '||ch=='k')  
            break;  
  
    }  
    fclose(fp);  
}  


void SaCa()                    //保存函数 
{     

   // if((fp==fopen("txl.dat","w"))!=1)       //以只写的方式创建并打开文件 
   fp=fopen("txl.dat","w"); 
   if(fp==NULL)
    {  
        printf("文件打开失败");  
        exit(1);  
    }  
    
    
    p1=head;   //将P1置为头结点
	 
    while(p1->next!=NULL)    //若未到表尾，则移动P1直到P1指向表尾 
    
    {  
        if(fwrite(p1,sizeof(struct node),1,fp)!=1)     //将P1这个指针变量所指向的内容输出到fp这个文件中，
		                                                            //每次输出的数据单元占sizeof(struct node)个字节，总共输出1次

                                                                    // 如果输出正确，应该是返回1的，因为fwrite返回值是返回正确输出了几个数据单元
                                                                  
        
            printf("写入错误");  
        p1=p1->next;             //让P1指向下一个节点 
          
    }   
    fclose(fp);  
}  

///////////////////////////////////////////////////////////////////显示函数、、、、、、、、、、、、、、、、、、、//////////////////////////////////////////////////// 
void Display()                        //显示所有 xinxi 
{  
system("cls");
    HeadShow();  
    printf("%10s %6s  %11s %9s %16s \n","姓名","性别","电话","邮编","地址");      
    printf("**************************************************************\n");  
    
    p1=head;  //将P1做为头结点
	 
    while(p1->next!=NULL)                ///////若未到表尾，则移动P1直到P1指向表尾 ，如若不是表尾，则输出所有信息 
    {  
        printf("%10s %6s %11s %9s %16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
        
        p1=p1->next;                  ////////让P1指向下一个节点  ,继续循环 
          
    }   
     system("pause");   
     
	 //Sleep(60000);return;
}  


/*
void Fond()
{
	int numb; 
		system("color 33");
 	printf("*********                                   ***********\n");
 	printf(" **       **        $ 欢迎使用通讯录 $     **       **\n");
 	printf("  **       **                             **   O   **\n");
 	printf("   **   O   **            秦始皇         **       **\n");
 	printf("    **       **                         **       **\n");
 	printf("     **       ***************************       **\n");
 	printf("      **                                       **\n");
 	printf("       **         1---->>>按姓名查询          **\n");
 	printf("        **                                    **\n");
 	printf("         **       2---->>>按电话查询         **\n");
 	printf("          **                                **\n");
 	printf("           **     5---->>>退出  查询      **\n");
 	printf("            **                           **\n");
 	printf("             **           W             **\n");
 	printf("              **                      **\n");
 	printf("               **    *        *      **\n");
 	printf("                **     * * **       **\n");
 	printf("                  **               **\n");
 	printf("                   **             **\n");
 	printf("                    **           **\n");
 	printf("                      **        **\n");
 	printf("                       **      **\n");
 	printf("                         **  **\n");
 	printf("                           ** \n");
}

*/


void Lookname()  
{   system("cls");   //清屏
 
   HeadShow();  //调用函数或者叫方法 
    	system("cls");
    printf("%8.8s %6.6s  %11.14s %9.8s %20s \n","姓名","性别","电话","邮编","地址");      ///设置输出的格式，属性间的值可以根据需求来调节，最好与输出时写出数据形式配对 
    printf("---------------------------------------------------------------------\n");  
    
    p1=head;         ///////////////将P1做为头结点
    
    char Xingming[8];              //定义数组 用于接受姓名输入的存储 
    
int count=0;   //////用于记录成员变量的个数，有一个记录一个 
    
    printf("请输入要查询的姓名：");  
    scanf("%s",&Xingming);  
    printf("----------------------------\n");
    printf("查询结果如下：\n"); 
     printf("\n");
    while(p1->next!=NULL)             ///////若未到表尾，则移动P1直到P1指向表尾
    {  
        if(strcmp(p1->name,Xingming)==0)   // 将接受用户输入的姓名和结构体指针中的姓名比较，如果相等则返回0，用strcmp的返回值与后面的0比较，若二者相等，则输出与此姓名相关的所有值 
        
            {
			printf("%8.8s %5.5s  %11.14s %9.7s %18s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  //////访问结构体指针变量 P1指向的结构体的成员并输出 
            
            count++;         //访问下一个 ,记录同名的人的个数 
            }  
        p1=p1->next;     //// ////////让P1指向下一个节点,直到表尾 ,防止无限循环 ， /////////////////////////P1指向当前节点的下一节点  
          
    }   
    printf("\n");
	printf("共  %d   条\n",count) ; 
	printf("----------------------------------------------------\n"); //做一个排版 
    system("pause");   
    return ;
}   
  
void Seekphone()  
{   system("cls");   
    HeadShow();  
    printf("%10.8s %6.6s  %11.4s %9.7s %16.6s \n","姓名","性别","电话","邮编","地址");      
    printf("---------------------------------------------------------------------\n");  
    p1=head;  
    char phone[11];  
    int i=0;   
    printf("请输入要查询的电话号码：");  
    scanf("%s",&phone);  
    printf("查询结果如下：\n"); 
    while(p1->next!=NULL)      // ///////若未到表尾，则移动P1直到P1指向表尾
    {  
        if(strcmp(p1->phone,phone)==0)   
        
            {printf("%10.8s %6.6s  %11.4s %9.7s %16.6s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
            i++;  
            }  
        p1=p1->next;  /////////////////////////P1指向当前节点的下一节点 
          
    }   
     printf("\n");
    printf("共  %d  条\n",i);  
    	printf("----------------------------------------------------\n");
    system("pause");   
   
}   


void End()
{
	system("cls");
	system("color 4f");
 	printf("*********                                   ***********\n");
 	printf(" **       **        $ 欢迎使用通讯录 $     **       **\n");
 	printf("  **       **                             **   O   **\n");
 	printf("   **   O   **            秦始皇         **       **\n");
 	printf("    **       **             ▲          **       **\n");
 	printf("     **       ***************************       **\n");
 	printf("      **                                       **\n");
 	printf("       **                  **                   $\n");
 	printf("        **                **   谢                $$\n");
 	printf("         **              **   谢                    $$\n");
 	printf("          **            **                       $$\n");
 	printf("           **         **   使                  $$\n");
 	printf("            **         **  用              $$\n");
 	printf("             **           W             **\n");
 	printf("              **                      **\n");
 	printf("               **    *        *      **\n");
 	printf("                **     * * **       **\n");
 	printf("                  **               **\n");
 	printf("                   **             **\n");
 	printf("                    **           **\n");
 	printf("                      **        **\n");
 	printf("                       **      **\n");
 	printf("                         **  **\n");
 	printf("                           ** \n");
 	
 
 
}

////////////////////////////////////////////////修改函数、、、、、、、、、////////////////////////////////////////////// 
void Revise()  

{ system("color ac");
	system("cls");
  char names[8];   
  
  
    system("cls");  
    HeadShow();  
    Display(); 
    int i,B=3;          ////////设置程序标记 B,  用于后续函数的操作  
    int R;  
    p1=p2=head;    
    
   
	            
    printf("请输入你要修改的联系人姓名：");  
    
    scanf("%s",&names);  
    
        getchar();               ///接受用户输入 
    while(p1!=NULL)  
    {     
    if(strcmp(p1->name,names)==0)               ////将用户输入的名字与已经存在的数据进行比较，符合则执行下面语句 
    
       {    printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
       
       
       
            printf("您确定修改 ●●●1---是$▋$----2 ●●●否\n");  
            scanf("%d",&i);  
            
            if(i==1)  
            
            { 
            
		B=1;  
			
            printf("你要修改的通讯录为:\n");  
            printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
            printf("请选择您的操作：----4---删除|-----5---修改\n");  
            scanf("%s",&R);   
               if(R=4)   
            {  
                    if(p1==head)   ////////////若果P1是头结点，则让头指针指向待删节点P1的下一节点 
				       
                        {
				           head=p1->next;    
                                    free(p1);  
                       }  
                  else  
               {  
                p2->next=p1->next;        ////////否则让前一节点的指针域指向待删节点的下一节点 
                free(p1);     
                SaCa();     //////////////////////////////保存数据 
                  
              }  
                  
            }   
               else if(R=5)  
             {  
            printf("姓名:");scanf("%s",p1->name);  
           /* printf("性别:");scanf("%s",p1->sex);  
           
            printf("电话:");scanf("%s",p1->phone);  
            printf("邮编:");scanf("%s",p1->postcode);  
            printf("地址:");scanf("%s",p1->adder);    */
            SaCa();  
            
            printf("\n  OK!    \n");  
            }     
        }             
          else if(i==2)         //////////如果用户放弃修改，则直接返回主菜单 
		  {
                 return ;
		   } 
       }  
    else if(strcmp(p1->name,names)&&(p1->next)==NULL)     ///////如果 找到表尾 且没有 值，则将已经定义的i的值任取一个 然后将B 的值传给i输出 ，因为B是标记 
      {
      	i==3;                         
	  }
        p2=p1;                           //////////////////////////////////////将P1的值给前一节点P2 
        p1=p1->next;     /////////////////////////P1指向当前节点的下一节点 
    }  
  
     if(B==3)                  ///////////////B的值可以随便取， 与i相等即可 
    {  
        printf("对不起，查无此人，请检查你要修改的姓名是否正确\n");  
    }  
      
      
    system("pause");  
}  





/*void Revise()  

{   
system("cls");
char names[8];   
    int R;  
    system("cls");  
    HeadShow();  
    int i;   
	             
    p1=p2=head;       
    
    printf("请输入你要修改的条目的姓名：");  
    
    scanf("%s",&names);  
    
        getchar();    
        
    while(p1!=NULL)  
    {     
    if(strcmp(p1->name,names)==0)     
       {   
	    printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
       
       
       
            printf("您要修改的是这条记录吗？1---是|2否\n");  
            scanf("%d",&i);  
  if(i==1)
	   {  
            printf("姓名:");scanf("%s",p1->name);  
            printf("性别:");scanf("%s",p1->sex);  
           
            printf("电话:");scanf("%s",p1->phone);  
            printf("邮编:");scanf("%s",p1->postcode);  
            printf("地址:");scanf("%s",p1->adder);    
            SaCa();  
            printf("\n  OK!    \n");  
            
        }     
        else
       	
        {
        	printf("按任意键返回主菜单\n");
        Sleep(3000);
			return; 
		}
		
} 
}
system("pause");  
}
/*	char ChangeName[8];   
    int changekey,flag=0;  
    system("cls");  
    HeadShow();  
    if(!head->next)
    { system("cls");  
    	printf("lalalallalalal");
    	
    	
    }
    else
    {
    	printf("input the name!");
    	gets (ChangeName);
    	p2=head;
    	p1=head->next;
    	while(p1 && strcmp(p1->name,ChangeName)!=0)
    	{
    	p2=p1;
		p1=p1->next;	
    	}
    	if(p1)
    	{
    		p2->next=p1->next;
    		flag=1;
    		free(p1);
    		printf(" \n chuhuhuhu \n");
    		getchar();
    	}
    	else
    	printf("\n no find. \n");
    	 SaCa();
    	 getchar();
    	
    	
    }
    
}
*/
/*void Dele()  

{  
system("cls");
 char names[8];   
    int D;  
    system("cls");  
    HeadShow();  
   
	             
    p1=p2=head;       
    
    printf("请输入你要修改的条目的姓名：");  
    
    scanf("%s",&names);  
    
        getchar();    
        
    while(p1!=NULL)  
    {     
    if(strcmp(p1->name,names)==0)     
       {   
	    printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
       
       
       
            printf("您要删除的是这条记录吗？1---是|2否\n");  
            scanf("%d",&D);  

             if(D==1)   
             {  
                if(p1==head)           
                 {head=p1->next;    
                  free(p1);  
                 }  
                  else  
                 {  
                p2->next=p1->next;  
                free(p1);     
                SaCa();     
                  
                 }  

           } 
            else
       	
        {
        	printf("按任意键返回主菜单\n");
        Sleep(3000);
			return; 
		}
    }
    else if(strcmp(p1->name,names)&&(p1->next)==NULL)
    {
    	 p2=p1;        
        p1=p1->next; 
	}
}
 system("pause"); 
}

*/

void  pass()
{
	system("cls");

	//////////////////////////////另一种字体颜色的方式 
	/*	HANDLE hOut;  
  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_GREEN |   
                            FOREGROUND_BLUE);  
 printf("This text is cyan.\n");
  
  
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_BLUE |   
                            FOREGROUND_RED);  
     printf("This text is cyan.\n");  
  
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_RED |   
                           FOREGROUND_GREEN |   
                            FOREGROUND_BLUE);  
    printf("This text is cyan.\n");
    */
    
    /////////////////////////////////////////////////////////////////////////////////////////////////// 
    
    HANDLE hOut;  
  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
  printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED);  
    printf("-------------------我们都是戏子，在别人的故事里流自己的眼泪------------------\n") ; printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_INTENSITY);  
       printf("-----------在一页页深蓝浅蓝的泪痕里 有着谁都不知道的语句------------------\n") ;printf("\n") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN);  
   printf(" --------------我曾踏月而来，只因你在山中 山风拂髮 拂颈 拂我心 -------------\n") ;printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN |  
                            BACKGROUND_INTENSITY);  
    printf("-------------我将我的心事  夹在书页里 也将我的爱慕放在文字里----------------\n") ;printf("\n") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE);  
     printf("------------如果最美的年华再错过，再也没有什么借口可以原谅自己的-------------\n") ;  printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE |  
                            BACKGROUND_INTENSITY);  
    printf("-------------爱，原来是没有名字的，在相遇之前等待的，就是它的名字-----------\n") ;  printf("\n") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN);  
    printf("---------->>>>联系") ;  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN |  
                            BACKGROUND_INTENSITY);  
    printf("也是") ;  
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE);  
    printf("爱的") ; 
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE |  
                            BACKGROUND_INTENSITY);  
    printf("一种") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE |  
                            BACKGROUND_RED);  
     printf("方式") ;  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE |  
                            BACKGROUND_RED |  
                            BACKGROUND_INTENSITY);  
    printf("@@") ;  
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE);  
   printf("所有") ; 
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE |  
                            BACKGROUND_INTENSITY);  
     printf("人----->>>>>") ;  
    
  
  Sleep(1000);
    	
	
	system("cls");
		system("color e4");
		printf("\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("***************         通讯录         ****************\n");
					printf("\n");
		printf(" @@------->>>>       联系是情感的桥梁      ------->>>>%%%\n");
 	printf("                                                        \n");
 	printf("***************        我是秦始皇        ****************\n"); 
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("\n");printf("\n");printf("\n");
	
	printf("---------------------皇上，妲己陪你玩\n");
	
	printf("\n") ;
		printf("--------------------别废话，密码是多少\n");
	
	int loop;
	
	char password[13];                 //为密码的字符串预留一个结束标志位 
	
	printf("\n input the password(6~12characters):");
	
	for(loop=0;loop<MAX;loop++)                  ///设置循环 
	{
		password[loop]=getch();                //接受输入 
		
		printf("*");                       //以星号代替密码字符显示 
		
		if(password[loop]=='\x0d')                 //回车结束密码的输入 
		{
			if(loop<MIN)
			{
				printf("\n The length the password is less than 6,press any  key to contine....");
				
				getch();                   //暂停，按任意键继续 
				
				printf("\n Please input the password agin(6~12):");
				
				loop=-1;                // 执行loop++后，使下标复位为0 
			}
			else
			{
				password[loop]='\0';                  //设置密码结束标志 
				break;
			}
		}
		if(loop==MAX-1)                //密码长度达到最大值 
		password[loop]='\0';                //设置密码串结束标志 
		
		
		
	}
}









int main()  
{  
pass();
	system("cls");
	
 int demo;  
    int Ex;   
    int numb;  
    char a[10];  
    if((fp=fopen("txl.dat","ab"))==NULL)  ///////////////////判断以只写的方式打开二进制文件txl.dat，文件句柄保存到fp，fp是否为空,如果为空，就是打开文件失败，否则打开文件成功
    {  
        printf("文件操作错误，请检查是否有权限操作文件！");  
        Sleep(3000);  
        exit(1);  
    }  
    fclose(fp);   
    Loading();  
    while(1)
	{  
    menu();  
    
    gets(a);                           //获取用户输入 
    demo=atoi(a);  /* 将字符转化为整数    ，并且将值传给deno 
	   atoi (表示 ascii to integer)是把字符串转换成整型数的一个函数，应用在计算机程序和办公软件中。
	             atoi( ) 函数会扫描参数 nptr字符串，跳过前面的空白字符（例如空格，tab缩进等。
                         可 以通过isspace( )函数来检测），直到遇上数字或正负符号才开始做转换，
                  而在遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
                        如果 nptr不能转换成 int 或者 nptr为空字符串，那么将返回 0[1]  。    
						 
						
					vs2013里调用printf函数请使用预处理命令#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
    int n;
    char *str = "12345.67";
    n = atoi(str);
    printf("n=%d\n",n);
    return 0;
}
输出：
n = 12345

（2）
//vs2013里调用printf函数请使用预处理命令#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
 
int main()
{
    char a[] = "-100";
    char b[] = "123";
    int c;
    c = atoi(a) + atoi(b);
    printf("c=%d\n", c);
    return 0;
}
执行结果：
c = 23  */
  
      if(demo==1)                 ///////////////////如果为1，则加载函数 
      
         {
      system("cls");
          Tiajia() ; 
          }
else

switch(demo)             ////////////////利用switch 语句根据值进行主菜单的提示输入，进行函数调用 
{
	///case 0:Dele() ;break;
	case 2: Lookname(); break;
	
	case 6: Seekphone();break;
	
	case 3:Display();	Sleep(1000);
	break;;
	
	case 4:Revise()  ; break;
	
	case 5:End();   
	Sleep(1000);  
        exit(0);               ////////设置函数调用后的正常退出 
	break;

	
}
 	
}
 
}


