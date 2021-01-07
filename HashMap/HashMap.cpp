//
// Created by bokket on 2021/1/7.
//

#include "HashMap.h"

inline int Hash(int key)
{
    return key;
}

inline int Hash(const char* key)
{
    int nkey=0;
    int nlen=strlen(key);
    for(int i=0;i<len;i++)
        nkey+=key[i];
    return nkey;
}

template<typename KEY,typename VALUE>
HashMap<KEY,VALUE>::HashMap<typename KEY, typename VALUE>()
{
    m_pMap=NULL;
    m_TableSize=0;
    m_Count=0;
}

template<typename KEY,typename VALUE>
HashMap<KEY,VALUE>::~HashMap<KEY, VALUE>()
{

}

template<typename KEY,typename VALUE>
void HashMap<KEY,VALUE>::InitHashMap(int size)
{
    m_TableSize=size;
    m_pMap=new HashMapNode<KEY,VALUE>* [size];
    memset(m_pMap,0,sizeof(HashMapNode<KEY,VALUE>*)*size);
}

template<typename KEY,typename VALUE>
void HashMap<KEY,VALUE>::set(KEY key, VALUE value)
{
    unsigned int hash;
    HashMapNode<KEY,VALUE> *pNewNode=new HashMapNode<KEY,VALUE>();
    HashMapNode<KEY,VALUE> *pFindNode=GetNode(key,hash);


    if(pFindNode==NULL)
    {
        pNewNode->m_key=key;
        pNewNode->m_vaule=value;

        if (m_pMap[hash] == NULL)
        {
            m_pMap = pNewNode;
        }
        else
        {
            pNewNode->m_pnext = m_pMap[hash]->m_pnext;
            m_pMap[hash]->m_pnext = pNewNode;
        }
        m_Count++;
    }
    else
    {
        pFindNode->m_vaule=value;
    }
}

template<typename KEY,typename VALUE>
void HashMap<KEY,VALUE>::del(KEY key, VALUE value)
{
}

template<typename KEY,typename VALUE>
bool HashMap<KEY,VALUE>::get(KEY key, VALUE &value)
{
    unsigned int hash;
    HashMapNode<KEY,VALUE>* pNode=GetNode(key,hash);

    if(pNode==NULL)
        return false;

    value=pNode->m_vaule;
    return true;
}

template<typename KEY,typename VALUE>
HashMapNode<KEY, VALUE> * HashMap<KEY,VALUE>::GetNode(KEY key, unsigned int &uHash)
{
    uHash=Hash(key)%m_TableSize;

    HashMapNode<KEY,VALUE>* pFind=m_pMap[uHash];
    if(pFind==NULL)
        return NULL;

    HashMapNode<KEY,VALUE>* pCurNode=pFind;
    while(pCurNode!=NULL)
    {
        if(pCurNode->m_key==key)
            return pCurNode;

        pCurNode=pCurNode->m_pnext;
    }
    return NULL;
}