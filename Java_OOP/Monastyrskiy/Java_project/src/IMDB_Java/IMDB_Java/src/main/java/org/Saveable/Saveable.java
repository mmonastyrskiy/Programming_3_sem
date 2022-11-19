package org.Saveable;

import java.nio.file.Path;

public interface Saveable {
    public String GetDBInsertPrerapedFMT();
    public void Save(Path path);

}
