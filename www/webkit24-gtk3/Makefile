# $NetBSD: Makefile,v 1.24 2018/11/14 22:22:37 kleink Exp $

PKGREVISION= 20
.include "../../www/webkit24-gtk/Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit24-gtk3/}

COMMENT=	GTK3 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=3.0
CONFIGURE_ARGS+=	--disable-gtk-doc-html
CONFIGURE_ARGS+=	--disable-webkit2

# Automatically generate PLIST from www/webkit24-gtk/PLIST
.PHONY: print-PLIST-from-gtk
print-PLIST-from-gtk:
	${RUN}${SED} 						\
	-e 's/jsc-1/jsc-3/'					\
	-e 's/javascriptcoregtk-1.0/javascriptcoregtk-3.0/'	\
	-e 's/webkit-1.0.pc/webkitgtk-3.0.pc/'			\
	-e 's/webkit-1.0/webkit-3.0/'				\
	-e 's/webkit-2.0/webkit-3.0/'				\
	-e 's/webkitgtk-2.0.mo/webkitgtk-3.0.mo/'		\
	-e 's/webkitgtk-1.0/webkitgtk-3.0/'			\
	-e 's/JSCore-1.0/JSCore-3.0/'				\
	-e 's/WebKit-1.0/WebKit-3.0/'				\
	../../www/webkit-gtk/PLIST

# XXX Kludge: --disable-gtk-doc-html is ignored, mv(1) the Documentation
# XXX directory in order to not install it (nii).
pre-install:
	${MV} ${WRKSRC}/Documentation ${WRKSRC}/Documentation.nii

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
