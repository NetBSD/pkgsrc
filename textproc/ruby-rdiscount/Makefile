# $NetBSD: Makefile,v 1.5 2022/12/29 16:23:52 taca Exp $

DISTNAME=		rdiscount-2.2.7
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
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
