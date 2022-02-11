# $NetBSD: Makefile,v 1.1 2022/02/11 13:39:09 pin Exp $

DISTNAME=	wmutils-libwm-1.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmutils/}
GITHUB_PROJECT=	libwm
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wmutils/libwm/
COMMENT=	Small library for X windows manipulation
LICENSE=	isc

SUBST_CLASSES+=		configmk
SUBST_MESSAGE.configmk=	Adjust comfig.mk
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
