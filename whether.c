#include <stdio.h>
#include <string.h>

struct weather {
    char city[100];
    int temperature;
    int humidity;
};
typede#f struct weather w;

void readWeatherData(w records[], int n);
void displayWeatherData(w records[], int n);
void searchWeather(w records[], int n, char searchCity[]);
void saveToFile(w records[], int n);

int main() {
    int num;
    printf("Enter number of cities: ");
    scanf("%d", &num);

    w records[1000];

    readWeatherData(records, num);
    displayWeatherData(records, num);
    saveToFile(records, num);

    char searchCity[100];
    printf("\nEnter city name to search: ");
    scanf("%s", searchCity);
    searchWeather(records, num, searchCity);

    return 0;
}

void readWeatherData(w records[], int n) {
    printf("Enter weather details (City, Temperature(°C), Humidity(%%)):\n");
    for (int i = 0; i < n; i++) {
        printf("City %d: ", i + 1);
        scanf("%s %d %d", records[i].city, &records[i].temperature, &records[i].humidity);
    }
}

void displayWeatherData(w records[], int n) {
    printf("\nWeather Records:\n");
    for (int i = 0; i < n; i++) {
        printf("City: %s, Temperature: %d°C, Humidity: %d%%\n",
               records[i].city, records[i].temperature, records[i].humidity);
    }
}

void searchWeather(w records[], int n, char searchCity[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].city, searchCity) == 0) {
            printf("Weather in %s: %d°C, %d%% Humidity\n",
                   records[i].city, records[i].temperature, records[i].humidity);
            return;
        }
    }
    printf("City %s not found.\n", searchCity);
}

void saveToFile(w records[], int n) {
    FILE *file = fopen("weather_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s, %d°C, %d%%\n",
                records[i].city, records[i].temperature, records[i].humidity);
    }
    fclose(file);
    printf("Data saved in \"weather_data.txt\"\n");
}
