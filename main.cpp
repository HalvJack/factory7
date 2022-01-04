#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

template<typename T>
void ride(T& vehicle){
    float length;
    cout<<"Ile km jazdy: "<<endl;
    cin>>length;
    if(length> ((vehicle.currentAmountOfFuel)/vehicle.fuelConsumption)*100 )
    {
        throw "Za malo benzyny w samochodzie";
    }
    else
    {
        vehicle.mileage+=length;
        vehicle.currentAmountOfFuel-= (length/100)*vehicle.fuelConsumption;
        cout<<"Przejechane"<<endl;
        cout<<"Obecny przebieg to: "<<vehicle.mileage<<endl;
        cout<<"A poziom paliwa w baku to: "<<vehicle.currentAmountOfFuel<<endl;
    }
}
template<typename T>
void calculatePrice(T& vehicle){
    int helpInt = 1000000/vehicle.mileage;
    if(vehicle.brand == "Toyota")
    {
        vehicle.price = 100000 + helpInt;
    }
    else if(vehicle.brand == "BMW")
    {
        vehicle.price = 200000 + helpInt;
    }
    else if(vehicle.brand == "Mercedes")
    {
        vehicle.price = 300000 + helpInt;
    }
}
class vehicle {
public:
    int numberOfWheels;
    string color;
    int vehiclePayload;

