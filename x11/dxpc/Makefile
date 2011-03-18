# $NetBSD: Makefile,v 1.30 2011/03/18 10:50:46 adam Exp $

DISTNAME=	dxpc-3.9.2
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	man1dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/lzo/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
