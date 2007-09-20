# $NetBSD: Makefile,v 1.28 2007/09/20 08:04:17 rillig Exp $

DISTNAME=	dxpc-3.8.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/3.8.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"

post-install:
	strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
