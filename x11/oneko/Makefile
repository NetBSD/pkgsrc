# $NetBSD: Makefile,v 1.2 2000/05/18 22:51:42 itohy Exp $

DISTNAME=		oneko-1.1b
PKGNAME=		oneko-1.2
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}

PATCHFILES=		oneko-1.2.diff.gz
PATCH_SITES=		http://hp.vector.co.jp/authors/VA004959/oneko/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		johnam@mail.kemper.org

USE_IMAKE=		yes
WRKSRC=			${WRKDIR}/oneko

.include "../../mk/bsd.pkg.mk"
