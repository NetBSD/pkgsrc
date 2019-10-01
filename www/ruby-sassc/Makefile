# $NetBSD: Makefile,v 1.1 2019/10/01 15:34:50 ryoon Exp $

DISTNAME=	sassc-2.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sass/sassc-ruby
COMMENT=	Use libsass with Ruby
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.9<2:../../devel/ruby-ffi

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
