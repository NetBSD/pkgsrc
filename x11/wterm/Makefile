# $NetBSD: Makefile,v 1.1.1.1 1999/05/03 18:03:29 rh Exp $
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	http://wm.current.nu/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wm.current.nu/files.html\#wterm

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	windowmaker-0.53.0:../../x11/windowmaker

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
