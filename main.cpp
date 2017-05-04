#include <cstdint>
#include <cstdlib>
#include <iostream>
//#include <vector>

using namespace std;
struct vector
{

    typedef uint64_t value_type;

       vector()
    {
        data = nullptr;
        size = 0;
    }

    vector(vector const& other)
    {
        data = (value_type*)malloc(other.size * sizeof(value_type));
        for (size_t i = 0; i != other.size; ++i)
            data[i] = other.data[i];
        size = other.size;
    }

    ~vector()
    {
        free(data);
    }

    vector& operator=(vector const& rhs)
    {
        if (this != &rhs)
        {
            free(data);
    
            data = (value_type*)malloc(rhs.size * sizeof(value_type));
            for (size_t i = 0; i != rhs.size; ++i)
                data[i] = rhs.data[i];
            size = rhs.size;
        }

        return *this;
    }

    void push_back(value_type val)
    {
        if(size==capacity)
        {
            size_t new_capacity =  capacity*2;
            value_type*new_data=(value_type*)malloc(new_capacity*sizeof(value_type));

            for(size_t i=0;i!=size;++i)
                new_data[i]=data[i];

            free(data);

            data=new_data;
            capacity=new_capacity;
        }
        data[size]=val;
        ++size;
    }



    value_type& operator[](size_t i)
    {
        return data[i];
    }

private:

    value_type capacity = 0;
    value_type* data;
    size_t size;
};

void escape(void* p)
{
    asm volatile("" : : "g"(p) : "memory");
}

void clobber()
{
    asm volatile("" : : : "memory");
}

int main()
{
 //std::vector<uint64_t> v;
    vector v;
    for (uint64_t i = 15; i != 20; ++i)
        v.push_back(i);

// vector vv = v;
    for (uint64_t i = 0; i != 3; ++i)
  cout<<v[i]<<endl;
// cout<<vv[0]<<vv[1]<<vv[3]<<endl;
    escape(&v);

    return 0;
}
