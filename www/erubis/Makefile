# $NetBSD: Makefile,v 1.4 2010/09/13 14:12:14 taca Exp $

DISTNAME=	erubis-2.6.6
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast, secure, and extensible implementation of eRuby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-abstract>=1.0.0:../../devel/ruby-abstract

CONFLICTS+=	ruby[1-9][0-9]-erubis-[0-9]* erubis-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
