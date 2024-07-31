#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user_t {
  double lat;
  double lon;
  double alt;
  double time;
  char name[50];
};

struct distfromuser {
  double dist;
  char other[50];
};

int get_arraysize(FILE *file) {
  char line[256];
  fgets(line, sizeof(line), file);
  int firstline = atoi(line); // Storing the first line
  return firstline;
}
void scan_user(struct user_t *our_user, struct user_t *other_users, int size,
               FILE *file) {
  char uname[50];
  double ulat;
  double ulon;
  double ualt;
  double utime;

  // Taking the user's input for our_user
  printf("Name:");
  scanf("%[^\n]%*c", uname);
  printf("Latitude:");
  scanf("%lf", &ulat);
  printf("Longitude:");
  scanf("%lf", &ulon);
  printf("Altitude:");
  scanf("%lf", &ualt);
  printf("Time:");
  scanf("%lf", &utime);

  // Storing the input
  strcpy(our_user->name, uname);
  our_user->lat = ulat;
  our_user->lon = ulon;
  our_user->alt = ualt;
  our_user->time = utime;

  printf("----------------------------\n");

  // For other_users
  for (int i = 0; i < size; i++) {
    char line[256]; // read a line from a file
    fgets(line, sizeof(line), file);
    other_users[i].lat = atof(line);
    fgets(line, sizeof(line), file);
    other_users[i].lon = atof(line);
    fgets(line, sizeof(line), file);
    other_users[i].alt = atof(line);
    fgets(line, sizeof(line), file);
    other_users[i].time = atof(line);
    fgets(line, sizeof(line), file);
    int length = strlen(line); // checking in case last character is a newline
    if (line[length - 1] == '\n') {
      line[length - 1] = '\0';
    }
    strcpy(other_users[i].name, line);
  }
}

void distance(struct user_t *our_user, struct user_t *other_user,
              struct distfromuser *dist, int size) {
  double lat1 = our_user->lat; // our user position values
  double lon1 = our_user->lon;
  double alt1 = our_user->alt;

  for (int i = 0; i < size; i++) {
    double lat2 = other_user[i].lat; // other user position values
    double lon2 = other_user[i].lon;
    double alt2 = other_user[i].alt;

    // applying the distance formula
    double lat = pow(lat1 - lat2, 2);
    double lon = pow(lon1 - lon2, 2);
    double alt = pow(alt1 - alt2, 2);
    double distance = sqrt(lat + lon + alt);
    //Stores the distance and the name of the other user
    dist[i].dist = distance;
    strcpy(dist[i].other, other_user[i].name);
  }
}

struct user_t closest(struct distfromuser *dist, int size,
                      struct user_t *details) {
  struct distfromuser closestuser;
  struct user_t closestuserdetails;
  closestuser.dist = dist[0].dist;
  int user_number = 0;
  // Finding the closest
  for (int i = 0; i < size; i++) {
    if (dist[i].dist < closestuser.dist) {
      closestuser.dist = dist[i].dist;
      user_number = i;
    }
  }

  // Storing the details of the closest user
  strcpy(closestuserdetails.name, details[user_number].name);
  closestuserdetails.lat = details[user_number].lat;
  closestuserdetails.lon = details[user_number].lon;
  closestuserdetails.alt = details[user_number].alt;
  closestuserdetails.time = details[user_number].time;
  return closestuserdetails;
}

int main(int argc, char *argv[]) {
  // Checking for argument
  if (argc != 2) {
    printf("Usage: ./main <file>\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

  // Checking if file exists
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  struct user_t our_user;
  int size = get_arraysize(fp); // Getting the amount of other_users
  struct user_t other_users[size];

  scan_user(&our_user, other_users, size, fp);
  printf("\n");
  printf("Reference User:\nUser %s:\n", our_user.name);
  printf("Latitude: %.2lf\nLongitude: %.2lf\nAltitude: %.2lf\n", our_user.lat,
         our_user.lon, our_user.alt);

  printf("\nList of other users:\n");
  for (int i = 0; i < size; i++) {
    printf("User %s:\n", other_users[i].name);
    printf("Latitude: %.2lf\nLongitude: %.2lf\nAltitude: %.2lf\n",
           other_users[i].lat, other_users[i].lon, other_users[i].alt);
  }
  printf("\n");

  // Obtaining the distances
  struct distfromuser dist[size];
  distance(&our_user, other_users, dist, size);
  //Print each user's distance from us
  printf("Actual distances from our user were:\n");
  for (int i = 0; i < size; i++) {
    printf("User number: %i at distance %lf named %s\n", i, dist[i].dist,
           dist[i].other);
  }
  printf("\n");

  // Finding the closest
  struct user_t closestuser = closest(dist, size, other_users);
  printf("Nearest user to reference user:\n");
  printf("User %s:\n", closestuser.name);
  printf("Latitude %.2lf\n", closestuser.lat);
  printf("Longitude %.2lf\n", closestuser.lon);
  printf("Altitude %.2lf\n", closestuser.alt);

  // Closing the file
  fclose(fp);
  return 0;
}