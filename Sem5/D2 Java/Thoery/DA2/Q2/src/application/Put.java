package application;

import javafx.application.Application;

import javafx.stage.Stage;
import javafx.scene.Scene;

import javafx.geometry.Pos;
import javafx.scene.layout.GridPane;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

import database.DB;

public class Put extends Application {

    public void start(Stage primaryStage) throws Exception {

        // LABELS AND TEXT FIEDLS FOR INPUT
        Label RollNo = new Label("Roll Number");
        TextField rollno = new TextField();

        Label Name = new Label("Name");
        TextField name = new TextField();

        Label CAT1 = new Label("CAT1");
        TextField cat1 = new TextField();

        Label CAT2 = new Label("CAT2");
        TextField cat2 = new TextField();

        Label FAT = new Label("FAT");
        TextField fat = new TextField();

        Label DA1 = new Label("DA1");
        TextField da1 = new TextField();

        Label DA2 = new Label("DA2");
        TextField da2 = new TextField();

        Label DA3 = new Label("DA3");
        TextField da3 = new TextField();

        // TITLE
        Label title = new Label();
        title.setText("DA2 CSE1007 Q1");
        Label res = new Label();
        title.setId("title"); // FOR CSS
        res.setId("res"); // FOR CSS

        // SUBMIT BUTTON
        Button Submit = new Button("Submit");
        Submit.setId("submit");

        // GRID PANE
        GridPane root = new GridPane();
        root.setVgap(5);
        root.setHgap(5);
        root.setAlignment(Pos.CENTER);

        // CSS
        root.getStylesheets().add("form.css");

        // NODES
        root.add(title, 0, 0);
        root.addRow(1, RollNo, rollno);
        root.addRow(2, Name, name);
        root.addRow(3, CAT1, cat1);
        root.addRow(4, CAT2, cat2);
        root.addRow(5, FAT, fat);
        root.addRow(6, DA1, da1);
        root.addRow(7, DA2, da2);
        root.addRow(8, DA3, da3);
        root.addRow(9, Submit);
        root.addRow(10, res);

        // EVENT HANDLER FOR SUBMIT BUTTON
        Submit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                String[] input = new String[9];
                int i = 0;

                input[i] = rollno.getText();
                input[++i] = name.getText();
                input[++i] = cat1.getText();
                input[++i] = cat2.getText();
                input[++i] = fat.getText();
                input[++i] = da1.getText();
                input[++i] = da2.getText();
                input[++i] = da3.getText();
                i = 0;

                String result = name.getText() + "< | " +
                        cat1.getText() + " | " +
                        cat2.getText() + " | " +
                        fat.getText() + " | " +
                        da1.getText() + " | " +
                        da2.getText() + " | " +
                        da3.getText() + " | >";

                System.out.println(result);
                root.getChildren().clear();
                root.addRow(0, title);
                root.addRow(1, res);
                res.setText(result);

                new DB().put(input);
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