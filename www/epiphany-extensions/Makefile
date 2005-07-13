# $NetBSD: Makefile,v 1.13 2005/07/13 09:55:50 drochner Exp $
#

DISTNAME=	epiphany-extensions-1.6.4
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/1.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

GNU_CONFIGURE=		YES
USE_TOOLS=		gmake
USE_LIBTOOL=		YES
USE_MSGFMT_PLURALS=	YES
USE_PKGLOCALEDIR=	YES

# Avoid -Werror, which breaks the build sometimes.
CONFIGURE_ARGS+=	--enable-compile-warnings=no
CONFIGURE_ARGS+=	--with-extensions=all

.include "../../mk/bsd.prefs.mk"

.if ${GECKO_PROVIDER} == "firefox"
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/dom
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
CPPFLAGS+=		-I${BUILDLINK_PREFIX.firefox}/include/firefox/webbrwsr
.else
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/dom
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/pref
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/webbrwsr
.endif

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/epiphany/buildlink3.mk"
.if ${GECKO_PROVIDER} == "firefox"
.include "../../www/firefox/buildlink3.mk"
.else
.include "../../www/mozilla-gtk2/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
