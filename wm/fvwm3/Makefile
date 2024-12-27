# $NetBSD: Makefile,v 1.46 2024/12/27 08:20:46 wiz Exp $

DISTNAME=	fvwm3-1.1.1
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fvwmorg/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/fvwmorg/fvwm3
COMMENT=	Multiple large virtual desktop window manager
LICENSE=	gnu-gpl-v2 AND mit

CONFLICTS=	fvwm-[0-9]* fvwm1-[0-9]* fvwm2-[0-9]* metisse-[0-9]*

USE_TOOLS+=		grep pkg-config perl sed
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_PKGLOCALEDIR=	yes

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg	# needed by fvwm-menu-desktop

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27				# wants python3

.include "../../lang/go/go-vars.mk"				# required by go linker

REPLACE_PERL=	perllib/FVWM/create-commands

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	bin/fvwm-menu-desktop.in doc/fvwm3_manpage_source.adoc
SUBST_FILES.paths+=	fvwm/fvwm3.c meson.build
SUBST_VARS.paths=	PKG_SYSCONFDIR SED BUILDLINK_PREFIX.readline
SUBST_SED.paths=	-e "s:/etc/system.fvwm2rc:${PKG_SYSCONFDIR}/fvwm/system.fvwm2rc:g"
SUBST_SED.paths+=	-e "s:/usr/local/share/fvwm:${PREFIX}/share/fvwm:g"

MESON_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/fvwm
MESON_ARGS+=	-Dreadline=enabled				# required by FvwmConsole
MESON_ARGS+=	-Dgolang=disabled				# handled locally by options.mk
MESON_ARGS+=	-Dlocaledir=${PKGLOCALEDIR}/fvwm3/locale
MESON_ARGS+=	-Dnls=enabled
# otherwise we get installed scripts that point to the tools directory
MESON_ARGS+=	-Dpython=${PYTHONBIN:Q}
MESON_ARGS+=	-Dperl=${PERL5:Q}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
