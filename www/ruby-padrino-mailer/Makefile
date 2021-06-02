# $NetBSD: Makefile,v 1.6 2021/06/02 15:09:53 taca Exp $

DISTNAME=	padrino-mailer-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Mailer system for padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.3.1<4:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.6<3:../../mail/ruby-mail

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
