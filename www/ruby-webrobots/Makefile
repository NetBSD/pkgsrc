# $NetBSD: Makefile,v 1.8 2014/04/28 21:57:46 joerg Exp $

DISTNAME=	webrobots-0.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/webrobots/
COMMENT=	Ruby library to help write robots.txt compliant web robots
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4.4:../../textproc/ruby-nokogiri

RUBY_VERSION_SUPPORTED=	200 193 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
