# $NetBSD: Makefile,v 1.23 1999/05/04 20:31:32 tron Exp $
#

DISTNAME=	gnome-libs-1.0.9
CATEGORIES=	x11 gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ORBit-0.4.3:../../corba/ORBit
DEPENDS+=	imlib-1.9.4:../../graphics/imlib
DEPENDS+=	xpm-3.4k:../../graphics/xpm

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
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
	@cd ${PREFIX}; find lib -name 'libgnome.so.*' >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

.if (${OBJECT_FMT} == a.out)
.if exists(/usr/bin/c89)
MAKE_ENV+=	A_OUT_LIBTOOL_FLAGS=--cplusplus
.else
MAKE_ENV+=	A_OUT_STATIC=-static
.endif
.endif
