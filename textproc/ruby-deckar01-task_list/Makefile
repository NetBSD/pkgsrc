# $NetBSD: Makefile,v 1.3 2024/03/04 15:18:46 taca Exp $

DISTNAME=	deckar01-task_list-2.3.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/deckar01/task_list
COMMENT=	Markdown TaskList components
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-html-pipeline>=2.0<3:../../textproc/ruby-html-pipeline

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
