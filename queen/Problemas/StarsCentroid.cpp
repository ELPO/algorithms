#include "StarsCentroid.h"

#include <QDebug>

struct PointF {
    double x;
    double y;
};

//vector<vector<int>> v = {{1,1,2},{-1,1,2},{-1,-1,4},{1,-1,5}};
//vector<vector<int>> v = {{748798831,-200797120,595},{-774675771,179630170,159},{-338760201,945958360,750},{955629379,-312997434,516},{755005057,-672683474,405},{-743176829,190325067,86},{-301478753,-718170081,923},{-795908444,985440803,854},{-102868895,671114060,246},{-698209449,12550066,190}};
//    vector<vector<int>> v =
//    {{233743240,-777812700,991},
//    {710505266,635433994,251},
//    {961240622,-559998666,292},
//    {317622290,-269656857,270},
//    {687524020,297709949,757},
//    {224560970,967953108,808},
//    {588930376,-39938323,340},
//    {88387668,915475807,743},
//    {15621290,-244257473,333},
//    {-313099768,-489434665,988},
//    {118853137,-823979220,118},
//    {745694067,314124971,47},
//    {-183633372,294074811,234},
//    {240420841,-827927481,701},
//    {566477599,744449347,156},
//    {35733911,-687803907,26},
//    {-656472449,446094902,336},
//    {362501987,649599455,470},
//    {337988092,351226272,61},
//    {-362801770,594707544,810}};

int StarsCentroid::solve(const vector<vector<int>> &stars)
{
    int dif = -1;

    for (int i = 0; i < stars.size(); i++) {
        for (int r = 0; r < stars.size(); r++) {
            if (true) {
                double pos = 0;//stars[i][2];
                double neg = 0;//stars[r][2];
                vector<int> posv,negv;
//                negv.push_back(r);
//                posv.push_back(i);
                for (int k = 0; k < stars.size(); k++) {
                  if (k == r || k == i || i == r)
                        continue;
                    int d = (stars[r][0]-stars[i][0])*(stars[k][1]-stars[r][1])-
                               (stars[r][1]-stars[i][1])*(stars[k][0]-stars[r][0]);
                    if (d < 0) {
                        pos += stars[k][2];
                        posv.push_back(k);
                    } else {
                        neg += stars[k][2];
                        negv.push_back(k);
                    }
                }


                if (pos == 4343){
                    qDebug() << "a!!!!!!!!!"  << i << r << neg << pos << stars[i][2]<<stars[r][2];
                }

                if (neg == 4343)
                    qDebug() << "b!!!!!!!!!";

                if (pos+stars[i][2] == 4343)
                    qDebug() << "c!!!!!!!!!";

                if (pos+stars[r][2] == 4343)
                    qDebug() << "d!!!!!!!!!";

                if (pos+stars[i][2]+stars[r][2] == 4343)
                    qDebug() << "e!!!!!!!!!";

                if (neg+stars[i][2] == 4343)
                    qDebug() << "f!!!!!!!!!";

                if (neg+stars[r][2] == 4343)
                    qDebug() << "g!!!!!!!!!";

                if (neg+stars[i][2]+stars[r][2] == 4343) {
                    qDebug() << "h!!!!!!!!!"  << i << r << neg << pos << stars[i][2]<<stars[r][2] << neg + pos;

                }

                if (pos == 4389){
                    qDebug() << "a!!!!!!!!!"  << i << r << neg << pos << stars[i][2]<<stars[r][2];
                }

                if (neg == 4389)
                    qDebug() << "b!!!!!!!!!";

                if (pos+stars[i][2] == 4389)
                    qDebug() << "c!!!!!!!!!";

                if (pos+stars[r][2] == 4389)
                    qDebug() << "d!!!!!!!!!";

                if (pos+stars[i][2]+stars[r][2] == 4389)
                    qDebug() << "e!!!!!!!!!";

                if (neg+stars[i][2] == 4389)
                     qDebug() << "ff!!!!!!!!!"  << i << r << neg << pos << stars[i][2]<<stars[r][2] << neg + pos;

                if (neg+stars[r][2] == 4389)
                    qDebug() << "g!!!!!!!!!";

                if (neg+stars[i][2]+stars[r][2] == 4389) {
                    qDebug() << "hh!!!!!!!!!"  << i << r << neg << pos << stars[i][2]<<stars[r][2] << neg + pos;

                }

                //qDebug() << pos << neg;

                int a,b;
                int mi;
                int spe;
                int aux;

//                mi = abs(neg-pos);
//                spe = min(neg,pos);

                a = pos;
                b = neg + stars[i][2]+stars[r][2];
                mi= abs(a - b);
                spe = min(a,b);

                a = neg;
                b = (pos + stars[i][2]+stars[r][2]);
                aux = abs(a - b);
                if (aux < mi) {
                    mi = aux;
                    spe = min(a,b);
                }

                a = pos + stars[i][2];
                b = neg + stars[r][2];
                aux = abs(a - b);
                if (aux < mi) {
                    mi = aux;
                    spe = min(a,b);
                }

                a = pos + stars[r][2];
                b = neg + stars[i][2];
                aux = abs(a - b);
                if (aux < mi) {
                    mi = aux;
                    spe = min(a,b);
                }

                //qDebug() << spe;

                if (dif == -1) {
                    dif = spe;
                } else if (dif < spe) {
                    qDebug() << spe << mi << i << r << neg << pos << stars[i][2] << stars[r][2] <<  "@@@";
                    qDebug() << posv << negv;
                    dif = spe;
                }
            }
        }
    }

    qDebug() << "mmmm ";

    return dif;
}
