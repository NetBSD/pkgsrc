# $NetBSD: Makefile,v 1.9 2001/02/17 17:22:39 wiz Exp $
#

DISTNAME=	surfraw-1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=surfraw/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/
COMMENT=	Shell Users' Revolutionary Front Rage Against the Web

CONFLICTS+=	surfaw-*

GNU_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/surfraw

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/etc/surfraw.conf.dist
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
