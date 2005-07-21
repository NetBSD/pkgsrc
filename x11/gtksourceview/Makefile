# $NetBSD: Makefile,v 1.24 2005/07/21 16:30:01 wiz Exp $
#

DISTNAME=	gtksourceview-1.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gtksourceview.sourceforge.net/
COMMENT=	Text widget that extends GTK2's GtkTextView widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl

PKGCONFIG_OVERRIDE=	gtksourceview-1.0.pc.in

CONFIGURE_ARGS=		--disable-build-tests
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
