# $NetBSD: Makefile,v 1.1.1.1 2004/11/28 04:51:38 taca Exp $
#

DISTNAME=	xmlparser-0.6.8
PKGNAME=	${RUBY_PKGPREFIX}-xmlparser-0.6.8
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#xmlparser
COMMENT=	expat interface module for Ruby

USE_BUILDLINK3=		yes
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
