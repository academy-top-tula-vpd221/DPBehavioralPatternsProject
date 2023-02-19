#include <iostream>

/*
#include "ChainOfResponsibility.h"
void ChainOfResponsibilityExample()
{
    Receiver* receiver1 = new Receiver(false, true, true);
    Receiver* receiver2 = new Receiver(false, false, true);
    Receiver* receiver3 = new Receiver(true, true, true);
    Receiver* receiver4 = new Receiver(false, false, false);

    PaymentHadler* handler = new PayPalPankmentHandler(
        new BankPankmentHandler(
            new MoneyPankmentHandler()
        )
    );
    handler->Handle(receiver1);
    cout << "\n";
    handler->Handle(receiver2);
    cout << "\n";
    handler->Handle(receiver3);
    cout << "\n";
    handler->Handle(receiver4);
    cout << "\n";
}
*/
/*
#include "Iterator.h"
void IteratorExample()
{
    srand(time(nullptr));
    Matrix matrix(5, 8);
    for (int i = 0; i < matrix.Rows(); i++)
        for (int j = 0; j < matrix.Cols(); j++)
            matrix.Get(i, j) = rand() % 100;

    matrix.Print();

    auto it = matrix.GetIterator();
    while (it->Next())
        std::cout << it->Current() << " ";
}
*/
/*
#include "Command.h"
void CommandExample()
{
    Televison* tv = new Televison();

    Controller* pult = new Controller(new TvOnCommand(tv),
        new TvSoundUpCommand(tv), new TvSoundDownCommand(tv));

    pult->ButtomPower();
    pult->ButtonVolumePlus();
    pult->ButtonVolumePlus();
    pult->ButtonVolumePlus();
    pult->ButtonVolumePlus();
    pult->ButtonVolumeMinus();
    pult->ButtonVolumeMinus();
    pult->ButtonVolumePlus();

    cout << "\n";

    pult->ButtonUndo();
    pult->ButtonUndo();
    pult->ButtonUndo();
    pult->ButtonUndo();

    cout << "\n";
    pult->ButtomPower();
    pult->ButtonVolumePlus();
}
*/
/*
#include "Mediator.h"
void MediatorExample()
{
    ManagerMediator* manager = new ManagerMediator();
    manager->Customer() = new CustomerColleague(manager);
    manager->Developer() = new DeveloperColleague(manager);
    manager->Tester() = new TesterColleague(manager);

    manager->Customer()->Send("Order!!! I need program!");
    manager->Developer()->Send("Program is ready!");
    manager->Tester()->Send("Program tested and ready!");
}
*/
/*
#include "Strategy.h"
void StrategyExample()
{
    Archiver* archiver = new Archiver(new ZipCompression());
    string file = "file.dat";
    archiver->Archiving(file);

    archiver->Compression() = new ArjCompression();
    archiver->Archiving(file);

    archiver->Compression() = new RarCompression();
    archiver->Archiving(file);
}
*/
/*
#include "State.h"
void StateExample()
{
    Water* water = new Water(new LiquidWaterState());

    water->Heating();
    water->Heating();
    water->Heating();
    water->Frosting();
    water->Frosting();
    water->Frosting();
}
*/
/*
#include "Interpreter.h"
void InterpreterExample()
{
    Context* context = new Context();
    context->SetVar("a", 70);
    context->SetVar("b", 30);
    context->SetVar("c", 20);

    IExpression* expr = new SubstructExpression(
        new AddExpression(new NumberExpression("a"), new NumberExpression("b")),
        new NumberExpression("c")
    );

    int result = expr->Interpret(context);

    cout << result << "\n";
}
*/
/*
#include "Memento.h"
void MementoExample()
{
    Player* player = new Player();
    GameHistory* gameHistory = new GameHistory();

    player->Play();
    player->Play();

    gameHistory->Save(player->Save());

    player->Play();
    player->Play();

    player->Load(gameHistory->Load());

    player->Play();
}
*/
/*
#include "Observer.h"
void ObserverExample()
{
    Market* market = new Market();
    Bank* bank = new Bank("VTB", market);
    Broker* broker = new Broker("Jhon Smith", market);

    market->Bidding();
    cout << "\n";

    market->Bidding();
    cout << "\n";

    broker->StopMarket();

    market->Bidding();
    cout << "\n";
}
*/
/*
#include "TemplateMethod.h"
void TemplateMethodExample()
{
    Education* education = new School();
    education->Learn();
    cout << "\n";

    education = new Universitet();
    education->Learn();
}
*/

#include "Visiter.h"
int main()
{
    Person* bob = new Person();
    bob->name = "Bob";
    bob->accauntNumber = "123345";
    bob->amount = 1234;

    Company* yandex = new Company();
    yandex->title = "Yandex";
    yandex->amount = 78678656;
    yandex->accauntNumber = "GHJ87678655";
    yandex->license = "HJG-675-HJGJ";

    IAccount* account = bob;
    account->Accept(new XmlVisiter());
    cout << "\n";
    account->Accept(new JsonVisiter());
    cout << "\n";

    account = yandex;
    account->Accept(new XmlVisiter());
    cout << "\n";
    account->Accept(new JsonVisiter());
    cout << "\n";
}
