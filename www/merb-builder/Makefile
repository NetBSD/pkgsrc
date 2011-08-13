# $NetBSD: Makefile,v 1.4 2011/08/13 00:17:16 taca Exp $

DISTNAME=	merb_builder-0.9.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for ruby-builder XML generation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.8:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

CONFLICTS+=	merb-builder-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
