# $NetBSD: Makefile,v 1.2 2011/08/13 00:14:46 taca Exp $

DISTNAME=	merb-auth-slice-password-reset-1.1.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb Slice for password-reset functionality
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-slices>=1.1.0<1.2:../../www/merb-slices
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-core>=1.1.0<1.2:../../www/merb-auth-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-more>=1.1.0<1.2:../../www/merb-auth-more
DEPENDS+=	${RUBY_PKGPREFIX}-merb-mailer>=1.1.0<1.2:../../www/merb-mailer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
