#include "RenamerWindow.h"
#include "Renamer.h"
#include <iostream>
#include <string>

RenamerWindow::RenamerWindow(): m_VBox(Gtk::ORIENTATION_VERTICAL),  m_Button_Start("Start")
{
  set_size_request(300, 200);
  set_title("Renamer");

  add(m_VBox);

  m_Entry_Vol.set_max_length(5);
  m_Entry_Vol.set_text("Volume Number");
  m_Entry_Vol.select_region(0, m_Entry_Vol.get_text_length());
  m_VBox.pack_start(m_Entry_Vol);
  
  m_Entry_Chi.set_max_length(5);
  m_Entry_Chi.set_text("Fist Chapter");
  m_Entry_Chi.select_region(0, m_Entry_Chi.get_text_length());
  m_VBox.pack_start(m_Entry_Chi);
  
  m_Entry_Chf.set_max_length(5);
  m_Entry_Chf.set_text("Last Chapter");
  m_Entry_Chf.select_region(0, m_Entry_Chf.get_text_length());
  m_VBox.pack_start(m_Entry_Chf);
  
  m_Entry_Hal.set_max_length(50);
  m_Entry_Hal.set_text("Pages Separate By Space");
  m_Entry_Hal.select_region(0, m_Entry_Hal.get_text_length());
  m_VBox.pack_start(m_Entry_Hal);


  // Note that add() can also be used instead of pack_xxx()

  m_Button_Start.signal_clicked().connect( sigc::mem_fun(*this, &RenamerWindow::on_button_start));
  m_VBox.pack_start(m_Button_Start);
  m_Button_Start.set_can_default();
  m_Button_Start.grab_default();

  show_all_children();
}

RenamerWindow::~RenamerWindow()
{
}


void RenamerWindow::on_button_start()
{	
	vol = std::stoi (m_Entry_Vol.get_text(), &sz);
	chi = std::stoi (m_Entry_Chi.get_text(), &sz);
	chf = std::stoi (m_Entry_Chf.get_text(), &sz);
	hal = m_Entry_Hal.get_text();
	std::cout << hal << endl;
	Renamer renamer(vol, chi, chf);
	renamer.renames(hal);
	
}
