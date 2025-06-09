#include <iostream> 
#include <string>   
#include <windows.h> 

using namespace std;

// Оголошення класу для представлення мобільного телефону
class MobilePhone {
private: 
	string model = "Xiaomi_Redmi_Note_14"; // Модель телефону
	int battery = 100; // Рівень заряду батареї у відсотках
	int storage = 256; // Загальний обсяг пам'яті в Гб
	int freespace = 100; // Вільний простір у відсотках
	int internet_available = 10240; // Доступний інтернет-трафік в Мб

public: 
	// Метод для виведення інформації про телефон на консоль
	void print_info() {
		cout << "\n============================\n";
		cout << "Модель: " << model << endl;
		cout << "Батарея: " << battery << "%" << endl;
		cout << "Пам'ять: " << storage << "Gb" << endl;
		cout << "Доступно пам'яті: " << freespace << "%" << endl;
		cout << "Доступно інтернету: " << internet_available << "Mb" << endl;
		cout << "\n============================\n";
	}

	// Метод для зміни моделі та обсягу пам'яті телефону
	void change_info(string m, int s) {
		model = m;
		storage = s;
	}

	// Метод для зарядки батареї до 100%
	void charge_battery() {
		if (battery < 100) {
			battery = 100;
		}
		else cout << "телефон заряджено";

	}

	// Метод, що імітує гру на телефоні, зменшуючи пам'ять та заряд батареї
	void play_game() {
		if (freespace > 0 && battery > 0) {
			cout << "граємо в гру" << endl;
			freespace -= 10;
			battery -= 5;
		}
		else {
			cout << "недостатньо пам'яті або інтернету для гри" << endl;
		}
	}

	// Метод, що імітує завантаження фото, зменшуючи інтернет-трафік та вільну пам'ять
	void download_foto() {
		if (internet_available > 0 && freespace > 0) {
			cout << "завантажено фото" << endl;
			internet_available -= 5;
			freespace -= 2;
		}
		else {
			cout << "недостатньо пам'яті або інтернету для завантаження" << endl;
		}
	}

	// Метод, що імітує перегляд соціальних мереж, зменшуючи трафік та пам'ять
	void serf_social() {
		if (internet_available > 0 && freespace > 0) {
			cout << "пішли дивитись відяшки: тум тум тум сахур!!!" << endl;
			internet_available -= 10;
			freespace -= 5;
		}
		else {
			cout << "недостатньо пам'яті або інтернету для перегляду відяшок" << endl;
		}
	}
};


// Оголошення класу для представлення холодильника
class Freezer {
private: 
	string brand = "Борисфен"; // Марка холодильника
	int temperature = 3; // Температура в градусах Цельсія
	int capasity = 150; // Загальна ємність в літрах
	int freecapasity = 100; // Вільна ємність у відсотках
	bool work = 0; // Стан роботи (0 - вимкнено, 1 - увімкнено)

public: 
	// Метод для виведення інформації про холодильник
	void print_info() {
		cout << "\n============================\n";
		cout << "Модель: " << brand << endl;
		cout << "Ємність: " << capasity << "л" << endl;
		cout << "Вільне місце: " << freecapasity << "%" << endl;
		cout << "Температура: " << temperature << " С" << endl;
		if (work) {
			cout << "Холодильник працює" << endl;
		}
		else {
			cout << "Холодильник не працює" << endl;
		}
		cout << "\n============================\n";
	}

	// Метод для зміни марки та ємності холодильника
	void change_brand(string b, int c) {
		brand = b;
		capasity = c;
	}

	// Метод для увімкнення холодильника
	void turn_on() {
		if (!work) {
			work = true;
			temperature = 1;
			cout << "Холодильник увімкнено" << endl;
		}
		else {
			cout << "Холодильник вже працює" << endl;
		}
	}

	// Метод, що імітує додавання їжі в холодильник
	void put_food() {
		if (freecapasity > 0) {
			cout << "Їжа покладена в холодильник" << endl;
			freecapasity -= 10;
		}
		else {
			cout << "Немає місця в холодильнику" << endl;
		}
	}

