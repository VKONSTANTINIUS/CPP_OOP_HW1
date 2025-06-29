//----------Домашнє завдання 1 ООП:

// 1. Вибрано п’ять предметів з навколишнього світу.
// 2. Для кожного предмета створено окремий клас:
//		- Мобільний телефон    - MobilePhone;
//		- Холодильнк           - Freezer;
//		- Кавоварка            - Сoffee_machine;
//		- Комп*ютер            - PersonalComputer;
//		- Пральна машина       - Washer.
// 3. У кожному класі створено:
//		- 5 приватних полів, які описують характеристики предмета;
//		- 5 публічних методів, які дозволяють взаємодіяти з предметом;
//		- Метод для виведення загальної інформації про об*єкт.
// 4. У функції мейн:
//		- Створено по одній змінній кожного класу;
//		- Заповнено поля предметів;
//		- Викликано всі методи для кожного предмету;

//----------Домашнє завдання 2 ООП:

// 1. Для кожного класу додано сетери та гетери для кожного поля.
// 2. У сетери додані перевірки введених даних;
// 3. Гетери - константні;
// 4. Методи перероблені з урахуванням доданих функцій;
// 5. У функції мейн показана робота доданих сетерів і гетерів, а також перероблених функцій.
// 6. Відкореговані "коментарі"

//----------Домашнє завдання 3 ООП:
// 1. Додано поля-покажчики:
//    - для класу MobilePhone поле phonesystem;
//    - для класу CoffeeMachine поле room;
// 2. Для полів-покажчиків:
//    - Створено сетери і гетери;
//    - Виділена пам*ять;
//    - Вивільнена пам*ять в деструкторі.
// 3. Створено конструктори класів:
//    - конструктор з параметрами;
//    - конструктор делегування;
//    - конструктор копіювання;
// 4. Створено деструктори для об*єктів класів.
// 5. У функції мейн показана робота конструкторів.


#include <iostream> 
#include <string>   
#include <windows.h> 

using namespace std;

// 1 клас - мобільний телефон
class MobilePhone {
private: 
	string model;                  // Модель телефону
	int battery;                   // Рівень заряду батареї у відсотках
	int storage;                   // Загальний обсяг пам'яті в Гб
	int freespace;                 // Вільний простір у відсотках
	int internet;                  // Доступний інтернет в Мб

	char* phonesystem = nullptr;   // Операційна система телефону (поле покажчик)

public: 
	// Конструктор за замовчуванням що делегує роботу конструктору з параметрами
	MobilePhone(): MobilePhone("Xiaomi_Redmi_Note_14", 100, 256, 90, 10240, "android")  {

		cout << "конструктор делегування, адреса -  " << this << endl;	

	}
	// Конструктор з параметрами
	MobilePhone(string model, int battery, int storage, int freespace, int internet, const char* phsys) {

		cout << "конструктор з параметрами, адреса -  " << this << endl;

		setModel(model);
		setBattery(battery);
		setStorage(storage);
		setFreespace(freespace);
		setInternet(internet);
		setPhoneSystem(phsys);			

	}
	// Конструктор копіювання
	MobilePhone(const MobilePhone& copy) {
		cout << "конструктор копіювання, адреса -  " << this << endl;
		model = copy.model;
		battery = copy.battery;
		storage = copy.storage;
		freespace = copy.freespace;
		internet = copy.internet;

		phonesystem = new char[strlen(copy.phonesystem) + 1];
		strcpy_s(phonesystem, strlen(copy.phonesystem) + 1, copy.phonesystem);

	}
	// Деструктор
	~MobilePhone() {
		cout << "деструктор для адреси - " << this << endl;
		delete[] phonesystem;

	}

	// Сетери

	void setPhoneSystem(const char* newPhsys) {
		delete[] phonesystem;
		phonesystem = new char[strlen(newPhsys) + 1];
		strcpy_s(phonesystem, strlen(newPhsys) + 1, newPhsys);
		
	}

