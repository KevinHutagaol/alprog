//
// Created by kevin on 21/04/2025.
//

#ifndef MYCLASS_H
#define MYCLASS_H


class myClass {
private:
    int a{};

public:

    explicit myClass(int a);

    virtual ~myClass();

    [[nodiscard]] int getA() const;

    void setA(int a);

    virtual int myFunc();

};


#endif //MYCLASS_H
