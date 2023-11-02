# $NetBSD: Makefile,v 1.13 2023/11/02 06:37:42 pho Exp $

DISTNAME=	time-compat-1.9.6.1
PKGREVISION=	5
CATEGORIES=	time

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compatibility package for time
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	base-orphans	\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
