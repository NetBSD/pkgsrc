# $NetBSD: Makefile,v 1.22 2024/05/29 16:34:43 adam Exp $

DISTNAME=	gnome-pomodoro-0.17.0
PKGREVISION=	16
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=codito/}
GITHUB_PROJECT=	gnome-pomodoro
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gnomepomodoro.org/
COMMENT=	Pomodoro timer for Gnome
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive
TOOL_DEPENDS+=		vala-[0-9]*:../../lang/vala

# Broken generated code uses g_return_if_fail when g_return_val_if_fail
# is necessary
CFLAGS+=	-Wno-return-type

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

USE_TOOLS+=		automake autopoint gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/gom/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/appstream-glib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
