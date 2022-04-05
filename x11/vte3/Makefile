# $NetBSD: Makefile,v 1.47 2022/04/05 15:51:57 jperkin Exp $

DISTNAME=	vte-0.68.0
PKGNAME=	${DISTNAME:S/vte/vte3/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
GITHUB_PROJECT=	vte
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support
LICENSE=	gnu-lgpl-v2

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		output/meson-private/vte-2.91.pc

USE_TOOLS+=		msgfmt pkg-config bash
USE_LANGUAGES=		c c++17
# for c++17
GCC_REQD+=		7

# Otherwise, this will fail on Linux distributions that don't
# have libsystemd.
MESON_ARGS+=		-D_systemd=false

CONF_FILES+=		${PREFIX}/share/examples/profile.d/vte.sh \
			${PKG_SYSCONFDIR}/profile.d/vte.sh

CONF_FILES+=		${PREFIX}/share/examples/profile.d/vte.csh \
			${PKG_SYSCONFDIR}/profile.d/vte.csh

MAKE_DIRS+=		${PKG_SYSCONFDIR}/profile.d

PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON=		src/*.py

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
