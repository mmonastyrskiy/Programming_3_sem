package org.Terminal;
import org.Searcher.*;
public class Terminal{
    public Terminal(){

    }
    private void quit(){
        System.exit(0);
    }
    private void Save(String[] query){


    }
    private void Load(String[] query){

    }
    private void Search(String[] query){


    }
    private void Stat(String[] query){

    }
    private void Add(String[] query){

    }
    private void Del(String[] query){

    }
    public String[] ParceQuery(String query){
        String[] cmd = query.toLowerCase().split(" ");
        switch (cmd[0]){
            case "q":{quit();return cmd;}
            case "save":{Save(cmd);return cmd;}
            case "load":{Load(cmd);return cmd;}
            case "search":{Search(cmd);return cmd;}
            case "stat":{Stat(cmd); return  cmd;}
            case "add":{Add(cmd);return cmd;}
            case "del":{Del(cmd);return cmd;}
            default: return cmd;


        }
    }
}
