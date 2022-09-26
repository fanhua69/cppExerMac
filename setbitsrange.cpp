

int bits(int n, int m, int i, int j)
{
  int z = ~(-1);
  int max = ~0; /* All 1¡¯s */
                // 1¡¯s through position j, then 0¡¯s 
  int left = max - ((1 << j) - 1);
  // 1¡¯s after position i 
  int right = ((1 << i) - 1);
  // 1¡¯s, with 0s between i and j 
  int mask = right | left;
  // Clear i through j, then put m in there 
  return (n & mask) | (m << i);
}

void setbitsrange()
{
  int n = bits(0b11111111, 0b1111,3,6);


}