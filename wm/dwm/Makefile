# $NetBSD: Makefile,v 1.23 2023/01/29 21:17:57 ryoon Exp $

DISTNAME=	dwm-6.4
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	https://dl.suckless.org/dwm/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://dwm.suckless.org/
COMMENT=	Dynamic window manager
LICENSE=	mit

USE_LANGUAGES=	c99

CPPFLAGS+=	-D_XOPEN_SOURCE=600

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/-I$${FREETYPEINC}/$${FREETYPEINC}/'
SUBST_SED.makefile+=	-e 's,^FREETYPEINC *=.*,FREETYPEINC != freetype-config --cflags,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
