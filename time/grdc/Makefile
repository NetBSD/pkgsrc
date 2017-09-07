# $NetBSD: Makefile,v 1.12 2017/09/07 07:56:02 wiz Exp $

DISTNAME=		grdc-20031019
PKGREVISION=		2
CATEGORIES=		time
MASTER_SITES=		# ftp://ftp.terabyte.com.ua/pub/software/time/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		https://www.FreeBSD.org/
COMMENT=		Grand digital clock from FreeBSD-current games

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
