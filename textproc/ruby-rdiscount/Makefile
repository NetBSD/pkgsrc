# $NetBSD: Makefile,v 1.4 2022/12/23 13:38:46 taca Exp $

DISTNAME=		rdiscount-2.2.7
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://dafoster.net/projects/rdiscount/
COMMENT=		Converts documents in Markdown syntax to HTML
LICENSE=		modified-bsd

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
