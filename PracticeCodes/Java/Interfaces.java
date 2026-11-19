/*
 * OOP concept: Interfaces and multiple capabilities.
 *
 * An interface defines a contract: it describes methods that an implementing
 * class must provide without requiring that class to inherit implementation
 * from a particular parent class. Camera describes taking photos and GPS
 * describes locating the device. SmartPhone implements both contracts.
 *
 * Java allows a class to implement multiple interfaces. This provides a safe
 * form of multiple inheritance of type and avoids the shared-state ambiguity
 * that can occur when extending multiple classes. A caller can hold the same
 * SmartPhone through a Camera reference or a GPS reference and depend only on
 * the capability it needs.
 *
 * Interfaces support loose coupling and dependency inversion: services can be
 * written against Camera or GPS rather than against the concrete SmartPhone.
 * Another class could implement the same interface later without changing the
 * client code.
 *
 * Execution flow: one SmartPhone object is viewed through two interface types,
 * and each reference invokes its corresponding capability.
 */
public class Interfaces {
    private interface Camera { void takePhoto(); }
    private interface GPS { void locate(); }

    private static class SmartPhone implements Camera, GPS {
        @Override public void takePhoto() { System.out.println("Photo captured"); }
        @Override public void locate() { System.out.println("Current location found"); }
    }

    public static void main(String[] args) {
        SmartPhone phone = new SmartPhone();
        Camera camera = phone;
        GPS gps = phone;
        camera.takePhoto();
        gps.locate();
    }
}