# $NetBSD: Makefile,v 1.1 2025/03/08 03:21:46 pho Exp $

DISTNAME=	snap-server-1.1.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Web server for the Snap Framework
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	containers	\
	network	\
	text	\
	unix-compat

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../devel/hs-io-streams/buildlink3.mk"
.include "../../net/hs-io-streams-haproxy/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../www/hs-snap-core/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
