void manacher()
{
    int i;
    int mx = 0;
    int id;
    for(i=1; i<n; i++)
    {
        if( mx > i )
            p[i] = min( p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++);
            
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

void pre()
{
    int i,j,k;
    n = strlen(s);
    str[0] = '$';
    str[1] = '#';
    For(i, n)
    {
        str[i*2 + 2] = s[i];
        str[i*2 + 3] = '#';
    }
    n = n*2 + 2;
    str[n] = 0;
}