#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int N=30;
const int M=50;
typedef struct name   //名字结构体
{
    char name[30];
    int v;   //ascll码值之和
}Name;

Name name[30];

typedef struct hashs   //哈希表结构体
{
    char name[30];   //名字
    int key;   //关键字
    int cnt;   //哈希表中含有的元素个数
}Hash;

Hash HASH[50];

/*
int my_toasscii(char* str)
{
    int len=strlen(str);
    int cnt=0;
    for(int i=0;i!=len;i++)
    {
        //return toasscii(str[i]);
        return cnt+=(str[i]-'a');
    }
}*/

void init()   //初始化
{
    int i,j,cnt;
    for(i=0; i<N; i++)
    {
        name[i].v=0;
        strcpy(name[i].name,"0");
    }
    strcpy(name[0].name,"Lvyunfan");
    strcpy(name[1].name,"HuangYuntong");
    strcpy(name[2].name,"RenHao");
    strcpy(name[3].name,"ChenChunhan");
    strcpy(name[4].name,"MiJishi");
    strcpy(name[5].name,"ZhengJunjie");
    
    strcpy(name[6].name,"LiuBoshuai");
    strcpy(name[7].name,"GaoDongdong");
    strcpy(name[8].name,"JiaSen");
    strcpy(name[9].name,"JiangSichen");
    strcpy(name[10].name,"YangShaojie");

    strcpy(name[11].name,"WuDihao");
    strcpy(name[12].name,"MaYushen");
    strcpy(name[13].name,"GuoHengxing");
    strcpy(name[14].name,"ChenJiashuo");
    strcpy(name[15].name,"HouZihan");

    strcpy(name[16].name,"SongYuhang");
    strcpy(name[17].name,"FuTianyao");
    strcpy(name[18].name,"ZhangYuankun");
    strcpy(name[19].name,"WuXuanzhang");
    strcpy(name[20].name,"WangYili");

    strcpy(name[21].name,"HanZhongding");
    strcpy(name[22].name,"QiChenyang");
    strcpy(name[23].name,"LiuJia");
    strcpy(name[24].name,"ZhaoXiangdong");
    strcpy(name[25].name,"ZhangYi");

    strcpy(name[26].name,"ZhangYaoTian");
    strcpy(name[27].name,"ZhangHang");
    strcpy(name[28].name,"SunXiaoyu");
    strcpy(name[29].name,"HeMinghao");
    for(i=0; i<30; i++)
    {
        cnt=0;
        for(j=0; j<strlen(name[i].name); j++)
        {
            cnt=cnt+(name[i].name[j]-'A');
        }
        //int cnt=my_toasscii(name[i].name);

        
        name[i].v=cnt;   //名字字母ascll码之和
    }
}
void creathash()    //构造哈希表
{
    int i;
    int n,m,counts;
    for(i=0; i<50; i++)
    {
        strcpy(HASH[i].name,"0");
        HASH[i].key=0;
        HASH[i].cnt=0;
    }


    for(i=0; i<30; i++)
    {
        counts=1;
        //srand(40);
        n=(name[i].v)%41;
        //srand(13);
        //n=(name[i].v+rand())%30;

        m=n;
        if(HASH[n].cnt==0)   //不冲突
        {
            strcpy(HASH[n].name,name[i].name);
            HASH[n].key=name[i].v;
            HASH[n].cnt=1;
        }
        else   //如果发生了冲突
        {
            while(1)
            {
                //srand(40);
                m=(m+1)%41;
                //m=(m+1)%30;
                counts++;
                if(HASH[m].key==0)
                {
                    break;
                }
            }
            strcpy(HASH[m].name,name[i].name);
            HASH[m].key=name[i].v;
            HASH[m].cnt=counts;
        }
    }
    return ;
}
void searchhash()
{
    char name[30];
    int i,cnt,n,m,counts;
    cnt=0;
    n=0;
    counts=1;
    printf("请输入要查找人的姓名拼音：\n");
    scanf("%s",name);
    for(i=0; i<strlen(name); i++)
    {
        cnt+=(name[i]-'A');
    }
    srand(13);
    n=cnt%41;
    //n=cnt%30;
    m=n;
    if(strcmp(HASH[n].name,name)==0)
    {
        printf("姓名:%s 关键字:%d 查找长度:%d\n",HASH[n].name,cnt,counts);
    }
    else if(HASH[n].cnt==0)
    {
        printf("没有找到\n");
    }
    else
    {
        while(1)
        {
            //m=(m+1)%30;
            //srand(40);
            //srand(2);
            m=(m+rand())%41;
            counts++;

            if(strcmp(HASH[m].name,name)==0)
            {
                printf("姓名:%s 关键字:%d 查找长度:%d\n",HASH[m].name,cnt,counts);
                break;
            }
            if(HASH[m].key==0)
            {
                printf("没有找到\n");
                break;
            }
        }
    }
}
void displayhash()   //演示哈希表
{
    int i,cnt;
    float ave;
    ave=0.0;
    cnt=0;
    printf("\n地址\t\t关键字\t\t搜索长度\t姓名\n");
    for(i=0; i<50; i++)
    {
        printf("%d",i);
        printf("\t\t%d",HASH[i].key);
        printf("\t\t%d",HASH[i].cnt);
        printf("\t\t%s",HASH[i].name);
        printf("\n");
    }
    for(i=0; i<50; i++)
    {
        cnt+=HASH[i].cnt;
    }
    ave=((cnt)*1.0)/30;
    printf("\n");
    printf("平均查找长度ASL(%d)=%.3lf\n",30,ave);
    return ;
}
void display()
{
    int i;
    for(i=0; i<30; i++)
    {
        printf("关键字\t\t姓名\n");
        printf("%d\t\t",name[i].v);
        printf("%s\n",name[i].name);
    }
    return ;
}

int main()
{
    printf("\n\n");
    init();
    creathash();
    printf("展示姓名和关键字\n");

    display();
    printf("展示哈希表\n");
    displayhash();

    printf("\n");
    printf("\n");
    printf("查找关键字\n");
    searchhash();
}

