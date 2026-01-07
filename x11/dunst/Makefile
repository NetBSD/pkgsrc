# $NetBSD: Makefile,v 1.51 2026/01/07 08:49:28 wiz Exp $

DISTNAME=	dunst-1.13.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dunst-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dunst-project.org/
COMMENT=	Customizable and lightweight notification-daemon
LICENSE=	modified-bsd

USE_TOOLS+=	bash:test gmake pod2man pkg-config

# FAIL test_calculate_dimensions_height_min: dim.h == expected_height (test/draw.c:321) (0 ticks, 0.000 sec)
# FAIL test_pattern_match: rule_field_matches_string("asd", "") (test/rules.c:44) (0 ticks, 0.000 sec)
# Total: 202 tests (3 ticks, 0.030 sec), 2643 assertions
# Pass: 200, fail: 2, skip: 0.
TEST_TARGET=	test

MAKE_FLAGS+=	SYSTEMD=0
MAKE_FLAGS+=	WAYLAND=0

REPLACE_SH+=	contrib/progress-notify.sh
REPLACE_BASH+=	contrib/dunst_xr_theme_changer.sh
REPLACE_BASH+=	test/test-install.sh

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		dunstrc
SUBST_FILES.fix-paths+=		docs/dunst.5.pod
SUBST_FILES.fix-paths+=		src/icon-lookup.c
SUBST_FILES.fix-paths+=		src/settings_data.h
SUBST_SED.fix-paths+=		-e 's,/usr/local/share/:/usr/share/,${PREFIX}/share,g'
SUBST_SED.fix-paths+=		-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'

INSTALL_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
INSTALL_ENV+=	SYSCONFDIR=${PREFIX}/share

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/dbus-1/services
INSTALLATION_DIRS+=	share/dunst
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
