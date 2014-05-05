# $NetBSD: Makefile,v 1.30 2014/05/05 00:48:27 ryoon Exp $

.include "../../www/webkit-gtk/Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk3/}
PKGREVISION=	12

COMMENT=	GTK3 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=3.0
CONFIGURE_ARGS+=	--disable-webkit2

# gen PLIST from webkit-gtk/PLIST
print-PLIST-from-gtk:
	${RUN}${SED} 						\
	-e 's/jsc-1/jsc-3/'					\
	-e 's/javascriptcoregtk-1.0/javascriptcoregtk-3.0/'	\
	-e 's/webkit-1.0.pc/webkitgtk-3.0.pc/'			\
	-e 's/webkit-1.0/webkit-3.0/'				\
	-e 's/webkit-2.0/webkit-3.0/'				\
	-e 's/webkitgtk-2.0.mo/webkitgtk-3.0.mo/'			\
	-e 's/webkitgtk-1.0/webkitgtk-3.0/'			\
	-e 's/JSCore-1.0/JSCore-3.0/'				\
	-e 's/WebKit-1.0/WebKit-3.0/'				\
	../../www/webkit-gtk/PLIST

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
