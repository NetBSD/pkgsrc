# $NetBSD: Makefile,v 1.1.1.1 2003/12/13 17:54:14 xtraeme Exp $
#

DISTNAME=	vte-0.11.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vte/0.11/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/vte.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