    vehicle(): numberOfWheels{4},color{"black"},vehiclePayload{500}{

    }
    vehicle(int numberOfWheels, string color, int vehiclePayload){
        this->numberOfWheels = numberOfWheels;
        this->color = color;
        this->vehiclePayload = vehiclePayload;
    }
    friend ostream &operator<<(ostream &os, const vehicle &vehiclePom) {
        os << "Liczba kol: " << vehiclePom.numberOfWheels << "\nKolor: "<< vehiclePom.color<< "\nLadownosc: "<< vehiclePom.vehiclePayload;
        return os;
    }
    ~vehicle(){

    }

};
class motorVehicle : public vehicle {
public:
    int tankCapacity;
    int fuelConsumption;
    int mileage;
    int currentAmountOfFuel;
    int yearOfProduction;
    int price;
    motorVehicle(): price{100000},tankCapacity{30}, fuelConsumption{6}, mileage{100}, currentAmountOfFuel{10}, yearOfProduction{2021},
                    vehicle([]{
                        vehicle rc;
                        rc.numberOfWheels = 4;
                        rc.color = "black";
                        rc.vehiclePayload = 500;
                        return rc;
                    }()) {

    }
    motorVehicle(vehicle(int numberOfWheels, string color, int vehiclePayload),
                 int price,int tankCapacity, int fuelConsumption, int mileage, int currentAmountOfFuel,
                 int yearOfProduction){
        vehicle(numberOfWheels, color, vehiclePayload);
        this->tankCapacity = tankCapacity;
        this->fuelConsumption = fuelConsumption;
        this->mileage = mileage;
        this->currentAmountOfFuel = currentAmountOfFuel;
        this->yearOfProduction = yearOfProduction;
        this->price = price;
    }
    friend ostream &operator<<(ostream &os, const motorVehicle &motorVehiclePom) {
        os << static_cast<const vehicle &>(motorVehiclePom) << "\nPojemnosc baku: "<<motorVehiclePom.tankCapacity<<
        "\nSpalanie: "<<motorVehiclePom.fuelConsumption<<
           "\nPrzebieg: "<<motorVehiclePom.mileage<<"\nIlosc paliwa w baku: "<<motorVehiclePom.currentAmountOfFuel<<
           "\nRok produkcji: "<<motorVehiclePom.yearOfProduction<<endl;
        return os;
    }
    ~motorVehicle(){

    }
};
class car : public motorVehicle{
public:
    int bootSize;
    string brand;
    int model;
    int vin;
    car(): bootSize{500}, brand{"BMW"}, model{5},vin{0},
           motorVehicle([]{
               motorVehicle mV;
               mV.tankCapacity = 30;
               mV.fuelConsumption = 6;
               mV.mileage = 100;
               mV.currentAmountOfFuel = 10;
               mV.yearOfProduction = 2021;
               mV.numberOfWheels = 4;
               mV.color = "black";
               mV.vehiclePayload = 500;
               mV.price =100000;
               return mV;
           }()) {

    }
    car(int numberOfWheels, string color, int vehiclePayload,
        int tankCapacity, int fuelConsumption, int mileage, int currentAmountOfFuel,
        int yearOfProduction, int vin,int bootSize, string brand,
        int, int price ){
        this->numberOfWheels = numberOfWheels;
        this->color = color;
        this->vehiclePayload = vehiclePayload;
        this->tankCapacity = tankCapacity;
        this->fuelConsumption = fuelConsumption;
        this->mileage = mileage;
        this->currentAmountOfFuel = currentAmountOfFuel;
        this->yearOfProduction = yearOfProduction;
        this->vin = vin;
        this->bootSize = bootSize;
        this->brand = brand;
        this->model = model;
        this->price = price;
    }
    void ride(){
        int length;
        cout<<"Ile km jazdy: "<<endl;
        cin>>length;
        if(length > ((currentAmountOfFuel/fuelConsumption)*100) )
        {
            throw "Za malo benzyny w samochodzie";
        }
        else
        {
            //mileage+=length;
            //currentAmountOfFuel-= ((length/100)*fuelConsumption);
            cout<<"Przejechane"<<endl;
            cout<<"Obecny przebieg to: "<<mileage<<endl;
            cout<<"A poziom paliwa w baku to: "<<currentAmountOfFuel<<endl;
        }
    }
    void refueling(){
        int volume;
        cout<<"Ile litrow chcesz zatankowac?"<<endl;
        cin>>volume;
        if(volume> tankCapacity - currentAmountOfFuel)
        {
            throw 101; // za duzo paliwa, nie zmiesci sie tyle;
        }
        else
        {
            currentAmountOfFuel+=volume;
            cout<<"Zatankowano. Obecny poziom paliwa w baku to: "<<currentAmountOfFuel<<" litrow"<<endl;
        }
    }
    void calculatePrice(){
        int helpInt = 1000000/mileage;
        if(brand == "Toyota")
        {
            price = 100000 + helpInt;
        }
        else if(brand == "BMW")
        {
            price = 200000 + helpInt;
        }
        else if(brand == "Mercedes")
        {
            price = 300000 + helpInt;
        }
    }
    friend ostream &operator<<(ostream &os, const car &carPom) {
            os << static_cast<const motorVehicle &>(carPom) << "\nRozmiar bagaznika: "<<
               carPom.bootSize<<"\nMarka: "<<carPom.brand<<"\nModel: "<<carPom.model<<"\nNr VIN: "<<carPom.vin<<endl;
            return os;
        }
    friend ofstream &operator<<(ofstream& stream, const car& carPom) //operator wypisania do pliku
    {
        stream<<"Marka: "<<carPom.brand<<endl<<"Model: "<<carPom.model<<endl<<"Kolor: "<<carPom.color<<endl
              <<"VIN: "<<carPom.vin<<endl<<"Rocznik: "<<carPom.yearOfProduction<<endl<<"Przebieg: "<<carPom.mileage<<endl
              <<"Pojemnosc baku: "<<carPom.tankCapacity<<endl<<"Stan baku: "<<carPom.currentAmountOfFuel<<
              endl<<"-------------------"<<endl;

        return stream;
    }
    ~car(){

    }
};
class motorcycle : public motorVehicle{
public:
    float bootSize;
    string brand;
    int model;
    motorcycle(): bootSize{500}, brand{"Ninja"}, model{1},
                  motorVehicle([]{
                      motorVehicle mV;
                      mV.tankCapacity = 30;
                      mV.fuelConsumption = 6;
                      mV.mileage = 100;
                      mV.currentAmountOfFuel = 10;
                      mV.yearOfProduction = 2021;
                      mV.numberOfWheels = 2;
                      mV.color = "black";
                      mV.vehiclePayload = 500;
                      return mV;
                  }()) {

    }
    motorcycle(int numberOfWheels, string color, float vehiclePayload,
               float tankCapacity, float fuelConsumption, float mileage, float currentAmountOfFuel,
               int yearOfProduction,float bootSize, string brand,
               int model ){
        this->numberOfWheels = numberOfWheels;
        this->color = color;
        this->vehiclePayload = vehiclePayload;
        this->tankCapacity = tankCapacity;
        this->fuelConsumption = fuelConsumption;
        this->mileage = mileage;
        this->currentAmountOfFuel = currentAmountOfFuel;
        this->yearOfProduction = yearOfProduction;
        this->bootSize = bootSize;
        this->brand = brand;
        this->model = model;
    }

