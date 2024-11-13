package DesignPrinciples.LLD.ObserverDesignPattern.NotifyExample.Observers;

public class EmailObserverImpl implements NotificationObserver {

    @Override
    public void update() {
        onUpdate();
    }

    private void onUpdate() {
        System.out.println("Sending email...");
    }

}
