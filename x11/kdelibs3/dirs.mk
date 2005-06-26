# $NetBSD: dirs.mk,v 1.7 2005/06/26 23:46:11 markd Exp $
#

.if !defined(DIRS_KDE3_MK)
DIRS_KDE3_MK=	#defined

KDE3_DIRS=	include/dom
KDE3_DIRS+=	include/kabc
KDE3_DIRS+=	include/kate
KDE3_DIRS+=	include/kparts
KDE3_DIRS+=	lib/kconf_update_bin
KDE3_DIRS+=	lib/kde3
KDE3_DIRS+=	lib/kde3/plugins
KDE3_DIRS+=	lib/kde3/plugins/designer
KDE3_DIRS+=	lib/kde3/plugins/styles
KDE3_DIRS+=	share/applications/kde
KDE3_DIRS+=	share/doc/kde
KDE3_DIRS+=	share/doc/kde/HTML
KDE3_DIRS+=	share/doc/kde/HTML/en
KDE3_DIRS+=	share/doc/kde/HTML/en/common
KDE3_DIRS+=	share/doc/kde/HTML/en/kcontrol
KDE3_DIRS+=	share/doc/kde/HTML/en/kinfocenter

_LANGS= cs da de en_GB es et eu fi fr he hr hu it ja nl pt pt_BR \
	ro ru sk sl sr sv tr uk zh_CN zh_TW
.for dir in ${_LANGS}
KDE3_DIRS+=	share/doc/kde/HTML/${dir}
.endfor

KDE3_DIRS+=	share/kde
KDE3_DIRS+=	share/kde/applnk
KDE3_DIRS+=	share/kde/applnk/.hidden
KDE3_DIRS+=	share/kde/applnk/Applications
KDE3_DIRS+=	share/kde/applnk/Development
KDE3_DIRS+=	share/kde/applnk/Editors
KDE3_DIRS+=	share/kde/applnk/Graphics
KDE3_DIRS+=	share/kde/applnk/Internet
KDE3_DIRS+=	share/kde/applnk/Settings
KDE3_DIRS+=	share/kde/applnk/Settingsmenu
KDE3_DIRS+=	share/kde/applnk/System
KDE3_DIRS+=	share/kde/applnk/System/ScreenSavers
KDE3_DIRS+=	share/kde/applnk/Toys
KDE3_DIRS+=	share/kde/applnk/Utilities
KDE3_DIRS+=	share/kde/apps
KDE3_DIRS+=	share/kde/apps/kabc
KDE3_DIRS+=	share/kde/apps/kabc/formats
KDE3_DIRS+=	share/kde/apps/kaddressbook
KDE3_DIRS+=	share/kde/apps/kate
KDE3_DIRS+=	share/kde/apps/kate/plugins
KDE3_DIRS+=	share/kde/apps/kate/scripts
KDE3_DIRS+=	share/kde/apps/katepart
KDE3_DIRS+=	share/kde/apps/katepart/syntax
KDE3_DIRS+=	share/kde/apps/kcm_componentchooser
KDE3_DIRS+=	share/kde/apps/kconf_update
KDE3_DIRS+=	share/kde/apps/kcontrol
KDE3_DIRS+=	share/kde/apps/kcontrol/pics
KDE3_DIRS+=	share/kde/apps/kdeprint
KDE3_DIRS+=	share/kde/apps/kdesktop
KDE3_DIRS+=	share/kde/apps/kdesktop/programs
KDE3_DIRS+=	share/kde/apps/khangman
KDE3_DIRS+=	share/kde/apps/khangman/data
KDE3_DIRS+=	share/kde/apps/khtml
KDE3_DIRS+=	share/kde/apps/khtml/kpartplugins
KDE3_DIRS+=	share/kde/apps/kicker
KDE3_DIRS+=	share/kde/apps/kicker/applets
KDE3_DIRS+=	share/kde/apps/kicker/extensions
KDE3_DIRS+=	share/kde/apps/klettres
KDE3_DIRS+=	share/kde/apps/konqsidebartng
KDE3_DIRS+=	share/kde/apps/konqsidebartng/virtual_folders
KDE3_DIRS+=	share/kde/apps/konqsidebartng/virtual_folders/services
KDE3_DIRS+=	share/kde/apps/konqueror
KDE3_DIRS+=	share/kde/apps/konqueror/dirtree
KDE3_DIRS+=	share/kde/apps/konqueror/dirtree/remote
KDE3_DIRS+=	share/kde/apps/konqueror/kpartplugins
KDE3_DIRS+=	share/kde/apps/konqueror/servicemenus
KDE3_DIRS+=	share/kde/apps/kstyle
KDE3_DIRS+=	share/kde/apps/kstyle/themes
KDE3_DIRS+=	share/kde/apps/ktuberling
KDE3_DIRS+=	share/kde/apps/ktuberling/sounds
KDE3_DIRS+=	share/kde/apps/kturtle
KDE3_DIRS+=	share/kde/apps/kturtle/examples
KDE3_DIRS+=	share/kde/apps/kturtle/data
KDE3_DIRS+=	share/kde/apps/kwin
KDE3_DIRS+=	share/kde/apps/profiles
KDE3_DIRS+=	share/kde/apps/remoteview
KDE3_DIRS+=	share/kde/apps/zeroconf
KDE3_DIRS+=	share/kde/autostart
KDE3_DIRS+=	share/kde/config
KDE3_DIRS+=	share/kde/config/magic
KDE3_DIRS+=	share/kde/config.kcfg
KDE3_DIRS+=	share/kde/emoticons

