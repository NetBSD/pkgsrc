# $NetBSD: Makefile,v 1.1 2026/02/01 20:30:52 leot Exp $

DISTNAME=	xssstate-1.1
CATEGORIES=	x11
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://tools.suckless.org/x/xssstate/
COMMENT=	Simple tool to retrieve the X screensaver state
LICENSE=	mit

USE_CC_FEATURES=	c99

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e '/^CFLAGS/s/-g//'
SUBST_SED.makefile+=	-e '/^CFLAGS/s/-O0//'
SUBST_SED.makefile+=	-e '/^LDFLAGS/s/-g//'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
