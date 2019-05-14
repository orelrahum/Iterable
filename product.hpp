#include <utility> 

namespace itertools
{


template <class T, class E>

class product
{
private:
    T iterat1;    
    E iterat2;    

    template <typename U, typename V>
    class iterator
    {
    public:
        U itr1; 
        V itr2; 
        V itr3; 

        iterator(U iteratable_A, V iteratable_B) : 
            itr1(iteratable_A), 
            itr2(iteratable_B),
            itr3(iteratable_B) {}

        bool operator!=(product::iterator<U,V> const &other) 
        {            
            if ((itr1 != other.itr1) && !(itr2 != other.itr2))
            {
                itr2 = itr3;
                ++itr1;
            }

            return (itr1 != other.itr1);
        }

        std::pair<decltype(*itr1),decltype(*itr2)> operator*() const
        {
            return std::pair< decltype(*itr1),
                              decltype(*itr2)> (*itr1,*itr2);
        }

        product::iterator<U,V> &operator++()
        {
            ++itr2;
            return *this;
        }
    };

public:
    product(T from, E to) : iterat1(from), iterat2(to) {} // constructor

    auto begin() const{ 
        return  product::iterator<decltype(iterat1.begin()),decltype(iterat2.begin())>(iterat1.begin(), iterat2.begin()); }  

    auto end() const {
        return product::iterator<decltype(iterat1.end()),decltype(iterat2.end())>(iterat1.end(), iterat2.end()); }  
};  // class

template <typename T, typename E>

product<T, E> myproduct(T first, E second)
{
    return product<T, E>(first, second);
}

} 
