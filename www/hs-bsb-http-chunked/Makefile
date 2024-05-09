# $NetBSD: Makefile,v 1.9 2024/05/09 01:32:52 pho Exp $

DISTNAME=	bsb-http-chunked-0.0.0.4
PKGREVISION=	7
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Chunked HTTP transfer encoding for bytestring builders
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+= \
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
