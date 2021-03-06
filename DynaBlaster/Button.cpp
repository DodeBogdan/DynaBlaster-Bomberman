#include "Button.h"

Button::Button()
{
	// Empty
}

Button::Button(const std::string& buttonText, const sf::Vector2f& size, const int charSize, const sf::Color& bgColor, const sf::Color& textColor)
{
	m_text.setString(buttonText);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(charSize);

	m_button.setSize(size);
	m_button.setFillColor(bgColor);
}

void Button::SetFont(const sf::Font& font)
{
	m_text.setFont(font);
}

void Button::SetFontSize(const int charSize)
{
	m_text.setCharacterSize(charSize);
}

void Button::SetBgColor(const sf::Color& color)
{
	m_button.setFillColor(color);
}

void Button::SetPosition(const sf::Vector2f& position)
{
	m_button.setPosition(position);
	float xPosition = (position.x + m_button.getGlobalBounds().width / 4) - (m_text.getGlobalBounds().width / 2);
	float yPosition = (position.y + m_button.getGlobalBounds().height / 4) - (m_text.getGlobalBounds().height / 2);
	m_text.setPosition({ xPosition, yPosition });
}

void Button::DrawTo(sf::RenderWindow& window)
{
	window.draw(m_button);
	window.draw(m_text);
}

bool Button::IsMouseOver(const sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonPosX = m_button.getPosition().x;
	float buttonPosY = m_button.getPosition().y;

	float buttonXPosWidth = m_button.getPosition().x + m_button.getLocalBounds().width;
	float buttonYPosHeight = m_button.getPosition().y + m_button.getLocalBounds().height;

	if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
		return true;
	return false;
}
