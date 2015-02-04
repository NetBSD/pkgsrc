# $NetBSD: Makefile,v 1.3 2015/02/04 14:57:44 taca Exp $

DISTNAME=	padrino-mailer-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Mailer system for padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-mail25>=2.5.3<2.6:../../mail/ruby-mail25

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
