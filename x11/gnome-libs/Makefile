# $NetBSD: Makefile,v 1.3 1998/10/04 23:42:01 tron Exp $
#

DISTNAME=	gnome-libs-0.30.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/sources/

NOT_FOR_ARCHS=	alpha	# problems with gtk

MAINTAINER=	tron@netbsd.org

DEPENDS+=	gettext-0.10:../../misc/gettext
DEPENDS+=	gtk+-1.1.2:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	imlib-1.7:../../graphics/imlib

CONFLICTS=	gnome-libs-0.27

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--localstatedir=${X11BASE}/lib/X11/Gnome/var --with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

pre-build:
	(cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h)

.include "../../mk/bsd.pkg.mk"
