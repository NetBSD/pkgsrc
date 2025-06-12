# $NetBSD: Makefile,v 1.5 2025/06/12 20:04:10 vins Exp $

DISTNAME=	lemonbar-1.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LemonBoy/}
GITHUB_PROJECT=	bar
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hopkinsza@gmail.com
HOMEPAGE=	https://github.com/LemonBoy/bar
COMMENT=	Featherweight lemon-scented bar
LICENSE=	mit

CONFLICTS=	lemonbar-xft-[0-9]*

USE_TOOLS+=	gmake pod2man

BUILD_TARGET=	all doc

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE # memrchr

BUILDLINK_TRANSFORM+=	rm:-0s
BUILDLINK_TRANSFORM+=	opt:-std=c99:-std=gnu99	# strdup(), getopt()

MAKE_FLAGS+=		VERSION=${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
