#ifndef FILEWITHCASHFLOW_H
#define FILEWITHCASHFLOW_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "CashFlow.h"
#include "XmlFile.h"


using namespace std;

class FileWithCashFlow : public XmlFile  {

    public:
    FileWithCashFlow(string cashFlowsFilename) : XmlFile(cashFlowsFilename) {};

    vector <CashFlow> loadCashFlowsFromFile(int loggedUserID);
    void addCashFlowToFile(CashFlow cashFlow);
    int getLastCashFlowID();
};
#endif
