# $NetBSD: Makefile,v 1.4 2012/10/08 13:04:30 asau Exp $
#

DISTNAME=		wmzcalock-0.1
CATEGORIES=		time x11
MASTER_SITES=		http://zapatopi.net/zapatoware/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://zapatopi.net/zapatoware/wmzcalock.html
COMMENT=		Dockapp calendar clock
LICENSE=		gnu-gpl-v2

EXTRACT_SUFX=		.tgz

USE_TOOLS+=		pax
INSTALLATION_DIRS=	bin share/wmzcalock/theme

.include "../../mk/bsd.prefs.mk"

do-build:
	cd ${WRKSRC} && ${CC} -c ${CFLAGS} wmzcalock.c && \
		${CC} -o wmzcalock wmzcalock.o -lc ${LIBS} ${X11_LDFLAGS} \
		    -lX11 -lXext -lm -lXpm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/wmzcalock ${DESTDIR}${PREFIX:Q}/bin
	cd ${WRKSRC}/theme; ${PAX} -rw . \
	    ${DESTDIR}${PREFIX}/share/wmzcalock/theme

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
