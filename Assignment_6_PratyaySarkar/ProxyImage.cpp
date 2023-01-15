#include <iostream>
#include <ctime>
using namespace std;

class Image
{
public:
    string filename;
    int width;
    int height;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual string getName() = 0;
    virtual void modifyImage(int) = 0;
};

class RealImage : public Image
{
    int **image;

public:
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    string getName()
    {
        return filename;
    }
    int **getImage()
    {
        return image;
    }
    void setImage(int **image)
    {
        int i, j;
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++)
                this->image[i][j] = image[i][j];
    }
    void setImage()
    {
        srand((unsigned)time(0));
        int i, j;
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++)
                image[i][j] = rand() % 255;
    }
    void modifyImage(int bias)
    {
        int i, j;
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++)
                image[i][j] = (image[i][j] + bias) % 255;
    }
    void displayImage()
    {
        int i, j;
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
                cout << image[i][j] << "\t";
            cout << endl;
        }
    }
    RealImage(int w, int h, string s)
    {
        height = h;
        width = w;
        filename = s;
        image = new int *[height];
        for (int i = 0; i < height; i++)
            image[i] = new int[width];
        setImage();
        cout << "real Image" << endl;
    }
};

class ProxyImage : public Image
{
    RealImage *ri;

public:
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    string getName()
    {
        return filename;
    }
    void modifyImage(int bias)
    {
        this->ri->modifyImage(bias);
    }
    void displayImage()
    {
        this->ri->displayImage();
    }
    ProxyImage(RealImage *r)
    {
        this->height = r->height;
        this->width = r->width;
        this->filename = r->filename;
        this->ri = r;
        // cout << "proxy image complete" << endl;
    }
};

int main()
{
    cout << "\nEnter width and height of image: ";
    int w, h; string s;
    cin >> w >> h;
    cout << "\nEnter filename: ";
    cin >> s;
    RealImage *r = new RealImage(w, h, s);
    ProxyImage *p = new ProxyImage(r);
    cout << "\nThe height and width of the image: " << p->getHeight() << ", " << p->getWidth() << endl;
    cout << "Displaying the image matrix: " << endl;
    p->displayImage();
    int bias;
    cout << "\nEnter the bias for modifying the image matrix: ";
    cin >> bias;
    p->modifyImage(bias);
    cout << "Displaying the image matrix (after modification): " << endl;
    p->displayImage();
    return 0;
}