# $NetBSD: Makefile,v 1.5 1999/01/16 05:39:42 tron Exp $
#

DISTNAME=	gnome-core-0.99.3.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/sources/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs-0.99.3:../../x11/gnome-libs
DEPENDS+=	libgtop-0.99.2:../../devel/libgtop

CONFLICTS=	gnome-core-*

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

LOCALSTATEDIR=	/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE} \
			--with-catgets
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
