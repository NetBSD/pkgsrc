# $NetBSD: Makefile,v 1.3 2012/01/08 11:08:23 obache Exp $

DISTNAME=	rack-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Ruby webserver interface
LICENSE=	mit

CONFLICTS=	ruby[1-9][0-9]-rack-[0-9]*

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
