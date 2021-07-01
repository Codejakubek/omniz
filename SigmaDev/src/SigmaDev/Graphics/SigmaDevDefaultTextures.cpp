////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on github repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/src/SigmaDev/Graphics/SigmaDevDefaultTextures.cpp
// Description:
// Additional Notes:


#include <SigmaDev/Graphics/SigmaDevDefaultTextures.h>

//#include <SigmaDev/Resources/Resources.h>


void SD_LoadDefaultTextureListForDefineList(/*SD_DefaultSigmaDevGUITexturePack& texture_pack*/) {

/*  
    //Order = By name
    //Button 32h (button with 32 pixel height)
    texture_pack.AddTextureDefine("button_32h_left_on_clicked");
    texture_pack.AddTextureDefine("button_32h_left_on_hover");
    texture_pack.AddTextureDefine("button_32h_left_on_normal");
    texture_pack.AddTextureDefine("button_32h_mid_on_clicked");
    texture_pack.AddTextureDefine("button_32h_mid_on_hover");
    texture_pack.AddTextureDefine("button_32h_mid_on_normal");
    texture_pack.AddTextureDefine("button_32h_right_on_clicked");
    texture_pack.AddTextureDefine("button_32h_right_on_hover");
    texture_pack.AddTextureDefine("button_32h_right_on_normal");

    //Checkbox 20h (checkbox with 20 height and width)
    texture_pack.AddTextureDefine("checkbox_20h_tick");
    texture_pack.AddTextureDefine("checkbox_20h_on_clicked");
    texture_pack.AddTextureDefine("checkbox_20h_on_hover");
    texture_pack.AddTextureDefine("checkbox_20h_on_normal");

    //Combobox
    texture_pack.AddTextureDefine("combobox_item_button_left_on_clicked");
    texture_pack.AddTextureDefine("combobox_item_button_left_on_hover");
    texture_pack.AddTextureDefine("combobox_item_button_left_on_normal");
    texture_pack.AddTextureDefine("combobox_item_button_mid_on_clicked");
    texture_pack.AddTextureDefine("combobox_item_button_mid_on_hover");
    texture_pack.AddTextureDefine("combobox_item_button_mid_on_normal");
    texture_pack.AddTextureDefine("combobox_item_button_right_on_clicked");
    texture_pack.AddTextureDefine("combobox_item_button_right_on_hover");
    texture_pack.AddTextureDefine("combobox_item_button_right_on_normal");
    texture_pack.AddTextureDefine("combobox_main_button_arrow_top_to_bottom");
    texture_pack.AddTextureDefine("combobox_main_button_left_on_clicked");
    texture_pack.AddTextureDefine("combobox_main_button_left_on_hover");
    texture_pack.AddTextureDefine("combobox_main_button_left_on_normal");
    texture_pack.AddTextureDefine("combobox_main_button_mid_on_clicked");
    texture_pack.AddTextureDefine("combobox_main_button_mid_on_hover");
    texture_pack.AddTextureDefine("combobox_main_button_mid_on_normal");
    texture_pack.AddTextureDefine("combobox_main_button_right_on_clicked");
    texture_pack.AddTextureDefine("combobox_main_button_right_on_hover");
    texture_pack.AddTextureDefine("combobox_main_button_right_on_normal");

    //Listbox_horizontal
    texture_pack.AddTextureDefine("listbox_horizontal_button_left_on_clicked");
    texture_pack.AddTextureDefine("listbox_horizontal_button_left_on_hover");
    texture_pack.AddTextureDefine("listbox_horizontal_button_left_on_normal");
    texture_pack.AddTextureDefine("listbox_horizontal_button_mid_on_clicked");
    texture_pack.AddTextureDefine("listbox_horizontal_button_mid_on_hover");
    texture_pack.AddTextureDefine("listbox_horizontal_button_mid_on_normal");
    texture_pack.AddTextureDefine("listbox_horizontal_button_right_on_clicked");
    texture_pack.AddTextureDefine("listbox_horizontal_button_right_on_hover");
    texture_pack.AddTextureDefine("listbox_horizontal_button_right_on_normal");
    texture_pack.AddTextureDefine("listbox_vertical_button_bottom_arrow");
    texture_pack.AddTextureDefine("listbox_vertical_button_bottom_on_clicked");
    texture_pack.AddTextureDefine("listbox_vertical_button_bottom_on_hover");
    texture_pack.AddTextureDefine("listbox_vertical_button_bottom_on_normal");
    texture_pack.AddTextureDefine("listbox_vertical_button_left_on_clicked");
    texture_pack.AddTextureDefine("listbox_vertical_button_left_on_hover");
    texture_pack.AddTextureDefine("listbox_vertical_button_left_on_normal");
    texture_pack.AddTextureDefine("listbox_vertical_button_mid_on_clicked");
    texture_pack.AddTextureDefine("listbox_vertical_button_mid_on_hover");
    texture_pack.AddTextureDefine("listbox_vertical_button_mid_on_normal");
    texture_pack.AddTextureDefine("listbox_vertical_button_top_arrow");
    texture_pack.AddTextureDefine("listbox_vertical_button_top_on_clicked");
    texture_pack.AddTextureDefine("listbox_vertical_button_top_on_hover");
    texture_pack.AddTextureDefine("listbox_vertical_button_top_on_normal");

    //Node
    texture_pack.AddTextureDefine("node_bg_bottom");
    texture_pack.AddTextureDefine("node_bg_bottom_left");
    texture_pack.AddTextureDefine("node_bg_bottom_right");
    texture_pack.AddTextureDefine("node_bg_left");
    texture_pack.AddTextureDefine("node_bg_right");
    texture_pack.AddTextureDefine("node_bg_mid");
    texture_pack.AddTextureDefine("node_bg_top");
    texture_pack.AddTextureDefine("node_bg_top_header_left");
    texture_pack.AddTextureDefine("node_bg_top_header_right");
    texture_pack.AddTextureDefine("node_bg_top_header_top");
    texture_pack.AddTextureDefine("node_bg_top_left");
    texture_pack.AddTextureDefine("node_bg_top_right");
    
    //Node - NodeButton
    texture_pack.AddTextureDefine("nodebutton_left_on_clicked");
    texture_pack.AddTextureDefine("nodebutton_left_on_hover");
    texture_pack.AddTextureDefine("nodebutton_left_on_normal");
    texture_pack.AddTextureDefine("nodebutton_mid_on_clicked");
    texture_pack.AddTextureDefine("nodebutton_mid_on_hover");
    texture_pack.AddTextureDefine("nodebutton_mid_on_normal");
    texture_pack.AddTextureDefine("nodebutton_right_on_clicked");
    texture_pack.AddTextureDefine("nodebutton_right_on_hover");
    texture_pack.AddTextureDefine("nodebutton_right_on_normal");

    //Node - NodeCheckbox
    texture_pack.AddTextureDefine("nodecheckbox_on_clicked");
    texture_pack.AddTextureDefine("nodecheckbox_on_hover");
    texture_pack.AddTextureDefine("nodecheckbox_on_normal");
    texture_pack.AddTextureDefine("nodecheckbox_tick");

    //Node - Connector
    texture_pack.AddTextureDefine("node_connector_active_on_clicked");
    texture_pack.AddTextureDefine("node_connector_active_on_hover");
    texture_pack.AddTextureDefine("node_connector_active_on_normal");
    texture_pack.AddTextureDefine("node_connector_inactive_on_clicked");
    texture_pack.AddTextureDefine("node_connector_inactive_on_hover");
    texture_pack.AddTextureDefine("node_connector_inactive_on_normal");
    
    //Node - NodeListBox
    texture_pack.AddTextureDefine("nodelistbox_horizontal_left_on_clicked");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_left_on_hover");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_left_on_normal");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_mid_on_clicked");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_mid_on_hover");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_mid_on_normal");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_right_on_clicked");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_right_on_hover");
    texture_pack.AddTextureDefine("nodelistbox_horizontal_right_on_normal");

    //Node - NodeProgressbar
    texture_pack.AddTextureDefine("nodeprogressbar_bg_left_on_clicked");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_left_on_hover");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_left_on_normal");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_mid_on_clicked");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_mid_on_hover");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_mid_on_normal");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_right_on_clicked");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_right_on_hover");
    texture_pack.AddTextureDefine("nodeprogressbar_bg_right_on_normal");

    //Node - NodeRadiobox
    texture_pack.AddTextureDefine("noderadiobox_tick");
    //Missing - button bg

    //Node - NodeSlider
    texture_pack.AddTextureDefine("nodeslider_slideline_left");
    texture_pack.AddTextureDefine("nodeslider_slideline_mid");
    texture_pack.AddTextureDefine("nodeslider_slideline_right");
    
    //Panel
    texture_pack.AddTextureDefine("panel_bg_bottom");
    texture_pack.AddTextureDefine("panel_bg_bottom_left");
    texture_pack.AddTextureDefine("panel_bg_bottom_right");
    texture_pack.AddTextureDefine("panel_bg_left");
    texture_pack.AddTextureDefine("panel_bg_mid");
    texture_pack.AddTextureDefine("panel_bg_right");
    texture_pack.AddTextureDefine("panel_bg_top");
    texture_pack.AddTextureDefine("panel_bg_top_left");
    texture_pack.AddTextureDefine("panel_bg_top_right");
    texture_pack.AddTextureDefine("panel_topbar_left");
    texture_pack.AddTextureDefine("panel_topbar_mid");
    texture_pack.AddTextureDefine("panel_topbar_right");


    //Progressbar
    texture_pack.AddTextureDefine("progressbar_left_on_clicked");
    texture_pack.AddTextureDefine("progressbar_left_on_hover");
    texture_pack.AddTextureDefine("progressbar_left_on_normal");
    texture_pack.AddTextureDefine("progressbar_mid_on_clicked");
    texture_pack.AddTextureDefine("progressbar_mid_on_hover");
    texture_pack.AddTextureDefine("progressbar_mid_on_normal");
    texture_pack.AddTextureDefine("progressbar_right_on_clicked");
    texture_pack.AddTextureDefine("progressbar_right_on_hover");
    texture_pack.AddTextureDefine("progressbar_right_on_normal");
    
    //Radiobox
    texture_pack.AddTextureDefine("radiobox_20h_on_clicked");
    texture_pack.AddTextureDefine("radiobox_20h_on_hover");
    texture_pack.AddTextureDefine("radiobox_20h_on_normal");
    texture_pack.AddTextureDefine("radiobox_20h_tick");

    //Slider
    texture_pack.AddTextureDefine("slider_horizontal_head_button_on_clicked");
    texture_pack.AddTextureDefine("slider_horizontal_head_button_on_hover");
    texture_pack.AddTextureDefine("slider_horizontal_head_button_on_normal");
    texture_pack.AddTextureDefine("slider_horizontal_slideline_left");
    texture_pack.AddTextureDefine("slider_horizontal_slideline_mid");
    texture_pack.AddTextureDefine("slider_horizontal_slideline_right");
        
    texture_pack.AddTextureDefine("slider_vertical_head_button_on_clicked");
    texture_pack.AddTextureDefine("slider_vertical_head_button_on_hover");
    texture_pack.AddTextureDefine("slider_vertical_head_button_on_normal");
    texture_pack.AddTextureDefine("slider_vertical_slideline_top");
    texture_pack.AddTextureDefine("slider_vertical_slideline_mid");
    texture_pack.AddTextureDefine("slider_vertical_slideline_bottom");
    
    //Textinputfield
    texture_pack.AddTextureDefine("textinputfield_bottom_left_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_bottom_left_on_hover");
    texture_pack.AddTextureDefine("textinputfield_bottom_left_on_normal");
    texture_pack.AddTextureDefine("textinputfield_bottom_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_bottom_on_hover");
    texture_pack.AddTextureDefine("textinputfield_bottom_on_normal");
    texture_pack.AddTextureDefine("textinputfield_bottom_right_on_cli+cked");
    texture_pack.AddTextureDefine("textinputfield_bottom_right_on_hover");
    texture_pack.AddTextureDefine("textinputfield_bottom_right_on_normal");
    texture_pack.AddTextureDefine("textinputfield_left_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_left_on_hover");
    texture_pack.AddTextureDefine("textinputfield_left_on_normal");
    texture_pack.AddTextureDefine("textinputfield_mid_on_normal_hover_and_clicked");
    texture_pack.AddTextureDefine("textinputfield_right_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_right_on_hover");
    texture_pack.AddTextureDefine("textinputfield_right_on_normal");
    texture_pack.AddTextureDefine("textinputfield_top_left_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_top_left_on_hover");
    texture_pack.AddTextureDefine("textinputfield_top_left_on_normal");
    texture_pack.AddTextureDefine("textinputfield_top_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_top_on_hover");
    texture_pack.AddTextureDefine("textinputfield_top_on_normal");
    texture_pack.AddTextureDefine("textinputfield_top_right_on_clicked");
    texture_pack.AddTextureDefine("textinputfield_top_right_on_hover");
    texture_pack.AddTextureDefine("textinputfield_top_right_on_normal");

    //MenuBar
    texture_pack.AddTextureDefine("top_menubar_bg");
    texture_pack.AddTextureDefine("top_menubar_button_left_on_clicked");
    texture_pack.AddTextureDefine("top_menubar_button_left_on_hover");
    texture_pack.AddTextureDefine("top_menubar_button_left_on_normal");
    texture_pack.AddTextureDefine("top_menubar_button_mid_on_clicked");
    texture_pack.AddTextureDefine("top_menubar_button_mid_on_hover");
    texture_pack.AddTextureDefine("top_menubar_button_mid_on_normal");
    texture_pack.AddTextureDefine("top_menubar_button_right_on_clicked");
    texture_pack.AddTextureDefine("top_menubar_button_right_on_hover");
    texture_pack.AddTextureDefine("top_menubar_button_right_on_normal");
*/

}
