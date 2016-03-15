# $NetBSD: Makefile,v 1.4 2016/03/15 16:41:50 taca Exp $

DISTNAME=	padrino-mailer-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Mailer system for padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-mail25>=2.5<3:../../mail/ruby-mail

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
