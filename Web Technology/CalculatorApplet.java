import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class CalculatorApplet extends Applet implements ActionListener {
    TextField input;
    double result = 0;
    String operator = "=";
    boolean start = true;

    public void init() {
        setLayout(new BorderLayout());
        input = new TextField("0");
        input.setEditable(false);
        add(input, "North");

        Panel panel = new Panel();
        panel.setLayout(new GridLayout(4, 4));
        String[] keys = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+"};
        for (int i = 0; i < keys.length; i++) {
            Button b = new Button(keys[i]);
            panel.add(b);
            b.addActionListener(this);
        }
        add(panel, "Center");
    }

    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
        if ('0' <= cmd.charAt(0) && cmd.charAt(0) <= '9' || cmd.equals(".")) {
            if (start) {
                input.setText(cmd);
            } else {
                input.setText(input.getText() + cmd);
            }
            start = false;
        } else {
            if (start) {
                if (cmd.equals("-")) {
                    input.setText(cmd);
                    start = false;
                } else {
                    operator = cmd;
                }
            } else {
                double x = Double.parseDouble(input.getText());
                calculate(x);
                operator = cmd;
                start = true;
            }
        }
    }

    private void calculate(double n) {
        switch (operator) {
            case "+": result += n; break;
            case "-": result -= n; break;
            case "*": result *= n; break;
            case "/": result /= n; break;
            case "=": result = n; break;
        }
        input.setText("" + result);
    }
}
