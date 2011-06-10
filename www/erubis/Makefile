# $NetBSD: Makefile,v 1.5 2011/06/10 03:48:01 taca Exp $

DISTNAME=	erubis-2.6.6
CATEGORIES=	www

# Note: www/ruby-actionpack3 needs erubis<2.7.
MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast, secure, and extensible implementation of eRuby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-abstract>=1.0.0:../../devel/ruby-abstract

CONFLICTS+=	ruby[1-9][0-9]-erubis-[0-9]* erubis-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
