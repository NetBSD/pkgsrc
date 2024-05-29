# $NetBSD: Makefile,v 1.29 2024/05/29 16:34:48 adam Exp $

DISTNAME=	badwolf-1.3.0
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	https://hacktivis.me/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hacktivis.me/projects/badwolf
COMMENT=	Minimalist and privacy-oriented webkit browser
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2
TOOL_DEPENDS+=	ninja-build>=1.7:../../devel/ninja-build

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ninja -j ${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		ninja -j ${MAKE_JOBS:U1} install

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
