# $NetBSD: Makefile,v 1.24 2000/03/21 22:40:57 tron Exp $
# FreeBSD Id: Makefile,v 1.10 1998/05/04 20:22:31 jseger Exp
#

DISTNAME=		arena-0.3.62
WRKSRC=			${WRKDIR}/Arena-0.3.62
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.yggdrasil.com/pub/dist/web/arena/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.yggdrasil.com/Products/Arena/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		gettext-0.10.*:../../devel/gettext
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		libwww-5.2.8:../../www/libwww
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		xpm-3.4k:../../graphics/xpm

#XXX "black screen" fixed for 16-bit displays on mac68k, not verified on alpha.
#NOT_FOR_PLATFORM=	*-*-alpha	#Runs, displays black screen

GNU_CONFIGURE=		yes
MAKEFILE=		makefile
USE_GMAKE=		yes
USE_X11=		yes

# Comment out the following to build in the debugging symbols.
CONFIGURE_ARGS+=	--without-debug

CONFIGURE_ARGS+=	--with-arenarc-dir=${LOCALBASE}/etc
CONFIGURE_ARGS+=	--with-libwww-config-h-dir=${WRKDIR}
CONFIGURE_ARGS+=	--with-libwww-include=${LOCALBASE}/include/w3c-libwww
CONFIGURE_ARGS+=	--with-libwww-libdir=${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -I${WRKDIR}"

# Arena requires libwww's "config.h" header - it is installed as "wwwconf.h",
# so make a symlink in ${WRKDIR} and add it to the -I list.
pre-configure:
	${LN} -sf ${LOCALBASE}/include/w3c-libwww/wwwconf.h ${WRKDIR}/config.h
	cd ${WRKSRC} && autoconf

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
