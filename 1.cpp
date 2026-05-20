#include <iostream>
#include <string>
using namespace std;

class room
{
public:
    room(float);
    float get_area();

private:
    float area;
};

room::room(float area)
{
    room::area = area;
}

float room::get_area()
{
    return area;
}

class apartment
{
public:
    apartment(float, float, int);
    void show_info();

private:
    room my_room;
    float kitchen;
    int floor;
};


apartment::apartment(float room_area, float kitchen, int floor) : my_room(room_area)
{
    apartment::kitchen = kitchen;
    apartment::floor = floor;
}

void apartment::show_info()
{
    cout << "Room area: " << my_room.get_area() << endl;
    cout << "Kitchen area: " << kitchen << endl;
    cout << "Floor: " << floor << endl;
}

class city_apartment : public apartment
{
public:
    city_apartment(float, float, int, string);
    ~city_apartment();
    void show_city_apartment();

private:
    string city_name;
};

city_apartment::city_apartment(float room_area, float kitchen, int floor, string city_name)
    : apartment(room_area, kitchen, floor)
{
    city_apartment::city_name = city_name;
}

city_apartment::~city_apartment()
{
    cout << "Delete city_apartment" << endl;
}

void city_apartment::show_city_apartment()
{
    cout << "City: " << city_name << endl;
    apartment::show_info();
}

int main()
{
    city_apartment my_flat(20.5, 10.0, 5, "Kharkiv");
    my_flat.show_city_apartment();
}
