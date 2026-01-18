# $NetBSD: Makefile,v 1.1 2026/01/18 14:58:02 taca Exp $

DISTNAME=	bullet-8.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flyerhzm/bullet
COMMENT=	Help to kill N+1 queries and unused eager loading
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-uniform_notifier>=1.11<2:../../misc/ruby-uniform_notifier
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_ACCEPTED=	# any

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
