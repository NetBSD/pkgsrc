# $NetBSD: Makefile,v 1.3 2020/09/14 15:05:28 taca Exp $

DISTNAME=		rdiscount-2.2.0.2
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://dafoster.net/projects/rdiscount/
COMMENT=		Converts documents in Markdown syntax to HTML
LICENSE=		modified-bsd

RUBYGEM_OPTIONS+=	--format-executable

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/rdiscount.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${RUBY_PKGPREFIX}-rdiscount.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
