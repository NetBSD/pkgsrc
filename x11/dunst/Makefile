# $NetBSD: Makefile,v 1.37 2024/05/29 16:34:58 adam Exp $

DISTNAME=	dunst-1.11.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dunst-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dunst-project.org/
COMMENT=	Customizable and lightweight notification-daemon
LICENSE=	modified-bsd

USE_TOOLS+=	bash:test gmake pod2man pkg-config

# PASS test_notification_referencing:  (0 ticks, 0.000 sec)
# bash: line 2: 14069 Segmentation fault      (core dumped) ./test/test -v
#      11348 Done                    | ./test/greenest.awk
# gmake: *** [Makefile:76: test] Error 139
TEST_TARGET=	test

MAKE_FLAGS+=	SYSTEMD=0
MAKE_FLAGS+=	WAYLAND=0

REPLACE_SH+=	contrib/progress-notify.sh
REPLACE_BASH+=	contrib/dunst_xr_theme_changer.sh
REPLACE_BASH+=	test/test-install.sh

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		dunstrc docs/dunst.1.pod
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
