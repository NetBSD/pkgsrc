# $NetBSD: Makefile,v 1.3 2000/06/15 22:13:43 wiz Exp $
#

DISTNAME=	adzap-20000615
CATEGORIES=	www perl
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zip.com.au/~cs/adzap/index.html

MESSAGE_FILE=	${WRKDIR}/MESSAGE

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
USE_PERL5=	YES

do-configure:
.for FILE in squid_redirect wrapzap
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.orig
	${SED} -e "s:/usr/bin/perl:${PREFIX}/bin/perl:g" \
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

post-install:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' < ${PKGDIR}/MESSAGE \
		>${WRKDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
