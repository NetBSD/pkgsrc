# $NetBSD: Makefile,v 1.11 2004/09/18 11:59:06 blymn Exp $

DISTNAME=	tvtwm.pl11
PKGNAME=	tvtwm-11
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=window_managers/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Classic twm with virtual desktop support

WRKSRC=		${WRKDIR}/tvtwm
USE_BUILDLINK3=	YES
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
