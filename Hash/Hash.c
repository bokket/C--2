#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Name   
{
    char name[30];
    int v;   
}Name;

Name name[30];



typedef struct
{
    char value[30];   
    int key;   
    int cnt;   
}Hash;

Hash hash[100];

void init()  
{
    int i,j,cnt;
    
    for(i=0; i<30; i++)
    {
        name[i].v=0;
        strcpy(name[i].name,"\0");
    }
    

    /*char m_name[30]={ "LvYunfan", "HuangYuntong", "RenHao", "ChenChunhan", "MiJishi", "ZhengJunjie",
        "LiuBoshuai", "GaoDongdong", "JiaSen", "JiangSichen", "YangShaojie", "WuDihao",
        "MaYushen", "GuoHengxing", "ChenJiashuo", "HouZihan", "SongYuhang", "FuTianyao",
        "ZhangYuankun", "WuXuanzhang", "WangYili", "HanZhongding", "QiChenyang", "LiuJia",
        "ZhaoXiangdong", "ZhangYi", "ZhangYaoTian", "ZhangHang", "SunXiaoyu", "HeMinghao"};
*/
   
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
    strcpy(name[18].name, "ZhangYuankun");
    strcpy(name[19].name,"WuXuanzhang");
    strcpy(name[20].name,"WangYili");
    strcpy(name[21].name,"HanZhongding");
    strcpy(name[22].name,"QiChenyang");
    strcpy(name[23].name,"LiuJia");
    strcpy(name[24].name, "ZhaoXiangdong");
    strcpy(name[25].name,"ZhangYi");
    strcpy(name[26].name,"ZhangYaoTian");
    strcpy(name[27].name,"ZhangHang");
    strcpy(name[28].name,"SunXiaoyu");
    strcpy(name[29].name,"HeMinghao");


    for(i=0; name[i].name; i++)
    {
        cnt=0;
        for(j=0; j<strlen(name[i].name); j++)
        {
            cnt=cnt+(name[i].name[j]-'a');
        }
        //cnt=cnt+toascii(name[i].name);
        name[i].v=cnt;   //名字字母ascll码之和
    }
}



void creathash()    
{
    int i;
    int n,m,counts;
    for(i=0; i<50; i++)
    {
        strcpy(hash[i].value,"0");
        hash[i].key=0;
        hash[i].cnt=0;
    }
    for(i=0; i<30; i++)
    {
        counts=1;
        n=(name[i].v)%31;
        m=n;

        if(hash[n].cnt==0)   //不冲突
        {
            strcpy(hash[n].value,name[i].name);
            hash[n].key=name[i].v;
            hash[n].cnt=1;
        }
        else   //如果发生了冲突
        {
            while(1)
            {
                m=(m+1)%31;
                counts++;
                if(hash[m].key==0)
                {
                    break;
                }
            }
            strcpy(hash[m].value,name[i].name);
            hash[m].key=name[i].v;
            hash[m].cnt=counts;
        }
    }
    return ;
}
void searchhash()
{
    char Name[30];
    int i,cnt,n,m,counts;
    cnt=0;
    n=0;
    counts=1;
    printf("请输入要查找人的姓名拼音：\n");
    scanf("%s",Name);
    
    //cnt+=toascii(&Name);
    for(i=0; i<strlen(Name); i++)
    {
        cnt+=(Name[i]-'a');
    }


    n=cnt%31;
    m=n;
    if(strcmp(hash[n].value,Name)==0)
    {
        printf("姓名:%s 关键字:%d 查找长度:1\n",hash[n].value,cnt);
    }
    else if(hash[n].cnt==0)
    {
        printf("没有找到\n");
    }
    else
    {
        while(1)
        {
            m=(m+1)%31;
            counts++;
            if(strcmp(hash[m].value,Name)==0)
            {
                printf("姓名:%s 关键字:%d 查找长度:%d\n",hash[m].value,cnt,counts);
                break;
            }
            if(hash[m].key==0)
            {
                printf("没有找到\n");
                break;
            }
        }
    }
}
void displayhash()   
{
    int i,cnt;
    float ave;
    ave=0.0;
    cnt=0;
    printf("\n地址\t\t关键字\t\t搜索长度\t\t姓名\n");
    for(i=0; i<100; i++)
    {
        printf("%d",i);
        printf("\t\t%d",hash[i].key);
        printf("\t\t%d",hash[i].cnt);
        printf("\t\t%s",hash[i].value);
        printf("\n");
    }
    for(i=0; i<100; i++)
    {
        cnt+=hash[i].cnt;
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
        printf("\n\t姓名\t\t关键字\n");
        printf("\t%s",name[i].name);
        printf("\t%d",name[i].v);
    }
    return ;
}
int main()
{
    printf("\n\n");
    init();
    creathash();
    printf("展示姓名拼音和关键字\n");

    display();
    printf("展示哈希表\n");
    displayhash();

    printf("\n");
    printf("\n");
    printf("查找关键字\n");
    searchhash();
}