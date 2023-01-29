# $NetBSD: Makefile,v 1.26 2023/01/29 21:18:08 ryoon Exp $

DISTNAME=	dunst-1.9.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dunst-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dunst-project.org/
COMMENT=	Customizable and lightweight notification-daemon
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pod2man pkg-config

TEST_DEPENDS+=	bash-[0-9]*:../../shells/bash
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
SUBST_SED.fix-paths+=		-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'

SUBST_CLASSES+=		malloc
SUBST_STAGE.malloc=	pre-configure
SUBST_MESSAGE.malloc=	Replacing malloc.h.
SUBST_FILES.malloc=	src/icon-lookup.c
SUBST_SED.malloc=	-e 's|<malloc.h>|<stdlib.h>|g'

INSTALL_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
INSTALL_ENV+=	SYSCONFDIR=${PREFIX}/share

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/dbus-1/services
INSTALLATION_DIRS+=	share/dunst

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
