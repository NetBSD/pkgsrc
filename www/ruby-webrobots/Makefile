# $NetBSD: Makefile,v 1.10 2016/02/01 14:08:23 taca Exp $

DISTNAME=	webrobots-0.1.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/webrobots/
COMMENT=	Ruby library to help write robots.txt compliant web robots
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4.4:../../textproc/ruby-nokogiri

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
