package application;

import javafx.application.Application;

import javafx.scene.Scene;

import javafx.geometry.Pos;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

import database.DB;

public class Get extends Application {
    public void start(Stage primaryStage) throws Exception {

        // LABELS AND TEXT FIEDLS FOR INPUT
        Label Name = new Label("Name");
        TextField name = new TextField();

        // TITLE
        Label title = new Label();
        title.setText("DA2 CSE1007 Q1");
        title.setId("title");

        Label res = new Label();
        res.setId("res");

        Button Submit = new Button("Submit");
        Submit.setId("submit");

        // GRID PANE
        GridPane root = new GridPane();
        root.setVgap(5);
        root.setHgap(5);
        root.setAlignment(Pos.CENTER);
        root.getStylesheets().add("form.css");

        // NODES
        root.add(title, 0, 0);
        root.addRow(1, Name, name);
        root.addRow(2, Submit);
        root.addRow(3, res);

        Submit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                String input = name.getText();
                String[][] result = new String[5][8];

                result = new DB().get(input);
                String row = "< ";
                for (int i = 0; i < 5; i++) {
                    if (result[i][0] == null)
                        break;

                    Double tot = Integer.parseInt(result[i][2]) * .15 +
                            Integer.parseInt(result[i][3]) * .15 +
                            Integer.parseInt(result[i][4]) * .4 +
                            Integer.parseInt(result[i][5]) * 1.0 +
                            Integer.parseInt(result[i][6]) * 1.0 +
                            Integer.parseInt(result[i][7]) * 1.0;
                    for (int j = 0; j < 8; j++) {
                        row += result[i][j] + " | ";
                    }
                    row += ">\nTOTAL MARKS: " + tot + "\nGRADE: " + new DB().grades(tot);

                }

                if (row == "< ")
                    row = "No result found";
                System.out.println(row);
                root.getChildren().clear();
                root.addRow(0, title);
                root.addRow(1, res);
                res.setText(row);

            }
        });
        // SCENE
        Scene scene = new Scene(root, 800, 600);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
