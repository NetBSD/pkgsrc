# $NetBSD: Makefile,v 1.9 2004/01/20 12:27:35 agc Exp $

DISTNAME=	tvtwm.pl11
PKGNAME=	tvtwm-11
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=window_managers/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Classic twm with virtual desktop support

WRKSRC=		${WRKDIR}/tvtwm
USE_BUILDLINK2=	YES
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
