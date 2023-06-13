import pa7.*;

public class driver {


    public static void main(String args[]){
        //This is our dataset. We have only one dataset.
        DataSet ds = new DataSet();

        Player p1 = new Player(); 
        Player p2 = new Player();
        Viewer v1 = new Viewer(); 
        Viewer v2 = new Viewer();

        
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
    

        
        ds.add(new Image("imagename1", "dimension info1", "other info1")); ds.add(new Image("imagename2", "dimension info2", "other info2")); ds.add(new Image("imagename3", "dimension info3", "other info3")); ds.add(new Image("imagename4", "dimension info4", "other info4")); ds.add(new Image("imagename5", "dimension info5", "other info5"));
        ds.add(new Audio("audioname1", "duration1", "other info1")); ds.add(new Audio("audioname2", "duration2", "other info2")); ds.add(new Audio("audioname3", "duration3", "other info3"));
        ds.add(new Video("videoname1", "duration1", "other info1")); ds.add(new Video("videoname2", "duration2", "other info2")); ds.add(new Video("videoname3", "duration3", "other info3"));
        ds.add(new Text("textname1", "other info1")); ds.add(new Text("textname2", "other info2")); ds.add(new Text("textname3", "other info3"));
        
        System.out.println(">>>>>PLAYER<<<<<");
        //remove the p1 player check later changes are affected
        ds.remove_observer(p1);

        Playable po = p1.currentlyPlaying();
        po.info();
        System.out.println();
        
        //next video
        p1.next("pa7.Video");
        po = p1.currentlyPlaying();
        po.info();
        System.out.println();
        ds.remove(po);//Remove the current playing

        System.out.println("******P1******");
        p1.show_list(); //No changes on p1
        System.out.println("******P2******");
        p2.show_list(); //videoname 1 will be deleted

        p1.previous("pa7.Audio");
        po = p1.currentlyPlaying();
        ds.remove(po);

        System.out.println("After deleting the previous Audio");
        System.out.println("******P2******");
        p2.show_list();
            
        //View
        System.out.println(">>>>>WIEWER<<<<<");
        ds.remove_observer(v1);
        NonPlayable px = v1.currentlyViewing();
        px.info();
        System.out.println();
        
        v1.next("pa7.Text");
        px = v1.currentlyViewing();
        px.info();
        System.out.println();
        ds.remove(px);//Remove the current viewing

        System.out.println("******V1******");
        v1.show_list(); //No changes on v1
        System.out.println("******V2******");
        v2.show_list();

        v1.previous("pa7.Image");
        v1.previous("pa7.Image");
        v1.previous("pa7.Image");
        px = v1.currentlyViewing();
        ds.remove(px);

        System.out.println("After deleting the 3 previous Image");
        System.out.println("******V2******");
        v2.show_list();

    }

    

    
}
