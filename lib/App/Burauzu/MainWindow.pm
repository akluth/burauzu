#!/usr/bin/perl
package Burauzu::MainWindow;

require Exporter;
@ISA = qw(Exporter);
@EXPORT = qw(show);

use strict;
use warnings;
use Gtk3 -init;
use Gtk3::WebKit;
     

sub show
{
    my $params = shift;

    # Build a WebKit frame
    my $view = Gtk3::WebKit::WebView->new();
    $view->load_uri('http://www.google.de');
      
    my $window = Gtk3::Window->new('toplevel');
    my $scrolls = Gtk3::ScrolledWindow->new();
    $scrolls->add($view);
    $window->add($scrolls);
    $window->set_default_size(800, 600);
    $window->show_all();
    $window->signal_connect(destroy => sub { Gtk3->main_quit() });
      
    Gtk3->main();
}

sub open_page
{

}

1;
