# $NetBSD: Makefile,v 1.7 2001/01/29 11:34:44 wiz Exp $
#

DISTNAME=	adzap-20010112
CATEGORIES=	www perl5
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zip.com.au/~cs/adzap/index.html
WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	# defined
USE_PERL5=	# defined

do-configure:
.for FILE in squid_redirect wrapzap
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.orig
	${SED} -e "s:/usr/bin/perl:${PERL5}:g" \
	       -e "s:@@PREFIX@@:${PREFIX}:g" \
		<${WRKSRC}/${FILE}.orig >${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/wrapzap ${PREFIX}/libexec/adzap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/adzap
.for FILE in adzap.conf proxy-cisra.pac proxy-home.pac proxy-zip.pac \
	closepopup-clear.html no-op-clear.html closepopup.html no-op.html \
	no-op-clear.js no-op.js ad-clear.gif ad.gif
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/examples/adzap
.endfor

.include "../../mk/bsd.pkg.mk"
