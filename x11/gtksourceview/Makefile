# $NetBSD: Makefile,v 1.28 2005/12/05 20:51:17 rillig Exp $
#

DISTNAME=	gtksourceview-1.4.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/1.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gtksourceview.sourceforge.net/
COMMENT=	Text widget that extends GTK2's GtkTextView widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config

PKGCONFIG_OVERRIDE=	gtksourceview-1.0.pc.in

CONFIGURE_ARGS+=	--disable-build-tests
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
