# $NetBSD: Makefile,v 1.29 1999/08/22 22:02:34 tron Exp $
#

DISTNAME=		gnome-libs-1.0.10
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		ORBit-0.4.3:../../corba/ORBit
DEPENDS+=		imlib-1.9.4:../../graphics/imlib
DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha	# problems with gtk

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LDFLAGS+=       	"-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

LOCALSTATEDIR=		/var/gnome

PLIST_SRC=		${WRKDIR}/PLIST

pre-build:
	(cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h)

post-install:
	${MKDIR} ${LOCALSTATEDIR}
	${SED} -e 's#@@LOCALSTATEDIR@@#${LOCALSTATEDIR}#' \
	    <${PKGDIR}/PLIST >${PLIST_SRC}
	@cd ${PREFIX}; find lib -name 'libgnome.so.*' >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

.if (${OBJECT_FMT} == a.out)
MAKE_ENV+=	A_OUT_STATIC=-static
.endif
