# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 02:57:54 taca Exp $

DISTNAME=	merb-auth-slice-password-reset-1.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb Slice for password-reset functionality
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-slices>=1.1:../../www/merb-slices
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-core>=1.1.1:../../www/merb-auth-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-more>=1.1.1:../../www/merb-auth-more
DEPENDS+=	${RUBY_PKGPREFIX}-merb-mailer>=1.1.1:../../www/merb-mailer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
