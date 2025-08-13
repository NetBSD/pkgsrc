# $NetBSD: Makefile,v 1.29 2025/08/13 11:07:41 pho Exp $

DISTNAME=	HTTP-4000.4.1
PKGREVISION=	7
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell library for client-side HTTP
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base		\
	bytestring	\
	network

.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
