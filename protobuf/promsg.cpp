//
// Created by bokket on 2020/12/11.
//

#include <assert.h>
#include <iostream>
#include "msg.pb.h"

using namespace std;

int main()
{
    test_2::student student_;

    cout << "类所占字节数 = "
         << student_.ByteSize()
         << endl;

    //对于int类型的只提供获取,修改和清楚三个API
    student_.set_stamp(123); //生成的API都是小写

    //消息中的自定义类型,并没有set借口,而是要通过mutable_*接口
    //来得到对应指针进而去进行操作
    auto usrLoginPtr = student_.mutable_usrlogin();
    auto usrInfoPtr = student_.mutable_usrinfo();

    string name("lzj");
    string passwd("123456");
    usrLoginPtr->set_usrname(name);
    usrLoginPtr->set_usrpasswd(passwd);

    string id("04161027");
    usrInfoPtr->set_classrome(5);
    usrInfoPtr->set_studentid(id);

    cout << "未初始化前array长度 = "
         << student_.arr_size()
         << endl;


    for (int i = 0; i < 5; i++)
    {
        //对于repeated的类型,add_*()接口增加一条记录
        //该接口返回一个指向该条记录的指针,用来做相关操作
        //我这里只是简单的里面一个int
        auto arrPtr = student_.add_arr();
        arrPtr->set_id(i);
    }

    //将其转化为字符串
    //即可用在网络编程通信时
    string buff;
    //序列化为字符串
    bool isSucceed = student_.SerializePartialToString(&buff);
    assert(isSucceed == true);


    /*********parsing***************/
    test_2::student res;
    //反序列化
    isSucceed = res.ParseFromString(buff);
    assert(isSucceed == true);

    cout << "student`s STAMP = "
         << res.stamp()
         << endl;

    usrLoginPtr = res.mutable_usrlogin();
    cout << "usrLogin`s usrname = "
         << usrLoginPtr->usrname()
         << endl;
    cout << "usrLogin`s usrpasswd = "
         << usrLoginPtr->usrpasswd()
         << endl;

    usrInfoPtr = res.mutable_usrinfo();
    cout << "usrInfo`s classrome = "
         << usrInfoPtr->classrome()
         << endl;
    cout << "usrInfo`s studentID = "
         << usrInfoPtr->studentid()
         << endl;

    //遍历数组
    for (int i = 0; i < res.arr_size(); i++)
    {
        //获得一个该下标的元素的引用
        //返回值为const类型的,不能通过该返回值去进行修改
        auto tmpPtr = res.arr(i);
        cout << "arr["
             << i
             << "] = "
             << tmpPtr.id()
             << endl;
    }
    cout << endl;

    //返回下标为2的数组元素的指针
    auto tmpArr = res.mutable_arr(2);
    //改变其值
    tmpArr->set_id(99);
    for (int i = 0; i < res.arr_size(); i++)
    {
        auto tmpPtr = res.arr(i);
        cout << "arr["
             << i
             << "] = "
             << tmpPtr.id()
             << endl;
    }
}

