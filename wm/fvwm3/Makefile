# $NetBSD: Makefile,v 1.31 2024/05/29 16:34:45 adam Exp $

DISTNAME=	fvwm3-1.0.9
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fvwmorg/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/fvwmorg/fvwm3
COMMENT=	Multiple large virtual desktop window manager
LICENSE=	gnu-gpl-v2 AND mit

CONFLICTS=	fvwm-[0-9]* fvwm1-[0-9]* fvwm2-[0-9]* metisse-[0-9]*

GNU_CONFIGURE=		yes

USE_TOOLS+=	pkg-config perl:run
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	gmake # needed for manpages installation

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg				# fvwm-menu-desktop

PYTHON_VERSIONS_INCOMPATIBLE=	27	# wants python3

REPLACE_SH=	utils/*.sh
REPLACE_PERL=	perllib/FVWM/create-commands

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	fvwm/fvwm3.c doc/fvwm3_manpage_source.adoc	\
			bin/fvwm-menu-desktop.in doc/fvwm-menu-desktop.adoc
SUBST_SED.paths+=	-e "s:/etc/xdg/menus:${PKG_SYSCONFDIR}/xdg/menus:g"
SUBST_SED.paths+=	-e "s:/etc/system.fvwm2rc:${PKG_SYSCONFDIR}/fvwm/system.fvwm2rc:g"
SUBST_SED.paths+=	-e "s:/usr/local/share/fvwm:${PREFIX}/share/fvwm:g"

# otherwise we get installed scripts that point to the tools directory.
CONFIGURE_ENV+=	ac_cv_path_PYTHON=${PYTHONBIN}
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL5}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/fvwm
CONFIGURE_ARGS+=	--with-iconv-library=${BUILDLINK_PREFIX.iconv}/lib
CONFIGURE_ARGS+=	--with-iconv-includes=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_INCDIRS.iconv:Q}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
