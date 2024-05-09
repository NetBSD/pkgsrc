# $NetBSD: Makefile,v 1.4 2024/05/09 01:32:50 pho Exp $

DISTNAME=	text-iso8601-0.1
PKGREVISION=	2
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
