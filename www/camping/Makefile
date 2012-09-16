# $NetBSD: Makefile,v 1.6 2012/09/16 14:34:35 taca Exp $

DISTNAME=	camping-2.1.523
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/camping/
COMMENT=	Ruby micro-framework for web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mab>=0:../../textproc/ruby-mab
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack

CONFLICTS+=	ruby[1-9][0-9]-camping-[0-9]* camping-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
