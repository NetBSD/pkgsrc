# $NetBSD: Makefile,v 1.11 2004/12/28 23:18:17 reed Exp $

DISTNAME=	hot-babe-0.1.2
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://dindinx.net/hotbabe/
COMMENT=	System load monitor

USE_BUILDLINK3=	yes
USE_X11=	yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
