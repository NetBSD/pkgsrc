# $NetBSD: Makefile,v 1.2 2003/10/24 21:55:34 cube Exp $
#

DISTNAME=	gtksourceview-0.7.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/0.7/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/gtksourceview
COMMENT=	Text widget that extends GTK2's GtkTextView widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gtksourceview-1.0.pc.in

CONFIGURE_ARGS=		--disable-build-tests
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
