# $NetBSD: Makefile,v 1.5 2001/05/15 06:54:23 zuntum Exp $
#

DISTNAME=	devtodo-0.1.6-1
PKGNAME=	devtodo-0.1.6.1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=devtodo/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

DEPENDS+=	readline-[0-9]*:../../devel/readline

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1//}

GNU_CONFIGURE=	yes
MAKE_ENV+=	CXXFLAGS="-Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
