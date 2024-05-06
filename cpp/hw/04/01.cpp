#include <iostream>

class Animal {
public:
    virtual void move() = 0;  // ���麯����������������ʵ��
    virtual ~Animal() {}  // ����������

protected:
    int m_age;
    std::string m_name;
};

class LandAnimal : public virtual Animal {
public:
    LandAnimal() {
        std::cout << "½�ض��ﴴ���ɹ�" << std::endl;
    }

    void move() override {
        std::cout << "½�ض����ڵ�������" << std::endl;
    }

protected:
    int m_leg_num;
};

class AquaticAnimal : public virtual Animal {
public:
    AquaticAnimal() {
        std::cout << "ˮ�����ﴴ���ɹ�" << std::endl;
    }

    void move() override {
        std::cout << "ˮ��������ˮ����Ӿ" << std::endl;
    }

protected:
    int m_fin_num;
};

class Amphibian : public LandAnimal, public AquaticAnimal {
public:
    Amphibian() {
        std::cout << "���ܶ��ﴴ���ɹ�" << std::endl;
    }

    void move() override {
        std::cout << "���ܶ��������½�������ߣ�Ҳ����ˮ����Ӿ" << std::endl;
    }
};

int main() {
    // ������ͬ��Ķ��󲢽��в���
    Animal* animal = new Amphibian();
    animal->move();  // ��������ܶ��������½�������ߣ�Ҳ����ˮ����Ӿ

    LandAnimal* land_animal = new Amphibian();
    land_animal->move();  // ��������ܶ��������½�������ߣ�Ҳ����ˮ����Ӿ

    AquaticAnimal* aquatic_animal = new Amphibian();
    aquatic_animal->move();  // ��������ܶ��������½�������ߣ�Ҳ����ˮ����Ӿ

    delete animal;
    delete land_animal;
    delete aquatic_animal;

    return 0;
}
