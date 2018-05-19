# $NetBSD: Makefile,v 1.20.8.1 2018/05/19 09:14:24 spz Exp $
#

DISTNAME=	apachetop-0.18.4
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tessus/apachetop/archive/}
DISTFILES=	0.18.4.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tessus/apachetop
COMMENT=	Real time apache log display
LICENSE=	modified-bsd

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/log/httpd/access_log
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
