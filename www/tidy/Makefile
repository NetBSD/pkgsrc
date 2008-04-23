# $NetBSD: Makefile,v 1.28 2008/04/23 22:20:47 wiz Exp $
#

DISTNAME=	tidy-20080423
CATEGORIES=	www
MASTER_SITES=	# manually created tarballs on ftp.NetBSD.org only

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tidy.sourceforge.net/
COMMENT=	Fixes and tidies up HTML files

BUILD_DEPENDS+=	libxslt>=1.1.0:../../textproc/libxslt
BUILD_DEPENDS+=	doxygen>=1.0:../../devel/doxygen

WRKSRC=		${WRKDIR}/tidy
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake gmake
CPPFLAGS+=	-DSUPPORT_ACCESSIBILITY_CHECKS=1 -DSUPPORT_UTF16_ENCODINGS=1
CPPFLAGS+=	-DSUPPORT_ASIAN_ENCODINGS=1 -DSUPPORT_GETPWNAM=1

HTML_DOCFILES=	Overview.html doxygen.cfg grid.gif tidy.css faq.html \
		license.html pending.html release-notes.html tidy.gif
HTML_DOCDIR=	${PREFIX}/share/doc/tidy
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${HTML_DOCDIR} ${HTML_DOCDIR}/api

pre-configure:
	cd ${WRKSRC}/build/gnuauto && cp -R -f * ${WRKSRC}
	cd ${WRKSRC} && \
		touch NEWS README AUTHORS ChangeLog; \
		libtoolize --force --copy; \
		aclocal; \
		autoconf; \
		automake -acf

post-build:
	cd ${WRKSRC}/htmldoc && \
	${WRKSRC}/console/tidy -xml-help > tidy.xml && \
	${WRKSRC}/console/tidy -xml-config > tidy-config.xml && \
	xsltproc tidy1.xsl tidy.xml > tidy.1
	cd ${WRKSRC} && \
	doxygen htmldoc/doxygen.cfg

post-install:
	${INSTALL_MAN} ${WRKSRC}/htmldoc/tidy.1 ${PREFIX}/${PKGMANDIR}/man1
	for doc in ${HTML_DOCFILES}; do					\
	    ${INSTALL_DATA} ${WRKSRC}/htmldoc/$$doc ${HTML_DOCDIR} ;	\
	done
	${INSTALL_DATA} ${WRKSRC}/htmldoc/api/* ${HTML_DOCDIR}/api

.include "../../mk/bsd.pkg.mk"
