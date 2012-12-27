# $NetBSD: Makefile,v 1.32 2012/12/27 20:19:35 ryoon Exp $

DISTNAME=	dxpc-3.9.2
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	man1dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

LIBS.SunOS+=		-lsocket -lnsl

.include "../../archivers/lzo/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
