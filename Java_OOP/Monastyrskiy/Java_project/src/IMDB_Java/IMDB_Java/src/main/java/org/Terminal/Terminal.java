package org.Terminal;

public class Terminal{
    public Terminal(){

    }
    private void quit(){
        System.exit(0);
    }
    private void Save(String query){

    }
    private void Load(String query){

    }
    private void Search(String query){

    }
    private void Stat(String query){

    }
    private void Add(String query){

    }
    private void Del(String query){

    }
    public String[] ParceQuery(String query){
        String[] cmd = query.toLowerCase().split(" ");
        switch (cmd[0]){
            case "q":{quit();return cmd;}
            case "save":{Save(query);return cmd;}
            case "load":{Load(query);return cmd;}
            case "search":{Search(query);return cmd;}
            case "stat":{Stat(query); return  cmd;}
            case "add":{Add(query);return cmd;}
            case "del":{Del(query);return cmd;}
            default: return cmd;


        }
    }
}
