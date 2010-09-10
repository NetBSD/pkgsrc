# $NetBSD: Makefile,v 1.2 2010/09/10 12:30:39 taca Exp $

DISTNAME=	mongrel_console-0.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Mongrel & Rails IRB console
LICENSE=	# unknown

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
