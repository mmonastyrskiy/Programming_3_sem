package org.Terminal;

class EndOfMenuException extends  Exception{
    public EndOfMenuException(){
        super("Меню выведено");
    }

}