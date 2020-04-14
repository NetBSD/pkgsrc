# $NetBSD: Makefile,v 1.1 2020/04/14 14:25:19 ryoon Exp $

DISTNAME=	gnome-pomodoro-0.17.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=codito/}
GITHUB_PROJECT=	gnome-pomodoro
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gnomepomodoro.org/
COMMENT=	Pomodoro timer for Gnome
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive
BUILD_DEPENDS+=		vala-[0-9]*:../../lang/vala

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

USE_TOOLS+=		automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/gom/buildlink3.mk"
.include "../../devel/appstream-glib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
