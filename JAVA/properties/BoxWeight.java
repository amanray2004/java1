package JAVA.properties;

public class BoxWeight extends Box {

    int w;
    public BoxWeight(){
        super();
        this.w=-1;
    }

    public BoxWeight(int w) {
        this.w = w;
    }

    public BoxWeight(double side, int w) {
        super(side);
        this.w = w;
    }

    public BoxWeight(double l, double h, double w, int w2) {
        super(l, h, w);//CALLS THE PARENT CLASS CONSTRUCTOR
        w = w2;
    }

    public BoxWeight(Box old, int w) {
        super(old);
        this.w = w;
    }
    
    
}
