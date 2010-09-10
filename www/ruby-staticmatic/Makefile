# $NetBSD: Makefile,v 1.2 2010/09/10 13:20:04 taca Exp $

DISTNAME=	staticmatic-0.10.8
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staticmatic.net
COMMENT=	Lightweight static site framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.0:../../textproc/ruby-haml
DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.1.5:../../www/mongrel

CONFLICTS+=	ruby[1-9][0-9]-staticmatic-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
