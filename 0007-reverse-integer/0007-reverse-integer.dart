
class Solution {
  int reverse(int x) {
    int a = x<0 ? -(int.parse((-x).toString().split('').reversed.join())):
        int.parse(x.toString().split('').reversed.join());
    return a >= 2147483648 || a < -2147483648 ? 0:a;
  }
}