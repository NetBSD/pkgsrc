# $NetBSD: Makefile,v 1.4 2016/10/18 15:56:31 taca Exp $

DISTNAME=	mustermann19-0.4.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/namusyaka/mustermann
COMMENT=	Use patterns like regular expressions
LICENSE=	mit

# enumerable-lazy is not needed Ruby 2.0 and later.
OVERRIDE_GEMSPEC+=	enumerable-lazy:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
