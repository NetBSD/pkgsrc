# $NetBSD: Makefile,v 1.133 2020/11/05 09:09:21 ryoon Exp $

DISTNAME=	midori-v9.0
PKGNAME=	${DISTNAME:S/v//}
PKGREVISION=	11
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=midori-browser/}
GITHUB_PROJECT=	core
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://midori-browser.org/
COMMENT=		Lightweight web browser using WebKit
LICENSE=		gnu-lgpl-v2.1
USE_GCC_RUNTIME=	yes

USE_CMAKE=	yes
USE_TOOLS+=	intltool msgfmt pkg-config

BUILDLINK_TRANSFORM+=	rm:-Werror

CONFIGURE_ENV+=	VALAC=${VALAC}

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
