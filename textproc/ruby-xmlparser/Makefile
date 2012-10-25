# $NetBSD: Makefile,v 1.16 2012/10/25 06:56:59 asau Exp $

DISTNAME=	xmlparser-0.7.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#xmlparser
COMMENT=	Ruby bindings to the Expat XML parsing library

WRKSRC=			${WRKDIR}/${DISTNAME:C/-.*//}
USE_RUBY_EXTCONF=	YES
DOCS=			README README.ja Encodings/README.ja
DOCDIR=			${RUBY_DOC}/xmlparser
INSTALLATION_DIRS+=	${DOCDIR}/Encodings

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}/${f}
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
