# $NetBSD: Makefile,v 1.31 2006/07/22 04:46:19 rillig Exp $
#

DISTNAME=	epiphany-extensions-2.14.1.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++

# Avoid -Werror, which breaks the build sometimes.
CONFIGURE_ARGS+=	--enable-compile-warnings=no
CONFIGURE_ARGS+=	--with-extensions=all

# this should use the same gecko option as epiphany
PKG_OPTIONS_VAR=	PKG_OPTIONS.epiphany
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/dom
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/webbrwsr
.else
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/dom
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/pref
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/webbrwsr
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/epiphany/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
