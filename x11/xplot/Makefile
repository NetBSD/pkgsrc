# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:58 agc Exp $
#

DISTNAME=	xplot-0.90
CATEGORIES=	x11
MASTER_SITES=	ftp://mercury.lcs.mit.edu/pub/shep/

MAINTAINER=	thorpej@netbsd.org

GNU_CONFIGURE=	yes

DOCFILES=	ANNOUNCE README README.tcp_plots demo.0 demo.1 demo.2 \
		demo.3 demo.4 demo.5 demo.6 demo.7

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xplot
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xplot
.endfor
.endif

.include "../../mk/bsd.pkg.mk"
