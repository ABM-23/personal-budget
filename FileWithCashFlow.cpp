#include "FileWithCashFlow.h"

vector<CashFlow> FileWithCashFlow::loadCashFlowsFromFile(int loggedUserID){
    CMarkup xml;
    vector<CashFlow> cashFlows;
    bool fileExists = xml.Load(getFileName().c_str());

    if (fileExists) {

        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("CashFlow") ) {
            xml.IntoElem();

            xml.FindElem( "UserID" );
            if (loggedUserID == atoi(MCD_2PCSZ(xml.GetData()))) {
                CashFlow cashFlow;
                cashFlow.setUserID(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem( "CashFlowID" );
                cashFlow.setCashFlowID(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem( "Item" );
                cashFlow.setItemName(xml.GetData());

                xml.FindElem( "Amount" );
                cashFlow.setAmount(stof(xml.GetData()));

                xml.FindElem( "Date" );
                cashFlow.setDate(AuxiliaryMethods::convertStringToDate(xml.GetData()));

                cashFlows.push_back(cashFlow);
            }
            xml.OutOfElem();
        }
    }
    return cashFlows;
}
void FileWithCashFlow::addCashFlowToFile(CashFlow cashFlowToAdd) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("CashFlows");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "CashFlow" );
    xml.IntoElem();
    xml.AddElem( "UserID", cashFlowToAdd.getUserID());
    xml.AddElem( "CashFlowID", cashFlowToAdd.getCashFlowID());
    xml.AddElem( "Item", cashFlowToAdd.getItemName());
    xml.AddElem( "Amount", to_string(cashFlowToAdd.getAmount()));
    xml.AddElem( "Date", AuxiliaryMethods::convertDateToString(cashFlowToAdd.getDate()));
    xml.Save(getFileName().c_str());
}
int FileWithCashFlow::getLastCashFlowID(){
    CMarkup xml;
    int lastCashFlowID = 0;
    bool fileExists = xml.Load(getFileName().c_str());

    if (fileExists) {

        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("CashFlow") ) {
            xml.IntoElem();
            xml.FindElem( "CashFlowID" );
            lastCashFlowID++;
            xml.OutOfElem();
        }
    }
    return lastCashFlowID;
}
