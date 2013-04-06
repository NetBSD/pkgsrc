# $NetBSD: Makefile,v 1.4 2013/04/06 12:08:40 rodent Exp $

DISTNAME=	staticmatic-0.11.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staticmatic.net/
COMMENT=	Lightweight static site framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.0:../../textproc/ruby-haml
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-compass>=0.10.0:../../www/ruby-compass

CONFLICTS+=	ruby[1-9][0-9]-staticmatic-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
