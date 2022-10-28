interface Selector {
    boolean end();

    Object current();

    void next();
}

public class Sequence {
    private Object[] items;
    private int next = 0;
    private int next2 = 10;

    public Sequence(int size) {
        items = new Object[size];
    }

    public void add(Object x) {
        if (next < items.length)
            items[next++] = x;
    }

    public void down(Object y) {
        if (next2 > 0)
            items[--next2] = y;
    }


    public  void getSelector() {
        Selector selector = new Selector() {
            private int i = 0;

            @Override
            public boolean end() {
                return i == items.length;
            }

            @Override
            public Object current() {
                return items[i];
            }

            @Override
            public void next() {
                if (i < items.length)
                    i++;
            }
        };

        while (!selector.end()) {
            System.out.print(selector.current() + " ");
            selector.next();
        }

    }


    public  void getSelectorReverse(Sequence sequence) {
        Selector selector2 = new Selector() {
            private int i = 0;

            @Override
            public boolean end() {
                return i == items.length;
            }

            @Override
            public Object current() {
                return items[i];
            }

            @Override
            public void next() {
                if (i < sequence.items.length)
                    i++;


            }
        };
        while (!selector2.end()) {
            System.out.print(selector2.current() + " ");
            selector2.next();
        }
    }


    public static void main(String[] args) {
        Sequence sequence = new Sequence(10);
        for (int i = 0; i < 10; i++)
            sequence.add(Integer.toString(i));
        getSelector(sequence);
        System.out.println();
        for (int i = 0; i < 10; i++)
            sequence.down(Integer.toString(i));
        getSelectorReverse(sequence);
    }
}
