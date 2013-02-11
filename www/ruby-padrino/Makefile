# $NetBSD: Makefile,v 1.1 2013/02/11 14:34:54 taca Exp $

DISTNAME=	padrino-${RUBY_PADRINO_VERS}
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Padrino Ruby Web framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-cache>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-cache
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-gen>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-gen
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-admin>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-admin
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-mailer>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-mailer

META_PACKAGE=	yes

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
