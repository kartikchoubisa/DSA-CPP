
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <numeric>
using namespace std;

bool can_read_m_pages(vector<int> books, int n_students, int m){
  //10,20,30,40. 3 students. m = 40
  int curr_sum = 0;
  int student_count = 0;
  for (int i = 0; i<books.size(); i++){
    if (curr_sum + books[i] <= m){
      curr_sum += books[i];
    }
    else {
      student_count++;
      curr_sum = books[i];
    }
  }
  return student_count <= n_students;

int main(){
  //minimize the max no of pages a student has to read
  vector<int> books{10,20,30,40};
  int n_books = books.size();
  int n_students = 2;

  //mono serach space of max no of pages a student has to read
  //start: books[last], ie one person reads one book, max no pages is largest book
  //end: sum(books), ie all the books read by one student

  int start = 0;
  int end = accumulate(books.begin(), books.end(), 0, [](int x, int y){return x+y;})-books[books.size()-1];
  int ans;
  
  while(start<=end){
    int mid = (start+end)/2;
    bool upper_lim_eqls_mid = can_read_m_pages(books, n_students, mid);
    if (upper_lim_eqls_mid){
      end = mid - 1;
      ans = min(ans,mid);
    }
    //upper lim is greater than mid
    //ie max no of pages a student has to read is more than mid
    else {
      start = mid + 1;
    }
  }

  cout << ans;
}
