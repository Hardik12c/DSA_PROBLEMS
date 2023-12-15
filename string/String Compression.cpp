class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int count = 1;
        char c = chars[0];
        int lastindex = 0;
        int size = 1;
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == c)
                count++;
            else
            {
                chars[lastindex] = c;
                lastindex++;
                if (count > 1)
                {
                    if (count <= 9)
                    {
                        chars[lastindex] = (count) + '0';
                        lastindex++;
                        size++;
                    }
                    else
                    {
                        string cou = to_string(count);
                        for (int j = 0; j < cou.size(); j++)
                        {
                            chars[lastindex] = cou[j];
                            lastindex++;
                        }
                        size += cou.size();
                    }
                }
                count = 1;
                c = chars[i];
                size++;
            }
        }
        chars[lastindex] = c;
        lastindex++;
        if (count > 1)
        {
            if (count <= 9)
            {
                chars[lastindex] = (count) + '0';
                lastindex++;
                size++;
            }
            else
            {
                string cou = to_string(count);
                for (int j = 0; j < cou.size(); j++)
                {
                    chars[lastindex] = cou[j];
                    lastindex++;
                }
                size += cou.size();
            }
        }
        return size;
    }
};