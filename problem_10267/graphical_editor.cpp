#if !defined(NOT_JUDGING) or PROBLEM == 10267

#include <cstring>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class Image
{
public:
  explicit Image();
  ~Image();

  void Clear();
  void Reset(int width, int height);

  void DrawVerticalLine(int x, int y1, int y2, char color);
  void DrawHorizontalLine(int x1, int x2, int y, char color);
  void FillRectangle(int x1, int y1, int x2, int y2, char color);
  void FillRegion(int x, int y, char color);
  void SetPixel(int x, int y, char color);

  void Save(const string& name);

private:
  void ClearMask();
  void FillMask(int x, int y);

  int size;
  int width;
  char* content;
  bool* mask;
};

Image::Image() : size(0), width(0)
{
  content = new char[size];
  mask = new bool[size];
}

Image::~Image()
{
  delete [] content;
  delete [] mask;
}

void Image::Clear()
{
  memset(content, 'O', size);
}

void Image::ClearMask()
{
  memset(mask, false, size);
}

void Image::Reset(int width, int height)
{
  this->width = width;
  this->size = width * height;

  delete [] content;
  content = new char[size];

  delete [] mask;
  mask = new bool[size];

  Clear();
}

void Image::DrawVerticalLine(int x, int y1, int y2, char color)
{
  int first = min(y1, y2);
  int last = max(y1, y2);
  for (int y = first; y <= last; y++)
    SetPixel(x, y, color);
}

void Image::DrawHorizontalLine(int x1, int x2, int y, char color)
{
  int first = min(x1, x2);
  int last = max(x1, x2);
  for (int x = first; x <= last; x++)
    SetPixel(x, y, color);
}

void Image::FillRectangle(int x1, int y1, int x2, int y2, char color)
{
  int first_x = min(x1, x2);
  int last_x = max(x1, x2);
  int first_y = min(y1, y2);
  int last_y = max(y1, y2);
  for (int x = first_x; x <= last_x; x++)
    for (int y = first_y; y <= last_y; y++)
      SetPixel(x, y, color);
}

void Image::FillMask(int x, int y)
{
  int index = x + width * y;
  mask[index] = true;

  if (x > 0 && !mask[index - 1] && content[index - 1] == content[index])
    FillMask(x - 1, y);
  if ((x + 1) < width && !mask[index + 1] && content[index + 1] == content[index])
    FillMask(x + 1, y);

  if (y > 0 && !mask[index - width] && content[index - width] == content[index])
    FillMask(x, y - 1);
  if ((index + width) < size && !mask[index + width] && content[index + width] == content[index])
    FillMask(x, y + 1);
}

void Image::FillRegion(int x, int y, char color)
{
  ClearMask();
  FillMask(x, y);

  for (int i = 0; i < size; i++)
    if (mask[i])
      content[i] = color;
}

void Image::SetPixel(int x, int y, char color)
{
  content[x + width * y] = color;
}

void Image::Save(const string& name)
{
  cout << name << endl;
  for (int i = 0; i < size; i++)
  {
    if (i > 0 && (i % width) == 0)
      cout << endl;
    cout << content[i];
  }
  cout << endl;
}

int main()
{
  Image image;

  char command_char;
  while (cin >> command_char && command_char != 'X')
  {
    switch (command_char)
    {
    case 'I':
      {
        int width, height;
        cin >> width >> height;
        image.Reset(width, height);
      }
      break;

    case 'C':
      image.Clear();
      break;

    case 'L':
      {
        int x, y;
        char color;
        cin >> x >> y >> color;
        image.SetPixel(x - 1, y - 1, color);
      }
      break;

    case 'V':
      {
        int x, y1, y2;
        char color;
        cin >> x >> y1 >> y2 >> color;
        image.DrawVerticalLine(x - 1, y1 - 1, y2 - 1, color);
      }
      break;

    case 'H':
      {
        int x1, x2, y;
        char color;
        cin >> x1 >> x2 >> y >> color;
        image.DrawHorizontalLine(x1 - 1, x2 - 1, y - 1, color);
      }
      break;

    case 'K':
      {
        int x1, x2, y1, y2;
        char color;
        cin >> x1 >> y1 >> x2 >> y2 >> color;
        image.FillRectangle(x1 - 1, y1 - 1, x2 - 1, y2 - 1, color);
      }
      break;

    case 'F':
      {
        int x, y;
        char color;
        cin >> x >> y >> color;
        image.FillRegion(x - 1, y - 1, color);
      }
      break;

    case 'S':
      {
        string name;
        cin >> name;
        image.Save(name);
      }
      break;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return 0;
}

#endif
