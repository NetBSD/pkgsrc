# $NetBSD: Makefile,v 1.35 2001/05/22 09:32:26 wiz Exp $
# FreeBSD Id: Makefile,v 1.10 1998/05/04 20:22:31 jseger Exp
#

DISTNAME=		arena-0.3.62
WRKSRC=			${WRKDIR}/Arena-0.3.62
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.yggdrasil.com/pub/dist/web/arena/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.yggdrasil.com/Products/Arena/
COMMENT=		Experimental HTML 3 browser, supports math and style sheets

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_USES_MSGFMT=	yes
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		libwww>=5.2.8:../../www/libwww
DEPENDS+=		png>=1.0.11:../../graphics/png

GNU_CONFIGURE=		YES
MAKEFILE=		makefile
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_X11=		YES
USE_XPM=		YES

# Comment out the following to build in the debugging symbols.
CONFIGURE_ARGS+=	--without-debug

CONFIGURE_ARGS+=	--with-arenarc-dir=${LOCALBASE}/etc
CONFIGURE_ARGS+=	--with-libwww-config-h-dir=${WRKDIR}
CONFIGURE_ARGS+=	--with-libwww-include=${LOCALBASE}/include/w3c-libwww
CONFIGURE_ARGS+=	--with-libwww-libdir=${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

# Arena requires libwww's "config.h" header - it is installed as "wwwconf.h",
# so make a symlink in ${WRKSRC}
pre-configure:
	for c in ${LOCALBASE}/include/w3c-libwww/wwwconf.h ${LOCALBASE}/include/wwwconf.h; do \
	  if [ -f $$c ]; then \
	    ${LN} -sf $$c ${WRKSRC}/config.h; \
 	  fi; \
	done
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Arena/netbsd/arena ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/Arena/Source/arenarc ${PREFIX}/share/examples/
	if [ ! -f ${LOCALBASE}/etc/arenarc ]; then \
	  ${CP} ${PREFIX}/share/examples/arenarc ${LOCALBASE}/etc/; fi
	${INSTALL_DATA_DIR} ${PREFIX}/share/locale/en/LC_MESSAGES
	msgfmt --output-file=${WRKDIR}/Arena.gmo ${WRKSRC}/Arena/LC_MESSAGES/en/Arena.po
	${INSTALL_DATA} ${WRKDIR}/Arena.gmo ${PREFIX}/share/locale/en/LC_MESSAGES/
	${INSTALL_DATA} ${WRKSRC}/Arena/doc/arena.man ${PREFIX}/man/man1/arena.1

.include "../../mk/bsd.prefs.mk"

.if defined(EXTRACT_USING_PAX)
GLOBAL_EXCLUDE_ARG=	-c
.else
EXCLUDE_ARG=		--exclude
.endif
EXTRACT_ELEMENTS=	${GLOBAL_EXCLUDE_ARG}
.for DONT_EXTRACT_SUBDIR in jpeg-* libpng-* zlib-*
EXTRACT_ELEMENTS+=	${EXCLUDE_ARG} Arena-*/Auxiliary/${DONT_EXTRACT_SUBDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
