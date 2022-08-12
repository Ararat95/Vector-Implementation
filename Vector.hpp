Vector::Vector ()
{
    _size = 0;
    _capacity = 1;
    _arr = new int [_capacity];
    _index = _arr;
}

Vector::Vector (int capacity)
{
    if(capacity > 0)
    {
        _capacity = capacity;
        _size = 0;
        _arr = new int [_capacity];
        _index = _arr;
    }
    else
    {
        std::cout << "undefined behaifor\n";
    }
}

Vector::Vector (int capacity, int value)
{
    if(capacity > 0)
    {
        _capacity = capacity;
        _size = capacity;
        _arr = new int [_capacity];
        _index = _arr;

        for (int i = 0; i < _size; ++i)
        {
            _arr[i] = value;
        }
    }
    else
    {
        std::cout << "undefined behaifor\n";
    }
}

Vector::~Vector ()
{
    delete[] _arr;
}

Vector::Vector (const Vector& ob) 
{
    _size = ob._size;
    _capacity = ob._capacity;
    _arr = new int [_capacity];
    _index = _arr;
    for(int i = 0; i < _size; ++i)
    {
        _arr[i] = ob._arr[i];
    }
}

Vector& Vector::operator = (const Vector& rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    delete[] _arr;
    _arr = new int (_capacity);
    _index = _arr;
    for (int i = 0; i < _size; ++i)
    {
        _arr[i] = rhs._arr[i];
    }
    return *this;
}

Vector::Vector (Vector&& mob)
{
    _size = mob._size;
    _capacity = mob._capacity;
    _arr = mob._arr;
    _index = _arr;
    
    mob._size = 0;
    mob._capacity = 0;
    mob._arr = nullptr;
    
}

Vector Vector::operator + (const Vector& rhs)
{
    Vector tmp (_capacity > rhs._capacity ? _capacity : rhs._capacity);
    tmp._size = _size > rhs._size ? _size : rhs._size;
    for (int i = 0; i < tmp._size; ++i)
    {
        if (i >= _size)
        {
            tmp._arr[i] = rhs._arr[i] + 0;
        }
        else if(i >= rhs._size)
        {
            tmp._arr[i] = _arr[i] + 0;
        }
        else{
            tmp._arr[i] = _arr[i] + rhs._arr[i];
        }
    }
    return tmp;
}

Vector& Vector::operator += (const Vector& rhs)
{
    Vector tmp (_capacity > rhs._capacity ? _capacity : rhs._capacity);
    tmp._size = _size > rhs._size ? _size : rhs._size;
    for (int i = 0; i < tmp._size; ++i)
    {
          if (i >= _size)
        {
            tmp._arr[i] = rhs._arr[i] + 0;
        }
        else if(i >= rhs._size)
        {
            tmp._arr[i] = _arr[i] + 0;
        }
        else{
            tmp._arr[i] = _arr[i] + rhs._arr[i];
        }
    }
    _size = tmp._size;
    _capacity = tmp._capacity;
    delete[] _arr;
    _arr = new int (_capacity);
    _index = _arr;
    for (int i = 0; i < _size; ++i)
    {
        _arr[i] = tmp._arr[i];
    }
    return *this;
}

int Vector::operator ++ ()
{
    _index += 1;
    return *_index;

}

int& Vector::operator [] (size_t index)
{
    return _arr[index];
}

const int Vector::operator ++ (int zero)
{
    const int tmp = *_index;
    _index += 1;
    return tmp;
}

std::ostream& operator << (std::ostream& os, const Vector& v)
{
    os << '|';
    for (int i = 0; i < v._size; ++i)
    {
        os << v._arr[i] << '|';
    }
    return os;
}

void Vector::push_back (int elem)
{
    if(_size == _capacity)
    {
        _capacity *= 2;
    
    int* tmp = new int [_capacity];

        for (int i = 0; i < _size; ++i)
        {
            tmp[i] = _arr[i];
        }
        delete[] _arr;
        _arr = tmp;
        _index = _arr;
    }
    _arr[_size++] = elem;
}

void Vector::pop_back ()
{
    if(_size > 0)
    {
        --_size;
        _arr[_size] = 0;
    }
}

void Vector::print ()
{
    for (int i = 0; i < _size; ++i)
    {
        std::cout << _arr[i] << ' ';
    }
}
int Vector::size ()
{
    return _size;
}

void Vector :: insert (int index, int value)
{
    int* tmp = new int [_capacity];
    if (index > _size || index < 0)
    {
        std::cout << "invalid index\n";
    }
    else if (index == _size)
    {
        push_back (value);
        return;
    }
    else if (_size == _capacity)
    {
        _capacity *= 2;
        delete[] tmp;
        tmp = new int [_capacity];
    }
    for (int i = 0, j = 0; i < _size; ++i, ++j)
    {
        if (i == index)
        {
            tmp[j] = value;
            ++j;
        }
        tmp[j] = _arr[i];
    }
    delete[] _arr;
    _arr = tmp;
    ++_size;
    _index = _arr;
}

std::string Vector :: find_by_value (int value)
{
    if (_size == 0)
    {
        return "No items in your vector\n";
    }
    std::string index_list{"Value found in: "};
    for (int i = 0; i < _size; ++i)
    {
        if(_arr[i] == value)
        {
            index_list = index_list + std::to_string (i) + '|';
        }
    }
    if(index_list.length() == 0)
    {
        return "No such a value in your vector\n";
    }
    return index_list;
}
void Vector :: remove_by_value (int value)
{
    if (_size == 0)
    {
        return;
    }
    int* tmp = new int [_capacity];
    int count_removed_value = 0;
    for (int i = 0, j = 0; j < _size; ++j)
    {
        if (_arr[j] == value)
        {
            ++count_removed_value;
        }
        else
        {
            tmp[i] = _arr[j];
            ++i;
        }
    }
    delete[] _arr;
    _arr = tmp;
    _index = _arr;
    _size -= count_removed_value;
    tmp = nullptr;
}