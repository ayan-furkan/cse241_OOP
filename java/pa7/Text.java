package pa7;

public class Text extends DataSetObject implements NonPlayable, NonVisual{
        private String otherInfo;

        public Text(String name, String otherInfo){
            super(name);
            this.otherInfo = otherInfo;
        }

        @Override
        public void info(){
            System.out.println(name);
            System.out.println("Other Info: " + otherInfo);
        }
    
        public String getOtherInfo(){
            return otherInfo;
        }
    
        public void setOtherInfo(String otherInfo){
            this.otherInfo = otherInfo;
        }


}
