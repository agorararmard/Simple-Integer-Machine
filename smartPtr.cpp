template <class T>
class smartPtr{
    T* ptr; 
public:
    smartPtr(){}
    smartPtr(T* a):ptr(a){}
    smartPtr operator=(T* a){
        ptr = a;
        return ptr;
    }
    bool operator==(T* a){
        return (ptr == a);
    }
    bool operator!=(T* a){
        return (ptr != a);
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }
    ~smartPtr(){
        if(ptr!=nullptr)
            delete ptr;
    }
};
