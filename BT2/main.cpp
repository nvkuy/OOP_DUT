#include <iostream>

using namespace std;

struct date {
    int d, m, y;
    date() {
    }
    date(int d, int m, int y) {
        this->d = d, this->m = m, this->y = y;
    }
};

void next_date(date &cur) {
    int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (cur.y % 4 == 0)
        dayOfMonth[1]++;
    cur.d++;
    if (cur.d > dayOfMonth[cur.m - 1]) {
        cur.d = 1;
        cur.m++;
        if (cur.m > 12) {
            cur.m = 1;
            cur.y++;
        }
    }
}

void prev_date(date &cur) {
    int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (cur.y % 4 == 0)
        dayOfMonth[1]++;
    cur.d--;
    if (cur.d < 1) {
        cur.m--;
        if (cur.m < 1) {
            cur.m = 12;
            cur.y--;
        }
        cur.d = dayOfMonth[cur.m - 1];
    }
}

date operator ++ (date &cur, int) {
    date bef = cur;
    next_date(cur);
    return bef;
}
date & operator ++ (date &cur) {
    next_date(cur);
    return cur;
}
date operator -- (date &cur, int) {
    date bef = cur;
    prev_date(cur);
    return bef;
}
date & operator -- (date &cur) {
    prev_date(cur);
    return cur;
}
istream & operator >> (istream &in, date &d) {
    string dd, mm, yy, tmp;
    cin >> tmp;
    int i = 0;
    while (tmp[i] != '/') {
        dd.push_back(tmp[i]);
        i++;
    }
    i++;
    while (tmp[i] != '/') {
        mm.push_back(tmp[i]);
        i++;
    }
    i++;
    while (i < tmp.length()) {
        yy.push_back(tmp[i]);
        i++;
    }
    d = date(stoi(dd), stoi(mm), stoi(yy));
    return in;
}
ostream & operator << (ostream &out, const date &dt) {
    out << dt.d << '/' << dt.m << '/' << dt.y;
    return out;
}

int main()
{

    date dt;
    cin >> dt;
    --dt;
    cout << dt << endl;
    dt++;
    cout << dt;

    return 0;
}
