# $NetBSD: Makefile,v 1.3 2001/05/06 02:02:09 jtb Exp $

DISTNAME=	haskell-cgi-20001206
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.informatik.uni-muenchen.de/~Sven.Panne/haskell_libs/CGI.html
COMMENT=	CGI module for the Hugs Haskell 98 interpreter

DEPENDS+=	hugs98-[0-9]*:../../lang/hugs

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

NO_BUILD= 	#defined

HUGS_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=	HUGS_PREFIX=hugs

do-configure:
	@for i in ${WRKSRC}/*; do					     \
		${SED} -e 's:\/soft\/bin\/runhugs:'${PREFIX}'/bin/runhugs:g' \
		$$i > $$i.tmp && ${MV} $$i.tmp $$i;			     \
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/CGI.lhs ${PREFIX}/share/hugs/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hugs-cgi
	${INSTALL_DATA} ${WRKSRC}/*.cgi ${PREFIX}/share/examples/hugs-cgi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/examples/hugs-cgi
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/examples/hugs-cgi

.include "../../mk/bsd.pkg.mk"
