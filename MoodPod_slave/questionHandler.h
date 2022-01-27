#include "data.h"

//declaring method for queriing new question form the dataset
String getQuestion(int category)
{
  String answer = "";
  switch (category) {
    case 0 :
      answer = workloadQ[random(0, workloadCount - 1)];
      break;
    case 1 :
      answer = clarityQ[random(0, clarityCount - 1)];
      break;
    case 2 :
      answer = responisibilityQ[random(0, responisbilityCount - 1)];
      break;
    case 3 :
      answer = mentalityQ[random(0, mentalityCount - 1)];
      break;
    case 4 :
      answer = privateQ[random(0, privateCount - 1)];
      break;
    case 5 :
      answer = healthQ[random(0, healthCount - 1)];
      break;
  }

  return answer;
}