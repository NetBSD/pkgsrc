# $NetBSD: Makefile,v 1.10 2009/12/01 13:58:33 itohy Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/oneko
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
