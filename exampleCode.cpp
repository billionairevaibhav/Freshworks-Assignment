// This is example code which shows how you can interct with this dataStore library


#include "dataStore.h"
int main()
{
    Create("1",{{"Name","vaibahv"},{"aim","nothing"}},100);

    cout<<'\n';
    Read("1");
    cout<<'\n';

    Delete("1");
    cout<<'\n';

    Read("1");
    cout<<'\n';

    Create("vab",{{"Name","Vaibhav"},{"Coolege","Graphic Era University"}},60);
    cout<<'\n';

    Create("123",{{"CusId",24},{"Amount",2398}});
    cout<<'\n';

    Create("123",{{"CusId",128},{"Amount",10000}});
    cout<<'\n';

    Create("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",{{"Model","12"},{"Price",250000}});
    cout<<'\n';

    Read("vab");
    cout<<'\n';





}