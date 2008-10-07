# $NetBSD: Makefile,v 1.9 2008/10/07 05:28:33 minskim Exp $

DISTNAME=	mongrel-1.1.5
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Fast HTTP library and server for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin

RUBY_REQD=	1.8.6.110
GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
