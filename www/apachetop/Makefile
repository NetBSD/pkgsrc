# $NetBSD: Makefile,v 1.2 2004/04/27 05:44:23 snj Exp $
#

DISTNAME=	apachetop-0.8.2
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
