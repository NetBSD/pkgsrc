# $NetBSD: Makefile,v 1.24 2006/02/05 23:11:32 joerg Exp $

DISTNAME=	dxpc-3.8.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/3.8.2/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
