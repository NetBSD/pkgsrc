# $NetBSD: Makefile,v 1.20 2023/08/11 13:38:58 taca Exp $

DISTNAME=	rack-protection-3.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2:../../www/ruby-rack2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
