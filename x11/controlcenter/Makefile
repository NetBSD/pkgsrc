# $NetBSD: Makefile,v 1.1.1.1 1999/04/01 05:43:46 garbled Exp $
#

DISTNAME=	control-center-1.0.4
CATEGORIES=	x11 gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.circ.us.eu.org/mirrors/ftp.gnome.org/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/control-center/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-1.0.3:../../x11/gnome-core
DEPENDS+=	xscreensaver-3.07:../../x11/xscreensaver

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

LOCALSTATEDIR=	/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
