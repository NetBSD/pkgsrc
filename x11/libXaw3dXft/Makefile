# $NetBSD: Makefile,v 1.2 2023/01/29 21:15:11 ryoon Exp $

DISTNAME=	libXaw3dXft-1.6.2h
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	FreeType and UTF-8 support for libXaw3d
LICENSE=	x11

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-internationalization
CONFIGURE_ARGS+=	--enable-arrow-scrollbars
USE_LIBTOOL=		yes
USE_TOOLS=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
