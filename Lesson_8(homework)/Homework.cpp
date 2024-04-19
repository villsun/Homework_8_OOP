#include <iostream>

using namespace std;

class Light_Figure
{
public:
	virtual void Draw()
	{
		cout << "Nothing\n";
	}
};

class Square : public Light_Figure
{
private:
	int user_input;
public:
	Square(int user_input = 0)
	{
		this->user_input = user_input;
	}

	virtual void Draw() override
	{
		if (user_input <= 0)
		{
			cout << "ERROR!\n";
			return;
		}
		for (int i = 0; i < user_input; i++)
		{
			for (int j = 0; j < user_input; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
};

class Rectangle : public Light_Figure
{
private:
	int user_input_1;
	int user_input_2;
public:
	Rectangle(int user_input_1 = 0, int user_input_2 = 0)
	{
		this->user_input_1 = user_input_1;
		this->user_input_2 = user_input_2;
	}

	virtual void Draw() override
	{
		if (user_input_1 <= 0 || user_input_2 <= 0)
		{
			cout << "ERROR!\n";
			return;
		}
		for (int i = 0; i < user_input_1; i++)
		{
			for (int j = 0; j < user_input_2; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
};

class Wrong_Figure : public Light_Figure
{
private:
	int user_input_1;
	int user_input_2;
public:
	Wrong_Figure(int user_input_1 = 0, int user_input_2 = 0)
	{
		this->user_input_1 = user_input_1;
		this->user_input_2 = user_input_2;
	}
	virtual void Draw() override
	{
		if (user_input_1 <= 0 || user_input_2 <= 0)
		{
			cout << "ERROR!\n";
			return;
		}
		int number_spaces = 3;
		for (int i = 0; i < user_input_1; i++)
		{
			for (int k = number_spaces; k > 0; k--)
			{
				cout << " ";
			}
			for (int j = 0; j < user_input_2; j++)
			{
				cout << "*";
			}
			cout << endl;
			number_spaces--;
		}

	}
};

int main()
{
	Square square_1(5);
	Light_Figure& light_figure_1 = square_1;
	light_figure_1.Draw();

	Rectangle rectangle_1(5, 2);
	Light_Figure& light_figure_2 = rectangle_1;
	light_figure_2.Draw();

	Wrong_Figure wrong_figure_1(3, 5);
	Light_Figure& light_figure_3 = wrong_figure_1;
	light_figure_3.Draw();

	return 0;
}