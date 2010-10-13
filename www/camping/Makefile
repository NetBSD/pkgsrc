# $NetBSD: Makefile,v 1.4 2010/10/13 11:33:47 obache Exp $

DISTNAME=	camping-2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/camping/
COMMENT=	Ruby micro-framework for web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack

CONFLICTS+=	ruby[1-9][0-9]-camping-[0-9]* camping-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
