#include <iostream>

class Robot {
    int m_x;
    int m_y;
public:
    Robot(const int x, const int y) : m_x(x), m_y(y) { }
    virtual ~Robot() { }
    void getCoord() {
        std::cout << "Robot (x:" << m_x << ", y:" << m_y << ")" << std::endl;
    }
    void move(const char m);
};

void Robot::move(const char m) {
    if ((m=='w') || (m=='s') || (m=='a') || (m=='d') || (m=='e')) {
        switch (m) {
            case ('w'):
                if (m_y == 1)
                    std::cout << "You can't go Up" << std::endl;
                else
                    m_y--;
                break;
            case ('s'):
                if (m_y == 10)
                    std::cout << "You can't go Down" << std::endl;
                else
                    m_y++;
                break;
            case ('a'):
                if (m_x == 1)
                    std::cout << "You can't go Left" << std::endl;
                else
                    m_x--;
                break;
            case ('d'):
                if (m_x == 10)
                    std::cout << "You can't go Right" << std::endl;
                else
                    m_x++;
                break;
            case ('e'):
                std::cout << "Game over" << std::endl;
        }
    } else {
        std::cout << "Incorrect input" << std::endl;;
    }
}

int main() {
    Robot r1(5, 5);
    char move;
    do {
        r1.getCoord();
        std::cout << "Where to move w(Up), s(Down), a(Left), d(Right), e(exit): ";
        std::cin >> move;
        r1.move(move);
    } while (move !='e');
    return 0;
}

