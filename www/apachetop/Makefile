# $NetBSD: Makefile,v 1.16 2015/08/17 17:11:30 wiz Exp $
#

DISTNAME=	apachetop-0.12.5
PKGREVISION=	3
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spork.qfe3.net/apachetop/
COMMENT=	Real time apache log display

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/log/httpd/access_log
USE_LANGUAGES=		c c++

# NetBSD releases which do not include wattr_on() et al.
INCOMPAT_CURSES=	NetBSD-1.5*-*
INCOMPAT_CURSES=	NetBSD-1.6-* NetBSD-1.6.*-* NetBSD-1.6[A-Q]-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
