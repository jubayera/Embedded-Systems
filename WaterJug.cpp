/* Water and Jug Problem:
   ---------------------
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. 
You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z litres of water is measurable, you must have z litres of water contained within one or both buckets by the end.

Operations allowed:

    -> Fill any of the jugs completely with water.
    -> Empty any of the jugs.
    -> Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

Example 1:
    Input: x = 3, y = 5, z = 4
    Output: True

Example 2:
    Input: x = 2, y = 6, z = 5
    Output: False   */

class Solution {
    public:
        bool canMeasureWater(int x, int y, int z) {
            if(z > x+y) 
                return false;

            if(x == 0 || y == 0) {
                int either = x + y;
                return either > 0 ? (z % either == 0) : (z == 0);
            }

            while (x != y)
            {
                if(x > y)
                    x -= y;
                else
                    y -= x;                
            }

            return z % x == 0;
            
        }
};
