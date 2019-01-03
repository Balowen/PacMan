#include "Animation.h"



Animation::Animation()
:current_frameIndex(0)
,m_animationTime(sf::Time::Zero)
,m_isPlaying(false)
,m_loopAnimation(false)
{
}


Animation::~Animation()
{
}

void Animation::addFrame(sf::IntRect frame)
{
	m_frames.push_back(frame);	//add frame to m_frames vector
}

void Animation::play(sf::Time animationTime, bool loopAnimation)
{
	m_isPlaying = true;
	m_animationTime = animationTime;
	m_loopAnimation = loopAnimation;	//if true, keep animating
}

bool Animation::isPlaying() const
{
	return m_isPlaying;
}

void Animation::update(sf::Time elapsedTime)
{
	if (!isPlaying())				//if we didn't call animate, don't do anything
		return;

	static sf::Time buffer = sf::Time::Zero;
	buffer += elapsedTime;		//it will always be = elapsedTime

	// single frame animation time = wholeAnimationTime / number of frames in vector m_frames
	sf::Time single_frameTime = m_animationTime / static_cast<float>(m_frames.size());
												//because size() returns uint
	while (buffer > single_frameTime)	//if we have elapsedTime to animate
	{
		current_frameIndex++;
		if (current_frameIndex == m_frames.size())	
		{
			if (!m_loopAnimation)
				m_isPlaying = false;	//dont want to loopAnimation, then stop playing

			current_frameIndex = 0;	//else, keep changing animations 
		}
		buffer -= single_frameTime;
	}
}

void Animation::animate(sf::Sprite & sprite)
{
	sprite.setTextureRect(m_frames[current_frameIndex]);	//changes sprite texture
}
