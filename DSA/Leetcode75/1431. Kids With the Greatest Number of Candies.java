class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = Arrays.stream(candies).max().orElse(0);
        int threshold = max - extraCandies;

        return Arrays.stream(candies).mapToObj(candy -> candy >= threshold)
                .collect(Collectors.toList());
    }
}