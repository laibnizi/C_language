#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define  MIN 6               //������С���� 
#define MAX 12                //������󳤶� 

struct node         //node �ṹ���� 
                       //������ṹ���У����������Ա𣬵绰���ʱ࣬��ַ�����ݣ�������ʵ�����ݵĴ洢 
{
	char name[10];
	char sex[5];
	char phone [12];
	char postcode[7];
	char adder [50];
	
	struct node *next;      // �����ַ�Ľṹ��ָ�� 
	
 } mvp;                                            //����struct node���͵Ľṹ�����mvp 
 
 struct node *p1,*p2,*head;                  // ���� ָ��ṹ����struct node �����ָ�����p1,p2,head
 
 FILE *fp;                           //����һ��ָ���ļ���ָ�룬ͨ���������ָ������ļ���д����,�ر�
 void menu(){
system("cls");
 	system("color bc");                //����dos��������Dos������ɫ,ǰ��� 4���ô��ڱ�����ɫ��f ���ô���������ɫ��ǰ��          
	 
 /* 0 = ��ɫ       8 = ��ɫ
    1 = ��ɫ       9 = ����ɫ
    2 = ��ɫ       A = ����ɫ
    3 = ����ɫ     B = ��ǳ��ɫ
    4 = ��ɫ       C = ����ɫ
    5 = ��ɫ       D = ����ɫ
    6 = ��ɫ       E = ����ɫ
    7 = ��ɫ       F = ����ɫ
	 */
	 
	         
 	printf("*********                                   ***********\n");
 	printf(" **       **        $ ��ӭʹ��ͨѶ¼ $     **       **\n");
 	printf("  **       **                             **   O   **\n");
 	printf("   **   O   **      ���� �� ��ʼ��       **       **\n");
 	printf("    **       **                         **       **\n");
 	printf("     **       ***************************       **\n");
 	printf("      **                                       **\n");
 	printf("       **         1---->>>�½���ϵ��          **\n");
 	printf("        **        2---->>>��������ѯ         **\n");
 	printf("         **       3---->>>��ʾĳĳĳ        **\n");
 	printf("          **      4---->>>ɾ�����޸�       **\n");
 	printf("           **     5---->>>�˳�ͨѶ¼      **\n");
 	printf("            **    6---->>>���绰��ѯ     **\n");
 	printf("             **    0----->>>>ɾ��       **\n"); 
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
 	printf("@@------->>>>       ��ϵ����е�����      ------->>>>%%%\n");
 	printf("                                                        \n");
 	printf("***************         ͨѶ¼         ****************\n"); 
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  } 
  
  
  
  void Loading()                  ///////////////////////  //���� ��װ�� ////////////////////////////////////////////////////////////////////////////////////////////////////
  {
  	if((fp=fopen("txl.dat","rb"))==NULL)      //�жϴ��ļ��Ƿ�ɹ����ж��Զ������Ƶķ�ʽ���ļ�txl.dat���ļ�������浽fp��fp�Ƿ�Ϊ��,���Ϊ�գ����Ǵ��ļ�ʧ�ܣ�������ļ��ɹ�
  	
  	                                             
												    /*���ļ�I/O�У�Ҫ��һ���ļ���ȡ���ݣ�Ӧ�ó�������Ҫ���ò���ϵͳ�����������ļ�������ѡһ�������ļ���·�������ļ���
  	                                              
													�ú���ȡ��һ��˳��ţ����ļ������file handle�������ļ�������ڴ򿪵��ļ���Ψһ��ʶ�����ݡ�
													
													Ҫ���ļ��ж�ȡһ�����ݣ�Ӧ�ó�����Ҫ���ú���ReadFile�������ļ�������ڴ��еĵ�ַ��Ҫ�������ֽ������͸�����ϵͳ��
													
													������������ͨ������ϵͳ�������رո��ļ���__________�ļ����*/
  	
  	
	  {
	  	printf("��������");
		  Sleep(3000);
		  exit(1);          //�쳣�˳� 
	   } 
	   
	   
	   
	   p1=(struct node *)malloc(sizeof( struct node));       /*  ΪP1 �����ڴ�ռ�       
	                                                              1.sizeof(struct node )������ struct node ����ṹ��ռ�õ��ֽ�����
	   
                                                                2.  malloc(sizeof(struct node))
                                                                  ���� struct node ����ṹ��ռ���ֽ�����С�Ŀռ�
                                                                  
                                                                3. (struct node *) malloc(sizeof(struct node))
                                                                       ������Ŀռ�ĵ�ַǿ��ת��Ϊ struct node * ָ������
                                                                       
                                                                4. p1=(struct node *) malloc(sizeof(struct node))
                                                                        ���Ǹ�ǿ��ת���ĵ�ַ��ֵ�� p1.        */

 
	    
	    p1->next=NULL;                //��P1����һ���ڵ���Ϊ�� ����Ϊ������ڵ�P1��ָ����ֵΪ��ָ�� 
		head=p1;                            //��P1��Ϊͷ��� 
		
		while(!feof(fp))       //�ж��ļ�ָ���Ƿ�ﵽĩβ��û����ִ������Ĳ���
		                              
		                              //feof(file stream)�ļ�ָ�뵽���ļ�ĩβ
                                        //!feof(fp) ��ʾû�е���ĩβ
		
		                            //feof��C���Ա�׼�⺯������ԭ����stdio.h�У�
									//�书���Ǽ�����ϵ��ļ�������������ļ��������򷵻ط�0ֵ�����򷵻�0���ļ�������ֻ�ܱ�clearerr()�����������ļ�����ϵ��ļ����������൱�������������źŵ�һ�����̣� 
		                            
		{
			if(fread(p1,sizeof(struct node),1,fp)!=1)     //��fp�ж�ȡһ�������λ������sizeof(steuct node)���ֽڣ�������浽P1ָ����ڴ棻���ص�λ��������������1 �Ƚ� 
		
			break;                                         //�������ֵ��Ϊ1��������ѭ����,��ȡʧ�� 
			                                                   //fread��һ�������������ļ����ж����ݣ�����ȡcount���ÿ����size���ֽڣ�������óɹ�����ʵ�ʶ�ȡ���������,����Ϊ1 
			
			 p2=(struct node*)malloc(sizeof(struct node));
			                                            //ΪP2�����ڴ� 
			
			p2->next=NULL;                          /////������ڵ�P2��ָ����ֵΪ��ָ�� 
			p1->next=p2;            //��P1����һ��������ΪP2 
			p1=p2;                              //��p2��P1 
		 } 
		 fclose(fp);
  }
  
  
  void Tiajia()  
{     
    char ch;   
    //if((fp==fopen("txl.dat","ab+"))!=1)  //��һ�ִ򿪺��жϵķ�ʽ 
    fp=fopen("txl.dat","ab+");                //�Զ�д�ķ�ʽ�򿪶������ļ� txt.dat ,����ԭ�ļ����������ݣ������ļ�ĩβ�������
	                                           //dat,��ʽ�ĺô����ҷ��֣���Щ�ļ�����ֱ�Ӵ򿪣�Ҳ����ת�����ı��ļ����������չ���������ݣ���ȫ����TXT��ɱ��鿴 
    if(fp==NULL)
    {  
        printf("�ļ���ʧ��");  
        exit(1);  
    }  
    
    
    while(1)  
    {   system("cls");  /*����������˼�壬���������Ļ��������á�
                             ����������ʱ����Ļ������������ᱻ������൱�������ṩ��һ����������������������
                   ����һ���������¼��������
                       1 ��һ������ִ����ϣ����������Ҫ����Ҫ��ʾ�µ����ݻ��߲˵�ʱ��
                              2 ���ڼ��ܿ��ǣ�����һЩ���������Ϸ������ʾ�������������������
                                                 3 Ҫ��ʾ��ιؼ����ݣ�Ϊ����֮ǰ��ӡ��Ϣ��Ӱ�죬ִ������������
                                                    C����������һ��ʹ��
                                                                 system("cls");     */
    
    
    
    
        printf("�����롪������\n");  
        p2=(struct node*)malloc(sizeof(struct node));    //��������ڴ� 
        
        p2->next=NULL;         //��P2���¸��ڵ���Ϊ�� 
        
        printf("������");scanf("%s",mvp.name);  
        
             printf("�Ա�");scanf("%s",mvp.sex);  
        
                   printf("�绰���룺");scanf("%s",mvp.phone);  
                              printf("�ʱࣺ");scanf("%s",mvp.postcode);  
                                 printf("��ַ��");scanf("%s",mvp.adder);  
                                 
                                   strcpy(p1->name,mvp.name);  //���ṹ�������Աname��ֵ��������ַָ�� 
                                  strcpy(p1->sex,mvp.sex);  
        
                           strcpy(p1->phone,mvp.phone);  
                   strcpy(p1->postcode,mvp.postcode);  
             strcpy(p1->adder,mvp.adder);  
             
        p1->next=p2;  
        p1=p2;          
        if(fwrite(&mvp,sizeof(struct node),1,fp)!=1)            //��mvp������ָ����������뵽fp����ļ��У�
		                                                            //ÿ����������ݵ�Ԫռsizeof(struct node)���ֽڣ��ܹ����1��

                                                                    // ��������ȷ��Ӧ���Ƿ���1�ģ���Ϊfwrite����ֵ�Ƿ�����ȷ����˼������ݵ�Ԫ
                                                                  
            printf("д�����");  
            
        printf("��Enter�������--- |---- k��������");                        //������������ 
        
        getchar();  
        ch=getchar();  
        if(ch==' '||ch=='k')  
            break;  
  
    }  
    fclose(fp);  
}  


