# $NetBSD: Makefile,v 1.33 1999/10/22 07:54:17 agc Exp $
#

DISTNAME=		gnome-libs-1.0.16
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		ORBit-0.4.3:../../corba/ORBit
DEPENDS+=		imlib-1.9.4:../../graphics/imlib
DEPENDS+=		xpm-3.4k:../../graphics/xpm

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=		db-*:../../databases/db

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/db2"

pre-configure:
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure-pre-db-sub && \
		${SED} -e 's|-ldb|-ldb2|g' ${WRKSRC}/configure-pre-db-sub > ${WRKSRC}/configure && \
		${CHMOD} 0755 ${WRKSRC}/configure
.endif

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
