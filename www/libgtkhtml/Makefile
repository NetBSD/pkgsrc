# $NetBSD: Makefile,v 1.5 2003/03/15 17:15:37 jmmv Exp $
#

DISTNAME=	libgtkhtml-2.2.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtkhtml/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering GTK2 widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgtkhtml-2.0.pc.in

.include "../../devel/gail/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
