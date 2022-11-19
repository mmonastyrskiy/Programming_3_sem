package org.Saveable;

import java.nio.file.Path;
import java.sql.ResultSet;

public interface Saveable {
    String GetDBInsertPrerapedFMT();
    void Save(Path path);

    void Load(Path path);
    static void ObjCreator( ResultSet obj_data, Saveable[] data_array){    // TODO ObjCreator должен извлекать данные из ResultSet, вызывать конструкторы сохраняемых объектов, создавая экземпляры
    }
}
