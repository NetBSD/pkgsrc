# $NetBSD: Makefile,v 1.6 2026/01/18 15:24:29 taca Exp $

DISTNAME=	padrino-helpers-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Helpers for padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-support>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-support
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.1<3:../../textproc/ruby-tilt
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.6.7:../../devel/ruby-i18n

USE_LANGUAGES=	# empty

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
