#ifndef TIME_INCLUDED
#define TIME_INCLUDED
#include <windows.h>

double        pcFreq;        // Counter frequency (timer resolution)
__int64       counterStart;  // Timer value
LARGE_INTEGER li;            // Large interger for timer value
double        elapsed;       // Elapsed time in seconds
int           retcode;       // Return code
float tempoLimite = 1;
#define GET_FREQ retcode = QueryPerformanceFrequency(&li) //pega frequencia do computador
#define SET_FREQ pcFreq = li.QuadPart
#define BEGIN { QueryPerformanceCounter(&li); counterStart = li.QuadPart; }
#define CLOSE { QueryPerformanceCounter(&li); elapsed = 1000.0 * ((li.QuadPart - counterStart) / pcFreq); }
#define TIME_STATUS fprintf (fpAnswer, "T-> %s\t\t", (elapsed < tempoLimite) ? "OK" : "TEMPO ESGOTADO");
// #define SHOWTIME fprintf (fpAnswer, "%6.3f milliseconds elapsed\n", elapsed);
#define SHOWTIME printf ("%6.3f milliseconds elapsed\n", elapsed);
#endif