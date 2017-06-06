# $NetBSD: Makefile,v 1.3 2017/06/06 11:12:05 jperkin Exp $

DISTNAME=	padrino-contrib-0.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.padrinorb.com/
COMMENT=	Contributed plugins and utilities for Padrino Framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=0.12.3:../../www/ruby-padrino-core

RUBY_VERSIONS_ACCEPTED=	22 23	# www/ruby-rack via www/ruby-padrino-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
