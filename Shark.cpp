#include "Shark.h"
#include <iostream>
Shark::Shark() {

}

Shark::Shark(sf::Texture& _texture, sf::Font& font, std::string str, int _lives,int y) {
	isdeath = false;
	_type = _lives;
	lives = _lives;
	word = str;
	body.setTexture(_texture);
	body.setScale(2, 2);
	animation.Init(&_texture, sf::Vector2u(20, 1), 0.1f);
	body.setPosition(1000, y*body.getGlobalBounds().height);
	text.setFont(font);
	text.setString(word);
	text.setCharacterSize(22);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	text.setPosition(body.getPosition().x + body.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2.75);
}

void Shark::Init(sf::Texture& _texture, sf::Font& font, std::string str, int _lives,int y) {
	isdeath = false;
	_type = _lives;
	lives = _lives;
	word = str;
	body.setTexture(_texture);
	body.setScale(2, 2);
	animation.Init(&_texture, sf::Vector2u(20, 1), 0.1f);
	body.setPosition(1000, y * body.getGlobalBounds().height);
	text.setFont(font);
	text.setString(word);
	text.setCharacterSize(22);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	text.setPosition((body.getPosition().x + body.getGlobalBounds().width / 2) - text.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2.75);
}

void Shark::Update()
{
	datatime = clock.restart().asSeconds();
	animation.Update(0, datatime);
	body.setTextureRect(animation.uvRect);
	if (!isdeath)
	{
		body.move(Shark_Speed * datatime, 0);
		text.setPosition((body.getPosition().x + body.getGlobalBounds().width / 2) - text.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2.75);
	}	
}

void Shark::Draw(sf::RenderWindow& _window) {
	_window.draw(body);
	if(!isdeath)
		_window.draw(text);
}

std::string Shark::getString()
{
	return word;
}
void Shark::setString(std::string str)
{
	word = str;
	text.setString(word);
}
int Shark::getLives()
{
	return lives;
}
void Shark::reduceLives()
{
	lives--;
	std::cout << "New Lives : " << lives << std::endl;
}
sf::Sprite Shark::GetSprite()
{
	return body;
}

void Shark::death(sf::Texture& _texture)
{
	body.setTexture(_texture);
	body.setScale(2, 2);
	animation.Init(&_texture, sf::Vector2u(6, 1), 0.1f);
	body.move(0, 0);
	_deathtimer.restart();
	isdeath = true;
}

int Shark::getType()
{
	return _type;
}

bool Shark::isDeath()
{
	if (isdeath && _deathtimer.getElapsedTime().asSeconds() >= Shark_Death_Timer)
		return true;
	else
		return false;
}
