# $NetBSD: Makefile,v 1.119 2009/08/26 19:58:26 sno Exp $
#

DISTNAME=		galeon-2.0.7
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=galeon/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://galeon.sourceforge.net/
COMMENT=		GNOME2 Web browser based on gecko

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		galeon-devel-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

GCONF_SCHEMAS=		galeon.schemas

EGDIR=			${PREFIX}/share/examples/galeon
CONF_FILES=		${EGDIR}/sound/events/galeon.soundlist \
			${PKG_SYSCONFDIR}/sound/events/galeon.soundlist

CONFIGURE_ARGS+=	--with-mozilla=libxul-embedding-unstable

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
