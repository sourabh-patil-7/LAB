import java.util.Scanner;

public class DiffieHellmanAlgorithmExample {
    public DiffieHellmanAlgorithmExample() {
    }

    public static void main(String[] var0) {
        try (Scanner var17 = new Scanner(System.in)) {
            System.out.println("Both the users should be agreed upon the public keys G and P");
            System.out.println("Enter value for public key G:");
            long var3 = var17.nextLong();
            System.out.println("Enter value for public key P:");
            long var1 = var17.nextLong();
            System.out.println("Enter value for private key a selected by user1:");
            long var7 = var17.nextLong();
            System.out.println("Enter value for private key b selected by user2:");
            long var11 = var17.nextLong();
            long var5 = calculatePower(var3, var7, var1);
            long var9 = calculatePower(var3, var11, var1);
            long var13 = calculatePower(var9, var7, var1);
            long var15 = calculatePower(var5, var11, var1);
            System.out.println("Secret key for User1 is:" + var13);
            System.out.println("Secret key for User2 is:" + var15);
        }
    }

    private static long calculatePower(long var0, long var2, long var4) {
        long var6 = 0L;
        if (var2 == 1L) {
            return var0;
        } else {
            var6 = (long) Math.pow((double) var0, (double) var2) % var4;
            return var6;
        }
    }
}
