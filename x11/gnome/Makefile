# $NetBSD: Makefile,v 1.1.1.1 1999/11/20 20:45:20 tron Exp $

DISTNAME=	gnome-1.0.53
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	control-center-*:../controlcenter
DEPENDS+=	ee-*:../../graphics/ee
DEPENDS+=	gdm-*:../gdm
DEPENDS+=	glade-*:../../devel/glade
DEPENDS+=	gmc-*:../../sysutils/gmc
DEPENDS+=	gnome-audio-*:../../audio/gnome-audio
DEPENDS+=	gnome-chess-*:../../games/gnome-chess
DEPENDS+=	gnome-games-*:../../games/gnome-games
DEPENDS+=	gnome-media-*:../../audio/gnome-media
DEPENDS+=	gnome-pim-*:../../misc/gnome-pim
DEPENDS+=	gnome-python-*:../gnome-python
DEPENDS+=	gnome-users-guide-*:../gnome-users-guide
DEPENDS+=	gnome-utils-*:../../misc/gnome-utils
DEPENDS+=	gnumeric-*:../../math/gnumeric
DEPENDS+=	gtk---*:../gtk--
DEPENDS+=	gtk-engines-*:../gtk-engines
DEPENDS+=	xchat-*:../../net/xchat

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
