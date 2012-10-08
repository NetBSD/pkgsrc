# $NetBSD: Makefile,v 1.8 2012/10/08 13:04:18 asau Exp $

DISTNAME=		grdc-20031019
CATEGORIES=		time
MASTER_SITES=		# ftp://ftp.terabyte.com.ua/pub/software/time/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://www.FreeBSD.org/
COMMENT=		Grand digital clock from FreeBSD-current games

INSTALLATION_DIRS+=	bin man/man6
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
