# $NetBSD: Makefile,v 1.3 2008/04/21 16:09:42 jlam Exp $

DISTNAME=	thin-0.8.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.macournoyer.com/thin/
COMMENT=	Fast and very simple Ruby web server

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.2.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.10.0:../../devel/ruby-eventmachine

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
