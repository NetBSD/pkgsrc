# $NetBSD: Makefile,v 1.12 1999/08/29 12:49:00 rh Exp $
#

DISTNAME=		control-center-1.0.6
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/control-center/}
MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/

DEPENDS=		gnome-core-1.0.9:../../x11/gnome-core \
			xscreensaver-3.17:../../x11/xscreensaver

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
