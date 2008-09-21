# $NetBSD: Makefile,v 1.14 2008/09/21 21:54:01 minskim Exp $

DISTNAME=	rails-2.1.1
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications

DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.1.1:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.1.1:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-activeresource>=2.1.1:../../www/ruby-activeresource
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.1.1:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=2.1.1:../../mail/ruby-actionmailer

REPLACE_RUBY=	bin/about bin/console bin/dbconsole bin/destroy bin/generate	\
		bin/performance/benchmarker bin/performance/profiler		\
		bin/performance/request bin/plugin bin/process/inspector	\
		bin/process/reaper bin/process/spawner bin/runner bin/server

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
