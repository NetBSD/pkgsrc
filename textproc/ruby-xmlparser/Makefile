# $NetBSD: Makefile,v 1.5 2005/06/25 02:34:27 taca Exp $
#

DISTNAME=	xmlparser-0.6.8.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#xmlparser
COMMENT=	Expat interface module for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
CONFIGURE_ARGS+=	--with-perl-enc-map
WRKSRC=			${WRKDIR}/xmlparser
REPLACE_RUBY_DIRS=	${WRKSRC}/samples

pre-patch:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/samples; ${RM} -r */CVS

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlparser
	${CP} -r ${WRKSRC}/samples/* ${RUBY_EXAMPLESDIR}/xmlparser

.include "../../lang/ruby/modules.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
