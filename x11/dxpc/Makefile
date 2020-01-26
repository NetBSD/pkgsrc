# $NetBSD: Makefile,v 1.34 2020/01/26 17:32:26 rillig Exp $

DISTNAME=	dxpc-3.9.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	man1dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

LIBS.SunOS+=		-lsocket -lnsl

.include "../../archivers/lzo/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
