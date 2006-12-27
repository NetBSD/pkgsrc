# $NetBSD: Makefile,v 1.13 2006/12/27 13:37:46 joerg Exp $
#

DISTNAME=	xpaste-1.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display the content of the X11 paste buffer in a window

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
