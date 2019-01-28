package panache;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;

/**
 * FXML Controller class
 *
 * @author sanat
 */
public class RegisterController implements Initializable {

    @FXML
    private AnchorPane registerPane;
    @FXML
    private TextField userName;
    @FXML
    private TextField mailId;
    @FXML
    private PasswordField password;
    @FXML
    private PasswordField repassword;
    @FXML
    private Button backButton;
    @FXML
    private Button submitButton;
    @FXML
    private Button exitbutton;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    

    @FXML
    private void backButtonAction(ActionEvent event) {
        
        try {
            AnchorPane rootPane = FXMLLoader.load(getClass().getResource("FXMLDocument.fxml"));
            registerPane.getChildren().setAll(rootPane);
        } catch (IOException ex) {
            Logger.getLogger(RegisterController.class.getName()).log(Level.SEVERE, null, ex);
        }
            
    }

    @FXML
    private void submitButtonAction(ActionEvent event) {
    }

    @FXML
    private void exitButtonAction(ActionEvent event) {
        System.exit(0);
    }
    
}
