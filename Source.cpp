#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);


int string_to_int(string price)			// function to convert string to integer
{
    int new_price = 0, c = 1;

    for (int i = price.size() - 1; i >= 0; i--)
    {
        new_price += c * (price[i] - '0');

        c *= 10;
    }

    return new_price;
}
//******************************	Start of Book struct	*************************
const int arrsize = 10000;		// max size to the books 
int fantasy_num, mystery_num, romance_num, non_fiction_num, science_fiction_num; // number of books in each array (section)

struct book
{
    string title;
    string author;
    string description;
    string type;
    string status;
    string price;
    string numofpages;
    string review;
    string countity;

} fantasy[arrsize], mystery[arrsize], romance[arrsize], non_fiction[arrsize], science_fiction[arrsize];

struct person
{
    string usertype;
    string username;
    string password;
};
int users = 0;
person information[arrsize];

vector <pair<int, int>>cart_vector;

//******************************	End of Book struct	*************************
//******************************	Start of transitions	*************************
void file_to_fantasy()
//converting file to the fantasy struct
{
    string line;
    int index;
    ifstream file("fantasy.txt");

    if (file.is_open()) {
        for (int i = 0; i < fantasy_num; i++) {
            index = 0;
            while (getline(file, line))
            {
                if (index == 0)    fantasy[i].title = line;
                else if (index == 1)    fantasy[i].author = line;
                else if (index == 2)    fantasy[i].description = line;
                else if (index == 3)    fantasy[i].type = line;
                else if (index == 4)    fantasy[i].status = line;
                else if (index == 5)    fantasy[i].price = line;
                else if (index == 6)    fantasy[i].numofpages = line;
                else if (index == 7)    fantasy[i].review = line;
                else if (index == 8)     fantasy[i].countity = line;
                index++;
                if (line == "##") { break; }
                if (index == 9)		break;
            }
        }
    }
    file.close();
}
void file_to_mystery()
//converting file to the mystery struct
{
    string line;
    int index;
    ifstream file("mystery.txt");

    if (file.is_open()) {
        for (int i = 0; i < mystery_num; i++) {
            index = 0;
            while (getline(file, line))
            {
                if (index == 0)    mystery[i].title = line;
                else if (index == 1)    mystery[i].author = line;
                else if (index == 2)    mystery[i].description = line;
                else if (index == 3)    mystery[i].type = line;
                else if (index == 4)    mystery[i].status = line;
                else if (index == 5)    mystery[i].price = line;
                else if (index == 6)    mystery[i].numofpages = line;
                else if (index == 7)    mystery[i].review = line;
                else if (index == 8)    mystery[i].countity = line;
                index++;
                if (line == "##") { break; }
                if (index == 9)	break;
            }
        }
    }

    file.close();
}
void file_to_romance()
//converting file to the romance struct
{
    string line;
    int index;
    ifstream file("romance.txt");

    if (file.is_open()) {
        for (int i = 0; i < romance_num; i++) {
            index = 0;
            while (getline(file, line))
            {
                if (index == 0)    romance[i].title = line;
                else if (index == 1)    romance[i].author = line;
                else if (index == 2)    romance[i].description = line;
                else if (index == 3)    romance[i].type = line;
                else if (index == 4)    romance[i].status = line;
                else if (index == 5)    romance[i].price = line;
                else if (index == 6)    romance[i].numofpages = line;
                else if (index == 7)    romance[i].review = line;
                else if (index == 8)    romance[i].countity = line;
                index++;
                if (line == "##") { break; }
                if (index == 9)	break;
            }
        }
    }

    file.close();
}
void file_to_non_fiction()
//converting file to the non fiction struct
{
    string line;
    int index;
    ifstream file("nonfiction.txt");

    if (file.is_open()) {
        for (int i = 0; i < non_fiction_num; i++) {
            index = 0;
            while (getline(file, line))
            {
                if (index == 0)    non_fiction[i].title = line;
                else if (index == 1)    non_fiction[i].author = line;
                else if (index == 2)    non_fiction[i].description = line;
                else if (index == 3)    non_fiction[i].type = line;
                else if (index == 4)    non_fiction[i].status = line;
                else if (index == 5)    non_fiction[i].price = line;
                else if (index == 6)    non_fiction[i].numofpages = line;
                else if (index == 7)    non_fiction[i].review = line;
                else if (index == 8)    non_fiction[i].countity = line;
                index++;
                if (line == "##") {
                    break;
                }
                if (index == 9)	break;
            }
        }
    }
    file.close();
}
void file_to_science_fiction()
//converting file to the science fiction struct
{
    string line;
    int index;
    ifstream file("science_fiction.txt");

    if (file.is_open()) {
        for (int i = 0; i < science_fiction_num; i++) {
            index = 0;
            while (getline(file, line))
            {
                if (index == 0)    science_fiction[i].title = line;
                else if (index == 1)    science_fiction[i].author = line;
                else if (index == 2)    science_fiction[i].description = line;
                else if (index == 3)    science_fiction[i].type = line;
                else if (index == 4)    science_fiction[i].status = line;
                else if (index == 5)    science_fiction[i].price = line;
                else if (index == 6)    science_fiction[i].numofpages = line;
                else if (index == 7)    science_fiction[i].review = line;
                else if (index == 8)     science_fiction[i].countity = line;
                index++;
                if (line == "##") { break; }
                if (index == 9)	break;
            }
        }
    }

    file.close();
}
void struct_to_fantasy()
{
    ofstream file;
    file.open("fantasy.txt");

    for (int i = 0; i < fantasy_num; i++)
    {
        file << fantasy[i].title << endl;
        file << fantasy[i].author << endl;
        file << fantasy[i].description << endl;
        file << fantasy[i].type << endl;
        file << fantasy[i].status << endl;
        file << fantasy[i].price << endl;
        file << fantasy[i].numofpages << endl;
        file << fantasy[i].review << endl;
        file << fantasy[i].countity << endl;
    }
    file << "##";
    file.close();
}
void struct_to_mystery()
{
    ofstream file;
    file.open("mystery.txt");

    for (int i = 0; i < mystery_num; i++)
    {
        file << mystery[i].title << endl;
        file << mystery[i].author << endl;
        file << mystery[i].description << endl;
        file << mystery[i].type << endl;
        file << mystery[i].status << endl;
        file << mystery[i].price << endl;
        file << mystery[i].numofpages << endl;
        file << mystery[i].review << endl;
        file << mystery[i].countity << endl;
    }
    file << "##";
    file.close();
}
void struct_to_romantic()
{
    ofstream file;
    file.open("romance.txt");

    for (int i = 0; i < romance_num; i++)
    {
        file << romance[i].title << endl;
        file << romance[i].author << endl;
        file << romance[i].description << endl;
        file << romance[i].type << endl;
        file << romance[i].status << endl;
        file << romance[i].price << endl;
        file << romance[i].numofpages << endl;
        file << romance[i].review << endl;
        file << romance[i].countity << endl;
    }
    file << "##";
    file.close();
}
void struct_to_non_fiction()
{
    ofstream file;
    file.open("non_fiction.txt");

    for (int i = 0; i < non_fiction_num; i++)
    {
        file << non_fiction[i].title << endl;
        file << non_fiction[i].author << endl;
        file << non_fiction[i].description << endl;
        file << non_fiction[i].type << endl;
        file << non_fiction[i].status << endl;
        file << non_fiction[i].price << endl;
        file << non_fiction[i].numofpages << endl;
        file << non_fiction[i].review << endl;
        file << non_fiction[i].countity << endl;
    }
    file << "##";
    file.close();
}
void struct_to_scientific_fiction()
{
    ofstream file;
    file.open("science_fiction.txt");

    for (int i = 0; i < science_fiction_num; i++)
    {
        file << science_fiction[i].title << endl;
        file << science_fiction[i].author << endl;
        file << science_fiction[i].description << endl;
        file << science_fiction[i].type << endl;
        file << science_fiction[i].status << endl;
        file << science_fiction[i].price << endl;
        file << science_fiction[i].numofpages << endl;
        file << science_fiction[i].review << endl;
        file << science_fiction[i].countity << endl;
    }
    file << "##";
    file.close();
}
void files_to_struct() {
    file_to_fantasy();
    file_to_mystery();
    file_to_romance();
    file_to_non_fiction();
    file_to_science_fiction();
}
void structs_to_files()
{
    struct_to_fantasy();
    struct_to_mystery();
    struct_to_romantic();
    struct_to_non_fiction();
    struct_to_scientific_fiction();
}
void file_to_counter()
{
    ifstream file("bookssize.txt");
    int i = 0;
    string line;
    while (getline(file, line))
    {
        if (i == 0) { fantasy_num = string_to_int(line); }
        else if (i == 1) { mystery_num = string_to_int(line); }
        else if (i == 2) { romance_num = string_to_int(line); }
        else if (i == 3) { non_fiction_num = string_to_int(line); }
        else if (i == 4) { science_fiction_num = string_to_int(line); }
        i++;
    }

    file.close();
}
void counetr_to_file()
{
    ofstream file("bookssize.txt");
    file << fantasy_num << endl << mystery_num << endl << romance_num << endl;
    file << non_fiction_num << endl << science_fiction_num << endl;
    file.close();
}
void file_to_information()
{
    string userType, user_name, password_;
    ifstream read("ourfile.txt");
    while (getline(read, userType))
    {
        getline(read, user_name);
        getline(read, password_);
        information[users].usertype = userType;
        information[users].username = user_name;
        information[users].password = password_;
        users++;
    }
}
void information_to_file()
{
    ofstream read("ourfile.txt");
    for (int i = 0; i < users; i++)
        read << information[i].usertype << endl << information[i].username << endl << information[i].password << endl;
}
//******************************	 End of transitions		*************************

