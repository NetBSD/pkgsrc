# $NetBSD: Makefile,v 1.40 2000/03/13 22:25:45 tron Exp $

DISTNAME=		gnome-libs-1.0.56
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-libs/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		ORBit-*:../../corba/ORBit
DEPENDS+=		esound-*:../../audio/esound
DEPENDS+=		imlib-*:../../graphics/imlib
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
PLIST_SUBST+=		LOCALBASE=${LOCALBASE} \
			LOCALSTATEDIR=${LOCALSTATEDIR}

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
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${PREFIX}; ${FIND} lib -name 'libgnome.so.*' >>${PLIST_SRC}
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libart.m4 \
	  ${LOCALBASE}/share/aclocal/libart.m4

.include "../../mk/bsd.pkg.mk"

.if (${OBJECT_FMT} == a.out)
MAKE_ENV+=	A_OUT_STATIC=-static
.endif
