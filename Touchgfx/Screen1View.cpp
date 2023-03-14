#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{

	if(count>=9)
	{
		count=0;
	}
	if(count>0 && count<4)
	{
		 circle1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 255,0 ));
		circle1.setPainter(circle1Painter);
		circle1.invalidate();

	}
	else if(count>4 && count<6)
	{
		 circle1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 255));
		circle1.setPainter(circle1Painter);
		circle1.invalidate();
	}
	else
	{
		 circle1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
			circle1.setPainter(circle1Painter);
			circle1.invalidate();
	}

	count++;
	Unicode::snprintf(textArea1Buffer,TEXTAREA1_SIZE,"%d",count);
	textArea1.invalidate();
}

