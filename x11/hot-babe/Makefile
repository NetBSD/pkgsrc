# $NetBSD: Makefile,v 1.4 2003/05/02 11:57:09 wiz Exp $
#

DISTNAME=	hot-babe-0.1.2
PKGREVISION=	1
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
