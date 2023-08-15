#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
    /* data */
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};
void PAUSE()
{
    cout << "Press Enter to continue...\n";
    cin.get();
    cin.get();
    return;
}
void addPerson(Addressbooks *abs)
{

    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满\n";
        return;
    }
    string name;
    cout << "请输入一个姓名: \n";
    cin >> name;
    abs->personArray[abs->m_Size].m_Name = name;

    cout << "请输入一个性别: \n";
    cout << "1男2女\n";
    int sex = 0;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->personArray[abs->m_Size].m_Sex = sex;
            break;
        }
        else
        {
            cout << "输入有误, 请重新输入\n";
        }
    }
    int age = 0;
    cout << "请输入年龄: \n";
    cin >> age;
    abs->personArray[abs->m_Size].m_Age = age;

    string phone;
    cout << "请输入一个电话号码: \n";
    cin >> phone;
    abs->personArray[abs->m_Size].m_Phone = phone;

    string addr;
    cout << "请输入一个地址: \n";
    cin >> addr;
    abs->personArray[abs->m_Size].m_Addr = addr;

    abs->m_Size += 1;
    cout << "添加成功\n";
    system("clear");
    return;
}
void showPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "通讯录为空\n";
        return;
    }
    for (int i = 0; i < abs->m_Size; ++i)
    {
        cout << "姓名: " << abs->personArray[i].m_Name << "\t";
        cout << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄: " << abs->personArray[i].m_Age << "\t";
        cout << "电话: " << abs->personArray[i].m_Phone << "\t";
        cout << "地址: " << abs->personArray[i].m_Addr << "\n";
    }
    PAUSE();
    system("clear");
    return;
}
void showMenu()
{
    cout << "******************************\n";
    cout << "***** 1.添加联系人 *****\n";
    cout << "***** 2.显示联系人 *****\n";
    cout << "***** 3.删除联系人 *****\n";
    cout << "***** 4.查找联系人 *****\n";
    cout << "***** 5.修改联系人 *****\n";
    cout << "***** 6.清空联系人 *****\n";
    cout << "***** 0.退出通讯录 *****\n";
    cout << "******************************\n";
}
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; ++i)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}
void deletePerson(Addressbooks *abs)
{

    cout << "输入删除的联系人\n";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "没查到\n";
    }
    else
    {
        for (int i = ret; i < abs->m_Size; ++i)
        {

            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size -= 1;
    }
    PAUSE();
    system("clear");
    return;
}
void findPerson(Addressbooks *abs)
{
    cout << "查找联系人\n";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
        cout << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
        cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
        cout << "地址: " << abs->personArray[ret].m_Addr << "\n";
    }
    else
    {
        cout << "没找到\n";
    }
    PAUSE();
    system("clear");
}
void modifyPerson(Addressbooks *abs)
{
    cout << "输入联系人名字\n";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "请输入一个姓名: \n";
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入一个性别: \n";
        cout << "1男2女\n";
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误, 请重新输入\n";
            }
        }
        int age = 0;
        cout << "请输入年龄: \n";
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        string phone;
        cout << "请输入一个电话号码: \n";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        string addr;
        cout << "请输入一个地址: \n";
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;
    }
    else
    {
        cout << "没找到\n";
    }
    PAUSE();
    system("clear");
}
void clearPerson(Addressbooks *abs){

    abs->m_Size = 0;
    cout << "通讯录已清空\n";
    PAUSE();
    system("clear");
    return;
}
int main()
{
    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1: // 添加联系人
            addPerson(&abs);
            break;
        case 2: // 显示联系人
            showPerson(&abs);
            break;
        case 3: // 删除联系人
            deletePerson(&abs);
            break;
        case 4: // 查找联系人
            findPerson(&abs);
            break;
        case 5: // 修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 清空联系人
            clearPerson(&abs);
            break;
        case 0:
            cout << "欢迎下次使用\n";
            return 0;
            break;
        default:
            break;
        }
    }

    // system("pause");
    return 0;
}