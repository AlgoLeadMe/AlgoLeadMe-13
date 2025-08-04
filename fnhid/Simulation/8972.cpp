#include <iostream>
#include <vector>
#include <map>

class CrazyArdu;
using namespace std;

#define R first
#define S second

typedef pair<int, int> Pos;
int dr[10]={0,1,1,1,0,0,0,-1,-1,-1};
int ds[10]={0,-1,0,1,-1,0,1,-1,0,1}; // [0] is dummy



class Ardu
{
protected:
    Pos cur;

public:
    Ardu(Pos p)
    {
        this->cur = p;
    }

    Pos getPos()
    {
        return this->cur;
    }
};

class JongSuArdu : public Ardu {
private:
    int moveCnt;
    Pos boardPos;
public:
    JongSuArdu(const Pos& initP, const Pos& boardP) : Ardu(initP)
    {
        this->moveCnt = 0;
        this->boardPos.R = boardP.R;
        this->boardPos.S = boardP.S;
    }

    int getMoveCnt(){
        return moveCnt;
    }

    void move(char idx)
    {
        char d = idx - '0';
        if (cur.R < boardPos.R && cur.R >= 0)
            cur.R = cur.R + dr[d];
        if (cur.S < boardPos.S && cur.S >= 0)
            cur.S = cur.S + ds[d];
        if (idx != 5)
            moveCnt++;
    }
};

class CrazyArdu : public Ardu
{
private:
    vector<int> dirDist;

    void updateDirDist(JongSuArdu j)
    {
        Pos jPos = j.getPos();
        for (int i=1;i<5;i++)
        {
            int cr = cur.R + dr[i]; // 1~4
            int cs = cur.S + ds[i];
            dirDist[i] = abs(cr - jPos.R) + abs(cs - jPos.S);
        }

        for (int i=6;i<=9;i++)
        {
            int cr = cur.R + dr[i]; // 6~9
            int cs = cur.S + ds[i];
            dirDist[i] = abs(cr - jPos.R) + abs(cs - jPos.S);
        }
    };


public:
    CrazyArdu(const Pos& initP) : Ardu(initP)
    {
        dirDist = vector<int>(10, 9999);
    }
    void move(JongSuArdu j)
    {
        updateDirDist(j);
        int minIdx=0, minVal=999999;
        for (int i=0;i<10;i++)
        {
            if (minVal>dirDist[i])
            {
                minIdx = i;
                minVal = dirDist[i];
            }
        }
        cur.R=cur.R+dr[minIdx];
        cur.S=cur.S+ds[minIdx];
    }

};
int main()
{
    int c, r;
    string cmdStr;

    vector<CrazyArdu*> crazyArdus;
    JongSuArdu* jongSu = nullptr;

    cin >> r >> c;


    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == 'R') crazyArdus.push_back(new CrazyArdu(Pos{i,j}));
            else if (tmp == 'I') jongSu = new JongSuArdu(Pos{i,j}, Pos{r, c});
        }
    }


    cin >> cmdStr;

    for (char cmd: cmdStr)
    {
        jongSu->move(cmd);
        for (auto crazyArdu: crazyArdus) // JongsuCollision check
        {
            if (crazyArdu->getPos() == jongSu->getPos())
            {
                cout << "kraj " << jongSu->getMoveCnt()<< "\n";

                delete jongSu;
                for (auto *ard : crazyArdus) delete ard;
                return 0;
            }
        }

        map<Pos, vector<CrazyArdu*>> posMap;

        for (auto crazyArdu: crazyArdus) // crazyArdu moves && JongsuCollision check && pre for crazyarducollisioncheck
        {
            crazyArdu->move(*jongSu);
            posMap[crazyArdu->getPos()].push_back(crazyArdu);
            if (crazyArdu->getPos() == jongSu->getPos())
            {
                cout << "kraj " << jongSu->getMoveCnt()<< "\n";

                delete jongSu;
                for (auto *ard : crazyArdus) delete ard;
                return 0;
            }
        }

        // crazyArdu Collision check
        vector<CrazyArdu*> survivedCrazyArdu;

        for (auto& p : posMap)
        {
            if (p.second.size() == 1)
                survivedCrazyArdu.push_back(p.second[0]);
            else
            {
                for (auto* v : p.second) delete v;
            }
        }
        crazyArdus = survivedCrazyArdu;


    }


    // print

    vector<vector<char>> board(r, vector<char>(c+1,'.'));

    board[jongSu->getPos().R][jongSu->getPos().S] = 'I';

    for (auto crazyArdu: crazyArdus)
        board[crazyArdu->getPos().R][crazyArdu->getPos().S] = 'R';


    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cout << board[i][j];
        }
        cout << " \n";
    }

    for (auto *ard : crazyArdus) delete ard;
    delete jongSu;

}
