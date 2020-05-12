//l => loan 
//c => calculation way
//p => payback way 
#include<iostream>
#include<iomanip>
#include<cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

class l1c1p1
{
	private:
		double unit_price, area, mortgage_rate, interest_rate;
		
		int mortgage_year;
		
	public:
		l1c1p1(double a,double b,double c,int d,double e)
		{
			unit_price = a;
			
			area = b;
			
			mortgage_rate = c;
			
			mortgage_year = d;
			
			interest_rate = e;
		}
		

        double first_pay()
        {
            double fp;

            fp = unit_price*area*(1-mortgage_rate);

            return fp;
        }

        double month_pay()
        {
            double mp;

            mp = (unit_price*area*mortgage_rate)*(interest_rate/12)*pow((1+interest_rate/12),mortgage_year*12)/(pow((1+interest_rate/12),mortgage_year*12)-1);

            return mp;
        }

        double total_loan()
        {
            double tl;

            tl = unit_price*area*mortgage_rate;

            return tl;
        }

        double interest_pay()
        {
            double ip;

            ip = month_pay()*mortgage_year*12 - total_loan();

            return ip;
        }

        double total_pay()
        {
            double tp;

            tp = month_pay()*mortgage_year*12;

            return tp;
        }

        int mortgage_month()
        {
            return mortgage_year*12;
        }
};

class l1c1p2
{
	private:
		double unit_price, area, mortgage_rate, interest_rate;
		
		int mortgage_year;
	
	public:
		l1c1p2(double a,double b,double c,int d,double e)
		{
			unit_price = a;
			
			area = b;
			
			mortgage_rate = c;
			
			mortgage_year = d;
			
			interest_rate = e;
		}
		
        double first_pay()
        {
            double fp;

            fp = unit_price*area*(1-mortgage_rate);

            return fp;
        }

        double first_month_pay()
        {
            double fmp;

            fmp = (unit_price*area*mortgage_rate/(mortgage_year*12))+((unit_price*area*mortgage_rate)*interest_rate/12);

            return fmp;
        }

        double every_month_decrease()
        {
            double emd;

            emd = unit_price*area*mortgage_rate/(mortgage_year*12)*(interest_rate/12);

            return emd;
        }

        double total_loan()
        {
            double tl;

            tl = unit_price*area*mortgage_rate;

            return tl;
        }

        double interest_pay()
        {
            double ip;

            ip = ((unit_price*area*mortgage_rate/(mortgage_year*12)+unit_price*area*mortgage_rate*(interest_rate/12))+unit_price*area*mortgage_rate/(mortgage_year*12)*(1+interest_rate/12))/2*(mortgage_year*12)-unit_price*area*mortgage_rate;

            return ip;
        }

        double total_pay()
        {
            double tp;

            tp = ((unit_price*area*mortgage_rate/(mortgage_year*12)+unit_price*area*mortgage_rate*(interest_rate/12))+unit_price*area*mortgage_rate/(mortgage_year*12)*(1+interest_rate/12))/2*(mortgage_year*12);

            return tp;
        }

        int mortgage_month()
        {
            return mortgage_year*12;
        }
};

class l1c2p1
{
	private:
        double totalloan, interest_rate;
		
		int mortgage_year;
		
	public:
		l1c2p1(double a, int b, double c)
		{
            totalloan = a;
			
			mortgage_year = b;
			
			interest_rate = c;
		}

        double month_pay()
        {
            double mp;

            mp = totalloan*(interest_rate/12)*pow((1+interest_rate/12),mortgage_year*12)/(pow((1+interest_rate/12),mortgage_year*12)-1);

            return mp;
        }

        double total_loan()
        {
            double tl;

            tl = totalloan;

            return tl;
        }

        double interest_pay()
        {
            double ip;

            ip = month_pay()*mortgage_year*12 - total_loan();

            return ip;
        }

        double total_pay()
        {
            double tp;

            tp = month_pay()*mortgage_year*12;

            return tp;
        }

        int mortgage_month()
        {
            return mortgage_year*12;
        }
};

class l1c2p2
{
	private:
        double totalloan, interest_rate;
		
		int mortgage_year;
	
	public:
		l1c2p2(double a, int b, double c)
		{
            totalloan = a;
			
			mortgage_year = b;
			
			interest_rate = c;
		}
		 
