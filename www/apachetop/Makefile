# $NetBSD: Makefile,v 1.9 2006/07/22 04:46:19 rillig Exp $
#

DISTNAME=	apachetop-0.12.5
PKGREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	http://spork.qfe3.net/apachetop/files/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://spork.qfe3.net/apachetop/
COMMENT=	Real time apache log display

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/log/httpd/access_log
USE_LANGUAGES=		c c++

# NetBSD releases which do not include wattr_on() et al.
INCOMPAT_CURSES=	NetBSD-1.5*-*
INCOMPAT_CURSES=	NetBSD-1.6-* NetBSD-1.6.*-* NetBSD-1.6[A-Q]-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
