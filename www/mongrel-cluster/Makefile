# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:31 jlam Exp $

DISTNAME=	mongrel_cluster-1.0.5
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Mongrel plugin to manage a mongrel cluster

DEPENDS+=	mongrel>=1.0.2:../../www/mongrel
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
