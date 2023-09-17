/* ʹ����Ӧ�ȸ��������㷨�� W = 1 + �ȴ�ʱ��/����ʱ��
 * ������ҵ���ȵ��Ⱥ���������������������ҵ���ȵ��Ⱥ������������ÿ��Ϊһ����ҵ״̬�������ҷֱ��ǵ��ȴ�����ҵ�ţ�����ʱ�䣬��תʱ��ʹ�Ȩ��תʱ��
 * ���һ���������������һΪƽ����תʱ�䣬�ڶ�Ϊƽ����Ȩ��תʱ��
 */

/* ��ҵ ����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��ת
 * 0    800    200      800     1000    200     1.0
 * 1    850    50       1010    1060    210     4.2
 * 2    900    10       1000    1010    110     11.0
 * 3    950    20       1060    1080    130     6.5
 */

/* ���룺�������ʽ��XXYY������XX��ʱ��YY�Ƿ֣�
4
1320 200
1410 50
1500 10
1550 20
 */

/* ���룺�������ʽ���Է��Ӽƣ�
4
800 200
850 50
900 10
950 20
 */

/* �����
���ȴ���  ��ҵ��  ����ʱ��(min)  ��תʱ��(min)  ��Ȩ��תʱ��(1+W/T)
1        0        800        200        1.000000
2        2        1000        110        11.000000
3        1        1010        210        4.200000
4        3        1060        130        6.500000
ƽ����תʱ�䣺162.5min
ƽ����Ȩ��תʱ�䣺5.675
 */

#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

class Homework
{
private:
    int schedulingOrder{};         // ���ȴ���1--n��������û��������Ϊ0��
    int arrivalTime{};             // ����ʱ�̣�10��28��->1028->628��
    int finishTime{};              // ���ʱ��

    int waitTime{};                // �ȴ�ʱ��
    int runTime{};                 // ����ʱ�䣨�Է��Ӽƣ�
    int number{};                  // ��ҵ��
    int dispatchTime{};            // ����ʱ�䣨��һ�α�CPU���ȣ�����ʼʱ�̣���MIN��
    int turnaroundTime{};          // ��תʱ�䣨���ʱ�� - ����ʱ�̣�
    double weightedTurnaroundTime{};  // ��Ȩ��תʱ��
public:
    int getWaitTime() const {
        return waitTime;
    }

    void setWaitTime(int waitTime) {
        Homework::waitTime = waitTime;
    }

public:
    int getSchedulingOrder() const {
        return schedulingOrder;
    }

    void setSchedulingOrder(int schedulingOrder) {
        Homework::schedulingOrder = schedulingOrder;
    }

    int getArrivalTime() const {
        return arrivalTime;
    }

    void setArrivalTime(int arrivalTime) {
        Homework::arrivalTime = arrivalTime;
    }

    int getFinishTime() const {
        return finishTime;
    }

    void setFinishTime(int finishTime) {
        Homework::finishTime = finishTime;
    }

    int getRunTime() const {
        return runTime;
    }

    void setRunTime(int runTime) {
        Homework::runTime = runTime;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        Homework::number = number;
    }

    int getDispatchTime() const {
        return dispatchTime;
    }

    void setDispatchTime(int dispatchTime) {
        Homework::dispatchTime = dispatchTime;
    }

    int getTurnaroundTime() const {
        return turnaroundTime;
    }

    void setTurnaroundTime(int turnaroundTime) {
        Homework::turnaroundTime = turnaroundTime;
    }

    double getWeightedTurnaroundTime() const {
        return weightedTurnaroundTime;
    }

    void setWeightedTurnaroundTime(double weightedTurnaroundTime) {
        Homework::weightedTurnaroundTime = weightedTurnaroundTime;
    }

    string getInfo ()
    {
        int dispatchTime = { getDispatchTime() };
//        dispatchTime = (dispatchTime / 60 * 100) + (dispatchTime % 60);
        // ���ȴ���  ��ҵ��  ����ʱ��  ��תʱ��  ��Ȩ��תʱ��
        return to_string(getSchedulingOrder()) + "        " + to_string(getNumber())
               + "        " + to_string(dispatchTime) + "        " + to_string(getTurnaroundTime())
               + "        " + to_string(getWeightedTurnaroundTime());
    }
};

/*
 * ���ܣ�      ������ҵ����תȨ��
 * ���������  ��ҵ ��ҵ�� ��ǰʱ�� ���ȴ���
 * �� �� ֵ��  ��תȨ��������ҵ��
 */
