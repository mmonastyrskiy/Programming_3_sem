package org.Saveable;

import java.io.IOException;
import java.nio.file.Path;
import java.sql.ResultSet;

public interface Saveable {
    String getDBInsertPrerapedFMT();

    static void ObjCreator( ResultSet obj_data, Saveable[] data_array){    // TODO ObjCreator должен извлекать данные из ResultSet, вызывать конструкторы сохраняемых объектов, создавая экземпляры
    }
}
