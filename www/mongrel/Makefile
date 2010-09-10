# $NetBSD: Makefile,v 1.10 2010/09/10 12:27:34 taca Exp $

DISTNAME=	mongrel-1.1.5
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Fast HTTP library and server for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.3:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin

RUBY_REQD=	1.8.6.110

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
