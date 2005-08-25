# $NetBSD: Makefile,v 1.40 2005/08/25 21:05:12 jmmv Exp $
#

DISTNAME=	epiphany-1.6.5
PKGREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/1.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/
COMMENT=	The web browser for the GNOME Desktop

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
USE_MSGFMT_PLURALS=	YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	data/epiphany-1.6.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKG_OPTIONS_VAR=	PKG_OPTIONS.epiphany
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/find
CFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/find
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/necko
CFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/necko
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
CFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
.else
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/find
CFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/find
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/necko
CFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/necko
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/pref
CFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/pref
.endif

GCONF2_SCHEMAS=		epiphany.schemas
GCONF2_SCHEMAS+=	epiphany-lockdown.schemas

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.10.0
BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.6.10
BUILDLINK_DEPENDS.pango+=	pango>=1.8.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../mk/bsd.pkg.mk"