	// Метод, що імітує взяття їжі з холодильника
	void take_food() {
		if (freecapasity < 100) {
			cout << "Їжа взята з холодильника" << endl;
			freecapasity += 10;
		}
		else {
			cout << "Холодильник порожній" << endl;
		}
	}

};

// Оголошення класу для представлення кавоварки
class coffee_machine {
private: 
	string brand = "Philips"; // Марка кавоварки
	bool water = 0; // Наявність води
	bool coffee_beans = 0; // Наявність кавових зерен
	bool work = 0; // Стан роботи
	bool trash = 0; // Наявність сміття (відпрацьованої кави)

public: 

	// Метод для виведення інформації про стан кавоварки
	void print_info() {
		cout << "\n============================\n";
		cout << "Бренд: " << brand << endl;
		if (water) {
			cout << "Вода є" << endl;
		}
		else {
			cout << "Вода відсутня" << endl;
		}
		if (coffee_beans) {
			cout << "Кавові зерна є" << endl;
		}
		else {
			cout << "Кавові зерна відсутні" << endl;
		}
		if (work) {
			cout << "Кавоварка працює" << endl;
		}
		else {
			cout << "Кавоварка не працює" << endl;
		}
		if (trash) {
			cout << "Сміття в контейнері" << endl;
		}
		else {
			cout << "Контейнер чистий" << endl;
		}
		cout << "\n============================\n";
	}

	// Метод для додавання води
	void add_water() {
		if (!water) {
			water = true;
			cout << "Вода додана" << endl;
		}
		else {
			cout << "Вода вже є" << endl;
		}
	}

	// Метод для додавання кавових зерен
	void add_coffee() {
		if (!coffee_beans) {
			coffee_beans = true;
			cout << "Кавові зерна додані" << endl;
		}
		else {
			cout << "Кавові зерна вже є" << endl;
		}
	}

	// Метод для увімкнення кавоварки
	void turn_on() {
		if (!work) {
			if (water && coffee_beans) {
				work = true;
				Beep(523, 150);  
				Beep(659, 150);
				Beep(784, 200); Sleep(575); 
				cout << "Кавоварка увімкнена" << endl;
			}
			else {
				cout << "Необхідно додати воду та кавові зерна" << endl;
			}
		}
		else {
			cout << "Кавоварка вже працює" << endl;
		}
	}

	// Метод для приготування кави
	void make_coffee() {
		if (work) {
			if (water && coffee_beans) {
				cout << "Кава приготована" << endl;
				trash = true; // Контейнер для сміття заповнюється
				water = false; // Вода витрачається
				coffee_beans = false; // Зерна витрачаються
				// Відтворення мелодії
				Beep(440, 500); Beep(440, 500); Beep(440, 500);
				Beep(349, 350); Beep(523, 150);
				Beep(440, 500); Beep(349, 350); Beep(523, 150);
				Beep(440, 1000); Sleep(575);
			}
			else {
				cout << "Необхідно додати воду та кавові зерна" << endl;
			}
		}
		else {
			cout << "Кавоварка не працює" << endl;
		}
	}

	// Метод для очищення контейнера для сміття
	void clean() {
		if (trash) {
			trash = false;
			cout << "Контейнер для сміття очищено" << endl;
		}
		else {
			cout << "Контейнер для сміття вже чистий" << endl;
		}
	}
};

// Оголошення класу для представлення персонального комп'ютера
class personal_computer {
private: 
	bool power = 0; // Стан живлення (увімкнено/вимкнено)
	int processor_using = 0; // Завантаження процесора у %
	int ram_using = 0; // Використання оперативної пам'яті у %
	int videocard_using = 0; // Завантаження відеокарти у %
	int hdd_using = 20; // Використання жорсткого диска у %

public: 
	// Метод для виведення інформації про стан комп'ютера
	void print_info() {
		cout << "\n============================\n";
		if (power) {
			cout << "Комп'ютер увімкнено" << endl;
		}
		else {
			cout << "Комп'ютер вимкнено" << endl;
		}
		cout << "Використання процесора: " << processor_using << "%" << endl;
		cout << "Використання оперативної пам'яті: " << ram_using << "%" << endl;
		cout << "Використання відеокарти: " << videocard_using << "%" << endl;
		cout << "Використання жорсткого диска: " << hdd_using << "%" << endl;
		cout << "\n============================\n";
	}