Font italiana, AbrilFatface_Regular;
Texture homeIcon_texture, cartIcon_texture, fantacy_texture, mystery_texture, romance_texture, scienceFiction_texture, nonFiction_texture , f1t;

/////////     SFML code ////////////
struct STARTING_PAGE {
    Text sign_up, log_in, library_name;
    RectangleShape sign_up_button, log_in_button;
    bool visible = true;
};
struct  SIGN_UP {
    Text sign_up_label, sign_up_username, sign_up_password, reader, administrator, sign_up_submit ,wrongans;
    RectangleShape sign_up_submit_button, sign_up_input_username, sign_up_input_password;
    CircleShape reader_check, administrator_check;
    String userInput, passInput;
    string userInput_, passInput_, message ;
    Text userText, passText;
    int focusedTextField = 0;
    bool visible = false , isAdmin , used ;
};
struct  LOG_IN {
    Text login_label, login_username, login_password, login_submit;
    RectangleShape login_submit_button, login_input_username, login_input_password;
    String userInput, passInput;
    string message ;
    Text userText, passText;
    int focusedTextField = 0;
    bool visible = false, found = true;
};
struct HOME
{
    Text fantacy_label, mystery_label, romance_label, scienceFiction_label, nonFiction_label;
    Sprite fantacy_sprite, mystery_sprite, romance_sprite, scienceFiction_sprite, nonFiction_sprite;
    bool visible = false;
};
struct MENU
{
    Sprite homeIcon_sprite, cartIcon_sprite;
    Text logOut;
    bool visible = false;
};
struct DISPLAYBOOK
{
    Text title_, author_, description_, type_, status_, price_, numofpages_, review_;
    Sprite cover;
    bool visible = false;
};
struct DROPDOWNBOX
{
    RectangleShape box , shade;
    Text boxLabel;
    vector<Text>books;
    bool visible = false;
};

