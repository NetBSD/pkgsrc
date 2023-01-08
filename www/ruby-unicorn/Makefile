# $NetBSD: Makefile,v 1.21.2.1 2023/01/08 15:57:25 bsiegert Exp $

DISTNAME=	unicorn-6.1.0
PKGREVISION=	3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bogomips.org/unicorn/
COMMENT=	Rack HTTP server for fast clients and Unix
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-kgio>=2.6<3:../../devel/ruby-kgio
DEPENDS+=	${RUBY_PKGPREFIX}-raindrops>=0.7<1:../../www/ruby-raindrops

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
