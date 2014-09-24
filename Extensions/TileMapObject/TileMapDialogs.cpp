//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: TileMapDialogs.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "TileMapDialogs.h"
#include "TileMapDialogsIds.h"


// Declare the bitmap loading function
extern void wxCF6DCInitBitmapResources();

static bool bBitmapLoaded = false;


TileMapObjectEditorBase::TileMapObjectEditorBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCF6DCInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    m_auimgr178 = new wxAuiManager;
    m_auimgr178->SetManagedWindow( this );
    m_auimgr178->SetFlags( wxAUI_MGR_LIVE_RESIZE|wxAUI_MGR_VENETIAN_BLINDS_HINT|wxAUI_MGR_TRANSPARENT_HINT|wxAUI_MGR_TRANSPARENT_DRAG|wxAUI_MGR_ALLOW_FLOATING);
    m_auimgr178->GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, wxAUI_GRADIENT_NONE);
    
    m_tileSetPropertiesPanel = new wxPanel(this, ID_TILESETPANEL, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    m_auimgr178->AddPane(m_tileSetPropertiesPanel, wxAuiPaneInfo().Name(wxT("TILESETPANEL")).Caption(_("Tileset")).Direction(wxAUI_DOCK_LEFT).Layer(0).Row(0).Position(0).BestSize(400,550).MinSize(400,550).CaptionVisible(true).MaximizeButton(false).CloseButton(false).MinimizeButton(false).PinButton(false));
    
    wxFlexGridSizer* flexGridSizer5 = new wxFlexGridSizer(6, 1, 0, 0);
    flexGridSizer5->SetFlexibleDirection( wxBOTH );
    flexGridSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer5->AddGrowableCol(0);
    flexGridSizer5->AddGrowableRow(1);
    m_tileSetPropertiesPanel->SetSizer(flexGridSizer5);
    
    m_tileSetToolBar = new wxToolBar(m_tileSetPropertiesPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_FLAT);
    m_tileSetToolBar->SetToolBitmapSize(wxSize(16,16));
    
    flexGridSizer5->Add(m_tileSetToolBar, 0, wxALL|wxEXPAND, 0);
    
    m_tileSetToolBar->AddTool(CONFIGURE_TILESET_TOOL_ID, _("Configure the tileset"), wxXmlResource::Get()->LoadBitmap(wxT("options16")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_tileSetToolBar->AddTool(EDIT_TILE_TOOL_ID, _("Edit the selected tile"), wxXmlResource::Get()->LoadBitmap(wxT("maskEdit16")), wxNullBitmap, wxITEM_CHECK, _("Opens the tile editor to edit the tile collision mask."), wxT(""), NULL);
    m_tileSetToolBar->Realize();
    
    m_tileSetPanel = new TileSetPanel(m_tileSetPropertiesPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxFULL_REPAINT_ON_RESIZE|wxHSCROLL|wxVSCROLL);
    m_tileSetPanel->SetScrollRate(5, 5);
    
    flexGridSizer5->Add(m_tileSetPanel, 0, wxALL|wxEXPAND, 5);
    
    m_mainPanel = new wxPanel(this, ID_MAINPANEL, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    m_auimgr178->AddPane(m_mainPanel, wxAuiPaneInfo().Name(wxT("MAINPANEL")).Direction(wxAUI_DOCK_CENTER).Layer(0).Row(0).Position(0).BestSize(600,800).MinSize(600,800).Fixed().CaptionVisible(false).MaximizeButton(false).CloseButton(false).MinimizeButton(false).PinButton(false));
    m_auimgr178->Update();
    
    wxFlexGridSizer* flexGridSizer200 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer200->SetFlexibleDirection( wxBOTH );
    flexGridSizer200->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer200->AddGrowableCol(0);
    flexGridSizer200->AddGrowableRow(1);
    m_mainPanel->SetSizer(flexGridSizer200);
    
    wxFlexGridSizer* flexGridSizer490 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer490->SetFlexibleDirection( wxBOTH );
    flexGridSizer490->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer490->AddGrowableCol(1);
    flexGridSizer490->AddGrowableRow(0);
    
    flexGridSizer200->Add(flexGridSizer490, 1, wxALL|wxEXPAND, 0);
    
    m_toolbar492 = new wxToolBar(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTB_NODIVIDER|wxTB_FLAT);
    m_toolbar492->SetToolBitmapSize(wxSize(16,16));
    
    flexGridSizer490->Add(m_toolbar492, 0, wxALL|wxEXPAND|wxALIGN_TOP, 0);
    
    m_toolbar492->AddTool(MODE_SINGLE_TILE_TOOL_ID, _("Pencil mode"), wxXmlResource::Get()->LoadBitmap(wxT("edit16")), wxNullBitmap, wxITEM_RADIO, _("Pencil mode\nAdd tiles only where the mouse goes."), wxT(""), NULL);
    
    m_toolbar492->AddTool(MODE_RECTANGLE_TILE_TOOL_ID, _("Rectangle mode"), wxXmlResource::Get()->LoadBitmap(wxT("rectangle")), wxNullBitmap, wxITEM_RADIO, _("Rectangle mode\nAdd tile in a rectangle from the position where the mouse was pressed to the position the mouse was released."), wxT(""), NULL);
    
    m_toolbar492->AddSeparator();
    
    m_toolbar492->AddTool(FILL_WITH_TILE_TOOL_ID, _("Fill layer"), wxXmlResource::Get()->LoadBitmap(wxT("fill16")), wxNullBitmap, wxITEM_NORMAL, _("Fill the whole layer with the selected tile."), wxT(""), NULL);
    
    m_toolbar492->AddTool(ERASE_ALL_TILES_TOOL_ID, _("Erase all the layer"), wxXmlResource::Get()->LoadBitmap(wxT("delete16")), wxNullBitmap, wxITEM_NORMAL, _("Delete all the tiles from the current layer."), wxT(""), NULL);
    
    m_toolbar492->AddSeparator();
    m_toolbar492->Realize();
    
    m_mainPanelToolbar = new wxToolBar(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_FLAT);
    m_mainPanelToolbar->SetToolBitmapSize(wxSize(16,16));
    
    flexGridSizer490->Add(m_mainPanelToolbar, 0, wxALL|wxEXPAND, 0);
    
    m_mainPanelToolbar->AddTool(CHANGE_MAP_SIZE_TOOL_ID, _("Change map size"), wxXmlResource::Get()->LoadBitmap(wxT("options16")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainPanelToolbar->AddSeparator();
    
    m_staticText355 = new wxStaticText(m_mainPanelToolbar, wxID_ANY, _("Current layer:"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_mainPanelToolbar->AddControl(m_staticText355);
    
    wxArrayString m_layerChoiceArr;
    m_layerChoiceArr.Add(wxT("Back"));
    m_layerChoiceArr.Add(wxT("Middle"));
    m_layerChoiceArr.Add(wxT("Top"));
    m_layerChoice = new wxChoice(m_mainPanelToolbar, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_layerChoiceArr, 0);
    m_layerChoice->SetSelection(0);
    m_mainPanelToolbar->AddControl(m_layerChoice);
    
    m_mainPanelToolbar->AddSeparator();
    
    m_mainPanelToolbar->AddTool(HIDE_UPPER_LAYERS_TOOL_ID, _("Hide upper layers"), wxXmlResource::Get()->LoadBitmap(wxT("layer16")), wxNullBitmap, wxITEM_CHECK, wxT(""), wxT(""), NULL);
    m_mainPanelToolbar->Realize();
    
    wxFlexGridSizer* flexGridSizer7 = new wxFlexGridSizer(4, 1, 0, 0);
    flexGridSizer7->SetFlexibleDirection( wxBOTH );
    flexGridSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer7->AddGrowableCol(0);
    flexGridSizer7->AddGrowableRow(0);
    
    flexGridSizer200->Add(flexGridSizer7, 1, wxALL|wxEXPAND, 5);
    
    m_tileMapPanel = new TileMapPanel(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxFULL_REPAINT_ON_RESIZE|wxHSCROLL|wxVSCROLL);
    m_tileMapPanel->SetScrollRate(5, 5);
    
    flexGridSizer7->Add(m_tileMapPanel, 0, wxALL|wxEXPAND, 5);
    
    m_staticText448 = new wxStaticText(m_mainPanel, wxID_ANY, _("Use left mouse click to add the current tile and right click to remove it."), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer7->Add(m_staticText448, 0, wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer452 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer452->SetFlexibleDirection( wxBOTH );
    flexGridSizer452->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer452->AddGrowableCol(1);
    flexGridSizer452->AddGrowableRow(0);
    
    flexGridSizer200->Add(flexGridSizer452, 1, wxALL|wxEXPAND, 0);
    
    m_staticBitmap456 = new wxStaticBitmap(m_mainPanel, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("help16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    flexGridSizer452->Add(m_staticBitmap456, 0, wxALL|wxEXPAND, 5);
    
    m_hyperLink454 = new wxHyperlinkCtrl(m_mainPanel, wxID_ANY, _("Help about this object"), wxT(""), wxDefaultPosition, wxSize(-1,-1), wxHL_DEFAULT_STYLE);
    m_hyperLink454->SetNormalColour(wxColour(wxT("#0000FF")));
    m_hyperLink454->SetHoverColour(wxColour(wxT("#0000FF")));
    m_hyperLink454->SetVisitedColour(wxColour(wxT("#FF0000")));
    
    flexGridSizer452->Add(m_hyperLink454, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_stdBtnSizer60 = new wxStdDialogButtonSizer();
    
    flexGridSizer452->Add(m_stdBtnSizer60, 0, wxALL|wxEXPAND, 5);
    
    m_button62 = new wxButton(m_mainPanel, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer60->AddButton(m_button62);
    
    m_button64 = new wxButton(m_mainPanel, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer60->AddButton(m_button64);
    m_stdBtnSizer60->Realize();
    
    SetMinSize( wxSize(950,550) );
    SetSizeHints(950,550);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(TileMapObjectEditorBase::OnCloseButtonClicked), NULL, this);
    this->Connect(CONFIGURE_TILESET_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileSetConfigureButtonClicked), NULL, this);
    this->Connect(EDIT_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileEditToolClicked), NULL, this);
    this->Connect(MODE_SINGLE_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileInsertionModeChanged), NULL, this);
    this->Connect(MODE_RECTANGLE_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileInsertionModeChanged), NULL, this);
    this->Connect(FILL_WITH_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnFillLayerToolClicked), NULL, this);
    this->Connect(ERASE_ALL_TILES_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnClearLayerToolClicked), NULL, this);
    this->Connect(CHANGE_MAP_SIZE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnChangeMapSizeButtonClicked), NULL, this);
    m_layerChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(TileMapObjectEditorBase::OnLayerChoiceChanged), NULL, this);
    this->Connect(HIDE_UPPER_LAYERS_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnHideUpperLayerChecked), NULL, this);
    m_hyperLink454->Connect(wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler(TileMapObjectEditorBase::OnHelpButtonClicked), NULL, this);
    m_button62->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnOkButtonPressed), NULL, this);
    m_button64->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnCancelButtonPressed), NULL, this);
    
}

