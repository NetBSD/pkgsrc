# $NetBSD: Makefile,v 1.3 2011/06/19 08:06:33 taca Exp $

DISTNAME=	staticmatic-0.11.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staticmatic.net
COMMENT=	Lightweight static site framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.0:../../textproc/ruby-haml
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-compass>=0.10.0:../../www/ruby-compass

CONFLICTS+=	ruby[1-9][0-9]-staticmatic-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
