# $NetBSD: Makefile,v 1.15 2019/06/15 15:02:13 nia Exp $

DISTNAME=	dunst-1.4.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dunst-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dunst-project.org/
COMMENT=	Customizable and lightweight notification-daemon
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pod2man pkg-config

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	SYSTEMD=0

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		dunstrc config.h
SUBST_SED.fix-paths+=		-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/dbus-1/services
INSTALLATION_DIRS+=	share/dunst

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
