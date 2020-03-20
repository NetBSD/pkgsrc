# $NetBSD: Makefile,v 1.76 2020/03/20 11:58:33 nia Exp $

DISTNAME=	adzap-20110915
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	http://adzapper.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://adzapper.sourceforge.net/
COMMENT=	Filter out animated ad banners from web pages
LICENSE=	2-clause-bsd

USE_TOOLS+=		perl:run
NO_BUILD=		yes

CHECK_PORTABILITY_SKIP=	scripts/update-zapper.damien

INSTALLATION_DIRS=	libexec share/examples/adzap

REPLACE_PERL+=		scripts/squid_redirect-nodata

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	scripts/squid_redirect
SUBST_FILES.paths+=	scripts/wrapzap
SUBST_VARS.paths=	PREFIX

DEPENDS+=		p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect-nodata \
		${DESTDIR}${PREFIX}/libexec/squid_redirect
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap \
		${DESTDIR}${PREFIX}/libexec/adzap
	${INSTALL_DATA} ${WRKSRC}/zaps/* \
		${DESTDIR}${PREFIX}/share/examples/adzap/
	${INSTALL_DATA} ${WRKSRC}/rc/*.pac \
		${DESTDIR}${PREFIX}/share/examples/adzap/
	${INSTALL_DATA} ${WRKSRC}/scripts/adzap.conf \
	    ${DESTDIR}${PREFIX}/share/examples/adzap/

.include "../../mk/bsd.pkg.mk"
