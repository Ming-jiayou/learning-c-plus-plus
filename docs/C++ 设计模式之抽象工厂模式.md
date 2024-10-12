# 使用C++实现抽象工厂模式（Abstract Factory）

抽象工厂模式是一种创建型设计模式，它提供了一种方式来封装一组具有共同主题的单独工厂。抽象工厂模式通过提供一个超级工厂创建其他工厂的接口，使得客户端使用抽象的接口操作具体对象，从而实现客户端与具体工厂类解耦。

下面是一个使用C++实现抽象工厂模式的例子：

```c++
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
```

运行结果如下所示：

![image-20241012095327960](https://mingupupup.oss-cn-wuhan-lr.aliyuncs.com/imgs/image-20241012095327960.png)

在这个例子中，我们定义了两个抽象产品类`AbstractProductA`和`AbstractProductB`，以及两个具体产品类`ProductA1`和`ProductA2`、`ProductB1`和`ProductB2`。我们还定义了一个抽象工厂类`AbstractFactory`，以及两个具体工厂类`Factory1`和`Factory2`。

客户端代码使用抽象工厂接口来创建具体产品，并使用这些产品。通过使用抽象工厂模式，我们可以在不改变客户端代码的情况下，改变具体工厂类和具体产品类。