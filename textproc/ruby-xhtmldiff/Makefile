# $NetBSD: Makefile,v 1.1 2017/06/04 16:49:35 taca Exp $

DISTNAME=	xhtmldiff-1.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://theinternetco.net/projects/ruby/
# necessary since it will be overwritten by gem.mk
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# http://theinternetco.net/projects/ruby/xhtmldiff.html
COMMENT=	Tool for generating valid XHTML redline documents

DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.1:../../textproc/ruby-diff-lcs

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${CP} ${WRKSRC}/packaging/xhtmldiff.gemspec ${GEM_SPECFILE}
	${RM} -fr ${WRKSRC}/packaging

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
