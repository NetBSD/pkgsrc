# $NetBSD: Makefile,v 1.17 2014/10/09 14:07:16 wiz Exp $
#

DISTNAME=	xpaste-1.1
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display the content of the X11 paste buffer in a window

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
