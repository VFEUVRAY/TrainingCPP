using System;
using System.Collections;

public class Whatever
{
    /* all of your previous shit*/


    private static int getDiffIndex(string a, string b)
    {
        int i = 0;
        while(a[i] && b[i]) {
            if (a[i] != b[i])
                return (i);
            i++;
        }
        return (-1);
    }
    private static int obj_compare(object a, object b)
    {
        int diffIndex;
        if (a.quality == b.quality){
            //considering a.name is type String
            diffIndex = a.name.CompareTo(b.name);
            if (diffIndex == 0) {
                return (a.quantity > b.quantity);
            }
            return (diffIndex);
        }
        return (a.quality < b.quality);
    }

    public override Sort()
    {
        ObjectList.Sort(obj_compare);
    }
}