# $NetBSD: Makefile,v 1.5 2003/07/13 13:54:05 wiz Exp $
#

DISTNAME=	hot-babe-0.1.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://dindinx.net/hotbabe/
COMMENT=	System monitor

USE_BUILDLINK2=	yes
USE_X11=	yes

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
