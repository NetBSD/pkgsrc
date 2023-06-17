# $NetBSD: Makefile,v 1.7 2023/06/17 15:27:05 taca Exp $

DISTNAME=		rdiscount-2.2.7.1
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
