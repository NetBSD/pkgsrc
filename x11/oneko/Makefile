# $NetBSD: Makefile,v 1.12 2012/10/29 05:06:42 asau Exp $

DISTNAME=		oneko-1.1b
PKGNAME=		oneko-1.2
PKGREVISION=		2
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=		.tar.Z

PATCHFILES=		oneko-1.2.diff.gz
PATCH_SITES=		http://www.bsddiary.net/oneko/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		johnam@mail.kemper.org
COMMENT=		Like xneko except on the desktop and with other animals

WRKSRC=			${WRKDIR}/oneko
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
