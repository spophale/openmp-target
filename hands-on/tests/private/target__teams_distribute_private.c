#include <stdio.h>
#include <omp.h>

int main()
{
  const int Nteams = 2;
  void* pointer[Nteams];
  int team_ID[Nteams];
  float a;
  #pragma omp target map(from:pointer[:Nteams], team_ID[:Nteams])
  {
    #pragma omp teams distribute num_teams(Nteams) private(a)
    for(int i = 0; i<Nteams; i++)
    {
      team_ID[i] = omp_get_team_num();
      pointer[i] = &a;
    }
  }

  printf("host pointer = %p\n", &a);
  for(int i = 0; i<Nteams; i++)
    printf("pointer[%d] = %p, team id %d\n", i, pointer[i], team_ID[i]);
  return 0;
}
