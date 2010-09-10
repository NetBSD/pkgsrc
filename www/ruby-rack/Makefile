# $NetBSD: Makefile,v 1.5 2010/09/10 13:16:50 taca Exp $

DISTNAME=	rack-1.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
