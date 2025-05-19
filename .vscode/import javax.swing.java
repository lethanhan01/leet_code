import javax.swing.JOptionPane;

public class Main {

    public static void main(String[] args) {
        int option = JOptionPane.showConfirmDialog(null,
                "Do you want to change to the first class ticket?");
        JOptionPane.showMessageDialog(null, "You've chosen: "
                + (option == JOptionPane.YES_OPTION ? "Yes" : "No"));
        JOptionPane.showMessageDialog(null, "ok");
        System.exit(0);
    }
}