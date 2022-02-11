# $NetBSD: Makefile,v 1.3 2022/02/11 09:47:34 pin Exp $

DISTNAME=	wmutils-core-1.6
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmutils/}
GITHUB_PROJECT=	core
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wmutils/core/
COMMENT=	Window Manipulation Utilities
LICENSE=	isc

MAKE_FLAGS+=	PREFIX=${PREFIX}

SUBST_CLASSES+=		configmk
SUBST_MESSAGE.configmk=	Adjust comfig.mk
SUBST_STAGE.configmk=	pre-configure
SUBST_FILES.configmk+=	config.mk
SUBST_SED.configmk+=	-e 's,/usr,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
