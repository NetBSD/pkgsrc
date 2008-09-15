# $NetBSD: Makefile,v 1.4 2008/09/15 05:43:01 minskim Exp $

DISTNAME=	activeresource-2.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activeresource/
COMMENT=	Object-relational mapping for REST webservices

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.1.1:../../devel/ruby-activesupport

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
