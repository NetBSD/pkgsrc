# $NetBSD: Makefile,v 1.9 2026/04/12 15:17:04 taca Exp $

DISTNAME=		rdiscount-2.2.7.4
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
