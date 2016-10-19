# $NetBSD: Makefile,v 1.5 2016/10/19 14:45:26 taca Exp $

DISTNAME=	padrino-mailer-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Mailer system for padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types2>=2.6<3:../../mail/ruby-mime-types2
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.6<3:../../mail/ruby-mail

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
