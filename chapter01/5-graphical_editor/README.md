# Graphical Editor (10267) #

The simple graphical editor deals with a rectangular table M×N (1<=M,N<=250).
Each pixel of the table has its colour. The picture is formed from this square
pixels.

The problem is to write a program, which simulates an interactive work of the
graphical editor.


## Input ##

Input consists of the editor commands, one per line. Each command is represented
by one Latin capital placed in the very beginning of the line. If the command
supposes parameters, all the parameters will be given in the same line separated
by space. As the parameters there may be: the coordinates of the pixel - two
integers, the first one is the column number and belongs to 1..M, the second one
is the row number and belongs to 1..N, the origin is in the upper left corner of
the table; the colour - the Latin capital; file name - in MSDOS 8.3 format.

The editor deals with the following commands:

<table>
  <tr>
    <td>I M N</td>
    <td>Creates a new table M×N. All the pixels are colored in white (O).</td>
  </tr>
  <tr>
    <td>C</td>
    <td>Clears the table. The size remains the same. All the pixels became white
      (O).</td>
  </tr>
  <tr>
    <td>L X Y C</td>
    <td>Colors the pixel with coordinates (X,Y) in colour C.</td>
  </tr>
  <tr>
    <td>V X Y1 Y2 C</td>
    <td>Draws the vertical segment in the column X between the rows Y1 and Y2
      inclusive in colour C.</td>
  </tr>
  <tr>
    <td>H X1 X2 Y C</td>
    <td>Draws the horizontal segment in the row Y between the columns X1 and X2
      inclusive in colour C.</td>
  </tr>
  <tr>
    <td>K X1 Y1 X2 Y2 C</td>
    <td>Draws the filled rectangle in colour C. (X1,Y1) is the upper left
      corner, (X2,Y2) is the lower right corner of the rectangle.</td>
  </tr>
  <tr>
    <td>F X Y C</td>
    <td>Fills the region with the colour C. The region R to be filled is defined
      as follows. The pixel (X,Y) belongs to this region. The other pixel
      belongs to the region R if and only if it has the same colour as pixel
      (X,Y) and a common side with any pixel which belongs to this region.</td>
  </tr>
  <tr>
    <td>S Name</td>
    <td>Writes the picture in the file Name.</td>
  </tr>
  <tr>
    <td>X</td>
    <td>Terminates the session.</td>
  </tr>
</table>


## Output ##

Every time the command S NAME meets, you should output the file name NAME and
the current table, row by row. Each row is represented by a pixels' colours
series, see the output sample.


## Errors ##

If as a command there will be a character different from I, C, L, V, H, K, F, S,
X, the editor should ignore the whole line and pass to the next command.

In case of other errors the program behaviour is unpredictable.


## Sample Input ##

    I 5 6
    L 2 3 A
    S one.bmp
    G 2 3 J
    F 3 3 J
    V 2 3 4 W
    H 3 4 2 Z
    S two.bmp
    X


## Sample Output ##

    one.bmp
    OOOOO
    OOOOO
    OAOOO
    OOOOO
    OOOOO
    OOOOO
    two.bmp
    JJJJJ
    JJZZJ
    JWJJJ
    JWJJJ
    JJJJJ
    JJJJJ
