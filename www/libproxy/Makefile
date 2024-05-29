# $NetBSD: Makefile,v 1.53 2024/05/29 16:34:52 adam Exp $

DISTNAME=	libproxy-0.5.6
PKGREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=libproxy/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libproxy.github.io/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:build pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/libproxy-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/src/backend:${WRKSRC}/output/src/libproxy
TEST_TARGET=	test

REPLACE_BASH+=	data/check-code-style
REPLACE_BASH+=	data/install-git-hook.sh
REPLACE_BASH+=	data/pre-commit-hook

# shouldn't be necessary, but is?
# https://github.com/libproxy/libproxy/issues/237
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/libproxy

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gi-docgen/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/libduktape/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
