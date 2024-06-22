#include <iostream>
#include <queue>
#include <functional>

void ejemplo_1() {
  std::priority_queue<int> pq; // Big O(1)
  pq.push(1);                  // log(n)
  pq.push(20);                 // log(n)
  pq.push(5);                  // log(n)
  pq.push(7);
  pq.push(3);
  pq.push(35);
  pq.push(2);                  // log(n)
  // Big O(nlog(n))
 
  std::cout << pq.top() << std::endl;
  pq.pop();
  std::cout << pq.top() << std::endl;
}

void ejemplo_2() {
  std::vector<int> v = {1, 20, 5, 7, 3, 35, 2};
  // std::less
  // std::greater
  std::priority_queue<int, std::vector<int>, std::less<>> pq(std::less<>(), v); // Big O(n)
  std::cout << pq.top() << std::endl;
  pq.pop();   // Big O(log n)
  std::cout << pq.top() << std::endl;
}


// Funcion Objeto

// Template Base
template <typename T = void>
struct menor_que {
  bool operator() (T a, T b) const {
    return a < b;
  }
};

// Template Especializado (especialización total)
template <>
struct menor_que<void> {
  template <typename T>
  bool operator() (T a, T b) const {
    return a < b;
  }
};

void ejemplo_3() {
  std::vector<int> v = {1, 20, 5, 7, 3, 35, 2};
  // std::less
  // std::greater
  std::priority_queue<int, std::vector<int>, menor_que<>> pq(menor_que<>(), v); // Big O(n)
  std::cout << pq.top() << std::endl;
  pq.pop();   // Big O(log n)
  std::cout << pq.top() << std::endl;
}

class Persona {
  std::string nombre;
  int edad  = 0;
public:
  Persona() = default;
  Persona(std::string nombre, int edad): nombre(std::move(nombre)), edad(edad) {}
  [[nodiscard]] std::string get_nombre() const { return nombre; }
  [[nodiscard]] int get_edad() const { return edad; }
  bool operator<(const Persona& other) const {
    return edad < other.edad;
  }
  bool operator>(const Persona& other) const {
    return edad > other.edad;
  }
  friend std::ostream& operator << (std::ostream& os, const Persona& p) {
    os << p.nombre << " " << p.edad;
    return os;
  }
};

void ejemplo_4() {
  std::vector<Persona> v = { {"Daniel", 20}, {"Zaira", 10}, {"Ada", 15}, {"Pedro", 50}};
  std::priority_queue<Persona, std::vector<Persona>, std::less<>> pq_1(std::less<>(), v);
  std::cout << pq_1.top() << std::endl;
  pq_1.pop();
  std::cout << pq_1.top() << std::endl;

  std::priority_queue<Persona, std::vector<Persona>, std::greater<>> pq_2(std::greater<>(), v);
  std::cout << pq_2.top() << std::endl;
  pq_2.pop();
  std::cout << pq_2.top() << std::endl;
}

void ejemplo_5() {
  std::vector<Persona> v = { {"Daniel", 20}, {"Zaira", 10}, {"Ada", 15}, {"Pedro", 50}};
  auto compare_nombre_menor_que = [](auto a, auto b) { return a.get_nombre() < b.get_nombre(); };
  auto compare_nombre_mayor_que = [](auto a, auto b) { return a.get_nombre() > b.get_nombre(); };
  std::priority_queue<Persona, std::vector<Persona>, decltype(compare_nombre_menor_que)> pq_1(compare_nombre_menor_que, v);
  std::cout << pq_1.top() << std::endl;
  pq_1.pop();
  std::cout << pq_1.top() << std::endl;
  std::priority_queue<Persona, std::vector<Persona>, decltype(compare_nombre_mayor_que)> pq_2(compare_nombre_mayor_que, v);
  std::cout << pq_2.top() << std::endl;
  pq_2.pop();
  std::cout << pq_2.top() << std::endl;
}

void ejemplo_6() {
  std::vector<Persona> v = { {"Daniel", 20}, {"Zaira", 10}, {"Ada", 15}, {"Pedro", 50}};
  auto compare_nombre_menor_que = [](auto a, auto b) { return a.get_nombre() < b.get_nombre(); };
  auto compare_nombre_mayor_que = [](auto a, auto b) { return a.get_nombre() > b.get_nombre(); };
  std::priority_queue<Persona, std::vector<Persona>, std::function<bool(Persona, Persona)>> pq_1(compare_nombre_menor_que, v);
  std::cout << pq_1.top() << std::endl;
  pq_1.pop();
  std::cout << pq_1.top() << std::endl;
  std::priority_queue<Persona, std::vector<Persona>, std::function<bool(Persona, Persona)>> pq_2(compare_nombre_mayor_que, v);
  std::cout << pq_2.top() << std::endl;
  pq_2.pop();
  std::cout << pq_2.top() << std::endl;
}


int main() {
//  ejemplo_1();
//  ejemplo_2();
//  ejemplo_3();
//  ejemplo_4();
//  ejemplo_5();
  ejemplo_6();
  return 0;
}
