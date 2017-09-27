#include <stdio.h>

  struct student{
    char name[20];
    int eng;
    int math;
    int phys;
    double mean;
};

static struct student data[]={
  {"Tuan", 82, 72, 58, 0.0},
  {"Nam", 77, 82, 79, 0.0},
  {"Khanh", 52, 62, 39, 0.0},
  {"Phuong", 61, 82, 88, 0.0}
};

typedef struct student Student;

float getMean(Student data){
  return (float)(data.eng + data.math + data.phys)/3;
}

char* getGrade(Student data){
  if(data.mean >= 90 && data.mean <=100)
    return "S";
  if(data.mean >= 80 && data.mean <=90)
    return "A";
  if(data.mean >= 70 && data.mean <=80)
    return "B";
  if(data.mean >= 60 && data.mean <=70)
    return "C";
  if(data.mean < 60)
    return "D";
}

void setMeanArr(){
  int i;
  for(i = 0; i < 4; i++){
    data[i].mean = getMean(data[i]);
  }
}

int main(){
  setMeanArr(data, 4);
  printf("%-15s%-10s%-10s%-10s%-10s%-10s\n",
    "Name", "English", "Math", "Physical", "Mean", "Grade");
  int i;
  for(i = 0; i < 4; i++){
    printf("%-15s%-10d%-10d%-10d%-10.2f",
      data[i].name, data[i].eng, data[i].math, data[i].phys, data[i].mean);
    printf("%-10s\n", getGrade(data[i]));
  }
  return 0;
}
