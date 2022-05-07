# $NetBSD: Makefile,v 1.7.30.1 2022/05/07 10:01:18 bsiegert Exp $

DISTNAME=	yajl-ruby-1.4.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brianmario/yajl-ruby
COMMENT=	Ruby C binding to YAJL JSON library
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
