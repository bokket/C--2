//
// Created by bokket on 2021/1/3.
//

#ifndef C_2_CONFIG_H
#define C_2_CONFIG_H

#include <memory>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <yaml-cpp/yaml.h>
#include "./log/log.h"

using namespace std;
namespace bokket
{


class ConfigVarBase
{
public:
    typedef shared_ptr<ConfigVarBase> ptr;
public:
    ConfigVarBase(const string& name,const string & description="")
                :m_name(name)
                ,m_description(description)
    {
        transform(m_name.begin(),m_name.end(),m_name.begin(),::tolower);
    }

    virtual ~ConfigVarBase() {}

    const string & getName() const { return m_name; }
    const string & getDescription() const { return m_description; }

    virtual string toString() =0;
    virtual bool fromString(const string& val)=0;
protected:
    string m_name;
    string m_description;
};

template<class T>
class ConfigVar: public ConfigVarBase
{
public:
    typedef shared_ptr<ConfigVar> ptr;
public:
    ConfigVar(const string & name,const T & default_value, const string description="")
            :ConfigVarBase(name,description)
            ,m_val(default_value)
    {}

    string toString() override;

    bool bool fromString(const string &val) override;

    const T getValue() const { return m_val; }
    void setValue(const T& v) { m_val=v; }

private:
    T m_val;
};

class Config
{
    
};
}


#endif //C_2_CONFIG_H
