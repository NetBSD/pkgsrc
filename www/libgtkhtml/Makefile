# $NetBSD: Makefile,v 1.1.1.1 2002/09/21 01:26:09 rh Exp $
#

DISTNAME=	libgtkhtml-2.0.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=2.0.1/sources/libgtkhtml/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering GTK2 widget

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gail/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
