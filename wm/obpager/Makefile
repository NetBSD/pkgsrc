# $NetBSD: Makefile,v 1.3 2012/10/08 12:42:22 asau Exp $
#

DISTNAME=	obpager-1.8
PKGREVISION=	1
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obpager ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
