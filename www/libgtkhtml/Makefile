# $NetBSD: Makefile,v 1.22 2004/03/26 02:27:57 wiz Exp $
#

DISTNAME=	libgtkhtml-2.4.1
PKGREVISION=	6
CATEGORIES=	www devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtkhtml/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering GTK2 widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes

PKGCONFIG_OVERRIDE=	libgtkhtml-2.0.pc.in

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
