# $NetBSD: Makefile,v 1.6 2023/02/07 01:41:17 pho Exp $

DISTNAME=	bsb-http-chunked-0.0.0.4
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Chunked HTTP transfer encoding for bytestring builders
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+= \
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
