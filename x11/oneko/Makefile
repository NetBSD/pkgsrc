# $NetBSD: Makefile,v 1.6 2004/01/20 12:28:26 agc Exp $

DISTNAME=		oneko-1.1b
PKGNAME=		oneko-1.2
PKGREVISION=		1
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}

PATCHFILES=		oneko-1.2.diff.gz
PATCH_SITES=		http://hp.vector.co.jp/authors/VA004959/oneko/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		johnam@mail.kemper.org
COMMENT=		Like xneko except on the desktop and with other animals

WRKSRC=			${WRKDIR}/oneko
USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
