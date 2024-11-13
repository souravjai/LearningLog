package DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample;

import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observables.StockObservable;
import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observables.iPhoneStockImp;
import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observers.AppNotificationObserverImpl;
import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observers.EmailObserverImpl;
import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observers.NotificationObserver;

public class NotifyMain {
    public static void main(String[] args) {

        NotificationObserver ob1 = new EmailObserverImpl();
        NotificationObserver ob2 = new EmailObserverImpl();
        NotificationObserver ob3 = new AppNotificationObserverImpl();

        StockObservable iphoneStock = new iPhoneStockImp();

        iphoneStock.addObserever(ob1);
        iphoneStock.addObserever(ob2);
        iphoneStock.addObserever(ob3);

        iphoneStock.updateStock(5);
        iphoneStock.updateStock(2);

        iphoneStock.removeObserver(ob2);

        iphoneStock.updateStock(0);
        iphoneStock.updateStock(10);

    }
}
