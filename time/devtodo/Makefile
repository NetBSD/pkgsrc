# $NetBSD: Makefile,v 1.4 2001/04/22 11:44:46 zuntum Exp $
#

DISTNAME=	devtodo-0.1.5
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=devtodo/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

DEPENDS+=	readline-[0-9]*:../../devel/readline

GNU_CONFIGURE=	yes
MAKE_ENV+=	CXXFLAGS="-Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
