int compare(const void* elem1, const void* elem2)
{
	int a = *((int*) elem1);
	int b = *((int*) elem2);

	if(a > b)
	{
		return 1;
	}
	else if(a < b)
	{
		return -1;
	}

	return 0;
}