_ICONCOLORS=     crystalsvg hicolor locolor
_ICONSIZES=      16x16 22x22 32x32 48x48 64x64 128x128 scalable
_ICONDIRS=       actions actions/kde apps devices filesystems mimetypes

KDE3_DIRS+=	share/kde/icons
.for color in ${_ICONCOLORS}
KDE3_DIRS+=	share/kde/icons/${color}
.  for size in ${_ICONSIZES}
KDE3_DIRS+=	share/kde/icons/${color}/${size}
.    for dir in ${_ICONDIRS}
KDE3_DIRS+=	share/kde/icons/${color}/${size}/${dir}
.    endfor
.  endfor
.endfor

KDE3_DIRS+=	share/kde/mimelnk
KDE3_DIRS+=	share/kde/mimelnk/all
KDE3_DIRS+=	share/kde/mimelnk/application
KDE3_DIRS+=	share/kde/mimelnk/audio
KDE3_DIRS+=	share/kde/mimelnk/fonts
KDE3_DIRS+=	share/kde/mimelnk/image
KDE3_DIRS+=	share/kde/mimelnk/inode
KDE3_DIRS+=	share/kde/mimelnk/interface
KDE3_DIRS+=	share/kde/mimelnk/media
KDE3_DIRS+=	share/kde/mimelnk/message
KDE3_DIRS+=	share/kde/mimelnk/model
KDE3_DIRS+=	share/kde/mimelnk/multipart
KDE3_DIRS+=	share/kde/mimelnk/print
KDE3_DIRS+=	share/kde/mimelnk/text
KDE3_DIRS+=	share/kde/mimelnk/uri
KDE3_DIRS+=	share/kde/mimelnk/video
KDE3_DIRS+=	share/kde/services
KDE3_DIRS+=	share/kde/services/kaddressbook
KDE3_DIRS+=	share/kde/services/kconfiguredialog
KDE3_DIRS+=	share/kde/services/kded
KDE3_DIRS+=	share/kde/services/kresources
KDE3_DIRS+=	share/kde/services/kresources/kabc
KDE3_DIRS+=	share/kde/servicetypes
KDE3_DIRS+=	share/kde/sounds
KDE3_DIRS+=	share/kde/templates
KDE3_DIRS+=	share/kde/templates/.source
KDE3_DIRS+=	share/kde/wallpapers

.for dir in ${KDE3_DIRS}
PRINT_PLIST_AWK+=       /^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in kde: " $$0; next; }
.endfor

.endif		# !defined(DIRS_KDE3_MK)