void texturesANDfonts();
void set_starting_page(STARTING_PAGE&);
void draw_starting_page(STARTING_PAGE);
void set_sign_up(SIGN_UP&);
void draw_sign_up(SIGN_UP);
void set_login(LOG_IN&);
void draw_login(LOG_IN);
void set_home(HOME&);
void draw_home(HOME);
void set_menu(MENU&);
void draw_menu(MENU);
void set_displaybook(DISPLAYBOOK&);
void draw_displaybook(DISPLAYBOOK);
void set_dropdownbox(DROPDOWNBOX&);
void draw_dropdownbox(DROPDOWNBOX);

int main() {
    file_to_counter();
    files_to_struct();
    STARTING_PAGE starting_page;
    SIGN_UP sign_up_page;
    LOG_IN login_page;
    HOME home;
    MENU menu;
    DISPLAYBOOK displaybook;
    DROPDOWNBOX dropdownbox;

    bool check_user = false;
    Clock clock;
    Time timeLimit = seconds(10.0f); // 10 seconds

    texturesANDfonts();
    set_starting_page(starting_page);
    set_sign_up(sign_up_page);
    set_login(login_page);
    set_home(home);
    set_menu(menu);
    set_displaybook(displaybook);
    set_dropdownbox(dropdownbox);

    //////////// background ///////////// 
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");
    Sprite background(backgroundTexture);
    background.setScale(1.5, 1.5);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
            case Event::Closed:
                window.close();        break;

            case Event::TextEntered:        // Handle text input
                if (event.text.unicode >= 32 && event.text.unicode <= 126) {

                    if (sign_up_page.focusedTextField == 0) {
                        sign_up_page.userText.setString(sign_up_page.userText.getString() + static_cast<char>(event.text.unicode));
                    }
                    else if (sign_up_page.focusedTextField == 1) {
                        sign_up_page.passText.setString(sign_up_page.passText.getString() + static_cast<char>(event.text.unicode));
                    }
                    if (login_page.focusedTextField == 0) {
                        login_page.userText.setString(login_page.userText.getString() + static_cast<char>(event.text.unicode));
                    }
                    else if (login_page.focusedTextField == 1) {
                        login_page.passText.setString(login_page.passText.getString() + static_cast<char>(event.text.unicode));
                    }
                }        break;

            case Event::KeyPressed:        // Handle key presses
                if (event.key.code == Keyboard::Enter)
                {
                    sign_up_page.focusedTextField++;             // Move focus to the next text field
                    if (sign_up_page.focusedTextField >= 2) {
                        sign_up_page.focusedTextField = 0;
                    }
                    login_page.focusedTextField++;             // Move focus to the next text field
                    if (login_page.focusedTextField >= 2) {
                        login_page.focusedTextField = 0;
                    }
                }            break;
            case Event::MouseButtonPressed:      // Handle mouse button presses
                if (event.mouseButton.button == Mouse::Left) {        // Check if button was clicked
                    FloatRect signup_button = starting_page.sign_up_button.getGlobalBounds();
                    Vector2f StartingmousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (signup_button.contains(StartingmousePosition)) {     
                        // The button was clicked!
                        // Hide the starting_page and draw the sign_up_page
                        starting_page.visible = false;
                        sign_up_page.visible = true;
                    }    
                    
                    FloatRect login_button = starting_page.log_in_button.getGlobalBounds();
                    Vector2f StartingmousePosition2 = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (login_button.contains(StartingmousePosition2)) {
                        // The button was clicked!
                        // Hide the starting_page and draw the login_page
                        starting_page.visible = false;
                        login_page.visible = true;
                    }
                   
                    FloatRect AdminCheck = sign_up_page.administrator_check.getGlobalBounds();
                    Vector2f adminCheckmousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (AdminCheck.contains(adminCheckmousePosition)) {
                        sign_up_page.isAdmin = true;
                        sign_up_page.administrator_check.setFillColor(Color::White);
                        sign_up_page.reader_check.setFillColor(Color(255, 255, 255, 128));
                    }
                    FloatRect AdminCheck2 = sign_up_page.reader_check.getGlobalBounds();
                    Vector2f adminCheckmousePosition2 = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (AdminCheck2.contains(adminCheckmousePosition2)) {
                        sign_up_page.isAdmin = false;
                        sign_up_page.reader_check.setFillColor(Color::White);
                        sign_up_page.administrator_check.setFillColor(Color(255, 255, 255, 128));
                    }

                    FloatRect signup_submitBottonBounds = sign_up_page.sign_up_submit_button.getGlobalBounds();
                    Vector2f signupMousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (signup_submitBottonBounds.contains(signupMousePosition)) {       
                        string userType_signin, user_name__, password__;
                        sign_up_page.userInput = sign_up_page.userText.getString();
                        sign_up_page.passInput = sign_up_page.passText.getString();
                        ifstream read("ourfile.txt");
                        ofstream outfile;
                        outfile.open("ourfile.txt", ios::app); // Change file open mode to append
                        if (outfile.is_open())
                        {
                            if (sign_up_page.isAdmin) {
                                outfile << "admin" << endl;
                            }
                            else {
                                outfile << "user" << endl;
                            }
                            user_name__ = sign_up_page.userInput;  password__ = sign_up_page.passInput;
                            outfile << user_name__ << endl << password__ << endl;
                            cout << "\n\t\tRegistration completed\n";
                            sign_up_page.userText.setString("");
                            sign_up_page.passText.setString("");
                            sign_up_page.visible = false;
                            draw_menu(menu);
                            home.visible = true;
                        }
                        outfile.close();
                    }

                    FloatRect login_submitButtonBounds2 = login_page.login_submit_button.getGlobalBounds();
                    Vector2f loginmousePosition2 = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (login_submitButtonBounds2.contains(loginmousePosition2)) {       // Clear text fields
                        login_page.userInput = login_page.userText.getString();
                        login_page.passInput = login_page.passText.getString();
                        string  userType_login, user_name, password_;		//user_name & password_ variables to read from file 
                        ifstream read("ourfile.txt");
                        while (getline(read, userType_login)) {
                            getline(read, user_name);
                            getline(read, password_);
                            if (login_page.userInput == user_name && login_page.passInput == password_ && userType_login == "admin") {
                                login_page.visible = false;
                                home.visible = true;
                                login_page.found = true;
                                break;
                            }
                            else if (user_name == login_page.userInput && password_ == login_page.passInput && userType_login == "user") {
                                login_page.visible = false;
                                home.visible = true;
                                login_page.found = true;
                                break;
                            }
                            else {
                                check_user = true;
                            }
                        }
                        login_page.userText.setString("");
                        login_page.passText.setString("");
                    }

                    FloatRect menubounds = menu.homeIcon_sprite.getGlobalBounds();
                    Vector2f menumousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (menubounds.contains(menumousePosition)) {       // Clear text fields
                        displaybook.visible = false;
                        home.visible = true;
                    }
                    FloatRect menubounds2 = menu.logOut.getGlobalBounds();
                    Vector2f menumousePosition2 = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (menubounds2.contains(menumousePosition2)) {       // Clear text fields
                        displaybook.visible = false;
                        home.visible = false;
                        login_page.visible = true;
                    }
                    FloatRect menubounds3 = menu.cartIcon_sprite.getGlobalBounds();
                    Vector2f menumousePosition3 = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (menubounds3.contains(menumousePosition3)) {       // Clear text fields
                        displaybook.visible = false;
                        home.visible = false;
                    }

                }            break;
            default:         break;
            }
        }
       
        

        window.clear();
        window.draw(background);
        //draw_displaybook(displaybook);
        // Draw the visible page
        if (starting_page.visible) {
            draw_starting_page(starting_page);
        }
        else if (sign_up_page.visible) {
            draw_sign_up(sign_up_page);
        }
        else if (login_page.visible) {
            draw_login(login_page);
        }
        else if(home.visible){
            draw_menu(menu);
            draw_home(home);
        }
        else if(draw_dropdownbox.visible){
            draw_dropdownbox(dropdownbox);
        }
        window.display();

    }
    structs_to_files();
    counetr_to_file();
    return 0;
}

