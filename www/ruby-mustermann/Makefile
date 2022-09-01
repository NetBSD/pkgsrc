# $NetBSD: Makefile,v 1.6 2022/09/01 13:46:30 taca Exp $

DISTNAME=	mustermann-2.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sinatra/mustermann
COMMENT=	Use patterns like regular expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.1<0.1:../../devel/ruby-ruby2_keywords

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
