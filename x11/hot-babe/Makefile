# $NetBSD: Makefile,v 1.7 2004/01/03 18:49:57 reed Exp $
#

DISTNAME=	hot-babe-0.1.2
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://dindinx.net/hotbabe/
COMMENT=	System monitor

USE_BUILDLINK2=	yes
USE_X11=	yes

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
