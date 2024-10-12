#include <iostream>
#include <string>

// 抽象产品A
class AbstractProductA {
public:
    virtual ~AbstractProductA() {}
    virtual std::string use() = 0;
};

// 抽象产品B
class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual std::string eat() = 0;
};

// 具体产品A1
class ProductA1 : public AbstractProductA {
public:
    std::string use() override {
        return "Using Product A1";
    }
};

// 具体产品A2
class ProductA2 : public AbstractProductA {
public:
    std::string use() override {
        return "Using Product A2";
    }
};

// 具体产品B1
class ProductB1 : public AbstractProductB {
public:
    std::string eat() override {
        return "Eating Product B1";
    }
};

// 具体产品B2
class ProductB2 : public AbstractProductB {
public:
    std::string eat() override {
        return "Eating Product B2";
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// 具体工厂1
class Factory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA1();
    }
    AbstractProductB* createProductB() override {
        return new ProductB1();
    }
};

// 具体工厂2
class Factory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA2();
    }
    AbstractProductB* createProductB() override {
        return new ProductB2();
    }
};

// 客户端代码
void clientCode(AbstractFactory* factory) {
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();

    std::cout << productA->use() << std::endl;
    std::cout << productB->eat() << std::endl;

    delete productA;
    delete productB;
}

int main() {
    AbstractFactory* factory1 = new Factory1();
    AbstractFactory* factory2 = new Factory2();

    std::cout << "Using the products created by Factory 1:" << std::endl;
    clientCode(factory1);

    std::cout << "Using the products created by Factory 2:" << std::endl;
    clientCode(factory2);

    delete factory1;
    delete factory2;

    return 0;
}