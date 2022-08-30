# $NetBSD: Makefile,v 1.9 2022/08/30 15:51:38 taca Exp $

DISTNAME=	yajl-ruby-1.4.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brianmario/yajl-ruby
COMMENT=	Ruby C binding to YAJL JSON library
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
