# $NetBSD: Makefile,v 1.2 2020/11/23 14:07:27 nia Exp $

DISTNAME=	lemonbar-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LemonBoy/}
GITHUB_PROJECT=	bar
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hopkinsza@gmail.com
HOMEPAGE=	https://github.com/LemonBoy/bar
COMMENT=	Featherweight lemon-scented bar
LICENSE=	mit

USE_TOOLS+=	gmake pod2man

BUILD_TARGET=	all doc

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE # memrchr

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
