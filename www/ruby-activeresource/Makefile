# $NetBSD: Makefile,v 1.5 2009/04/07 17:13:27 minskim Exp $

DISTNAME=	activeresource-2.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activeresource/
COMMENT=	Object-relational mapping for REST webservices

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.2:../../devel/ruby-activesupport

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
