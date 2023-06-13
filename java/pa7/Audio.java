package pa7;

public class Audio extends DataSetObject implements NonVisual,Playable {
    private String durationInfo;
    private String otherInfo;    

    public Audio(String name, String durationInfo, String otherInfo){
        super(name);
        this.durationInfo = durationInfo;
        this.otherInfo = otherInfo;
    }

    @Override
    public void info(){
        System.out.println(name);
        System.out.println("Duration: " + durationInfo);
        System.out.println("Other Info: " + otherInfo);
    }

    public String getDurationInfo(){
        return durationInfo;
    }

    public String getOtherInfo(){
        return otherInfo;
    }

    public void setDurationInfo(String durationInfo){
        this.durationInfo = durationInfo;
    }

    public void setOtherInfo(String otherInfo){
        this.otherInfo = otherInfo;
    }

}
