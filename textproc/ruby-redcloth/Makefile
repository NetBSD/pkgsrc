# $NetBSD: Makefile,v 1.3 2005/09/22 01:40:23 minskim Exp $

DISTNAME=	RedCloth-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-redcloth-${VER}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://rubyforge.org/frs/download.php/2896/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/ruby/redcloth/
COMMENT=	Textile library for Ruby

USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
VER=		3.0.3

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/redcloth
	${INSTALL_DATA} ${WRKSRC}/doc/README ${RUBY_DOCDIR}/redcloth

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
