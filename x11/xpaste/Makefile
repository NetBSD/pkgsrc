# $NetBSD: Makefile,v 1.8 2004/01/20 12:28:28 agc Exp $
#

DISTNAME=	xpaste-1.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	seb@NetBSD.org
COMMENT=	Display the content of the X11 paste buffer in a window

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes
USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"
