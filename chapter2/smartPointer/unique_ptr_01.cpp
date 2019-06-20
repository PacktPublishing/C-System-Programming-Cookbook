#include <iostream>
#include <memory>

class CruiseControl
{
public:
    CruiseControl()
    {
        std::cout << "CruiseControl object created" << std::endl;
    };
    ~CruiseControl()
    {
        std::cout << "CruiseControl object destroyed" << std::endl;
    }
    void increaseSpeedTo(int speed)
    {
        std::cout << "Speed at " << speed << std::endl;
    };
};

int main ()
{
    std::cout << "unique_ptr test started" << std::endl;

    std::unique_ptr<CruiseControl> cruiseControl = std::make_unique<CruiseControl>();
    cruiseControl->increaseSpeedTo(12);

    std::cout << "unique_ptr test finished" << std::endl;
}


