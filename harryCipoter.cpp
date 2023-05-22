#include "personajes.h"
#include "Enemigos.h"
#include "Boss.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <vector>
#include <time.h>

using namespace std;

const int WEIGHT = 20;
const int HEIGHT = 20;
bool fin = false;
bool winner = false;

void imprimirMapa(string mapa[WEIGHT][HEIGHT], int posX, int posY, Personajes* enemigos) {
    // Crear las paredes exteriores
    for (int i = 0; i < WEIGHT; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (i == 0 || j == 0 || i == WEIGHT - 1 || j == HEIGHT - 1) {
                mapa[i][j] = " @ ";
            }
            else {
                mapa[i][j] = "   ";
            }
        }
    }

    // Crear las paredes interiores
    int midX = HEIGHT / 2;
    int midY = WEIGHT / 2;

    for (int i = 1; i < WEIGHT - 1; i++) {
        mapa[i][midX] = " @ ";
    }

    for (int j = 1; j < HEIGHT - 1; j++) {
        mapa[midY][j] = " @ ";
    }

    // Hierba
    for (size_t i = 1; i < 10; i++) {
        for (size_t j = 6; j < 9; j++) {
            mapa[i][j] = " M ";
        }
    }

    for (size_t i = 6; i < 10; i++) {
        for (size_t j = 11; j < 19; j++) {
            mapa[i][j] = " M ";
        }
    }

    for (size_t i = 11; i < 19; i++) {
        for (size_t j = 11; j < 14; j++) {
            mapa[i][j] = " M ";
        }
    }

    int holeX = 10;
    int holeY = 2;

    mapa[holeY][holeX] = "   ";

    holeX = 18;
    holeY = 10;

    mapa[holeY][holeX] = "   ";

    holeX = 10;
    holeY = 14;

    mapa[holeY][holeX] = "   ";

    // Colocar al personaje en el mapa
    mapa[posY][posX] = " P ";

    mapa[15][3] = " ! ";

    // Imprimir el mapa
    for (int i = 0; i < WEIGHT; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void battle(int eneN, Personajes enemigos[], Personajes jarry) {
    system("cls");
    cout << eneN;
    int op;
    cout << "\n\n\t\tTE HAS ENCONTRA UN ENEMIGO\n\n";

    do
    {
        cout << "\nQue ataque quieres hacer?: [ 1 | 2 | 3 ]: ";

        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Tu ataque ha quitado " << jarry.gettHab1() << endl;
            enemigos[eneN].settHp(enemigos[eneN].gettHp() - jarry.gettHab1());
            break;
        case 2:
            cout << "Tu ataque ha quitado " << jarry.gettHab2() << endl;
            enemigos[eneN].settHp(enemigos[eneN].gettHp() - jarry.gettHab2());
            break;
        case 3:
            cout << "Tu ataque ha quitado " << jarry.gettHab2() << endl;
            enemigos[eneN].settHp(enemigos[eneN].gettHp() - jarry.gettHab3());
            break;
        default:
            break;
        }

        cout << endl << "El enemigo te ha quitado " << enemigos[eneN].gettHab1() << endl;

        jarry.settHp(jarry.gettHp() - enemigos[eneN].gettHab1());

        cout << "Te queda " << jarry.gettHp() <<" hp!" <<  endl;
        cout << endl << "Al enemigo le queda " << enemigos[eneN].gettHp() << " hp!" << endl;
        
        if (enemigos[eneN].gettHp() <= 0)
        {
            enemigos[eneN].settAlive(false);
            cout << "ENEMIGO DERROTADO";
            Sleep(1000);
        }
        else if (jarry.gettHp() <= 0)
        {
            jarry.settAlive(false);
            cout << "HAS PERDIDO";
            Sleep(1000);
        }
    } while (jarry.gettAlive() && enemigos[eneN].gettAlive());
  
}

