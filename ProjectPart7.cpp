

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <thread>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;


char sky[6][100];


char ground[1][101]={"____________________________________________________________________________________________________"};


char mountains[6][102]={    {"                       /\\                      /\\                  /\\   /\\   /\\          /\\         "},
                            {"       /\\             /  \\   /\\     /\\        /  \\ /\\     /\\      /  \\ /  \\ /  \\   /\\   /  \\        "},
                            {"\\     /  \\   /\\   /\\ /    \\ /  \\   /  \\   /\\ /    /  \\   /  \\ /\\ /    \\    /    \\ /  \\ /    \\  /\\  /\\"},
                            {" \\/\\ /    \\ /  \\ /  \\      /    \\ /    \\ /  \\         \\ /    /  \\      \\         /    \\      \\/  \\/ "},
                            {" /  \\      \\    /    \\    /      \\      \\              \\         \\                            \\   \\ "},
                            {"/    \\                \\                                                                             "}};


char king[4][11]={{"  WWWWWW  "},{" (  \'-\' ) "},{"/|      |\\"},{"  |    |  "}};


int a=0,x=0,qcon=0;     //variable x makes sure that start screen is only displayed once and music and input thread is only created once
                        //qcon is used quit during the game
                        //variable a counts the score and is used to shuffle king's legs while it also assigns initial values to arrays at start of game
int user=0,udec=0;      //variable user takes real  time input from user and controls characters (king) movements
                        //variable dec is also used to take real time input from user

int delay=10,pit=50;

string name ;

void music()
{
    mciSendString("open \"song.mp3\" type mpegvideo alias mp3",NULL, 0,NULL);
    mciSendString("play mp3 from 0 wait", NULL, 0, NULL);
    music();
}


void quit()
{

    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|              DO YOU REALLY WANT TO QUIT  (Y/N)               |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    return;
}


void userin()
{

        switch(getch())
        {
        case 13:
        {
            if(user==0)
                user=1;
            udec=33;
            break;
        }
        case 49:
        {
            udec=1;
            break;
        }
        case 50:
        {
            udec=2;
            break;
        }
        case 51:
        {
            udec=3;
            break;
        }
        case 113:    //q
        {
            udec=113;
            qcon=1;
            break;
        }
        case 81:     //Q
        {
            udec=81;
            qcon=1;
            break;
        }
        case 89:     //Y
        {
            udec=89;
            break;
        }
        case 121:      //y
        {
            udec=121;
            break;
        }
        case 78:      //N
        {
            udec=78;
            break;
        }
        case 110:     //n
        {
            udec=110;
            break;
        }
        default:
        {
            udec=33;
        }

        }
        userin();
}


void shuffle()
{
    a++;
    //shuffles sky
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<99;j++)
        {
                sky[i][j]=sky[i][j+1];
        }
        sky[i][99]=sky[i][0];
    }

    //shuffle mountains
    for(int i=0;i<6;i++)
    {

        for(int j=0;j<100;j++)
        {
            mountains[i][j]=mountains[i][j+1];
        }
        mountains[i][100]=mountains[i][0];
    }

    //shuffles ground

    for(int j=0;j<99;j++)
        {
            ground[0][j]=ground[0][j+1];
        }
        ground[0][99]='_';
    if(ground[0][5]==' ')
        a=a+50;

    //creates pit in the ground
    if(a%pit==0)
    {
        ground[0][96]=' ';
        ground[0][97]=' ';
        ground[0][98]=' ';
        ground[0][99]=' ';
        //if(pit>40)
          //  pit--;
       // if(delay>10)
         //   delay--;
    }


    //changes kings
    if(user==0)
    {
        if(a%2==0)
        {
            king[3][2]='\\';
            king[3][7]='|';
            return;
        }
        else if(a%2==1)
        {
            king[3][2]='|';
            king[3][7]='\\';
            return;
        }
    }
    else if(user==1||user==16)
    {
        king[1][5]=',';

        king[3][2]='>';
        king[3][7]='>';

        user++;
        return;
    }

    else if(user==2||user==3||user==4||user==5||user==6||user==7||user==8||user==9||user==10||user==11||user==12||user==13||user==14||user==15)
    {
        king[3][2]='|';
        king[3][7]='|';
        king[1][4]='^';
        king[1][6]='^';

        user++;
        return;
    }


    else if(user==17)
    {
        king[3][2]='|';
        king[3][7]='|';
        king[1][5]='.';
        king[1][4]='\'';
        king[1][6]='\'';

        user=0;
        return;
    }

    return;
}


