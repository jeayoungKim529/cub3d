#include <stdio.h> 
int get_t(int trgb)
{
  return (trgb & (0xFF << 24));
}

int get_r(int trgb)
{
  return (trgb & (0xFF << 16));
}

int get_g(int trgb)
{
  return (trgb & (0xFF << 8));
}

int get_b(int trgb)
{
  return (trgb & 0xFF);
}
int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int main()
{
	printf("color get_r: %x\n", get_r(0xFFFF00));
	printf("color get_g: %x\n", get_g(0xFFFF00));
	printf("color get_b: %x\n", get_b(0xFFFF00));
	printf("color get_r: %x\n", create_trgb(100, 220, 100, 0));
	printf("color get_r: %x\n", create_trgb(0, 225, 30, 0));
	// #dc6400 floor
	//#e11e00 ceiling

}