# $NetBSD: Makefile,v 1.2 2011/08/13 00:13:17 taca Exp $

DISTNAME=	merb-auth-slice-password-1.1.1
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb Slice with password UI support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-slices>=1.1<2:../../www/merb-slices
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-core>=1.1.1<1.2:../../www/merb-auth-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth-more>=1.1.1<1.2:../../www/merb-auth-more

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
