#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

class Intelligence
{
protected:

  explicit Intelligence();
  short rate;
  virtual void getRate()const;
  virtual void upgradeRate();
  virtual void downgradeRate();

};


#endif // INTELLIGENCE_H
