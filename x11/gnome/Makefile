# $NetBSD: Makefile,v 1.4 2000/03/16 22:25:29 tron Exp $

DISTNAME=	gnome-1.0.53.3
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	control-center>=1.0.51:../controlcenter
DEPENDS+=	ee>=0.3.11:../../graphics/ee
DEPENDS+=	gdm>=2.0b4:../gdm
DEPENDS+=	glade>=0.5.3:../../devel/glade
DEPENDS+=	gmc>=4.5.42:../../sysutils/gmc
DEPENDS+=	gnome-audio>=1.0.0:../../audio/gnome-audio
DEPENDS+=	gnome-chess>=0.2.4:../../games/gnome-chess
DEPENDS+=	gnome-games>=1.0.51:../../games/gnome-games
DEPENDS+=	gnome-media>=1.0.51:../../audio/gnome-media
DEPENDS+=	gnome-pim>=1.0.55:../../misc/gnome-pim
DEPENDS+=	gnome-python>=1.0.51:../gnome-python
DEPENDS+=	gnome-users-guide>=1.0.72:../gnome-users-guide
DEPENDS+=	gnome-utils>=1.0.51:../../misc/gnome-utils
DEPENDS+=	gnumeric>=0.48:../../math/gnumeric
DEPENDS+=	gtk-->=1.0.3:../gtk--
DEPENDS+=	gtk-engines>=0.8:../gtk-engines
DEPENDS+=	xchat>=1.4.1:../../net/xchat

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