void texturesANDfonts() {
    italiana.loadFromFile("italiana-regular.otf");
    AbrilFatface_Regular.loadFromFile("AbrilFatface-Regular.otf");
    fantacy_texture.loadFromFile("1.png");
    mystery_texture.loadFromFile("2.png");
    romance_texture.loadFromFile("3.png");
    scienceFiction_texture.loadFromFile("4.png");
    nonFiction_texture.loadFromFile("5.png");
    homeIcon_texture.loadFromFile("home.png");
    cartIcon_texture.loadFromFile("cart.png");
    f1t.loadFromFile("Dance Of Thieves.png");
}
/****************                Starting page             ****************/

void draw_starting_page(STARTING_PAGE starting_page) {
    window.draw(starting_page.library_name);
    window.draw(starting_page.sign_up_button);
    window.draw(starting_page.log_in_button);
    window.draw(starting_page.log_in);
    window.draw(starting_page.sign_up);
}
void set_starting_page(STARTING_PAGE& starting_page) {
    string name = "Library Name";
    starting_page.library_name.setFont(italiana);
    starting_page.library_name.setString(name);
    starting_page.library_name.setPosition(300, 300);
    starting_page.library_name.setCharacterSize(88);

    starting_page.sign_up.setFont(AbrilFatface_Regular);
    starting_page.sign_up.setString("sign up");
    starting_page.sign_up.setPosition(350, 620);

    starting_page.log_in.setFont(AbrilFatface_Regular);
    starting_page.log_in.setString("log in");
    starting_page.log_in.setPosition(660, 620);

    starting_page.log_in_button.setSize(Vector2f(200, 80));
    starting_page.log_in_button.setFillColor(Color(0, 141, 220));
    starting_page.log_in_button.setPosition(600, 600);

    starting_page.sign_up_button.setSize(Vector2f(200, 80));
    starting_page.sign_up_button.setFillColor(Color(0, 141, 220, 128));
    starting_page.sign_up_button.setPosition(300, 600);
    starting_page.sign_up_button.setOutlineColor(Color::White);
    starting_page.sign_up_button.setOutlineThickness(2);
}

