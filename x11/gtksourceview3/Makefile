# $NetBSD: Makefile,v 1.72 2024/05/29 16:35:00 adam Exp $

DISTNAME=	gtksourceview-3.24.11
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview3/}
PKGREVISION=	20
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/GtkSourceView
COMMENT=	Text widget that extends GTK3's GtkTextView widget (v3)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed msgfmt pkg-config itstool
USE_PKGLOCALEDIR=	yes
#CONFIGURE_ARGS+=	--disable-deprecations
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--disable-vala

PKGCONFIG_OVERRIDE+=	gtksourceview-3.0.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtksourceview3
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}
PLIST_VARS+=		introspection

.include "../../mk/bsd.options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.48
.include "../../devel/glib2/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.42.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.20
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
