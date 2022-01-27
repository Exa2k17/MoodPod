//declaring method for gathering random question category
byte getQuestionCategory()
{
  byte cat;
  cat = random(0, 6);

  return cat;
}

//declaring method for incrementing cloud variables after voting
void incrementCategoryVotes() {
  float total;
  //setting cloud variables for the categories of votes
  if (vote == 1) {
    switch (category) {
      case 0 :
        workloadP++;
        total = workloadN + workloadP;
        workloadLevel = workloadN / total * 100;
        break;
      case 1 :
        clarityP++;
        total = clarityN + clarityP;
        clarityLevel = clarityN / total * 100;
        break;
      case 2 :
        responsibilityP++;
        total = responsibilityN + responsibilityP;
        responsibilityLevel = responsibilityN / total * 100;
        break;
      case 3 :
        mentalityP++;
        total = mentalityN + mentalityP;
        mentalityLevel = mentalityN / total * 100;
        break;
      case 4 :
        privateP++;
        total = privateN + privateP;
        privateLevel = privateN / total * 100;
        break;
      case 5 :
        healthP++;
        total = healthN + healthP;
        healthLevel = healthN / total * 100;
        break;
    }
  }  
  else if (vote == 2) {
    switch (category) {
      case 0 :
        workloadN++;
        total = workloadN + workloadP;
        workloadLevel = workloadN / total * 100;
        break;
      case 1 :
        clarityN++;
        total = clarityN + clarityP;
        clarityLevel = clarityN / total * 100;
        break;
      case 2 :
        responsibilityN++;
        total = responsibilityN + responsibilityP;
        responsibilityLevel = responsibilityN / total * 100;
        break;
      case 3 :
        mentalityN++;
        total = mentalityN + mentalityP;
        mentalityLevel = mentalityN / total * 100;
        break;
      case 4 :
        privateN++;
        total = privateN + privateP;
        privateLevel = privateN / total * 100;
        break;
      case 5 :
        healthN++;
        total = healthN + healthP;
        healthLevel = healthN / total * 100;
        break;
    }
  }
}

