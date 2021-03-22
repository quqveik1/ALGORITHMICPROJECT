#define VerifyPtr(adress)								         \
{														         \
	if (!checkPtr ((const int *) adress))			             \
	{													         \ 
		printf (" (Invalid adress {%s} = %p)", #adress, adress); \
	}													         \													        
}														   		 \

int main ()
{
	int i = 0;
	VerifyPtr (&i);
}