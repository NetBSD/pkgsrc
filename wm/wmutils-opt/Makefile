# $NetBSD: Makefile,v 1.3 2022/02/11 10:18:41 pin Exp $

DISTNAME=	wmutils-opt-1.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmutils/}
GITHUB_PROJECT=	opt
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wmutils/opt/
COMMENT=	Optional addons to wmutils
LICENSE=	isc

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		configmk
SUBST_MESSAGE.configmk=	Adjust comfig.mk
SUBST_STAGE.configmk=	pre-configure
SUBST_FILES.configmk+=	config.mk
SUBST_SED.configmk+=	-e 's,/usr,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