	void setModel(string model = "Xiaomi_Redmi_Note_14") {
		this->model = model;		
	}

	void setBattery(int battery) {
		if (battery < 0 || battery > 100) {
			this->battery = 100;
		}
		else { this->battery = battery; }	
	}

	void setStorage(int storage) {
		if (storage < 0) { this->storage = 256; }
		else { this->storage = storage; }	
	}

	void setFreespace(int freespace) {
		if (freespace < 0 || freespace > 100) {
			this->freespace = 90;
		}
		else { this->freespace = freespace; }
	}

	void setInternet(int internet) {
		if (internet < 0) { this->internet = 10240; }
		else { this->internet = internet; }
	}

	//Гетери
	const char* getPhoneSystem() const {
		return phonesystem;

	}

	string getModel() const {
		return model;
	}

	int getBattery() const {
		return battery;
	}

	int getStorage() const {
		return storage;
	}

	int getFreespace() const {
		return freespace;
	}

	int getInternet() const {
		return internet;
	}

	// Зарядка батареї 
	void charge_battery() {
		if (battery < 100) {
			battery = 100;
			cout << "телефон заряджено";
		}
		else cout << "телефон заряджено";

	}

	// Гра на телефоні - зменшуює пам'ять та заряд батареї
	void play_game() {
		if (getFreespace() > 0 && getBattery() > 0) {
			cout << "граємо в гру" << endl;
			freespace -= 10;
			battery -= 5;
		}
		else {
			cout << "недостатньо пам'яті або інтернету для гри" << endl;
		}
	}

	// Завантаження фото - зменшуює трафік та вільну пам'ять
	void download_foto() {
		if (getInternet() > 0 && getFreespace() > 0) {
			cout << "завантажено фото" << endl;
			internet -= 5;
			freespace -= 2;
		}
		else {
			cout << "недостатньо пам'яті або інтернету для завантаження" << endl;
		}
	}

	// Перегляд соціальних мереж - зменшуює трафік та пам'ять
	void serf_social() {
		if (getInternet() > 0 && getFreespace() > 0) {
			cout << "Перегляд соціальних мереж" << endl;
			internet -= 10;
			freespace -= 5;
		}
		else {
			cout << "недостатньо пам'яті або інтернету для перегляду відяшок" << endl;
		}
	}

	// Виведення інформації 
	void print_info() const{
		cout << "\n============================\n";
		cout << "Модель: " << getModel() << endl;
		cout << "Батарея: " << getBattery() << "%" << endl;
		cout << "Пам'ять: " << getStorage() << "Gb" << endl;
		cout << "Доступно пам'яті: " << getFreespace() << "%" << endl;
		cout << "Доступно інтернету: " << getInternet() << "Mb" << endl;
		cout << "Операційна система " << getPhoneSystem() << endl;
		cout << "\n============================\n";
	}
};


// 2 Клас - холодильник
class Freezer {
private: 
	string brand;        // Марка холодильника
	int temperature;     // Температура в градусах Цельсія
	int capasity;        // Загальна ємність в літрах
	int freecapasity;    // Вільне місце у відсотках
	bool work;           // Стан роботи (0 - вимкнено, 1 - увімкнено)

public: 
	// Конструктор з параметрами
	Freezer(string brand, int temperature, int capasity, int freecapasity, bool work) {
		
		cout << "конструктор з параметрами, адреса -  " << this << endl;

		setBrand(brand);
		setTemperature(temperature);
		setCapasity(capasity);
		setFreecapasity(freecapasity);
		setWork(work);
	}
	// Конструктор делегування
	Freezer() : Freezer("bosch", 2, 300, 90, 1) {
		cout << "конструктор делегування, адреса -  " << this << endl;

	}
	// Конструктор копіювання - створення копії через делегування
	Freezer(const Freezer& copy) : Freezer(copy.brand, copy.temperature, copy.capasity, copy.freecapasity, copy.work) {
		cout << "конструктор копіювання, адреса - " << this << endl;
	}

