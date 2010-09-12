# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 02:59:29 taca Exp $

DISTNAME=	merb-exceptions-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that supports exception notification
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-mailer>=1.1.3:../../www/merb-mailer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
