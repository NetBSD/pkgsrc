# $NetBSD: Makefile,v 1.5 2013/02/08 13:19:13 taca Exp $

DISTNAME=	rack-1.2.8
CATEGORIES=	www

# Note: www/ruby-actionpack3needs ruby-rack<1.3.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
