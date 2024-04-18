#include <iostream>
#include <vector>

struct Size{
    size_t x;
    size_t y;
    size_t z;
};

class Lattice {
    private: //m for member
        Size m_size; //xyz dimensions
        std::vector<int> m_grid;

    public:
        Lattice (Size t_size): m_size(t_size), m_grid(m_size.x * m_size.y * m_size.z, 0) {
            std::cout << "Construcer run!!!\n" << std::endl; 
        }
    
    int getSpin(Size index) {
        return m_grid[index.x + index.y * m_size.x + index.z * m_size.x * m_size.y];
    }
    void fillRand() {
        for(auto &v: m_grid){
            v = rand() % 2;
            // std::cout << v << std::endl;
        }
    }
};


int main(int argc, char const *argv[])
{
    Size mySize = {10, 10, 10};
    Lattice myLattice(mySize);
    myLattice.fillRand();
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            for (size_t k = 0; k < 10; k++)
            {
                Size myIndex = {i, j, k};
                std::cout << myLattice.getSpin(myIndex);
            }
        std::cout << "\n";
        }
    }
    return 0;
}
