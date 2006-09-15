# $NetBSD: Makefile,v 1.40 2006/09/15 15:16:42 jmmv Exp $
#

DISTNAME=	vte-0.14.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vte/0.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support

USE_DIRS+=		gnome2-1.2
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--with-ft-exec-prefix=${BUILDLINK_PREFIX.freetype2}

PKGCONFIG_OVERRIDE+=	vte.pc.in

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.10.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
# for FC_WIDTH
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.1.93

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
