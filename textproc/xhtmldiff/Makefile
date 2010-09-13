# $NetBSD: Makefile,v 1.5 2010/09/13 14:39:30 taca Exp $

DISTNAME=	xhtmldiff-1.2.2
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://theinternetco.net/projects/ruby/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# http://theinternetco.net/projects/ruby/xhtmldiff.html
COMMENT=	Tool for generating valid XHTML redline documents
LICENSE=	# unknown

DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.1:../../textproc/ruby-diff-lcs

CONFLICTS+=	ruby[1-9][0-9]-xhtmldiff-[0-9]* xhtmldiff-[0-9]*

RUBY_VERSION_SUPPORTED= 18

post-extract:
	cp ${WRKSRC}/packaging/xhtmldiff.gemspec ${GEM_SPECFILE}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
