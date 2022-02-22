# $NetBSD: Makefile,v 1.1 2022/02/22 08:19:16 pin Exp $

DISTNAME=	glazier-1.1
CATEGORIES=	wm
MASTER_SITES=	https://dl.z3bra.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://z3bra.org/glazier/
COMMENT=	X windows manipulator
LICENSE=	isc

#USE_TOOLS+=	pkg-config
MAKE_FILE=	makefile

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		configmk
SUBST_MESSAGE.configmk=	Adjust comfig.mk
SUBST_STAGE.configmk=	pre-configure
SUBST_FILES.configmk+=	config.mk
SUBST_SED.configmk+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../wm/wmutils-libwm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
