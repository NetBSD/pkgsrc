# $NetBSD: Makefile,v 1.14 2017/09/06 10:40:34 wiz Exp $
#

DISTNAME=	xtu-1.3
CATEGORIES=	time
#MASTER_SITES=	http://coto.marsrakete.de/projects/xtu/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://coto.marsrakete.de/projects/xtu/
COMMENT=	Small configurable X11 analog clock

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CC} -DUSE_XPM *.c -o xtu -I${X11BASE}/include ${X11_LDFLAGS} -lXpm -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xtu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
