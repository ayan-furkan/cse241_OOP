package pa7;

import java.util.ArrayList;
import java.util.List;

public class Player {
    private List<Playable> playlist;
    private int currentIndex;

    public Player() {
        playlist = new ArrayList<>();
        currentIndex = 0;
    }

    public void update(DataSetObject object) {
        if (object instanceof Playable) {
            playlist.add((Playable) object);
        }
    }

    public void remove(Playable object){
        playlist.remove(object);        
    }


    public void next(String type) {

        while(currentIndex < playlist.size() - 1){
            if(playlist.get(currentIndex).getClass().getName() == type){
                return;
            }
            else {
                currentIndex++;
            }
        }

        System.out.println("No next playable object.");

    }

    public void previous(String type) {
        while(currentIndex > 0){
            currentIndex--;
            if(playlist.get(currentIndex).getClass().getName() == type){
                return;
            }
        }

        System.out.println("No next playable object.");
    }

    public Playable currentlyPlaying() {
        if (currentIndex < playlist.size()) {
            return playlist.get(currentIndex);
        } else {
            System.out.println("No currently playing object.");
            return null;
        }
    }

    public void show_list() {
        System.out.println("Playlist:");
        for (Playable playable : playlist) {
            System.out.print("-");
            playable.info();
            System.out.println("--------------------");
        }
    }
}