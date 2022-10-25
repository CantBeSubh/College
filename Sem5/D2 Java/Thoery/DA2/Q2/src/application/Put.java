package application;

import database.DB;

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

public class Put extends Application {

    public void start(Stage primaryStage) throws Exception {

        // Label and Text Field for input
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

        // Title
        Label title = new Label();
        title.setText("DA2 CSE1007 Q1");
        Label res = new Label();
        // title.setX(120);
        // title.setY(120);
        title.setId("title");
        res.setId("res");

        // creating submit button
        Button Submit = new Button("Submit");
        Submit.setId("submit");
        // Grid-pane
        GridPane root = new GridPane();
        // Gap
        root.setVgap(5);
        root.setHgap(5);
        // Alignment
        root.setAlignment(Pos.CENTER);
        // Nodes
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
        // CSS
        root.getStylesheets().add("form.css");

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

                String result = name.getText() + " " +
                        cat1.getText() + " " +
                        cat2.getText() + " " +
                        fat.getText() + " " +
                        da1.getText() + " " +
                        da2.getText() + " " +
                        da3.getText() + " ";

                System.out.println(result);
                root.getChildren().clear();
                root.addRow(0, title);
                root.addRow(1, res);
                res.setText(result);

                new DB().put(input);
            }
        });

        // Scene
        Scene scene = new Scene(root, 800, 600);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }

}