	// Метод для увімкнення комп'ютера
	void turn_on() {
		if (!power) {
			power = true;
			cout << "Комп'ютер увімкнено" << endl;
		}
		else {
			cout << "Комп'ютер вже працює" << endl;
		}
	}

	// Метод, що імітує серфінг в інтернеті, збільшуючи навантаження на компоненти
	void serf_internet() {
		if (power) {
			cout << "Ви полізли в інтернет" << endl;
			processor_using += 10;
			ram_using += 20;
			videocard_using += 5;
			hdd_using += 2;
		}
		else {
			cout << "Комп'ютер вимкнено, увімкніть його" << endl;
		}
	}

	// Метод, що імітує гру, значно збільшуючи навантаження на компоненти
	void play_game() {
		if (power) {
			cout << "Ви граєте в гру" << endl;
			processor_using += 20;
			ram_using += 30;
			videocard_using += 40;
			hdd_using += 10;
			Beep(660, 100); Sleep(100);
			Beep(660, 100); Sleep(300);
			Beep(660, 100); Sleep(300);
			Beep(510, 100); Sleep(100);
			Beep(660, 100); Sleep(300);
			Beep(770, 100); Sleep(550);
			Beep(380, 100); Sleep(575);
		}
		else {
			cout << "Комп'ютер вимкнено, увімкніть його" << endl;
		}
	}

	// Метод, що імітує завантаження фільму
	void download_movie() {
		if (power) {
			cout << "Ви завантажили фільм" << endl;
			processor_using += 5;
			ram_using += 10;
			videocard_using += 5;
			hdd_using += 25;
		}
		else {
			cout << "Комп'ютер вимкнено, увімкніть його" << endl;
		}
	}
};

// Оголошення класу для представлення пральної машини
class washer {
private: 
	string brand = "LG"; // Марка пральної машини
	bool capasity = 0; // Наявність білизни
	bool powder = 0; // Наявність порошку
	int temperature = 30; // Температура прання
	bool work = 0; // Стан роботи

public: 
	// Метод для виведення інформації про стан пральної машини
	void print_info() {
		cout << "\n============================\n";
		cout << "Бренд: " << brand << endl;
		if (capasity) {
			cout << "Завантаження білизни є" << endl;
		}
		else {
			cout << "Завантаження білизни відсутнє" << endl;
		}
		if (powder) {
			cout << "Пральний порошок додано" << endl;
		}
		else {
			cout << "Пральний порошок відсутній" << endl;
		}
		cout << "Температура прання: " << temperature << " С" << endl;
		if (work) {
			cout << "Пральна машина працює" << endl;
		}
		else {
			cout << "Пральна машина не працює" << endl;
		}
		cout << "\n============================\n";
	}

	// Метод для зміни марки пральної машини
	void change_brand(string b) {
		brand = b;
	}

	// Метод для зміни температури прання з перевіркою діапазону
	void change_temperature(int t) {
		if (t >= 30 && t <= 90) {
			temperature = t;
			cout << "Температура прання змінена на " << temperature << " С" << endl;
		}
		else {
			cout << "Недійсна температура. Введіть значення від 30 до 90 градусів." << endl;
		}
	}

	// Метод для додавання білизни
	void add_clothes() {
		if (!capasity) {
			capasity = true;
			cout << "Білизна додана до пральної машини" << endl;
		}
		else {
			cout << "Білизна вже завантажена" << endl;
		}
	}

	// Метод для додавання прального порошку
	void add_powder() {
		if (!powder) {
			powder = true;
			cout << "Пральний порошок додано" << endl;
		}
		else {
			cout << "Пральний порошок вже додано" << endl;
		}
	}

