
Debian
====================
This directory contains files used to package versessd/versess-qt
for Debian-based Linux systems. If you compile versessd/versess-qt yourself, there are some useful files here.

## versess: URI support ##


versess-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install versess-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your versess-qt binary to `/usr/bin`
and the `../../share/pixmaps/versess128.png` to `/usr/share/pixmaps`

versess-qt.protocol (KDE)

