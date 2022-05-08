# $NetBSD: Makefile,v 1.3 2022/05/08 13:17:47 jperkin Exp $

DISTNAME=	wmutils-libwm-1.3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmutils/}
GITHUB_PROJECT=	libwm
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wmutils/libwm/
COMMENT=	Small library for X windows manipulation
LICENSE=	isc

USE_TOOLS+=	gmake

SUBST_CLASSES+=		configmk
SUBST_MESSAGE.configmk=	Adjust config.mk
SUBST_STAGE.configmk=	pre-configure
SUBST_FILES.configmk+=	config.mk
SUBST_SED.configmk+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
