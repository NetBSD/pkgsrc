# $NetBSD: Makefile,v 1.7 2000/10/31 13:48:37 jlam Exp $
#

DISTNAME=	surfraw-1.0.2
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfraw/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/

CONFLICTS+=	surfaw-*

GNU_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/surfraw

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/etc/surfraw.conf.dist
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
