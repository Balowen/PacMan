#include "Animation.h"



Animation::Animation()
:currentFrame(0)
,m_animationTime(sf::Time::Zero)
,m_isPlaying(false)
,m_keepAnimating(false)
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
}

void Animation::animate(sf::Sprite & sprite)
{
	sprite.setTextureRect(m_frames[current_frameIndex]);	//changes sprite texture
}
