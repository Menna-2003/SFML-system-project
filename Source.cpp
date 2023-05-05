#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

Font italiana, AbrilFatface_Regular;
Texture library_name;

RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);

struct STARTING_PAGE{
    Text sign_up, log_in, library_name;
    RectangleShape sign_up_button, log_in_button;
};
struct  SIGN_UP {
    Text sign_up_label, sign_up_username, sign_up_password, reader, administrator, sign_up_submit;
    RectangleShape sign_up_submit_button, sign_up_input_username, sign_up_input_password;
    CircleShape reader_check, administrator_check;
};
struct  LOG_IN {
    Text login_label, login_username, login_password, login_submit;
    RectangleShape login_submit_button, login_input_username, login_input_password;
};

void fonts();

void draw_starting_page(STARTING_PAGE);
void set_starting_page(STARTING_PAGE& starting_page);

void set_sign_up(SIGN_UP& sign_up_page);
void draw_sign_up(SIGN_UP sign_up_page);

void set_login(LOG_IN& login_page);
void draw_login(LOG_IN  login_page);

int main() {
    STARTING_PAGE starting_page;
    SIGN_UP sign_up_page;
    LOG_IN login_page;
    fonts();
    set_starting_page(starting_page);
    set_sign_up(sign_up_page);
    set_login(login_page);

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");
    Sprite background(backgroundTexture);
    background.setScale(1.5, 1.5);
    string input_string;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(background);
        //draw_starting_page(starting_page);
        //draw_sign_up(sign_up_page);
        draw_login(login_page);
        window.display();
    }
    return 0;
}

void fonts() {
    italiana.loadFromFile("italiana-regular.otf");
    AbrilFatface_Regular.loadFromFile("AbrilFatface-Regular.otf");
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
    starting_page.library_name.setFont(italiana);
    starting_page.library_name.setString("Library Name");
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
    starting_page.log_in_button.setPosition(300, 600);
   
    starting_page.sign_up_button.setOutlineThickness(2);
    starting_page.sign_up_button.setSize(Vector2f(200, 80));
    starting_page.sign_up_button.setFillColor(Color(0, 141, 220, 128));
    starting_page.sign_up_button.setPosition(600, 600);
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
}
void draw_login(LOG_IN login_page) {
    window.draw(login_page.login_label);
    window.draw(login_page.login_username);
    window.draw(login_page.login_password);
    window.draw(login_page.login_submit_button);
    window.draw(login_page.login_submit);
    window.draw(login_page.login_input_username);
    window.draw(login_page.login_input_password);
}