/*This illustrate template classes.
Note that the implementation must be in the header file!*/

template <typename T>
class foo
{
public:
	foo();
	T get();
private:
	T x;
};

template <typename T>
foo<T>::foo()
{
	x = 10;
}

template <typename T>
T foo<T>::get()
{
	return x;
}

