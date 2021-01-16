# $NetBSD: Makefile,v 1.22 2021/01/16 13:43:38 taca Exp $

DISTNAME=	thin-1.8.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/macournoyer/thin
COMMENT=	Fast and very simple Ruby web server
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.6.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.4:../../devel/ruby-eventmachine

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
