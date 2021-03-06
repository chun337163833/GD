/**

GDevelop - Text Object Extension
Copyright (c) 2008-2015 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/

#if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)

#ifndef TEXTOBJECTEDITOR_H
#define TEXTOBJECTEDITOR_H

//(*Headers(TextObjectEditor)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/tglbtn.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
namespace gd { class Project; }
class TextObject;
namespace gd { class MainFrameWrapper; }

class TextObjectEditor: public wxDialog
{
	public:

		TextObjectEditor( wxWindow* parent, gd::Project & game_, TextObject & object_, gd::MainFrameWrapper & mainFrameWrapper_);
		virtual ~TextObjectEditor();

		void AdaptFontColor(wxButton *button);

		//(*Declarations(TextObjectEditor)
		wxSpinCtrl* sizeEdit;
		wxStaticText* StaticText2;
		wxTextCtrl* textEdit;
		wxStaticText* StaticText1;
		wxToggleButton* underlineToggleButton;
		wxStaticText* StaticText3;
		wxButton* fontBt;
		wxButton* colorBt;
		wxStaticLine* StaticLine1;
		wxToggleButton* boldToggleButton;
		wxCheckBox* smoothCheck;
		wxTextCtrl* fontEdit;
		wxStaticText* StaticText4;
		wxButton* okBt;
		wxToggleButton* italicToggleButton;
		//*)

	protected:

		//(*Identifiers(TextObjectEditor)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TOGGLEBUTTON1;
		static const long ID_TOGGLEBUTTON2;
		static const long ID_TOGGLEBUTTON3;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(TextObjectEditor)
		void OnokBtClick(wxCommandEvent& event);
		void OncolorBtClick(wxCommandEvent& event);
		void OnfontBtClick(wxCommandEvent& event);
		void OnSizeEditChange(wxSpinEvent& event);
		void OncancelBtClick(wxCommandEvent& event);
		//*)

		gd::Project & game;
		TextObject & object;
		gd::MainFrameWrapper & mainFrameWrapper;

		DECLARE_EVENT_TABLE()
};

#endif
#endif

