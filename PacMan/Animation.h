#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation();
	~Animation();
	
	void addFrame(sf::IntRect frame);	//adding frames of animation to vector frames

	void play(sf::Time animationTime, bool loopAnimation);
	bool isPlaying() const;

	void update(sf::Time elapsedTime);
	void animate(sf::Sprite& sprite);

private:
	std::vector <sf::IntRect> m_frames;
	
	bool m_isPlaying;
	bool m_loopAnimation;
	sf::Time m_animationTime;

	unsigned int current_frameIndex;	//index of current frame in vector
};

