# $NetBSD: Makefile,v 1.25 2006/03/04 21:31:08 jlam Exp $

DISTNAME=	dxpc-3.8.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/3.8.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
