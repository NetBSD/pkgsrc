# $NetBSD: Makefile,v 1.1 1998/09/04 22:14:25 agc Exp $
#

DISTNAME=	gnome-libs-0.27
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/v0.27/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/v0.27/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	gettext-0.10:../../misc/gettext
DEPENDS+=	gtk+-1.1.1:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	imlib-1.7:../../graphics/imlib

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--localstatedir=${X11BASE}/lib/X11/Gnome/var --with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

pre-build:
	(cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h)

.include "../../mk/bsd.pkg.mk"
