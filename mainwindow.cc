/*
Compile:
g++ -c Renamer.cc
g++ -c RenamerWindow.cc -std=c++11 `pkg-config gtkmm-3.0 --cflags --libs`
g++ mainwindow.cc RenamerWindow.o Renamer.o -o Renamer-GUI `pkg-config gtkmm-3.0 --cflags --libs`

Test Run:
./Renamer-GUI
Pages: 55 23 21 19 21 22 21 20
*/

#include "RenamerWindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  RenamerWindow renamerwindow;

  //Shows the window and returns when it is closed.
  return app->run(renamerwindow);
}
