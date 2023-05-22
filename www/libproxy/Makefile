# $NetBSD: Makefile,v 1.40 2023/05/22 20:28:28 wiz Exp $

DISTNAME=	libproxy-0.5.0
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=libproxy/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libproxy.github.io/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	bash:build pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/libproxy-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

TEST_TARGET=	test

REPLACE_BASH+=	data/check-code-style
REPLACE_BASH+=	data/install-git-hook.sh
REPLACE_BASH+=	data/pre-commit-hook

# see libsoup comment below
MESON_ARGS+=	-Dtests=false

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gi-docgen/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/libduktape/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
# needed for tests, but causes dependency loop via
# libsoup3 -> glib-networking -> libproxy
#.include "../../net/libsoup3/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
