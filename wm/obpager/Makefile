# $NetBSD: Makefile,v 1.1.1.1 2007/06/20 18:09:24 tnn Exp $
#

DISTNAME=	obpager-1.8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=obpager/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://obpager.sourceforge.net/
COMMENT=	Lightweight pager applet for OpenBox

USE_LANGUAGES=	c++
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

CPPFLAGS+=	-I${X11BASE}/include/X11
CPPFLAGS+=	-I${X11BASE}/include/X11/extensions

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obpager ${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
