# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=	gnome-themes-extras-0.5
PKGREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-themes-extras/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Extra themes for GNOME 2

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../x11/gtk2-engines/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
