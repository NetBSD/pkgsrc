# $NetBSD: Makefile,v 1.3 1999/06/21 07:53:49 tron Exp $
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	http://wm.current.nu/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wm.current.nu/files.html\#wterm

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	windowmaker-0.60.0:../../x11/windowmaker

USE_X11=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-I${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