/****************                sign up page             ****************/

void set_sign_up(SIGN_UP& sign_up_page) {
    sign_up_page.sign_up_label.setFont(italiana);
    sign_up_page.sign_up_label.setString("Sign up");
    sign_up_page.sign_up_label.setPosition(260, 100);
    sign_up_page.sign_up_label.setCharacterSize(72);

    sign_up_page.sign_up_username.setFont(italiana);
    sign_up_page.sign_up_username.setString("username");
    sign_up_page.sign_up_username.setPosition(350, 300);
    sign_up_page.sign_up_username.setCharacterSize(40);

    sign_up_page.sign_up_password.setFont(italiana);
    sign_up_page.sign_up_password.setString("password");
    sign_up_page.sign_up_password.setPosition(350, 500);
    sign_up_page.sign_up_password.setCharacterSize(40);

    sign_up_page.sign_up_submit.setFont(AbrilFatface_Regular);
    sign_up_page.sign_up_submit.setString("sign up");
    sign_up_page.sign_up_submit.setPosition(1450, 720);

    sign_up_page.sign_up_submit_button.setSize(Vector2f(200, 80));
    sign_up_page.sign_up_submit_button.setFillColor(Color(0, 141, 220, 128));
    sign_up_page.sign_up_submit_button.setPosition(1400, 700);
    sign_up_page.sign_up_submit_button.setOutlineColor(Color::White);
    sign_up_page.sign_up_submit_button.setOutlineThickness(2);

    sign_up_page.administrator_check.setRadius(11);
    sign_up_page.administrator_check.setFillColor(Color(255, 255, 255, 128));
    sign_up_page.administrator_check.setPosition(350, 710);
    sign_up_page.administrator_check.setOutlineThickness(1);
    sign_up_page.administrator_check.setOutlineColor(Color::White);

    sign_up_page.reader_check.setRadius(11);
    sign_up_page.reader_check.setFillColor(Color(255, 255, 255, 128));
    sign_up_page.reader_check.setPosition(700, 710);
    sign_up_page.reader_check.setOutlineThickness(1);
    sign_up_page.reader_check.setOutlineColor(Color::White);

    sign_up_page.reader.setFont(italiana);
    sign_up_page.reader.setString("As a Reader");
    sign_up_page.reader.setPosition(750, 700);
    sign_up_page.reader.setCharacterSize(30);

    sign_up_page.administrator.setFont(italiana);
    sign_up_page.administrator.setString("As a administrator");
    sign_up_page.administrator.setPosition(400, 700);
    sign_up_page.administrator.setCharacterSize(30);

    sign_up_page.sign_up_input_username.setSize(Vector2f(370, 40));
    sign_up_page.sign_up_input_username.setFillColor(Color(255, 255, 255, 0));
    sign_up_page.sign_up_input_username.setPosition(500, 380);
    sign_up_page.sign_up_input_username.setOutlineColor(Color::White);
    sign_up_page.sign_up_input_username.setOutlineThickness(-0.5);

    sign_up_page.sign_up_input_password.setSize(Vector2f(370, 40));
    sign_up_page.sign_up_input_password.setFillColor(Color(255, 255, 255, 0));
    sign_up_page.sign_up_input_password.setPosition(500, 580);
    sign_up_page.sign_up_input_password.setOutlineColor(Color::White);
    sign_up_page.sign_up_input_password.setOutlineThickness(-0.5);

    sign_up_page.userText.setFont(italiana);
    sign_up_page.userText.setCharacterSize(30);
    sign_up_page.userText.setFillColor(sf::Color::White);
    sign_up_page.userText.setPosition(500, 377);

    sign_up_page.passText.setFont(italiana);
    sign_up_page.passText.setCharacterSize(30);
    sign_up_page.passText.setFillColor(sf::Color::White);
    sign_up_page.passText.setPosition(500, 580);

    sign_up_page.wrongans.setString("Try again");
    sign_up_page.wrongans.setFont(italiana);
    sign_up_page.wrongans.setCharacterSize(50);
    sign_up_page.wrongans.setFillColor(sf::Color::Red);
    sign_up_page.wrongans.setPosition(1000, 300);


}
void draw_sign_up(SIGN_UP sign_up_page) {
    window.draw(sign_up_page.sign_up_label);
    window.draw(sign_up_page.sign_up_username);
    window.draw(sign_up_page.sign_up_password);
    window.draw(sign_up_page.sign_up_submit_button);
    window.draw(sign_up_page.sign_up_submit);
    window.draw(sign_up_page.administrator_check);
    window.draw(sign_up_page.reader_check);
    window.draw(sign_up_page.reader);
    window.draw(sign_up_page.administrator);
    window.draw(sign_up_page.sign_up_input_username);
    window.draw(sign_up_page.sign_up_input_password);
    window.draw(sign_up_page.passText);
    window.draw(sign_up_page.userText);

}

