# $NetBSD: Makefile,v 1.5 2018/11/12 03:51:30 ryoon Exp $

DISTNAME=	gtksourceview-4.0.2
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview4/}
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/GtkSourceView
COMMENT=	Text widget that extends GTK3's GtkTextView widget (v4)
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--disable-vala

# needs DISPLAY
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	gtksourceview.pc.in

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.48
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.20
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
