# $NetBSD: Makefile,v 1.7 1998/12/13 21:46:52 tron Exp $
#

DISTNAME=	gnome-libs-0.30.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/sources/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	gettext-0.10:../../misc/gettext
DEPENDS+=	gtk+-1.1.3:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	imlib-1.8.1:../../graphics/imlib
DEPENDS+=	ORBit-0.3.0:../../corba/ORBit

NOT_FOR_ARCHS=	alpha	# problems with gtk

CONFLICTS=	gnome-libs-0.27

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

LOCALSTATEDIR=	/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

PLIST_SRC=	${WRKDIR}/PLIST

pre-build:
	(cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h)

post-install:
	${MKDIR} ${LOCALSTATEDIR}
	${SED} -e 's#@@LOCALSTATEDIR@@#${LOCALSTATEDIR}#' \
	    <${PKGDIR}/PLIST >${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
