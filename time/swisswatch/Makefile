# $NetBSD: Makefile,v 1.10 2012/10/23 10:24:11 wiz Exp $

DISTNAME=	swisswatch-0.06
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sanpei@yy.cs.keio.ac.jp
COMMENT=	Swiss railway clock emulation, and a fancy default appearance

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
