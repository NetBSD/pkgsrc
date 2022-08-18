# $NetBSD: Makefile,v 1.2 2022/08/18 15:35:29 hauke Exp $

DISTNAME=	nx-libs-${PKGVER}-lite
PKGNAME=	nx-libs-${PKGVER}
PKGVER=		3.5.99.26
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArcticaProject/}/nx-libs/archive/${PKGVER}/
CATEGORIES=	x11 devel

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://wiki.x2go.org/doku.php
COMMENT=	NX X11 protocol compression library

LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/nx-libs-${PKGVER}
NXDIRS=		nxcomp nxproxy

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		aclocal automake autoconf pkg-config gmake
USE_LANGUAGES+=		c c++

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_DIRS=		${NXDIRS}
BUILD_DIRS=		${NXDIRS}
INSTALL_DIRS=		${NXDIRS}

pre-configure:
.for nxd in ${NXDIRS}
	cd ${WRKSRC}/${nxd} && autoreconf -vfsi
.endfor

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
