# $NetBSD: Makefile,v 1.11 2023/11/02 06:37:48 pho Exp $

DISTNAME=	xss-sanitize-0.3.7.2
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Sanitize untrusted HTML to prevent XSS attacks
LICENSE=	2-clause-bsd

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-css-text/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
