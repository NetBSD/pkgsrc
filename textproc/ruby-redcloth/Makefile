# $NetBSD: Makefile,v 1.8 2007/10/03 14:45:42 heinz Exp $

DISTNAME=	RedCloth-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-redcloth-${VERSION}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://rubyforge.org/frs/download.php/6064/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.whytheluckystiff.net/ruby/redcloth/
COMMENT=	Textile library for Ruby

VERSION=	3.0.4
REPLACE_RUBY=	${WRKSRC}/bin/redcloth
USE_RUBY_SETUP=	yes

DOCS=		CHANGELOG README REFERENCE

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/redcloth
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_DOCDIR}/redcloth
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
