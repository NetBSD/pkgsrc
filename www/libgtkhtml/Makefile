# $NetBSD: Makefile,v 1.34 2006/01/24 07:32:48 wiz Exp $
#

DISTNAME=	libgtkhtml-2.6.3
PKGREVISION=	2
CATEGORIES=	www devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtkhtml/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering GTK2 widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libgtkhtml-2.0.pc.in

.include "../../devel/gail/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
