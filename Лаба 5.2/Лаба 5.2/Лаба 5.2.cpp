#include <iostream>
#include <string>
#include <fstream>




int s4et(std::string slovo)
{
	int count = 1;
	int maxi = INT_MIN;

	for (int i = 0; i < slovo.length(); i++)
	{
		for (int j = i + 1; j < slovo.length(); j++)
		{
			if (slovo[i] == slovo[j])
			{
				count++;
			}
		}

		if (count > maxi)
		{
			maxi = count;
		}
		count = 1;
	}
	return maxi;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100];
	int maxi = INT_MIN;
	int N, counter[20], cnt = 0;
	int j = 0;
	std::ifstream F("Test.txt", std::ios::in);
	F >> N;
	F.getline(str, 100);
	std::cout << "N = " << N << std::endl;

	std::string slova[100];
	std::string slovo;
	for (int i = 0; i <= strlen(str); i++) 
	{
		if ((str[i] != ' ') && (str[i] != '\0'))
		{
			slovo += str[i];
		}
		else
		{
			counter[j] = s4et(slovo);
			slova[j] = slovo;
			slovo = "";
			j++;
			
		}
	}
	for (int i = 0; i < j; i++)
	{
		for (int m = i + 1;m <j;m++)
		{
			if (slova[i] == slova[m])
			{
				slova[i] = '\0';
				counter[i] = 0;
				i++;
			}
		}
		std::cout << slova[i] << " — " << counter[i] << ". ";
	}
	int tmpc;
	std::string tmps;
	for (int i = 0; i < j - 1; i++)
	{
		for (int k = 0; k < j - i - 1; k++)
		{
			if (counter[k] < counter[k + 1])
			{
				tmpc = counter[k];
				tmps = slova[k];
				counter[k] = counter[k + 1];
				slova[k] = slova[k + 1];
				counter[k + 1] = tmpc;
				slova[k + 1] = tmps;
			}
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << slova[i] << " — " << counter[i] << ". ";
	}



}