# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 11:43:28 sborrill Exp $
#

DISTNAME=		wmzcalock-0.1
CATEGORIES=		x11
MASTER_SITES=		http://zapatopi.net/zapatoware/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://zapatopi.net/zapatoware/wmzcalock.html
COMMENT=		Dockapp calendar clock
LICENSE=		gnu-gpl-v2

EXTRACT_SUFX=		.tgz

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pax
INSTALLATION_DIRS=	share/wmzcalock/theme

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
.include "../../mk/bsd.pkg.mk"
