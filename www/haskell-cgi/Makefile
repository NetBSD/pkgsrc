# $NetBSD: Makefile,v 1.1.1.1 2000/12/06 22:05:56 jtb Exp $

DISTNAME=	haskell-cgi-20001206
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.informatik.uni-muenchen.de/~Sven.Panne/haskell_libs/CGI.html

DEPENDS+=	hugs98-[0-9]*:../../lang/hugs

NO_BUILD= 	YES
EVAL_PREFIX+=	PREFIX=hugs

do-configure:
	@for i in ${WRKSRC}/* ; do \
	${SED} -e 's:\/soft\/bin\/runhugs:'${PREFIX}'/bin/runhugs:g' \
	< $$i > $$i.tmp && ${MV} $$i.tmp $$i ; done

do-install:
	${INSTALL_DATA} ${WRKSRC}/CGI.lhs ${PREFIX}/share/hugs/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hugs-cgi
	for c in ${WRKSRC}/*.cgi ; do \
	${INSTALL_SCRIPT} $$c ${PREFIX}/share/examples/hugs-cgi ; done
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/examples/hugs-cgi
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/examples/hugs-cgi

.include "../../mk/bsd.pkg.mk"
