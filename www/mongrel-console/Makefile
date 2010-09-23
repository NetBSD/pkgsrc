# $NetBSD: Makefile,v 1.4 2010/09/23 09:22:14 taca Exp $

DISTNAME=	mongrel_console-0.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Mongrel & Rails IRB console

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel

CONFLICTS+=	ruby[1-9][0-9]-mongrel-console-[0-9]* mongrel-console-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