	// Деструктор 
	~Freezer() {
		cout << "деструктор для адреси - " << this << endl;

	}
	//Сетери
	void setBrand(string brand = "Борисфен") {
		this->brand = brand;
	}

	void setTemperature(int temperature) {
		if (temperature < -20 || temperature > 20) {
			this->temperature = 3;
		}
		else { this->temperature = temperature; }
	}

	void setCapasity(int capasity) {
		if (capasity < 0) { this->capasity = 300; }
		else { this->capasity = capasity; }
	}

	void setFreecapasity(int freecapasity) {
		if (freecapasity < 0 || freecapasity > 100) {
			this->freecapasity = 90;
		}
		else { this->freecapasity = freecapasity; }
	}

	void setWork(bool work) {
		if (work != 0 && work != 1) { this->work = 0; }
		else { this->work = work; }
	}

	//Гетери
	string getBrand() const {
		return brand;
	}

	int getTemperature() const {
		return temperature;
	}

	int getCapasity() const {
		return capasity;
	}

	int getFreecapasity() const {
		return freecapasity;
	}

	bool getWork() const {
		return work;
	}


	// Інформація про холодильник
	void print_info() const{
		cout << "\n============================\n";
		cout << "Модель: " << getBrand() << endl;
		cout << "Ємність: " << getCapasity() << "л" << endl;
		cout << "Вільне місце: " << getFreecapasity() << "%" << endl;
		cout << "Температура: " << getTemperature() << " С" << endl;
		if (work) {
			cout << "Холодильник працює" << endl;
		}
		else {
			cout << "Холодильник не працює" << endl;
		}
		cout << "\n============================\n";
	}

	// Увімкнення холодильника
	void turn_on() {
		if (getWork() == 0) {
			setWork(1);
			setTemperature(1);
			cout << "Холодильник увімкнено" << endl;
		}
		else {
			cout << "Холодильник вже працює" << endl;
		}
	}

	// Покласти їжу
	void put_food() {
		if (getFreecapasity() > 0) {
			cout << "Їжа покладена в холодильник" << endl;
			freecapasity -= 10;
		}
		else {
			cout << "Немає місця в холодильнику" << endl;
		}
	}

	// Дістати їжу
	void take_food() {
		if (getFreecapasity() < 100) {
			cout << "Їжа взята з холодильника" << endl;
			freecapasity += 10;
		}
		else {
			cout << "Холодильник порожній" << endl;
		}
	}

};

// 3 Клас - кавоварка
class CoffeeMachine {
private: 
	string brand;     // Марка кавоварки
	bool water;       // Наявність води
	bool coffee;      // Наявність кави
	bool work;        // Стан роботи
	bool trash;       // Наявність відпрацьованої кави

	char* room = nullptr;

public: 
	// Конструктор з параметрами
	CoffeeMachine(string brand, bool water, bool coffee, bool work, bool trash, const char* r) {
		
		cout << "конструктор з параметрами, адреса -  " << this << endl;

		setRoom(r);
		setBrand(brand);
		setWater(water);
		setCoffee(coffee);
		setWork(work);
		setTrash(trash);
	}
	// Конструктор за замовчуванням що делегує роботу конструктору з параметрами
	CoffeeMachine() : CoffeeMachine("Philips", 0, 0, 0, 0, "Kitchen") {

		cout << "конструктор делегування, адреса -  " << this << endl;
	}
	// Конструктор копіювання
	CoffeeMachine(CoffeeMachine& second) {

		cout << "конструктор копіювання, адреса -  " << this << endl;

		brand = second.brand;
		water = second.water;
		coffee = second.coffee;
		work = second.work;
		trash = second.trash;
		room = new char[strlen(second.room) + 1];
		strcpy_s(room, strlen(second.room) + 1, second.room);

	}
	// Деструктор
	~CoffeeMachine() {
		cout << "деструктор для адреси - " << this << endl;
		delete[] room;

	}
	//Сетери
	void setRoom(const char* newRoom) {
		delete[] room;
		room = new char[strlen(newRoom) + 1];
		strcpy_s(room, strlen(newRoom) + 1, newRoom);

	}

