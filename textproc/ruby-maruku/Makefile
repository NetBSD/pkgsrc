# $NetBSD: Makefile,v 1.4 2008/09/15 06:05:47 minskim Exp $

DISTNAME=	maruku-0.5.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://maruku.rubyforge.org/
COMMENT=	Markdown-superset interpreter

DEPENDS+=	${RUBY_PKGPREFIX}-syntax>=1.0.0:../../textproc/ruby-syntax

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
