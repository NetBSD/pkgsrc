# $NetBSD: Makefile,v 1.6 2003/03/03 03:32:35 jschauma Exp $

DISTNAME=	tvtwm.pl11
PKGNAME=	tvtwm-11
PKGREVISION=	1
WRKSRC=		${WRKDIR}/tvtwm
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=window_managers/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Classic twm with virtual desktop support

USE_BUILDLINK2=	YES
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
