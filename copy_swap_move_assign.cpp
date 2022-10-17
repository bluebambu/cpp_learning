#include <iostream>

class Intvec
{
public:
    explicit Intvec(size_t num = 0)
        : m_size(num), m_data(new int[m_size])
    {
        log("constructor");
    }

    ~Intvec()
    {
        log("destructor");
        if (m_data) {
            delete[] m_data;
            m_data = 0;
        }
    }

    // copy ctor
    Intvec(const Intvec& other)
        : m_size(other.m_size), m_data(new int[m_size])
    {
        log("copy constructor");
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }

    // copy assignment
    Intvec& operator=(const Intvec& other)
    {
        log("copy assignment operator");
        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }

    // move assignment for rvalue reference
    Intvec& operator=(Intvec&& other)
    {
        log("copy assignment operator");
        std::swap(m_size, other.m_size);
        std::swap(m_data, other.m_data);
        return *this;
    }

private:
    void log(const char* msg)
    {
        std::cout << "[" << this << "] " << msg << "\n";
    }

    size_t m_size;
    int* m_data;
};

int main () {
	Intvec v2;

	// colorful output
	std::cout << "\033[1;31m assigning lvalue...\033[0m \n";
	// copy assign with a rvalue !
	v2 = Intvec(2);
	std::cout << "\033[1;31m ended assigning lvalue...\033[0m \n";
}

