# $NetBSD: Makefile,v 1.2 2020/04/22 08:21:06 pin Exp $

DISTNAME=	sowm-1.6
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/sowm/
COMMENT=	Itsy bitsy floating window manager
LICENSE=	mit

USE_LANGUAGES=	c99

INSTALLATION_DIRS+=	bin share/doc/sowm

SUBST_CLASSES+=		optimize
SUBST_STAGE.optimize=	pre-configure
SUBST_SED.optimize+=	-e 's|-O3||g'
SUBST_MESSAGE.optimize=	Do not force -O3 optimizations
SUBST_FILES.optimize+=	Makefile

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu
DEPENDS+=	st-term-[0-9]*:../../x11/st-term
DEPENDS+=	scrot-[0-9]*:../../graphics/scrot

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD"
DEPENDS+=	alsa-utils-[0-9]*:../../audio/alsa-utils
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/sowm

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
