# $NetBSD: Makefile,v 1.11.4.2 2011/03/05 11:03:04 tron Exp $

DISTNAME=	mongrel-1.1.5
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Fast HTTP library and server for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.3:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin

CONFLICTS+=	ruby[1-9][0-9]-mongrel-[0-9]* mongrel-[0-9]*

# use pre-generated gemspec file to avoid rubygems's incompatibility.
post-extract:
	${CP} ${FILESDIR}/gemspec ${WRKDIR}/${DISTNAME}.gemspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
