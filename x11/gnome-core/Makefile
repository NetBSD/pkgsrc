# $NetBSD: Makefile,v 1.7 1999/01/30 23:18:56 agc Exp $
#

DISTNAME=	gnome-core-0.99.3.1
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.gnome.org/pub/GNOME/sources/gnome-libs/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/gnome-libs/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs-0.99.3:../../x11/gnome-libs
DEPENDS+=	libgtop-0.99.2:../../devel/libgtop

CONFLICTS=	gnome-core-*

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

LOCALSTATEDIR=	/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE} \
			--with-catgets
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
