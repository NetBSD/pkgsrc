# $NetBSD: Makefile,v 1.11 2010/09/13 14:39:31 taca Exp $

DISTNAME=	mongrel-1.1.5
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Fast HTTP library and server for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.3:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin

CONFLICTS+=	ruby[1-9][0-9]-mongrel-[0-9]* mongrel-[0-9]*

RUBY_REQD=	1.8.6.110

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
