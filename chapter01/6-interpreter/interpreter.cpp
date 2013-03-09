#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

int read_program(int* program);
int execute_interpreter(int* program, int program_length);

int main()
{
    int num_cases;
    cin >> num_cases;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int program[1000];

    for (int case_num = 0; case_num < num_cases; case_num++)
    {
        if (case_num > 0)
            cout << endl;

        memset(program, 0, 1000 * sizeof(int));
        int program_length = read_program(program);
        int instruction_count = execute_interpreter(program, program_length);

        cout << instruction_count << endl;
    }
}

int read_program(int* program)
{
    int program_length = 0;

    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;

        istringstream ls(line);
        ls >> program[program_length];
        program_length++;
    }

    return program_length;
}

int execute_interpreter(int* program, int program_length)
{
    int instruction_count = 0;
    int pointer = 0;

    int reg[10];
    memset(reg, 0, 10 * sizeof(int));

    while (true)
    {
        instruction_count++;

        int instruction = program[pointer];
        int command = instruction / 100;
        int d1 = (instruction / 10) % 10;
        int d2 = instruction % 10;

        pointer++;

        switch (command)
        {
            case 0:
                if (reg[d2] > 0)
                    pointer = reg[d1];
                break;

            case 1:
                return instruction_count;

            case 2:
                reg[d1] = d2;
                break;

            case 3:
                reg[d1] = (reg[d1] + d2) % 1000;
                break;

            case 4:
                reg[d1] = (reg[d1] * d2) % 1000;
                break;

            case 5:
                reg[d1] = reg[d2];
                break;

            case 6:
                reg[d1] = (reg[d1] + reg[d2]) % 1000;
                break;

            case 7:
                reg[d1] = (reg[d1] * reg[d2]) % 1000;
                break;

            case 8:
                reg[d1] = program[reg[d2]];
                break;

            case 9:
                program[reg[d2]] = reg[d1];
                break;
        }
    }

    return 0;
}
