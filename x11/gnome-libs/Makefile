# $NetBSD: Makefile,v 1.13 1999/01/16 03:34:56 tron Exp $
#

DISTNAME=	gnome-libs-0.99.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/sources/gnome-libs/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/gnome-libs/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	imlib-1.9.0:../../graphics/imlib
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