TileMapObjectEditorBase::~TileMapObjectEditorBase()
{
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(TileMapObjectEditorBase::OnCloseButtonClicked), NULL, this);
    this->Disconnect(CONFIGURE_TILESET_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileSetConfigureButtonClicked), NULL, this);
    this->Disconnect(EDIT_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileEditToolClicked), NULL, this);
    this->Disconnect(MODE_SINGLE_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileInsertionModeChanged), NULL, this);
    this->Disconnect(MODE_RECTANGLE_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnTileInsertionModeChanged), NULL, this);
    this->Disconnect(FILL_WITH_TILE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnFillLayerToolClicked), NULL, this);
    this->Disconnect(ERASE_ALL_TILES_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnClearLayerToolClicked), NULL, this);
    this->Disconnect(CHANGE_MAP_SIZE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnChangeMapSizeButtonClicked), NULL, this);
    m_layerChoice->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(TileMapObjectEditorBase::OnLayerChoiceChanged), NULL, this);
    this->Disconnect(HIDE_UPPER_LAYERS_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnHideUpperLayerChecked), NULL, this);
    m_hyperLink454->Disconnect(wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler(TileMapObjectEditorBase::OnHelpButtonClicked), NULL, this);
    m_button62->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnOkButtonPressed), NULL, this);
    m_button64->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapObjectEditorBase::OnCancelButtonPressed), NULL, this);
    
    m_auimgr178->UnInit();
    delete m_auimgr178;

}

