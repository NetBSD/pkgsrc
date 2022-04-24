# $NetBSD: Makefile,v 1.8 2022/04/24 14:39:31 taca Exp $

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
