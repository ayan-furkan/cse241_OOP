package pa7;

import java.util.ArrayList;
import java.util.List;

public class Viewer {
    private List<NonPlayable> viewList;
    private int currentIndex;

    public Viewer() {
        viewList = new ArrayList<>();
        currentIndex = 0;
    }

    public void update(DataSetObject object) {
        if (object instanceof NonPlayable) {
            viewList.add((NonPlayable) object);
        }
    }

    public void remove(NonPlayable object){
        viewList.remove(object);        
    }


    public void show_list() {
        System.out.println("Viewlist:");
        for (NonPlayable nonplayable : viewList) {
            System.out.print("-");
            nonplayable.info();
            System.out.println("--------------------");
        }
    }

    public NonPlayable currentlyViewing() {
        if (currentIndex < viewList.size()) {
            return viewList.get(currentIndex);
        } else {
            System.out.println("No currently viewing object.");
            return null;
        }
    }

    public void next(String type) {
        while(currentIndex < viewList.size() - 1){
            if(viewList.get(currentIndex).getClass().getName() == type){
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
            if(viewList.get(currentIndex).getClass().getName() == type){
                return;
            }

        }

        System.out.println("No next viewable object.");
    }

}