/****************                log in page             ****************/

void set_login(LOG_IN& login_page) {
    login_page.login_label.setFont(italiana);
    login_page.login_label.setString("Log in");
    login_page.login_label.setPosition(260, 100);
    login_page.login_label.setCharacterSize(72);

    login_page.login_username.setFont(italiana);
    login_page.login_username.setString("username");
    login_page.login_username.setPosition(350, 300);
    login_page.login_username.setCharacterSize(40);

    login_page.login_password.setFont(italiana);
    login_page.login_password.setString("password");
    login_page.login_password.setPosition(350, 500);
    login_page.login_password.setCharacterSize(40);

    login_page.login_submit.setFont(AbrilFatface_Regular);
    login_page.login_submit.setString("log in");
    login_page.login_submit.setPosition(1450, 720);

    login_page.login_submit_button.setSize(Vector2f(200, 80));
    login_page.login_submit_button.setFillColor(Color(0, 141, 220, 128));
    login_page.login_submit_button.setPosition(1400, 700);
    login_page.login_submit_button.setOutlineColor(Color::White);
    login_page.login_submit_button.setOutlineThickness(2);

    login_page.login_input_username.setSize(Vector2f(370, 40));
    login_page.login_input_username.setFillColor(Color(255, 255, 255, 0));
    login_page.login_input_username.setPosition(500, 380);
    login_page.login_input_username.setOutlineColor(Color::White);
    login_page.login_input_username.setOutlineThickness(-0.5);

    login_page.login_input_password.setSize(Vector2f(370, 40));
    login_page.login_input_password.setFillColor(Color(255, 255, 255, 0));
    login_page.login_input_password.setPosition(500, 580);
    login_page.login_input_password.setOutlineColor(Color::White);
    login_page.login_input_password.setOutlineThickness(-0.5);


    login_page.userText.setFont(italiana);
    login_page.userText.setCharacterSize(30);
    login_page.userText.setFillColor(sf::Color::White);
    login_page.userText.setPosition(500, 377);

    login_page.passText.setFont(italiana);
    login_page.passText.setCharacterSize(30);
    login_page.passText.setFillColor(sf::Color::White);
    login_page.passText.setPosition(500, 580);
}
void draw_login(LOG_IN login_page) {
    window.draw(login_page.login_label);
    window.draw(login_page.login_username);
    window.draw(login_page.login_password);
    window.draw(login_page.login_submit_button);
    window.draw(login_page.login_submit);
    window.draw(login_page.login_input_username);
    window.draw(login_page.login_input_password);
    window.draw(login_page.passText);
    window.draw(login_page.userText);
}

