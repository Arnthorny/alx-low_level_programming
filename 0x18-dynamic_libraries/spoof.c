int rand(void)
{
	static int count = -1;
	int arr[6] = {8,8,7,9,23,74};

	count++;

	return (arr[count % 6]);
}
