#include <iostream>
#include <string>
#include <list>

int ID = 0;

class Website
{
  private:
    std :: string content;
    int id;
    int min_age;
    int max_age;
    
    public:
        Website(std :: string content, int id, int min_age, int max_age) : content(content), id(id), min_age(min_age), max_age(max_age) {}
        int get_id() {return id;}
        std :: string get_content() {return content;}
        int check_age(int age)
        {
            return (age >= min_age && age <= max_age);
        }
};

class User
{
  private:
    int id;
    std :: string name;
    int year;
    int month;
    int day;
    
  public:
    User(std :: string name, int year, int month, int day) : name(name), year(year), month(month), day(day)
    {
        id = ID++;
    }
    
    void display_user()
    {
        std :: cout << id << '\n' << name << '\n' << year << ' ' << month << ' ' << day << '\n';
    }
    
    void check_birthday()
    {
        if( (year >= 1900 && year <= 2022) && (month <= 30))
        {
            std :: cout << id << '\n' << year << ' ' << month << ' ' << day << '\n';
        }
        else
        {
            std :: cout << id << '\n' << "ERROR: Your birthday is not correct\n";
        }
    }
    
    void calculate_age(int current_year, int current_month, int current_day)
    {
        int age = current_year - year;
        if(month > current_month)
            age--;
        if(month == current_month)
            if(day > current_day)
                age--;
                
        if(age >= 18)
            std :: cout << name << '\n' << age << '\n';
    }
    
    int get_age(int current_year, int current_month, int current_day)
    {
        int age = current_year - year;
        if(month > current_month)
            age--;
        if(month == current_month)
            if(day > current_day)
                age--;
                
        return age;
    }
    
    int get_id() {return id;}
    std :: string get_name() {return name;}
    
};

int main()
{
    int n_users;
    int id, age;
    std :: string name;
    int year, month, day;
    int test;
    int n_posts;
    int min_age, max_age;
    std :: string content;
    std :: list<Website*> web;
    std :: list<User*> user;
    
    std :: cin >> n_users;
    std :: cin.ignore();
    for(int i = 0; i < n_users; i++)
    {
        getline(std :: cin, name);
        std :: cin >> year >> month >> day;
        std :: cin.ignore();
        user.push_back(new User(name, year, month, day));
    }
    
    std :: cin >> test;
    
    if(test == 1)
    {
        for(auto x : user)
            x->display_user();
    }
    
    if(test == 2)
    {
        for(auto x : user)
            x->check_birthday();
    }
    
    if(test == 3)
    {
        std :: cin >> year >> month >> day;
        for(auto x : user)
            x->calculate_age(year, month, day);
    }
    if(test == 4)
    {
        int count = 0;
        std :: cin >> year >> month >> day;
        std :: cin >> n_posts;
        for(int i = 0; i < n_posts; i++)
        {
            std :: cin >> id;
            std :: cin >> min_age >> max_age;
            std :: cin.ignore();
            getline(std :: cin, content);
            web.push_back(new Website(content, id, min_age, max_age));
        }
        
        std :: cout << "News Feed\n";
        
        for(auto u : user)
            if(u->get_id() == 0)
                age = u->get_age(year, month, day);
                
        for(auto u : user)
        {
            for(auto w : web)
            {
                if(u->get_id() == w->get_id())
                {
                    if(u->get_id() == 0)
                    {
                        std :: cout << u->get_name() << '\n' << w->get_content() << '\n';
                        count++;
                        
                    }
                    else
                    {
                        if(w->check_age(age))
                        {
                             std :: cout << u->get_name() << '\n' << w->get_content() << '\n';
                        count++;
                        }
                    }
                }
            }
        }
        
        
        
        if(count == 0)
            std :: cout << "No posts for you\n";
        
    }
    
    return 0;
}