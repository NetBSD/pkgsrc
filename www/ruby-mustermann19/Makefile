# $NetBSD: Makefile,v 1.3 2016/03/15 16:48:53 taca Exp $

DISTNAME=	mustermann19-0.4.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/namusyaka/mustermann
COMMENT=	Use patterns like regular expressions
LICENSE=	mit

# enumerable-lazy is not needed Ruby 2.0 and later.
OVERRIDE_GEMSPEC+=	enumerable-lazy:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
