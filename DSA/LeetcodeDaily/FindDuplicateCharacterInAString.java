package LeetcodeDaily;

class Test {
    public static void main(String[] args) {
        String s = "ABBCBC";

        int freq[] = new int[26];

        for (int i = 0; i < s.length(); i++) {
            char ch = Character.toLowerCase(s.charAt(i));
            int alphabetPos = ch - 'a';

            freq[alphabetPos]++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 1) {
                System.out.println((char) ('a' + i));
            }
        }

    }
}