int calculateHomeworkWeight(Homework* homeworks, int n, int& presentMonment, int order)
{
    int maxWeightNumber{ 0 };
    int maxWeight{ -INF };
    int earliestHomeworkNumber{ 0 };  // ����ǰʱ��û�����񵽴��¼���絽�����ҵ���±�
    int earlisetMonment{ INF };       // ����ǰʱ��û�����񵽴��¼���絽�����ҵ�ĵ���ʱ��
    for (int i = 0; i < n; ++i)
    {
        // δ������ && �ѵ���
        if(!homeworks[i].getSchedulingOrder() && presentMonment >= homeworks[i].getArrivalTime())
        {
            homeworks[i].setWaitTime(presentMonment - homeworks[i].getArrivalTime());                            // �ȴ�ʱ�� = ��ǰʱ�� - ����ʱ��
            homeworks[i].setWeightedTurnaroundTime(1 + 1.0 * homeworks[i].getWaitTime() / homeworks[i].getRunTime());  // W = 1 + �ȴ�ʱ��/����ʱ��

            if (homeworks[i].getWeightedTurnaroundTime() > maxWeight)  // ��תȨ��������ҵ��
            {
                maxWeightNumber = i;
                maxWeight = homeworks[i].getWeightedTurnaroundTime();
            }
        }

        // δ������ && δ���� --> �ҵ��������絽�������
        if (!homeworks[i].getSchedulingOrder() && presentMonment < homeworks[i].getArrivalTime())
        {
            if (earlisetMonment >= homeworks[i].getArrivalTime())
            {
                earlisetMonment = homeworks[i].getArrivalTime();
                earliestHomeworkNumber = i;
            }
        }
    }


    // ��ǰʱ��û�����񵽴�
    if (maxWeight == -INF)
    {
        presentMonment = earlisetMonment;
        return calculateHomeworkWeight(homeworks, n, presentMonment, order);
    }

    // ���±����ȵ���ҵ������ֵ
    homeworks[maxWeightNumber].setSchedulingOrder(order);        // ���ȴ���1--n��������û��������Ϊ0��
    homeworks[maxWeightNumber].setFinishTime(presentMonment +
                                             homeworks[maxWeightNumber].getRunTime());                    // ���ʱ��
    homeworks[maxWeightNumber].setDispatchTime(presentMonment);  // ����ʱ�䣨��һ�α�CPU���ȣ�����ʼʱ�̣�
    homeworks[maxWeightNumber].setTurnaroundTime(homeworks[maxWeightNumber].getFinishTime() -
                                                 homeworks[maxWeightNumber].getArrivalTime());                // ��תʱ�䣨���ʱ�� - ����ʱ�̣�

    presentMonment = homeworks[maxWeightNumber].getFinishTime();

    return maxWeightNumber;
}

int main()
{
    cout << "������ҵ��K��\n";
    int n{};   // ��ҵ����>0��
    cin >> n;
    Homework* homeworks = new Homework[n]{};

    cout << "���� " << n << " ���ύʱ�������ʱ�䣺\n";
    int presentMoment{ INF };
    int TJ{};  // ����ʱ�� �������ʽ��XXYY������XX��ʱ��YY�Ƿ֣�
    int YS{};  // ����ʱ�䣨�Է��Ӽƣ�
    for (int i = 0; i < n; ++i)
    {
        cin >> TJ;
        homeworks[i].setArrivalTime((TJ / 100 * 60) + (TJ % 100));
        presentMoment = min(presentMoment, homeworks[i].getArrivalTime());  // ��ȡ��ʼʱ�̣������ȵ������ҵ����ʱ��

        cin >> YS;
        homeworks[i].setRunTime(YS);
        homeworks[i].setNumber(i);
    }

    cout << "���ȴ���  ��ҵ��  ����ʱ��(min)  ��תʱ��(min)  ��Ȩ��תʱ��(1+W/T)\n";
    int number{};                            // ��ǰ��CPU���ȵ���ҵ�ţ�0~n-1��
    double averageTurnaroundTime{};          // ƽ����תʱ��
    double averageWeightedTurnaroundTime{};  // ƽ����Ȩ��תʱ��
    int dispatchTime{};
    for (int i = 0; i < n; ++i)
    {
        number = calculateHomeworkWeight(homeworks, n, presentMoment, i + 1);
        cout << homeworks[number].getInfo() << '\n';
        averageTurnaroundTime += homeworks[number].getTurnaroundTime();
        averageWeightedTurnaroundTime += homeworks[number].getWeightedTurnaroundTime();
    }

    averageWeightedTurnaroundTime /= n;
    averageTurnaroundTime /= n;

    cout << "ƽ����תʱ�䣺" << averageTurnaroundTime << "min" << '\n';
    cout << "ƽ����Ȩ��תʱ�䣺" << averageWeightedTurnaroundTime << '\n';

    return 0;
}