# $NetBSD: Makefile,v 1.2 2008/04/04 15:22:47 jlam Exp $

DISTNAME=	erubis-2.5.0
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast, secure, and extensible implementation of eRuby

DEPENDS+=	${RUBY_PKGPREFIX}-abstract>=1.0.0:../../devel/ruby-abstract

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
