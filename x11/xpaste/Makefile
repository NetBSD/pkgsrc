# $NetBSD: Makefile,v 1.7 2004/01/06 07:17:13 jlam Exp $
#

DISTNAME=	xpaste-1.1
PKGREVISION=	2
WRKSRC=		${WRKDIR}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	seb@NetBSD.org
COMMENT=	Display the content of the X11 paste buffer in a window

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"
