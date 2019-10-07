/*

In this problem, we are basically given the coordinates to two rectangles.
We can find the coordinates of overlapping rectangles through the following steps:
- the left x value is the maximum of the two x1 values
- the right x value is the minimum of the two x2 values
- the top y value is the minimum of the two y2 values
- the bottom y value is the maximum of the two y1 values
I recommend drawing a picture--it will make much more sense.

Use these steps to solve the overlap between the truck and each of the two billboards
and compute the area with these coordinates like you would (length*height).

Then just subtract the overlap from the area of the billboard and add the result
for the two billboards together and output this.

*/


#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x1, y1, x2, y2;
} b1, b2, t;

int getOverlapArea(Rect a, Rect b) {
    int leftInt = max(a.x1, b.x1);
    int rightInt = min(a.x2, b.x2);
    int topInt = min(a.y2, b.y2);
    int bottomInt = max(a.y1, b.y1);

    if (leftInt < rightInt && bottomInt < topInt) {
        return (rightInt-leftInt) * (topInt-bottomInt);
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    if (fopen("billboard.in", "r")) {
        freopen("billboard.in", "r", stdin);
        freopen("billboard.out", "w", stdout);
    }

    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    int b1t = getOverlapArea(b1, t);
    int b1area = (b1.x2 - b1.x1) * (b1.y2 - b1.y1);

    int b2t = getOverlapArea(b2, t);
    int b2area = (b2.x2 - b2.x1) * (b2.y2 - b2.y1);

    cout << ((b1area-b1t) + (b2area-b2t)) << "\n";

    return 0;
}
