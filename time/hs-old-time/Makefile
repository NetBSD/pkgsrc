# $NetBSD: Makefile,v 1.9 2023/11/02 06:37:42 pho Exp $

DISTNAME=	old-time-1.1.0.3
PKGREVISION=	7
CATEGORIES=	time

MAINTAINER=	pho@cielonegro.org
COMMENT=	Time library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
