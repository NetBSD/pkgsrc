# $NetBSD: Makefile,v 1.1 2020/12/11 15:12:35 nia Exp $

DISTNAME=	tinywm-1.3
CATEGORIES=	wm x11
MASTER_SITES=	http://incise.org/files/dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incise.org/tinywm.html
COMMENT=	Very basic X window manager in around 50 lines of C
LICENSE=	public-domain

INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -lX11 -o tinywm tinywm.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinywm ${DESTDIR}${PREFIX}/bin/tinywm

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
