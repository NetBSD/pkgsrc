# $NetBSD: Makefile,v 1.1.1.1 2004/10/23 06:51:00 jdolecek Exp $

DISTNAME=	gnotime-2.2.0
PKGREVISION=	# empty
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gttr/}

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://gttr.sourceforge.net/
COMMENT=	time tracker for gnome2

USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../www/gtkhtml3/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../devel/guile-gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
