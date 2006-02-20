# $NetBSD: Makefile,v 1.1.1.1 2006/02/20 12:07:12 adam Exp $

DISTNAME=	qt4-${QTVERSION}
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "./Makefile.common"

DEPENDS+=	qt4-libs-${QTVERSION}{,nb[0-9]*}:../../x11/qt4-libs
DEPENDS+=	qt4-tools-${QTVERSION}{,nb[0-9]*}:../../x11/qt4-tools
DEPENDS+=	qt4-docs-${QTVERSION}{,nb[0-9]*}:../../x11/qt4-docs

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
