
#include <Screen.h>
#include <String.h>

#include "About.h"
#include "Msg.h"
#include "globals.h"

#define ABOUTWINDOW_RECT BRect(100,100,500,400)

AboutView::AboutView( BRect aRect ) : BView( aRect,
											 "AboutView",
											 B_FOLLOW_ALL,
											 B_WILL_DRAW ) {
	SetViewColor( 60, 60, 60 );
}

void AboutView::Draw( BRect aRect ) {
	BFont font( be_plain_font );
	font.SetSize( 18.0 );
	SetFont( &font );
	SetDrawingMode( B_OP_OVER );
	BString title( APP_NAME " " VERSION );
	MovePenTo(  ( ( ABOUTWINDOW_RECT.right - ABOUTWINDOW_RECT.left) /2 ) - font.StringWidth( title.String() ) /2 , 20 );
	SetHighColor( 255, 255, 255 );
	DrawString( APP_NAME " " VERSION );
}

AboutWindow::AboutWindow() : BWindow( ABOUTWINDOW_RECT,
									  "About",
									  B_TITLED_WINDOW,
									  B_NOT_RESIZABLE |
									  B_NOT_ZOOMABLE |
									  B_NOT_MOVABLE ) {
	/* setting background */
	BRect r = Bounds();
	AboutView *aboutView;
	aboutView = new AboutView( r );
	AddChild( aboutView );
}

void AboutWindow::Show() {
	BScreen *screen = new BScreen( this );
	display_mode mode;
	screen->GetMode( &mode );
	/* we center a window */
	int32 width = (int32)( ABOUTWINDOW_RECT.right - ABOUTWINDOW_RECT.left );
	int32 height = (int32)( ABOUTWINDOW_RECT.bottom - ABOUTWINDOW_RECT.top );
	/* calculating center of a screen /2 - 1/2 of window width */
	int32 x_wind = mode.timing.h_display/2 - ( width/2 );
	/* calculating center of a screen /2 - 1/2 of window height */
	int32 y_wind = mode.timing.v_display/2 - ( height/2 );
	MoveTo( x_wind, y_wind );
	BWindow::Show();
}

bool AboutWindow::QuitRequested() {
	return true;
}
