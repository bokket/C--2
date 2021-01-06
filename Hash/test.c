#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
    char* key;
    char* value;
}ht_item;

typedef struct
{
    int size;
    int count;
    ht_item** items;
}ht_hash_table;



static ht_item HT_DELETED_ITEM={NULL,NULL};
static const int HT_PRIME_1 = 151;
static const int HT_PRIME_2 = 163;



static ht_item *ht_new_item(const char* k,const char* v)
{
    ht_item* i=(ht_item*)malloc(sizeof(ht_item));

    i->key=strdup(k);
    i->value=strdup(v);
}

ht_hash_table * ht_new()
{
    ht_hash_table* ht=(ht_hash_table*)malloc(sizeof(ht_hash_table));

    ht->size=53;
    ht->count=0;
    ht->items=calloc((size_t)ht->size,sizeof(ht_item*));

    return ht;
}

static void ht_del_item(ht_item* i)
{
    free(i->key);
    free(i->value);
    free(i);
}


void ht_del_hash_table(ht_hash_table* ht)
{
    for(int i=0;i<ht->size;i++)
    {
        ht_item *item=ht->items[i];
        if(item!=NULL && item!=&HT_DELETED_ITEM  )
            ht_del_item(item);
    }
    free(ht->items);
    free(ht);
}

static int ht_hash(const char* s,const int a,const int m)
{
    long hash=0;
    const int len_s=strlen(s);
    for(int i=0;i<len_s;i++)
    {
        hash+=(long )pow(a,len_s-(i+1))*s[i];
        hash=hash%m;
    }
    return (int)hash;
}


static int ht_get_hash(const char* s,const int num_buckes,const int attempt)
{
    const int hash_a=ht_hash(s,HT_PRIME_1,num_buckes);
    const int hash_b=ht_hash(s,HT_PRIME_2,num_buckes);

    return (hash_a+(attempt*(hash_b+1)))%num_buckes;
}




void ht_insert(ht_hash_table* ht,const char* key,const char* value)
{
    ht_item *item=ht_new_item(key,value);
    int index=ht_hash(item->key,ht->size,0);

    ht_item *cur_item=ht->items[index];

    int i=0;
    //while(cur_item!=NULL)
    while(cur_item!=NULL)
    {
        if(cur_item!=&HT_DELETED_ITEM)
        {
            if(strcmp(cur_item->key,key)==0)
            {
                ht_del_item(cur_item);
                ht->items[index]=item;
                return ;
            }
        }
        index=ht_hash(item->key,ht->size,i);
        cur_item=ht->items[index];
        i++;
    }

    ht->items[index]=item;
    ht->count++;
}

//搜索类似于插入，但是在循环的每次迭代中while，我们都会检查项目的键是否与我们要搜索的键匹配。
// 如果是这样，我们将返回该项目的值。如果while循环失败了NULL，我们将返回 NULL，表明未找到任何值。

char* ht_search(ht_hash_table* ht,const char* key)
{
    int index=ht_hash(key,ht->size,0);
    ht_item *item=ht->items[index];
    int i=1;

    while(item!=NULL)
    {
        if(item!=&HT_DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                return item->value;
            }
        }
        index=ht_hash(key,ht->size,1);
        item=ht->items[index];
        i++;
    }
    return NULL;
}


//从打开的寻址哈希表中删除要比插入或搜索复杂得多。我们希望删除的项目可能是碰撞链的一部分。
// 将其从桌子上移开将破坏该链，并使在链尾无法找到物品。为了解决这个问题，我们不删除项目，而只是将其标记为已删除。


void ht_delete(ht_hash_table* ht,const char* key)
{
    int index=ht_hash(key,ht->size,0);
    ht_item *item=ht->items[index];

    int i=1;
    while(item!=NULL && item!=&HT_DELETED_ITEM)
    {
        if(strcmp(item->key,key)==0)
        {
            ht_del_item(item);
            ht->items[index]=&HT_DELETED_ITEM;
            ht->count--;
        }
        index=ht_hash(key,ht->size,i);
        item=ht->items[index];
        i++;
    }
    //ht->count--;
}

int main()
{
    ht_hash_table * ht=ht_new();

    //int count=0;
    static char *key= {
        "LvYunfan", "HuangYuntong", "RenHao", "ChenChunhan", "MiJishi", "ZhengJunjie",
        "LiuBoshuai", "GaoDongdong", "JiaSen", "JiangSichen", "YangShaojie", "WuDihao",
        "MaYushen", "GuoHengxing", "ChenJiashuo", "HouZihan", "SongYuhang", "FuTianyao",
        "ZhangYuankun", "WuXuanzhang", "WangYili", "HanZhongding", "QiChenyang", "LiuJia",
        "ZhaoXiangdong", "ZhangYi", "ZhangYaoTian", "ZhangHang", "SunXiaoyu", "HeMinghao"
    };

    for(int i=0;i<30;i++)
    {
        ht_insert(ht,key[i],"key");
    }

    printf("-------------");

   // ht_del_hash_table(ht);
}