	// Метод для увімкнення пральної машини
	void turn_on() {
		if (!work) {
			if (capasity && powder) {
				work = true;
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

	// Метод, що імітує режим делікатного прання
	void delicate_wash() {
		if (work) {
			if (capasity && powder) {
				cout << "Делікатне прання завершено" << endl;
				capasity = false;
				powder = false;
				work = false;
			}
			else {
				cout << "Необхідно додати білизну та пральний порошок" << endl;
			}
		}
		else {
			cout << "Пральна машина не працює" << endl;
		}
	}

	// Метод, що імітує режим швидкого прання
	void fast_wash() {
		if (work) {
			if (capasity && powder) {
				cout << "Швидке прання завершено" << endl;
				capasity = false;
				powder = false;
				work = false;
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

	// --- Демонстрація роботи класу MobilePhone ---
	MobilePhone myphone; // Створення об'єкта класу MobilePhone

	myphone.print_info(); // Виведення початкової інформації
	myphone.change_info("Samsung_S23", 256); // Зміна параметрів телефону
	myphone.print_info(); // Виведення оновленої інформації

	myphone.download_foto(); // Завантаження фото

	myphone.play_game(); // Гра на телефоні
	myphone.print_info(); // Перевірка стану після гри

	myphone.serf_social(); // Перегляд соцмереж
	myphone.print_info(); // Перевірка стану

	myphone.charge_battery(); // Зарядка телефону
	myphone.print_info(); // Перевірка стану після зарядки

	// --- Демонстрація роботи класу Freezer ---
	Freezer holodok; // Створення об'єкта класу Freezer

	holodok.print_info(); // Виведення початкової інформації
	holodok.change_brand("Saturn", 200); // Зміна параметрів
	holodok.print_info(); // Виведення оновленої інформації

	holodok.turn_on(); // Увімкнення
	holodok.put_food(); // Додавання їжі
	holodok.print_info(); // Перевірка стану

	holodok.take_food(); // Взяття їжі
	holodok.take_food(); // Ще раз взяття їжі
	holodok.print_info(); // Перевірка стану

	// --- Демонстрація роботи класу coffee_machine ---
	coffee_machine coffeeyok; // Створення об'єкта класу coffee_machine

	coffeeyok.print_info(); // Виведення початкового стану
	coffeeyok.make_coffee(); // Спроба зробити каву без інгредієнтів

	coffeeyok.add_water(); // Додавання води
	coffeeyok.add_coffee(); // Додавання зерен
	coffeeyok.turn_on(); // Увімкнення

	coffeeyok.print_info(); // Перевірка стану готовності
	coffeeyok.make_coffee(); // Приготування кави

	coffeeyok.print_info(); // Перевірка стану після приготування
	coffeeyok.clean(); // Очищення

	// --- Демонстрація роботи класу personal_computer ---
	personal_computer pekarnya; // Створення об'єкта класу personal_computer

	pekarnya.print_info(); // Початковий стан
	pekarnya.play_game(); // Спроба пограти на вимкненому ПК
	pekarnya.turn_on(); // Увімкнення
	pekarnya.serf_internet(); // Серфінг в інтернеті
	pekarnya.play_game(); // Гра
	pekarnya.download_movie(); // Завантаження фільму
	pekarnya.print_info(); // Перевірка навантаження на систему

	// --- Демонстрація роботи класу washer ---
	washer stiralka; // Створення об'єкта класу washer
	stiralka.print_info(); // Початковий стан
	stiralka.change_brand("Bosch"); // Зміна марки
	stiralka.change_temperature(60); // Зміна температури
	stiralka.print_info(); // Перевірка змін
	stiralka.add_clothes(); // Додавання білизни
	stiralka.add_powder(); // Додавання порошку
	stiralka.turn_on(); // Увімкнення
	stiralka.print_info(); // Перевірка стану перед пранням
	stiralka.delicate_wash(); // Запуск делікатного прання
	stiralka.fast_wash(); // Спроба запустити прання, коли машина вже завершила цикл і вимкнулась
}