	void setBrand(string brand = "Philips") {
		this->brand = brand;
	}

	void setWater(bool water) {
		if (water != 0 && water != 1) { this->water = 0; }
		else { this->water = water; }
	}

	void setCoffee(bool coffee) {
		if (coffee != 0 && coffee != 1) { this->coffee = 0;	}
		else { this->coffee = coffee; }
	}

	void setWork(bool work) {
		if (work != 0 && work != 1) { this->work = 0; }
		else { this->work = work; }
	}
	
	void setTrash(bool trash) {
		if (trash != 0 && trash != 1) { this->trash = 0; }
		else { this->trash = trash; }
	}

	//Гетери

	const char* getRoom() const {
		return room;

	}

	string getBrand() const {
		return brand;
	}

	bool getWater() const {
		return water;
	}

	bool getCoffee() const {
		return coffee;
	}

	bool getWork() const {
		return work;
	}

	bool getTrash() const {
		return trash;
	}

	// Виведення інформації про стан кавоварки
	void print_info() {

		cout << "\n============================\n";
		cout << "Бренд: " << getBrand() << endl;

		if (getWater()) { cout << "Вода є" << endl; }
		else { cout << "Вода відсутня" << endl; }

		if (getCoffee()) { cout << "Кавові зерна є" << endl; }
		else { cout << "Кавові зерна відсутні" << endl; }

		if (getWork()) { cout << "Кавоварка працює" << endl; }
		else { cout << "Кавоварка не працює" << endl; }

		if (getTrash()) { cout << "Сміття в контейнері" << endl; }
		else { cout << "Контейнер чистий" << endl; }

		cout << "Місце знаходження " << room;
		cout << "\n============================\n";
	}

	// Додати воду
	void add_water() {
		if (getWater() == 0) {
			setWater(1);
			cout << "Вода додана" << endl;
		}
		else {
			cout << "Вода вже є" << endl;
		}
	}

	// Додати каву
	void add_coffee() {
		if (getCoffee() == 0) {
			setCoffee(1);
			cout << "Кавові зерна додані" << endl;
		}
		else {
			cout << "Кавові зерна вже є" << endl;
		}
	}

	// Увімкнути кавоварку
	void turn_on() {
		if (getWork() == 0) {
			if (getWater() && getCoffee()) {
				setWork(1);
				cout << "Кавоварка увімкнена" << endl;
			}
			else { cout << "Необхідно додати воду та кавові зерна" << endl; }
		}
		else { cout << "Кавоварка вже працює" << endl; }
	}

	// Приготувати каву
	void make_coffee() {
		if (getWork()) {
			if (getWater() && getCoffee()) {
				cout << "Кава приготована" << endl;
				setTrash(1);                            // Контейнер для сміття заповнюється
				setWater(0);                            // Вода витрачається
				setCoffee(0);                           // Зерна витрачаються				
			}
			else { cout << "Необхідно додати воду та кавові зерна" << endl; }
		}
		else { cout << "Кавоварка не працює" << endl; }
	}

	// Очистка
	void clean() {
		if (getTrash()) {
			setTrash(0);
			cout << "Контейнер для сміття очищено" << endl;
		}
		else {
			cout << "Контейнер для сміття вже чистий" << endl;
		}
	}
};

