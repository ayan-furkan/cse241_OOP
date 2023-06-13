package pa7;

import java.util.ArrayList;
import java.util.List;




public class DataSet {
    private List<DataSetObject> objects;
    private List<Player> players;
    private List<Viewer> viewers;

    public DataSet() {
        objects = new ArrayList<>();
        players = new ArrayList<>();
        viewers = new ArrayList<>();
    }

    public void add(DataSetObject object) {
        objects.add(object);
        notifyObservers(object);
    }


    public void remove(Playable obj){
        for(Player player: players){
            player.remove(obj);
        }
    }
    
    public void remove(NonPlayable obj){
        for(Viewer view: viewers){
            view.remove(obj);
        }
    }

    public void register(Player player) {
        players.add(player);
    }

    public void remove_observer(Player player) {
        players.remove(player);
    }

    public void register(Viewer viewer) {
        viewers.add(viewer);
    }

    public void remove_observer(Viewer viewer) {
        viewers.remove(viewer);
    }

    private void notifyObservers(DataSetObject object) {
        if (object instanceof Playable) {
            for (Player player : players) {
                player.update(object);
            }
        } else if (object instanceof NonPlayable) {
            for (Viewer viewer : viewers) {
                viewer.update(object);
            }
        }
    }
}
