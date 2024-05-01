# $NetBSD: Makefile,v 1.3 2024/05/01 14:18:53 pho Exp $

DISTNAME=	text-iso8601-0.1
PKGREVISION=	1
CATEGORIES=	time converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Converting time to and from ISO 8601 text
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../math/hs-integer-conversion/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
