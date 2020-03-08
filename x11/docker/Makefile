# $NetBSD: Makefile,v 1.11 2020/03/08 16:51:41 wiz Exp $
#

DISTNAME=	docker-1.5
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://offload1.icculus.org/openbox/2/docker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://icculus.org/openbox/2/docker/
COMMENT=	WindowMaker dock app which acts as a system tray
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config gmake

MAKE_ENV+=	LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/docker ${DESTDIR}${PREFIX}/bin

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
