#include <iostream>

using namespace std;
// BUOC 1  tao cau truc node
struct node
{
    int data;
    node* pnext;
};
// BUOC 2: khoi tao node
node* initnode(int value)//ordata)
{
  node* p = new node;
  p->data = value;
  p->pnext = NULL;
  return p;
}
// BUOC 3: tao cau truc list
struct List
{
    node* phead;
    node* ptail;
};
// BUOC 4: khoi tao list
void initlist(List &l)
{   l.phead = NULL;
    l.ptail = NULL;

}
void addhead(List& l, node* p)
{
    if(l.ptail == NULL)
    { l.phead = p;
      l.ptail = p;

    }
    else
    {
        p->pnext = l.phead;
        l.phead = p;
    }
}
void addtail(List& l, node* p)
{
    if(l.phead == NULL)
        { l.phead = p;
      l.ptail = p;

    }
    else
    {
        l.ptail->pnext = p;
        l.ptail = p;
    }

}
void printlistfor(List l)
{
   for(node* p = l.phead;p!= NULL ;p->pnext)
    {
        cout << p->data << "     ";
        p = p->pnext;

    }
}
/*yeu cau ; viet ham tim kiem gia tri co trong list hay khong
input:
+ 1: list
+ value: int
output:
+ return bool
*/
bool timgt(List l, int value)
{
    for(node* p = l.phead; p !=NULL; p = p->pnext)
    {
        if(p->data == value)
            return true;
    }
    return false;
}
node* timgt2(List l, int value)
{
    for(node* p = l.phead; p !=NULL; p = p->pnext)
    {
        if(p->data == value)
            return p;
    }
    return NULL;
}
 /* yeu cau: dem chan
input:
+1:list
output:
+return chan
*/
int demchan(List l)
{ int dem=0;
    for(node* p = l.phead; p !=NULL; p = p->pnext)
    {
        if(p->data) dem++;
    }
            return dem;


}
/* yeu cau: viet ham tim gia tri nho nhat trong list
phan tich:
input:
+list => list1
output:
+ gia tri lon nhat => return gia tri
*/
int timmin(List l)
{
    int m = l.phead->data;
    for(node* p = l.phead->pnext;p!=NULL;p=p->pnext)
    {
        if(p->data <m)
            m=p->data;
    }
    return m;
}
/* yeu cau: bt cau 5 viet ham khoi tao cho danh sach tu mang 1 chieu
input:
+ l: list&
+ a: int*
+ n: int
output:
+ l: list&
*/
void initList_array(List& l, int* a, int n)
{
    for(int i = 0;i<n;i++)
    {
        addhead(l,initnode(*(a+i)));
    }
}

int main()
{   List l;
    initlist(l);
    node* p1= initnode(10);
    node* p2= initnode(79);
    node* p3= initnode(39);
    addhead(l, p1);
    addhead(l, p2);
    addhead(l, p3);
    addhead(l, initnode(66));
    addtail(l, initnode(90));
    cout << "test: in danh sach:"<< endl;

    printlistfor(l);
    cout<<"test: ket qua tim 60(0):" << timgt(l,60) <<endl;
    cout<<"test: ket qua tim 66(1):" << timgt(l,66) <<endl;
    cout<<"test: ket qua tim 90(1):" << timgt(l,90) <<endl;
    cout<<"test: ket qua tim 61(0):" << timgt(l,61) <<endl;
    cout<<"\ntest: tim min(10)="<< timmin(l) << endl;
    cout<< "\ntest5.them gia tri tu mang vao list"<< endl;
    int a[]={89,67,32};
    int n = 3;
    initList_array(l,a,n);
    printlistfor(l);
  //ds.phead = NULL;
  //ds.ptail = NULL;
  //cout << "dia chi: " << p1 << endl;
  //cout << " data =" << p1->data << endl;
  //cout << "pnext =" << p1->pnext << endl;
  /*cout << "dia chi: " << p2 << endl;
  cout << " data =" << p2->data << endl;
  cout << "pnext =" << p2->pnet << endl;
  cout << "dia chi: " << p3 << endl;
  cout << " data =" << p3->data << endl;
  cout << "pnext =" << p3->pnet << endl;
  */
 return 0;
}
