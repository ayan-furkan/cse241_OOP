package pa7;

abstract public class DataSetObject {
    protected String name;

    public DataSetObject(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

}
