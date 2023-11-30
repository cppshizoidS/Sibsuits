namespace src;

public static partial class HW27
{
   public delegate bool MaxHashSetDelegate(int a);
   
   public static int Function27(HashSet<int> intSet, MaxHashSetDelegate filter)
   {
      int max = 0;
      foreach(int num in intSet)
      {
         if(filter(num) && num > max)
         {
            max = num;
         }
      }
      return max;
   }
}
