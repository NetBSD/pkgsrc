# $NetBSD: Makefile,v 1.3 2010/09/10 10:53:49 taca Exp $

DISTNAME=	erubis-2.6.6
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast, secure, and extensible implementation of eRuby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-abstract>=1.0.0:../../devel/ruby-abstract

CONFLICTS+=	ruby[1-9][0-9]-erubis-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
