# $NetBSD: Makefile,v 1.8 2009/05/30 01:35:45 zafer Exp $

DISTNAME=	swisswatch-0.06
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sanpei@yy.cs.keio.ac.jp
COMMENT=	Swiss railway clock emulation, and a fancy default appearance

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
