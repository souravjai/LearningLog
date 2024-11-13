package DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observables;

import DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observers.NotificationObserver;

public interface StockObservable {

    void addObserever(NotificationObserver ob);

    void removeObserver(NotificationObserver ob);

    void notifyAllObserver();

    void updateStock(int items);

}
