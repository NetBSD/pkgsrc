# $NetBSD: Makefile,v 1.3 2024/02/23 17:13:10 hauke Exp $

DISTNAME=	nx-libs-${PKGVER}-lite
PKGNAME=	nx-libs-${PKGVER:S/-/./}
PKGVER=		3.5.99.26-0x2go1
MASTER_SITES=	https://code.x2go.org/releases/source/nx-libs/
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
