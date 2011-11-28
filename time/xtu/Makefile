# $NetBSD: Makefile,v 1.10 2011/11/28 00:06:18 wiz Exp $
#

DISTNAME=	xtu-1.2
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://core.de/~coto/projects/xtu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.de/~coto/projects/xtu/
COMMENT=	Small configurable X11 analog clock

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} *.c -o xtu -I${X11BASE}/include ${X11_LDFLAGS} -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtu ${DESTDIR}${PREFIX}/bin/

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
