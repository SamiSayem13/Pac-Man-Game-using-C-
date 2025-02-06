#include <bits/stdc++.h>
#include <windows.h>
#include<random>

using namespace std;

void chooseMap();
void display();
void mirpur();
void gulisthan();
void robo();
void badda();
void display();

int pts = 0;  // Points counter
char tmp_map[18][32];
char gameMap[18][32];

void ShowMap()
{
    for (int i = 0; i < 18; i++)
    {
        printf("%s\n", gameMap[i]);
    }
}

void gotoxy(short x, short y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}

struct Walk
{
    short walk_count;
    short x;
    short y;
    short back;
};

struct Target
{
    short x;
    short y;
};

vector<Target> walk_queue;
vector<Walk> BFSArray;

void AddArray(int x, int y, int wc, int back)
{
    if (tmp_map[y][x] == ' ' || tmp_map[y][x] == '.')
    {
        tmp_map[y][x] = '#';
        Walk tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.walk_count = wc;
        tmp.back = back;
        BFSArray.push_back(tmp);
    }
}

void FindPath(int sx, int sy, int x, int y) //sx=ex  sy=ey  x=hx  y=hy
{
    memcpy(tmp_map, gameMap, sizeof(gameMap));  // Updated here
    BFSArray.clear();
    Walk tmp;
    tmp.x = sx;
    tmp.y = sy;
    tmp.walk_count = 0;
    tmp.back = -1;//no parent;
    BFSArray.push_back(tmp);

    int i = 0;
    while (i < BFSArray.size()) //0 means till not empty
    {
        if (BFSArray[i].x == x && BFSArray[i].y == y)
        {
            walk_queue.clear();
            Target tmp2;
            while (BFSArray[i].walk_count != 0)
            {
                tmp2.x = BFSArray[i].x;
                tmp2.y = BFSArray[i].y;
                walk_queue.push_back(tmp2);

                i = BFSArray[i].back;
            }
            break;
        }

        // Explore neighboring cells
        AddArray(BFSArray[i].x + 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
        AddArray(BFSArray[i].x - 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
        AddArray(BFSArray[i].x, BFSArray[i].y + 1, BFSArray[i].walk_count + 1, i);
        AddArray(BFSArray[i].x, BFSArray[i].y - 1, BFSArray[i].walk_count + 1, i);

        i++;
    }
    BFSArray.clear();
}

void mirpur() {
    // Define Map 1 (Mirpur)
    char map1[18][32] =
{
        "+############################+",
        "|                            |",
        "|         ##    ##   ##      |",
        "|  |  |  |   ##   ##         |",
        "|  |  |  ##    ##   | ##     |",
        "| ## ##  ##      ##  |       |",
        "|   #  #   ##    ##   ##     |",
        "|  ##          ##   ##  ##   |",
        "|  |   ##  ##          ##    |",
        "|   ##  #   ##    ##  | ##   |",
        "| ##            ### ##   ##  |",
        "|  |   ##   ##      |    #   |",
        "|  ###  ## ##    ##  ##  ##  |",
        "| ##    |  ##   ##   ###     |",
        "|       ##  ##   ##   ##     |",
        "| ##  ###   ## ##     ##     |",
        "|                            |",
        "+############################+",
    };
    memcpy(gameMap, map1, sizeof(map1));  // Copy map1 into gameMap
}

void gulisthan() {
    // Define Map 2 (Gulistan)
    char map2[18][32] =
{
    "+#############################+",
    "|                             |",
    "|     #######                 |",
    "|##  #########   #  ##########|",
    "|    |                        |",
    "| ||### | |###  |  |   #####  |",
    "|    #          |  |    |     |",
    "|               |  |    |     |",
    "|  ##  | ##### |    |    ###  |",
    "|            |   ##   |       |",
    "|  | #  |##|                  |",
    "|             |##    ##  #####|",
    "| |    ###                    |",
    "|    # |     |##########      |",
    "|                     |  ##   |",
    "|     ###############    |  ##|",
    "|                             |",
    "+#############################+"
};

    memcpy(gameMap, map2, sizeof(map2));  // Copy map2 into gameMap
}

void robo() {
    // Define Map 3 (Robo-Man)
    char map3[18][32] =
{
        "+############################+",
        "|                            |",
        "|              ##            |",
        "|  #  ####     ||    ####  # |",
        "|     ####           ####    |",
        "|  #  ####           ####  # |",
        "|  #          ||||         # |",
        "|  #          ||||         # |",
        "|                            |",
        "|  #   |  ############  |  # |",
        "|  #   |  #          #  |  # |",
        "|      |  ############  |    |",
        "|  #   |                |  # |",
        "|      ##################    |",
        "|  #     #     #     #     # |",
        "|  |  #  |  #  |  #  |  #  | |",
        "|     |     |     |     |    |",
        "+############################+",
    };
    memcpy(gameMap, map3, sizeof(map3));  // Copy map3 into gameMap
}

void badda() {
    // Define Map 4 (Badda)
    char map4[18][32] =
{  // Game map layout
"+#############################+",
"|                             |",
"|   ##      ###     ###    |  |",
"|   | |      ######    ###    |",
"|   | |   ##                  |",
"|        ##         ##        |",
"| #    ## ##     ##      ##   |",
"|                 ##          |",
"|       | |   | |             |",
"|      ##| |##           ###  |",
"|       | |   | |   ##        |",
"|##          ####             |",
"|      ##              ##| |  |",
"|          ##                 |",
"|   ##          ##            |",
"|  ##          ##             |",
"|         ##           ##     |",
"+#############################+"
};
    memcpy(gameMap, map4, sizeof(map4));  // Copy map4 into gameMap
}

void chooseMap()
{
    display();
    cout<<endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tChoose a Map:\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t1. Mirpur\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t2. Gulistan\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t3. Robo-Man\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t4. Badda\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your choice: ";

    int choice;
    cin >> choice;

    switch(choice)
    {
        case 1:
            mirpur();  // Select Mirpur
            break;
        case 2:
            gulisthan();  // Select Gulistan
            break;
        case 3:
            robo();  // Select Robo-Man
            break;
        case 4:
            badda();  // Select Badda
            break;
        default:
            cout <<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t\tInvalid choice! try choosing random map\n";

             int random_number;
	         srand(time(0));
		     random_number = rand() % 5;

             if(random_number==1) mirpur();
             else if(random_number==2) gulisthan();
             else if(random_number==3) robo();
             else if(random_number==4) badda();

            break;
    }
}

int main()
{
    bool running = true;
    int x = 15; // hero x
    int y = 16; // hero y
    int old_x;
    int old_y;

    int ex = 1; // enemy x
    int ey = 1; // enemy y

    // Display map selection
    chooseMap();

    printf("\t\t\t\t\t\t\t\t\t\t\tInstruction:\n\t\t\t\t\t\t\t\t\t\t\t1. Arrow Keys to move your hero\n\t\t\t\t\t\t\t\t\t\t\t2. Eat the dots produced by the Eater to gain points\n\t\t\t\t\t\t\t\t\t\t\t3. Don't get caught by the Eater\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\tH -> Hard\n\t\t\t\t\t\t\t\t\t\t\tN -> Normal\n\t\t\t\t\t\t\t\t\t\t\tE -> Easy\n\n\t\t\t\t\t\t\t\t\t\t\tInput : ");

    char diffi;
    int speedmod = 3;

    cin >> diffi;

    if (diffi == 'N')
    {
        speedmod = 2;
    }
    else if (diffi == 'H')
    {
        speedmod = 1;
    }

    // Clear the screen after the user inputs the difficulty
    system("cls");

    ShowMap();  //

    gotoxy(x, y);
    cout << "H";  // Draw the hero

    int frame = 0;

    FindPath(ex, ey, x, y);  // Calculate enemy's path initially

    while (running)
    {
        // Clear hero's current position
        gotoxy(x, y);
        cout << " ";

        old_x = x;
        old_y = y;

        // Movement input for hero
        if (GetAsyncKeyState(VK_UP))
        {
            if (gameMap[y - 1][x] == '.')
            {
                y--;
                pts++;
                gameMap[y][x] = ' ';  // Remove the dot
            }
            else if (gameMap[y - 1][x] == ' ') y--;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (gameMap[y + 1][x] == '.')
            {
                y++;
                pts++;
                gameMap[y][x] = ' ';  // Remove the dot
            }
            else if (gameMap[y + 1][x] == ' ') y++;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (gameMap[y][x - 1] == '.')
            {
                x--;
                pts++;
                gameMap[y][x] = ' ';  // Remove the dot
            }
            else if (gameMap[y][x - 1] == ' ') x--;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (gameMap[y][x + 1] == '.')
            {
                x++;
                pts++;
                gameMap[y][x] = ' ';  // Remove the dot
            }
            else if (gameMap[y][x + 1] == ' ') x++;
        }

        if (old_x != x || old_y != y)
        {
            FindPath(ex, ey, x, y);  // Recalculate path if hero moves
        }

        // Leave a dot at the previous enemy position
        if (frame % speedmod == 0 && walk_queue.size() != 0)
        {
            gotoxy(ex, ey);           // Move to enemy's old position
            cout << ".";              // Draw a dot where enemy used to be

            // Remove dot from the enemy's old position if it's not the same as the hero's current position
            if (gameMap[ey][ex] != 'H')
            {
                gameMap[ey][ex] = '.'; // Update the gameMap with the dot
            }

            // Move the enemy to the next position
            ex = walk_queue.back().x;
            ey = walk_queue.back().y;
            walk_queue.pop_back();    // Remove the last element from the queue
        }

        // Draw hero at the new position
        gotoxy(x, y);
        cout << "H";

        // Draw enemy at the new position
        gotoxy(ex, ey);
        cout << "E";

        // Check for collision
        if (ex == x && ey == y)
        {
            break;
        }

        // Display the points
        gotoxy(32, 1);
        cout << "Points: " << pts;

        Sleep(100);  // Delay to control game speed
        frame++;
    }

    // End game
    system("cls");
    printf("You Lose and your score is: %i\n", pts);
    system("pause");

    return 0;
}

void display()
{
    vector<string> asciiArt =
    {
        " __          __  _                            _          ______      _                 _            ",
        " \\ \\        / / | |                          | |        |  ____|    | |               | |           ",
        "  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |__ ______| |__  _   _ _ __ | |_ ___ _ __ ",
        "   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  |  __|______| '_ \\| | | | '_ \\| __/ _ \\ '__|",
        "    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |____     | | | | |_| | | | | ||  __/ |   ",
        "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___| \\__\\\\___/  |______|    |_| |_|\\__,_|_| |_|\\__\\___|_|   ",
    };

    for(auto line : asciiArt)
    {
        cout <<"\t\t\t\t\t\t\t\t"<<line << endl;
        //Sleep(500); // Pause for 100 milliseconds between each line
    }
    cout<<endl<<endl<<endl<<endl;

}
