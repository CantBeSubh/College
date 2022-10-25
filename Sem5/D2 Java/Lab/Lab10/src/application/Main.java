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

public class Main extends Application {
    int reverse(int n) {
        int res = 0;
        while (n != 0) {
            int r = n % 10;
            res = res * 10 + r;
            n = n / 10;
        }
        return res;
    }

    Boolean armstrong(int number) {
        int originalNumber, remainder, result = 0, n = 0;

        originalNumber = number;

        for (; originalNumber != 0; originalNumber /= 10, ++n)
            ;

        originalNumber = number;

        for (; originalNumber != 0; originalNumber /= 10) {
            remainder = originalNumber % 10;
            result += Math.pow(remainder, n);
        }

        if (result == number)
            return true;
        return false;
    }

    int decimalToBinary(int N) {
        int B_Number = 0;
        int cnt = 0;
        while (N != 0) {
            int rem = N % 2;
            double c = Math.pow(10, cnt);
            B_Number += rem * c;
            N /= 2;
            cnt++;
        }

        return B_Number;
    }

    Boolean pallindrone(int n) {
        int temp = n, r, sum = 0;
        while (n > 0) {
            r = n % 10;
            sum = (sum * 10) + r;
            n = n / 10;
        }
        if (temp == sum)
            return true;
        return false;

    }

    public void start(Stage primaryStage) throws Exception {

        // Label and Text Field for input
        Label input = new Label("Input");
        TextField tf1 = new TextField();

        // Title
        Label title = new Label();
        title.setText("Lab 10 CSE1007");
        Label res = new Label();
        title.setId("title");
        res.setId("res");

        // creating submit button
        Button Reverse = new Button("Reverse");
        Button Armstrong = new Button("Armstrong");
        Button DecimalToBinary = new Button("Decimal to Binary");
        Button Pallindrone = new Button("Pallindrone");
        Reverse.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                String val = tf1.getText();
                int n = 99;
                try {
                    n = Integer.parseInt(val);
                } catch (Exception e) {
                    System.out.println("WARNING: Invalid Input.Using default value.");
                }

                res.setText("Reverse of " + n + " is " + reverse(n));

            }
        });
        Armstrong.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                String val = tf1.getText();
                int n = 99;
                try {
                    n = Integer.parseInt(val);
                } catch (Exception e) {
                    System.out.println("WARNING: Invalid Input.Using default value.");
                }

                res.setText(n + " is " + (armstrong(n) ? "a armstrong" : "not a armstrong"));

            }
        });
        DecimalToBinary.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                String val = tf1.getText();
                int n = 99;
                try {
                    n = Integer.parseInt(val);
                } catch (Exception e) {
                    System.out.println("WARNING: Invalid Input.Using default value.");
                }

                res.setText("Binary of " + n + " is " + decimalToBinary(n));

            }
        });
        Pallindrone.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                System.out.println("Button Clicked");
                String val = tf1.getText();
                int n = 99;
                try {
                    n = Integer.parseInt(val);
                } catch (Exception e) {
                    System.out.println("WARNING: Invalid Input.Using default value.");
                }

                res.setText(n + " is " + (pallindrone(n) ? "a pallindrone" : "not a pallindrone"));

            }
        });

        // Grid-pane
        GridPane root = new GridPane();
        // Gap
        root.setVgap(5);
        root.setHgap(5);
        // Alignment
        root.setAlignment(Pos.CENTER);
        // Nodes
        // root.addRow(0, title);
        root.addRow(1, input, tf1);
        root.addRow(2, Reverse, Armstrong, DecimalToBinary);
        root.addRow(3, Pallindrone);
        root.addRow(4, res);
        root.add(title, 0, 0);
        // CSS
        root.getStylesheets().add("form.css");

        // Scene
        Scene scene = new Scene(root, 800, 600);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }

}