
#ifndef __BEGADU_GFX_STUFF_H__
#define __BEGADU_GFX_STUFF_H__

#include <View.h>

class BBitmap;
class BResources;

BBitmap *LoadBMP( char* );
BBitmap *LoadGFX( const char* );

class BString;
BString *fromISO2(const char *input);
BString *toISO2(const char *input);

class IconControl : public BView
{
	public:
		IconControl( BRect aFrame, const char *aName, BBitmap *MOut, BBitmap *MOver, BMessage *aMessage );
		~IconControl();
		virtual void Draw( BRect updateRect );
		virtual void AttachedToWindow();
		virtual void MouseMoved( BPoint aPoint, uint32 aTransit, const BMessage *aMessage );
		virtual void MouseDown( BPoint aPoint );
		virtual void MouseUp( BPoint aPoint );
		virtual void MessageReceived( BMessage *aMessage );

	private:
		BMessage *mesg;
		BBitmap *IconOut;
		BBitmap *IconOver;
		bool IsDown;
		bool IsMouseOver;
};

class BitmapView : public BView
{
	public:
		BitmapView(BRect frame, const char *name, BResources *res);
		~BitmapView();
		void Draw(BRect updateRect);
		void AttachedToWindow();
		BBitmap *GetBitmap(const char *name);

	private:
		BResources 	*	fResources;
		BBitmap		*	fBitmap;
		BRect 			bmbounds;
};

#endif // GFX_STUFF_H
