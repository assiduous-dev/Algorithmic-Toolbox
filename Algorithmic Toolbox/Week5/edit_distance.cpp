#include <iostream>
#include <string>
#include<cstring>

using std::string;
using namespace::std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

int editDist[str1.size()+1][str2.size()+1];

for(int a=0;a<str1.size()+1;a++)
{
  for(int b=0;b<str2.size()+1;b++)
  {
    editDist[a][b]=0;
  }
}
for(int i=0;i<str1.size()+1;i++)
{
  editDist[i][0] = i;
}

for(int j=0;j<str2.size()+1;j++)
{
  editDist[0][j] = j;
}

int a,b,c;
for(int x = 1;x<str1.size()+1;x++)
{
  for(int y=1;y<str2.size()+1;y++)
  {
    b=editDist[x-1][y-1];
    a=editDist[x-1][y] + 1;
    c=editDist[x][y-1] + 1;
    char jj = str1[x-1];
    char xx = str2[y-1];
    if(str1[x-1]==str2[y-1])
    {
      editDist[x][y] = std::min(std::min(a,b),c);
    }else
    {
      editDist[x][y] = std::min(std::min(a,b+1),c);
    }
  }
}

  return editDist[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
