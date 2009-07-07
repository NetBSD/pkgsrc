# $NetBSD: Makefile,v 1.29 2009/07/07 18:30:27 joerg Exp $

DISTNAME=	dxpc-3.8.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/3.8.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			man1dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
