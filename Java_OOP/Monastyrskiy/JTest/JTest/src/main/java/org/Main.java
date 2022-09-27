package org;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Random;
import java.net.URL;
import java.net.URLConnection;
import org.json.*;
import org.json.JSONObject;


class PL{
    public static Path TaskFolderPath = Paths.get(".","Tasks");
    String name;
    String ext;
    String command;
    Task task;
    public PL(String name,Task T){
        this.name = name;
        this.task = T;
        if (!(T == null)) {
            get_settings(T);
        }

    }
    void get_settings(Task T){
        String filename = T.id;
        Path SettingsFile = Paths.get(TaskFolderPath.toString(),filename,".json");
        try {
            FileReader reader = new FileReader(SettingsFile.toString());
            JSONObject object = new JSONObject(reader.toString());
            this.ext = object.getJSONObject(name).getString("ext");
            this.command = object.getJSONObject(name).getString("cmd");


        }
        catch (FileNotFoundException e){"".isEmpty();
        }
        catch (IOException e){"".isEmpty();
        }


    }

}



class Task{
    String id;
    Path tests = Paths.get("Tests",this.id.toString());




}

class connection extends Socket{
    String id;
    String codefile = "";
    URL code_url;
    Socket client;
    PL attempt_PL;


   public void stop(){
        try {
            this.close();
        } catch (java.io.IOException e){
            "".isEmpty();
        }
    }

   public void downloadCode(Path d,PL p){
       try {
           URLConnection conn = this.code_url.openConnection();
           conn.setRequestProperty("User-Agent", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.95 Safari/537.11");
           String code =  conn.getInputStream().toString();
           PrintWriter printer = new PrintWriter(Paths.get(d.toString(),this.id,p.ext).toString());
           printer.println(code);
           printer.close();
           this.codefile = Paths.get(d.toString(),this.id,p.ext).toString();
           this.attempt_PL = p;






       } catch (IOException e){
           "".isEmpty();
       }

   }

   public void Run(){
       try {
           Path TestsFolder = this.attempt_PL.task.tests;
           FileReader reader = new FileReader(TestsFolder.toString());
           JSONObject Obj = new JSONObject(reader.toString());
           JSONArray inp_array= (JSONArray) Obj;
           String[] Input;
           String[] Expected_out;
       } catch (FileNotFoundException e){
           "".isEmpty();
       }




       try {
           Process process = Runtime.getRuntime().exec(this.attempt_PL.command + this.codefile);
           BufferedReader in = new BufferedReader(new InputStreamReader(process.getInputStream()));
           BufferedWriter out = new BufferedWriter(new OutputStreamWriter(process.getOutputStream()));



       } catch (IOException e) {
           "".isEmpty();
       }



   }
    public connection(Socket c){
        this.client = c;
        byte[] name = new byte[10];
        new Random().nextBytes(name);
                this.id = new String(name, Charset.forName("UTF-8"));



    }
}


public class Main {

    private static Socket clientSocket; //сокет для общения
    private static ServerSocket server; // серверсокет
    private static BufferedReader in; // поток чтения из сокета
    private static BufferedWriter out; // поток записи в сокет


    public static Path DownloadFolderPath = Paths.get(".","TMP","Codes");


    public static void main(String[] args){

    String[] langs = {"c++","python","java"};
    Task[] tasks = new Task[1000];
        int client_index =0;
        connection[] ActiveClients = new connection[100];

        try {
            try {
                server = new ServerSocket(9001);
                System.out.println("Сервер запущен!");
                clientSocket = server.accept();
                connection c = new connection(clientSocket);
                ActiveClients[client_index] = c;
                client_index++;


                try { // установив связь и воссоздав сокет для общения с клиентом можно перейти
                    // к созданию потоков ввода/вывода.
                    // теперь мы можем принимать сообщения
                    in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                    // и отправлять
                    out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()));



                    out.write("Введите ссылку на исходный код в Pastebin/raw ");





                    String url_str = in.readLine(); // ждём пока клиент что-нибудь нам напишет
                    System.out.println(url_str);
                    // не долго думая отвечает клиенту
                    out.write("Привет, это Сервер! Подтверждаю, вы написали : " + url_str + "\n");
                    URL url = new URL(url_str);
                    ActiveClients[client_index--].code_url = url;
                    out.write("Выберите язык из списка указав индекс");
                    for (String s: langs) {
                        out.write(s);
                    }
                    String idx = in.readLine();
                    int lang_idx = Integer.parseInt(idx);

                        out.write("Выберите таск из списка указав индекс");
                        for (int i =0; i < tasks.length; i++){
                            out.write("[" + i + "]" + tasks[i].id);

                        }
                    String lidx = in.readLine();
                    int lidxi = Integer.parseInt(lidx);
                    PL lang = new PL(langs[lang_idx],tasks[lidxi]);

                    ActiveClients[client_index--].downloadCode(DownloadFolderPath,lang);












                } finally { // в любом случае сокет будет закрыт
                    clientSocket.close();
                    // потоки тоже хорошо бы закрыть
                    in.close();
                    out.close();
                }
            } finally {
                System.out.println("Сервер закрыт!");
                server.close();
            }
        } catch (IOException e) {
            System.err.println(e);
        }
    }
            }