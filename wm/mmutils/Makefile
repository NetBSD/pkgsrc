# $NetBSD: Makefile,v 1.1 2022/02/11 13:44:45 pin Exp $

DISTNAME=	mmutils-1.4.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=pockata/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pockata/mmutils/
COMMENT=	Set of utilities to easily get xrandr monitor information
LICENSE=	isc

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		configmk
SUBST_MESSAGE.configmk=	Adjust comfig.mk
SUBST_STAGE.configmk=	pre-configure
SUBST_FILES.configmk+=	config.mk
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