bool finalBattle(Personajes jarry) {
    system("cls");
    Boss boss(200, 0.40, 30, 10, true);
    int op;
    cout << "BIENVENIDO A LA PELEA FINAL";
    Sleep(1000);
    do
    {
        cout << "\nQue ataque quieres hacer?: [ 1 | 2 | 3 ]: ";

        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Tu ataque ha quitado" << jarry.gettHab1();
            boss.settHp(boss.gettHp() - jarry.gettHab1());
            break;
        case 2:
            cout << "Tu ataque ha quitado" << jarry.gettHab2();
            boss.settHp(boss.gettHp() - jarry.gettHab2());
            break;
        case 3:
            cout << "Tu ataque ha quitado" << jarry.gettHab2();
            boss.settHp(boss.gettHp() - jarry.gettHab3());
            break;
        default:
            break;
        }

        int atakBoss = 0;
        int countAtak = 0;

        atakBoss = rand() % 2;
        if (atakBoss == 0)
        {
            cout <<endl << "El BOSS ha usado su ataque normal y te ha quitado " << boss.gettHab1() << endl;
            jarry.settHp(jarry.gettHp() - boss.gettHab1());
        }
        else
        {
            cout << endl << "El BOSS ha usado su SUPERATAK y te ha quitado " << boss.gettSuperHab() << endl;
            jarry.settHp(jarry.gettHp() - boss.gettSuperHab());
        }

        cout <<endl<< "Te queda " << jarry.gettHp() << " hp!" <<endl;
        cout << endl << "Al Boss le queda " << boss.gettHp() << " hp!" << endl;

        if (boss.gettHp() <= 0)
        {
            boss.settAlive(false);
            cout << "BOSS DERROTADO";
            fin = true;
            winner = true;
            return fin;
            Sleep(1000);
        }
        else if (jarry.gettHp() <= 0)
        {
            jarry.settAlive(false);
            cout << "HAS PERDIDO";
            fin = true;
            
            return fin;
            Sleep(1000);
        }
    } while (jarry.gettAlive() && boss.gettAlive());


}

void mapaFinal(Personajes jarry){
    string mapa[10][20];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == 0 || j == 0 || i == 10 - 1 || j == 20 - 1) {
                mapa[i][j] = " @ ";
            }
            else {
                mapa[i][j] = "   ";
            }
        }
    }
    
    mapa[jarry.gettPosY()][jarry.gettPosX()] = " P ";

    mapa[5][15] = " b ";


    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            cout << mapa[i][j];

        }
        cout << endl;
    }

    if (jarry.gettPosX() == 15 && jarry.gettPosY() == 3)
    {
        finalBattle(jarry);
    }

    
}

int main() {
    Personajes jarry("Jarry", 200, 20, 20, 20, 1, 5, true);
    srand(time(0));
    string mapa[WEIGHT][HEIGHT];
    
    Personajes enemigos[5];

    enemigos[0] = Enemigos(50, 10, true);
    enemigos[1] = Enemigos(50, 10, true);
    enemigos[2] = Enemigos(50, 10, true);
    enemigos[3] = Enemigos(50, 10, true);
    enemigos[4] = Enemigos(50, 10, true);

    

    enemigos[0].settPosX(8);
    enemigos[0].settPosY(4);
    enemigos[1].settPosX(15);
    enemigos[1].settPosY(8);
    enemigos[2].settPosX(16);
    enemigos[2].settPosY(9);
    enemigos[3].settPosX(13);
    enemigos[3].settPosY(17);
    enemigos[4].settPosX(11);
    enemigos[4].settPosY(14);
    int eneN = 0;

    bool final = false;

    do {
        if (!final)
        {
            imprimirMapa(mapa, jarry.gettPosX(), jarry.gettPosY(), enemigos);

        }
        else
        {
            mapaFinal(jarry);
        }
        if (mapa[jarry.gettPosY()][jarry.gettPosX()] == " ! ")
        {
            final = true;
            jarry.settPosX(3);
            jarry.settPosY(5);
        }

        char dir;
        dir = _getch();

        int newX = jarry.gettPosX();
        int newY = jarry.gettPosY();

        switch (dir) {
        case 'H':
            if (mapa[jarry.gettPosY() - 1][jarry.gettPosX()] != " @ ") {
                newY = jarry.gettPosY() - 1;
            }
            break;
        case 'P':
            if (mapa[jarry.gettPosY() + 1][jarry.gettPosX()] != " @ ") {
                newY = jarry.gettPosY() + 1;
            }
            break;
        case 'K':
            if (mapa[jarry.gettPosY()][jarry.gettPosX() - 1] != " @ ") {
                newX = jarry.gettPosX() - 1;
            }
            break;
        case 'M':
            if (mapa[jarry.gettPosY()][jarry.gettPosX() + 1] != " @ ") {
                newX = jarry.gettPosX() + 1;
            }
            break;
        default:
            break;
        }

        jarry.settPosX(newX);
        jarry.settPosY(newY);

        
        if (!final)
        {
            if (mapa[jarry.gettPosY()][jarry.gettPosX()] == " M ")
            {
                for (size_t i = 0; i < 5; i++)
                {
                    if (jarry.gettPosX() == enemigos[i].gettPosX() && jarry.gettPosY() == enemigos[i].gettPosY() && eneN < 5)
                    {
                        battle(eneN, enemigos, jarry);
                        eneN = eneN + 1;
                    }
                }
            }
        }
        
        system("cls");

    } while (!fin);

    if (winner == true)
    {
        system("cls");
        cout << endl << "HAS GANADO";
    }
    else
    {
        system("cls");
        cout << endl << "Has perdido :(";
    }

    return 0;
}

