# $NetBSD: Makefile,v 1.7 2023/10/09 04:54:58 pho Exp $

DISTNAME=	bsb-http-chunked-0.0.0.4
PKGREVISION=	5
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Chunked HTTP transfer encoding for bytestring builders
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+= \
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
