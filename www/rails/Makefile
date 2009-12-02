# $NetBSD: Makefile,v 1.16.2.1 2009/12/02 23:17:10 tron Exp $

DISTNAME=	rails-2.3.5
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications

DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.5:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.5:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=2.3.5:../../mail/ruby-actionmailer
DEPENDS+=	${RUBY_PKGPREFIX}-activeresource>=2.3.5:../../www/ruby-activeresource
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.3.5:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack

REPLACE_RUBY=	bin/about bin/console bin/dbconsole bin/destroy \
		bin/generate bin/performance/benchmarker \
		bin/performance/profiler bin/plugin bin/runner bin/server

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
