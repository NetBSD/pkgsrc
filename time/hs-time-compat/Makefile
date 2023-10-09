# $NetBSD: Makefile,v 1.11 2023/10/09 04:54:57 pho Exp $

DISTNAME=	time-compat-1.9.6.1
PKGREVISION=	4
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
