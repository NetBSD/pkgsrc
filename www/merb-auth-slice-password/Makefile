# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 02:57:05 taca Exp $

DISTNAME=	merb-auth-slice-password-1.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb Slice with password UI support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-slices>=1.1:../../www/merb-slices
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-core>=1.1.1:../../www/merb-auth-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-more>=1.1.1:../../www/merb-auth-more

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
