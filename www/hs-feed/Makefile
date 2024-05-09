# $NetBSD: Makefile,v 1.4 2024/05/09 01:32:52 pho Exp $

DISTNAME=	feed-1.3.2.1
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interfacing with RSS (v 0.9x, 2.x, 1.0) + Atom feeds
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES=	\
	base		\
	base-compat	\
	bytestring	\
	text		\
	time

.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../time/hs-time-locale-compat/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-xml-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
