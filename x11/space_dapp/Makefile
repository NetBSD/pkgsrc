# $NetBSD: Makefile,v 1.5 2012/10/29 05:06:52 asau Exp $

PKGNAME=		space_dapp-20060717
CATEGORIES=		x11
MASTER_SITES=		http://darkshed.net/files/c_cpp/bits/

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://darkshed.net/files/c_cpp/bits/
COMMENT=		Tiny dock app to create an empty space
DISTNAME=		space_dapp.c
EXTRACT_SUFX=

INSTALLATION_DIRS=	bin

NO_CONFIGURE=		yes

WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

do-build:
	cd ${WRKSRC} && ${CC} -c ${CFLAGS} space_dapp.c -DSHAPE && \
		${CC} -o space_dapp space_dapp.o -lc ${LIBS} ${X11_LDFLAGS} -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/space_dapp ${DESTDIR}${PREFIX}/bin/

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
