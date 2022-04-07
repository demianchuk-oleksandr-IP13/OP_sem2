#11. �������� ���� i� ������� ������ � �������: 
#������������, ���� �������, ������� ����� ����������, 
#����. ������� ���� �� 5% �� �� ������, ������������ 
#����� ��������� ���� �� �������� ���� �����. 
#ϳ������� ���� �� 3% �� ������, ������������ ����� 
#��������� ���� ���� ������ ����. ������������ 
#����� ��������� ����������� �� ������ �������� 
#������ ���������� �� ���� ������� ������. 
#��������� � ����� ���� ��� ��� ������, �������� 
#����� ��������� �����.
import pickle
import datetime as dt
def createfile(path):
    with open(path, "wb") as f:
        info = []
        amt = int(input("wwedit' kilkist' tovariv: "))
        for i in range(amt):
            name = input("nazwa towaru: ")
            rdate = input("data wypusku (DD.MM.YYYY): ")
            xdate = input("termin prydatnosti: ")
            price = float(input("cina: "))
            tovar = {
                "name": name,
                "rdate": dt.datetime.strptime(rdate, "%d.%m.%Y"),
                "xdate": dt.datetime.strptime(xdate, "%d.%m.%Y"),
                "price": price
                }
            diff = tovar["xdate"] - tovar["rdate"]
            if(diff.days <= 14):
                tovar["price"] *= 0.95
            elif(diff.days > 365):
                tovar["price"] *= 1.03
            round(tovar["price"], 2)
            info.append(tovar)
        pickle.dump(info, f)

def outputfile(path):
    with open(path, 'rb') as f:
        l = pickle.load(f)
        for tovar in l:
            for key, value in tovar.items():
                print(key, value)

def copyfile(path, newpath):
    with open(path, 'rb') as old, open(newpath, 'wb') as new:
        current = dt.date.today()
        newinfo = []
        o = pickle.load(old)
        for tovar in o:
            if(tovar["rdate"].month < current.month):
                newinfo.append(tovar)
        pickle.dump(newinfo, new)