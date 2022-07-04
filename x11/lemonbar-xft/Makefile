# $NetBSD: Makefile,v 1.1 2022/07/04 19:56:05 pin Exp $

DISTNAME=	lemonbar-xft-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITLAB:=protesilaos/lemonbar-xft/-/archive/0042efd2ec1477ab96eb044ebba72a10aefff21f/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/protesilaos/lemonbar-xft/
COMMENT=	Featherweight lemon-scented bar
LICENSE=	mit

WRKSRC=	${WRKDIR}/lemonbar-xft-0042efd2ec1477ab96eb044ebba72a10aefff21f

CONFLICTS=	lemonbar-[0-9]*

USE_TOOLS+=	gmake pod2man

BUILD_TARGET=	all doc

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE # memrchr

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
