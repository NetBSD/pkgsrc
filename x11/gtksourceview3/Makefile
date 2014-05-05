# $NetBSD: Makefile,v 1.19 2014/05/05 00:48:30 ryoon Exp $
#

DISTNAME=	gtksourceview-3.10.2
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview3/}
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://projects.gnome.org/gtksourceview/
COMMENT=	Text widget that extends GTK3's GtkTextView widget
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
#CONFIGURE_ARGS+=	--disable-deprecations
CONFIGURE_ARGS+=	--disable-maintainer-mode

PKGCONFIG_OVERRIDE+=	gtksourceview-3.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
