# $NetBSD: Makefile,v 1.8 1999/02/19 01:29:08 tv Exp $
#

DISTNAME=	gnome-core-0.99.3.1
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.gnome.org/pub/GNOME/sources/gnome-libs/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/gnome-libs/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs-0.99.3:../../x11/gnome-libs
DEPENDS+=	libgtop-0.99.2:../../devel/libgtop

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
