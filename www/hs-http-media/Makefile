# $NetBSD: Makefile,v 1.8 2025/01/30 14:53:37 pho Exp $

DISTNAME=	http-media-0.8.1.1
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Processing HTTP Content-Type and Accept headers
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES=	\
	bytestring	\
	containers

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
