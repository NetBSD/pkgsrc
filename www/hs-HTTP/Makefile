# $NetBSD: Makefile,v 1.24 2023/11/02 06:37:44 pho Exp $

DISTNAME=	HTTP-4000.4.1
PKGREVISION=	3
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell library for client-side HTTP
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