void SaCa()                    //���溯�� 
{     

   // if((fp==fopen("txl.dat","w"))!=1)       //��ֻд�ķ�ʽ���������ļ� 
   fp=fopen("txl.dat","w"); 
   if(fp==NULL)
    {  
        printf("�ļ���ʧ��");  
        exit(1);  
    }  
    
    
    p1=head;   //��P1��Ϊͷ���
	 
    while(p1->next!=NULL)    //��δ����β�����ƶ�P1ֱ��P1ָ���β 
    
    {  
        if(fwrite(p1,sizeof(struct node),1,fp)!=1)     //��P1���ָ�������ָ������������fp����ļ��У�
		                                                            //ÿ����������ݵ�Ԫռsizeof(struct node)���ֽڣ��ܹ����1��

                                                                    // ��������ȷ��Ӧ���Ƿ���1�ģ���Ϊfwrite����ֵ�Ƿ�����ȷ����˼������ݵ�Ԫ
                                                                  
        
            printf("д�����");  
        p1=p1->next;             //��P1ָ����һ���ڵ� 
          
    }   
    fclose(fp);  
}  

///////////////////////////////////////////////////////////////////��ʾ������������������������������������������//////////////////////////////////////////////////// 
void Display()                        //��ʾ���� xinxi 
{  
system("cls");
    HeadShow();  
    printf("%10s %6s  %11s %9s %16s \n","����","�Ա�","�绰","�ʱ�","��ַ");      
    printf("**************************************************************\n");  
    
    p1=head;  //��P1��Ϊͷ���
	 
    while(p1->next!=NULL)                ///////��δ����β�����ƶ�P1ֱ��P1ָ���β ���������Ǳ�β�������������Ϣ 
    {  
        printf("%10s %6s %11s %9s %16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
        
        p1=p1->next;                  ////////��P1ָ����һ���ڵ�  ,����ѭ�� 
          
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
 	printf(" **       **        $ ��ӭʹ��ͨѶ¼ $     **       **\n");
 	printf("  **       **                             **   O   **\n");
 	printf("   **   O   **            ��ʼ��         **       **\n");
 	printf("    **       **                         **       **\n");
 	printf("     **       ***************************       **\n");
 	printf("      **                                       **\n");
 	printf("       **         1---->>>��������ѯ          **\n");
 	printf("        **                                    **\n");
 	printf("         **       2---->>>���绰��ѯ         **\n");
 	printf("          **                                **\n");
 	printf("           **     5---->>>�˳�  ��ѯ      **\n");
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
{   system("cls");   //����
 
   HeadShow();  //���ú������߽з��� 
    	system("cls");
    printf("%8.8s %6.6s  %11.14s %9.8s %20s \n","����","�Ա�","�绰","�ʱ�","��ַ");      ///��������ĸ�ʽ�����Լ��ֵ���Ը������������ڣ���������ʱд��������ʽ��� 
    printf("---------------------------------------------------------------------\n");  
    
    p1=head;         ///////////////��P1��Ϊͷ���
    
    char Xingming[8];              //�������� ���ڽ�����������Ĵ洢 
    
int count=0;   //////���ڼ�¼��Ա�����ĸ�������һ����¼һ�� 
    
    printf("������Ҫ��ѯ��������");  
    scanf("%s",&Xingming);  
    printf("----------------------------\n");
    printf("��ѯ������£�\n"); 
     printf("\n");
    while(p1->next!=NULL)             ///////��δ����β�����ƶ�P1ֱ��P1ָ���β
    {  
        if(strcmp(p1->name,Xingming)==0)   // �������û�����������ͽṹ��ָ���е������Ƚϣ��������򷵻�0����strcmp�ķ���ֵ������0�Ƚϣ���������ȣ���������������ص�����ֵ 
        
            {
			printf("%8.8s %5.5s  %11.14s %9.7s %18s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  //////���ʽṹ��ָ����� P1ָ��Ľṹ��ĳ�Ա����� 
            
            count++;         //������һ�� ,��¼ͬ�����˵ĸ��� 
            }  
        p1=p1->next;     //// ////////��P1ָ����һ���ڵ�,ֱ����β ,��ֹ����ѭ�� �� /////////////////////////P1ָ��ǰ�ڵ����һ�ڵ�  
          
    }   
    printf("\n");
	printf("��  %d   ��\n",count) ; 
	printf("----------------------------------------------------\n"); //��һ���Ű� 
    system("pause");   
    return ;
}   
  
void Seekphone()  
{   system("cls");   
    HeadShow();  
    printf("%10.8s %6.6s  %11.4s %9.7s %16.6s \n","����","�Ա�","�绰","�ʱ�","��ַ");      
    printf("---------------------------------------------------------------------\n");  
    p1=head;  
    char phone[11];  
    int i=0;   
    printf("������Ҫ��ѯ�ĵ绰���룺");  
    scanf("%s",&phone);  
    printf("��ѯ������£�\n"); 
    while(p1->next!=NULL)      // ///////��δ����β�����ƶ�P1ֱ��P1ָ���β
    {  
        if(strcmp(p1->phone,phone)==0)   
        
            {printf("%10.8s %6.6s  %11.4s %9.7s %16.6s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
            i++;  
            }  
        p1=p1->next;  /////////////////////////P1ָ��ǰ�ڵ����һ�ڵ� 
          
    }   
     printf("\n");
    printf("��  %d  ��\n",i);  
    	printf("----------------------------------------------------\n");
    system("pause");   
   
}   


void End()
{
	system("cls");
	system("color 4f");
 	printf("*********                                   ***********\n");
 	printf(" **       **        $ ��ӭʹ��ͨѶ¼ $     **       **\n");
 	printf("  **       **                             **   O   **\n");
 	printf("   **   O   **            ��ʼ��         **       **\n");
 	printf("    **       **             ��          **       **\n");
 	printf("     **       ***************************       **\n");
 	printf("      **                                       **\n");
 	printf("       **                  **                   $\n");
 	printf("        **                **   л                $$\n");
 	printf("         **              **   л                    $$\n");
 	printf("          **            **                       $$\n");
 	printf("           **         **   ʹ                  $$\n");
 	printf("            **         **  ��              $$\n");
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

////////////////////////////////////////////////�޸ĺ���������������������////////////////////////////////////////////// 
void Revise()  

{ system("color ac");
	system("cls");
  char names[8];   
  
  
    system("cls");  
    HeadShow();  
    Display(); 
    int i,B=3;          ////////���ó����� B,  ���ں��������Ĳ���  
    int R;  
    p1=p2=head;    
    
   
	            
    printf("��������Ҫ�޸ĵ���ϵ��������");  
    
    scanf("%s",&names);  
    
        getchar();               ///�����û����� 
    while(p1!=NULL)  
    {     
    if(strcmp(p1->name,names)==0)               ////���û�������������Ѿ����ڵ����ݽ��бȽϣ�������ִ��������� 
    
       {    printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
       
       
       
            printf("��ȷ���޸� ����1---��$��$----2 �����\n");  
            scanf("%d",&i);  
            
            if(i==1)  
            
            { 
            
		B=1;  
			
            printf("��Ҫ�޸ĵ�ͨѶ¼Ϊ:\n");  
            printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
            printf("��ѡ�����Ĳ�����----4---ɾ��|-----5---�޸�\n");  
            scanf("%s",&R);   
               if(R=4)   
            {  
                    if(p1==head)   ////////////����P1��ͷ��㣬����ͷָ��ָ���ɾ�ڵ�P1����һ�ڵ� 
				       
                        {
				           head=p1->next;    
                                    free(p1);  
                       }  
                  else  
               {  
                p2->next=p1->next;        ////////������ǰһ�ڵ��ָ����ָ���ɾ�ڵ����һ�ڵ� 
                free(p1);     
                SaCa();     //////////////////////////////�������� 
                  
              }  
                  
            }   
               else if(R=5)  
             {  
            printf("����:");scanf("%s",p1->name);  
           /* printf("�Ա�:");scanf("%s",p1->sex);  
           
            printf("�绰:");scanf("%s",p1->phone);  
            printf("�ʱ�:");scanf("%s",p1->postcode);  
            printf("��ַ:");scanf("%s",p1->adder);    */
            SaCa();  
            
            printf("\n  OK!    \n");  
            }     
        }             
          else if(i==2)         //////////����û������޸ģ���ֱ�ӷ������˵� 
		  {
                 return ;
		   } 
       }  
    else if(strcmp(p1->name,names)&&(p1->next)==NULL)     ///////��� �ҵ���β ��û�� ֵ�����Ѿ������i��ֵ��ȡһ�� Ȼ��B ��ֵ����i��� ����ΪB�Ǳ�� 
      {
      	i==3;                         
	  }
        p2=p1;                           //////////////////////////////////////��P1��ֵ��ǰһ�ڵ�P2 
        p1=p1->next;     /////////////////////////P1ָ��ǰ�ڵ����һ�ڵ� 
    }  
  
     if(B==3)                  ///////////////B��ֵ�������ȡ�� ��i��ȼ��� 
    {  
        printf("�Բ��𣬲��޴��ˣ�������Ҫ�޸ĵ������Ƿ���ȷ\n");  
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
    
    printf("��������Ҫ�޸ĵ���Ŀ��������");  
    
    scanf("%s",&names);  
    
        getchar();    
        
    while(p1!=NULL)  
    {     
    if(strcmp(p1->name,names)==0)     
       {   
	    printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
       
       
       
            printf("��Ҫ�޸ĵ���������¼��1---��|2��\n");  
            scanf("%d",&i);  
  if(i==1)
	   {  
            printf("����:");scanf("%s",p1->name);  
            printf("�Ա�:");scanf("%s",p1->sex);  
           
            printf("�绰:");scanf("%s",p1->phone);  
            printf("�ʱ�:");scanf("%s",p1->postcode);  
            printf("��ַ:");scanf("%s",p1->adder);    
            SaCa();  
            printf("\n  OK!    \n");  
            
        }     
        else
       	
        {
        	printf("��������������˵�\n");
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
    
    printf("��������Ҫ�޸ĵ���Ŀ��������");  
    
    scanf("%s",&names);  
    
        getchar();    
        
    while(p1!=NULL)  
    {     
    if(strcmp(p1->name,names)==0)     
       {   
	    printf("%10.8s %6.6s  %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->phone,p1->postcode,p1->adder);  
       
       
       
            printf("��Ҫɾ������������¼��1---��|2��\n");  
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
        	printf("��������������˵�\n");
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

	//////////////////////////////��һ��������ɫ�ķ�ʽ 
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
    printf("-------------------���Ƕ���Ϸ�ӣ��ڱ��˵Ĺ��������Լ�������------------------\n") ; printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_INTENSITY);  
       printf("-----------��һҳҳ����ǳ��������� ����˭����֪�������------------------\n") ;printf("\n") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN);  
   printf(" --------------����̤�¶�����ֻ������ɽ�� ɽ���� ���� ������ -------------\n") ;printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN |  
                            BACKGROUND_INTENSITY);  
    printf("-------------�ҽ��ҵ�����  ������ҳ�� Ҳ���ҵİ�Ľ����������----------------\n") ;printf("\n") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE);  
     printf("------------����������껪�ٴ������Ҳû��ʲô��ڿ���ԭ���Լ���-------------\n") ;  printf("\n") ;
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE |  
                            BACKGROUND_INTENSITY);  
    printf("-------------����ԭ����û�����ֵģ�������֮ǰ�ȴ��ģ�������������-----------\n") ;  printf("\n") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN);  
    printf("---------->>>>��ϵ") ;  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN |  
                            BACKGROUND_INTENSITY);  
    printf("Ҳ��") ;  
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE);  
    printf("����") ; 
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE |  
                            BACKGROUND_INTENSITY);  
    printf("һ��") ;
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE |  
                            BACKGROUND_RED);  
     printf("��ʽ") ;  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_BLUE |  
                            BACKGROUND_RED |  
                            BACKGROUND_INTENSITY);  
    printf("@@") ;  
  
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE);  
   printf("����") ; 
    SetConsoleTextAttribute(hOut,  
                            BACKGROUND_RED |  
                            BACKGROUND_GREEN |  
                            BACKGROUND_BLUE |  
                            BACKGROUND_INTENSITY);  
     printf("��----->>>>>") ;  
    
  
  Sleep(1000);
    	
	
	system("cls");
		system("color e4");
		printf("\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("***************         ͨѶ¼         ****************\n");
					printf("\n");
		printf(" @@------->>>>       ��ϵ����е�����      ------->>>>%%%\n");
 	printf("                                                        \n");
 	printf("***************        ������ʼ��        ****************\n"); 
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("\n");printf("\n");printf("\n");
	
	printf("---------------------���ϣ�槼�������\n");
	
	printf("\n") ;
		printf("--------------------��ϻ��������Ƕ���\n");
	
	int loop;
	
	char password[13];                 //Ϊ������ַ���Ԥ��һ��������־λ 
	
	printf("\n input the password(6~12characters):");
	
	for(loop=0;loop<MAX;loop++)                  ///����ѭ�� 
	{
		password[loop]=getch();                //�������� 
		
		printf("*");                       //���ǺŴ��������ַ���ʾ 
		
		if(password[loop]=='\x0d')                 //�س�������������� 
		{
			if(loop<MIN)
			{
				printf("\n The length the password is less than 6,press any  key to contine....");
				
				getch();                   //��ͣ������������� 
				
				printf("\n Please input the password agin(6~12):");
				
				loop=-1;                // ִ��loop++��ʹ�±긴λΪ0 
			}
			else
			{
				password[loop]='\0';                  //�������������־ 
				break;
			}
		}
		if(loop==MAX-1)                //���볤�ȴﵽ���ֵ 
		password[loop]='\0';                //�������봮������־ 
		
		
		
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
    if((fp=fopen("txl.dat","ab"))==NULL)  ///////////////////�ж���ֻд�ķ�ʽ�򿪶������ļ�txl.dat���ļ�������浽fp��fp�Ƿ�Ϊ��,���Ϊ�գ����Ǵ��ļ�ʧ�ܣ�������ļ��ɹ�
    {  
        printf("�ļ��������������Ƿ���Ȩ�޲����ļ���");  
        Sleep(3000);  
        exit(1);  
    }  
    fclose(fp);   
    Loading();  
    while(1)
	{  
    menu();  
    
    gets(a);                           //��ȡ�û����� 
    demo=atoi(a);  /* ���ַ�ת��Ϊ����    �����ҽ�ֵ����deno 
	   atoi (��ʾ ascii to integer)�ǰ��ַ���ת������������һ��������Ӧ���ڼ��������Ͱ칫����С�
	             atoi( ) ������ɨ����� nptr�ַ���������ǰ��Ŀհ��ַ�������ո�tab�����ȡ�
                         �� ��ͨ��isspace( )��������⣩��ֱ���������ֻ��������Ųſ�ʼ��ת����
                  �������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�
                        ��� nptr����ת���� int ���� nptrΪ���ַ�������ô������ 0[1]  ��    
						 
						
					vs2013�����printf������ʹ��Ԥ��������#define _CRT_SECURE_NO_WARNINGS
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
�����
n = 12345

��2��
//vs2013�����printf������ʹ��Ԥ��������#define _CRT_SECURE_NO_WARNINGS
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
ִ�н����
c = 23  */
  
      if(demo==1)                 ///////////////////���Ϊ1������غ��� 
      
         {
      system("cls");
          Tiajia() ; 
          }
else

switch(demo)             ////////////////����switch ������ֵ�������˵�����ʾ���룬���к������� 
{
	///case 0:Dele() ;break;
	case 2: Lookname(); break;
	
	case 6: Seekphone();break;
	
	case 3:Display();	Sleep(1000);
	break;;
	
	case 4:Revise()  ; break;
	
	case 5:End();   
	Sleep(1000);  
        exit(0);               ////////���ú������ú�������˳� 
	break;

	
}
 	
}
 
}


