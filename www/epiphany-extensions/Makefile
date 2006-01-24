# $NetBSD: Makefile,v 1.21 2006/01/24 07:32:47 wiz Exp $
#

DISTNAME=	epiphany-extensions-1.8.1
PKGREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/1.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
USE_MSGFMT_PLURALS=	YES
USE_PKGLOCALEDIR=	YES

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

BUILDLINK_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/epiphany/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
