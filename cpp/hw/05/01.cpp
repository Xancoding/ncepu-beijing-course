#include <iostream>

class Loan {
public:
    virtual ~Loan() {}
    virtual void Show() const = 0;  // ���麯�������㲢��ʾ������Ϣ

protected:
    double m_loan_amount;  // ������
    int m_loan_years;     // ��������
    double m_interest_rate;  // ������

public:
    Loan(double amount, int years, double rate)
            : m_loan_amount(amount), m_loan_years(years), m_interest_rate(rate) {}
};

#include <cmath>

// �ȶϢ���ʽ
class EqualPrincipalAndInterest : public Loan {
public:
    EqualPrincipalAndInterest(double amount, int years, double rate)
            : Loan(amount, years, rate) {}

    void Show() const override {
        double monthly_payment = CalculateMonthlyPayment();
        std::cout << "�ȶϢ���ʽ��" << std::endl;
        std::cout << "ÿ�»���" << monthly_payment << std::endl;
        std::cout << "�ܻ���" << monthly_payment * m_loan_years * 12 << std::endl;
        std::cout << "����Ϣ��" << monthly_payment * m_loan_years * 12 - m_loan_amount << std::endl;

        for (int i = 1; i <= m_loan_years * 12; ++i) {
            double monthly_principal = monthly_payment - m_loan_amount * m_interest_rate / 12;
            double monthly_interest = monthly_payment - monthly_principal;
            std::cout << "�� " << i << " ���»��" << std::endl;
            std::cout << "    ����" << monthly_principal << std::endl;
            std::cout << "    ��Ϣ��" << monthly_interest << std::endl;
        }
    }

private:
    double CalculateMonthlyPayment() const {
        double monthly_interest_rate = m_interest_rate / 12 / 100;
        return m_loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, m_loan_years * 12) /
               (pow(1 + monthly_interest_rate, m_loan_years * 12) - 1);
    }
};

// �ȶ�𻹿ʽ
class EqualPrincipal : public Loan {
public:
    EqualPrincipal(double amount, int years, double rate) : Loan(amount, years, rate) {}

    void Show() const override {
        double monthly_principal = m_loan_amount / (m_loan_years * 12);
        double total_interest = 0;
        std::cout << "�ȶ�𻹿ʽ��" << std::endl;
        std::cout << "ÿ�»���" << monthly_principal + m_loan_amount * m_interest_rate / 12 / 100 << std::endl;
        std::cout << "�ܻ���" << (monthly_principal + m_loan_amount * m_interest_rate / 12 / 100) * m_loan_years * 12 << std::endl;

        for (int i = 1; i <= m_loan_years * 12; ++i) {
            double monthly_interest = m_loan_amount * m_interest_rate / 12 / 100 * (m_loan_years * 12 - i + 1) / (m_loan_years * 12);
            total_interest += monthly_interest;
            std::cout << "�� " << i << " ���»��" << std::endl;
            std::cout << "    ����" << monthly_principal << std::endl;
            std::cout << "    ��Ϣ��" << monthly_interest << std::endl;
        }

        std::cout << "����Ϣ��" << total_interest << std::endl;
    }
};

void ShowLoanInfo(const Loan& loan) {
    loan.Show();
}

int main() {
    const double amount = 1000000;  // ������
    const int years = 30;         // ��������
    const double rate = 4.9;       // ������

    // �����ȶϢ�͵ȶ�����
    EqualPrincipalAndInterest epi(amount, years, rate);
    EqualPrincipal ep(amount, years, rate);

    // ��ʾ������Ϣ
    ShowLoanInfo(epi);
    std::cout << std::endl;
    ShowLoanInfo(ep);

    return 0;
}
