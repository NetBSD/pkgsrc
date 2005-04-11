# $NetBSD: Makefile,v 1.5 2005/04/11 21:47:51 tv Exp $
#

DISTNAME=	apachetop-0.12.5
CATEGORIES=	sysutils www
MASTER_SITES=	http://clueful.shagged.org/apachetop/files/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://clueful.shagged.org/apachetop/
COMMENT=	Real time apache log display

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/log/httpd/access_log

# NetBSD releases which do not include wattr_on() et al.
INCOMPAT_CURSES=	NetBSD-1.5*-*
INCOMPAT_CURSES=	NetBSD-1.6-* NetBSD-1.6.*-* NetBSD-1.6[A-Q]-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
