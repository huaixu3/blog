import tushare as ts
import pandas as pd

year        = 2020;quarter=3;
t_300       = ts.get_hs300s();
t_300_index = t_300.code;
t_300_index = t_300_index.to_list();
#get hs300 code,name,wight
t_all       = ts.get_stock_basics()
t_all       = t_all.loc[t_300_index]
#get all stocks basics => area industry pe rev outstanding holders
#t_report    = ts.get_report_data(2020,2)#parater
#t_report    = t_report[t_300_index]
#get report =>roe
t_cash      = ts.get_debtpaying_data(2020,2)#
t_cash.index=t_cash.code
t_cash      = t_cash.loc[t_300_index]
#get debt[aying =>cashratio
#t_roe=ts.get_profit_data(2020,1)
#t_roe.index=t_roe.code
#t_roe=t_roe.loc[t_300_index]
#colloction 
hs300=t_all.loc[:,['name','industry','area','pe','rev']]
hs300['ave']=t_all.totalAssets*100000/t_all.holders
#hs300['roe']=t_roe.roe
hs300['roe']=t_all.esp*100/t_all.bvps
hs300['cashratio']=t_cash.cashratio
hs300['weight']=t_300.weight.to_list()
hs300.to_csv('hs300.csv')
