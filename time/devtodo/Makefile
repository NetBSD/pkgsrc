# $NetBSD: Makefile,v 1.3 2001/04/16 08:00:43 zuntum Exp $
#

DISTNAME=	devtodo-0.1.4
CATEGORIES=	time
MASTER_SITES=	http://ftp1.sourceforge.net/devtodo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

DEPENDS+=	readline-[0-9]*:../../devel/readline

GNU_CONFIGURE=	yes
MAKE_ENV+=	CXXFLAGS=-Wl,-R${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
