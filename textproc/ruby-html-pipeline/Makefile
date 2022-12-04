# $NetBSD: Makefile,v 1.2 2022/12/04 15:58:33 taca Exp $

DISTNAME=	html-pipeline-2.14.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jch/html-pipeline
COMMENT=	Helpers for processing content through a chain of filters
LICENSE=	mit

DEPENDS+=	${RUBY_ACCTIVESUPPORT__DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# empty

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
