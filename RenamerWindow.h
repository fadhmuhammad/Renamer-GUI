#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include "Renamer.h"

class RenamerWindow : public Gtk::Window
{
public:
  RenamerWindow();
  virtual ~RenamerWindow();

protected:
  //Signal handlers:
	void on_button_start();

  //Child widgets:
	Gtk::Box m_HBox;
	Gtk::Box m_VBox;
	Gtk::Entry m_Entry_Vol;
	Gtk::Entry m_Entry_Chi;
	Gtk::Entry m_Entry_Chf;
	Gtk::Entry m_Entry_Hal;
	Gtk::Button m_Button_Start;

private:
	std::string::size_type sz;
	std::string hal;
	int vol;
	int chi;
	int chf;
};

#endif //GTKMM_EXAMPLEWINDOW_H

