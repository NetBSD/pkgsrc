# $NetBSD: Makefile,v 1.7 1998/09/15 17:29:58 garbled Exp $
# FreeBSD Id: Makefile,v 1.10 1998/05/04 20:22:31 jseger Exp
#

DISTNAME=	arena-0.3.61
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/web/arena/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.yggdrasil.com/Products/Arena/

DEPENDS=	libwww-5.1m1:../../www/libwww \
		jpeg-6b:../../graphics/jpeg \
		png-1.0.2:../../graphics/png \
		xpm-3.4k:../../graphics/xpm

LDFLAGS+=	-L${PREFIX}/lib -L${X11BASE}/lib
USE_GMAKE=	yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
USE_X11=	yes
CONFIGURE_ARGS+=	--without-debug
CONFIGURE_ARGS+=	--with-libwww-include=${PREFIX}/include/w3c-libwww
CONFIGURE_ARGS+=	--with-libwww-libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-libwww-config-h-dir=${PREFIX}/include/w3c-libwww
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include -I${X11BASE}/include -I${WRKDIR}"

WRKSRC=		${WRKDIR}/Arena-0.3.61

# Arena requires libwww's "config.h" header - it is installed as "wwwconf.h",
# so make a symlink in ${WRKDIR} and add it to the -I list.
pre-configure:
	@${LN} -sf ${PREFIX}/include/w3c-libwww/wwwconf.h ${WRKDIR}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Arena/netbsd/arena ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/Arena
# XXX not quite right, breaks on some platforms
#	${INSTALL_DATA} ${WRKSRC}/Arena/Source/arenarc ${PREFIX}/share/Arena/
	${INSTALL_DATA} ${WRKSRC}/Arena/doc/arena.man ${PREFIX}/man/man1/arena.1

.include "../../mk/bsd.pkg.mk"
