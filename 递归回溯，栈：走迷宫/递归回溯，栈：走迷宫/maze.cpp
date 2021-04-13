#include <iostream>
#include <windows.h>
using namespace std;

short map[6][5] = {
	{-1	,-1	,-1	,-1	,-1	},
	{0	,0	,-1	,0	,-1	},
	{-1	,0	,-1	,0	,-1	},
	{-1	,0	,0	,0	,-1	},
	{-1	,0	,-1	,0	,0	},
	{-1	,-1	,-1	,-1	,-1	}
};
//0:road,-1:wall,2:way,1:bad road

void GotoXy(int x, int y)
{
	HANDLE hout;COORD coord;
	coord.X = x;coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);

	CONSOLE_CURSOR_INFO cursor_info = {1};
	SetConsoleCursorInfo(hout, &cursor_info);

}

void print()
{
	GotoXy(0, 0);
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			switch (map[i][j])
			{
				//0:road,-1:wall,2:way,1:bad road
			case 0:	cout << "  "; break;
			case -1:cout << "¡ù"; break;
			case 1:	cout << "¡î"; break;
			case 2:	cout << "¡ï"; break;
			default: break;
			};
		}
		cout << "\n";
	}
	//cout << "\n\n\n\n";
}


int next(short cur_x, short cur_y, short exit_x, short exit_y)
{
	print(); Sleep(500);

	if (cur_x == exit_x && cur_y == exit_y)
	{
		map[cur_x][cur_y] = 2;
		return 1;
	}

	else
	{

		map[cur_x][cur_y] = 2;
		//suppose that current point is a part of way
		//2:way,0:point that had never been tried yet

		if (map[cur_x - 1][cur_y] == 0)//north
		{
			short x = cur_x, y = cur_y;
			if (next(x - 1, y, exit_x, exit_y))return 1;
		}

		if (map[cur_x + 1][cur_y] == 0)//south
		{
			short x = cur_x, y = cur_y;
			if (next(x + 1, y, exit_x, exit_y))return 1;
		}

		if (map[cur_x][cur_y + 1] == 0)//east
		{
			short x = cur_x, y = cur_y;
			if (next(x, y + 1, exit_x, exit_y))return 1;
		}

		if (map[cur_x][cur_y - 1] == 0)//west
		{
			short x = cur_x, y = cur_y;
			if (next(x, y - 1, exit_x, exit_y))return 1;
		}

		map[cur_x][cur_y] = 1;
		//if all four sides are not qualified, set this point to bad road

		return 0;/*
		If all four sides are not qualified,
		we won't go further along the current way,
		Instead, we turn to other directions.
		*/
	}
}





int main()
{
	
	next(1, 0, 4, 4);
	print();
	return 0;

}