# $NetBSD: Makefile,v 1.1 2023/01/28 20:04:34 pho Exp $

DISTNAME=	http-media-0.8.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Processing HTTP Content-Type and Accept headers
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
