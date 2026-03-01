public class SmartCalculator {
    public static void main(String[] args) {
        
        if (args.length < 3) return;

        try {
            double a = Double.parseDouble(args[0]);
            String op = args[1];
            double b = Double.parseDouble(args[2]);

            if (op.equals("+")) System.out.println(a + b);
            else if (op.equals("-")) System.out.println(a - b);
            else if (op.equals("*")) System.out.println(a * b);
            else if (op.equals("/")) System.out.println(b == 0 ? "Error" : a / b);
            else System.out.println("Unknown Op");
        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}