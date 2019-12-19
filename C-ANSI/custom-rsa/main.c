int n;
int e = 7;
int k = 1;

int RSA(int p, int q)
{
    n = p * q;
    int fN = (p -1) * (q - 1); 
    if (e % 2 != 0 && fN % e != 0)
    {
        double d = (k * fN + 1) / e;
        int wD = (int)d;
        if (wD - d == 0)
        {
            return d;
        }
    }
    return 0;
}
int Encrypt(int message)
{
    return pow(message, e) * fabs(n);
}
int Decrypt(int c, int d)
{
    return pow(c, d) * fabs(n);
}

void testRSA()
{
    int d = 0;
    int temp = 0;
    while (temp == 0)
    {
        temp = RSA(7, 11);
        printf(temp + "\n");
        if (temp == 0)
        {
            k++;
        }
        else
        {
            d = temp;
            temp++;
        }
    }
    int encrypted = Encrypt(5002);
    printf(encrypted + "\n");
    int decrypted = Encrypt(encrypted);
    printf(decrypted + "\n");
}

int main(int argc, char** argv) 
{
    testRSA();
    return 0;
}