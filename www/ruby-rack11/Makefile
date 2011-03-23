# $NetBSD: Makefile,v 1.2 2011/03/23 15:27:28 taca Exp $

DISTNAME=	rack-1.1.2
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
