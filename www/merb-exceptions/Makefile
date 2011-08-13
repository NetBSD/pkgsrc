# $NetBSD: Makefile,v 1.2 2011/08/13 00:18:06 taca Exp $

DISTNAME=	merb-exceptions-1.1.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that supports exception notification
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3<1.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-mailer>=1.1.3<1.2:../../www/merb-mailer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
