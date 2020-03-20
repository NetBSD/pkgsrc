# $NetBSD: Makefile,v 1.15 2020/03/20 16:29:38 taca Exp $

DISTNAME=	rack-protection-2.0.8.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
