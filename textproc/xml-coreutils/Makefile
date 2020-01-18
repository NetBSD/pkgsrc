# $NetBSD: Makefile,v 1.7 2020/01/18 23:35:35 rillig Exp $
#

DISTNAME=	xml-coreutils-0.8a
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xml-coreutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xml-coreutils.sourceforge.net/
COMMENT=	Command line tools for XML processing
LICENSE=	gnu-gpl-v3
USE_LANGUAGES=	c99
GNU_CONFIGURE=	yes

# xml-coreutils doesn't actually use curses but does want
# to link to it regardless.
FAKE_NCURSES=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
