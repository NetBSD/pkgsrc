# $NetBSD: Makefile,v 1.15 1999/11/08 21:50:39 tron Exp $

DISTNAME=		control-center-1.0.51
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-core-*:../../x11/gnome-core
DEPENDS+=		xscreensaver-3.*:../../x11/xscreensaver

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
