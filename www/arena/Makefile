# $NetBSD: Makefile,v 1.14 1999/10/14 07:27:35 fredb Exp $
# FreeBSD Id: Makefile,v 1.10 1998/05/04 20:22:31 jseger Exp
#

DISTNAME=		arena-0.3.62
WRKSRC=			${WRKDIR}/Arena-0.3.62
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.yggdrasil.com/pub/dist/web/arena/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.yggdrasil.com/Products/Arena/

DEPENDS=		gettext-0.10.35:../../devel/gettext \
			jpeg-6b:../../graphics/jpeg \
			libwww-5.2.8:../../www/libwww \
			png-1.0.3:../../graphics/png \
			xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha	#Runs, displays black screen

USE_GMAKE=		yes
MAKEFILE=		makefile
GNU_CONFIGURE=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--without-debug
CONFIGURE_ARGS+=	--with-libwww-include=${LOCALBASE}/include/w3c-libwww
CONFIGURE_ARGS+=	--with-libwww-libdir=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-libwww-config-h-dir=${WRKDIR}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -I${WRKDIR}"

# Arena requires libwww's "config.h" header - it is installed as "wwwconf.h",
# so make a symlink in ${WRKDIR} and add it to the -I list.
pre-configure:
	@${LN} -sf ${LOCALBASE}/include/w3c-libwww/wwwconf.h ${WRKDIR}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Arena/netbsd/arena ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/Arena
# XXX not quite right, breaks on some platforms
	${INSTALL_DATA} ${WRKSRC}/Arena/Source/arenarc ${PREFIX}/share/Arena/
	${INSTALL_DATA_DIR} ${PREFIX}/share/locale/en/LC_MESSAGES
	msgfmt --output-file=${WRKDIR}/Arena.gmo ${WRKSRC}/Arena/LC_MESSAGES/en/Arena.po
	$(INSTALL_DATA) ${WRKDIR}/Arena.gmo ${PREFIX}/share/locale/en/LC_MESSAGES/
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
