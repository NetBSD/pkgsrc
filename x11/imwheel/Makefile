# $NetBSD: Makefile,v 1.20 2025/11/17 11:01:41 wiz Exp $
#

DISTNAME=	imwheel-0.9.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imwheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://imwheel.sourceforge.net/
COMMENT=	Tool which helps to use mousewheels

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
