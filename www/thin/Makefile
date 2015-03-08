# $NetBSD: Makefile,v 1.17 2015/03/08 16:10:37 taca Exp $

DISTNAME=	thin-1.6.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.macournoyer.com/thin/
COMMENT=	Fast and very simple Ruby web server
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack15>=1.0.0:../../www/ruby-rack15
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.0:../../devel/ruby-eventmachine

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
