#if !defined(NOT_JUDGING) or PROBLEM == 10267

#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

typedef void (*Command)(char** table, int* num_columns, int* num_rows);

void create_new_command(char** table, int* num_columns, int* num_rows)
{
  delete [] table;
  cin >> *num_columns >> *num_rows;
  int size = *num_columns * *num_rows;
  *table = new char[size];
  memset(*table, 'O', size);
}

void clear_table_command(char** table, int* num_columns, int* num_rows)
{
  int size = *num_columns * *num_rows;
  memset(*table, 'O', size);
}

void color_pixel_command(char** table, int* num_columns, int* num_rows)
{
  int x, y;
  char color;
  cin >> x >> y >> color;
  (*table)[(x - 1) + *num_columns * (y - 1)] = color;
}

void draw_vertical_segment_command(char** table, int* num_columns, int* num_rows)
{
  int x, y1, y2;
  char color;
  cin >> x >> y1 >> y2 >> color;
  for (int y = y1; y <= y2; y++)
    (*table)[(x - 1) + *num_columns * (y - 1)] = color;
}

void draw_horizontal_segment_command(char** table, int* num_columns, int* num_rows)
{
  int x1, x2, y;
  char color;
  cin >> x1 >> x2 >> y >> color;
  for (int x = x1; x <= x2; x++)
    (*table)[(x - 1) + *num_columns * (y - 1)] = color;
}

void draw_filled_rectangle_command(char** table, int* num_columns, int* num_rows)
{
  int x1, y1, x2, y2;
  char color;
  cin >> x1 >> y1 >> x2 >> y2 >> color;
  for (int x = x1; x <= x2; x++)
    for (int y = y1; y <= y2; y++)
      (*table)[(x - 1) + *num_columns * (y - 1)] = color;
}

void fill_region_command(char** table, int* num_columns, int* num_rows)
{
  int x, y;
  char color;
  cin >> x >> y >> color;
  x--; y--;

  // TODO!
}

void save_picture_command(char** table, int* num_columns, int* num_rows)
{
  string name;
  cin >> name;
  cout << name << endl;
  int size = *num_columns * *num_rows;
  for (int i = 0; i < size; i++)
  {
    if (i > 0 && (i % *num_columns) == 0)
      cout << endl;
    cout << (*table)[i];
  }
  cout << endl;
}

int main()
{
  map<char, Command> commands;
  commands.insert(pair<char, Command>('I', create_new_command));
  commands.insert(pair<char, Command>('C', clear_table_command));
  commands.insert(pair<char, Command>('L', color_pixel_command));
  commands.insert(pair<char, Command>('V', draw_vertical_segment_command));
  commands.insert(pair<char, Command>('H', draw_horizontal_segment_command));
  commands.insert(pair<char, Command>('K', draw_filled_rectangle_command));
  commands.insert(pair<char, Command>('F', fill_region_command));
  commands.insert(pair<char, Command>('S', save_picture_command));

  char* table = new char[0];
  int num_columns = 0, num_rows = 0;

  char command;
  while (cin >> command && command != 'X')
  {
    map<char, Command>::iterator it = commands.find(command);
    if (it == commands.end())
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    (it->second)(&table, &num_columns, &num_rows);
  }

  delete [] table;

  return 0;
}

#endif