// 4. Клас - персональний комп'ютер
class PersonalComputer {
private: 
	bool power;            // Стан живлення (увімкнено/вимкнено)
	int processor;         // Завантаження процесора у %
	int ram;               // Використання оперативної пам'яті у %
	int videocard;         // Завантаження відеокарти у %
	int hdd;               // Використання жорсткого диска у %

public: 
	// Конструктор з параметрами
	PersonalComputer(bool power, int processor, int ram, int videocard, int hdd) {

		cout << "конструктор з параметрами, адреса -  " << this << endl;

		setPower(power);
		setProcessor(processor);
		setRam(ram);
		setVideocard(videocard);
		setHdd(hdd);
	}

	// Конструктор делегування
	PersonalComputer() : PersonalComputer(0, 0, 0, 0, 30) {
		cout << "конструктор делегування, адреса -  " << this << endl;
	}

	// Конструктор копіювання
	PersonalComputer(PersonalComputer& pk2) : PersonalComputer(pk2.power, pk2.processor, pk2.ram, pk2.videocard, pk2.hdd) {
		cout << "конструктор копіювання, адреса - " << this << endl;
	}

	~PersonalComputer() {
		cout << "деструктор для адреси - " << this << endl;
	}

	//Сетери
	void setPower(bool power) {
		if (power != 0 && power != 1) { this->power = 0; }
		else { this->power = power; }
	}

	void setProcessor(int processor) {
		if ((processor < 0 || processor > 100)) { this->processor = 50; }
		else { this->processor = processor; }
	}

	void setRam(int ram) {
		if ((ram < 0 || ram > 100)) { this->ram = 30; }
		else { this->ram = ram; }
	}

	void setVideocard(int videocard) {
		if ((videocard < 0 || videocard > 100)) { this->videocard = 20; }
		else { this->videocard = videocard; }
	}

	void setHdd(int hdd) {
		if ((hdd < 0 || hdd > 100)) { this->hdd = 10; }
		else { this->hdd = hdd; }
	}

	//Гетери
	bool getPower() const {
		return power;
	}

	int getProcessor() const {
		return processor;
	}

	int getRam() const {
		return ram;
	}

	int getVideocard() const {
		return videocard;
	}	

	int getHdd() const {
		return hdd;
	}

	// Виведення інформації про стан комп'ютера
	void print_info() {
		cout << "\n============================\n";
		if (getPower()) { cout << "Комп'ютер увімкнено" << endl; }
		else { cout << "Комп'ютер вимкнено" << endl; }

		cout << "Використання процесора: " << getProcessor() << "%" << endl;
		cout << "Використання оперативної пам'яті: " << getRam() << "%" << endl;
		cout << "Використання відеокарти: " << getVideocard() << "%" << endl;
		cout << "Використання жорсткого диска: " << getHdd() << "%" << endl;
		cout << "\n============================\n";
	}

	// Увімкнути комп'ютер
	void turn_on() {
		if (getPower() == 0 ) {
			setPower(1);
			cout << "Комп'ютер увімкнено" << endl;
		}
		else {
			cout << "Комп'ютер вже працює" << endl;
		}
	}

	// Використання інтернету 
	void serf_internet() {
		if (getPower()) {
			cout << "Ви полізли в інтернет" << endl;
			processor += 10;
			ram += 20;
			videocard += 5;
			hdd += 2;
		}
		else {
			cout << "Комп'ютер вимкнено, увімкніть його" << endl;
		}
	}

	// Компьютерна гра
	void play_game() {
		if (getPower()) {
			cout << "Ви граєте в гру" << endl;
			processor += 20;
			ram += 30;
			videocard += 40;
			hdd += 10;			
		}
		else {
			cout << "Комп'ютер вимкнено, увімкніть його" << endl;
		}
	}

	// Завантаження фільму
	void download_movie() {
		if (getPower()) {
			cout << "Ви завантажили фільм" << endl;
			processor += 5;
			ram += 10;
			videocard += 5;
			hdd += 25; 
		}
		else {
			cout << "Комп'ютер вимкнено, увімкніть його" << endl;
		}
	}
};

