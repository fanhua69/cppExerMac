#include <vector>
#include <iostream>
#include <memory>


using namespace std;

class ICommand
{
public:
    virtual void Execute() = 0;
};

class Switcher
{
private:
    std::vector<ICommand *> _commands;

public:
    void StoreAndExecute(ICommand *command)
    {
        if ( command )
        {
            _commands.push_back(command);
            command->Execute();
        }
    }
};

class Light
{
public:
    Light()
    {
        int mm=0;
    }
    void TurnOn()
    {
        std::cout << "The light is on." << std::endl;
    }

    void TurnOff()
    {
        std::cout << "The light is off." << std::endl;
    }
};

/* The Command for turning on the light - ConcreteCommand #1 */
class FlipUpCommand : public ICommand
{
private:
    Light *_light;

public:
    FlipUpCommand(Light *light)
    {
        _light = light;
    }

    void Execute()
    {
        _light->TurnOn();
    }
};

/* The Command for turning off the light - ConcreteCommand #2 */
class FlipDownCommand : public ICommand
{
private:
    Light *_light;

public:
    FlipDownCommand(Light *light)
    {
        _light = light;
    }

    void Execute()
    {
        _light->TurnOff();
    }
};

int commandpattern()
{
    std::unique_ptr<Light> light = std::make_unique<Light>();
    std::unique_ptr<ICommand> switchOn(new FlipUpCommand(light.get()));
    std::unique_ptr<ICommand> switchDown(new FlipDownCommand(light.get()));

    std::unique_ptr<Switcher> switcher = std::make_unique<Switcher>();
    switcher->StoreAndExecute(switchOn.get());
    switcher->StoreAndExecute(switchDown.get());

    return 0;
}