#pragma once

// Sets a maximum value for an integer
int Max(const int Initial, const int Max)
{
	if (Initial > Max)
	{
		return Max;
	}

	return Initial;
}

// Sets a minimum value for an integer
int Min(const int Min, const int Initial)
{
	if (Initial < Min)
	{
		return Min;
	}

	return Initial;
}