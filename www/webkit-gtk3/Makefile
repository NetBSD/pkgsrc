# $NetBSD: Makefile,v 1.11 2012/07/06 14:03:50 drochner Exp $

.include "../../www/webkit-gtk/Makefile.common"

PKGNAME=	${DISTNAME:S/webkit/webkit-gtk3/}
PKGREVISION=	2

COMMENT=	GTK3 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=3.0

# gen PLIST from webkit-gtk/PLIST
print-PLIST-from-gtk:
	${RUN}${SED} 						\
	-e 's/jsc-1/jsc-3/'					\
	-e 's/javascriptcoregtk-1.0/javascriptcoregtk-3.0/'	\
	-e 's/webkit-1.0.pc/webkitgtk-3.0.pc/'			\
	-e 's/webkit-1.0/webkit-3.0/'				\
	-e 's/webkit-2.0/webkit-3.0/'				\
	-e 's/webkitgtk-1.0/webkitgtk-3.0/'			\
	../../www/webkit-gtk/PLIST

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
