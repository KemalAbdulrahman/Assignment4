//
//  main.cpp
//  Assignment4
//
//  Created by Kemal Abdulrahman on 5/1/20.
//  Copyright © 2020 Kemal Abdulrahman. All rights reserved.
//

#include <iostream>

using namespace std;

string data[][5]=
{{"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},
   {"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},
   {"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},
   {"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},
   {"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},
   {"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},
   {"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},
   {"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},
   {"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},
   {"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},
   {"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},
   {"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},
   {"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},
   {"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},
   {"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},
   {"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},
   {"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},
   {"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},
   {"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},
   {"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},
   {"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},
   {"Alaska","James Michener","Random House","7/3/1988","Fiction"},
   {"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},
   {"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},
   {"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},
   {"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},
   {"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},
   {"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},
   {"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},
   {"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},
   {"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},
   {"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},
   {"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},
   {"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},
   {"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},
   {"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},
   {"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},
   {"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},
   {"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},
   {"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"}};

#include <iostream>
#include<fstream>
#include <sstream>
#include <vector>
using namespace std;
class Book{

   string title;
   string author;
   string publisher;
   string  publisher_date;
   string catergory;
public:
   int getyear(){
      string year="";
      year.push_back(publisher_date.at(publisher_date.length()-4));
      year.push_back(publisher_date.at(publisher_date.length()-3));
      year.push_back(publisher_date.at(publisher_date.length()-2));
      year.push_back(publisher_date.at(publisher_date.length()-1));
      stringstream y(year);
      int x=0;
      y>>x;
      return x;
   }
   void displaybook(){
      cout<<""<<title<<" "<<publisher<<" "<<author<<" "<<publisher_date<<" "<<catergory<<endl;
   }
   void setTitle(string t){
      title=t;

   }
   void setauthor(string a){
      author=a;
   }
   void setpublisher(string p){
      publisher=p;

   }
   void setpublisher_date(string d){
      publisher_date=d;

   }
   void setcatergory(string c){
      catergory=c;
   }


   string  gettitle(){
      return title;
   }
   string  getauthor(){
      return author;
   }
   string  getcatergory(){
      return catergory;
   }
   string  getpublisher_date(){
      return publisher_date;
   }

};
vector<Book>books;
void menu(){
   cout<<"1:Display all books in a year range:"<<endl;
   cout<<"2:Search for an author:"<<endl;
   cout<<"3:Display all books for a category:"<<endl;
   cout<<"Q:Quit"<<endl;
}
void year_range(){
   int startyear;
   int endyear;
   cout<<"Enter beginning year:"<<endl;
   cin>>startyear;
   cout<<"Enter ending year:"<<endl;
   cin>>endyear;
   cout<<"All Books between "<<startyear<<" And "<<endyear<<endl;

   for (vector<Book>::iterator b = books.begin() ; b != books.end(); ++b){// Check for what is the book list
      Book& book = *b;// Each book are store in  a variable
      if(book.getyear()>=startyear&& book.getyear()<=endyear)///check if it is in the range from the begin to end
         book.displaybook();
   }


}
void search_author(){
   string author;
   cout<<"Please enter the author"<<endl;
   getline(cin,author);
   int x=0;
   for (vector<Book>::iterator b = books.begin() ; b != books.end(); ++b){
      Book& book = *b;
      if(book.getauthor()==author){//check if the author is in the book range
         x=1;
         book.displaybook();
      }
   }
   if (x!=1)
      cout<<" There is a  no book for the author "<<endl;

}

void displaybooks(){
   string category;
   cout<<"Please enter the category"<<endl;
   getline(cin,category);
   int x=0;
   for (vector<Book>::iterator b = books.begin() ; b != books.end(); ++b){
      Book& book = *b;
      if(book.getcatergory()==category){//check if the book is part of the category
         x=1;
         book.displaybook();
      }
   }
   if (x!=1)
      cout<<" There is a  no book for the catogory "<<endl;
}


int main(int argc, const char * argv[]) {
   for(int r=0;r<40;r++){
      Book bk1;
      for(int c=0;c<5;c++){
         if(c ==0){
            bk1.setTitle(data[r][c]);
         }
         else if(c==1){
            bk1.setauthor(data[r][c]);
         }
         else if(c==2){
            bk1.setpublisher(data[r][c]);
         }
         else if(c==3){
            bk1.setpublisher_date(data[r][c]);
         }
         else if(c==4){
            bk1.setcatergory(data[r][c]);
         }

      }
      books.push_back( bk1 );
   }

   while(true){
      menu();
      char option;
      cout<<"Select an option:"<<endl;
      cin>>option;
      cin.ignore();
      if(option=='1'){
         year_range();
      }
      else if(option=='2'){
         search_author();
      }
      else if(option=='3'){
         displaybooks();
      }
      else if(tolower(option)=='q'){
         cout<<" the quit the program"<<endl;
         exit(0);
      }
      else{
         cout<<"There a error and you put the wrong choice"<<endl;
      }
   }

}