/****************                home            ****************/

void set_home(HOME& home) {
    home.fantacy_label.setString("Fantacy");
    home.fantacy_label.setFont(italiana);
    home.fantacy_label.setPosition(330, 400);
    home.fantacy_label.setCharacterSize(50);

    home.mystery_label.setString("Mystery");
    home.mystery_label.setFont(italiana);
    home.mystery_label.setPosition(830, 400);
    home.mystery_label.setCharacterSize(50);

    home.nonFiction_label.setString("Non Fiction");
    home.nonFiction_label.setFont(italiana);
    home.nonFiction_label.setPosition(1150, 800);
    home.nonFiction_label.setCharacterSize(50);

    home.romance_label.setString("Romance");
    home.romance_label.setFont(italiana);
    home.romance_label.setPosition(1300, 400);
    home.romance_label.setCharacterSize(50);

    home.scienceFiction_label.setString("Science Fiction");
    home.scienceFiction_label.setFont(italiana);
    home.scienceFiction_label.setPosition(450, 800);
    home.scienceFiction_label.setCharacterSize(50);

    home.fantacy_sprite.setTexture(fantacy_texture);
    home.fantacy_sprite.setPosition(400, 250);
    home.fantacy_sprite.setOrigin(home.fantacy_sprite.getGlobalBounds().width / 2, home.fantacy_sprite.getGlobalBounds().height / 2);

    home.mystery_sprite.setTexture(mystery_texture);
    home.mystery_sprite.setPosition(900, 250);
    home.mystery_sprite.setOrigin(home.mystery_sprite.getGlobalBounds().width / 2, home.mystery_sprite.getGlobalBounds().height / 2);

    home.nonFiction_sprite.setTexture(nonFiction_texture);
    home.nonFiction_sprite.setPosition(1250, 650);
    home.nonFiction_sprite.setOrigin(home.nonFiction_sprite.getGlobalBounds().width / 2, home.nonFiction_sprite.getGlobalBounds().height / 2);

    home.romance_sprite.setTexture(romance_texture);
    home.romance_sprite.setPosition(1400, 250);
    home.romance_sprite.setOrigin(home.romance_sprite.getGlobalBounds().width / 2, home.romance_sprite.getGlobalBounds().height / 2);

    home.scienceFiction_sprite.setTexture(scienceFiction_texture);
    home.scienceFiction_sprite.setPosition(600, 650);
    home.scienceFiction_sprite.setOrigin(home.scienceFiction_sprite.getGlobalBounds().width / 2, home.scienceFiction_sprite.getGlobalBounds().height / 2);


}
void draw_home(HOME home) {
    window.draw(home.fantacy_label);
    window.draw(home.fantacy_sprite);
    window.draw(home.mystery_label);
    window.draw(home.mystery_sprite);
    window.draw(home.nonFiction_label);
    window.draw(home.nonFiction_sprite);
    window.draw(home.romance_label);
    window.draw(home.romance_sprite);
    window.draw(home.scienceFiction_label);
    window.draw(home.scienceFiction_sprite);
}

/****************                menu           ****************/

void set_menu(MENU& menu) {
    menu.homeIcon_sprite.setTexture(homeIcon_texture);
    menu.homeIcon_sprite.setOrigin(menu.homeIcon_sprite.getGlobalBounds().width / 2, menu.homeIcon_sprite.getGlobalBounds().height / 2);
    menu.homeIcon_sprite.setPosition(1530, 50);
    menu.homeIcon_sprite.setScale(0.3, 0.3);

    menu.cartIcon_sprite.setTexture(cartIcon_texture);
    menu.cartIcon_sprite.setOrigin(menu.cartIcon_sprite.getGlobalBounds().width / 2, menu.cartIcon_sprite.getGlobalBounds().height / 2);
    menu.cartIcon_sprite.setPosition(1600, 50);
    menu.cartIcon_sprite.setScale(0.3, 0.3);

    menu.logOut.setString("Log out");
    menu.logOut.setFont(italiana);
    menu.logOut.setCharacterSize(40);
    menu.logOut.setOrigin(menu.logOut.getGlobalBounds().width / 2, menu.logOut.getGlobalBounds().height / 2);
    menu.logOut.setPosition(1710, 40);

}
void draw_menu(MENU menu) {
    window.draw(menu.homeIcon_sprite);
    window.draw(menu.cartIcon_sprite);
    window.draw(menu.logOut);
}