TileSetConfigurationEditorBase::TileSetConfigurationEditorBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCF6DCInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    m_auimgr = new wxAuiManager;
    m_auimgr->SetManagedWindow( this );
    m_auimgr->SetFlags( wxAUI_MGR_LIVE_RESIZE|wxAUI_MGR_TRANSPARENT_HINT|wxAUI_MGR_TRANSPARENT_DRAG|wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_ALLOW_FLOATING);
    m_auimgr->GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, wxAUI_GRADIENT_NONE);
    
    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    m_auimgr->AddPane(m_mainPanel, wxAuiPaneInfo().Name(wxT("MAINPANEL")).Direction(wxAUI_DOCK_CENTER).Layer(0).Row(0).Position(0).BestSize(100,100).MinSize(100,100).MaxSize(100,100).Fixed().CaptionVisible(false).MaximizeButton(false).CloseButton(false).MinimizeButton(false).PinButton(false));
    m_auimgr->Update();
    
    wxFlexGridSizer* flexGridSizer2671 = new wxFlexGridSizer(0, 1, 0, 0);
    flexGridSizer2671->SetFlexibleDirection( wxBOTH );
    flexGridSizer2671->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer2671->AddGrowableCol(0);
    flexGridSizer2671->AddGrowableRow(2);
    m_mainPanel->SetSizer(flexGridSizer2671);
    
    m_staticText335 = new wxStaticText(m_mainPanel, wxID_ANY, _("The tileset is the texture containing all the tiles which will be used in your tilemap object."), wxDefaultPosition, wxSize(-1,-1), 0);
    wxFont m_staticText335Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText335Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText335->SetFont(m_staticText335Font);
    
    flexGridSizer2671->Add(m_staticText335, 0, wxALL, 5);
    
    m_staticText337 = new wxStaticText(m_mainPanel, wxID_ANY, _("Note: the tilemap object needs to have all the tiles in a single texture."), wxDefaultPosition, wxSize(-1,-1), 0);
    wxFont m_staticText337Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText337Font.SetStyle(wxFONTSTYLE_ITALIC);
    m_staticText337->SetFont(m_staticText337Font);
    
    flexGridSizer2671->Add(m_staticText337, 0, wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer2692 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer2692->SetFlexibleDirection( wxBOTH );
    flexGridSizer2692->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer2692->AddGrowableCol(1);
    flexGridSizer2692->AddGrowableRow(3);
    
    flexGridSizer2671->Add(flexGridSizer2692, 1, wxALL|wxEXPAND, 5);
    
    m_staticText287 = new wxStaticText(m_mainPanel, wxID_ANY, _("Tileset texture:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer2692->Add(m_staticText287, 0, wxALL|wxALIGN_CENTER|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxFlexGridSizer* flexGridSizer295 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer295->SetFlexibleDirection( wxBOTH );
    flexGridSizer295->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer295->AddGrowableCol(0);
    flexGridSizer295->AddGrowableRow(0);
    
    flexGridSizer2692->Add(flexGridSizer295, 1, wxALL|wxEXPAND, 5);
    
    m_textureNameTextCtrl = new wxTextCtrl(m_mainPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer295->Add(m_textureNameTextCtrl, 0, wxALL|wxEXPAND, 5);
    
    m_setTextureButton = new wxBitmapButton(m_mainPanel, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("image16")), wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
    
    flexGridSizer295->Add(m_setTextureButton, 0, wxALL, 5);
    
    m_staticText301 = new wxStaticText(m_mainPanel, wxID_ANY, _("Tile size:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer2692->Add(m_staticText301, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxFlexGridSizer* flexGridSizer303 = new wxFlexGridSizer(1, 4, 0, 0);
    flexGridSizer303->SetFlexibleDirection( wxBOTH );
    flexGridSizer303->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer303->AddGrowableCol(0);
    flexGridSizer303->AddGrowableCol(2);
    flexGridSizer303->AddGrowableRow(0);
    
    flexGridSizer2692->Add(flexGridSizer303, 1, wxALL|wxEXPAND, 5);
    
    m_tileWidthSpin = new wxSpinCtrl(m_mainPanel, wxID_ANY, wxT("24"), wxDefaultPosition, wxSize(-1,-1), wxSP_ARROW_KEYS);
    m_tileWidthSpin->SetRange(1, 10000);
    m_tileWidthSpin->SetValue(24);
    
    flexGridSizer303->Add(m_tileWidthSpin, 0, wxALL|wxEXPAND, 5);
    
    m_staticText307 = new wxStaticText(m_mainPanel, wxID_ANY, _("x"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer303->Add(m_staticText307, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_tileHeightSpin = new wxSpinCtrl(m_mainPanel, wxID_ANY, wxT("24"), wxDefaultPosition, wxSize(-1,-1), wxSP_ARROW_KEYS);
    m_tileHeightSpin->SetRange(1, 10000);
    m_tileHeightSpin->SetValue(24);
    
    flexGridSizer303->Add(m_tileHeightSpin, 0, wxALL|wxEXPAND, 5);
    
    m_staticText311 = new wxStaticText(m_mainPanel, wxID_ANY, _("pixels"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer303->Add(m_staticText311, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticText313 = new wxStaticText(m_mainPanel, wxID_ANY, _("Tile spacing:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer2692->Add(m_staticText313, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxFlexGridSizer* flexGridSizer317 = new wxFlexGridSizer(1, 4, 0, 0);
    flexGridSizer317->SetFlexibleDirection( wxBOTH );
    flexGridSizer317->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer317->AddGrowableCol(0);
    flexGridSizer317->AddGrowableCol(2);
    flexGridSizer317->AddGrowableRow(0);
    
    flexGridSizer2692->Add(flexGridSizer317, 1, wxALL|wxEXPAND, 5);
    
    m_spacingWidthSpin = new wxSpinCtrl(m_mainPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(-1,-1), wxSP_ARROW_KEYS);
    m_spacingWidthSpin->SetRange(0, 10000);
    m_spacingWidthSpin->SetValue(0);
    
    flexGridSizer317->Add(m_spacingWidthSpin, 0, wxALL|wxEXPAND, 5);
    
    m_staticText325 = new wxStaticText(m_mainPanel, wxID_ANY, _("x"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer317->Add(m_staticText325, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_spacingHeightSpin = new wxSpinCtrl(m_mainPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(-1,-1), wxSP_ARROW_KEYS);
    m_spacingHeightSpin->SetRange(0, 10000);
    m_spacingHeightSpin->SetValue(0);
    
    flexGridSizer317->Add(m_spacingHeightSpin, 0, wxALL|wxEXPAND, 5);
    
    m_staticText329 = new wxStaticText(m_mainPanel, wxID_ANY, _("pixels"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer317->Add(m_staticText329, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticText462 = new wxStaticText(m_mainPanel, wxID_ANY, _("Preview:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer2692->Add(m_staticText462, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_tileSetPreviewPanel = new TileSetPanel(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxHSCROLL|wxVSCROLL);
    m_tileSetPreviewPanel->SetScrollRate(5, 5);
    
    flexGridSizer2692->Add(m_tileSetPreviewPanel, 0, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer468 = new wxFlexGridSizer(1, 3, 0, 0);
    flexGridSizer468->SetFlexibleDirection( wxBOTH );
    flexGridSizer468->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer468->AddGrowableCol(2);
    flexGridSizer468->AddGrowableRow(0);
    
    flexGridSizer2671->Add(flexGridSizer468, 1, wxALL|wxEXPAND, 0);
    
    m_staticBitmap470 = new wxStaticBitmap(m_mainPanel, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("help16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    flexGridSizer468->Add(m_staticBitmap470, 0, wxALL, 5);
    
    m_hyperLink472 = new wxHyperlinkCtrl(m_mainPanel, wxID_ANY, _("Help on this dialog"), wxT(""), wxDefaultPosition, wxSize(-1,-1), wxHL_DEFAULT_STYLE);
    m_hyperLink472->SetNormalColour(wxColour(wxT("#0000FF")));
    m_hyperLink472->SetHoverColour(wxColour(wxT("#0000FF")));
    m_hyperLink472->SetVisitedColour(wxColour(wxT("#FF0000")));
    
    flexGridSizer468->Add(m_hyperLink472, 0, wxALL, 5);
    
    m_stdBtnSizer2713 = new wxStdDialogButtonSizer();
    
    flexGridSizer468->Add(m_stdBtnSizer2713, 0, wxALL|wxALIGN_RIGHT, 5);
    
    m_okButton = new wxButton(m_mainPanel, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer2713->AddButton(m_okButton);
    
    m_cancelButton = new wxButton(m_mainPanel, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer2713->AddButton(m_cancelButton);
    m_stdBtnSizer2713->Realize();
    
    SetSizeHints(750,500);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_textureNameTextCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnTileSetTextureUpdated), NULL, this);
    m_setTextureButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnSetTextureButtonClicked), NULL, this);
    m_tileWidthSpin->Connect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_tileHeightSpin->Connect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_spacingWidthSpin->Connect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_spacingHeightSpin->Connect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_hyperLink472->Connect(wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler(TileSetConfigurationEditorBase::OnHelpButtonClicked), NULL, this);
    m_okButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnOkButtonClicked), NULL, this);
    m_cancelButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnCancelButtonClicked), NULL, this);
    
}

TileSetConfigurationEditorBase::~TileSetConfigurationEditorBase()
{
    m_textureNameTextCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnTileSetTextureUpdated), NULL, this);
    m_setTextureButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnSetTextureButtonClicked), NULL, this);
    m_tileWidthSpin->Disconnect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_tileHeightSpin->Disconnect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_spacingWidthSpin->Disconnect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_spacingHeightSpin->Disconnect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(TileSetConfigurationEditorBase::OnTileSetParameterUpdated), NULL, this);
    m_hyperLink472->Disconnect(wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler(TileSetConfigurationEditorBase::OnHelpButtonClicked), NULL, this);
    m_okButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnOkButtonClicked), NULL, this);
    m_cancelButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileSetConfigurationEditorBase::OnCancelButtonClicked), NULL, this);
    
    m_auimgr->UnInit();
    delete m_auimgr;

}

TileMapConfigurationEditorBase::TileMapConfigurationEditorBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCF6DCInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxFlexGridSizer* flexGridSizer367 = new wxFlexGridSizer(0, 1, 0, 0);
    flexGridSizer367->SetFlexibleDirection( wxBOTH );
    flexGridSizer367->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer367->AddGrowableCol(0);
    flexGridSizer367->AddGrowableRow(0);
    this->SetSizer(flexGridSizer367);
    
    wxFlexGridSizer* flexGridSizer369 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer369->SetFlexibleDirection( wxBOTH );
    flexGridSizer369->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer369->AddGrowableCol(1);
    
    flexGridSizer367->Add(flexGridSizer369, 1, wxALL|wxEXPAND, 5);
    
    m_staticText378 = new wxStaticText(this, wxID_ANY, _("Map size:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer369->Add(m_staticText378, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxFlexGridSizer* flexGridSizer380 = new wxFlexGridSizer(1, 4, 0, 0);
    flexGridSizer380->SetFlexibleDirection( wxBOTH );
    flexGridSizer380->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer380->AddGrowableCol(0);
    flexGridSizer380->AddGrowableCol(2);
    
    flexGridSizer369->Add(flexGridSizer380, 1, wxALL|wxEXPAND, 5);
    
    m_mapWidthSpin = new wxSpinCtrl(this, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize(-1,-1), wxSP_ARROW_KEYS);
    m_mapWidthSpin->SetRange(1, 100000);
    m_mapWidthSpin->SetValue(10);
    
    flexGridSizer380->Add(m_mapWidthSpin, 0, wxALL|wxEXPAND, 5);
    
    m_staticText384 = new wxStaticText(this, wxID_ANY, _("x"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer380->Add(m_staticText384, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_mapHeightSpin = new wxSpinCtrl(this, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize(-1,-1), wxSP_ARROW_KEYS);
    m_mapHeightSpin->SetRange(1, 100000);
    m_mapHeightSpin->SetValue(5);
    
    flexGridSizer380->Add(m_mapHeightSpin, 0, wxALL|wxEXPAND, 5);
    
    m_staticText388 = new wxStaticText(this, wxID_ANY, _("tiles"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer380->Add(m_staticText388, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    wxFlexGridSizer* flexGridSizer474 = new wxFlexGridSizer(1, 3, 0, 0);
    flexGridSizer474->SetFlexibleDirection( wxBOTH );
    flexGridSizer474->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer474->AddGrowableCol(2);
    flexGridSizer474->AddGrowableRow(0);
    
    flexGridSizer367->Add(flexGridSizer474, 1, wxALL|wxEXPAND, 0);
    
    m_staticBitmap476 = new wxStaticBitmap(this, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("help16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    flexGridSizer474->Add(m_staticBitmap476, 0, wxALL, 5);
    
    m_hyperLink478 = new wxHyperlinkCtrl(this, wxID_ANY, _("Help on this dialog"), wxT(""), wxDefaultPosition, wxSize(-1,-1), wxHL_DEFAULT_STYLE);
    m_hyperLink478->SetNormalColour(wxColour(wxT("#0000FF")));
    m_hyperLink478->SetHoverColour(wxColour(wxT("#0000FF")));
    m_hyperLink478->SetVisitedColour(wxColour(wxT("#FF0000")));
    
    flexGridSizer474->Add(m_hyperLink478, 0, wxALL, 5);
    
    m_stdBtnSizer371 = new wxStdDialogButtonSizer();
    
    flexGridSizer474->Add(m_stdBtnSizer371, 0, wxALL|wxEXPAND, 5);
    
    m_okButton = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer371->AddButton(m_okButton);
    
    m_cancelButton = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer371->AddButton(m_cancelButton);
    m_stdBtnSizer371->Realize();
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_hyperLink478->Connect(wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler(TileMapConfigurationEditorBase::OnHelpButtonClicked), NULL, this);
    m_okButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapConfigurationEditorBase::OnOkPressed), NULL, this);
    m_cancelButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapConfigurationEditorBase::OnCancelPressed), NULL, this);
    
}

TileMapConfigurationEditorBase::~TileMapConfigurationEditorBase()
{
    m_hyperLink478->Disconnect(wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler(TileMapConfigurationEditorBase::OnHelpButtonClicked), NULL, this);
    m_okButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapConfigurationEditorBase::OnOkPressed), NULL, this);
    m_cancelButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TileMapConfigurationEditorBase::OnCancelPressed), NULL, this);
    
}

TileEditorBase::TileEditorBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCF6DCInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxFlexGridSizer* flexGridSizer398 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer398->SetFlexibleDirection( wxBOTH );
    flexGridSizer398->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer398->AddGrowableCol(0);
    flexGridSizer398->AddGrowableRow(1);
    this->SetSizer(flexGridSizer398);
    
    wxFlexGridSizer* flexGridSizer416 = new wxFlexGridSizer(1, 2, 0, 0);
    flexGridSizer416->SetFlexibleDirection( wxBOTH );
    flexGridSizer416->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer416->AddGrowableCol(1);
    flexGridSizer416->AddGrowableRow(0);
    
    flexGridSizer398->Add(flexGridSizer416, 1, wxALL|wxEXPAND, 0);
    
    m_mainToolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_FLAT);
    m_mainToolbar->SetToolBitmapSize(wxSize(16,16));
    
    flexGridSizer416->Add(m_mainToolbar, 0, wxALL|wxEXPAND, 0);
    
    m_mainToolbar->AddTool(COLLIDABLE_TOOL_ID, _("Collidable"), wxXmlResource::Get()->LoadBitmap(wxT("pathfindingobstacleicon16")), wxNullBitmap, wxITEM_CHECK, _("Activates the collision mask for collision detection"), wxT(""), NULL);
    
    m_mainToolbar->AddTool(PREDEFINED_SHAPE_TOOL_ID, _("Predefined shape"), wxXmlResource::Get()->LoadBitmap(wxT("tilemasktrianglebr16")), wxNullBitmap, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
    
    m_mainToolbar->AddSeparator();
    m_mainToolbar->Realize();
    
    m_toolbar418 = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTB_NODIVIDER|wxTB_FLAT);
    m_toolbar418->SetToolBitmapSize(wxSize(16,16));
    
    flexGridSizer416->Add(m_toolbar418, 0, wxALL, 0);
    
    m_toolbar418->AddTool(ADD_POINT_TOOL_ID, _("Add a point"), wxXmlResource::Get()->LoadBitmap(wxT("add16")), wxNullBitmap, wxITEM_NORMAL, _("Add a point to the collision mask"), wxT(""), NULL);
    
    m_toolbar418->AddTool(EDIT_POINT_TOOL_ID, _("Edit point position..."), wxXmlResource::Get()->LoadBitmap(wxT("edit16")), wxNullBitmap, wxITEM_NORMAL, _("Edit the selected point position..."), wxT(""), NULL);
    
    m_toolbar418->AddTool(REMOVE_POINT_TOOL_ID, _("Remove selected point"), wxXmlResource::Get()->LoadBitmap(wxT("remove16")), wxNullBitmap, wxITEM_NORMAL, _("Removes the selected point"), wxT(""), NULL);
    m_toolbar418->Realize();
    
    m_tilePreviewPanel = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxFULL_REPAINT_ON_RESIZE|wxHSCROLL|wxVSCROLL);
    m_tilePreviewPanel->SetScrollRate(5, 5);
    
    flexGridSizer398->Add(m_tilePreviewPanel, 0, wxALL|wxEXPAND, 5);
    m_tilePreviewPanel->SetMinSize(wxSize(100,100));
    
    SetMinSize( wxSize(200,200) );
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    this->Connect(COLLIDABLE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnCollidableToolToggled), NULL, this);
    this->Connect(PREDEFINED_SHAPE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnPredefinedShapeToolClicked), NULL, this);
    this->Connect(ADD_POINT_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnAddPointToolClicked), NULL, this);
    this->Connect(EDIT_POINT_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnEditPointToolClicked), NULL, this);
    this->Connect(REMOVE_POINT_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnRemovePointToolClicked), NULL, this);
    m_tilePreviewPanel->Connect(wxEVT_PAINT, wxPaintEventHandler(TileEditorBase::OnPreviewPaint), NULL, this);
    m_tilePreviewPanel->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(TileEditorBase::OnPreviewErase), NULL, this);
    m_tilePreviewPanel->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(TileEditorBase::OnPreviewLeftDown), NULL, this);
    m_tilePreviewPanel->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(TileEditorBase::OnPreviewLeftUp), NULL, this);
    m_tilePreviewPanel->Connect(wxEVT_MOTION, wxMouseEventHandler(TileEditorBase::OnPreviewMotion), NULL, this);
    
}

TileEditorBase::~TileEditorBase()
{
    this->Disconnect(COLLIDABLE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnCollidableToolToggled), NULL, this);
    this->Disconnect(PREDEFINED_SHAPE_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnPredefinedShapeToolClicked), NULL, this);
    this->Disconnect(ADD_POINT_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnAddPointToolClicked), NULL, this);
    this->Disconnect(EDIT_POINT_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnEditPointToolClicked), NULL, this);
    this->Disconnect(REMOVE_POINT_TOOL_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TileEditorBase::OnRemovePointToolClicked), NULL, this);
    m_tilePreviewPanel->Disconnect(wxEVT_PAINT, wxPaintEventHandler(TileEditorBase::OnPreviewPaint), NULL, this);
    m_tilePreviewPanel->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(TileEditorBase::OnPreviewErase), NULL, this);
    m_tilePreviewPanel->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(TileEditorBase::OnPreviewLeftDown), NULL, this);
    m_tilePreviewPanel->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(TileEditorBase::OnPreviewLeftUp), NULL, this);
    m_tilePreviewPanel->Disconnect(wxEVT_MOTION, wxMouseEventHandler(TileEditorBase::OnPreviewMotion), NULL, this);
    
}
