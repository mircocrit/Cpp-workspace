#include "linked_list.h"
#include <iostream>
#include "funzioni.h"

using namespace std;

int main(){
  Linked_list<int> list,list2;
  string value="";

  int s[10]={19,41,52,35,32,31,13,13,45,46};


  Linked_list<int>::position r=list.begin();
  for(int i=0;i<10;i++){
  	  list.insert(s[i], r);
    }
  cout << list<<endl;

  int z[8]={13,56,35,342,31,18,1,45};

  Linked_list<int>::position z_pos=list2.begin();
   for(int i=0;i<8;i++){
    	  list2.insert(z[i], z_pos);
     }
   cout << list2<<endl;



   delete_from(list,list2);
   cout << list<<endl;


  //exchange(list,list.begin(),list.last());
 // cout << list<<endl;


  ric_min_max(list);
  cout << list<<endl;


  cout<<(list!=list2)<<endl;

  //clear(list);
  cout << list<<endl;

  system("pause");
  return 0;

}
