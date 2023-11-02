# $NetBSD: Makefile,v 1.8 2023/11/02 06:37:44 pho Exp $

DISTNAME=	bsb-http-chunked-0.0.0.4
PKGREVISION=	6
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Chunked HTTP transfer encoding for bytestring builders
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+= \
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
