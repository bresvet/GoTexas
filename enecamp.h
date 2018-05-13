#ifndef ENECAMP_H
#define ENECAMP_H
#include <vector>
#include <memory>
#include "coopene.h"

class Enecamp
{
public:
  explicit Enecamp();
  unsigned short competitorsQuantity;
  unsigned short botEnemiesQuantity;
  std::vector<std::shared_ptr<Coopene>>coopenes;
  void retrieveData()const;
  void updateData()const;
};

#endif // ENECAMP_H
