#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// Общий ресурс
int bank_account = 100; 
std::mutex account_mutex; // Мьютекс для защиты счета

// Функция, которую будут выполнять потоки
void withdraw(const std::string& name, int amount) {
    // Блокируем мьютекс перед работой с общим ресурсом
    std::lock_guard<std::mutex> lock(account_mutex);
    
    // Критическая секция (безопасный доступ к bank_account)
    if (bank_account >= amount) {
        std::cout << name << " снимает " << amount << " руб. ";
        bank_account -= amount;
        std::cout << "Остаток: " << bank_account << " руб.\n";
    } else {
        std::cout << name << " хотел снять " << amount 
                  << " руб., но недостаточно средств! Остаток: " 
                  << bank_account << " руб.\n";
    }
    // Здесь lock_guard автоматически уничтожается и освобождает мьютекс
}

int main() {
    // Создаем два потока (муж и жена), которые одновременно вызывают функцию
    std::thread husband(withdraw, "Муж", 70);
    std::thread wife(withdraw, "Жена", 50);

    // Ожидаем завершения обоих потоков
    husband.join();
    wife.join();

    std::cout << "Итоговый баланс в конце дня: " << bank_account << " руб.\n";
    return 0;
}