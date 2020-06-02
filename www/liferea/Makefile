# $NetBSD: Makefile,v 1.174 2020/06/02 08:24:57 adam Exp $

DISTNAME=		liferea-1.12.7
PKGREVISION=		4
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=lwindolf/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://lzone.de/liferea/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoreconf autoconf automake gmake pkg-config msgfmt perl intltool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

SHLIBTOOL_OVERRIDE=	# empty

GLIB_SCHEMAS=		net.sf.liferea.gschema.xml

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
