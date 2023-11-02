# $NetBSD: Makefile,v 1.7 2023/11/02 06:37:48 pho Exp $

DISTNAME=	websockets-0.12.7.3
PKGREVISION=	5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sensible and clean way to write WebSocket-capable servers in Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-async/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-bytestring-builder/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../security/hs-SHA/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
