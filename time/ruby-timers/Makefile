# $NetBSD: Makefile,v 1.2 2015/09/13 14:06:36 taca Exp $

DISTNAME=	timers-4.1.1
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celluloid/timers
COMMENT=	Pure Ruby one-shot and periodic timers
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hitimes>=1.2.2:../../time/ruby-hitimes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
