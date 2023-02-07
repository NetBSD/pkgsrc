# $NetBSD: Makefile,v 1.10 2023/02/07 01:41:16 pho Exp $

DISTNAME=	time-compat-1.9.6.1
PKGREVISION=	3
CATEGORIES=	time

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compatibility package for time
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
