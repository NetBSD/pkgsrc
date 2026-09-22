# $NetBSD: Makefile,v 1.1 2026/09/22 09:04:53 ryoon Exp $

DISTNAME=	blueprint-compiler-v0.22.2
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	x11 python
MASTER_SITES=	https://gitlab.gnome.org/GNOME/blueprint-compiler/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/blueprint-compiler
COMMENT=	Markup language for GTK user interfaces
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

SUBST_CLASSES+=		py3
SUBST_STAGE.py3=	pre-configure
SUBST_MESSAGE.py3=	Replacing python3
SUBST_FILES.py3=	meson.build
SUBST_SED.py3=		-e "s,'python3','${PYTHONBIN}',g"

REPLACE_PYTHON+=	docs/collect-sections.py

PKGCONFIG_OVERRIDE+=	data/blueprint-compiler.pc.in

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
