# $NetBSD: Makefile,v 1.45 2002/10/21 13:27:24 wiz Exp $

DISTNAME=		arena-0.3.62
PKGREVISION=		2
WRKSRC=			${WRKDIR}/Arena-0.3.62
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.yggdrasil.com/pub/dist/web/arena/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.yggdrasil.com/Products/Arena/
COMMENT=	Experimental HTML 3 browser, supports math and style sheets

BUILD_USES_MSGFMT=	YES
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES

# Comment out the following to build in the debugging symbols.
CONFIGURE_ARGS+=	--without-debug

CONFIGURE_ARGS+=	--with-arenarc-dir=${LOCALBASE}/etc
CONFIGURE_ARGS+=	--with-libwww-config-h-dir=${WRKDIR}
CONFIGURE_ARGS+=	--with-libwww-include=${BUILDLINK_PREFIX.libwww}/include/w3c-libwww
CONFIGURE_ARGS+=	--with-libwww-libdir=${BUILDLINK_PREFIX.libwww}/lib

MAKEFILE=		makefile

# Arena requires libwww's "config.h" header - it is installed as "wwwconf.h",
# so make a symlink in ${WRKSRC}
pre-configure:
	for c in ${LOCALBASE}/include/w3c-libwww/wwwconf.h \
	    ${LOCALBASE}/include/wwwconf.h; do \
	  if [ -f $$c ]; then \
	    ${LN} -sf $$c ${WRKSRC}/config.h; \
 	  fi; \
	done

do-install:
	${INSTALL_PROGRAM} \
	    ${WRKSRC}/Arena/${MACHINE_GNU_PLATFORM:C/.*-.*-//}/arena \
	    ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/Arena/Source/arenarc ${PREFIX}/share/examples/
	if [ ! -f ${LOCALBASE}/etc/arenarc ]; then \
	  ${CP} ${PREFIX}/share/examples/arenarc ${LOCALBASE}/etc/; \
	fi
	${INSTALL_DATA_DIR} ${PREFIX}/share/locale/en/LC_MESSAGES
	msgfmt --output-file=${WRKDIR}/Arena.gmo \
	    ${WRKSRC}/Arena/LC_MESSAGES/en/Arena.po
	${INSTALL_DATA} ${WRKDIR}/Arena.gmo \
	    ${PREFIX}/share/locale/en/LC_MESSAGES/
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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
