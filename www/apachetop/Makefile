# $NetBSD: Makefile,v 1.19 2017/01/04 14:53:02 roy Exp $
#

DISTNAME=	apachetop-0.12.5
PKGREVISION=	4
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spork.qfe3.net/apachetop/
COMMENT=	Real time apache log display

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/log/httpd/access_log
USE_LANGUAGES=		c c++

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
