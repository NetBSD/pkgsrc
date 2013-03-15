# $NetBSD: Makefile,v 1.42 2013/03/15 18:24:10 drochner Exp $

DISTNAME=		liferea-1.8.12
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dbus
USE_TOOLS+=		gmake pkg-config msgfmt perl intltool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		c

SHLIBTOOL_OVERRIDE=	# empty

GCONF_SCHEMAS=		liferea.schemas

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