    friend ofstream &operator<<(ofstream& stream, const motorcycle& motorcyclePom) //operator wypisania do pliku
    {
        stream << "Marka: " << motorcyclePom.brand << endl << "Model: " << motorcyclePom.model << endl << "Kolor: " << motorcyclePom.color << endl
               << endl << "Rocznik: " << motorcyclePom.yearOfProduction << endl << "Przebieg: " << motorcyclePom.mileage << endl
               << "Pojemnosc baku: " << motorcyclePom.tankCapacity << endl << "Stan baku: " << motorcyclePom.currentAmountOfFuel <<
               endl << "-------------------" << endl;

        return stream;
    }
    friend ostream &operator<<(ostream &os, const motorcycle &motorcyclePom) {
        os << static_cast<const motorVehicle &>(motorcyclePom) << "\nRozmiar bagaznika: "<<
           motorcyclePom.bootSize<<"\nMarka: "<<motorcyclePom.brand<<"\nModel: "<<motorcyclePom.model<<endl;
        return os;
    }
    ~motorcycle(){

    }
};
class bike : public vehicle{
public:
    bool haveBasket;
    bike(): haveBasket{true}, vehicle{4,"black", 100}
    {}
    bike(vehicle(int numberOfWheels, string color, float vehiclePayload), bool haveBasket){
        vehicle(numberOfWheels,color, vehiclePayload);
        this->haveBasket = haveBasket;
    }
    friend ostream &operator<<(ostream &os, const bike &bikePom) {
        os << static_cast<const vehicle &>(bikePom) <<"Koszyk : "<<bikePom.haveBasket<<endl;
        return os;
    }
    friend ofstream &operator<<(ofstream& stream, const bike& bikePom) //operator wypisania do pliku
    {
        stream << "Ilosc kol: " << bikePom.numberOfWheels << endl << "Ladownosc: " << bikePom.vehiclePayload << endl
        << "Kolor: " << bikePom.color << endl
               << "Posiada koszyk: " << bikePom.haveBasket << endl << "-------------------" << endl;
        return stream;
    }
    ~bike(){

    }
};
class carDealer {
public:
    vector<car>yard;
    float margin = 5;
    void buyMotorVehicle(car toAdd)
    {
        yard.push_back(toAdd); // to nie dziala
        cout<<"in carDealer ";
        calculatePrice(toAdd);
        cout<<"Cena skupu: "<<toAdd.price<<endl;
        if(toAdd.brand == "Toyota")
        {
            toAdd.mileage/=2;
        }
        saveVehicle(toAdd);
    }
    void sellMotorVehicle(car& toSell)
    {
        cout<<"Cena sprzedazy z marza: "<<(toSell.price*105)/100<<endl;
    }
    void saveVehicle(car carToSave)
    {
        yard.push_back(carToSave);
        fstream plik;
        plik.open("carDealerList.txt",ios::out | ios::app);//app-dane zapisywane na koncu pliku

        if(!plik.good())
        {
            cout<<"Plik txt nie jest dostepny."<<endl;
            exit(0);
        }
        plik<<carToSave;//wpisanie samochodu s do pliku tekstowego
        plik.close();
    }
    void sellCar(int carVin){
        int numberPom;
        vector<car>carListHelp;
        for(int i = 0; i < yard.size(); i++)
        {
            if(carVin == yard[i].vin)
            {
                numberPom = i;
                i = yard.size();
            }
        }
        for(int i = 0; i < yard.size(); i++) //tworzymy pomocnicza liste aut bez sprzedanego auta
        {
            if(i != numberPom)
            {
                carListHelp.push_back(yard[i]);
            }
        }
        for(int i = 0; i < yard.size(); i++) //usuawamy cala liste aut z wektora
        {
            yard.pop_back();
        }
        if (remove ("carDealerList.txt") == 0 ) // plik z autami usuniety
        {
            for(int i = 0; i < carListHelp.size(); i++)
            {
                saveVehicle(carListHelp[i]); //nowa lista zapisana w wektorze i pliku bez sprzedanego auta
            }
        }
        else
        {
            cout << "Wystapil blad podczas usuwania pliku" << endl;
        }


    }
};
class varnisher {
public:
    void changeColor(car& vehicleToPaint, string newColor){
        vehicleToPaint.color = newColor;
    }
};
class vehicleFactory {
public:
    int counter = 0;
    vector<car>carList;
    vector<motorcycle>motorcycleList;
    vector<bike>bikeList;
    void makeVehicle(){
        bool isBasket;
        string chooseColor,chooseBrand;
        int chooseModel,chooseVehicle, chooseBrandToInteger;
        cout<<"Wybierz numer pojazdu jaki chcesz stworzyc: "<<endl;
        cout<< "1. Samochod 2. Motocykl 3. Rower"<<endl;
        cin>>chooseVehicle;
        cout<<"Podawaj wymagane dane zatwierdzajac enterem!"<<endl;
        switch(chooseVehicle){
            case 1:
                cout<<"Podaj kolor"<<endl;
                cin>>chooseColor;
                cout<<"Wpisz jedna z trzech marek, wpisujac jej nazwe: "<<endl<<
                "Toyota BMW Mercedes"<<endl;
                cin>>chooseBrand; if(chooseBrand == "Toyota") chooseBrandToInteger = 1; else if(chooseBrand == "BMW")
                    chooseBrandToInteger = 2; else if(chooseBrand == "Mercedes") chooseBrandToInteger = 3;
                switch(chooseBrandToInteger){
                    case 1:
                        cout<<"Wybierz model: "<<endl
                        <<"406 306 206"<<endl;
                        cin>>chooseModel;
                        makeCar(chooseColor,chooseBrand,chooseModel);
                        break;
                    case 2:
                        cout<<"Wybierz model:"<<endl
                        <<"4 5 6"<<endl;
                        cin>>chooseModel;
                        makeCar(chooseColor,chooseBrand,chooseModel);
                        break;
                    case 3:
                        cout<<"Wybierz model: "<<endl
                        <<"20 21 22"<<endl;
                        cin>>chooseModel;
                        makeCar(chooseColor,chooseBrand,chooseModel);
                        break;
                    default:
                        cout<<"Nie ma takiego modelu :("<<endl;
                    break;
                }
                break;
            case 2:
                cout<<"Podaj kolor"<<endl;
                cin>>chooseColor;
                cout<<"Wpisz jedna z dwoch marek wpisujac jej nazwe: "<<endl<<
                "Yamaha Toyota"<<endl;
                cin>>chooseBrand; if(chooseBrand == "Yamaha") chooseBrandToInteger = 1; else if(chooseBrand ==
                "Toyota") chooseBrandToInteger = 2;
                switch(chooseBrandToInteger){
                    case 1:
                        cout<<"Wybierz model: "<<endl
                        <<"1 2"<<endl;
                        cin>>chooseModel;
                        makeMotorcycle(chooseColor, chooseBrand, chooseModel);
                        break;
                    case 2:
                        cout<<"Wybierz model: "<<endl
                        <<"10 11"<<endl;
                        cin>>chooseModel;
                        makeMotorcycle(chooseColor, chooseBrand,chooseModel);
                        break;
                    default:
                        cout<<"Nie ma takiego pojazdu :("<<endl;
                }
                break;
            case 3:
                cout<<"Podaj kolor"<<endl;
                cin>>chooseColor;
                cout<<"Czy rower ma koszyk? Jesli tak wpisz 1, jesli nie wpisz 0";
                cin>>isBasket;
                makeBike(chooseColor, isBasket);
                break;
            default:
                cout<<"Nie ma takiego pojazdu :("<<endl;
                break;

        }
    }
    void makeCar(string &chooseColor, string &chooseBrand, int &chooseModel)
    {
        car newCar;
        if(chooseModel == 4 || chooseModel == 20 || chooseModel == 206){
            newCar.bootSize = 100;
            newCar.vehiclePayload +=newCar.bootSize;
            newCar.currentAmountOfFuel = newCar.tankCapacity - 5;
            newCar.vin = counter+1;
        }
        else if(chooseModel == 5 || chooseModel == 21 || chooseModel == 306)
        {
            newCar.bootSize = 200;
            newCar.vehiclePayload+=newCar.bootSize;
            newCar.currentAmountOfFuel = newCar.tankCapacity-5;
            newCar.vin = counter+1;
        }
        else
        {
            newCar.bootSize = 300;
            newCar.vehiclePayload+=newCar.bootSize;
            newCar.currentAmountOfFuel = newCar.tankCapacity-5;
            newCar.vin = counter+1;
        }
        newCar.color = chooseColor;
        newCar.brand = chooseBrand;
        newCar.model = chooseModel;
        counter++;
        saveVehicle(newCar);
    }
    void makeMotorcycle(string chooseColor, string chooseBrand, int chooseModel)
    {
        motorcycle newMotorcycle;
        if(chooseModel == 1 || chooseModel == 10)
        {
            newMotorcycle.bootSize = 50;
            newMotorcycle.vehiclePayload+= newMotorcycle.bootSize;
            newMotorcycle.currentAmountOfFuel =  newMotorcycle.tankCapacity;
        }
        else
        {
            newMotorcycle.bootSize = 100;
            newMotorcycle.vehiclePayload+= newMotorcycle.bootSize;
            newMotorcycle.currentAmountOfFuel =  newMotorcycle.tankCapacity;
        }
        newMotorcycle.color = chooseColor;
        newMotorcycle.brand = chooseBrand;
        newMotorcycle.model = chooseModel;
        saveVehicle(newMotorcycle);
    }
    void makeBike(string chooseColor, bool basket)
    {
        bike newBike;
        if(basket == true)
        {
            newBike.vehiclePayload+=50;
            newBike.color = chooseColor;
            newBike.haveBasket = basket;
        }
        else
        {
            newBike.haveBasket = basket;
            newBike.color = chooseColor;
        }
        saveVehicle(newBike);
    }
    void saveVehicle(car& carToSave)
    {
        carList.push_back(carToSave);
        fstream plik;
        plik.open("car.txt",ios::out | ios::app);//app-dane zapisywane na koncu pliku

        if(!plik.good())
        {
            cout<<"Plik txt nie jest dostepny."<<endl;
            exit(0);
        }
        plik<<carToSave;//wpisanie samochodu do pliku tekstowego
        plik.close();
    }
    void saveVehicle(motorcycle &motorcycleToSave)
    {
        motorcycleList.push_back(motorcycleToSave);
        fstream plik;
        plik.open("motorcycle.txt",ios::out | ios::app);//app-dane zapisywane na koncu pliku

        if(!plik.good())
        {
            cout<<"Plik txt nie jest dostepny."<<endl;
            exit(0);
        }
        plik<<motorcycleToSave;//wpisanie samochodu s do pliku tekstowego
        plik.close();
    }
    void saveVehicle(bike &bikeToSave)
    {
        bikeList.push_back(bikeToSave);
        fstream plik;
        plik.open("bike.txt",ios::out | ios::app);//app-dane zapisywane na koncu pliku

        if(!plik.good())
        {
            cout<<"Plik txt nie jest dostepny."<<endl;
            exit(0);
        }
        plik<<bikeToSave;//wpisanie samochodu s do pliku tekstowego
        plik.close();
    }
    void showVehicleList()
    {
        {
            string linia;
            fstream plikCar,plikMotorcycle,plikBike;
            cout<<"LISTA SAMOCHODOW: "<<endl;
            plikCar.open("car.txt",ios::in);//tryb do odczytu
            if(plikCar.good())
            {
                while(getline(plikCar,linia)) {
                    cout << linia << endl;
                }
            }
            plikCar.close();
            cout<<"LISTA MOTOCYKLI: "<<endl;
            plikMotorcycle.open("motorcycle.txt",ios::in);
            if(plikMotorcycle.good())
            {
                while(getline(plikMotorcycle,linia)) {
                    cout << linia << endl;
                }
            }
            plikMotorcycle.close();
            cout<<"LISTA ROWEROW: "<<endl;
            plikBike.open("bike.txt",ios::in);
            if(plikBike.good())
            {
                while(getline(plikBike,linia)) {
                    cout << linia << endl;
                }
            }
            plikBike.close();
        }
    }
    void sellFactoryCar(int carVin, carDealer Marlon){
        int helper = 0;
        int numberPom;
        vector<car>carListPom;
        for(int i = 0; i < carList.size(); i++)
            {
            if(carVin == carList[i].vin)
                {
                numberPom = i;
                i = carList.size();
                helper = 1;
                }
            }
        if(helper == 1) {
            for (int i = 0; i < carList.size(); i++) //tworzymy pomocnicza liste aut bez sprzedanego auta
            {
                if (i != numberPom) {
                    carListPom.push_back(carList[i]);
                }
            }
            Marlon.buyMotorVehicle(carList[numberPom]);
            for (int i = 0; i < carList.size(); i++) //usuawamy cala liste aut z wektora
            {
                carList.pop_back();
            }
            if (remove("car.txt") == 0) // plik z autami usuniety
            {
                for (int i = 0; i < carListPom.size(); i++) {
                    saveVehicle(carListPom[i]); //nowa lista zapisana w wektorze i pliku bez sprzedanego auta
                }
            } else {
                cout << "Wystapil blad podczas usuwania pliku" << endl;
            }
        }
        else
        {
            cout<<"Nie ma auta o takim nr vin"<<endl;
        }


    }

};
int main(int argc, char* argv[]) {
    vehicleFactory Ulsan;
    carDealer Marlon;
    varnisher Gazda;
    if(argc == 3 && argv[1] == "Toyota" && argv[2] == "tank")
    {
        Ulsan.makeVehicle();
        Ulsan.showVehicleList();
        int vinNumber;
        cout<< "Wpisz nr VIN samochodu, ktorym chcesz pojezdzic: ";
        cin>>vinNumber;
        for(int i = 0; i < Ulsan.carList.size(); i++)
        {
            if(vinNumber == Ulsan.carList[i].vin)
            {
                try{
                    ride(Ulsan.carList[vinNumber]);
                }

                catch(const char * fuelException) {
                    cout<< "Exception : " << fuelException << endl;
                }
                i = Ulsan.carList.size();
                //pomI = Ulsan.carList.size() + 1;
            }
        }
    }
    int choice;
    while(choice!= 7)
    {
        cout << "Witamy w MENU Fabryki Ulsan: " << endl << endl;
        cout << "1. Produkcja auta" << endl;
        cout << "2. Wyswietlenie aktualnego stanu fabryki" << endl;
        cout << "3. Sprzedaz aut" << endl;
        cout << "4. Korzystaj z auta" << endl;
        cout << "5. Przemaluj auto" << endl;
        cout << "6. Zatankuj auto" << endl;
        cout << "7. Zamknij program" << endl;

        cout << "\nWybierz akcje: ";
        cin >> choice;

        switch(choice) {
            case 1 : {
                Ulsan.makeVehicle();
            }
            break;
            case 2 : {
                Ulsan.showVehicleList();
            }
            break;
            case 3 : {
                int vinNumber;
                cout<< "Wpisz nr VIN samochodu, ktory chcesz sprzedac: ";
                cin>>vinNumber;
                Ulsan.sellFactoryCar(vinNumber, Marlon);
            }
            break;
            case 4 :
            {
                int vinNumber, helper = 0;
                cout<< "Wpisz nr VIN samochodu, ktorym chcesz pojezdzic: ";
                cin>>vinNumber;
                for(int i = 0; i < Ulsan.carList.size(); i++)
                {
                    if(vinNumber == Ulsan.carList[i].vin)
                    {
                        try{
                        ride(Ulsan.carList[vinNumber]);
                        }

                        catch(const char * fuelException) {
                            cout<< "Exception : " << fuelException << endl;
                        }
                        i = Ulsan.carList.size();
                        helper = 1;
                    }
                }
                if(helper == 0)
                {
                    cout<<"Nie udalo sie znalezc takiego auta"<<endl;
                }
            }
            break;
            case 5 :
            {
                int vinNumber,pomI;
                string color;
                cout<< "Wpisz nr VIN samochodu, ktory chcesz przemalowac";
                cin>>vinNumber;
                cout<< "Wpisz kolor na jaki chcesz pomalowac samochod: ";
                cin>>color;
                for(int i = 0; i < Ulsan.carList.size(); i++)
                {
                    if(vinNumber == Ulsan.carList[i].vin)
                    {
                        Gazda.changeColor(Ulsan.carList[i], color);
                        i = Ulsan.carList.size();
                        //pomI = Ulsan.carList.size() + 1;
                    }
                }
                //if(pomI > Ulsan.carList.size())
                //{
                  //  cout<<"Nie udalo sie znalezc takiego auta"<<endl;
                //}
            }
            break;
            case 6 : {
                int vinNumber,pomI;
                cout<< "Wpisz nr VIN samochodu, ktory chcesz zatankowac";
                cin>>vinNumber;
                for(int i = 0; i < Ulsan.carList.size(); i++)
                {
                    if(vinNumber == Ulsan.carList[i].vin)
                    {
                        try{
                        Ulsan.carList[i].refueling();
                        }
                        catch(int tankException) {
                            cout << "Exception: " << tankException << endl;
                        }
                        i = Ulsan.carList.size();
                       // pomI = Ulsan.carList.size() + 1;
                    }
                }
                //if(pomI > Ulsan.carList.size())
                //{
                //    cout<<"Nie udalo sie znalezc takiego auta"<<endl;
                //}
            }
                break;
            case 7 : {
                exit(0);
            }
                break;
            default:
                cout<< "Niepoprawny wybor, Taka opcja nie istnieje." <<endl;
                break;
        }
    }
    return 0;
}