        double first_month_pay()
        {
            double fmp;

            fmp = (total_loan()/(mortgage_year*12))+((total_loan())*interest_rate/12);

            return fmp;
        }

        double every_month_decrease()
        {
            double emd;

            emd = total_loan()/(mortgage_year*12)*(interest_rate/12);

            return emd;
        }

        double total_loan()
        {
            double tl;

            tl = totalloan;

            return tl;
        }

        double interest_pay()
        {
            double ip;

            ip = ((total_loan()/(mortgage_year*12)+total_loan()*(interest_rate/12))+total_loan()/(mortgage_year*12)*(1+interest_rate/12))/2*(mortgage_year*12)-total_loan();

            return ip;
        }

        double total_pay()
        {
            double tp;

            tp = ((total_loan()/(mortgage_year*12)+total_loan()*(interest_rate/12))+total_loan()/(mortgage_year*12)*(1+interest_rate/12))/2*(mortgage_year*12);

            return tp;
        }

        int mortgage_month()
        {
            return mortgage_year*12;
        }
};

class l2p1
{
	private:
		double buss_loan, buss_interest_rate, com_loan, com_interest_rate;
		
		int mortgage_year;
		
	public:
		l2p1(double a,double b, double c, double d, int e)
		{
			buss_loan = a;
			
			buss_interest_rate = b;
			
			com_loan = c;
			
			com_interest_rate = d;
			
			mortgage_year = e;
		}
		
        double month_pay()
        {
            double mp;

            mp = buss_loan*(buss_interest_rate/12)*pow((1+buss_interest_rate/12),mortgage_year*12)/(pow((1+buss_interest_rate/12),mortgage_year*12)-1);

            mp += com_loan*(com_interest_rate/12)*pow((1+com_interest_rate/12),mortgage_year*12)/(pow((1+com_interest_rate/12),mortgage_year*12)-1);

            return mp;
        }

        double total_loan()
        {
            double tl;

            tl = buss_loan+com_loan;

            return tl;
        }

        double interest_pay()
        {
            double ip;

            ip = month_pay()*mortgage_year*12 - total_loan();

            return ip;
        }

        double total_pay()
        {
            double tp;

            tp = month_pay()*mortgage_year*12;

            return tp;
        }

        int mortgage_month()
        {
            return mortgage_year*12;
        }

};

class l2p2
{
	private:
		double buss_loan, buss_interest_rate, com_loan, com_interest_rate;
		
		int mortgage_year;
		
	public:
		l2p2(double a,double b, double c, double d, int e)
		{
			buss_loan = a;
			
			buss_interest_rate = b;
			
			com_loan = c;
			
			com_interest_rate = d;
			
			mortgage_year = e;
		}
		
        double first_month_pay()
        {
            double fmp;

            fmp = (buss_loan/(mortgage_year*12))+((buss_loan)*buss_interest_rate/12)+(com_loan/(mortgage_year*12))+((com_loan)*com_interest_rate/12);

            return fmp;
        }

        double every_month_decrease()
        {
            double emd;

            emd = buss_loan/(mortgage_year*12)*(buss_interest_rate/12)+com_loan/(mortgage_year*12)*(com_interest_rate/12);

            return emd;
        }

        double total_loan()
        {
            double tl;

            tl = buss_loan + com_loan;

            return tl;
        }

        double interest_pay()
        {
            double ip;

            ip = ((buss_loan/(mortgage_year*12)+buss_loan*(buss_interest_rate/12))+buss_loan/(mortgage_year*12)*(1+buss_interest_rate/12))/2*(mortgage_year*12)-buss_loan + ((com_loan/(mortgage_year*12)+com_loan*(com_interest_rate/12))+com_loan/(mortgage_year*12)*(1+com_interest_rate/12))/2*(mortgage_year*12)-com_loan;

            return ip;
        }

        double total_pay()
        {
            double tp;

            tp = ((buss_loan/(mortgage_year*12)+buss_loan*(buss_interest_rate/12))+buss_loan/(mortgage_year*12)*(1+buss_interest_rate/12))/2*(mortgage_year*12) + ((com_loan/(mortgage_year*12)+com_loan*(com_interest_rate/12))+com_loan/(mortgage_year*12)*(1+com_interest_rate/12))/2*(mortgage_year*12);

            return tp;
        }

        int mortgage_month()
        {
            return mortgage_year*12;
        }
};
