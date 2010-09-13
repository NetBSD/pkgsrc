# $NetBSD: Makefile,v 1.3 2010/09/13 14:32:41 taca Exp $

DISTNAME=	merb-mailer-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides mailer functionality
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-mailfactory>=1.2.3:../../mail/ruby-mailfactory

CONFLICTS+=	merb-mailer-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
