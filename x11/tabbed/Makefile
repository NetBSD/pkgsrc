# $NetBSD: Makefile,v 1.6 2025/08/09 15:56:02 leot Exp $

DISTNAME=	tabbed-0.9
CATEGORIES=	x11
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	https://tools.suckless.org/tabbed/
COMMENT=	Simple generic tabbed frontend to xembed aware applications
LICENSE=	mit

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e 's,^FREETYPEINC *=.*,FREETYPEINC != freetype-config --cflags,'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/tabbed

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
