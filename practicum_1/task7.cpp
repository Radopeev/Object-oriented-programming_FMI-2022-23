#include<iostream>
using namespace std;
const int MAX_LENGTH = 31;
enum class Genres {
    Comedy, 
    Action, 
    Horror, 
    Romantic
};
struct Movies {
    char name[MAX_LENGTH];
    Genres genre;
    int runtime;
    int rating;
};
void createMovie(Movies& movie, char(&name)[MAX_LENGTH],int& genre,int& runtime,int& rating) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (name[i] == '\0') {
            movie.name[i] = name[i];
            break;
        }
        movie.name[i] = name[i];
    }
    switch (genre) {
        case 1:movie.genre = Genres::Comedy; break;
        case 2:movie.genre = Genres::Action; break;
        case 3:movie.genre = Genres::Horror; break;
        case 4:movie.genre = Genres::Romantic; break;
    }
    movie.runtime = runtime;
    movie.rating = rating;
}
void createArrayOfMovies(Movies(&movieArr)[3]) {
    char name[MAX_LENGTH];
    int genre,runtime,rating;
    for (int i = 0; i < 3; i++) {
        cout << "Enter Movie title:";
        cin.getline(name, MAX_LENGTH);
        cout << "Enter genre 1)Comedy,2)Action,3)Horror,4)Romantic : ";
        cin >> genre;
        cout << "Enter runtime:";
        cin >> runtime;
        cout << "Enter rating:";
        cin >> rating;
        createMovie(movieArr[i], name, genre, runtime, rating);
        cout << endl;
        cin.ignore();
    }
}
void printMovies(Movies(&movieArr)[3]) {
    for (int i = 0; i < 3; i++) {
        cout << " Name: " << movieArr[i].name << endl;
        switch (movieArr[i].genre) {
            case Genres::Comedy: cout<<"Comedy";
            case Genres::Action: cout << "Action"; 
            case Genres::Horror: cout << "Horror";
            case Genres::Romantic: cout << "Romantic";
        }
        cout << " Runtime: " << movieArr[i].runtime << endl;
        cout << " Rating: " << movieArr[i].rating << endl;
        cout << endl;
    }
}
void printHighestRatedMovies(Movies(&movieArr)[3]) {
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (movieArr[i].rating > max) {
            max = movieArr[i].rating;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (movieArr[i].rating == max) {
            cout << " Name: " << movieArr[i].name << endl;
            switch (movieArr[i].genre) {
            case Genres::Comedy: cout << "Comedy";
            case Genres::Action: cout << "Action";
            case Genres::Horror: cout << "Horror";
            case Genres::Romantic: cout << "Romantic";
            }
            cout << " Runtime: " << movieArr[i].runtime << endl;
            cout << " Rating: " << movieArr[i].rating << endl;
        }
    }
}
void swap(Movies& a, Movies& b) {
    Movies temp = a;
    a = b;
    b = temp;
}
void sortingArray(Movies(&movieArr)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (movieArr[i].rating < movieArr[j].rating) {
                swap(movieArr[i], movieArr[j]);
            }
        }
    }
}
int main() {
    Movies movie,arrOfMovies[3];
    char name[MAX_LENGTH];
    int runtime, rating,genre;
    cout << "Enter Movie title:";
    cin.getline(name, 30);
    cout << "Enter genre 1)Comedy,2)Action,3)Horror,4)Romantic : ";
    cin >> genre;
    cout << "Enter runtime:";
    cin >> runtime;
    cout << "Enter rating:";
    cin >> rating;
    createMovie(movie, name, genre, runtime, rating);
    cout << endl;
    cin.ignore();
    createArrayOfMovies(arrOfMovies);
    printMovies(arrOfMovies);
    cout << "---------------------" << endl;
    printHighestRatedMovies(arrOfMovies);
    cout << "---------------------" << endl;
    sortingArray(arrOfMovies);
    printMovies(arrOfMovies);
}