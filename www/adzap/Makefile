# $NetBSD: Makefile,v 1.1.1.1 2000/04/25 09:40:25 rh Exp $
#

DISTNAME=	adzap
PKGNAME=	${DISTNAME}-20000421
CATEGORIES=	www perl
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zip.com.au/~cs/adzap/index.html

MESSAGE_FILE=	${WRKDIR}/MESSAGE

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
USE_PERL5=	YES

do-configure:
.for file in squid_redirect zapwrap.sh
	${CP} ${WRKSRC}/${file} ${WRKSRC}/${file}.orig
	${SED} -e "s:/usr/bin/perl:${PREFIX}/bin/perl:g" \
	       -e "s:@@PREFIX@@:${PREFIX}:g" \
		<${WRKSRC}/${file}.orig >${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/zapwrap.sh ${PREFIX}/libexec/adzap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/adzap
.for file in adzap.conf proxy-cisra.pac proxy-home.pac proxy-zip.pac \
	closepopup-clear.html no-op-clear.html closepopup.html no-op.html \
	no-op-clear.js no-op.js ad-clear.gif ad.gif
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/adzap
.endfor

post-install:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' < ${PKGDIR}/MESSAGE \
		>${WRKDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
