#include <iostream>
using namespace std;

template <typename T> class myVector{
private:
    T* data;
    size_t m_size;
    size_t m_capacity;
public:
    myVector(){
        data=NULL;
        m_size=0;
        m_capacity=0;
    }
    ~myVector(){
        delete[] data;
    }
    size_t size(){
        return m_size;
    }
    size_t capacity(){
        return m_capacity;
    }
    T& operator[](size_t index){
        return data[index];
    }
    void reallocate(){
        size_t newCapacity = m_capacity==0? 1: (m_capacity*2);
        T* newData = new T[newCapacity];
        for(size_t i=0; i<m_size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data=newData;
        m_capacity=newCapacity;
    }
    void push_back(const T& value){
        if(m_size==m_capacity)
            reallocate();
        data[m_size]=value;
        m_size++;
    }
};

int main() {
    myVector<double> v;
    v.push_back(2.1);
    v.push_back(3.1);
    v.push_back(4.5);
    for(size_t i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
