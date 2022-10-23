package application;

import javafx.application.Application;

import javafx.scene.Scene;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.ComboBox;

import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

import javafx.collections.FXCollections;

public class Main extends Application {
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i < n; i++)
            res *= i;
        return res;
    }

    int sum(int n) {
        return n * (n + 1) / 2;
    }

    String positiveOrNegative(int n) {
        if (n < 0)
            return "Negative";
        else
            return "Positive";
    }

    String evenOrOdd(int n) {
        if (n % 2 == 0)
            return "Even";
        else
            return "Odd";
    }

    int ascii(char val) {
        int res = val;
        return res;
    }

    String fibb(int n) {
        String res;
        int n1 = 0, n2 = 1, n3, i;
        res = n1 + " " + n2;

        for (i = 2; i < n; ++i) {
            n3 = n1 + n2;
            res = res.concat(" " + n3);
            n1 = n2;
            n2 = n3;
        }
        return res;
    }

    public void start(Stage primaryStage) throws Exception {

        // Label and Text Field for input
        Label input = new Label("Input");
        TextField tf1 = new TextField();

        // Title
        Text title = new Text();
        title.setText("DA2 CSE1007 Q1");
        title.setX(120);
        title.setY(120);
        title.setUnderline(true);
        title.setId("title");

        // Dropdown Menu
        String options[] = { "Factorial", "Sum of Natural Numbers", "Positive or Negative", "Even or Odd",
                "ASCII Value", "Fibonacci Series" };

        ComboBox<String> combo_box = new ComboBox<String>(FXCollections.observableArrayList(options));
        Label selected = new Label("--select--");
        selected.setWrapText(true);

        combo_box.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                selected.setText(combo_box.getValue());
            }
        });

        // creating submit button
        Button Submit = new Button("Submit");
        Submit.setId("submit");
        Submit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                int index = combo_box.getSelectionModel().getSelectedIndex();

                String val = tf1.getText();
                int n = -1;
                try {
                    n = Integer.parseInt(val);
                } catch (Exception e) {
                    System.out.println("WARNING: Invalid Input.Using default value.");
                }

                switch (index) {
                    case 0:
                        selected.setText("Factorial of " + n + " is " + factorial(n));
                        break;
                    case 1:
                        selected.setText("Sum of " + n + " natural numbers is " + sum(n));
                        break;
                    case 2:
                        selected.setText(n + " is " + positiveOrNegative(n));
                        break;
                    case 3:
                        selected.setText(n + " is " + evenOrOdd(n));
                        break;
                    case 4:
                        selected.setText("ASCII value of " + val + " is " + ascii(val.charAt(0)));
                        break;
                    case 5:
                        selected.setText("FIBB: " + fibb(n));
                        break;
                }
            }
        });

        // Grid-pane
        GridPane root = new GridPane();
        // Nodes
        root.addRow(0, title);
        root.addRow(1, input, tf1, combo_box);
        root.addRow(2, Submit);
        root.addRow(3, selected);
        // CSS
        root.getStylesheets().add("form.css");

        // Scene
        Scene scene = new Scene(root, 400, 400);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }

}