
#ifndef __BEGADU_DESKBAR_H__
#define __BEGADU_DESKBAR_H__

#include <View.h>
#include <Resources.h>

class BBitmap;
class BPopUpMenu;
class BMessage;

class _EXPORT BGDeskbar : public BView
	{
	public:
		BGDeskbar();
		BGDeskbar( BMessage *aMessage );
		virtual ~BGDeskbar();

		virtual	status_t Archive( BMessage *aMessage, bool aDeep = true ) const;
		static BArchivable *Instantiate( BMessage *aData );
		virtual	void AttachedToWindow();
		virtual void DetachedFromWindow();
		virtual void Draw( BRect aRect );
		virtual void Pulse();
		virtual void MessageReceived( BMessage *aMessage );
		virtual void MouseDown( BPoint aWhere );
		void Initialize();
		void Remove();
		BBitmap	*GetBitmap( const char *name );
		
	private:
		BPopUpMenu		*	iMenuProfileSelected;
		BPopUpMenu		*	iMenuProfileNotSelected;
		BBitmap			*	iIcon;
		BBitmap			*	iIconAvail;
		BBitmap			*	iIconBusy;
		BBitmap			*	iIconInvisible;
		BBitmap			*	iIconNotAvail;
		BBitmap			*	iIconAvailDescr;
		BBitmap			*	iIconBusyDescr;
		BBitmap			*	iIconInvisibleDescr;
		BBitmap			*	iIconNotAvailDescr;
		BBitmap			*	iIconNewMessage;
		BBitmap			*	iIconQuit;
		BBitmap			*	iIconSelect;
		time_t				iMesgAnimate;
		bool				iProfileSelected;
		BResources			iResources;
	};

#endif /* __BEGADU_DESKBAR_H__ */
