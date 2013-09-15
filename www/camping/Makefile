# $NetBSD: Makefile,v 1.8 2013/09/15 16:42:23 taca Exp $

DISTNAME=	camping-2.1.532
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://camping.io/
COMMENT=	Ruby micro-framework for web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mab>=0.0.3:../../textproc/ruby-mab
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack

CONFLICTS+=	ruby[1-9][0-9]*-camping-[0-9]* camping-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
