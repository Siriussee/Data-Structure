int binSearch(const int s[], const int size, const int target)
{
    int flag = size / 2;
    int ans;
    while (1)
    {
        if (s[flag] < target)
        {
            flag /= 2;
            continue;
        }
        if (s[flag] > target)
        {
            flag += flag / 2;
        }
        if(s[flag] == target)
        {
            
        }
    }
}