void print()
{
    system("CLS");

    cout<<"\n\n\n\n\n\n\n\n\t\t\t\tSCORE: "<<a*5;
    cout<<"\n\t\t\t\t";

    //prints sky

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout<<sky[i][j];
        }
        cout<<endl<<"\t\t\t\t";
    }

    //prints mountains

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout<<mountains[i][j];
        }
        cout<<endl<<"\t\t\t\t";
    }

    if(user==0||user==1||user==2||user==17)
        cout<<"\n\n\n\n\n";
    else if(user==3||user==4||user==15||user==16)
        cout<<"\n\n\n\n";
    else if(user==5||user==6||user==13||user==14)
        cout<<"\n\n\n";
    else if(user==7||user==8||user==11||user==12)
        cout<<"\n\n";
    else if(user==9||user==10)
        cout<<"\n";
    //prints king

    for(int i=0;i<4;i++)
    {
        cout<<"\t\t\t\t\t";
        for(int j=0;j<11;j++)
            cout<<king[i][j];
        if(i!=3)
            cout<<endl;
    }

    if(user==0||user==1||user==2||user==17)
        cout<<"";
    else if(user==3||user==4||user==15||user==16)
        cout<<"\n";
    else if(user==5||user==6||user==13||user==14)
        cout<<"\n\n";
    else if(user==7||user==8||user==11||user==12)
        cout<<"\n\n\n";
    else if(user==9||user==10)
        cout<<"\n\n\n\n";
    cout<<"\n\t\t\t\t";
    for(int i=0;i<100;i++)
        cout<<ground[0][i];

    return;
}


void scorewrite( string name , int score)   // writing to file
{
    time_t t = time(0);

	tm *local = localtime(&t);

    ofstream writefile("allscores.txt" , ios::app);

    writefile<<setw(30)<<name <<setw(30)<<score<<setw(30)<<local->tm_mday<<"/"<<local->tm_mon<<"/"<<1900+local->tm_year<<"\n\n";

    writefile.close();

    a=0;

    return;
}


void allscores()  // file reading
{
    system("CLS");
    cout<<"\n\n\n\n"<<setw(30)<<"NAME:"<<setw(30)<<"SCORE:"<<setw(30)<<"Date and Time:\n\n\n";
    ifstream readfile("allscores.txt" , ios:: app ) ;
    string contents ;
    while(!readfile.eof())
    {
        getline(readfile, contents );
        cout<<contents<<endl;
    }
    readfile.close();
    return;
}


void options()  // this function just display the options on the console
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                      Press 1 to Play                         |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                   Press 2 to View Scores                     |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                 Press 3 to Know How To Play                  |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                      Press Q to quit                         |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;

    return;
}


void score()    //makes a=0 on return;
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                   Your Score is:"<<setw(10)<<a*5<<"                   |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                   Press any key to continue                  |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    while(udec==0)
    {
        Sleep(100);
    }
    udec=0;
    return;
}


void play()
{


    //assign random values to sky array

    if(a==0)
    {
        system("CLS");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                   Press ENTER for Jump                       |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                      Press Q to Quit                         |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<100;j++)
            {
                if(rand()%10==3)
                    sky[i][j]='*';
                else
                    sky[i][j]=' ';
            }
        }
        for(int i=0;i<101;i++)
            ground[0][i]='_';
        a++;
        Sleep(3000);
    }

    shuffle();

    print();

    if(((ground[0][15]==' ')&&(user==0||user==1||user==2||user==17))||((ground[0][10]==' ')&&(user==17)))
    {
        mciSendString("open \"GameOver.mp3\" type mpegvideo alias mp3",NULL, 0,NULL);  //***
        mciSendString("play mp3", NULL, 0, NULL);
        system("CLS");
        system("Color C0");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                         GAME OVER                            |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        udec=0;
        qcon=0;
        Sleep(3000);
        mciSendString("close mp3", NULL, 0, NULL);
        return;
    }

    Sleep(delay);

    if(qcon==1)
        {
            mciSendString("open \"GameOver.mp3\" type mpegvideo alias mp3",NULL, 0,NULL);
            mciSendString("play mp3", NULL, 0, NULL);
            system("CLS");
            system("Color C0");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                       You pressed Q                          |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
            cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
            udec=0;
            qcon=0;
            Sleep(3000);
            mciSendString("close mp3", NULL, 0, NULL);
            return;
        }

    play();

}


