# $NetBSD: Makefile,v 1.19 2004/05/31 16:43:45 kristerw Exp $
#

DISTNAME=		dxpc-3.8.1
CATEGORIES=		x11
MASTER_SITES=		http://www.vigor.nu/dxpc/3.8.1/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.vigor.nu/dxpc/
COMMENT=		Differential X Protocol Compressor

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_BUILDLINK3=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
