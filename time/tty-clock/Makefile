# $NetBSD: Makefile,v 1.1 2020/12/11 13:48:48 nia Exp $

DISTNAME=	tty-clock-2.3
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=xorg62/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xorg62/tty-clock
COMMENT=	Simple console clock
LICENSE=	modified-bsd

MAKE_FLAGS+=	MANPATH=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

FAKE_NCURSES=	yes

BUILD_TARGET=	tty-clock

LDFLAGS+=	${BUILDLINK_LDADD.curses}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
