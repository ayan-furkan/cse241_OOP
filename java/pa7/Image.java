package pa7;

public class Image extends DataSetObject implements Visual, NonPlayable {
    private String dimensionInfo;
    private String otherInfo;
    
    public Image(String name, String dimensionInfo, String otherInfo){
        super(name);
        this.dimensionInfo = dimensionInfo;
        this.otherInfo = otherInfo;
    }

    @Override
    public void info(){
        System.out.println(name);
        System.out.println("Dimension: "+dimensionInfo);
        System.out.println("Other Info: " + otherInfo);
    }

    public String getDimensionInfo(){
        return dimensionInfo;
    }

    public String getOtherInfo(){
        return otherInfo;
    }

    public void setDimensionInfo(String dimensionInfo){
        this.dimensionInfo = dimensionInfo;
    }

    public void setOtherInfo(String otherInfo){
        this.otherInfo = otherInfo;
    }

}
