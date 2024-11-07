#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace sf;

class Enemy {
public:
    Enemy(Texture& texture) {
        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f);
        resetPosition();
    }

    void resetPosition() {
        sprite.setPosition(static_cast<float>(rand() % (800 - 164)), static_cast<float>(rand() % (600 - 164)));
    }

    Sprite& getSprite() { return sprite; }
    FloatRect getBounds() const { return sprite.getGlobalBounds(); }

private:
    Sprite sprite;
};

class Crosshair {
public:
    Crosshair(Texture& texture) {
        sprite.setTexture(texture);
    }

    void setPosition(Vector2f position) {
        sprite.setPosition(position);
    }

    Sprite& getSprite() { return sprite; }
    FloatRect getBounds() const { return sprite.getGlobalBounds(); }

private:
    Sprite sprite;
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    RenderWindow App(VideoMode(800, 600), "elimina a los alienigenas");
    App.setFramerateLimit(60);

    App.setMouseCursorVisible(false);

    Texture enemyTexture, crosshairTexture;
    enemyTexture.loadFromFile("C:/SFML/imagenes/et.png");
    crosshairTexture.loadFromFile("C:/SFML/imagenes/crosshair.png");
 
Crosshair crosshair(crosshairTexture);
    std::vector<Enemy> enemies;
    for (int i = 0; i < 5; ++i) {
        enemies.emplace_back(enemyTexture);
    }

    int enemiesDefeated = 0;

    while (App.isOpen()) {
        Event evt;
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                App.close();
                break;
            case sf::Event::KeyPressed:Espace:
                App.close();
                break;
           }
            if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left) {
                Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));
                for (auto& enemy : enemies) { 
                    if (enemy.getBounds().contains(mousePos)) {
                        enemy.resetPosition(); 
                        enemiesDefeated++; 
                        std::cout << "Enemigos derrotados: " << enemiesDefeated << std::endl;

                        if (enemiesDefeated >= 5) {
                            std::cout << "¡Has derrotado a todos los enemigos!" << std::endl;
                            App.close();
                        }
                        break;
                    }
                }
            }
        }

        Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

        FloatRect crosshairBounds = crosshair.getSprite().getGlobalBounds();

        float crosshairCenterX = crosshairBounds.width / 2.0f;
        float crosshairCenterY = crosshairBounds.height / 2.0f;

        crosshair.setPosition(Vector2f(mousePos.x - crosshairCenterX, mousePos.y - crosshairCenterY));

        App.clear();

        for (auto& enemy : enemies) {
            App.draw(enemy.getSprite());
        }
        App.draw(crosshair.getSprite());

        App.display();
    }
    return 0;
}