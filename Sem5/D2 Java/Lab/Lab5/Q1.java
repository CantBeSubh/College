class Q1 {
    static int SentenceCount(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '.')
                count++;
        }
        return count;
    }

    static int CountC(String s) {
        int count = 0;
        if (s.charAt(0) == 'c')
            count++;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == ' ' && s.charAt(i) == 'c')
                count++;
        }
        return count;
    }

    public static void main(String[] args) {
        String str = "Welcome to VIT Chennai Campus. Have a great learning experience. Wishing you all the best for this semester. Thank you for your cooperation.";
        System.out.println("Sentence COunt: " + SentenceCount(str));
        System.out.println("Words starting with 'c': " + CountC(str));
    }
}