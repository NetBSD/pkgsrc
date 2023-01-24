# $NetBSD: Makefile,v 1.5 2023/01/24 11:39:04 pho Exp $

DISTNAME=	bsb-http-chunked-0.0.0.4
PKGREVISION=	3
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Chunked HTTP transfer encoding for bytestring builders
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+= \
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
