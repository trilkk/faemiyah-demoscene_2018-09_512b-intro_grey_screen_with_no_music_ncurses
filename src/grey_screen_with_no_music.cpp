#include "dnload.h"

#if defined(USE_LD)
/// Main function.
///
/// \param argc Argument count.
/// \param argv Arguments.
/// \return Program return code.
int main(int argc, char **argv)
#else
void _start()
#endif
{
  dnload();

  dnload_initscr();

  dnload_start_color();
  dnload_init_pair(1, COLOR_WHITE, COLOR_WHITE);

  for(int ii = 0; (ii < 0x2000); ++ii)
  {
    dnload_mvchgat(ii, 0, -1, 0, 1, NULL);
  }

  dnload_curs_set(0);
  dnload_refresh();
  dnload_getch();

  dnload_endwin();

#if defined(USE_LD)
  (void)argc;
  (void)argv;
  return 0;
#else
  asm_exit();
#endif
}

