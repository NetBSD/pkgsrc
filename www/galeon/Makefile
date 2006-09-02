# $NetBSD: Makefile,v 1.102 2006/09/02 19:42:58 rillig Exp $
#

DISTNAME=		galeon-2.0.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=galeon/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://galeon.sourceforge.net/
COMMENT=		GNOME2 Web browser based on gecko

CONFLICTS+=		galeon-devel-[0-9]*

USE_LANGUAGES=		c c++
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.galeon
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CONFIGURE_ARGS+=	--with-mozilla=firefox
.else
BUILDLINK_RPATHDIRS.mozilla-gtk2+=	lib/mozilla-gtk2
.endif

GCONF2_SCHEMAS=		galeon.schemas

EGDIR=			${PREFIX}/share/examples/galeon
CONF_FILES=		${EGDIR}/sound/events/galeon.soundlist \
			${PKG_SYSCONFDIR}/sound/events/galeon.soundlist

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../mk/bsd.pkg.mk"
