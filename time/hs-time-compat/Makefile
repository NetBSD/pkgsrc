# $NetBSD: Makefile,v 1.1 2019/12/31 18:06:15 pho Exp $

DISTNAME=	time-compat-1.9.2.2
CATEGORIES=	time

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compatibility package for time
LICENSE=	modified-bsd

# Setup.hs is missing from the package.
post-patch:
	${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/Setup.hs

.include "../../mk/haskell.mk"
.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
