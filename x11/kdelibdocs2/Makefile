# $NetBSD: Makefile,v 1.1.1.1 2001/08/01 08:57:36 skrll Exp $
#

DISTNAME=	kdelibdocs_kdoc2-1.1
PKGNAME=	kdelibdocs-2.1
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://ftp.kdevelop.org/pub/kdevelop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	KDE library documentation

BUILD_USES_MSGFMT=	yes
DEPENDS+=       kdelibs>=2.1:../../x11/kdelibs2
DEPENDS+=	qt2-docs>=2.2.4:../../x11/qt2-docs

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ARGS+= --with-qtdoc-dir=${QT2DIR}/qt2/doc/html

.include "../../mk/bsd.pkg.mk"
