#ifndef ENGINE
#define ENGINE

class engine{
    private:
    std::string engineType;
};

class V8: public engine{
    V8();
};

class V6: public engine{
    V6();
};

class electric: public engine{
    electric();
};
#endif 