# $NetBSD: Makefile,v 1.4.2.1 2023/01/08 15:57:25 bsiegert Exp $

DISTNAME=		rdiscount-2.2.7
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		2
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
