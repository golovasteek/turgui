#ifndef ALGO_H
#define ALGO_H

inline int maxCommonSubstring(const QVector<QString>& words, QVector<int> offsets)
{
    offsets.resize(words.size());
    for (offsets[0] = 0; offsets[0] < words[0].size(); ++offsets[0])
    {
        for (int length = words[0].size() - offsets[0]; length > 0; --length)
        {
            QString curSub = words[0].mid(offsets[0], length);
            for (int w = 1; w < words.size(); ++w)
            {
                if (words[w].indexOf(curSub) == -1)
                {
                    break;
                }
                else if (w == words.size() - 1)
                {
                    return length;
                }
            }
        }
    }
    return 0;
}
#endif // ALGO_H
