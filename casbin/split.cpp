#include <string>
#include <vector>
#include <iostream>
#include <string_view>

#define LARGE 2147483647

using namespace std;
/*
void split(const string& src, const string& separator, vector<string>& dest)
{
    string str = src;
    string substring;
    string::size_type start = 0,index;
 
    do
    {
        index = str.find_first_of(separator,start);
        if (index != string::npos)
        {
            substring = str.substr(start,index-start);
            dest.push_back(substring);
            start = str.find_first_not_of(separator,index);
            if (start == string::npos) return;
        }
    }while(index != string::npos);
 
    //the last token
    substring = str.substr(start);
    dest.push_back(substring);
}*/

/*void split(const string& src,const string& delimiters,vector<string>& dest)
{
    string::size_type lastPos=src.find_first_not_of(delimiters,0);
    string::size_type pos=src.find_first_of(delimiters,lastPos);
    while(string::npos != pos || string::npos != lastPos) {
        dest.emplace_back(src.substr(lastPos,pos-lastPos));
        lastPos=src.find_first_not_of(delimiters,pos);
        pos=src.find_first_of(delimiters,lastPos);
        
    }
}*/

/*void split(const string& src,const string& delimiters="",vector<string>& dest)
{
    string::size_type start=src.find_first_not_of(delimiters,0);
    
    string::size_type pos=src.find_first_of(delimiters,start);
    
    cout<<start<<pos<<endl;
    while(string::npos != pos || string::npos != start) {
        dest.emplace_back(src.substr(start,pos-start));
        //cout<<"1:"<<dest[0].c_str()<<endl;
	//cout<<"2"<<dest[1].c_str()<<endl;
    	//cout<<"3"<<dest[2].c_str()<<endl;
	
	start=src.find_first_not_of(delimiters,pos);
        pos=src.find_first_of(delimiters,start);
	cout<<start<<pos<<endl;

    }

    //dest.emplace_back(src.substr(start,pos-start));
}*/

void split(string_view src,string_view delimiters,vector<string_view>& dest)
{
    string_view ::size_type start=0;

    while(start<src.size()) {
        string_view ::size_type pos=src.find_first_of(delimiters,start);

        if(pos!=start)
            dest.emplace_back(src.substr(start,pos-start));

        if(pos==string_view::npos)
            break;
        start=src.find_first_not_of(delimiters,pos);
    }
}
int main()
{
	string key="other::key1::key2";
	vector<string_view> k;
	
	split(key,"::",k);
	//split(key,"::",k);
	/*for (auto it=0;it<key.size();it++)
       	{
                //vector<string> k;
		split(it,"::",k);

	}*/
	for(auto it2:k)
	{
		cout<<it2<<endl;
	}

}
