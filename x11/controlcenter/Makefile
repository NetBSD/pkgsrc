# $NetBSD: Makefile,v 1.23 2000/09/11 20:46:36 fredb Exp $

DISTNAME=		control-center-1.2.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/control-center/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-libs>=1.2.0:../../x11/gnome-libs

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS=-I${LOCALBASE}/include \
			LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/control-center/C/stylesheet-images

.include "../../mk/bsd.pkg.mk"
