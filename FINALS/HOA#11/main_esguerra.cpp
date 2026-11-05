#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

//ILO A
class Student
{
private:
    std::pair<int, int> name;
    bool vaccinated;


public:
    // constructor
    Student(std::pair<int, int> n, bool v) : name(n), vaccinated(v)
    {
    }
    // Getters
    auto get_name() { return name; }
    auto is_vaccinated() { return vaccinated; }


    // Two people are same if they have the same name
    bool operator==(const Student &p) const
    {
        return this->name == p.name;
    }
    // The ordering of a set of people is defined by their name
    bool operator<(const Student &p) const
    {
        return this->name < p.name;
    }
    bool operator>(const Student &p) const
    {
        return this->name > p.name;
    }
};


auto generate_random_Student(int max)
{
    std::random_device rd;
    std::mt19937 rand(rd());
    // the IDs of Student should be in range [1, max]
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, max);


    // Generate random credentials
    auto random_name = std::make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated = uniform_dist(rand) % 2 ? true : false;
    return Student(random_name, is_vaccinated);
}


bool needs_vaccination(Student P, std::vector<Student> &people)
{
    auto first = people.begin();
    auto last = people.end();
    while (true)
    {
        auto range_length = std::distance(first, last);
        auto mid_element_index = std::floor(range_length / 2);
        auto mid_element = *(first + mid_element_index);


        // Return true if the Student is found in the sequence and
        // he/she's not vaccinated
        if (mid_element == P && mid_element.is_vaccinated() == false)
            return true;


        else if (mid_element == P && mid_element.is_vaccinated() == true)
            return false;


        else if (mid_element > P)
            std::advance(last, -mid_element_index);


        if (mid_element < P)
            std::advance(first, mid_element_index);


        // Student not found in the sequence and therefore should be vaccinated
        if (range_length == 1)
            return true;
    }
}


void search_test(int size, Student p)
{
    std::vector<Student> people;
    // Create a list of random people
    for (auto i = 0; i < size; i++)
        people.push_back(generate_random_Student(size));


    std::sort(people.begin(), people.end());


    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();


    bool search_result = needs_vaccination(p, people);


    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken to search = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;
    if (search_result)
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
                  << ") " << "needs vaccination." << std::endl;
    else
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
                  << ") " << "does not need vaccination." << std::endl;
}


int main()
{
    // Generate a Student to search
    auto p = generate_random_Student(1000);
    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);
    return 0;
}


// ILO B
bool unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false; // Duplicate found
            }
        }
    }
    return true; // All elements are unique
}

int main() {
    std::vector<int> array1 = {1, 2, 3, 4};
    std::vector<int> array2 = {1, 2, 3, 1};
    
    std::cout << std::boolalpha; // Prints true/false instead of 1/0
    std::cout << unique(array1) << std::endl; // Prints true
    std::cout << unique(array2) << std::endl; // Prints false
    return 0;
}

//Supplementary Prob 1
#include <iostream>
#include <vector>
#include <chrono>
 
// returns true if all elements in A are unique
bool Unique(std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j])
                return false;
        }
    }
    return true;
}
 
// Worst case: all elements unique, so every pair is compared -> n(n-1)/2 comparisons
void worst_case_test(int size) {
    std::vector<int> A(size);
    for (int i = 0; i < size; i++)
        A[i] = i + 1;                      
 
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool result = Unique(A);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
 
    std::cout << "Worst case, n = " << size << std::endl;
    std::cout << "Time taken = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;
    std::cout << "Unique returned " << result << std::endl << std::endl;
}
 
// Best case: A[0] == A[1], so Unique stops after 1 comparison
void best_case_test(int size) {
    std::vector<int> A(size);
    for (int i = 0; i < size; i++)
        A[i] = i + 1;
    A[1] = A[0];                          
 
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool result = Unique(A);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
 
    std::cout << "Best case, n = " << size << std::endl;
    std::cout << "Time taken = "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
              << " nanoseconds" << std::endl;
    std::cout << "Unique returned " << result << std::endl << std::endl;
}
 
int main() {
    worst_case_test(1000);
    worst_case_test(10000);
    worst_case_test(100000);    
 
    best_case_test(1000);
    best_case_test(10000);
    best_case_test(100000);
    return 0;
}

//Supplementary Prob 2
#include <iostream>
#include <chrono>
 
typedef unsigned long long ull;
 
const int RUNS_R = 1000;        
const int RUNS_B = 1000000;     
 
// O(n): n recursive calls
ull rpower(ull x, int n) {
    if (n == 0) return 1;
    else return x * rpower(x, n - 1);
}
 
// O(log n): n is halved every call
ull brpower(ull x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        ull y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }
    else {
        ull y = brpower(x, n / 2);
        return y * y;
    }
}
 
// times both algorithms for the same n
void power_test(int n) {
    volatile ull result;                    
 
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int r = 0; r < RUNS_R; r++)
        result = rpower(2, n);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long long time_r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / RUNS_R;
 
    begin = std::chrono::steady_clock::now();
    for (int r = 0; r < RUNS_B; r++)
        result = brpower(2, n);
    end = std::chrono::steady_clock::now();
    long long time_b = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / RUNS_B;
 
    std::cout << "n = " << n << std::endl;
    std::cout << "rpower  average time taken = " << time_r << " nanoseconds" << std::endl;
    std::cout << "brpower average time taken = " << time_b << " nanoseconds" << std::endl << std::endl;
}
 
int main() {
    power_test(1000);
    power_test(2000);
    power_test(4000);
    power_test(8000);
 
    return 0;
}
