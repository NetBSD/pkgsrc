# $NetBSD: Makefile,v 1.14 2024/04/29 16:21:55 pho Exp $

DISTNAME=	time-compat-1.9.6.1
PKGREVISION=	5
CATEGORIES=	time

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compatibility package for time
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base		\
	base-orphans	\
	deepseq		\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