// 5. Клас - пральна машина
class Washer {
private: 
	string brand;          // Марка пральної машини
	bool capasity;         // Наявність білизни
	bool powder;           // Наявність порошку
	int temperature;       // Температура прання
	bool work;             // Стан роботи

public: 
	// Конструктор з параметрами
	Washer(string brand, bool capasity, bool powder, int temperature, bool work) {

		cout << "конструктор з параметрами, адреса -  " << this << endl;

		setBrand(brand);
		setCapasity(capasity);
		setPowder(powder);
		setTemperature(temperature);
		setWork(work);
	}
	// Конструктор делегування
	Washer(): Washer("Beko", 0, 0, 10, 0) {
		cout << "конструктор делегування, адреса -  " << this << endl;

	}
	// Конструктор копіювання
	Washer(Washer& copy) : Washer(copy.brand, copy.capasity, copy.powder, copy.temperature, copy.work) {
		cout << "конструктор копіювання, адреса - " << this << endl;

	}
	~Washer() {
		cout << "деструктор для адреси - " << this << endl;

	}

	//Сетери
	void setBrand(string brand) {
		this->brand = brand;
	}

	void setCapasity(bool capasity) {
		if (capasity != 0 && capasity != 1) { this->capasity = 0; }
		else { this->capasity = capasity; }
	}

	void setPowder(bool powder) {
		if (powder != 0 && powder != 1) { this->powder = 0; }
		else { this->powder = powder; }
	}

	void setTemperature(int temperature) {
		if ((temperature < 0 || temperature > 100)) { this->temperature = 30; }
		else { this->temperature = temperature; }
	}

	void setWork(bool work) {
		if (work != 0 && work != 1) { this->work = 0; }
		else { this->work = work; }
	}

	//Гетери
	string getBrand() const {
		return brand;
	}

	bool getCapasity() const {
		return capasity;
	}

	bool getPowder() const {
		return powder;
	}

	int getTemperature() const {
		return temperature;
	}

	bool getWork() const {
		return work;
	}

	// Виведення інформації про пральну машину
	void print_info() {
		cout << "\n============================\n";

		cout << "Бренд: " << getBrand() << endl;

		if (getCapasity()) { cout << "Білизна завантажена" << endl; }
		else { cout << "Білизна відсутня" << endl; }

		if (getPowder()) { cout << "Пральний порошок додано" << endl; }
		else { cout << "Пральний порошок відсутній" << endl; }

		cout << "Температура прання: " << getTemperature() << " С" << endl;

		if (getWork()) { cout << "Пральна машина працює" << endl; }
		else { cout << "Пральна машина не працює" << endl; }

		cout << "\n============================\n";
	}

	// Додати білизну
	void add_clothes() {
		if (!getCapasity()) {
			setCapasity(1);
			cout << "Білизна додана до пральної машини" << endl;
		}
		else {
			cout << "Білизна вже завантажена" << endl;
		}
	}

	// Додати пральний порошок
	void add_powder() {
		if (!getPowder()) {
			setPowder(1);
			cout << "Пральний порошок додано" << endl;
		}
		else {
			cout << "Пральний порошок вже додано" << endl;
		}
	}

	// Увімкнути пральну машину
	void turn_on() {
		if (!getWork()) {
			if (getCapasity() && getPowder()) {
				setWork(1);
				cout << "Пральна машина увімкнена" << endl;
			}
			else {
				cout << "Необхідно додати білизну та пральний порошок" << endl;
			}
		}
		else {
			cout << "Пральна машина вже працює" << endl;
		}
	}

	// Режим делікатного прання
	void delicate_wash() {
		if (getWork()) {
			if (getCapasity() && getPowder()) {
				cout << "Делікатне прання завершено" << endl;
				setCapasity(0);
				setPowder(0);
				setWork(0);
			}
			else {
				cout << "Необхідно додати білизну та пральний порошок" << endl;
			}
		}
		else {
			cout << "Пральна машина не працює" << endl;
		}
	}

