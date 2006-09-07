# $NetBSD: Makefile,v 1.5 2006/09/07 15:55:50 taca Exp $

DISTNAME=	RedCloth-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-redcloth-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://rubyforge.org/frs/download.php/6064/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/ruby/redcloth/
COMMENT=	Textile library for Ruby

VERSION=	3.0.4
USE_RUBY_SETUP=	yes
DOCS=		CHANGELOG README REFERENCE

RUBY_DYNAMIC_DIRS= ${RUBY_SITERIDIR:S,${PREFIX}/,,}/RedCloth

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/redcloth
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_DOCDIR}/redcloth
.endfor
	${RUBY_GENERATE_PLIST}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
