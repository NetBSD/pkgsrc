# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:25 tv Exp $
#

DISTNAME=	apachetop-0.8.2
PKGREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	http://clueful.shagged.org/apachetop/files/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://clueful.shagged.org/apachetop/
COMMENT=	Real time apache log display

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

# NetBSD releases which do not include wattr_on() et al.
INCOMPAT_CURSES=	NetBSD-1.5*-*
INCOMPAT_CURSES=	NetBSD-1.6-* NetBSD-1.6.*-* NetBSD-1.6[A-Q]-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
