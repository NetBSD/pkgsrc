# $NetBSD: Makefile,v 1.4 2018/03/23 14:33:21 taca Exp $

DISTNAME=	loofah-2.2.2
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/kieranmasterton/loofah
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.5.9:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-crass>=1.0.2<1.1:../../www/ruby-crass

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
