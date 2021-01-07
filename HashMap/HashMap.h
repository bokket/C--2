//
// Created by bokket on 2021/1/7.
//

#ifndef C_2_HASHMAP_H
#define C_2_HASHMAP_H

#include <string.h>
#define HASH_MAP_SIZE sizeof(CHashMapNode<KEY,VALUE>*)


template <typename KEY,typename VALUE>
struct HashMapNode
{
    HashMapNode()
    {
        m_pnext=NULL;
    }
    KEY m_key;
    VALUE m_vaule;
    HashMapNode<KEY,VALUE> *m_pnext;
};

template <typename KEY,typename VALUE>
class HashMap
{
public:
    HashMap();
    virtual ~HashMap();

public:
    void InitHashMap(int size);
    void set(KEY key,VALUE value);
    void del(KEY key,VALUE value);
    bool get(KEY key,VALUE& value);

private:
    HashMapNode<KEY,VALUE>* GetNode(KEY key,unsigned int & uHash);

private:
    HashMapNode<KEY,VALUE> **m_pMap;
    int m_TableSize;
    int m_Count;
};



#endif //C_2_HASHMAP_H
