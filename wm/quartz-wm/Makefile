# $NetBSD: Makefile,v 1.1 2015/10/01 11:06:08 tnn Exp $

DISTNAME=	quartz-wm-1.3.1
CATEGORIES=	wm
MASTER_SITES=	http://xquartz.macosforge.org/downloads/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xquartz.macosforge.org/downloads/src/
COMMENT=	Aqua Window Manager for the X Window System on OS X
LICENSE=	apple-public-source-license

USE_TOOLS=	pkg-config gmake
USE_LANGUAGES=	c objc
GNU_CONFIGURE=	yes

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../wm/libAppleWM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
