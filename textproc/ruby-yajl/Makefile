# $NetBSD: Makefile,v 1.5 2017/03/20 16:24:37 taca Exp $

DISTNAME=	yajl-ruby-1.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brianmario/yajl-ruby
COMMENT=	Ruby C binding to YAJL JSON library
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
