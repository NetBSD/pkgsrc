# $NetBSD: Makefile,v 1.14 2004/01/03 18:49:55 reed Exp $
#

DISTNAME=	libgtkhtml-2.4.1
PKGREVISION=	2
CATEGORIES=	www devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtkhtml/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering GTK2 widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	libgtkhtml-2.0.pc.in

.include "../../devel/gail/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
