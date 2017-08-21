# $NetBSD: Makefile,v 1.1 2017/08/21 11:56:15 nils Exp $

DISTNAME=		rdiscount-2.2.0.1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		http://dafoster.net/projects/rdiscount/
COMMENT=		Converts documents in Markdown syntax to HTML
LICENSE=		modified-bsd

RUBYGEM_OPTIONS+=	--format-executable

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/rdiscount.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${RUBY_PKGPREFIX}-rdiscount.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
