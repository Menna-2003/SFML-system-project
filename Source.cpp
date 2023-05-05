#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);

Font italiana, AbrilFatface_Regular;
Texture homeIcon_texture, cartIcon_texture, fantacy_texture, mystery_texture, romance_texture, scienceFiction_texture, nonFiction_texture;

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
struct HOME
{
    Text fantacy_label, mystery_label, romance_label, scienceFiction_label, nonFiction_label;
    Sprite fantacy_sprite, mystery_sprite, romance_sprite, scienceFiction_sprite, nonFiction_sprite;
};
struct MENU
{
    Sprite homeIcon_sprite, cartIcon_sprite;
    Text logOut;
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

int main() {
    STARTING_PAGE starting_page;
    SIGN_UP sign_up_page;
    LOG_IN login_page;
    HOME home;
    MENU menu;

    texturesANDfonts();
    set_starting_page(starting_page);
    set_sign_up(sign_up_page);
    set_login(login_page);
    set_home(home);
    set_menu(menu);

    //////////// background ///////////// 
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");
    Sprite background(backgroundTexture);
    background.setScale(1.5, 1.5);

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
        //draw_login(login_page);
        //draw_home(home);
        //draw_menu(menu);
        window.display();
    }
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
    starting_page.log_in_button.setPosition(300, 600);
   
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

                                    /****************                home            ****************/

void set_home(HOME& home) {
    home.fantacy_label.setString("Fantacy");
    home.fantacy_label.setFont(italiana);
    home.fantacy_label.setPosition(330,400);
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
