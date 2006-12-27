# $NetBSD: Makefile,v 1.6 2006/12/27 13:37:40 joerg Exp $

DISTNAME=	swisswatch-0.06
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/X/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sanpei@yy.cs.keio.ac.jp
COMMENT=	Swiss railway clock emulation, and a fancy default appearance

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
