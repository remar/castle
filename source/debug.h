#ifndef DEBUG_H
#define DEBUG_H

#define TRY(x) {if(RAGE_FAILED(x)) display_error(__FILE__, __LINE__);}
void display_error(const char *file, int line);

#endif
