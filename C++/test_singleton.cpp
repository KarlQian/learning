#include "singleton.hpp"
int main(){
    cout <<"begin"<<endl;
    using namespace cc;
    SingleTon* p1 = SingleTon::getinstance();
    SingleTon* p2 = SingleTon::getinstance();
    SingleTon* p3 = SingleTon::getinstance();
    printf("p1= %p\n",p1);
    printf("p3= %p\n",p2);
    printf("p4= %p\n",p3);
    SingleTon::destoryInstance();
    SingleTon::destoryInstance();
    SingleTon::destoryInstance();
    cout <<"end"<<endl;

}
