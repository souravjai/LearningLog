package DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observables;

import java.util.ArrayList;
import java.util.List;

import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observers.NotificationObserver;

public class iPhoneStockImp implements StockObservable {

    List<NotificationObserver> observers = new ArrayList<>();
    int currentStock = 0;

    @Override
    public void addObserever(NotificationObserver ob) {
        observers.add(ob);
    }

    @Override
    public void removeObserver(NotificationObserver ob) {
        observers.remove(ob);

    }

    @Override
    public void notifyAllObserver() {
        observers.forEach(obs -> obs.update());
    }

    @Override
    public void updateStock(int item) {

        if (currentStock == 0) {
            notifyAllObserver();
        }

        currentStock = item;

        System.out.println("Stock is now: "+currentStock);
        System.out.println();
    }

}
