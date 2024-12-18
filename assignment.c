#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hauptprogramm
int main(int argc, char *argv[]) {
    // Prüfen, ob die richtige Anzahl von Argumenten übergeben wurde
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc -1);
        return 1; // Programm mit Fehlercode beenden
    }

    // Argumente in Ganzzahlen umwandeln
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Prüfen, ob die Eingaben gültig sind
    if (rows <= 0 || cols <= 0) {
        printf("Rows and columns must be positive integers.\n");
        return 1; // Programm mit Fehlercode beenden
    }

    // Funktion aufrufen, um die Matrix zu erstellen und zu speichern
    generateMatrixAndSaveToFile(rows, cols, "matrix.txt");

    return 0; // Erfolgreiches Beenden
}


// Funktion zur Generierung der Matrix und Speicherung in einer Datei
void generateMatrixAndSaveToFile(int rows, int cols, const char *filename) {
    // Deklaration der Matrix als Variable Length Array
    int matrix[rows][cols];

    // Zufallszahlengenerator initialisieren
    srand(time(NULL));

    // Matrix mit Zufallszahlen zwischen 1 und 100 füllen
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1; // Zufallszahl generieren
        }
    }

    // Datei zum Schreiben öffnen
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file"); // Fehlermeldung ausgeben
        exit(1); // Programm mit Fehlercode beenden
    }

    // Matrix in die Datei schreiben
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]); // Zahl schreiben
            if (j < cols - 1) {
                fprintf(file, " "); // Leerzeichen zwischen den Zahlen
            }
        }
        fprintf(file, "\n"); // Zeilenumbruch nach jeder Reihe
    }

    // Datei schließen
    fclose(file);

    // Erfolgsnachricht
    printf("Matrix successfully created and saved to %s\n (latest version Check v2.3)", filename);
}
