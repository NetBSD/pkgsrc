# $NetBSD: Makefile,v 1.13 2024/11/05 17:16:45 adam Exp $

DISTNAME=	serd-0.32.2
CATEGORIES=	textproc
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/serd.html
COMMENT=	Lightweight C library for RDF syntax
LICENSE=	isc

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		gsed pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/serd-0.pc

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing Python binary names.
SUBST_SED.sphinx+=	-e "s,'sphinx-build','sphinx-build-${PYVERSSUFFIX}',"
SUBST_SED.sphinx+=	-e "s,'sphinxygen','sphinxygen-${PYVERSSUFFIX}',"

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
