#ifndef CAR
#define CAR

class Car{
    friend engine;
    friend suspension;
    private:
    std::string Engine;
    int cylinder;
    std::string Suspension;
    public:
    virtual void setEngine()=0;
    virtual void setSuspension()=0;

    virtual void engineStart()=0;
    virtual void engineStop()=0;
    virtual void drive()=0;
};

class PorscheTaycan : public Car{
    void setEngine() override;
    void setSuspension() override;
    void engineStart() override;
    void engineStop() override;
    void drive() override;
};

class DodgeRAM : public Car{
    void setEngine() override;
    void setSuspension() override;
    void engineStart() override;
    void engineStop() override;
    void drive() override;
}

class Polo : public Car{
    void setEngine() override;
    void setSuspension() override;
    void engineStart() override;
    void engineStop() override;
    void drive() override;
}
#endif