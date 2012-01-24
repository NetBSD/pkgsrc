# $NetBSD: Makefile,v 1.99 2012/01/24 09:11:17 sbd Exp $

DISTNAME=		liferea-1.4.28
PKGREVISION=		15
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds

GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		gmake pkg-config msgfmt perl intltool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		c

PKG_OPTIONS_VAR=	PKG_OPTIONS.liferea
PKG_OPTIONS_REQUIRED_GROUPS=	renderer
PKG_OPTIONS_GROUP.renderer=	liferea-gtkhtml liferea-mozilla liferea-webkit
PKG_OPTIONS_LEGACY_OPTS=	liferea-firefox:liferea-mozilla liferea-seamonkey:liferea-mozilla
PKG_SUGGESTED_OPTIONS=	liferea-gtkhtml
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtkhtml mozilla webkit
.if !empty(PKG_OPTIONS:Mliferea-gtkhtml)
CONFIGURE_ARGS+=	--disable-gecko
.include "../../www/libgtkhtml/buildlink3.mk"
PLIST.gtkhtml=	yes
.endif
.if !empty(PKG_OPTIONS:Mliferea-mozilla)
CONFIGURE_ARGS+=	--with-gecko=libxul
.include "../../devel/xulrunner/buildlink3.mk"
PLIST.mozilla=	yes
.endif
.if !empty(PKG_OPTIONS:Mliferea-webkit)
CONFIGURE_ARGS+=	--disable-gecko
.include "../../www/webkit-gtk/buildlink3.mk"
PLIST.webkit=	yes
.endif

SHLIBTOOL_OVERRIDE=	# empty

GCONF_SCHEMAS=		liferea.schemas

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