void start()
{

    thread bm(music);
    bm.detach();

    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||       |||||||    ||||||  ||||||  |||        ||||||||||          |||  |||||  |||        |||||||"<<endl;
    cout<<"\t\t\t\t|||||||  |||||||||||  ||  |||||  ||||||  |||  ||||||||||||||||||||  |||||||  |||||  |||  |||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||  |||||||||||  ||  ||||||  ||||  ||||  ||||||||||||||||||||  |||||||  |||||  |||  |||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||       |||||  ||||  |||||  ||||  ||||      ||||||||||||||||  |||||||         |||      |||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||  |||||        ||||||  ||  |||||  ||||||||||||||||||||  |||||||  |||||  |||  |||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||  ||||  ||||||  |||||  ||  |||||  ||||||||||||||||||||  |||||||  |||||  |||  |||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||       ||||  ||||||  ||||||    ||||||        ||||||||||||||  |||||||  |||||  |||        |||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   ||||   |||   |||     ||||||   ||||||         |||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   |||   ||||   |||      |||||   ||||   |||||||   |||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   ||   |||||   |||   |   ||||   |||   ||||||||   |||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||       ||||||   |||   ||   |||   |||   ||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||      |||||||   |||   |||   ||   |||   ||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   |   ||||||   |||   ||||   |   |||   |||||      |||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   ||   |||||   |||   |||||      |||   ||||||||   |||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   |||   ||||   |||   ||||||     ||||   |||||||   |||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t|||||||||||||||||||||||   ||||   |||   |||   |||||||    ||||||         |||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

    system("Color A0");
    Sleep(1000);
    system("Color B0");
    Sleep(1000);
    system("Color C0");
    Sleep(1000);
    system("Color D0");
    Sleep(1000);
    system("Color E0");
    Sleep(2000);

    x=1;               //so that this part is not executed again

    system("CLS");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                    ENTER YOUR FIRST NAME                     |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    Sleep(3000);
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t                    ";
    cin>> name ;

    thread ui(userin);
    ui.detach();

    return;
}


void rules()
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t ______________________________________________________________ "<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|         King is out for a walk to burn some calories.        |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|         But the road is dangerous - full of pitfalls.        |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|               You are going to save him from                 |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|                  falling into those pits.                    |"<<endl;
    cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
    cout<<"\t\t\t\t\t\t|       Press ENTER whenever King is in danger of falling.     |"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
    cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;

    while(udec==0)
        Sleep(100);
    return;
}


int main()
{
    qcon=0;
    udec=0;
    if(x==0)
        start();

    options();

    while( udec!=1 && udec!=2 && udec!=3 && udec!=81 && udec!=113 )
    {
        udec=0;
        options();
        while(udec==0)
            Sleep(100);
    }

    if(udec==1)   //1 for play
    {
        a=0;qcon=0;user=0;udec=0;
        play();
        system("Color E0");
        score();
        scorewrite(name,a);
        main();
    }


    if(udec==2)   //2 for allscores
    {

        udec=0;
        allscores();
        while(udec==0)
            Sleep(100);
        main();

    }


    if(udec==3)    //3 for rules
    {
        udec=0;
        rules();
        main();
    }


    if(udec==113||udec==81)     //Q or q for Quit
    {
        udec=0;
        quit();

        while(udec==0)
            Sleep(100);

        while(udec!=121&&udec!=89&&udec!=110&&udec!=78)
        {

            system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t ______________________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|              Press \'Y\' to quit, \'N\' to return                |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                              |"<<endl;
            cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
            cout<<"\t\t\t\t\t\t|______________________________________________________________|"<<endl;
        }

        if (udec==121||udec==89)
        {
            system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\tT";Sleep(100);
            cout<<"H";Sleep(100);
            cout<<"A";Sleep(100);
            cout<<"N";Sleep(100);
            cout<<"K";Sleep(100);
            cout<<"S";Sleep(100);
            cout<<" ";Sleep(100);
            cout<<"F";Sleep(100);
            cout<<"O";Sleep(100);
            cout<<"R";Sleep(100);
            cout<<" ";Sleep(100);
            cout<<"P";Sleep(100);
            cout<<"L";Sleep(100);
            cout<<"A";Sleep(100);
            cout<<"Y";Sleep(100);
            cout<<"I";Sleep(100);
            cout<<"N";Sleep(100);
            cout<<"G";Sleep(100);
            cout<<".";Sleep(100);
            cout<<".";Sleep(100);
            cout<<".";Sleep(100);
            cout<<".";Sleep(100);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
            return 0;
        }
        else if(udec==110||udec==78)
        {
            main();
        }

    }

    return 0;
}
