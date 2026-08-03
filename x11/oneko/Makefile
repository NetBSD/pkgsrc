# $NetBSD: Makefile,v 1.14 2026/08/03 13:12:33 wiz Exp $

DISTNAME=		oneko-1.1b
PKGNAME=		oneko-1.2
PKGREVISION=		2
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=		.tar.Z

PATCH_SITES=		http://www.bsddiary.net/oneko/
PATCHFILES=		oneko-1.2.diff.gz

MAINTAINER=		johnam@mail.kemper.org
COMMENT=		Like xneko except on the desktop and with other animals

WRKSRC=			${WRKDIR}/oneko
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
