# $NetBSD: Makefile,v 1.15 2004/04/19 14:36:42 jmmv Exp $
#

DISTNAME=	gtksourceview-1.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/gtksourceview
COMMENT=	Text widget that extends GTK2's GtkTextView widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make

PKGCONFIG_OVERRIDE=	gtksourceview-1.0.pc.in

CONFIGURE_ARGS=		--disable-build-tests
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
