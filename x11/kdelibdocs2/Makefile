# $NetBSD: Makefile,v 1.2 2001/11/13 21:29:20 jlam Exp $

DISTNAME=	kdelibdocs_kdoc2-1.1
PKGNAME=	kdelibdocs-2.1
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://ftp.kdevelop.org/pub/kdevelop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	KDE library documentation

DEPENDS+=	qt2-docs>=2.2.4:../../x11/qt2-docs

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-qtdoc-dir=${QTDIR}/qt2/doc/html

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
