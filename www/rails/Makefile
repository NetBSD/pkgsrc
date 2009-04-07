# $NetBSD: Makefile,v 1.15 2009/04/07 17:13:27 minskim Exp $

DISTNAME=	rails-2.3.2
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications

DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.2:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.2:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-activeresource>=2.3.2:../../www/ruby-activeresource
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.3.2:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=2.3.2:../../mail/ruby-actionmailer

REPLACE_RUBY=	bin/about bin/console bin/dbconsole bin/destroy \
		bin/generate bin/performance/benchmarker \
		bin/performance/profiler bin/plugin bin/runner bin/server

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
