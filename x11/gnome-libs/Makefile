# $NetBSD: Makefile,v 1.10 1998/12/29 17:53:10 tron Exp $
#

DISTNAME=	gnome-libs-0.99.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/sources/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gtk+-1.1.9:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	imlib-1.8.2:../../graphics/imlib
DEPENDS+=	ORBit-0.3.90:../../corba/ORBit

NOT_FOR_ARCHS=	alpha	# problems with gtk

CONFLICTS=	gnome-libs-*

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LDFLAGS+=       	"-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

LOCALSTATEDIR=	/var/gnome

PLIST_SRC=	${WRKDIR}/PLIST

pre-build:
	(cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h)

post-install:
	${MKDIR} ${LOCALSTATEDIR}
	${SED} -e 's#@@LOCALSTATEDIR@@#${LOCALSTATEDIR}#' \
	    <${PKGDIR}/PLIST >${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
