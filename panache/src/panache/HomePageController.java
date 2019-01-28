package panache;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javax.swing.JFileChooser;

/**
 * FXML Controller class
 *
 * @author sanat
 */
public class HomePageController implements Initializable {

    @FXML
    private HBox homeButton;
    @FXML
    private HBox trendingButton;
    @FXML
    private HBox historyButton;
    @FXML
    private HBox watchLaterButton;
    @FXML
    private HBox uploadButton;
    @FXML
    private HBox settingButton;
    @FXML
    private Button searchButton;
    @FXML
    private Label userName;
    @FXML
    private ScrollPane scrollPane;
    GridPane gridPane = new GridPane();
    private int row;
    private File[] preview;
    final File dir = new File("C:\\Users\\sanat\\Desktop\\preview");

    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        
        gridPane.setAlignment(Pos.TOP_LEFT);
        gridPane.setHgap(20);
        gridPane.setVgap(20);
        gridPane.setPadding(new Insets(25, 25, 25, 25));
        
        try {
            homeButtonAction();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(HomePageController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }    

    @FXML
    private void homeButtonAction() throws FileNotFoundException {
        preview = dir.listFiles();
        int count = -1;
        
        for(int i = 0;i<5;i++){
            for(int j =0;j<4;j++){
                FileInputStream imageStream = new FileInputStream(preview[++count]);
                Image image = new Image(imageStream);
                ImageView img = new ImageView(image);
                img.setFitHeight(130);
                img.setFitWidth(130);
                gridPane.add(img,j,i);
                //Label sample = new Label("Sample Label");
                //gridPane.add(sample, j, i);
                //sample.setPrefWidth(150);
                //sample.setAlignment(Pos.CENTER);
            }
        }
        scrollPane.setContent(gridPane);
        scrollPane.setFitToWidth(true);
    }

    @FXML
    private void trendingButtonAction(MouseEvent event) {
        for(int i = 0 ; i<preview.length ;i++){
            System.out.println(preview[i].getAbsolutePath());
        }
    }

    @FXML
    private void historyButtonAction(MouseEvent event) {
    }

    @FXML
    private void watchLaterButton(MouseEvent event) {
    }

    @FXML
    private void uploadButtonAction(MouseEvent event) {
        try{
            JFileChooser chooser = new JFileChooser();
            chooser.setDialogTitle("Choose file to play..."); // setting title of title bar //
            chooser.showOpenDialog(null);
            File uploadFile = chooser.getSelectedFile();
 
        }
        catch(Exception e){ 
            
        }
    }

    @FXML
    private void settingButtonAction(MouseEvent event) {
    }

    @FXML
    private void searchButtonAction(MouseEvent event) {
    }
    
}
