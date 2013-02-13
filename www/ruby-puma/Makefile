# $NetBSD: Makefile,v 1.1 2013/02/13 15:41:00 taca Exp $

DISTNAME=	puma-1.6.3
CATEGORIES=	www

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://puma.io/
COMMENT=	Modern concurrent web server for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.2<2:../../www/ruby-rack

CONFLICTS+=	ruby[1-9][0-9][0-9]-puma-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
