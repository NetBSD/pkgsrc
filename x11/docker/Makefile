# $NetBSD: Makefile,v 1.7 2012/07/30 02:04:23 dholland Exp $
#

DISTNAME=	docker-1.5
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://offload1.icculus.org/openbox/2/docker/

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/2/docker/
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
