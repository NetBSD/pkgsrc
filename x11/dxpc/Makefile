# $NetBSD: Makefile,v 1.21 2005/01/19 15:10:12 adam Exp $

DISTNAME=	dxpc-3.8.2
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/3.8.2/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vigor.nu/dxpc/
COMMENT=	Differential X Protocol Compressor

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
