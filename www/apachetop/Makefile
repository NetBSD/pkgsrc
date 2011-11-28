# $NetBSD: Makefile,v 1.13 2011/11/28 00:06:18 wiz Exp $
#

DISTNAME=	apachetop-0.12.5
PKGREVISION=	2
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spork.qfe3.net/apachetop/
COMMENT=	Real time apache log display

PKG_DESTDIR_SUPPORT=	user-destdir

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
