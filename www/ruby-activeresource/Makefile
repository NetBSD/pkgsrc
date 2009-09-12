# $NetBSD: Makefile,v 1.6 2009/09/12 22:14:17 minskim Exp $

DISTNAME=	activeresource-2.3.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activeresource/
COMMENT=	Object-relational mapping for REST webservices

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.2:../../devel/ruby-activesupport

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