	// Режим швидкого прання
	void fast_wash() {
		if (getWork()) {
			if (getCapasity() && getPowder()) {
				cout << "Швидке прання завершено" << endl;
				setCapasity(0);
				setPowder(0);
				setWork(0);
			}
			else {
				cout << "Необхідно додати білизну та пральний порошок" << endl;
			}
		}
		else {
			cout << "Пральна машина не працює" << endl;
		}
	}

};

// Головна функція програми
int main() {
	
	SetConsoleOutputCP(1251);

	//--- Клас Телефон ---
	MobilePhone myphone;                                      // Створення об'єкта  
	myphone.print_info();                                     // Перевірка стану

	MobilePhone se("samsung", 80, 128, 80, 5000, "Windows");  // Створення об'єкта з параметрами 
	se.print_info();										  // Створення об'єкта-копії

	MobilePhone secopy = se;
	secopy.print_info();	

	myphone.download_foto();                                  // Завантаження фото
	myphone.play_game();                                      // Гра на телефоні
	myphone.serf_social();                                    // Перегляд соцмереж	        
	myphone.charge_battery();								  // Зарядка телефону
	myphone.print_info();            
	

	// --- Клас холодильник ---
	Freezer holodok;                                          // Створення об'єкта  
	holodok.print_info();									  // Перевірка стану

	Freezer samsung("Samsung", 5, 250, 50, 0);		          // Створення об'єкта з параметрами 
	samsung.print_info();

	Freezer copysam = samsung;							      // Створення об'єкта-копії 
	copysam.print_info();

	holodok.turn_on();									      // Увімкнення
	holodok.put_food();								  	      // Додавання їжі
	holodok.take_food();									  // Взяття їжі
	holodok.take_food();                 
	holodok.print_info();               

	// --- Клас кавомашина ---
	CoffeeMachine coffeeyok;                                  // Створення об'єкта  
	coffeeyok.print_info();                                   // Перевірка стану

	CoffeeMachine sim("Siemens", 1, 1, 0, 0, "Livingroom");   // Створення об'єкта з параметрами
	sim.print_info();

	CoffeeMachine sim2 = sim;								  // Створення об'єкта-копії
	sim2.print_info();
		      
	coffeeyok.add_water();								     // Додавання води
	coffeeyok.add_coffee();							  	     // Додавання зерен
	coffeeyok.turn_on();									 // Увімкнення
		          
	coffeeyok.make_coffee();							     // Приготування кави  
	coffeeyok.print_info();              
	coffeeyok.clean();									     // Очищення

	// --- Клас комп*ютер ---
	PersonalComputer comp;                                  // Створення об'єкта  
	comp.print_info();                                      // Перевірка стану

	PersonalComputer note(1, 30, 20, 10, 45);               // Створення об'єкта з параметрами
	note.print_info();

	PersonalComputer copynote = note;                       // Створення об'єкта-копії
	copynote.print_info();

	comp.play_game();                                      // Грати в гру
	comp.turn_on();                                        // Увімкнути
	comp.serf_internet();                                  // Інтернет	 
	comp.download_movie();                                 // Завантаження фільму
	comp.print_info();                                     // Перевірка стану

	// --- Клас пральна машина ---
	Washer stiralka;                                       // Створення об'єкта  
	stiralka.print_info();                                 // Перевірка стану

	Washer ind("Indesit", 1, 0, 40, 0);                    // Створення об'єкта з параметрами
	ind.print_info();

	Washer otherind = ind;                                 // Створення об'єкта-копії
	otherind.print_info();
		
	stiralka.add_clothes();                                 // Додати білизни
	stiralka.add_powder();                                  // Додати порошку
	stiralka.turn_on();                                     // Увімкнути
	stiralka.delicate_wash();                               // Делікатне прання
	stiralka.print_info();  
	
	
}