void set_displaybook(DISPLAYBOOK& displaybook) {
    displaybook.title_.setString("fmdkjfoidjsf");
    displaybook.title_.setPosition(100, 100);
    displaybook.title_.setCharacterSize(50);
    displaybook.title_.setFont(italiana);
    
    displaybook.cover.setScale(0.5, 0.5);
    displaybook.cover.setTexture(f1t);
    displaybook.cover.setPosition(100, 100);


}

void draw_displaybook(DISPLAYBOOK displaybook) {
    window.draw(displaybook.author_);
    window.draw(displaybook.cover);
    window.draw(displaybook.description_);
    window.draw(displaybook.numofpages_);
    window.draw(displaybook.price_);
    window.draw(displaybook.review_);
    window.draw(displaybook.status_);
    window.draw(displaybook.title_);
    window.draw(displaybook.type_);
}

void set_dropdownbox(DROPDOWNBOX& dropdownbox) {
    dropdownbox.box.setSize(Vector2f(460, 50));
    dropdownbox.box.setFillColor(Color(0, 141, 220));
    dropdownbox.box.setPosition(40, 70);

    dropdownbox.shade.setSize(Vector2f(460, 600));
    dropdownbox.shade.setFillColor(Color(0, 141, 220, 128));
    dropdownbox.shade.setPosition(40, 70);

    dropdownbox.boxLabel.setString("Books");
    dropdownbox.boxLabel.setFont(italiana);
    dropdownbox.boxLabel.setPosition(200, 60);
    dropdownbox.boxLabel.setCharacterSize(50);

    Text book1, book2, book3, book4, book5, book6, book7, book8, book9, book10;
    
    book1.setFont(italiana);
    book1.setString(fantasy[0].title);
    book1.setCharacterSize(40);
    book1.setFillColor(Color::White);
    book1.setPosition(50, 150);
    dropdownbox.books.push_back(book1);

    book2.setFont(italiana);
    book2.setString(fantasy[1].title);
    book2.setCharacterSize(40);
    book2.setFillColor(Color::White);
    book2.setPosition(50, 200);
    dropdownbox.books.push_back(book2);

    book3.setFont(italiana);
    book3.setString(fantasy[2].title);
    book3.setCharacterSize(40);
    book3.setFillColor(Color::White);
    book3.setPosition(50, 250);
    dropdownbox.books.push_back(book3);

    book4.setFont(italiana);
    book4.setString(fantasy[3].title);
    book4.setCharacterSize(40);
    book4.setFillColor(Color::White);
    book4.setPosition(50, 300);
    dropdownbox.books.push_back(book4);

    book5.setFont(italiana);
    book5.setString(fantasy[4].title);
    book5.setCharacterSize(40);
    book5.setFillColor(Color::White);
    book5.setPosition(50, 350);
    dropdownbox.books.push_back(book5);

    book6.setFont(italiana);
    book6.setString(fantasy[5].title);
    book6.setCharacterSize(40);
    book6.setFillColor(Color::White);
    book6.setPosition(50, 400);
    dropdownbox.books.push_back(book6);

    book7.setFont(italiana);
    book7.setString(fantasy[6].title);
    book7.setCharacterSize(40);
    book7.setFillColor(Color::White);
    book7.setPosition(50, 450);
    dropdownbox.books.push_back(book7);

    book8.setFont(italiana);
    book8.setString(fantasy[7].title);
    book8.setCharacterSize(40);
    book8.setFillColor(Color::White);
    book8.setPosition(50, 500);
    dropdownbox.books.push_back(book8);

    book9.setFont(italiana);
    book9.setString(fantasy[8].title);
    book9.setCharacterSize(40);
    book9.setFillColor(Color::White);
    book9.setPosition(50, 550);
    dropdownbox.books.push_back(book9);

    book10.setFont(italiana);
    book10.setString(fantasy[9].title);
    book10.setCharacterSize(40);
    book10.setFillColor(Color::White);
    book10.setPosition(50, 600);
    dropdownbox.books.push_back(book10);

}
void draw_dropdownbox(DROPDOWNBOX dropdownbox) {
    window.draw(dropdownbox.shade);
    window.draw(dropdownbox.box);
    window.draw(dropdownbox.boxLabel);
    for (const auto& text : dropdownbox.books) {
        window.draw(text);
    }

}
