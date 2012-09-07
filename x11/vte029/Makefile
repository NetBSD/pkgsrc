# $NetBSD: Makefile,v 1.2 2012/09/07 19:17:53 adam Exp $
#

.include "Makefile.common"

PKGREVISION=	1
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-ft-exec-prefix=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--enable-Bsymbolic=auto

pre-configure:
	set -e; cd ${WRKSRC}/gnome-pty-helper; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.31.13
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pang+=	pango>=1.22.0
.include "../../devel/pango/buildlink3.mk"
# for FC_WIDTH
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.1.93
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=		gtk3+>=3.1.9
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
