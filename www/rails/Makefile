# $NetBSD: Makefile,v 1.20 2010/10/13 02:47:19 obache Exp $

DISTNAME=	rails-2.3.9
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.3:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.9:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.9:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.3.9:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=2.3.9:../../mail/ruby-actionmailer
DEPENDS+=	${RUBY_PKGPREFIX}-activeresource>=2.3.9:../../www/ruby-activeresource

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]* rails-[0-9]*

REPLACE_RUBY_DIRS=	bin
REPLACE_RUBY_PAT=	*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
