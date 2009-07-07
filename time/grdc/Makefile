# $NetBSD: Makefile,v 1.6 2009/07/07 20:11:57 joerg Exp $

DISTNAME=		grdc-20031019
CATEGORIES=		time
MASTER_SITES=		# ftp://ftp.terabyte.com.ua/pub/software/time/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://www.FreeBSD.org/
COMMENT=		Grand digital clock from FreeBSD-current games

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin man/man6
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
