# $NetBSD: Makefile,v 1.4 2003/01/03 15:27:01 jmmv Exp $
#

DISTNAME=	xbindkeys-1.5.5
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://hocwp.free.fr/xbindkeys/xbindkeys.html
COMMENT=	Launches shell commands with your keyboard or your mouse

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
