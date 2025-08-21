class Solution {
    int maxArea(List<int> height) {
        int l = 0, r = height.length - 1;
        int best = 0;

        while (l < r) {
            final int h = height[l] < height[r] ? height[l] : height[r];
            final int area = (r - l) * h;
            if (area > best) best = area;

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
    return best;
  }
}
