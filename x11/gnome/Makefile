# $NetBSD: Makefile,v 1.16 2000/11/26 07:39:30 rh Exp $

DISTNAME=	gnome-1.2.4
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	control-center>=1.2.2:../controlcenter
DEPENDS+=	ee>=0.3.12:../../graphics/ee
DEPENDS+=	gdm>=2.0b4:../gdm
DEPENDS+=	ggv>=0.95:../../print/ggv
DEPENDS+=	glade>=0.5.3:../../devel/glade
DEPENDS+=	gmc>=4.5.42:../../sysutils/gmc
DEPENDS+=	gnome-applets>=1.2.1:../gnome-applets
DEPENDS+=	gnome-audio>=1.0.0:../../audio/gnome-audio
DEPENDS+=	gnome-chess>=0.2.4:../../games/gnome-chess
DEPENDS+=	gnome-games>=1.0.51:../../games/gnome-games
DEPENDS+=	gnome-media>=1.0.51:../../audio/gnome-media
DEPENDS+=	gnome-pim>=1.0.55:../../misc/gnome-pim
DEPENDS+=	gnome-python>=1.0.51:../gnome-python
DEPENDS+=	gnome-users-guide>=1.2:../gnome-users-guide
DEPENDS+=	gnome-utils>=1.0.51:../../misc/gnome-utils
DEPENDS+=	gnumeric>=0.59:../../math/gnumeric
DEPENDS+=	gtk-->=1.0.3:../gtk--
DEPENDS+=	gtk-engines>=0.8:../gtk-engines
DEPENDS+=	gtop>=1.0.9:../../sysutils/gtop
DEPENDS+=	xchat>=1.5.6:../../net/xchat

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
